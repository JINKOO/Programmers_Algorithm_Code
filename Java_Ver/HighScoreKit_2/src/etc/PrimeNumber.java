package etc;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class PrimeNumber {

    public boolean isPrimeNumber(int n) {
        // 소수 판별 로직(1과 자기 자신)
        // 시간 복잡도 = O(n)
        for (int i = 2; i < n; i++) {
            if (n % i == 0) { // 2라는 약수가 존재한다는 의미입니다.
                return false;
            }
        }
        return true;
    }

    // 1 ~ n까지에서 소수 찾기
    public List<Integer> getPrimeNumbers(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        List<Integer> primeNumberList = new ArrayList<>();

        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i < isPrime.length; i++) {
            if (isPrime[i]) {
                primeNumberList.add(i);
            }
        }
        return primeNumberList;
    }

    public static void main(String[] args) {

        PrimeNumber primeNumber = new PrimeNumber();

        System.out.println(primeNumber.isPrimeNumber(4));
        System.out.println(primeNumber.isPrimeNumber(12));
        System.out.println(primeNumber.isPrimeNumber(137));

        System.out.println("======================");

        System.out.println(primeNumber.getPrimeNumbers(16));
    }
}
