/*
 *  #. [ 프로그래머스_여행경로 Level 3 ]
 *  
 *  #. 문제 설명
 *     주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 ICN 공항에서 출발합니다.
 *     항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 
 *     방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한사항
 *     - 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
 *     - 주어진 공항 수는 3개 이상 10,000개 이하입니다.
 *     - tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
 *     - 주어진 항공권은 모두 사용해야 합니다.
 *     - 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
 *     - 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
 *     
 *  #. 입출력 예
 *                                                          tickets	     return
 *                             [[ICN, JFK], [HND, IAD], [JFK, HND]]	     [ICN, JFK, HND, IAD]
 *     [[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL, SFO]]	     [ICN, ATL, ICN, SFO, ATL, SFO]
 *     
 *  #. 입출력 예 설명
 *     - 예제 #1
 *       [ICN, JFK, HND, IAD] 순으로 방문할 수 있습니다.
 *     - 예제 #2
 *       [ICN, SFO, ATL, ICN, ATL, SFO] 순으로 방문할 수도 있지만,
 *       [ICN, ATL, ICN, SFO, ATL, SFO] 가 알파벳 순으로 앞섭니다.
 */

/*
 *  #. 나의 풀이법.
 *     - 각 항공권의 연결 정보를 2차원 배열에 나타낸 후에, DFS를 수행하려 하였다.
 *     - 굳이 이렇게 안해도 된다. 
 *     - 하루종일 해매다가 못풀었다.구글링함.
 *     
 *  #. 풀이법.
 *     - 우선, 항공권의 도착지가 다른 항공권의 출발지와 같다면, 탐색을 수행한다. DFS
 *     - 이때, 모든 경우의 경로를 따져봐야 한다. 이 경로들을 ArrayList에 집어 넣고, 오름 차순 정렬을 한다.  
 *  
 *  #. 참고 백준_연구실 문제와 비슷.
 *  
 */
package dfs_bfs;

import java.util.ArrayList;
import java.util.Collections;

public class Problem04 {

	private ArrayList<String> list = new ArrayList<>();
	private boolean[] check;
	private String route = "";
	
	void dfs(String[][] tickets, int index, int count, String des) {
	
		//0. dfs에서 결과 문자열 처리 이렇게도 할 수 있다.
		route += des + ",";
		
		//1. 경로  = 항공권의 개수 이다.
		if(count == tickets.length) {
			list.add(route);
			return;
		}
		
		//check[index] = true;
		
		for(int i = 0; i < tickets.length; i++) {
			if(tickets[i][0].equals(des) && check[i] == false) {
				check[index] = true;
				dfs(tickets, i, count + 1, tickets[i][1]);
				//모든 경우의 수를 따져보기 위해 이렇게 한다. 방문처리를 해제 하고, route또한 한개의 공항이름만큼 지운다.
				check[index] = false;
				route  = route.substring(0, route.length() - 4);
			}
		}
	}
	
	public String[] solution(String[][] tickets) {
		String[] answer = {};
		//
		//모든 경우의 수를 따져야 하므로, check배열을 매번 초기화한다.
		for(int i = 0; i < tickets.length; i++) {
			this.check = new boolean[tickets.length];
			if(tickets[i][0].equals("ICN") && check[i] == false) {
				route = tickets[i][0] + ",";
				dfs(tickets, i, 1, tickets[i][1]);
			}
		}
		
		//System.out.println(list.size());
		
		//list의 개수는 1개일 수도 있고, 여러개 일 수 있다.알파벳 순 정렬하면, 0번째가 답이다.
		Collections.sort(list);
		answer = list.get(0).split(",");
		//
		return answer;
	}
	
	public void printResult(String[] answer) {
		for(int i = 0; i < answer.length; i++) {
			 if(i != answer.length - 1)
			    System.out.print(answer[i] + ", ");
			else
				System.out.print(answer[i]);
		}
		System.out.println();
	}
	
	public static void main(String[] args) {

		Problem04 p = new Problem04();
		String[][] tickets = { { "ICN", "JFK" }, { "HND", "IAD" }, { "JFK", "HND" }, };
		p.printResult(p.solution(tickets));
		
		Problem04 p2 = new Problem04();
		String[][] tickets2 = { { "ICN", "SFO" }, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" },
				{ "ATL", "SFO" } };
		p2.printResult(p2.solution(tickets2));
		
		Problem04 p3 = new Problem04();
		String[][] tickets3 = { { "ICN", "A" }, { "ICN", "B" }, { "B", "ICN" }};
		p3.printResult(p3.solution(tickets3));
		
		
	}
}
