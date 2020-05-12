/*
  #. [ ���� ������ �Ǻ� ]
  #. ���� ����
     ������ ���� ���� n�� ����, n�� � ���� ���� x�� �������� �ƴ��� �Ǵ��Ϸ� �մϴ�.
     n�� ���� ���� x�� �����̶�� x+1�� ������ �����ϰ�, 
     n�� ���� ���� x�� ������ �ƴ϶�� -1�� �����ϴ� �Լ��� �ϼ��ϼ���.

  #. ���� ����
     n�� 1�̻�, 50000000000000 ������ ���� �����Դϴ�.

  #. ����� ��
       n	    return
     121	       144
       3	        -1
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    //
    long long m = sqrt(n);
    if (m * m == n)
        answer = pow(m, 2);
    else
        answer = -1;
    //
    return answer;
}

int main()
{
    cout << solution(121) << "\n";
    cout << solution(3) << "\n";
    return 0;
}