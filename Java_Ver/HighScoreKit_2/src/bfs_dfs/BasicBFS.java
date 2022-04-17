package bfs_dfs;

import java.util.*;

class Pair {
    int i;
    int j;

    Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }
}

public class BasicBFS {

    int n;
    int m;

    int[][] board = new int[500][500];
    boolean[][] visited = new boolean[500][500];

    int[] di = {-1, 0, 1, 0};
    int[] dj = {0, -1, 0, 1};

    public int bfs(Pair p) {

        int pictureArea = 1;

        // Queue
        Queue<Pair> queue = new LinkedList<>();
        queue.add(p);
        visited[p.i][p.j] = true;

        while(!queue.isEmpty()) {
            Pair curr = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int ni = curr.i + di[dir];
                int nj = curr.j + dj[dir];

                // 범위 안에 존재해야하고,
                if ((0 <= ni && ni < n) && (0 <= nj && nj < m)) {
                    // 그림의 일부이며, 아직 방문하지 않은 곳이면
                    if (board[ni][nj] == 1 && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        queue.add(new Pair(ni, nj));
                        pictureArea++;
                    }
                }
            }
        }
        return pictureArea;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        BasicBFS b = new BasicBFS();
        b.n = 6;
        b.m = 5;

        // init board
        for (int i = 0; i < b.n; i++) {
            for (int j = 0; j < b.m; j++) {
                b.board[i][j] = sc.nextInt();
            }
        }

        // start bfs
        int pictureCount = 0;
        int maxPictureArea = 0;
        List<Integer> pictureList = new ArrayList<>();
        for (int i = 0; i < b.n; i++) {
            for (int j = 0; j < b.m; j++) {
                if (b.board[i][j] == 1 && !b.visited[i][j]) {
                    pictureList.add(b.bfs(new Pair(i, j)));
                    pictureCount++;
                }
            }
        }
        Collections.sort(pictureList, Collections.reverseOrder());
        maxPictureArea = pictureList.get(0);

        System.out.println(pictureCount);
        System.out.println(maxPictureArea);
    }
}
