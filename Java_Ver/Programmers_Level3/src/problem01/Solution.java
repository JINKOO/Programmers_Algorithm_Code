/*
 *  #. [ 프로그래머스_가장 먼 노드 Level 3 ]
 *  
 *  #. 문제 설명
 *     - n개의 노드가 있는 그래프가 있습니다. 각 노드는 1부터 n까지 번호가 적혀있습니다. 
 *       1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다. 
 *       가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.
 *       
 *  #. 노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때, 
 *     1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한사항
 *     - 노드의 개수 n은 2 이상 20,000 이하입니다.
 *     - 간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
 *     - vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.
 *  
 *  #. 입출력 예
 *     n	                                                 vertex	    return
 *     6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	     3
 *     
 *  
 *  #. 입출력 예 설명
 *     예제의 그래프를 표현하면 아래 그림과 같고, 1번 노드에서 가장 멀리 떨어진 노드는 4,5,6번 노드입니다.
 */

/**
 *  #. 나의 풀이법.
 *     - BFS풀이는 맞았고, 테이스테이스 8,9번에서 계속 실패가 나옴.(시간 초과 아님)
 *       메모리 사용 초과경우여서, 어떻게 풀지 고민하다가
 *       인접리스트로 풀면 된다고 함.
 *     
 *     - 혹시 몰라서, C++로 map[20001][20001]과 record[20001]로 하여 풀어보았는데 거뜬히 성공함...
 *       왜 Java는 이럴 때 불리한 것인가!!!
 *       
 *     - ArrayList<ArrayList<Intger>>로 선언하여 사용하였다.
 *       index는 1부터 시작하도록 하였고, 연결된 원소들은 index가 0부터 시작한다. 
 *       
 */
package problem01;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

	//0. 인접 리스트 선언
	private ArrayList<ArrayList<Integer>> list;
	//1. 현재까지의 최단경로 중 최댓값 기록.
	private int[] record;
	
	public void bfs(int n, int start) {

		Queue<Integer> q = new LinkedList<>();
		
		q.offer(start);
		record[start] = 1;
		
		while(!q.isEmpty()) {
			
			int curr = q.poll();
			
			//list의 index는 노드를 의미한다. 즉, 해당 노드와 연결되어 있는 길이 만큼만 반복한다.
			for(int k = 0; k < list.get(curr).size(); k++) {
				if(record[list.get(curr).get(k)] == 0) {
					//여기가 중요한 포인트. 
					record[list.get(curr).get(k)] = record[curr] + 1;
					q.offer(list.get(curr).get(k));
				}
			}
		}
	}

	public int solution(int n, int[][] edge) {
		int answer = 0;
		//
		this.list = new ArrayList<>();
		this.record = new int[n + 1];
		
		//인접 리스트 초기화
		for(int i = 0; i < n + 1; i++) 
			list.add(new ArrayList<>());
		
		//edge의 연결 정보를 바탕으로 index[]에 각 노드를 연결 정보 초기화.
		for(int i = 0; i < edge.length; i++) {
			list.get(edge[i][0]).add(edge[i][1]);
			list.get(edge[i][1]).add(edge[i][0]);
		}
		
		bfs(n, 1);
		
		Arrays.sort(record);
		int max = record[record.length-1];
		
		for(int i = 0; i < record.length; i++) {
			if(max == record[i])
				answer++;
		}
		
		//
		return answer;
	}
	
	public static void main(String[] args) {
		
		Solution s = new Solution();
		
		int[][] edge = {
				{3,4},
				{2,3},
				{1,2},
				{4,6}
		};
		//System.out.println(s.solution(6, edge));
		
		int[][] edge2 = {
				{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}
		};
		System.out.println(s.solution(6, edge2));
	}
}







