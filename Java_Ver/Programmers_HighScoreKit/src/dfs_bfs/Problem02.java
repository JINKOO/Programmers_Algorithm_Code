/*
 *  #. [ 프로그래머스_네트워크 Level 2 ]
 *  
 *  #. 문제 설명
 *     네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 
 *     예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 
 *     컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 
 *     따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.
 *     
 *     컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 
 *     네트워크의 개수를 return 하도록 solution 함수를 작성하시오.
 *     
 *  #. 제한사항
 *     - 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
 *     - 각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
 *     - i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
 *     - computer[i][i]는 항상 1입니다.
 *     
 *  #. 입출력 예
 *     n	 computers	                        return
 *     3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	     2
 *     3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	     1
 *      
 */
/*
 *  #. 나의 풀이법.
 *     - DFS 탐색을 활용하면 된다.
 *     - 컴퓨터의 번호가 0 ~ n-1로 부여된다.
 *     - 컴퓨터의 연결 정보가 2차원 배열 형태로 제공되는데, 이제 껏 풀어왔던 BFS/DFS문제와는 다르게 이 이차원 배열은
 *       map이 아니다. i<--->j가 연결되어 있다는 정보를 나타내기 때문에, 좌우대칭 형태이다.
 *       --> check배열을 1차원 배열로만 사용해도 충분하다.
 * 
 * 
 */
package dfs_bfs;

public class Problem02 {
	
	private boolean[] check;
	
	public Problem02() {
		// TODO Auto-generated constructor stub
		this.check = new boolean[200];
	}
	
	/*
	 * 2.DFS탐색 함수.
	 *   - 해당 index번호의 computer와 연결된, computer가 있는지 탐색한다. 
	 * 
	 */
	public void dfs(int[][] computers, int n, int index) {
		
		if(check[index] == true)
			return;
		
		check[index] = true;
		
		for(int next = 0; next < n; next++) {
			if(computers[index][next] == 1)
				dfs(computers, n, next);
		}
	}
	
	public int solution(int n, int[][] computers) {
		int answer = 0;
	    //
		//1. 아직 연결정보를 파악하지 않은 컴퓨터이면, DFS수행하고, answer++;
		for(int i = 0; i < n; i++) {
			if(check[i] == false) {
				dfs(computers, n, i);
				answer++;
			}
		}
		//
		return answer;
	 }
	
	public static void main(String[] args) {
		
		Problem02 p = new Problem02();
//		int n = 3;
//		int[][] computers = {{1,1,0}, {1,1,0}, {0,0,1}};
//		System.out.println(p.solution(n, computers));
		
		int n2 = 3;
		int[][] computers2 = {{1,1,0}, {1,1,1}, {0,1,1}};
		System.out.println(p.solution(n2, computers2));
	}
}
