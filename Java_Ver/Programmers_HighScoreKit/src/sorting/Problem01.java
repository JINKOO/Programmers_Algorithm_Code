/*
 *  #. [ 프로그래머스_K번째수 Level 3 ]
 *  
 *  #. 문제 설명
 *     배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.
 *     예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
 *     array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
 *     1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
 *     2에서 나온 배열의 3번째 숫자는 5입니다.
 *     
 *     배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, 
 *     commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한사항
 *     - array의 길이는 1 이상 100 이하입니다.
 *     - array의 각 원소는 1 이상 100 이하입니다.
 *     - commands의 길이는 1 이상 50 이하입니다.
 *     - commands의 각 원소는 길이가 3입니다.
 *  
 *  #. 입출력 예
 *                   array	                         commands	  return
 *   [1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]
 *   
 *   
 *  #. 입출력 예 설명
 *     - [1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
 *     - [1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
 *     - [1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.
 */

/*  ##. Java에서의 객체 정렬 2가지 방법.
 *      1. Interface Comparable
 *         - 정렬 수행 시 기본적인 정렬 기준(오름차순, 내림차순, 사전순)
 *         - 현재 객체.compareTo(파라미터 객체) Override한다.
 *           현재 객체 < 파라미터 객체 = 음수 리턴;
 *           현재 객체 == 파라미터 객체 = 0;
 *           현재 객체 > 파라미터 객체 = 양수 리턴
 *           
 *           양수 리턴일때에만, 두 객체의 자리가 바뀐다.
 *        
 *         - Arrays.sort() :: 배열 정렬, 기본 자료형, 객체 배열 정렬 가능
 *         - Collections.sort() :: List Collection의 정렬(내부적으로 Arrays.sort())를 사용한다.)
 *      
 *      2. Interface Comparator
 *         - 기본 정렬 방식 외 사용자 정의 정렬 방식 
 *         - compare(파라미터1, 파라미터2) Override한다.
 *           파라미터1 < 파라미터2 = 음수 리턴
 *           파라미터1 == 파라미터1 = 0;
 *           파라미터1 > 파라미터2 = 양수 리턴
 *           
 *           양수 리턴일때만, 객체의 자리가 바뀐다.
 */
package sorting;

import java.util.Arrays;

public class Problem01 {

	public int[] solution(int[] array, int[][] commands) {
		int[] answer = {};
		//
		answer = new int[commands.length];
		for(int c = 0; c < commands.length; c++) {
			int i = commands[c][0] - 1;
			int j = commands[c][1] - 1;
			int k = commands[c][2] - 1;
			
			Integer[] temp = new Integer[j-i+1];
			int t = 0;
			for(int p = i; p <= j && t < temp.length; p++)
				//auto-boxing일어난다.
				temp[t++] = array[p];
			
			Arrays.sort(temp);
			
			answer[c] = temp[k];
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

		Problem01 p = new Problem01();

		int[] array = { 1, 5, 2, 6, 3, 7, 4 };
		int[][] commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
		
		p.printResult(p.solution(array, commands));
	}
}
