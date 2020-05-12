/*
  #. [�ڿ��� ������ �迭�� �����]
  
  #. ���� ����
     �ڿ��� n�� ������ �� �ڸ� ���ڸ� ���ҷ� ������ �迭 ���·� �������ּ���. 
     ������� n�� 12345�̸� [5,4,3,2,1]�� �����մϴ�.

  #. ���� ����
     n�� 10,000,000,000������ �ڿ����Դϴ�.
  #. ����� ��
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