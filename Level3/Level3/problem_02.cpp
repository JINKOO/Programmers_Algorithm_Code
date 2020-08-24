/*
   #. [ ���α׷��ӽ�_�ܼ�ī�޶� Level 3 ]
   
   #. ���� ����
      ��ӵ��θ� �̵��ϴ� ��� ������ ��ӵ��θ� �̿��ϸ鼭 �ܼӿ� ī�޶� �� ���� �������� ī�޶� ��ġ�Ϸ��� �մϴ�.
      ��ӵ��θ� �̵��ϴ� ������ ��� routes�� �Ű������� �־��� ��, 
      ��� ������ �� ���� �ܼӿ� ī�޶� �������� �Ϸ��� �ּ� �� ���� ī�޶� ��ġ�ؾ� �ϴ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
      
   #. ���ѻ���
      - ������ ����� 1�� �̻� 10,000�� �����Դϴ�.
      - routes���� ������ �̵� ��ΰ� ���ԵǾ� ������ routes[i][0]���� i��° ������ ��ӵ��ο� ������ ����, 
        routes[i][1]���� i��° ������ ��ӵ��ο��� ���� ������ ���� �ֽ��ϴ�.
      - ������ ����/���� ������ ī�޶� ��ġ�Ǿ� �־ ī�޶� ���������� �����մϴ�.
      - ������ ���� ����, ���� ������ -30,000 �̻� 30,000 �����Դϴ�.
      
   #. ����� ��
                                        routes	return
      [[-20,15], [-14,-5], [-18,-13], [-5,-3]]	     2
      
   #. ����� �� ����
      - -5 ������ ī�޶� ��ġ�ϸ� �� ��°, �� ��° ������ ī�޶� �����ϴ�.
      - -15 ������ ī�޶� ��ġ�ϸ� ù ��°, �� ��° ������ ī�޶� �����ϴ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    //
    sort(routes.begin(), routes.end(), myCompare);

    int endPos = routes[0][1];
    for (int i = 1; i < routes.size(); i++)
    {
        if (endPos < routes[i][0])
        {
            answer++;
            endPos = routes[i][1];
        }
    }
    //
    return answer + 1;
}

int main()
{
    vector<vector<int>> routes = {
        {-20,15 }, { -14,-5 }, { -18,-13 }, { -5,-3 }
    };

    cout << solution(routes) << "\n";

    return 0;
}