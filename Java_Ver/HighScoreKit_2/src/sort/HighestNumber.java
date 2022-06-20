package sort;

import java.util.*;

public class HighestNumber {

    public String solution(int[] numbers) {
        String answer = "";

        StringBuffer sb = new StringBuffer();

        List<String> list = new ArrayList<>();
        for (int e : numbers) {
            list.add(Integer.toString(e));
        }

        // 정렬 기준
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1 + o2);
            }
        });

        for (String s : list) {
            sb.append(s);
        }

        answer = sb.toString();

        return answer;
    }

    public static void main(String[] args) {

        HighestNumber sol = new HighestNumber();

        int[] numbers1 = {6, 10, 2};
        int[] numbers2 = {3, 30, 34, 5, 9};
        System.out.println(sol.solution(numbers1));
        System.out.println(sol.solution(numbers2));
    }
}
