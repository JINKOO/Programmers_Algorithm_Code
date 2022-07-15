package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// N과 M(2)
public class BOJ_15650 {

    private int n;
    private int m;
    private int[] arr = new int[10];
    private boolean[] isUsed = new boolean[10];


    public void backTracking(int k) {

        if (k == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }

        int start = 1;
        if (k != 0) {
            // 그 다음에 와야할 값은, 전의 값보다 항상 커야한다.
            start = arr[k - 1] + 1;
        }

        for (int i = start; i <= n; i++) {
            if (!isUsed[i]) {
                arr[k] = i;
                isUsed[i] = true;
                backTracking(k + 1);
                isUsed[i] = false;
            }
        }
    }

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        this.n = Integer.parseInt(input[0]);
        this.m = Integer.parseInt(input[1]);

        backTracking(0);
    }

    public static void main(String[] args) throws IOException {

        BOJ_15650 sol = new BOJ_15650();
        sol.solution();
    }
}
