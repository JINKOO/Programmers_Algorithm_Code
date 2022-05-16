package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 아직 미해결 코드
public class BOJ_5648 {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        List<Integer> answer = new LinkedList<>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1번째 줄
        StringTokenizer stk = new StringTokenizer(br.readLine(), " ");
        StringBuilder sb;
        int n = Integer.parseInt(stk.nextToken());
        while (answer.size() < n && stk.hasMoreTokens()) {
            sb = new StringBuilder(stk.nextToken());
            answer.add(Integer.parseInt(sb.reverse().toString()));
        }

        // sort
        Collections.sort(answer);

        // iterate
        for (int e : answer) {
            System.out.println(e);
        }
    }
}
