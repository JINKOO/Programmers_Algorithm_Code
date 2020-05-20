/*
  #. [ ��ɰ��� ]
  #. ���� ����
     ���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. 
     �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.

  #. ��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, 
     �̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.
     ���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� 
     �� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� �� 
     �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

  #. ���� ����
     - �۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
     - �۾� ������ 100 �̸��� �ڿ����Դϴ�.
     - �۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
     - ������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�. 
       ���� ��� �������� 95%�� �۾��� ���� �ӵ��� �Ϸ翡 4%��� ������ 2�� �ڿ� �̷�����ϴ�.

  #. ����� ��
     progresses	  speeds	return
     [93,30,55]	[1,30,5]	 [2,1]
*/

#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    //
    queue<int> q;
    for (int i = 0; i < speeds.size(); i++)
    {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];
        if (remain % speeds[i] != 0)
            day += 1;
        q.push(day);
    }

    int count = 0;
    int first = q.front();
    while (!q.empty())
    {
        if (first < q.front())
        {
            answer.push_back(count);
            first = q.front();
            count = 0;
        }
        else
        {
            count++;
            q.pop();
        }
    }
    answer.push_back(count);
    //
    return answer;
}

void printResult(vector<int> answer)
{
    for (int i : answer)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    
    printResult(solution({ 93,30,55 }, { 1,30,5 }));

    return 0;
}










