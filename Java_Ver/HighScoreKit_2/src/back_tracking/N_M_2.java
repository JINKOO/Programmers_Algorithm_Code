package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class N_M_2 {

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

        N_M_2 sol = new N_M_2();
        sol.solution();
    }
}
