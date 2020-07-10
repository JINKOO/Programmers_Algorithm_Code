/*
  #. [ 프로그래머스_소수 찾기 Level 2 ]
  #. 문제 설명
     한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
     각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 
     return 하도록 solution 함수를 완성해주세요.

  #. 제한사항
     - numbers는 길이 1 이상 7 이하인 문자열입니다.
     - numbers는 0~9까지 숫자만으로 이루어져 있습니다.
     - 013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
 
  #. 입출력 예
     numbers	return
          17	     3
         011         2

  #. 입출력 예 설명
     - 예제 #1
       [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

     - 예제 #2
       [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
       11과 011은 같은 숫자로 취급합니다.
*/

/*
  #. 나의 접근법.
     - numbers문자열을 하나씩 쪼개서 모든 경우의 수를 통하여 정수로 변환 후,
       vector<int>에 넣어서 소수인지 판별하려고 함. --> 실패.

  #. 풀이
     - '완전 탐색' 문제이다. 완전 탐색을 어느 부분에 적용시킬 것인지.
     - 우선 numbers에 있는 숫자문자로 만들 수 있는 최대 정수를 만들고,
       1. 2 ~ max까지 반복하면서,
       2. 소수인지 판별하고,
       3. 해당 소수가 기존 numbers에 포함된 문자인지 판별한다.

       ==> 1 ~ 3 부분이 완전탐색..
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//소수 판별에 있어서 가장 빠른 방법이다.
//에라토스테네스의 체보다 빠른 듯..??
bool isPrime(int n)
{
    if (n == 0)
        return false;
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool contain(string numbers, int n)
{
    string s = to_string(n);
    //1. count가 s의 length()와 같다는 의미 = 해당 소수인 n이 numbers에 모두 포함되어있다.
    int count = 0;

    //2. numbers와 s의 각 index를 비교하는데, 비교한 자리인지 판단하기 위하여, 
    vector<bool> check(numbers.length(), false);

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < numbers.length(); j++)
        {
            if (s[i] == numbers[j] && check[j] == false)
            {
                check[j] = true;
                count++;
                // break를 거는 이유 : 일단 같은 거 찾으면 break함으로써, 
                // 11과 같은 n이 넘어왔을 때, 앞에 1과 뒤에 1이 동시에 count되는 것을 막는다. 
                break;
            }
        }
    }
    //3. count가 s의 length()와 같다는 의미 = 해당 소수인 n이 numbers에 모두 포함되어있다.
    return count == s.length() ? true : false;
}

bool myCompare(char c1, char c2) 
{
    return c1 > c2;
}

int solution(string numbers) {
    int answer = 0;
    //
    //1. numbers에서 가장 최댓값을 찾는다.
    int max = 0;
    //1.1 최댓값을 쉽게 찾기 위해 내림차순 정렬한다.
    sort(numbers.begin(), numbers.end(), myCompare);
    max = stoi(numbers);

    //2. 2 ~ max까지 소수 찾고, 이 소수가 기존 numbers에 들어있나 check한다.
    for (int i = 2; i <= max; i++)
    {
        //2.2 소수이면,
        if (isPrime(i))
        {
            //2.3 해당 소수가, numbers에 포함되어있는 문자인지 check한다.
            if (contain(numbers, i))
                answer++;
        }
    }
    //
    return answer;
}

int main()
{
    cout << solution("17") << "\n";
    cout << solution("011") << "\n";
    cout << solution("012342") << "\n";

    return 0;
}