/*
 *   #. [ ���α׷��ӽ�_ū �� ����� Level 2 ]
 *
 *   #. ���� ����
 *   � ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.
 *   ���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.
 *   ���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�.
 *   number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
 *
 *   #. ���� ����
 *      - number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
 *      - k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
 *
 *   #. ����� ��
 *          number	 k	 return
 *            1924	 2	     94
 *         1231234	 3	   3234
 *      4177252841	 4	 775841
 */

 /*
  *   #. ���� ���ٹ�
  *      - Greedy�� ������� �ּڰ� ã��, ���ڿ����� �� �ּڰ��� ���� ���� ������ ����.
  *        ����, ���� �ּڰ��� ã�� �ݺ� ����.
  *        --> �߸��� ����̴�.
  *   #. Ǯ�̹�.
  *      - ������ �����Ƿ� ��.. Stack�� ����ϰ��� �Ͽ���.
  *      - Greedy�� ��� :: Stack�� s.peek() < number[i]�̸� pop,
  *                                 s.peek() => number[i]�̸� push�Ѵ�.
  *        pop�� ������ k�� 0�� �ɶ����� �Ѵ�.
  */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    //
    stack<char> s;
    for (int i = 0; i < number.length(); i++)
    {
        char c = number[i];
        while (k > 0 && !s.empty() && s.top() < c)
        {
            s.pop();
            k--;
        }
        s.push(c);
    }

    while (!s.empty())
    {
        if (k != 0)
            k--;
        else
            answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    //
    return answer;
}

int main()
{

    cout << solution("1924", 2) << "\n";
    cout << solution("1231234", 3) << "\n";
    cout << solution("417725281", 4) << "\n";

    return 0;
}