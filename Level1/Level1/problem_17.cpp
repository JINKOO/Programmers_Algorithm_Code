/*
  #. [수박수박수박수박수박수?]
  #. 문제 설명
     길이가 n이고, 수박수박수박수....와 같은 패턴을 
     유지하는 문자열을 리턴하는 함수, solution을 완성하세요. 
     예를들어 n이 4이면 수박수박을 리턴하고 3이라면 수박수를 리턴하면 됩니다.

  #. 제한 조건
     n은 길이 10,000이하인 자연수입니다.
    
  #. 입출력 예
     n	  return
     3	  수박수
     4	  수박수박
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) 
{
    string answer = "";
    //
    string str = "수박";
    int repeat = n / 2;

    for (int i = 0; i < repeat; i++)
        answer.append(str);
    
    if (n % 2 == 1)
        answer.append("수");
    //
    return answer;
}

void printResult(string answer)
{
    cout << answer << "\n";
}

int main()
{
    printResult(solution(1));
    printResult(solution(5));
    printResult(solution(4));
    return 0;
}



































