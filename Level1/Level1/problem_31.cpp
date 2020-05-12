/*
  #. [ 핸드폰 번호 가리기 ]
  #. 문제 설명
     프로그래머스 모바일은 개인정보 보호를 위해 고지서를 보낼 때 고객들의 전화번호의 일부를 가립니다.
     전화번호가 문자열 phone_number로 주어졌을 때, 
     전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 리턴하는 함수, solution을 완성해주세요.

  #. 제한 조건
     s는 길이 4 이상, 20이하인 문자열입니다.

  #. 입출력 예
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





