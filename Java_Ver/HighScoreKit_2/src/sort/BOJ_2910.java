package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2910 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        Map<String, Integer> map = new LinkedHashMap<>();

        int n = Integer.parseInt(stk.nextToken());
        int c = Integer.parseInt(stk.nextToken());

        stk = new StringTokenizer(br.readLine());
        while (stk.hasMoreTokens()) {
            String value = stk.nextToken();
            if (map.containsKey(value)) {
                map.replace(value, map.get(value) + 1);
            } else {
                map.put(value, 1);
            }
        }

        ArrayList<String> list = new ArrayList<>(map.keySet());
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return map.get(o2).compareTo(map.get(o1));
            }
        });

        for (String value : list) {
            for (int i = 0; i < map.get(value); i++) {
                System.out.print(value + " ");
            }
        }
    }
}
