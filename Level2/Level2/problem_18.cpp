/*
  #. [ 프로그래머스_최댓값과 최솟값 Level 2 ]

  #. 문제 설명
     문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. 
     str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 (최소값) (최대값)형태의 문자열을 반환하는 함수, solution을 완성하세요.
     예를들어, s가 1 2 3 4라면 1 4를 리턴하고, -1 -2 -3 -4라면 -4 -1을 리턴하면 됩니다.

  #. 제한 조건
     - s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.
  #. 입출력 예
               s	return
         1 2 3 4	   1 4
     -1 -2 -3 -4	 -4 -1
           -1 -1	 -1 -1
*/

/*
   #. 나의 풀이법.
      - Greedy문제. 근데 문자열 길이에 대한 범위가 왜 없지..???
      - 간단한 문자열 처리문제. 단 2자리 이상, -붙였을 때 약간의 고민을 함.
        stoi()를 사용해야한다.
      - 공백을 제외한 문자들을 숫자로 변환하여 vector에 삽입하고, 정렬한다.

      2020.08.24 또 다른 풀이 추가 strtok_s()사용.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    //
    string max, min;
    //1. min, max구할 vector;
    vector<int> v;

    //2. v에 삽입하기 위한 임시 string, 삽입할 때, int변환
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        temp += s[i];
        //2.1 공백이거나, 문자열의 마지막 문자이면, int변환 후, 삽입 
        //    temp초기화.
        if (s[i] == ' ' || i == s.length() - 1)
        {
            v.push_back(stoi(temp));
            //문자열 초기화.
            temp.clear();
        }
    }

    sort(v.begin(), v.end());

    max = to_string(v.back());
    min = to_string(v.front());
    answer = min + " " + max;
    //
    return answer;
}


string solution2(string str)
{
    string answer = "";
    vector<int> v;

    //1. str을 char*c 형으로 복사(c_str()하면 원본으로는 사용 불가하다).
    char* c = new char[str.length() + 1];
    strcpy_s(c, str.length() + 1 ,str.c_str());

    //2. strtok_s()사용.
    char* context = nullptr;
    char* ptr = strtok_s(c, " ", &context);

    while (ptr != nullptr)
    {
        v.push_back(stoi(ptr));
        ptr = strtok_s(nullptr, " ", &context);
    }

    sort(v.begin(), v.end(), less<int>());

    string min = to_string(v.front());
    string max = to_string(v.back());

    answer = min + " " + max;
    return answer;
}

int main()
{
    //cout << solution("-1 -2 -3 -4") << "\n";
    cout << solution2("-1 -2 -3 -4") << "\n";
    return 0;
}