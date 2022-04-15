package stack_queue;

import java.util.*;

public class FeatureDevelop {

    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};

        ArrayList<Integer> workList = new ArrayList<>();
        ArrayList<Integer> deployList = new ArrayList<>();
        //Stack<Integer> stack = new Stack<>();
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < progresses.length; i++) {
            int remainWork = 100 - progresses[i];
            int remainDayToComplete = remainWork / speeds[i];
            if (remainWork % speeds[i] != 0) {
                remainDayToComplete++;
            }
            workList.add(remainDayToComplete);
        }

        for (Integer e : workList) {
            if (!queue.isEmpty() && queue.peek() < e) {
                // pop
                int count = 0;
                while(!queue.isEmpty()) {
                    queue.poll();
                    count++;
                }
                deployList.add(count);
            }
            queue.add(e);
        }

        if (!queue.isEmpty()) {
            deployList.add(queue.size());
        }

        answer = new int[deployList.size()];
        for (int i = 0; i < deployList.size(); i++) {
            answer[i] = deployList.get(i);
        }

        return answer;
    }

    public static void main(String[] args) {

        int[] progressesData1 = {93, 30, 55};
        int[] speedsData1 = {1, 30, 5};
        int[] progressesData2 = {95, 90, 99, 99, 80, 99};
        int[] speedsData2 = {1, 1, 1, 1, 1, 1};
        int[] progressesData3 = {95, 90, 99, 97, 95, 99};
        int[] speedsData3 = {1, 1, 1, 1, 1, 1};

        FeatureDevelop fd = new FeatureDevelop();

        System.out.println(Arrays.toString(fd.solution(progressesData1, speedsData1)));
        System.out.println(Arrays.toString(fd.solution(progressesData2, speedsData2)));
        System.out.println(Arrays.toString(fd.solution(progressesData3, speedsData3)));

    }
}
