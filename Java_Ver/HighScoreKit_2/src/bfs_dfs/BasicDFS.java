package bfs_dfs;

import java.util.Scanner;
import java.util.Stack;

public class BasicDFS {

    int n;
    int m;

    int[][] board = new int[500][500];
    boolean[][] isVisited = new boolean[500][500];

    int[] di = {-1, 0, 1, 0};
    int[] dj = {0, -1, -0, 1};

    public void dfs(Pair p) {
        Stack<Pair> stack = new Stack<>();
        stack.push(p);
        isVisited[p.i][p.j] = true;

        while (!stack.isEmpty()) {
            Pair curr = stack.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ni = curr.i + di[dir];
                int nj = curr.j + dj[dir];
                if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                    if (!isVisited[ni][nj] && board[ni][nj] == 1) {
                        isVisited[ni][nj] = true;
                        stack.push(new Pair(ni, nj));
                    }
                }
            }
        }
    }

    public static void main(String[] args) {

        BasicDFS bs = new BasicDFS();
        Scanner sc = new Scanner(System.in);
        bs.n = sc.nextInt();
        bs.m = sc.nextInt();

        for (int i = 0; i <bs.n; i++) {
            for (int j = 0; j < bs.m; j++) {
                bs.board[i][j] = sc.nextInt();
            }
        }

        int areaCount = 0;
        for (int i = 0; i < bs.n; i++) {
            for (int j = 0; j < bs.m; j++) {
                if (!bs.isVisited[i][j] && bs.board[i][j] == 1) {
                    bs.dfs(new Pair(i, j));
                    areaCount++;
                }
            }
        }
        System.out.println(areaCount);
    }
}
