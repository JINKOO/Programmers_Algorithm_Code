/*
  #. [����� ��]
  #. ���� ����
     ���� n�� �Է¹޾� n�� ����� ��� ���� ���� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

  #. ���� ����
     n�� 0 �̻� 3000������ �����Դϴ�.
  
  #. ����� ��
      n	 return
     12	     28
     5	      6
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    //
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            answer += n / i;
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
    printResult(solution(12));

    return 0;
}








