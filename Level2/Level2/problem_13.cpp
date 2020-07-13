/*
  #. [ ���α׷��ӽ�_�ùٸ� ��ȣ Level 2 ]
  #. ���� ����
     ��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' ���ڷ� ������ �Ѵٴ� ���Դϴ�. 
     ���� ���

     - ()() �Ǵ� (())() �� �ùٸ� ��ȣ�Դϴ�.
     - )()( �Ǵ� (()( �� �ùٸ��� ���� ��ȣ�Դϴ�.
     
     '(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��, ���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, 
     �ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

  #. ���ѻ���
     - ���ڿ� s�� ���� : 100,000 ������ �ڿ���
     - ���ڿ� s�� '(' �Ǵ� ')' �θ� �̷���� �ֽ��ϴ�.

  #. ����� ��
          s	   answer
       ()()	     true
     (())()	     true
       )()(	    false
       (()(	    false
*/


#include<string>
#include <iostream>
#include <stack>
using namespace std;

/*
   #. ���� Ǯ�̹�.
      - stack�� Ȱ���� ������ ��������.
      - stack�� ����ִٸ�, �켱 �����ϰ� s.top()�� '('�̰�, ������ �ݴ� ��ȣ'�� ������, s.pop()
      - stack�� empty()�̸� �ùٸ� ��ȣ�̴�.

*/

bool solution(string s)
{
    bool answer = true;
    //
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }

        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
    }

    if (!st.empty())
        answer = false;

    //
    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << solution(str) << "\n";

    return 0;
}