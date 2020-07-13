/*
  #. [ 프로그래머스_다음 큰 숫자 Level 2 ]
  #. 문제 설명
     자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.

     - 조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
     - 조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
     - 조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.
       예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.
       
    자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.

  #. 제한 사항
     n은 1,000,000 이하의 자연수 입니다.
     
  #. 입출력 예
      n	    result
     78	        83
     15	        23
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
   #. 나의 풀이법
      - 파라미터로 넘어온 숫자를 2진수로 변환하고, 1의 개수를 count.
      - 이 때, 변환된 숫자를 저장하기 위해 stack을 사용하였다.
      - 1의 개수를 count하고,
        n을 1씩 증가시키며, 2진수 변환, 1의 개수를 count하여(toBinary(), count_one()를 만들었음)
        개수가 같을 때, break건다.
      --> 효율성에서 시간초과 문제

   #. 풀이
      - 기존에 내가 생각했던 논리는 맞다. 즉, 얘는 '완전 탐색'문제이다.
      - but굳이 진법 변환하여 변환된 2진수를 저장하지 않아도 된다.
        진법 변환 할때, 1의 개수만 세도록 하자.stack도 필요없어짐.
*/

//진법 변환 알고리즘에서 1의 개수만 count한다.
//문제에서는 2진수로 변환하지만, 실제로는 2진수로 변환 하지 않음
int count_one(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            count++;
        n /= 2;
    }
    return count;
}

int solution(int n) 
{
    int answer = 0;
    //
    int result = count_one(n);
    while (1)
    {
        ++n;
        if (count_one(n) == result)
            break;
    }
    //
    answer = n;
    return answer;
}

int main()
{
    cout << solution(78) << "\n";
    cout << solution(15) << "\n";

    return 0;
}