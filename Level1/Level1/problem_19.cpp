/*
  #. [���� ��ȣ]
  #. ���� ����
     � ������ �� ���ĺ��� ������ �Ÿ���ŭ �о 
     �ٸ� ���ĺ����� �ٲٴ� ��ȣȭ ����� ���� ��ȣ��� �մϴ�. 
     ���� ��� AB�� 1��ŭ �и� BC�� �ǰ�, 3��ŭ �и� DE�� �˴ϴ�. 
     z�� 1��ŭ �и� a�� �˴ϴ�. 
     ���ڿ� s�� �Ÿ� n�� �Է¹޾� s�� n��ŭ �� ��ȣ���� ����� �Լ�, solution�� �ϼ��� ������.

  #. ���� ����
     ������ �ƹ��� �о �����Դϴ�.
     s�� ���ĺ� �ҹ���, �빮��, �������θ� �̷���� �ֽ��ϴ�.
     s�� ���̴� 8000�����Դϴ�.
     n�� 1 �̻�, 25������ �ڿ����Դϴ�.
 
  #. ����� ��
     s	      n 	result
     AB	      1	    BC
     z	      1	    a
     a B z	  4  	e F d
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    //
    //why % 26..??
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            char start = (s[i] >= 'a' && s[i] <= 'z') ? 'a' : 'A';
            s[i] = start + (s[i] + n - start) % 26;
        }
        answer += s[i];
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
    printResult(solution("   ", 1));
    printResult(solution("z", 1));
    printResult(solution("a b Z", 4));
    printResult(solution("A     Z", 1));
    return 0;
}

















