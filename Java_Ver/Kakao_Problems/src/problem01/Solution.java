/*
 *  #. [ 카카오기출_2017 카카오코드 예선_카카오프렌즈 컬러링북 ]
 *  
 *  #. 문제 설명 _ 카카오 프렌즈 컬러링북
 *     출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 
 *     여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 
 *     그림의 난이도를 영역의 수로 정의하였다. (영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)
 *     
 *     그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.
 *     
 *     위의 그림은 총 12개 영역으로 이루어져 있으며, 가장 넓은 영역은 어피치의 얼굴면으로 넓이는 120이다.
 *     
 *  #. 입력 형식
 *     입력은 그림의 크기를 나타내는 m과 n, 그리고 그림을 나타내는 m × n 크기의 2차원 배열 picture로 주어진다. 
 *     제한조건은 아래와 같다.
 *     - 1 <= m, n <= 100
 *     - picture의 원소는 0 이상 2^31 - 1 이하의 임의의 값이다.
 *     - picture의 원소 중 값이 0인 경우는 색칠하지 않는 영역을 뜻한다.
 *     
 *  #. 출력 형식
 *     리턴 타입은 원소가 두 개인 정수 배열이다. 그림에 몇 개의 영역이 있는지와 가장 큰 영역은 몇 칸으로 이루어져 있는지를 리턴한다.
 *     
 *  #. 예제 입출력
 *  	m	n	picture	                                               answer
 *		6	4	[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], 
 *		        [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]	           [4, 5]
 *
 *  #. 예제에 대한 설명
 *     예제로 주어진 그림은 총 4개의 영역으로 구성되어 있으며, 
 *     왼쪽 위의 영역과 오른쪽의 영역은 모두 1로 구성되어 있지만 상하좌우로 이어져있지 않으므로 다른 영역이다. 
 *     가장 넓은 영역은 왼쪽 위 1이 차지하는 영역으로 총 5칸이다.
 */

/**
 *  #. 나의 풀이법.
 *     - 기존에 풀었던 백준, 프로그래머스의 BFS, DFS문제와 비슷
 *     - 여기서의 유형은, 2차원 배열에서 상하좌우 움직여 각 원소값과 같은 지역 수 를 계산하고,
 *       가장 큰 영역의 개수를 구하는 것.
 *     
 *     1.처음 풀고 맞춰버렸다!! 하지만, 처음 풀었을 때, picture의 원소를 파악하기위하여, HashMap을 사용하였다.
 *       HashMap<Integer, Integer>인데 key를 picture의 원소로  하였다. value는 0.
 *       이후, keyset을 만들어 Iterator를 활용하여 해당 색깔과 picture 배열을 반복하면서 BFS수행.
 *       --> 삼중 for문이 들어간다.
 *    
 *     2.제출하고, 코드 다시 살펴보다가, 굳이 HashMap을 사용하지 않고, 풀 수 있다는 것을 알았다.
 *       어쩌피 check배열이 있으므로, 현재 color기반 BFS를 수행한다.  
 *       
 *     - Queue<Pair>를 사용 
 *     - BFS개념, 백준 문제 풀었다면, 딱히 어려운 문제는 아니였다.
 */

package problem01;

import java.util.LinkedList;
import java.util.Queue;

class Pair {
	int i;
	int j;

	Pair(int i, int j) {
		this.i = i;
		this.j = j;
	}
}

public class Solution {

	private boolean[][] check;
	private int[] di = { -1, 0, 1, 0 };
	private int[] dj = { 0, -1, 0, 1 };

	/**
	 * 
	 * @param pictures :: pictures배열
	 * @param c        :: BFS탐색 할 때, 기준이 되는 picture의 원소(color)
	 * @param m        :: pictures의 m
	 * @param n        :: pictures의 n
	 * @param i        :: 가장 처음 시작 위치
	 * @param j        :: 가장 처음 시작 위치   
	 * @return         :: c와 같은 영역의 원소 수 
	 * 
	 * 기존의 BFS방식과 유사.
	 */
	public int bfs(int[][] pictures, int c, int m, int n, int i, int j) {
		int count = 1;

		Queue<Pair> q = new LinkedList<>();

		q.offer(new Pair(i, j));
		check[i][j] = true;

		while (!q.isEmpty()) {

			Pair curr = q.poll();

			for (int k = 0; k < 4; k++) {
				int ni = curr.i + di[k];
				int nj = curr.j + dj[k];

				if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
					if (check[ni][nj] == false && pictures[ni][nj] == c) {
						check[ni][nj] = true;
						q.offer(new Pair(ni, nj));
						count++;
					}
				}

			}
		}
		return count;
	}

	public int[] solution(int m, int n, int[][] picture) {
		int numberOfArea = 0;
		int maxSizeOfOneArea = 0;
		//
		//1. check배열 초기화
		this.check = new boolean[m][n];
		
		//2. BFS수행 시작하기 위해
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				//2.1. BFS할 color 넘겨줄 변수
				int currentColor = picture[i][j];
				//2.2. BFS를 수행하게 되면, numberOfArea++
				int areaCount = 0;
				//3. 0이 아니고, 방문하지 않았던 원소이면, BFS수행
				if (currentColor != 0 && check[i][j] == false) {
					//3. BFS수행 후, 같은 색깔의 인접한 영역 수 return
					areaCount = bfs(picture, currentColor, m, n, i, j);
					//System.out.println(currentColor + ", " + areaCount);
					numberOfArea++;
				}
				
				//6.가장 큰 영역의 개수 설정.
				if (maxSizeOfOneArea < areaCount)
					maxSizeOfOneArea = areaCount;
			}
		}
		//
		int[] answer = new int[2];
		answer[0] = numberOfArea;
		answer[1] = maxSizeOfOneArea;

		return answer;
	}

	public void printResult(int[] answer) {
		for (int a : answer)
			System.out.print(a + " ");
		System.out.println();
	}

	public static void main(String[] args) {

		Solution s = new Solution();

		int[][] pictures = { { 1, 1, 1, 0 }, { 1, 2, 2, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 3 },
				{ 0, 0, 0, 3 } };

		s.printResult(s.solution(6, 4, pictures));
	}
}
