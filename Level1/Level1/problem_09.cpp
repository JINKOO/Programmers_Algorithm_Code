/*
  #. ������ �������� ���� �迭
  #. ���� ����
     array�� �� element �� divisor�� ������ �������� ���� 
     ������������ ������ �迭�� ��ȯ�ϴ� �Լ�, solution�� �ۼ����ּ���.
     divisor�� ������ �������� element�� �ϳ��� ���ٸ� �迭�� -1�� ��� ��ȯ�ϼ���.

  #. ���ѻ���
     arr�� �ڿ����� ���� �迭�Դϴ�.
     ���� i, j�� ���� i �� j �̸� arr[i] �� arr[j] �Դϴ�.
     divisor�� �ڿ����Դϴ�.
     array�� ���� 1 �̻��� �迭�Դϴ�.

  #. ����� ��
     arr	         divisor	   return
     [5, 9, 7, 10]	       5  	   [5, 10]
     [2, 36, 1, 3]	       1	   [1, 2, 3, 36]
           [3,2,6]	      10	   [-1]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> arr)
{
    vector<int>::iterator iter;
    for (iter = arr.begin(); iter != arr.end(); iter++)
        cout << *iter << " ";
    cout << "\n";
}

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;
    //
    sort(arr.begin(), arr.end());
    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
    {
        if (*iter % divisor == 0)
            answer.push_back(*iter);
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    
    //
    return answer;
}

int main()
{
    int d1 = 5, d2 = 1, d3 = 10;

    vector<int> v1 = { 5,9,7,10 };
    print(solution(v1, d1));
    vector<int> v2 = { 2,36,1,3 };
    print(solution(v2, d2));
    vector<int> v3 = { 3,2,6 };
    print(solution(v3, d3));

    return 0;
}