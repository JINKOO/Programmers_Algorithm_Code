/*
  #. [소수 찾기]
  
  #. 문제 설명
     1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.
     소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
     (1은 소수가 아닙니다.)

  #. 제한 조건
     n은 2이상 1000000이하의 자연수입니다.
  
  #. 입출력 예
      n	  result
     10	       4
      5        3
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    //
    vector<bool> is_prime(n, true);
    is_prime.at(0) = false;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i*i; j <= n; j += i)
        {
            is_prime.at(j - 1) = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (is_prime.at(i) == true)
            answer++;
    }
    //
    return answer;
}

int main()
{
    cout << solution(10) << "\n";

    return 0;
}






