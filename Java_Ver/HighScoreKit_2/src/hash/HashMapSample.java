package hash;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

class Fruit {
    String type;
    String dueDate;

    Fruit(String type, String dueDate) {
        this.type = type;
        this.dueDate = dueDate;
    }
}

public class HashMapSample {
    public static void main(String[] args) {
        Map<Fruit, Integer> map = new HashMap<>();

        map.put(new Fruit("Apple", "2022-04-23"), 1);
        map.put(new Fruit("Apple", "2022-04-23"), 1);

        System.out.println(map.size());

        Set<Fruit> keySet = map.keySet();
        Iterator<Fruit> it = keySet.iterator();
        while(it.hasNext()) {
            System.out.println(it.next().type);
        }
    }
}
