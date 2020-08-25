/*
   #. [ 프로그래머스_소수 찾기 Level 2 ]
   
   #. 문제 설명
      한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
      각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.
      
   #. 제한사항
      - numbers는 길이 1 이상 7 이하인 문자열입니다.
      - numbers는 0~9까지 숫자만으로 이루어져 있습니다.
      - 013은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
      
   #. 입출력 예
      numbers	return
           17	     3
          011	     2
          
   #. 입출력 예 설명
      예제 #1
      [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.
      
      예제 #2
      [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
      
      11과 011은 같은 숫자로 취급합니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
    if (n == 0 || n == 1)
        return false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_all_contained(int n, string number)
{
    string temp = to_string(n);
    bool check[7] = { false, };
    int count = 0;

    for (int i = 0; i < temp.length(); i++)
    {
        for (int j = 0; j < number.length(); j++)
        {
            if (temp[i] == number[j] && !check[j])
            {
                check[j] = true;
                count++;
                break;
            }
        }
    }

    return count == temp.length() ? true : false;
}

int solution(string numbers) 
{
    int answer = 0;
    //
    sort(numbers.begin(), numbers.end(), greater<char>());
    int max_num = stoi(numbers);

    int n = max_num;
    while (n != 0)
    {
        if (is_prime(n) && is_all_contained(n, numbers))
            answer++;
        n--;
    }
    //
    return answer;
}

int main()
{
    cout << solution("17") << "\n";
    cout << solution("011") << "\n";

    return 0;
}