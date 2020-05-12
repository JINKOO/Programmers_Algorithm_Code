/*
  #. [�Ҽ� ã��]
  
  #. ���� ����
     1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ������ ��ȯ�ϴ� �Լ�, solution�� ����� ������.
     �Ҽ��� 1�� �ڱ� �ڽ����θ� ���������� ���� �ǹ��մϴ�.
     (1�� �Ҽ��� �ƴմϴ�.)

  #. ���� ����
     n�� 2�̻� 1000000������ �ڿ����Դϴ�.
  
  #. ����� ��
      n	  result
     10	       4
      5        3
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    //
    vector<bool> is_prime(n, true);
    is_prime.at(0) = false;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i*i; j <= n; j += i)
        {
            is_prime.at(j - 1) = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (is_prime.at(i) == true)
            answer++;
    }
    //
    return answer;
}

int main()
{
    cout << solution(10) << "\n";

    return 0;
}






