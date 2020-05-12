/*
  #. ���� :: 2016��
 
  #. ���� ����
     2016�� 1�� 1���� �ݿ����Դϴ�. 2016�� a�� b���� ���� �����ϱ��? 
     �� �� a ,b�� �Է¹޾� 2016�� a�� b���� ���� �������� �����ϴ� �Լ�, solution�� �ϼ��ϼ���. 
     ������ �̸��� �Ͽ��Ϻ��� ����ϱ��� ���� SUN,MON,TUE,WED,THU,FRI,SAT�Դϴ�. 
     ���� ��� a=5, b=24��� 5�� 24���� ȭ�����̹Ƿ� ���ڿ� TUE�� ��ȯ�ϼ���.

  #. ���� ����
     2016���� �����Դϴ�.
     2016�� a�� b���� ������ �ִ� ���Դϴ�. (13�� 26���̳� 2�� 45�ϰ��� ��¥�� �־����� �ʽ��ϴ�)
  #. ����� ��
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


















