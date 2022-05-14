package stack_queue;

import java.util.Scanner;
import java.util.Stack;

public class BOJ_10773 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();
        int[] inputNumbers = new int[k];
        Stack<Integer> stack = new Stack<>();
        int answer = 0;

        // 배열 초기화
        for (int i = 0; i < k; i++) {
            inputNumbers[i] = sc.nextInt();
        }

        // stack 연산
        for (int i = 0; i < inputNumbers.length; i++) {
            if (!stack.empty() && inputNumbers[i] == 0) {
                stack.pop();
                continue;
            }
            stack.push(inputNumbers[i]);
        }

        // stack 원소의 합
        while (!stack.empty()) {
            answer += stack.peek();
            stack.pop();
        }

        System.out.println(answer);
    }
}
