/*
  #.[ 정수 내림차순으로 배치하기 ]
  
  #. 문제 설명
     함수 solution은 정수 n을 매개변수로 입력받습니다. 
     n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 
     예를들어 n이 118372면 873211을 리턴하면 됩니다.

  #. 제한 조건
     n은 1이상 8000000000 이하인 자연수입니다.
  
  #. 입출력 예
          n	   return
     118372	   873211
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    //
    string str = to_string(n);
    vector<int> v;
    for (int i = 0; i < str.size(); i++)
        v.push_back(str[i] - '0');
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); i++)
    {
        answer += v.at(i) * pow(10, v.size() - 1 - i);
    }

    //
    return answer;
}

void printResult(long long answer)
{
    cout << answer << "\n";
}
int main()
{
    printResult(solution(118372));

    return 0;
}