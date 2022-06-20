package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

/**
 *  정렬 문제
 */
public class BOJ_7795 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T =  Integer.parseInt(br.readLine());

        while(T > 0) {

            int answer = 0;

            // 1. size 만큼 입력 받기
            String[] size = br.readLine().split(" ");
            int sizeA = Integer.parseInt(size[0]);
            int sizeB = Integer.parseInt(size[1]);

            Integer[] arrA = new Integer[sizeA];
            Integer[] arrB = new Integer[sizeB];

            // 2. A 입력 받기
            String[] arrAInput = br.readLine().split(" ");
            for (int i = 0; i < sizeA; i++) {
                arrA[i] = Integer.parseInt(arrAInput[i]);
            }

            // 3. B 입력 받기
            String[] arrBInput = br.readLine().split(" ");
            for (int i = 0; i < sizeB; i++) {
                arrB[i] = Integer.parseInt(arrBInput[i]);
            }

            // 4. 각각 정렬하기.
            // A는 오름 차순, B는 내림차순으로 정렬한다.
            Arrays.sort(arrA);
            Arrays.sort(arrB, Collections.reverseOrder());

            // 5. 연산하기
            for (Integer integer : arrA) {
                // 만약, A의 첫번째 원소가 B의 첫번째 원소보다 크면, B는 모두 먹이가된다.
                if (integer > arrB[0]) {
                    answer += arrB.length;
                    continue;
                }
                for (Integer value : arrB) {
                    if (integer > value) {
                        answer++;
                    }
                }
            }

            // 6. 정답 출력
            System.out.println(answer);

            T--;
        }
    }
}
