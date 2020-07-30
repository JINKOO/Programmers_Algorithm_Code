package Problem01;

import java.util.HashMap;
import java.util.Iterator;
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
	private int[] di = {-1, 0, 1, 0};
	private int[] dj = {0, -1, 0, 1}; 
	
	public int bfs(int[][] pictures, int c, int m, int n, int i, int j) {
		int count = 1;
		
		Queue<Pair> q = new LinkedList<>();
		
		q.offer(new Pair(i, j));
		check[i][j] = true;
		
		while(!q.isEmpty()) {
			
			Pair curr = q.poll();
			
			for(int k = 0; k < 4; k++) {
				int ni = curr.i + di[k];
				int nj = curr.j + dj[k];
				
				if(ni >=0 && ni < m && nj >=0 && nj < n) {
					if(check[ni][nj] == false && pictures[ni][nj] == c) {
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

		HashMap<Integer, Integer> color = new HashMap<>();
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(picture[i][j] != 0)
					color.put(picture[i][j], 0);
			}
		}
		
		Iterator<Integer> iter = color.keySet().iterator();
		while(iter.hasNext()) {
			int c = iter.next();
			int result = 0;
			check = new boolean[m][n];
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(picture[i][j] == c && check[i][j] == false) {
						result = bfs(picture, c, m, n, i, j);
						numberOfArea++;
					}
					if(maxSizeOfOneArea < result)
						maxSizeOfOneArea = result;
				}
			}
		}
		
		int[] answer = new int[2];
		answer[0] = numberOfArea;
		answer[1] = maxSizeOfOneArea;
		
		return answer;
	}
	
	public void printResult(int[] answer) {
		for(int a : answer)
			System.out.print(a + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		
		Solution s = new Solution();
		
		int[][] pictures = {
				{1,1,1,0},
				{1,2,2,0},
				{1,0,0,1},
				{0,0,0,1},
				{0,0,0,3},
				{0,0,0,3}
		};
		
		s.printResult(s.solution(6, 4, pictures));
	}
}
