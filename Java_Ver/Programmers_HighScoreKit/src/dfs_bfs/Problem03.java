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

	private int[] record;
	private boolean[] check;
	
	public Problem03() {
		this.record = new int[50];
		this.check = new boolean[50];
	}
	
	public int bfs(String[] words, int index, String begin, String target) {
		
		Queue<Pair> q = new LinkedList<>();
		
		q.offer(new Pair(begin, index));
		check[index] = true;
		record[index] = 1;
		
		while(!q.isEmpty()) {
			Pair curr = q.poll();
			
			if(curr.str.equals(target))
				return record[curr.index];
	
			for(int k = 0; k < words.length; k++) {
				String next = words[k];
				int count = 0;
				for(int i = 0; i < next.length(); i++) {
					if(curr.str.charAt(i) != next.charAt(i))
						count++;
				}
				
				if(count == 1 && check[k] == false) {
					check[k] = true;
					record[k] = record[curr.index] + 1;
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
			String curr = words[i];
			int count = 0;
			for(int j = 0; j < begin.length(); j++) {
				if(curr.charAt(j) != begin.charAt(j))
					count++;
			}
			//System.out.println(count);
			if(count == 1 && check[i] == false) {
				answer = bfs(words, i, curr, target);
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
