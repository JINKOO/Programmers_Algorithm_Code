/*
  #. [ ������ ]
  #. ���� ����
     �Ϲ����� �����ʹ� �μ� ��û�� ���� ������� �μ��մϴ�. 
     �׷��� ������ �߿��� ������ ���߿� �μ�� �� �ֽ��ϴ�. 
     �̷� ������ �����ϱ� ���� �߿䵵�� ���� ������ ���� �μ��ϴ� �����͸� �����߽��ϴ�. 
     �� ���Ӱ� ������ �����ʹ� �Ʒ��� ���� ������� �μ� �۾��� �����մϴ�.
     
     1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
     2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� J�� ������� ���� �������� �ֽ��ϴ�.
     3. �׷��� ������ J�� �μ��մϴ�.
     
     ���� ���, 4���� ����(A, B, C, D)�� ������� �μ� ����Ͽ� �ְ� �߿䵵�� 2 1 3 2 ��� 
     C D A B ������ �μ��ϰ� �˴ϴ�.
     
     ���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� �˰� �ͽ��ϴ�. 
     ���� ������ C�� 1��°��, A�� 3��°�� �μ�˴ϴ�.
     
     ���� ����Ͽ� �ִ� ������ �߿䵵�� ������� ��� �迭 priorities�� 
     ���� �μ⸦ ��û�� ������ ���� ������� � ��ġ�� �ִ����� �˷��ִ� location�� �Ű������� �־��� ��, 
     ���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���ѻ���
     - ���� ����Ͽ��� 1�� �̻� 100�� ������ ������ �ֽ��ϴ�.
     - �μ� �۾��� �߿䵵�� 1~9�� ǥ���ϸ� ���ڰ� Ŭ���� �߿��ϴٴ� ���Դϴ�.
     - location�� 0 �̻� (���� ����Ͽ� �ִ� �۾� �� - 1) ������ ���� ������ ������� ���� �տ� ������ 0, 
       �� ��°�� ������ 1�� ǥ���մϴ�.

  #. ����� ��
             priorities	   location	        return
           [2, 1, 3, 2]	          2	             1
     [1, 1, 9, 1, 1, 1]	          0	             5
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    //
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    vector<int> order;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty())
    {
        if (q.front().second == pq.top())
        {
            order.push_back(q.front().first);
            q.pop();
            pq.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }

    for (int i = 0; i <= order.size(); i++)
    {
        if (order[i] == location)
        {
            answer = i + 1;
            break;
        }
    }

    //
    return answer;
}

int main()
{
    cout << solution({ 2, 1, 3, 2 }, 2) << "\n";
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << "\n";
    return 0;
}