package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BOJ_11656 {

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String inputWord = br.readLine();

        List<String> stringList = new ArrayList<>();
        for (int i = inputWord.length() - 1; i >= 0; i--) {
            stringList.add(inputWord.substring(i));
        }

        Collections.sort(stringList);

        for (String s : stringList) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) throws IOException {

        BOJ_11656 sol = new BOJ_11656();

        sol.solution();
    }
}
