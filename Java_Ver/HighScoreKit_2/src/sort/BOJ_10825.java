package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class BOJ_10825 {

    static class GradeInfo {
        public String name;
        public int kor;
        public int eng;
        public int math;

        GradeInfo(String name, int kor, int eng, int math) {
            this.name = name;
            this.kor = kor;
            this.eng = eng;
            this.math = math;
        }
    }

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int inputSize = Integer.parseInt(br.readLine());

        List<GradeInfo> list = new ArrayList<>();

        // 입력 받기
        while (inputSize > 0) {
            String[] inputGradeInfo = br.readLine().split(" ");
            list.add(new GradeInfo(
                    inputGradeInfo[0],
                    Integer.parseInt(inputGradeInfo[1]),
                    Integer.parseInt(inputGradeInfo[2]),
                    Integer.parseInt(inputGradeInfo[3])
            ));
            inputSize--;
        }

        // 정렬하기
        Collections.sort(list, new Comparator<GradeInfo>() {
            @Override
            public int compare(GradeInfo o1, GradeInfo o2) {
                // 국어 점수 내림차순으로 정렬하는데,
                // 국어 점수가 같다면, 영어점수가 높은 순으로 정렬.
                if (o1.kor == o2.kor) {
                    // 영어 점수마저 같다면, 수학 점수 감소 순
                    if (o1.eng == o2.eng) {
                        // 수학 점수 마저 같다면, 이름 사전 순
                        if (o1.math == o2.math) {
                            return o1.name.compareTo(o2.name);
                        }
                        return o2.math - o1.math;
                    }
                    return o1.eng - o2.eng;
                }
                return o2.kor - o1.kor;
            }
        });

        // 정답 출력
        for (GradeInfo gradeInfo : list) {
            System.out.println(gradeInfo.name);
        }
    }

    public static void main(String[] args) throws IOException {
        BOJ_10825 sol = new BOJ_10825();
        sol.solution();
    }
}
