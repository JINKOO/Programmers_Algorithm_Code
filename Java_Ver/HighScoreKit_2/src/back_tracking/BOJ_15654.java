package back_tracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// N과 M(5)
public class BOJ_15654 {

    private int n;
    private int m;
    private int[] arr;
    private int[] answer;
    private boolean[] isUsed = new boolean[10001];
    private StringBuilder sb = new StringBuilder();


    public void backTracking(int k) {
        if (k == m) {
            for (int i = 0; i < m; i++) {
                sb.append(answer[i]).append(' ');
            }
            sb.append('\n');
            return;
        }


        for (int i = 0; i < arr.length; i++) {
            if (!isUsed[arr[i]]) {
                answer[k] = arr[i];
                isUsed[arr[i]] = true;
                backTracking(k + 1);
                isUsed[arr[i]] = false;
            }
        }
    }

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputSize = br.readLine().split(" ");
        this.n = Integer.parseInt(inputSize[0]);
        this.m = Integer.parseInt(inputSize[1]);

        this.arr = new int[this.n];
        this.answer = new int[this.n];

        String inputNumbers = br.readLine();
        StringTokenizer stk = new StringTokenizer(inputNumbers, " ");
        int i = 0;
        while(stk.hasMoreElements()) {
            arr[i++] = Integer.parseInt(stk.nextToken());
        }

        System.out.println(Arrays.toString(arr));

        // 오름차순 정렬
        Arrays.sort(arr);

        // backTracking
        backTracking(0);

        // answer
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        BOJ_15654 sol = new BOJ_15654();
        sol.solution();
    }
}
