/*
  #. [ 프로그래머스_올바른 괄호 Level 2 ]
  #. 문제 설명
     괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 
     예를 들어

     - ()() 또는 (())() 는 올바른 괄호입니다.
     - )()( 또는 (()( 는 올바르지 않은 괄호입니다.
     
     '(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 
     올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.

  #. 제한사항
     - 문자열 s의 길이 : 100,000 이하의 자연수
     - 문자열 s는 '(' 또는 ')' 로만 이루어져 있습니다.

  #. 입출력 예
          s	   answer
       ()()	     true
     (())()	     true
       )()(	    false
       (()(	    false
*/


#include<string>
#include <iostream>
#include <stack>
using namespace std;

/*
   #. 나의 풀이법.
      - stack을 활용한 간단한 문제였다.
      - stack이 비어있다면, 우선 삽입하고 s.top()이 '('이고, 다음이 닫는 괄호'를 만나면, s.pop()
      - stack이 empty()이면 올바른 괄호이다.

*/

bool solution(string s)
{
    bool answer = true;
    //
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }

        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
    }

    if (!st.empty())
        answer = false;

    //
    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << solution(str) << "\n";

    return 0;
}