/*
  #. [자연수 뒤집어 배열로 만들기]
  
  #. 문제 설명
     자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 
     예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.

  #. 제한 조건
     n은 10,000,000,000이하인 자연수입니다.
  #. 입출력 예
     n	           return
     12345	  [5,4,3,2,1]
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) 
{
    vector<int> answer;
    //
    string str = to_string(n);
    for (int i = str.length() - 1; i >= 0; i--)
        answer.push_back(str[i] - '0');
    //
    return answer;
}

void printResult(vector<int> answer)
{
    for(int i = 0; i <answer.size(); i++)
        cout << answer[i] << "\n";
}
int main()
{
    printResult(solution(12339045));
    return 0;
}