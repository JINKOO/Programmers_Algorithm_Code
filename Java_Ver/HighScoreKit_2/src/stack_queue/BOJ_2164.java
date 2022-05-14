package stack_queue;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ_2164 {

    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int n = sc.nextInt();

        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            queue.offer(i + 1);
        }

        // queue연산 수행
        while (queue.size() > 1) {
            // 1. 맨 앞의 원소는 걍 버림(아니 이럴거면 왜 쓰는 건지..)
            queue.poll();

            // 2. 그 다음 원소는 맨 뒤로 이동(이게 핵심!, 큐를 사용하는 이유!)
            queue.offer(queue.poll());
        }

        System.out.println(queue.poll());
    }
}
