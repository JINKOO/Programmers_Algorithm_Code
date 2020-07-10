/*
  #. [ ���α׷��ӽ�_H-Index ]
  #. ���� ����
     H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. 
     ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. 
     ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.
     
     � �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� 
     h�� �ִ��� �� �������� H-Index�Դϴ�.

     � �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, 
     �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���ѻ���
     - �����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
     - ���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.

  #. ����� ��
           citations	return
     [3, 0, 6, 1, 5]	     3
    
  #. ����� �� ����
     �� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. 
     �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

�� ���� - 2019�� 2�� 28�� �׽�Ʈ ���̽��� �߰��Ǿ����ϴ�.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    //
    sort(citations.begin(), citations.end());
    int max_h = citations[citations.size() - 1];
    vector<int> v;
    for (int h = 1; h <= max_h; h++)
    {
        int count1 = 0;
        int count2 = 0;
        for (int j = 0; j < citations.size(); j++)
        {
            if (h <= citations[j])
                count1++;
            else
                count2++;
        }
        if (h <= count1 && h >= count2)
            v.push_back(h);
    }

    if (v.empty())
        answer = 0;
    else  // citations�� �����Ͽ����Ƿ�, v�� ������������ ���� ���ԵǱ� ������ �ִ��� ������ �����̴�. 
        answer = v[v.size() - 1];
    //
    return answer;
}

int main()
{

    cout << solution({ 3, 0, 6, 1, 5 }) << "\n";

    return 0;
}