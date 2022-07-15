package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// N과 M(4)
public class BOJ_15652 {

    private int n;
    private int m;
    private int[] arr = new int[10];

    // 시간 초과로 인해, StringBuilder를 사용한다.
    private StringBuilder sb = new StringBuilder();

    private void backTracking(int k) {
        if (k == m) {
            for (int i = 0; i < m; i++) {
                // 시간 초과 코드
                // System.out.print(arr[i] + " ");
                sb.append(arr[i]).append(' ');
            }
            // 시간초과 코드
            // System.out.println();
            sb.append('\n');
            return;
        }

        int start = 1;
        if (k != 0) {
            start = arr[k - 1];
        }

        for (int i = start; i <= n; i++) {
            arr[k] = i;
            backTracking(k + 1);
        }
    }

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        this.n = Integer.parseInt(input[0]);
        this.m = Integer.parseInt(input[1]);
        backTracking(0);
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        BOJ_15652 sol = new BOJ_15652();
        sol.solution();
    }
}
