/*
  #. [���ڿ� ������������ ��ġ�ϱ�
  
  #. ���� ����
     ���ڿ� s�� ��Ÿ���� ���ڸ� ū�ͺ��� ���� ������ ������ 
     ���ο� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.
     s�� ���� ��ҹ��ڷθ� �����Ǿ� ������, �빮�ڴ� �ҹ��ں��� ���� ������ �����մϴ�.
 
  #. ���� ����
     str�� ���� 1 �̻��� ���ڿ��Դϴ�.

  #. ����� ��
     s	        return
     Zbcdefg	gfedcbZ
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool mySort(char c1, char c2)
{
    return c1 > c2;
}

string solution(string s) 
{
    string answer = "";
    //
    sort(s.begin(), s.end(), mySort);      
    answer = s;
    //
    return answer;
}

void printResult(string s)
{
    cout << s << "\n";
}

int main()
{
    printResult(solution("Zbcdefg"));

    return 0;
}












