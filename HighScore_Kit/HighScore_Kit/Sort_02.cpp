/*
  #. [ 프로그래머스_가장 큰 수 ]
  #. 문제 설명
     0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
     예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

     0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

  #. 제한 사항
     - numbers의 길이는 1 이상 100,000 이하입니다.
     - numbers의 원소는 0 이상 1,000 이하입니다.
       정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
       
  #. 입출력 예
               numbers	     return
            [6, 10, 2]	       6210
     [3, 30, 34, 5, 9]	    9534330
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//비교기준을 다음과 같이 설정 할 수 도 있다..
bool myCompare(const string& s1, const string& s2)
{
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    //

    //1. 문자열로 변환하여 vector에 삽입.
    vector<string> v;
    for (int i : numbers)
        v.push_back(to_string(i));

    //2. 내림차순 정렬
    sort(v.begin(), v.end(), myCompare);
   
    for (string s : v)
        answer += s;

    //앞자리가 0인경우 처리해야한다.
    if (answer[0] == '0')
        answer = "0";
    //
    return answer;
}

int main()
{
    cout << solution({ 6, 10, 2 }) << "\n";
    cout << solution({ 3, 30, 34, 5, 9 }) << "\n";
    cout << solution({ 0, 0, 0}) << "\n";

    return 0;
}