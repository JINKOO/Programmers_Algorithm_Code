/*
  #. [���￡�� �輭�� ã��]

  #. ���� ����
     String�� �迭 seoul�� element�� Kim�� ��ġ x�� ã��, 
     �輭���� x�� �ִٴ� String�� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���. 
     seoul�� Kim�� ���� �� ���� ��Ÿ���� �߸��� ���� �ԷµǴ� ���� �����ϴ�.

  #. ���� ����
     seoul�� ���� 1 �̻�, 1000 ������ �迭�Դϴ�.
     seoul�� ���Ҵ� ���� 1 �̻�, 20 ������ ���ڿ��Դϴ�.
     Kim�� �ݵ�� seoul �ȿ� ���ԵǾ� �ֽ��ϴ�.
  
  #. ����� ��
     seoul	        return
     [Jane, Kim]	�輭���� 1�� �ִ�
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    //
    vector<string>::iterator iter = find(seoul.begin(), seoul.end(), "Kim");
    int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer = "�輭���� " + to_string(pos) + "�� �ִ�.";
    //
    return answer;
}

void printResult(string s)
{
    cout << s << "\n";
}

int main()
{
    vector<string> v = { "Jane", "Kim" };
    printResult(solution(v));

    return 0;
}











