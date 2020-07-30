/*
 *  #. [ 프로그래머스_숫자야구 Level 2 ]
 *  
 *  #. 문제 설명
 *     숫자 야구 게임이란 2명이 서로가 생각한 숫자를 맞추는 게임입니다. 게임해보기
 *     각자 서로 다른 1~9까지 3자리 임의의 숫자를 정한 뒤 서로에게 3자리의 숫자를 불러서 결과를 확인합니다. 
 *     그리고 그 결과를 토대로 상대가 정한 숫자를 예상한 뒤 맞힙니다.
 *     
 *     - 숫자는 맞지만, 위치가 틀렸을 때는 볼
 *     - 숫자와 위치가 모두 맞을 때는 스트라이크
 *     - 숫자와 위치가 모두 틀렸을 때는 아웃
 *     
 *     예를 들어, 아래의 경우가 있으면
 *     A : 123
 *     B : 1스트라이크 1볼.
 *     A : 356
 *     B : 1스트라이크 0볼.
 *     A : 327
 *     B : 2스트라이크 0볼.
 *     A : 489
 *     B : 0스트라이크 1볼.
 *     
 *     이때 가능한 답은 324와 328 두 가지입니다.
 *     
 *     질문한 세 자리의 수, 스트라이크의 수, 볼의 수를 담은 2차원 배열 baseball이 매개변수로 주어질 때, 
 *     가능한 답의 개수를 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한사항
 *     - 질문의 수는 1 이상 100 이하의 자연수입니다.
 *     - baseball의 각 행은 [세 자리의 수, 스트라이크의 수, 볼의 수] 를 담고 있습니다.
 *     
 *     
 *  #. 입출력 예
 *                                                 baseball	   return
 *     [[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]	        2
 */

/**
 *  #. 나의 풀이법.
 *     - 방향을 도저히 잡지 못함.
 *     
 *  #. 풀이법.
 *     완전탐색!!!
 *     Stack을 사용한다. 123 ~ 987까지 Stack에 push한다. 이때, 삼중 for문...
 *     (문제에서 서로다른 3자리 수라는 조건이 있다.)
 *     input의 크기가많지 않으므로, BP를 사용한다.
 *     
 *     이후,
 *     1. Stack에서 하나 pop()
 *     2. 꺼낸 숫자와 baseball[0][0] ~ baseball[i][0]의 숫자와 비교하여
 *        각각 strike의 개수, ball의 개수와 비교한다.
 *     3. 이때, baseball배열의 strike, ball수와 같다면, count를 ++한다.
 *     4. count == baseball.length가 되었으면, answer++한다.
 *        Stack에서 꺼낸 값이 baseball의 모든 숫자들과 strike, ball의 개수가 같으므로 정답이 될수 있는 후보 숫자이다.  
 * 
 *  #. 유사문제
 *     프로그래머스 소수찾기 Level 2 or HighScore Kit
 */
package brute_force;

import java.util.Stack;

public class Problem03 {

	public int getStrike(String curr, String number) {
		int count = 0;
		for(int i = 0; i < 3; i++) {
			if(curr.charAt(i) == number.charAt(i))
				count++;
		}
		return count;
	}
	
	public int getBall(String curr, String number) {
		int count = 0;
		for(int i = 0; i < 3; i++) {
			if(curr.contains(String.valueOf(number.charAt(i)))) {
				//같은 숫자가 포함되어 있지만, ball의 조건은 해당 숫자의 위치가 달라야 한다.
				if(curr.indexOf(number.charAt(i)) != number.indexOf(number.charAt(i)))
					count++;
			}
		}
		return count;
	}
	
	public int solution(int[][] baseball) {
        int answer = 0;
        //
        Stack<String> s = new Stack<>();
        for(int i = 1; i <= 9; i++) {
        	for(int j = 1; j <= 9; j++) {
        		for(int k = 1; k <= 9; k++) {
        			if(i!=j && j!=k && i!=k) {
        				s.push(String.valueOf(100 * i + 10 * j + k));
        			}
        		}
        	}
        }
        
        //Stack에사 하나씩 꺼내어 baseball의 숫자와 각각 비교한다.
        while(!s.isEmpty()) {
        	String curr = s.pop();
        	int count = 0;
        	for(int i = 0; i < baseball.length; i++) {
        		
        		int strike = getStrike(curr, String.valueOf(baseball[i][0]));
        		int ball = getBall(curr, String.valueOf(baseball[i][0]));
        		
        		if(strike == baseball[i][1] && ball == baseball[i][2]) count++;
        	}
        	//같으면, 정답이 될 수 있는 후보이다. baseball의 모든 숫자들의 strike, ball의 개수를 만족하였으므로
        	if(count ==  baseball.length) { 
        		System.out.println(curr);
        		answer++;
        	}
        }
        
        //
        return answer;
    }
	
	public static void main(String[] args) {
		
		Problem03 p = new Problem03();
		
		int[][] baseball = {
				{123,1,1},
				{356,1,0},
				{327, 2, 0},
				{489, 0, 1}
		};
		
		System.out.println(p.solution(baseball));
	}
}
