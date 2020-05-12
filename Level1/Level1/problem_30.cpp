/*
  #. [ �ϻ��� �� ]

  #. ���� ����
     ���� ���� x�� �ϻ��� ���̷��� x�� �ڸ����� ������ x�� ���������� �մϴ�. 
     ���� ��� 18�� �ڸ��� ���� 1+8=9�̰�, 18�� 9�� ������ �������Ƿ� 18�� �ϻ��� ���Դϴ�. 
     �ڿ��� x�� �Է¹޾� x�� �ϻ��� ������ �ƴ��� �˻��ϴ� �Լ�, solution�� �ϼ����ּ���.

  #. ���� ����
     x�� 1 �̻�, 10000 ������ �����Դϴ�.

  #. ����� ��
     arr	return
      10	  true
      12	  true
      11	 false
      13	 false
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) 
{
    bool answer = true;
    //
    string str = to_string(x);
    int total = 0;
    for (int i = 0; i < str.length(); i++)
        total += str[i] - '0';
    x % total == 0 ? answer : answer = false;
    //
    return answer;
}

void printResult(bool answer)
{
    cout << answer << "\n";
}

int main()
{

    printResult(solution(10));
    printResult(solution(12));
    printResult(solution(13));
    printResult(solution(9876));

    return 0;
}
