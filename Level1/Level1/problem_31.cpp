/*
  #. [ �ڵ��� ��ȣ ������ ]
  #. ���� ����
     ���α׷��ӽ� ������� �������� ��ȣ�� ���� �������� ���� �� ������ ��ȭ��ȣ�� �Ϻθ� �����ϴ�.
     ��ȭ��ȣ�� ���ڿ� phone_number�� �־����� ��, 
     ��ȭ��ȣ�� �� 4�ڸ��� ������ ������ ���ڸ� ���� *���� ���� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

  #. ���� ����
     s�� ���� 4 �̻�, 20������ ���ڿ��Դϴ�.

  #. ����� ��
     phone_number	     return
      01033334444	*******4444
        027778888	  *****8888
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string phone_number) 
{
    string answer = "";
    //
    /*char* c_str = new char[phone_number.length() + 1];
    strcpy_s(c_str, phone_number.length() + 1, phone_number.c_str());
    c_str[phone_number.length()] = '\0';

    for (int i = 0; i < phone_number.length(); i++)
    {
        if (i < phone_number.length() - 4)
            c_str[i] = '*';
        answer += c_str[i];
    }*/

    int i;
    for (i = 0; i < phone_number.size() - 4; i++)
    {
        phone_number[i] = '*';
        answer += phone_number[i];
    }
    answer += phone_number.substr(i, 4);
    //
    return answer;
}

void printResult(string answer)
{
    cout << answer << "\n";
}

int main()
{

    printResult(solution("01033334444"));
    printResult(solution("0222873663"));
    
    return 0;
}





