/*
  #. [���ڿ� �ٷ�� �⺻]
  
  #. ���� ����
     ���ڿ� s�� ���̰� 4 Ȥ�� 6�̰�, ���ڷθ� �������ִ��� Ȯ�����ִ� �Լ�, solution�� �ϼ��ϼ���. 
     ���� ��� s�� a234�̸� False�� �����ϰ� 1234��� True�� �����ϸ� �˴ϴ�.

  #. ���� ����
     s�� ���� 1 �̻�, ���� 8 ������ ���ڿ��Դϴ�.

  #. ����� ��
     s	    return
     a234	false
     1234	true
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    
    bool answer = true;
    //
    
    if (s.length() == 4 || s.length == 6)
    {
        int i;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] < 48 || s[i] > 57)
                break;
        }
        i == s.length() ? answer = true : answer = false;
    }
    else
        answer = false;
    //
    return answer;
}

void print(bool result)
{
    cout << result << "\n";
}

int main()
{
    print(solution("a234"));
    print(solution("1234"));
    print(solution(" 0"));

    return 0;
}








