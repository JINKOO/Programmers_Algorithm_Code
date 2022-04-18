package hash;

import java.util.*;


// HashMap
public class HashMapSort {

    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("A", 100);
        map.put("B", 10);
        map.put("C", 1000);
        map.put("D", 10000);
        map.put("E", 10);

        // map을 정렬하기 위해서는 List형태로 map을 가져와야 한다.
        List<Map.Entry<String, Integer>> entryList = new LinkedList<>(map.entrySet());

        // Map.Entry의 내장 정렬 함수 사용
//        entryList.sort(Map.Entry.comparingByValue());
//        for (Map.Entry<String, Integer> e : entryList) {
//            System.out.println("[" + e.getKey() + ", " + e.getValue() + "]");
//        }

        // 2. Comparator 인터페이스 구현체
        entryList.sort(new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if (Objects.equals(o1.getValue(), o2.getValue())) {
                    return (o2.getKey()).compareTo(o1.getKey());
                }
                return (o1.getValue()).compareTo(o2.getValue());
            }
        });

        for (Map.Entry<String, Integer> e : entryList) {
            System.out.println("[" + e.getKey() + ", " + e.getValue() + "]");
        }

        /////////////////////

        Set<String> set = new HashSet<>();
        set.add("KO");
        set.add("PARK");
        set.add("KIM");

        Iterator<String> it = set.iterator();
        System.out.println(set.size());
        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
