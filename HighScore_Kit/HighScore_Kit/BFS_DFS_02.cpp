/*
  #. [ ��Ʈ��ũ ]
  
  #. ���� ����
     ��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. 
     ���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, ��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� 
     ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�. 
     ���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

  #. ��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, 
     ��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

  #. ���ѻ���
     - ��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
     - �� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
     - i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers[i][j]�� 1�� ǥ���մϴ�.
     - computer[i][i]�� �׻� 1�Դϴ�.
  
  #. ����� ��
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
  #. ���� ������ bfs ����
  #. ���ٹ�
     - ���⼭ 2���� �迭��, ������ �ƴ϶�, �׷��� �� ���� �����̴�.
       ���� �湮ó�� �迭�� 2���� �� �ʿ䰡 ����.
     - �켱, ù ��° ���� �����Ͽ�, �湮ó���� �ϸ鼭 Ž���Ѵ�.
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
        
        //���� �Ͱ� ������ �� ��, �湮���� ���� �� ã�� �湮ó�� 
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