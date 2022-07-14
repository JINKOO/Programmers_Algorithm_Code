package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class N_M_1 {

    private int n;
    private int m;

    private int[] arr = new int[8];
    private boolean[] isUsed = new boolean[8];

    public void backTracking(int k) {

        if (k == m) {
            for (int i = 0; i < k; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
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

        String input = br.readLine();
        this.n = Integer.parseInt(input.split(" ")[0]);
        this.m = Integer.parseInt(input.split(" ")[1]);

        backTracking(0);

    }

    public static void main(String[] args) throws IOException {
        N_M_1 sol = new N_M_1();
        sol.solution();
    }
}
