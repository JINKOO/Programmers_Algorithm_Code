/*
 *  #. [ 프로그래머스_주식가격 Level 2 ]
 *  
 *  #. 문제 설명
 *     초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 
 *     가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
 *     
 *  #. 제한사항
 *     - prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
 *     - prices의 길이는 2 이상 100,000 이하입니다.
 *  
 *  #. 입출력 예
 *             prices	         return
 *     [1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]
 *     
 *  #. 입출력 예 설명
 *     - 1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
 *     - 2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
 *     - 3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
 *     - 4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
 *     - 5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.
 */

/*
 *  #. 풀이법.
 *     - Queue를 사용한다.
 *     - 풀이법은 'stack_queue/Problem03' 탑 문제와 같다.
 * 
 * 
 */
package stack_queue;

import java.util.LinkedList;
import java.util.Queue;
public class Problem03 {

	public int[] solution(int[] prices) {
		int[] answer = {};
		//
		answer = new int[prices.length];
		Queue<Integer> q = new LinkedList<>();
		
		for(int i = 0; i < prices.length; i++) {
			int count = 0;
			for(int j = i + 1; j < prices.length; j++) {
				if(prices[i] > prices[j]) {
					q.offer(count + 1);
					break;
				}
				else
					count++;
			}
			if(count == prices.length - (i+1))
				q.offer(count);
		}
		
		int i = 0;
		while(!q.isEmpty()) {
			answer[i++] = q.poll();
		}
		//
		return answer;
	}

	public void printResult(int[] answer) {
		for(int i : answer)
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {

		Problem03 p = new Problem03();
		int[] prices = {1,2,3,2,3};
		int[] prices2 = {1,2,3,2,3,3,1};
		
		p.printResult(p.solution(prices));
		p.printResult(p.solution(prices2));
		
	}
}
