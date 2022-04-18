package back_tracking;

import java.util.ArrayList;

public class NandM {

    int[] numbers = new int[10];
    boolean[] isUsed = new boolean[10];

    public void backTracking(int k, int n, int m) {
        if (k == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(numbers[i] + " ");
            }
            System.out.println();
        }

        for (int i = 1; i <= n; i++) {
            if (!isUsed[i]) {
                numbers[k] = i;
                isUsed[i] = true;
                backTracking(k + 1, n, m);
                isUsed[i] = false;
            }
        }
    }

    public static void main(String[] args) {

        NandM nm = new NandM();
        nm.backTracking(0, 4, 2);
    }
}
