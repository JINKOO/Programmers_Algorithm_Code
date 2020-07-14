/*
  #. [ 프로그래머스_N개의 최소공배수 Level 2 ]
  #. 문제 설명
     두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다.
     예를 들어 2와 7의 최소공배수는 14가 됩니다. 
     정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다. 
     n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

  #. 제한 사항
     - arr은 길이 1이상, 15이하인 배열입니다.
     - arr의 원소는 100 이하인 자연수입니다.
     
 #. 입출력 예
           arr	    result
    [2,6,8,14]	       168
       [1,2,3]	         6
*/

/*
   #. 나의 풀이법.
      - 처음에 최대공약수를 구하고, 최대공약수를 갱신하면서 최종 최대공약수를 구하고,
        이 GCD를 모든 원소의 최대공약수가 되므로, 최소공배수를 구하였다. --> 실패
      - 2번째 풀이에서
        각 원소를 만날때, GCD, LCM을 각각 구하고 얻어진 LCM을 바탕으로 다음 원소와의 
        최소공배수를 구한다. 원소의 끝에 다다르면, 해당 원소들의 최소공배수가 된다.

*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    while (b != 0)
    {
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        b = b % a;
    }
    return a;
}

int LCM(int gcd, int a, int b)
{
    return gcd * (a / gcd) * (b / gcd);
}

int solution(vector<int> arr) {
    int answer = 0;
    //
    int gcd = arr[0];
    int lcm = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        //1. 이전 최소공배수와, 현재 원소와의 최대공약수
        gcd = GCD(lcm, arr[i]);
        //2. 현재까지의 최소공배수와, 현재 원소와의 최소공배수를 구한다.
        lcm = LCM(gcd, lcm, arr[i]);
    }
    answer = lcm;
    //
    return answer;
}

int main()
{
    cout << solution({16, 24, 12}) << "\n";
    return 0;
}