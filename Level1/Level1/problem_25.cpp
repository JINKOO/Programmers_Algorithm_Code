/*
  #. [ 정수 제곱근 판별 ]
  #. 문제 설명
     임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하려 합니다.
     n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, 
     n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수를 완성하세요.

  #. 제한 사항
     n은 1이상, 50000000000000 이하인 양의 정수입니다.

  #. 입출력 예
       n	    return
     121	       144
       3	        -1
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    //
    long long m = sqrt(n);
    if (m * m == n)
        answer = pow(m, 2);
    else
        answer = -1;
    //
    return answer;
}

int main()
{
    cout << solution(121) << "\n";
    cout << solution(3) << "\n";
    return 0;
}