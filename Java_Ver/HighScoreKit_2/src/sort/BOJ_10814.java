package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *  회원 수가 주어진다.
 *  회원들의 나이가 증가하는 순으로,
 *  나이가 같으면 먼저 가입한 순서대로 정렬.
 *  입력 순서가 가입 순서
 *
 */
public class BOJ_10814 {

    static class Member {

        public int age;
        public int memberNumber;
        public String name;

        Member(int age, int memberNumber, String name) {
            this.age = age;
            this.memberNumber = memberNumber;
            this.name = name;
        }
    }

    // 입력 범위 :: 1 <= N <= 100,000
    private int N;

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<Member> memberList = new ArrayList<>();

        this.N = Integer.parseInt(br.readLine());

        // 입력 받기
        for (int i = 0; i < N; i++) {
            String[] inputLine = br.readLine().split(" ");
            int age = Integer.parseInt(inputLine[0]);
            String name = inputLine[1];
            memberList.add(new Member(age, i, name));
        }

        // 조건에 따른 정렬
        Collections.sort(memberList, new Comparator<Member>() {
            @Override
            public int compare(Member o1, Member o2) {
                // 나이가 같으면, 먼저 입력한 것부터 정렬
                if (o1.age == o2.age) {
                    // 양수 return시 swap이 이루어진다.
                    return o1.memberNumber - o2.memberNumber;
                }
                return o1.age - o2.age;
            }
        });

        // 정답 출력
        for (Member m : memberList) {
            System.out.println(m.age + " " + m.name);
        }
    }

    public static void main(String[] args) throws IOException {
        BOJ_10814 sol = new BOJ_10814();
        sol.solution();
    }
}
