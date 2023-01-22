package porr.spark;

import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class Friendship {
    private Integer personId;
    private Integer friendId;

    public Friendship reverse() {
        personId = friendId;
        friendId = personId;
        return this;
    }
}
