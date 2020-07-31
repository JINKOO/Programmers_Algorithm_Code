/*
 *  #. [ 카카오기출_2017 카카오코드 예선_카카오프렌즈 컬러링북 ]
 *     - DFS버전
 * 
 * 
 */

package problem01;

public class Solution2 {

	private boolean[][] check;
	private int[] di = {-1,0,1,0};
	private int[] dj = {0,-1,0,1};
	private int areaCount;
	
	public void dfs(int[][] picture, int m, int n, int i, int j, int c) {
		
		if(check[i][j] == true)
			return;
		
		check[i][j] = true;
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if(ni >= 0 && ni < m && nj >=0 && nj < n) {
				if(picture[ni][nj] == c && check[ni][nj] == false) {
					dfs(picture, m, n, ni, nj, c);
					this.areaCount++;
				}
			}
		}
	}
	
	public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        //
        
        this.check = new boolean[m][n];
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		int currColor = picture[i][j];
        		this.areaCount = 1;
        		if(currColor != 0 && check[i][j] == false) {
        			dfs(picture, m, n, i, j, currColor);
        			numberOfArea++;
        		}
        		
        		if(maxSizeOfOneArea < this.areaCount)
        			maxSizeOfOneArea = this.areaCount;
        	}
        }
        
        //
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
	
	public void printResult(int[] answer) {
		for(int i : answer) 
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		
		Solution2 s = new Solution2 ();

		int[][] pictures = { { 1, 1, 1, 0 }, { 1, 2, 2, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 3 },
				{ 0, 0, 0, 3 } };
		s.printResult(s.solution(6, 4, pictures));
		
		int[][] pictures2 = {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};
		s.printResult(s.solution(6, 4, pictures2));
	}
}
