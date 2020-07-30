/*
 *  #. [ 프로그래머스_소수 찾기 Level 2 ]
 *  
 *  #. 문제 설명
 *     한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
 *     각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.
 *     
 *     
 *  #. 제한사항
 *     - numbers는 길이 1 이상 7 이하인 문자열입니다.
 *     - numbers는 0~9까지 숫자만으로 이루어져 있습니다.
 *     - 013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
 *     
 *  #. 입출력 예
 *     numbers	return
 *          17	3
 *          011	2
 *          
 *  #. 입출력 예 설명
 *     - 예제 #1
 *       [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.
 *       
 *     - 예제 #2
 *       [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
 *       11과 011은 같은 숫자로 취급합니다.
 */

/**
 *  #. 나의 풀이법.
 *     - brute force방식으로 푼다. numbers의 길이가 작기 때문에 가능하다. max구하면, 최대 7자리 정수
 *     - Greedy방식도 필요한데.
 *       numbers에서 만들수 있는 가장 최대의 숫자를 찾는다.
 *       1~max까지 반복하면서,
 *       각 숫자가 소수이며, numbers문자에 포함된 숫자인지 판별한다.
 * 
 */

package brute_force;

import java.util.Arrays;

public class Problem02 {

	public boolean isPrime(int num) {
		
		if(num == 1)
			return false;
		for(int i = 2; i*i <= num; i++) {
			if(num % i == 0)
				return false;
		}
		return true;
	}
	
	public boolean allContain(int num, String numbers) {
		
		String temp = Integer.valueOf(num).toString();
		//check배열의 용도 :: num = 11 , numbers 110일 때, 첫번쨰 1, 두번쨰 1 구분 위하여
		boolean[] check = new boolean[numbers.length()];
		int count = 0;
		for(int i = 0; i < temp.length(); i++) {
			for(int j = 0; j < numbers.length(); j++) {
				if(temp.charAt(i) == numbers.charAt(j) && check[j] == false) {
					check[j] = true;
					count++;
					//break거는 이유는, 첫번째 나온 1이 이미 나왔고, 두번째 1과 또다시 검사하면 안되기 때문.
					break;
				}
			}
		}
		return (count == temp.length() ? true : false);
	}
	
	public int solution(String numbers) {
		int answer = 0;
		//
		//c++에선 String이 vector처럼 동작할 수 있는데
		//Java에서는 이렇게 해줘야 한다.
		char[] temp = numbers.toCharArray();
		Arrays.sort(temp);
		
		StringBuilder sb = new StringBuilder(new String(temp));
		int number = Integer.parseInt(sb.reverse().toString());
		//여기까지가 max구하는 부분.
		
		for(int i = 1; i <= number; i++) {
			
			if(isPrime(i) && allContain(i, numbers)) {
				answer++;
			}
		}
		//
		return answer;
	}

	public static void main(String[] args) {

		Problem02 p = new Problem02();
		
		System.out.println(p.solution("011"));
		System.out.println(p.solution("17"));
	}
}
