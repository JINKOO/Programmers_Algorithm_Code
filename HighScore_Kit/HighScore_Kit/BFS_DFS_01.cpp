/*
  #. [ Ÿ�� �ѹ� ]

  #. ���� ����
     n���� ���� �ƴ� ������ �ֽ��ϴ�. �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. 
     ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

     -1+1+1+1+1 = 3
     +1-1+1+1+1 = 3
     +1+1-1+1+1 = 3
     +1+1+1-1+1 = 3
     +1+1+1+1-1 = 3
     
     ����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� 
     ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���ѻ���
     - �־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
     - �� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
     - Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.

  #. �����
             numbers	target	  return
     [1, 1, 1, 1, 1]	     3	       5
*/

#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void dfs(int index, vector<int> numbers, int target, int total)
{
    if (index == numbers.size())
    {
        if (total == target)
            answer++;
        return;
    }

    dfs(index + 1, numbers, target, total + numbers[index]);
    dfs(index + 1, numbers, target, total + numbers[index] * -1);
}

int solution(vector<int> numbers, int target) 
{
    //
    dfs(0, numbers, target, 0);
    //
    return answer;
}

int main()
{
    vector<int> v = { 1,1,1,1,1 };
    cout << solution(v, 3) << "\n";

    return 0;
}
