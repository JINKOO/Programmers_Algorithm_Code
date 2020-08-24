/*
   #. [ ���α׷��ӽ�_�ְ��� ���� Level 3 ]
   
   #. ���� ����
      �ڿ��� n ���� �̷���� �ߺ� ����(multi set, ���ǻ� ���Ŀ��� �������� ��Ī) �߿� ���� �� ������ �����ϴ� ������ �ְ��� �����̶�� �մϴ�.
      
      1. �� ������ ���� S�� �Ǵ� ���� ����
      2. �� ������ �����ϸ鼭 �� ������ �� �� �ִ밡 �Ǵ� ����
      
      ���� �� �ڿ��� 2���� �̷���� ���� �� ���� 9�� �Ǵ� ������ ������ ���� 4���� �ֽ��ϴ�.
      { 1, 8 }, { 2, 7 }, { 3, 6 }, { 4, 5 }
      ���� �� ������ ���� �ִ��� { 4, 5 }�� �ְ��� �����Դϴ�.
      
      ������ ������ ���� n�� ��� ���ҵ��� �� s�� �Ű������� �־��� ��, �ְ��� ������ return �ϴ� solution �Լ��� �ϼ����ּ���.
      
   #. ���ѻ���
      - �ְ��� ������ ������������ ���ĵ� 1���� �迭(list, vector) �� return ���ּ���.
      - ���� �ְ��� ������ �������� �ʴ� ��쿡 ũ�Ⱑ 1�� 1���� �迭(list, vector) �� -1 �� ä���� return ���ּ���.
      - �ڿ����� ���� n�� 1 �̻� 10,000 ������ �ڿ����Դϴ�.
      - ��� ���ҵ��� �� s�� 1 �̻�, 100,000,000 ������ �ڿ����Դϴ�.
      
   #. ����� ��
       n	   s	result
       2	   9	[4, 5]
       2	   1	  [-1]
       2	   8	[4, 4]
      
   #. ����� �� ����
      ����� ��#1
      ������ ���ÿ� �����ϴ�.
      
      ����� ��#2
      �ڿ��� 2���� ������� ���� 1�� ������ ���� �� �����ϴ�. ���� -1�� ����ִ� �迭�� ��ȯ�մϴ�.
      
      ����� ��#3
      �ڿ��� 2���� �̷���� ���� �� ������ ���� 8�� ������ ������ �����ϴ�.
      { 1, 7 }, { 2, 6 }, { 3, 5 }, { 4, 4 }
      ���� �� ������ ���� �ִ��� { 4, 4 }�� �ְ��� �����Դϴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cost[10];
int _max;
vector<int> v;
vector<pair<int, vector<int>>> result;

void dfs(int index, int count, int n, int s)
{
    if (count == n)
    {
        int total = 0;
        for (int i = 0; i < v.size(); i++)
            total += v[i];

        if (total == s)
        {
            int multiple = 1;
            for (int i = 0; i < v.size(); i++)
                multiple *= v[i];

            if (multiple > _max)
            {
                cout << multiple << "\n";
                _max = multiple;
                result.push_back(make_pair(_max, v));
            }
        }
        return;
    }

    for (int i = index; i <= 9; i++)
    {
        v.push_back(cost[i]);
        dfs(i, count + 1, n, s);
        v.pop_back();
    }
}

vector<int> solution1(int n, int s) {
    vector<int> answer;
    //
    for (int i = 1; i <= 9; i++)
        cost[i] = i;

    dfs(1, 0, n, s);


    for (int i = 0; i < result.size(); i++)
    {
        if (result[i].first == _max)
        {
            //cout << _max << "\n";
            for (int j = 0; j < result[i].second.size(); j++)
                answer.push_back(result[i].second[j]);
        }
    }

    if (answer.size() != 0)
        sort(answer.begin(), answer.end(), less<int>());
    else
        answer.push_back(-1);
    //
    return answer;
}

void printResult(vector<int> answer)
{
    for (int i : answer)
        cout << i << " ";
    cout << "\n";
}

/*
   #. ���� �յ��ϰ� �̷���� ���ڵ��� ���� ���� ũ��.

*/
vector<int> solution2(int n, int s)
{
    vector<int> answer;
    //
    int c = 0;
    if (n > s)
        answer.push_back(-1);
    else
    {
        answer.resize(n);
        for (int i = n; i > 0; i--)
        {
            answer[c++] = s / i;
            s -= (s / i);
        }
    }
    //
    return answer;
}

int main()
{
    printResult(solution1(5, 13));

    printResult(solution2(5, 13));
    
    return 0;
}