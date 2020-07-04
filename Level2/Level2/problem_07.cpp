/*
  #. [ 

  #. ���� ����
     JadenCase�� ��� �ܾ��� ù ���ڰ� �빮���̰�, �� ���� ���ĺ��� �ҹ����� ���ڿ��Դϴ�. 
     ���ڿ� s�� �־����� ��, s�� JadenCase�� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

  #. ���� ����
     - s�� ���� 1 �̻��� ���ڿ��Դϴ�.
     - s�� ���ĺ��� ���鹮��(" ")�� �̷���� �ֽ��ϴ�.
     - ù ���ڰ� ������ �ƴҶ����� �̾����� ������ �ҹ��ڷ� ���ϴ�. ( ù��° ����� �� ���� )
     
  #. ����� ��
                         s	                               return
     3people unFollowed me	                3people Unfollowed Me
         for the last week	                    For The Last Week
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> str;
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            temp += s[i];

        if(s[i] == ' ' || i == s.length() - 1)
        {
            str.push_back(temp);
            temp = "";
        }
    }

    for (int i = 0; i < str.size(); i++)
    {
        string e = str[i];
        if ('a' <= e[0] && e[0] <= 'z')
            e[0] = (char)toupper(e[0]);

        for (int j = 1; j < e.length(); j++)
        {
            if ('A' <= e[j] && e[j] <= 'Z')
                e[j] = (char)tolower(e[j]);
        }
   
        answer += e;
        if (i != str.size() - 1)
            answer += " ";
    }

    return answer;
}

int main()
{
    cout << solution("!a   123Hello world") << "\n";
    cout << solution("321People unFollowed me") << "\n";
    cout << solution("for the last 1234week") << "\n";

    return 0;
}