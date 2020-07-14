/*
  #. [ 프로그래머스_숫자의 표현 Level 2 ]
  #. 문제 설명
     Finn은 요즘 수학공부에 빠져 있습니다. 
     수학 공부를 하던 Finn은 자연수 n을 연속한 자연수들로 표현 하는 방법이 여러개라는 사실을 알게 되었습니다. 
     예를들어 15는 다음과 같이 4가지로 표현 할 수 있습니다.
     
     1 + 2 + 3 + 4 + 5 = 15
     4 + 5 + 6 = 15
     7 + 8 = 15
     15 = 15
     
     자연수 n이 매개변수로 주어질 때, 연속된 자연수들로 n을 표현하는 방법의 수를 return하는 solution를 완성해주세요.

  #. 제한사항
     n은 10,000 이하의 자연수 입니다.
  
  #. 입출력 예
      n	 result
     15	      4
*/

/*
   #. 나의 풀이
      - n <= 1000이므로, '완전탐색'으로 푼다.
      - 1 ~ n까지 연속된 합을 구하여 n보다 크면, 반복을 중지하고, n이면 answer++한다.
        안쪽 반복문에서는 n / 2 + 1까지만 반복하면 된다.
        1 2 3 4 5 6 7 8 9 에서
        9 / 2 + 1 = 5이다. 5부터는 하나의 연속된 수만 더해도 무조건 n보다 크다.

        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        15 / 2 + 1 = 8 이다. 8 + 9 = 17 > 15

*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    //
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j <= n / 2 + 1; j++)
        { 
            sum += j;
            if (sum == n)
                answer++;
            else if (sum > n)
                break;
        }
    }
    //
    return answer + 1;  //+1이유는 n = n인 경우
}

int main()
{
    cout << solution(15) << "\n";
    
    return 0;
}