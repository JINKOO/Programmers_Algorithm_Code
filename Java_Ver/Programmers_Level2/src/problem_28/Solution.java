/*
 *  #. [ 프로그래머스_조이스틱 Level 2 ]
 *  
 *  #. 문제 설명
 *     조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
 *     ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA
 *     조이스틱을 각 방향으로 움직이면 아래와 같습니다.
 *     
 *     ▲ - 다음 알파벳
 *     ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
 *               ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
 *               ▶ - 커서를 오른쪽으로 이동
 *     
 *     예를 들어 아래의 방법으로 JAZ를 만들 수 있습니다.
 *     - 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
 *     - 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
 *     - 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
 *     따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
 *     
 *     만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.
 *  
 *  #. 제한 사항
 *     - name은 알파벳 대문자로만 이루어져 있습니다.
 *     - name의 길이는 1 이상 20 이하입니다.
 *  
 *  #. 입출력 예
 *       name   return
 *     JEROEN	    56
 *        JAN	    23
 *        
 */

/*
 *  #. 나의 풀이법.
 *     - 시도하다가 못 품..
 *     
 *  #. 풀이법.
 *     - 크게 2가지 경우로 나누어 생각한다.
 *     1. 상하 스틱 이동 
 *     2. 좌우 스틱 이동(커서의 최소 이동)
 *     
 *     1번은 쉽다.
 *     2번이 문제임.. 
 *     커서의 이동 방향이
 *     1.--> 방향으로만, 
 *     2.<-- 방향으로만, 
 *     3.--><--방향 중 
 *     최솟값을 찾는 것이 핵심이었다.
 *     
 *     특히 3번 경우가 어려움
 *     
 */

package problem_28;

public class Solution {

	public int getMin(int num1, int num2) {
		if(num1 < num2)
			return num1;
		else
			return num2;
	}
	
	public int solution(String name) {
		int answer = 0;
		//
		
		//1. 알파벳 변경 조이스틱 조작(위, 아래)
		for(int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);
			if(c != 'A') {
				int sub1 =  c - 'A';
				int sub2 = 'Z' + 1 - c;
				answer += (sub1 < sub2) ? sub1 : sub2;
			}
		}
		
		//2. 커서 이동.
		int min = name.length();
		for(int i = 0; i < name.length(); i++) {
			char c = name.charAt(i);
			if(c != 'A') {
				int index = i + 1;
				while(index < name.length() && name.charAt(index) == 'A')
					index++;
				
				int move = (i * 2) + name.length() - index;
				min = getMin(min, move);
			}
		}
		System.out.println(min);
		//
		return answer + min;
	}
	
	public void printResult(int answer) {
		System.out.println(answer);
	}
	
	public static void main(String[] args) {
		
		Solution sol = new Solution();
		sol.printResult(sol.solution("KJEAZAAN"));
		sol.printResult(sol.solution("JAN"));
		sol.printResult(sol.solution("JEROEN"));
	}
}
