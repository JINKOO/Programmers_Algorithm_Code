package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// N과 M(3)
public class BOJ_15651 {

    private int n;
    private int m;
    private int[] arr = new int[10];
    private boolean[] isUsed = new boolean[10];

    private void backTracking(int k) {
        if (k == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
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

    }

    public static void main(String[] args) throws IOException {

        BOJ_15651 sol = new BOJ_15651();
        sol.solution();
    }
}
