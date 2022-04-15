package stack_queue;

import java.util.*;

public class PriorityPrinter {
    public int solution(int[] priorities, int location) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < priorities.length; i++) {
            pq.add(priorities[i]);
        }

        //System.out.println(pq.poll() + ", " + pq.size());

        while (!pq.isEmpty()) {
            for (int i = 0; i < priorities.length; i++) {
                if (pq.peek() == priorities[i]) {
                    if (i == location) {
                        return answer;
                    }
                    answer++;
                    pq.poll();
                }
            }
        }

        for (Integer e : list) {
            if (location == e) {
                answer = e + 1;
            }
        }
        return answer;
    }
    public static void main(String[] args) {

        PriorityPrinter pp = new PriorityPrinter();

        int[] priorities = {2, 1, 3, 2};
        int location = 2;

        int [] priorities2 = {1, 1, 9, 1, 1, 1};
        int location2 = 0;

        System.out.println(pp.solution(priorities, location));
        System.out.println(pp.solution(priorities2, location2));
    }
}
