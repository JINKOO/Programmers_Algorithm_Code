/*
  #. [ ���α׷��ӽ�_�ִ񰪰� �ּڰ� Level 2 ]

  #. ���� ����
     ���ڿ� s���� �������� ���е� ���ڵ��� ����Ǿ� �ֽ��ϴ�. 
     str�� ��Ÿ���� ���� �� �ּҰ��� �ִ밪�� ã�� �̸� (�ּҰ�) (�ִ밪)������ ���ڿ��� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���.
     �������, s�� 1 2 3 4��� 1 4�� �����ϰ�, -1 -2 -3 -4��� -4 -1�� �����ϸ� �˴ϴ�.

  #. ���� ����
     - s���� �� �̻��� ������ �������� ���еǾ� �ֽ��ϴ�.
  #. ����� ��
               s	return
         1 2 3 4	   1 4
     -1 -2 -3 -4	 -4 -1
           -1 -1	 -1 -1
*/

/*
   #. ���� Ǯ�̹�.
      - Greedy����. �ٵ� ���ڿ� ���̿� ���� ������ �� ����..???
      - ������ ���ڿ� ó������. �� 2�ڸ� �̻�, -�ٿ��� �� �ణ�� ����� ��.
        stoi()�� ����ؾ��Ѵ�.
      - ������ ������ ���ڵ��� ���ڷ� ��ȯ�Ͽ� vector�� �����ϰ�, �����Ѵ�.

      2020.08.24 �� �ٸ� Ǯ�� �߰� strtok_s()���.
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
    //1. min, max���� vector;
    vector<int> v;

    //2. v�� �����ϱ� ���� �ӽ� string, ������ ��, int��ȯ
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        temp += s[i];
        //2.1 �����̰ų�, ���ڿ��� ������ �����̸�, int��ȯ ��, ���� 
        //    temp�ʱ�ȭ.
        if (s[i] == ' ' || i == s.length() - 1)
        {
            v.push_back(stoi(temp));
            //���ڿ� �ʱ�ȭ.
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

    //1. str�� char*c ������ ����(c_str()�ϸ� �������δ� ��� �Ұ��ϴ�).
    char* c = new char[str.length() + 1];
    strcpy_s(c, str.length() + 1 ,str.c_str());

    //2. strtok_s()���.
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