/*
 
  #. [�̻��� ���� �����]
  #. ���� ����
     ���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. 
     �� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. 
     �� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, 
     Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.

  #. ���� ����
     ���ڿ� ��ü�� ¦/Ȧ�� �ε����� �ƴ϶�, �ܾ�(������ ����)���� ¦/Ȧ�� �ε����� �Ǵ��ؾ��մϴ�.
     ù ��° ���ڴ� 0��° �ε����� ���� ¦����° ���ĺ����� ó���ؾ� �մϴ�.
  
  #. ����� ��
     s	                return
     try hello world	TrY HeLlO WoRlD
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) 
{
    string answer = "";
    //
    bool isEven = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            isEven = true;
            answer += " ";
        }
        else
        {
            if (isEven)
            {
                isEven = false;
                //answer += toupper(s[i]);
                if (s[i] >= 'A' && s[i] <= 'Z')
                    answer += s[i];
                else
                    answer += s[i] - 32;
            }
            else
            {
                isEven = true;
                //answer += tolower(s[i]);
                if (s[i] >= 'a' && s[i] <= 'z')
                    answer += s[i];
                else
                    answer += s[i] + 32;
            }
        }
    }
    //
    return answer;
}

void printResult(string str)
{
    cout << str << "\n";
}

int main()
{
    printResult(solution("try hello world"));
    printResult(solution("Oh hello"));
    
    return 0;
}