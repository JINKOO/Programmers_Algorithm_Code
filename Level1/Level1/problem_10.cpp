/*
  #. [�� ���� ������ �� ]

  #. ���� ����
     �� ���� a, b�� �־����� �� a�� b ���̿� ���� ��� ������ ���� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.
     ���� ��� a = 3, b = 5�� ���, 3 + 4 + 5 = 12�̹Ƿ� 12�� �����մϴ�.

  #. ���� ����
     a�� b�� ���� ���� �� �� �ƹ� ���� �����ϼ���.
     a�� b�� -10,000,000 �̻� 10,000,000 ������ �����Դϴ�.
     a�� b�� ��Ұ���� ���������� �ʽ��ϴ�.

  #. ����� ��
     a	 b	 return
     3	 5	 12
     3	 3	  3
     5	 3	 12
*/
#include <iostream>
#include <math.h>
using namespace std;

long long subAll(int min, int max)
{
    //int size = max - min + 1;
    //cout << min << ", " << max << ", " << size << "\n";
    return (long long) (max - min + 1) * (max + min) / 2;
}

long long solution(int a, int b)
{
    long long answer = 0;
    //
    answer = subAll(a < b ? a : b, a > b ? a : b);
    //
    return answer;
}
void print(long long answer)
{
    cout << answer << "\n";
}

int main()
{
    print(solution(3, 5));
    print(solution(-6, 1));
    print(solution(-15, -9));
    print(solution(-4, 2));
    print(solution(3, 11));
    return 0;
}