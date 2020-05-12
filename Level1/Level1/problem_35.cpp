/*
  #. [ ���� ] - Summer/Winter Coding 2018

  #. ���� ����
     S�翡���� �� �μ��� �ʿ��� ��ǰ�� ������ �ֱ� ���� �μ����� ��ǰ�� �����ϴµ� �ʿ��� �ݾ��� �����߽��ϴ�. 
     �׷���, ��ü ������ ������ �ֱ� ������ ��� �μ��� ��ǰ�� ������ �� ���� �����ϴ�. 
     �׷��� �ִ��� ���� �μ��� ��ǰ�� ������ �� �� �ֵ��� �Ϸ��� �մϴ�.

     ��ǰ�� ������ �� ���� �� �μ��� ��û�� �ݾ׸�ŭ�� ��� ������ ��� �մϴ�. 
     ���� ��� 1,000���� ��û�� �μ����� ��Ȯ�� 1,000���� �����ؾ� �ϸ�, 
     1,000������ ���� �ݾ��� ������ �� ���� �����ϴ�.

     �μ����� ��û�� �ݾ��� ����ִ� �迭 d�� ���� budget�� �Ű������� �־��� ��, 
     �ִ� �� ���� �μ��� ��ǰ�� ������ �� �ִ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

  #. ���ѻ���
     d�� �μ����� ��û�� �ݾ��� ����ִ� �迭�̸�, ����(��ü �μ��� ����)�� 1 �̻� 100 �����Դϴ�.
     d�� �� ���Ҵ� �μ����� ��û�� �ݾ��� ��Ÿ����, �μ��� ��û �ݾ��� 1 �̻� 100,000 ������ �ڿ����Դϴ�.
     budget�� ������ ��Ÿ����, 1 �̻� 10,000,000 ������ �ڿ����Դϴ�.
     
  #. ����� ��
               d    budget	  result
     [1,3,2,5,4]	     9	       3
       [2,2,3,3]	    10	       4
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max(vector<int> d, int budget)
{
    int count = 0;

    return count;
}

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    //
    sort(d.begin(), d.end());
    int total = 0;
    for (int i = 0; i < d.size(); i++)
    {
        if ((total += d[i]) <= budget)
            answer++;
        else
            break;
    }
    //
    return answer;
}

void printResult(int answer)
{
    cout << answer << "\n";
}

int main()
{
    printResult(solution({ 1,3,2,5,4 }, 9));
    printResult(solution({ 2,2,3,3 }, 10));

    return 0;
}