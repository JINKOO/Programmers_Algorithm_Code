package etc;

import java.io.BufferedReader;

public class Fibonacci {

    // recursion을 이용한 solution1
    public int fibonacci_recursion(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fibonacci_recursion(n - 2) + fibonacci_recursion(n - 1);
    }

    // DP를 이용한 solution2
    public int fibonacci_dp(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }

    public static void main(String[] args) {
        Fibonacci f = new Fibonacci();

        System.out.println(f.fibonacci_recursion(10));
        System.out.println(f.fibonacci_dp(10));
    }
}
