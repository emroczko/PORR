package porr.spark;

import lombok.extern.slf4j.Slf4j;
import org.apache.spark.api.java.function.Function;
import org.apache.spark.sql.Encoders;
import org.apache.spark.sql.SparkSession;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.time.Duration;
import java.time.Instant;
import java.util.List;

import static org.apache.spark.sql.functions.col;

@Slf4j
@SpringBootApplication
public class SparkApplication implements CommandLineRunner {

    public static void main(String[] args) {
        SpringApplication.run(SparkApplication.class, args);
    }

    @Override
    public void run(String... args) {
        log.info("Running...");

        var spark = SparkSession.builder().master("local[1]").appName("Simple Application").getOrCreate();
        var fileName = "Datasets/karate.txt";

        log.info("{}", spark.sparkContext().executorEnvs());

        var friendship = spark.read().textFile(fileName)
                .javaRDD()
                .filter((Function<String, Boolean>) line -> !line.startsWith("%"))
                .map((Function<String, Friendship>) line -> {
                    var parts = line.split(" ");
                    return Friendship.builder()
                            .personId(Integer.parseInt(parts[0]))
                            .friendId(Integer.parseInt(parts[1]))
                            .build();
                });

        var start = Instant.now();
        friendship.flatMap(x -> List.of(x, x.reverse()).iterator())
                .mapToPair(s -> new scala.Tuple2<>(s.getPersonId(), 1L))
                .countByKey();
        var end = Instant.now();
        var duration = Duration.between(start, end).toMillis();
        log.info("First method took {} milliseconds", duration);
//
//        start = Instant.now();
//        friendship.union(friendship.map((Function<Friendship, Friendship>) Friendship::reverse))
//                .mapToPair(s -> new scala.Tuple2<>(s.getPersonId(), 1L))
//                .countByKey();
//        end = Instant.now();
//        duration = Duration.between(start, end).toMillis();
//        log.info("Second method took {} milliseconds", duration);

        start = Instant.now();
        var friendshipDataset = spark.createDataFrame(friendship.rdd(), Friendship.class).as(Encoders.bean(Friendship.class));
        friendshipDataset.union(friendshipDataset
                        .select(col("personId").alias("friendId"),
                                col("friendId").alias("personId"))
                        .as(Encoders.bean(Friendship.class)))
                .groupBy("personId")
                .count().as("friends_count")
                .show();
        end = Instant.now();
        duration = Duration.between(start, end).toMillis();
        log.info("Third method took {} milliseconds", duration);
    }
}
