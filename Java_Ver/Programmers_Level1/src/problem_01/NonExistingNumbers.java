package problem_01;

import java.util.ArrayList;

//https://programmers.co.kr/learn/courses/30/lessons/86051
public class NonExistingNumbers {

    public static int Solution(int[] numbers) {
        int answer = 0;

        // 1. numbers를 ArrayList로 만든다.
        ArrayList<Integer> list = new ArrayList<>();
        for (int e : numbers) {
            list.add(e);
        }

        // 2. contains()를 사용해, 없는 숫자는 더한다.
        for (int i = 0; i < 10; i++) {
            if (!list.contains(i)) {
                answer += i;
            }
        }
        return answer;
    }

    public static void main(String[] args) {

        int[] numbersData1 = {1,2,3,4,6,7,8,0};
        int[] numbersData2 = {5,8,4,0,6,7,9};

        System.out.println(Solution(numbersData1));
        System.out.println(Solution(numbersData2));
    }
}
