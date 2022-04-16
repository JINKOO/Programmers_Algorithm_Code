package etc;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

// n! 에서 tail의 0의 개수 구하기.
public class ZeroCount {

    public int solution(int n) {
        //
        int count = 0;
        while(n > 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }

    public static void main(String[] args) {
        ZeroCount zeroCount = new ZeroCount();
        System.out.println(zeroCount.solution(10));
    }
}
