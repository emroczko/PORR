package porr.spark;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest(args = {"--add-opens" , "java.base/sun.nio.ch=ALL-UNNAMED"})
class SparkApplicationTests {

    @Test
    void contextLoads() {
    }
}
