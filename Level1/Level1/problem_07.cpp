
/*
   #. ��� ���� ��������
   
   #. ���� ����  
      �ܾ� s�� ��� ���ڸ� ��ȯ�ϴ� �Լ�, solution�� ����� ������. 
      �ܾ��� ���̰� ¦����� ��� �α��ڸ� ��ȯ�ϸ� �˴ϴ�.

   #. ���ѻ���
      s�� ���̰� 1 �̻�, 100������ ��Ʈ���Դϴ�.
   
   #. ����� ��
        s	 return
      abcde	    c
      qwer	   we
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s)
{
    string answer = "";
    //
    if (s.size() % 2 == 0)
        answer = s.substr(s.size() / 2 - 1, 2);
    else
        answer = s.substr(s.size() / 2, 1);
    cout << answer << "\n";
    //
    return answer;
}

int main()
{
    solution("qwer");
    return 0;
}






