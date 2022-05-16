package stack_queue;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class BOJ_1874 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] numbers = new int[n];
        Stack<Integer> stack = new Stack<>();
        List<Character> answer = new ArrayList<>();

        // 수열 초기화
        for (int i = 0; i < n; i++) {
            numbers[i] = sc.nextInt();
        }

        // 1 ~ n까지의 숫자를 관리하기 위한 현재 숫자 변수.
        int currentNumber = 1;
        for (int i = 0; i < numbers.length; i++) {
            /* stack의 삽입 조건.
               우리는 이 문제를 해결하기 위해 stack을 사용하는데,
               1 ~ n까지 숫자를 stack에 삽입해야한다,
               현재 currentNumber가 4라고 가정하면,
               1 ~ 3은 이미 사용되었다. (현재 stack안에 존재하거나, stack에 있다가 pop되었다는 의미)
               5 ~ n은 아직 사용되지 않았다.
               numbers[i]가 8이면, 4 ~ 8까지 숫자를 stack에 삽입해야 한다.
               이해가 갔음..? 안갔으면 걍 해보셈.
               누군가 내 코드 볼텐데 최대한 이해하기 쉽게 하려했으니까, 해보셈
             */
            while (currentNumber <= numbers[i]) {
                stack.push(currentNumber);
                answer.add('+');
                currentNumber++;
            }

            // stack의 top과 numbers[i]가 일치하면, 해당 수열이 완성되는데 일조하는 놈
            if (!stack.empty() && stack.peek() == numbers[i]) {
                stack.pop();
                answer.add('-');
            }

            // 이 경우에는, stack의 top이 수열을 만드는데 방해하는 놈
            if (!stack.empty() && stack.peek() > numbers[i]) {
                System.out.println("NO");
                return;
            }
        }

        // 드디어 정답 출력!!!
        for (char c : answer) {
            System.out.println(c);
        }
    }
}
