/*
  #. [두 정수 사이의 합 ]

  #. 문제 설명
     두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 리턴하는 함수, solution을 완성하세요.
     예를 들어 a = 3, b = 5인 경우, 3 + 4 + 5 = 12이므로 12를 리턴합니다.

  #. 제한 조건
     a와 b가 같은 경우는 둘 중 아무 수나 리턴하세요.
     a와 b는 -10,000,000 이상 10,000,000 이하인 정수입니다.
     a와 b의 대소관계는 정해져있지 않습니다.

  #. 입출력 예
     a	 b	 return
     3	 5	 12
     3	 3	  3
     5	 3	 12
*/
#include <iostream>
#include <math.h>
using namespace std;

long long subAll(int min, int max)
{
    //int size = max - min + 1;
    //cout << min << ", " << max << ", " << size << "\n";
    return (long long) (max - min + 1) * (max + min) / 2;
}

long long solution(int a, int b)
{
    long long answer = 0;
    //
    answer = subAll(a < b ? a : b, a > b ? a : b);
    //
    return answer;
}
void print(long long answer)
{
    cout << answer << "\n";
}

int main()
{
    print(solution(3, 5));
    print(solution(-6, 1));
    print(solution(-15, -9));
    print(solution(-4, 2));
    print(solution(3, 11));
    return 0;
}