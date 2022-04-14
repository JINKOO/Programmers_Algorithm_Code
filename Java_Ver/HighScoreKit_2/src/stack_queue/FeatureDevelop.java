package stack_queue;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class FeatureDevelop {

    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};

        // 1. stack 선언 및 잔여 작업 일수 저장 ArrayList
        Stack<Integer> stack = new Stack<>();
        ArrayList<Integer> remainDayList = new ArrayList<>();
        ArrayList<Integer> deployDayList = new ArrayList<>();

        // 2. 남은 작업 일 수 계산
        for (int i = 0; i < progresses.length; i++) {
            int remainWork = 100 - progresses[i];
            int remainDay = remainWork / speeds[i];

            //2.1 만약 나머지가 존재하면, +1일한다.
            if (remainWork % speeds[i] != 0) {
                remainDay += 1;
            }
            // 2.2 remainDayList에 삽입.
            remainDayList.add(remainDay);
        }
        // 3. stack연산
        for (int element : remainDayList) {
            int count = 0;
            // 3.1 stack이 비어 있다면, 무조건 push
            if (stack.empty()) {
                stack.push(element);
                continue;
            }

            // 3.2 peek와 다음 들어올 element비교
            if (stack.peek() < element) {
                while(!stack.empty()) {
                    stack.pop();
                    count++;
                }
                deployDayList.add(count);
            }
            stack.push(element);
        }

        if (!stack.empty()) {
            deployDayList.add(stack.size());
        }

        answer = new int[deployDayList.size()];
        for (int i = 0; i < deployDayList.size(); i++) {
            answer[i] = deployDayList.get(i);
        }
        //
        return answer;
    }

    public static void main(String[] args) {

        int[] progressesData1 = {93, 30, 55};
        int[] speedsData1 = {1, 30, 5};
        int[] progressesData2 = {95, 90, 99, 99, 80, 99};
        int[] speedsData2 = {1, 1, 1, 1, 1, 1};

        FeatureDevelop fd = new FeatureDevelop();

        System.out.println(Arrays.toString(fd.solution(progressesData1, speedsData1)));
        System.out.println(Arrays.toString(fd.solution(progressesData2, speedsData2)));

    }
}
