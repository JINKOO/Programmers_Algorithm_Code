/*
   #. [ ���α׷��ӽ�_���� �� ��� Level 3 ]
   
   #. ���� ����
      n���� ��尡 �ִ� �׷����� �ֽ��ϴ�. �� ���� 1���� n���� ��ȣ�� �����ֽ��ϴ�. 
      1�� ��忡�� ���� �ָ� ������ ����� ������ ���Ϸ��� �մϴ�. 
      ���� �ָ� ������ ���� �ִܰ�η� �̵����� �� ������ ������ ���� ���� ������ �ǹ��մϴ�.
      
      ����� ���� n, ������ ���� ������ ��� 2���� �迭 vertex�� �Ű������� �־��� ��, 
      1�� ���κ��� ���� �ָ� ������ ��尡 �� �������� return �ϵ��� solution �Լ��� �ۼ����ּ���.

   #. ���ѻ���
      - ����� ���� n�� 2 �̻� 20,000 �����Դϴ�.
      - ������ ������̸� �� 1�� �̻� 50,000�� ������ ������ �ֽ��ϴ�.
      - vertex �迭 �� �� [a, b]�� a�� ���� b�� ��� ���̿� ������ �ִٴ� �ǹ��Դϴ�.
      
   #. ����� ��
      n	                                                  vertex	return
      6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	     3

   #. ����� �� ����
      ������ �׷����� ǥ���ϸ� �Ʒ� �׸��� ����, 1�� ��忡�� ���� �ָ� ������ ���� 4,5,6�� ����Դϴ�.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[20001][20001];
//record�� �湮ó�� ��ɵ� �ϰ� �ȴ�. !=0�̸�, ��ϵ� ���̹Ƿ� �湮�Ѱ�
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