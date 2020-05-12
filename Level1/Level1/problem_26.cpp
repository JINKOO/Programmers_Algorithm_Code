/*
  #. [���� ���� �� �����ϱ�]
  #. ���� ����
     ������ ������ �迭, arr ���� ���� ���� ���� ������ �迭�� �����ϴ� �Լ�, solution�� �ϼ����ּ���. 
     ��, �����Ϸ��� �迭�� �� �迭�� ��쿣 �迭�� -1�� ä�� �����ϼ���. 
     ������� arr�� [4,3,2,1]�� ���� [4,3,2]�� ���� �ϰ�, [10]�� [-1]�� ���� �մϴ�.

  #. ���� ����
     arr�� ���� 1 �̻��� �迭�Դϴ�.
     �ε��� i, j�� ���� i �� j�̸� arr[i] �� arr[j] �Դϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    //
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }

    int min = *min_element(arr.begin(), arr.end());
    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
    {
        if (*iter == min)
            continue;
        answer.push_back(*iter);
    }
    //
    return answer;
}

void printResult(vector<int> answer)
{
    for (int i = 0; i < answer.size(); i++)
        cout << answer.at(i) << "\n";
}

int main(void)
{
    printResult(solution({4,3,2,1}));

    return 0;
}






