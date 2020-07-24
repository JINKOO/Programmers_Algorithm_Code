/*
 *   #. [ 프로그래머스_큰 수 만들기 Level 2 ]
 *
 *   #. 문제 설명
 *   어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
 *   예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.
 *   문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.
 *   number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.
 *
 *   #. 제한 조건
 *      - number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
 *      - k는 1 이상 number의 자릿수 미만인 자연수입니다.
 *
 *   #. 입출력 예
 *          number	 k	 return
 *            1924	 2	     94
 *         1231234	 3	   3234
 *      4177252841	 4	 775841
 */

 /*
  *   #. 나의 접근법
  *      - Greedy한 방식으로 최솟값 찾아, 문자열에서 이 최솟값과 같은 값이 있으면 제거.
  *        이후, 다음 최솟값을 찾고 반복 수행.
  *        --> 잘못된 방법이다.
  *   #. 풀이법.
  *      - 순서가 있으므로 음.. Stack을 사용하고자 하였다.
  *      - Greedy한 방식 :: Stack의 s.peek() < number[i]이면 pop,
  *                                 s.peek() => number[i]이면 push한다.
  *        pop의 개수는 k가 0이 될때까지 한다.
  */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    //
    stack<char> s;
    for (int i = 0; i < number.length(); i++)
    {
        char c = number[i];
        while (k > 0 && !s.empty() && s.top() < c)
        {
            s.pop();
            k--;
        }
        s.push(c);
    }

    while (!s.empty())
    {
        if (k != 0)
            k--;
        else
            answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    //
    return answer;
}

int main()
{

    cout << solution("1924", 2) << "\n";
    cout << solution("1231234", 3) << "\n";
    cout << solution("417725281", 4) << "\n";

    return 0;
}