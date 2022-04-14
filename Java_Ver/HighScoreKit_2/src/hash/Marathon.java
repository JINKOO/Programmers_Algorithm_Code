package hash;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class Marathon {

    public String solution(String[] participants, String[] completion) {
        String answer = "";

        HashMap<String, Integer> map = new HashMap<>();

        // 완주자를 우선 map에 삽입한다.
        // 동명이인이 있을 경우에는, 카운트를 1증가한다.
        for (String name : completion) {
            if (map.containsKey(name)) {
                int value = map.get(name) + 1;
                map.put(name, value);
            } else {
                map.put(name, 1);
            }
        }

        // 참석자를 map에서 찾는다. (동명이인 예외처리를 해야한다)
        for (String name : participants) {
            if (map.containsKey(name)) {
                int value = map.get(name) - 1;
                map.put(name, value);
            } else {
                answer = name;
            }
        }

        // map순회
        if (answer.isEmpty()) {
            for (String name : map.keySet()) {
                if (map.get(name) != 0) {
                    answer = name;
                }
            }
        }
        return answer;
    }

    public static void main(String[] args) {

        Marathon marathon = new Marathon();

        String[] participants = {"leo", "kiki","eden"};
        String[] completion = {"eden", "kiki"};

        String[] participants2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
        String[] completion2 = {"josipa", "filipa", "marina", "nikola"};

        String[] participants3 = {"mislav", "stanko", "mislav", "ana"};
        String[] completion3 = {"stanko", "ana", "mislav"};

        System.out.println(marathon.solution(participants, completion));
        System.out.println(marathon.solution(participants2, completion2));
        System.out.println(marathon.solution(participants3, completion3));

    }
}
