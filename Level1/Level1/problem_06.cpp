/*
  #. 문제 :: 2016년
 
  #. 문제 설명
     2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 
     두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 
     요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT입니다. 
     예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 TUE를 반환하세요.

  #. 제한 조건
     2016년은 윤년입니다.
     2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)
  #. 입출력 예
     a	 b	 result
     5	 24	 TUE
*/

#include <iostream>
#include <vector>
using namespace std;

string matchDay(int pos)
{
    if (pos == 0)
        return "SUN";
    else if (pos == 1)
        return "MON";
    else if (pos == 2)
        return "TUE";
    else if (pos == 3)
        return "WED";
    else if (pos == 4)
        return "THU";
    else if (pos == 5)
        return "FRI";
    else if (pos == 6)
        return "SAT";
    else
        return "";
}

string solution(int a, int b)
{
    string answer = "";
    //
    int day_pos, day_of_month;

    for (int i = 1; i <= 12; i++)
    {
        if (i <= 7)
        {
            if (i == 2)
                day_of_month = 29;
            else if (i % 2 == 0)
                day_of_month = 30;
            else
                day_of_month = 31;
        }
        else
        {
            if (i % 2 == 0)
                day_of_month = 31;
            else
                day_of_month = 30;
        }
        
        if (i == 1)
            day_pos = 5;

        for (int j = 1; j <= day_of_month; j++)
        {
            if (a == i && b == j)
            {
                answer = matchDay(day_pos % 7);
                break;
            }
            day_pos++;
        }
        day_pos = day_pos % 7;
    }
    cout << answer << "\n";
    //
    return answer;
}

int main()
{
    solution(2, 1);

    return 0;
}


















