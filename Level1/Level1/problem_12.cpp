/*
  #. [���ڿ� �� p�� y�� ����]
  
  #. ���� ����
     �빮�ڿ� �ҹ��ڰ� �����ִ� ���ڿ� s�� �־����ϴ�. 
     s�� 'p'�� ������ 'y'�� ������ ���� ������ True, �ٸ��� False�� return �ϴ� solution�� �ϼ��ϼ���. 
     'p', 'y' ��� �ϳ��� ���� ���� �׻� True�� �����մϴ�. 
     ��, ������ ���� �� �빮�ڿ� �ҹ��ڴ� �������� �ʽ��ϴ�.

  #. ���� ��� s�� pPoooyY�� true�� return�ϰ� Pyy��� false�� return�մϴ�.

  #. ���ѻ���
     ���ڿ� s�� ���� : 50 ������ �ڿ���
     ���ڿ� s�� ���ĺ����θ� �̷���� �ֽ��ϴ�.
  
  #. ����� ��
     s	        answer
     pPoooyY	true
     Pyy	    false
*/

#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    //
    int p_count = 0, y_count = 0;
    for (string::iterator iter = s.begin(); iter != s.end(); iter++)
    {
        if (*iter == 'P' || *iter == 'p')
            p_count++;
        if (*iter == 'Y' || *iter == 'y')
            y_count++;
    }
    p_count == y_count ? answer = true : answer = false;
    //
    return answer;
}

int main()
{
    string s1 = "pPooooyY";
    string s2 = "hello";
    string s3 = "PyY";
    cout << solution(s1) << "\n";
    cout << solution(s2) << "\n";
    cout << solution(s3) << "\n";

	return 0;
}