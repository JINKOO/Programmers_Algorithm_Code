/*
  #. [���ڼ��ڼ��ڼ��ڼ��ڼ�?]
  #. ���� ����
     ���̰� n�̰�, ���ڼ��ڼ��ڼ�....�� ���� ������ 
     �����ϴ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���. 
     ������� n�� 4�̸� ���ڼ����� �����ϰ� 3�̶�� ���ڼ��� �����ϸ� �˴ϴ�.

  #. ���� ����
     n�� ���� 10,000������ �ڿ����Դϴ�.
    
  #. ����� ��
     n	  return
     3	  ���ڼ�
     4	  ���ڼ���
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) 
{
    string answer = "";
    //
    string str = "����";
    int repeat = n / 2;

    for (int i = 0; i < repeat; i++)
        answer.append(str);
    
    if (n % 2 == 1)
        answer.append("��");
    //
    return answer;
}

void printResult(string answer)
{
    cout << answer << "\n";
}

int main()
{
    printResult(solution(1));
    printResult(solution(5));
    printResult(solution(4));
    return 0;
}



































