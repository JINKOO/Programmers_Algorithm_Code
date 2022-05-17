package dp;

import java.util.Scanner;

public class BOJ_1932 {

    private static final int MAX = 501;

    public static int getMax(int num1, int num2) {
        if (num1 >= num2) {
            return num1;
        }
        return num2;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // 1. table 정의
        int[][] dp = new int[MAX][MAX];

        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= i; j++) {
                dp[i][j] = sc.nextInt();
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 2. 조건에 따른 점화식 생성.
                if (j == 1) {
                    dp[i][j] = dp[i][j] + dp[i-1][j];
                } else if(j == i) {
                    dp[i][j] = dp[i][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j] + getMax(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }

        // 3. 정답 출력하기
        int answer = dp[n][0];
        for (int i = 1; i < dp[n].length; i++) {
            if (answer < dp[n][i]) {
                answer = dp[n][i];
            }
        }
        System.out.println(answer);
    }
}
