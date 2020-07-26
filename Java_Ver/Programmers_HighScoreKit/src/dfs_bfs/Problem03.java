/*
 *  #. [ 프로그래머스_단어 변환 Level 3 ]
 *  
 *  #. 문제 설명
 *     두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 
 *     아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.
 *  
 *     1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
 *     2. words에 있는 단어로만 변환할 수 있습니다.
 *  
 *     예를 들어 begin이 hit, target가 cog, words가 [hot, dot, dog, lot, log, cog]라면,
 *     hit -> hot -> dot -> dog -> cog와 같이 4단계를 거쳐 변환할 수 있습니다.
 *     
 *     두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 
 *     최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.
 *     
 *  #. 제한사항
 *     - 각 단어는 알파벳 소문자로만 이루어져 있습니다.
 *     - 각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
 *     - words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
 *     - begin과 target은 같지 않습니다.
 *     -변환할 수 없는 경우에는 0를 return 합니다.
 *  
 *  #. 입출력 예
 *     begin	target	                         words	 return
 *       hit	   cog	[hot, dot, dog, lot, log, cog]	      4
 *       hit	   cog	     [hot, dot, dog, lot, log]	      0
 */

/*
 *  #. 나의 풀이법.
 *     - 최단 변환 수를 구하는 것이므로, BFS로 접근 하였다.
 *     - Queue에 삽입 할 원소를 Pair형으로 하였다.
 *       String과 words[]에서 해당 String의 index를 저장한다.
 *     - record가 필요하다. 변환 된 단어이면, 이전 단어의 record + 1;
 *       record[index]의미는 현재 단어까지 변환 횟수이다.
 *     - 단어가 변환되는 것은 두 String을 비교하는데 같지 않은 char가 오직 1개여야 한다.
 *     
 *                    1      2      3      4     5
 *     hit(begin) -> hot -> dot -> dog -> cog(target)
 *                              -> lot -> log -> cog(target)
 *                       -> lot -> log -> cog(target)
 *     이 중 최소 변환 수는 4이다.
 */
package dfs_bfs;

import java.util.LinkedList;
import java.util.Queue;

class Pair {
	
	String str;
	int index;
	
	Pair(String str, int index) {
		this.str = str;
		this.index = index;
	}
}

public class Problem03 {
	
	private boolean[] check;    //해당 문자열 index 방문 처리 배열
	private int[] record;       //해당 문자열까지의 변환 횟수 저장 배열
	
	public Problem03() {
		this.check = new boolean[50];
		this.record = new int[50];
	}
	
	public boolean compareString(String curr, String next) {
		int count = 0;
		
		for(int i = 0; i < curr.length(); i++) {
			if(curr.charAt(i) != next.charAt(i))
				count++;
		}
		
		return (count == 1) ? true : false;
	}
	
	public int bfs(String[] words, int index, String begin, String target) {
		
		Queue<Pair> q = new LinkedList<>();
		
		q.offer(new Pair(begin, index));
		check[index] = true;
		
		//1. 일단 bfs함수에 진입했다는 뜻은 begin에서 변횐된 단어가 있다는 뜻이므로, 해당 단어가 존재하는 index에 1기록.
		record[index] = 1;
		
		while(!q.isEmpty()) {
			Pair curr = q.poll();
			
			//2. target과 일치하는 단어 이면, 현재 까지의 변환 횟수 return.
			if(curr.str.equals(target))
				return record[curr.index];
			
			for(int k = 0; k < words.length; k++) {
				String next = words[k];
				//3. 변환 가능한 단어이고, 아직 방문하지 않았던 index이면,
				if(compareString(curr.str, next) && check[k] == false) {
					//3.1 방문처리 하고
					check[k] = true;
					//3.2 이전 단어 까지의 변환 횟수 + 1
					record[k] = record[curr.index] + 1;
					//3.3 Queue에 삽입
					q.offer(new Pair(next, k));
				}
			}
		}
		return 0;
	}
	
	public int solution(String begin, String target, String[] words) {
		int answer = 0;
		//
		for(int i = 0; i < words.length; i++) {
			String next = words[i];
			if(compareString(begin, next) && check[i] == false) {
				answer = bfs(words, i, next, target);
			}
		}
		
		//
		return answer;
	}
	
	public void printResult(int answer) {
		System.out.println(answer);
	}
	
	public static void main(String[] args) {
		
		Problem03 p = new Problem03();
		
		String begin = "hit";
		String target = "cog";
		String[] words = {"hot", "dot", "dog", "log", "lot", "cog"};
		p.printResult(p.solution(begin, target, words));
		
		p.check = new boolean[50];
		
		String begin2 = "hit";
		String target2 = "cog";
		String[] words2 = {"hot", "dot", "dog", "lot"};
		p.printResult(p.solution(begin2, target2, words2));
	}
}
