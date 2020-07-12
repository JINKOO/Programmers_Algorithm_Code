/*
  #. [ 프로그래머스_124나라의 숫자 Level 2]

  #. 문제 설명
     124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.
     
     1. 124 나라에는 자연수만 존재합니다.
     2. 124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
     
     예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.

     10진법	  124 나라	 10진법	 124 나라
          1    	    1	     6	       14
          2     	2	     7	       21
          3     	4      	 8	       22
          4	       11	     9	       24
          5	       12	    10	       41
          
     자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.

  #. 제한사항
     - n은 500,000,000이하의 자연수 입니다.
  #. 입출력 예
     n	   result
     1	        1
     2	        2
     3	        4
     4	       11
*/


/*
  #. 풀이법.
     - 간단한 진법 변환 알고리즘을 적용하여 푼다.
     - 10진법의 수를 3진법으로 변환하는 규칙을 적용하지만, 나머지가 0인 경우는 별도의 처리필요.
     - n의 최대크기가 5억이므로 int 가능
*/

#include <string>
#include <iostream>
#include <stack>
using namespace std;

string solution(int n)
{
    string answer = "";
    //
    //0. 거꾸로 출력해야 하므로 stack에 담는다.
    stack<string> s;
    
    //1. 10진법 -> 3진법 변환 규칙 적용
    while (n > 0)
    {
        //1.1 3으로 나누어 떨어지는 경우, 0이 아닌 4로 변환하고,
        //    n = n/3 - 1의 규칙을 적용한다.
        if (n % 3 == 0)
        {
            s.push("4");
            n = n / 3 - 1;
        }

        //1.2 나머지가 1,2인 경우에는 일반적인 진법변환과 동일 규칙
        else
        {
            s.push(to_string(n % 3));
            n /= 3;
        }
    }

    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    //
    return answer;
}

int main()
{
    cout << solution(1) << "\n";
    cout << solution(2) << "\n";
    cout << solution(13) << "\n";
    cout << solution(500000000) << "\n";

    return 0;
}