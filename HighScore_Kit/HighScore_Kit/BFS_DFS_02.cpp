/*
  #. [ 네트워크 ]
  
  #. 문제 설명
     네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 
     예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 
     컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 
     따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

  #. 컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 
     네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

  #. 제한사항
     - 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
     - 각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
     - i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
     - computer[i][i]는 항상 1입니다.
  
  #. 입출력 예
     n	                        computers	return
     3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	     2
     3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	     1
*/

#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int check[200];

/*
  #. 아주 간단한 bfs 문제
  #. 접근법
     - 여기서 2차원 배열은, 지도가 아니라, 그래프 간 연결 정보이다.
       따라서 방문처리 배열이 2차원 일 필요가 없다.
     - 우선, 첫 번째 부터 시작하여, 방문처리를 하면서 탐색한다.
*/
void bfs(int n, int i, vector<vector<int>> computers)
{
    queue<int> q;

    q.push(i);
    check[i] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        //꺼낸 것과 인접한 것 중, 방문하지 않은 곳 찾고 방문처리 
        for (int k = 0; k < n; k++)
        {
            if (computers[x][k] == 1 && check[k] == false)
            {
                q.push(k);
                check[k] = true;
            }
        }
    }
}

void dfs(int n, int i, vector<vector<int>> computers)
{
    if (check[i])
        return;

    for (int k = 0; k < n; k++)
    {
        if (computers[i][k] == 1)
            bfs(n, k, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    //
    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
        {
            answer++;
            //bfs(n, i, computers);
            dfs(n, i, computers);
        }
    }
    //
    return answer;
}

int main()
{
    vector<vector<int>> computer1 = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    vector<vector<int>> computer2 = { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} };
    
    cout << solution(3, computer1) << "\n";
    memset(check, 0, sizeof(check));
    cout << solution(3, computer2) << "\n";

    return 0;
}