/*
  #. ���� ���ڴ� �Ⱦ�
  #. ���� ����
     �迭 arr�� �־����ϴ�. �迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�. 
     �̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�. 
     ��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�. 
     ���� ���,
     arr = [1, 1, 3, 3, 0, 1, 1] �̸� [1, 3, 0, 1] �� return �մϴ�.
     arr = [4, 4, 4, 3, 3] �̸� [4, 3] �� return �մϴ�.
     �迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

  #. ���ѻ���
  �迭 arr�� ũ�� : 1,000,000 ������ �ڿ���
  �迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����

  #. ����� ��
     arr	            answer
     [1,1,3,3,0,1,1]	[1,3,0,1]
     [4,4,4,3,3]	    [4,3]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
  unique() :: ������ �ߺ� ���� ���� but �ڿ� ������ �ʴ� �κ� ��ȯ 
*/
vector<int> solution2(vector<int> arr)
{
    vector<int> answer;
    //
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    //
    return answer;
}

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    //
    int i = 0, j;
    while(i < arr.size())
    {
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] != arr[j])
                break;
        }
        i = j;
        answer.push_back(arr[j-1]);
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    cout << "\n";
    
    //
    return answer;
}

int main()
{
    vector<int> v = { 1,1,3,3,0,1,1 };
    vector<int> v2 = { 4,4,4,3,3 };
    
    //solution(v);
    //solution2(v2);

    solution2(v);
    solution2(v2);

    return 0;
}