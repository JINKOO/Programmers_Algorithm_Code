package bfs_dfs;

import java.util.Arrays;

class Point {

    int x;
    int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class BFS {

    char[][] keyboard = new char[5][6];
    boolean[][] visited = new boolean[5][6];

    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, -1, 0, 1};

    public void findPosition(char target) {
        for (int i = 0; i < keyboard.length; i++) {
            for (int j = 0; j < keyboard[i].length; j++) {
                if (keyboard[i][j] == target) {
                    return;
                }
            }
        }
    }

    public int solution(String param) {
        int answer = 0;

        // keyboard 만들기
        char alphabet = 'A';
        for (int i = 0; i < keyboard.length; i++) {
            for (int j = 0; j < keyboard[i].length; j++) {
                keyboard[i][j] = alphabet++;
                System.out.print(keyboard[i][j]);
            }
            System.out.println();
        }

        // bfs 시작할 좌표 구하기.
        for (int i = 0; i < param.length(); i++) {
            findPosition(param.charAt(i));
        }
        return answer;
    }

    public static void main(String[] args) {

        BFS sol = new BFS();
        sol.solution("HAPPY");
    }
}
