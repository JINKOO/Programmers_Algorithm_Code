/*
  #.[ ���� ������������ ��ġ�ϱ� ]
  
  #. ���� ����
     �Լ� solution�� ���� n�� �Ű������� �Է¹޽��ϴ�. 
     n�� �� �ڸ����� ū�ͺ��� ���� ������ ������ ���ο� ������ �������ּ���. 
     ������� n�� 118372�� 873211�� �����ϸ� �˴ϴ�.

  #. ���� ����
     n�� 1�̻� 8000000000 ������ �ڿ����Դϴ�.
  
  #. ����� ��
          n	   return
     118372	   873211
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    //
    string str = to_string(n);
    vector<int> v;
    for (int i = 0; i < str.size(); i++)
        v.push_back(str[i] - '0');
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); i++)
    {
        answer += v.at(i) * pow(10, v.size() - 1 - i);
    }

    //
    return answer;
}

void printResult(long long answer)
{
    cout << answer << "\n";
}
int main()
{
    printResult(solution(118372));

    return 0;
}