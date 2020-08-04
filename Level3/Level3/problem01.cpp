/*
   #. [ 프로그래머스_가장 먼 노드 Level 3 ]
   
   #. 문제 설명
      n개의 노드가 있는 그래프가 있습니다. 각 노드는 1부터 n까지 번호가 적혀있습니다. 
      1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다. 
      가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.
      
      노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때, 
      1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.

   #. 제한사항
      - 노드의 개수 n은 2 이상 20,000 이하입니다.
      - 간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
      - vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.
      
   #. 입출력 예
      n	                                                  vertex	return
      6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	     3

   #. 입출력 예 설명
      예제의 그래프를 표현하면 아래 그림과 같고, 1번 노드에서 가장 멀리 떨어진 노드는 4,5,6번 노드입니다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[20001][20001];
//record가 방문처리 기능도 하게 된다. !=0이면, 기록된 곳이므로 방문한곳
int record[20001];

void bfs(int n, int start)
{
    queue<int> q;
    
    q.push(start);
    record[start] = 1;

    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();

        for (int k = 1; k <= n; k++) {
            if (map[curr][k] == 1 && record[k] == 0) {
                record[k] = record[curr] + 1;
                q.push(k);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    //
    for (int i = 0; i < edge.size(); i++)
    {
        map[edge[i][0]][edge[i][1]] = 1;
        map[edge[i][1]][edge[i][0]] = 1;
    }

    bfs(n, 1);

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < record[i])
            max = record[i];
    }

    for (int i = 1; i <= n; i++) {
        if (max == record[i])
            answer++;
    }
    
    //
    return answer;
}

int main()
{
    vector<vector<int>> edge = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };
    cout << solution(6, edge) << "\n";

}