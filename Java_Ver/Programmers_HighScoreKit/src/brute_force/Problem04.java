/*
 *  #. [ 프로그래머스_카펫 Level 2 ]
 *  
 *  #. 문제 설명
 *     Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
 *     Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.
 *     
 *     Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때, 
 *     카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한사항
 *     - 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
 *     - 노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
 *     - 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
 *  
 *  #. 입출력 예
 *     brown	yellow	return
 *        10	     2	[4, 3]
 *         8	     1	[3, 3]
 *        24	    24	[8, 6]
 */

/**
 *  #. 나의 풀이법.
 *     - 예전에 한 번에 풀었던 문제 였는데, 다시 풀 때 못 풀었다...
 *     - 도대체 뭐가 문제 인가.
 *     
 *     - 파라미터로 넘어온 yellow의 개수를 기반으로, yellow의 약수를 구한다.
 *       이 약수는 width, (yellow / 약수)는 height로 설정하여 
 *       Yellow가 될 수 있는 후보 길이들을 list에 저장하고,
 *       후보들 중에서 brown의 개수와 같을 때의 
 *       최종 카펫의 width, height가 정답이 된다.
 * 
 */

package brute_force;

import java.util.ArrayList;

class Carpet {
	int width;
	int height;
	
	Carpet(int width, int height) {
		this.width = width;
		this.height = height;
	}
}
public class Problem04 {

	public int[] solution(int brown, int yellow) {
		int[] answer = {};
		//
		answer = new int[2];
		//0. carpet이 될수 있는 후보들
		ArrayList<Carpet> list = new ArrayList<>();
		
		//1. i가 yellow의 약수이면, i와 yellow / i는 width, height의 후보가 된다.
		for(int i = 1; i <= yellow; i++) {
			if(yellow % i == 0) {
				int height = i;
				int width = yellow / i;
				
				if(width >= height) {
					list.add(new Carpet(width, height));
				}
				else 
					//break거는 이유 :: width >= height까지만 반복하기 위해. 반복 횟수 줄이기 위해
					break;
			}
		}
		
		//2. 후보들 중, brown의 개수와 일치 할 때의 y_width, y_height를 통하여 카펫 가로, 세로 구한다.
		for(int i = 0; i < list.size(); i++) {
			int y_width = list.get(i).width;
			int y_height = list.get(i).height;
			
			if(((y_width + 2) + (y_height + 2)) * 2 - 4 == brown) {
				answer[0] = y_width + 2;
				answer[1] = y_height + 2;
			}
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
		
		Problem04 p = new Problem04();
		
		p.printResult(p.solution(10, 2));
		p.printResult(p.solution(8, 1));
		p.printResult(p.solution(24, 24));
	}
}
