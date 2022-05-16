package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class BOJ_1181 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<String> answer = new LinkedList<>();

        while (n > 0) {
            String word = br.readLine();
            answer.add(word);
            n--;
        }

        answer.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() == o2.length()) {
                    return o1.compareTo(o2);
                }
                return Integer.compare(o1.length(), o2.length());
            }
        });

        System.out.println(answer.get(0));
        for (int i = 1; i < answer.size(); i++) {
            if (answer.get(i - 1).equals(answer.get(i))) {
                continue;
            }
            System.out.println(answer.get(i));
        }
    }
}
