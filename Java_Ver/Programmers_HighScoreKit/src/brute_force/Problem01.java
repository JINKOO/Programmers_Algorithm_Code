/*
 *  #. [ 프로그래머스_모의고사 Level 1 ]
 *  
 *  #. 문제 설명
 *     수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 
 *     수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
 *     
 *     1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
 *     2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
 *     3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
 *     
 *     
 *     1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 
 *     가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한 조건
 *     - 시험은 최대 10,000 문제로 구성되어있습니다.
 *     - 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
 *     - 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
 *  
 *  #. 입출력 예
 *         answers	return
 *     [1,2,3,4,5]	   [1]
 *     [1,3,2,4,2]	[1,2,3]
 */

/**
 *  #. 나의 풀이법.
 *     - 변수 명 잘보자.. 파라미터로 넘어온 answers, solution()의 지역 변수 answer를 혼용하여 사용하였다...
 *     - C++에서는 answer가 vector로 주어졌지만, Java에서는 int[]로 주어진다.
 *       length를 알기 어려우므로, List를 사용하여 배열로 복사한다.
 *     
 *     - 나머지 풀이는 간단한 brute force문제 이다.
 *     - index를 활용해야...
 * 
 */
package brute_force;

import java.util.LinkedList;

public class Problem01 {

	public int getMax(int num1, int num2) {
		return (num1 > num2) ? num1 : num2;
	}
	
	public int[] solution(int[] answers) {
		int[] answer = {};
		//
		
		LinkedList<Integer> list = new LinkedList<>();
		
		int[] s1 = {1,2,3,4,5};
		int[] s2 = {2, 1, 2, 3, 2, 4, 2, 5};
		int[] s3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
		
		int[] score = new int[3];
		for(int i = 0; i < answers.length; i++) {
			if(s1[i % s1.length] == answers[i])
				score[0]++;
			if(s2[i % s2.length] == answers[i])
				score[1]++;
			if(s3[i % s3.length] == answers[i])
				score[2]++;
		}
		
		int max = getMax(score[0], getMax(score[1], score[2]));
		for(int i = 0; i < score.length; i++) {
			if(max == score[i])
				list.add(i + 1);
		}
	
		answer = new int[list.size()];
		for(int i = 0; i < list.size(); i++) {
			answer[i] = list.get(i);
		}
		
		//
		return answer;
	}
	
	public void printResult(int[] answers) {
		for(int i : answers)
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		
		Problem01 p = new Problem01();
		
		int[] answers = {1,2,3,4,5};
		p.printResult(p.solution(answers));
		
		int[] answers2 = {1,3,2,4,2};
		p.printResult(p.solution(answers2));
	}
}
