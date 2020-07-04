/*
  #. [ 

  #. 문제 설명
     JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 
     문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

  #. 제한 조건
     - s는 길이 1 이상인 문자열입니다.
     - s는 알파벳과 공백문자(" ")로 이루어져 있습니다.
     - 첫 문자가 영문이 아닐때에는 이어지는 영문은 소문자로 씁니다. ( 첫번째 입출력 예 참고 )
     
  #. 입출력 예
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