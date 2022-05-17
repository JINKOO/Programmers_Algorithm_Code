package dp;

import java.util.Scanner;

public class BOJ_1003 {

    private static final int MAX = 41;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        // 1. table setting
        int[][] dp = new int[2][MAX];

        while (t > 0) {
            int n = sc.nextInt();
            // 2. 초기값 setting
            dp[0][0] = 1;
            dp[0][1] = 0;
            dp[1][0] = 0;
            dp[1][1] = 1;

            for (int i = 2; i <= n; i++) {
                dp[0][i] = dp[0][i-2] + dp[0][i-1];
                dp[1][i] = dp[1][i-2] + dp[1][i-1];
            }

            // answer
            System.out.println(dp[0][n] + " " + dp[1][n]);

            t--;
        }
    }
}
