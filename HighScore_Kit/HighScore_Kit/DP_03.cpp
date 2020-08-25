/*
  #. [ ���α׷��ӽ�_���� �ﰢ�� Level 3 ]

     7
     3 8
     8 1 0
     2 7 4 4
     4 5 2 6 5

  #. ���� ���� �ﰢ���� ����⿡�� �ٴڱ��� �̾����� ��� ��, ���İ� ������ ���� ���� ū ��츦 ã�ƺ����� �մϴ�. �Ʒ� ĭ���� �̵��� ���� �밢�� �������� �� ĭ ������ �Ǵ� �������θ� �̵� �����մϴ�. ���� ��� 3������ �� �Ʒ�ĭ�� 8 �Ǵ� 1�θ� �̵��� �����մϴ�.
     �ﰢ���� ������ ��� �迭 triangle�� �Ű������� �־��� ��, 
     ���İ� ������ �ִ��� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

  #. ���ѻ���
     - �ﰢ���� ���̴� 1 �̻� 500 �����Դϴ�.
     - �ﰢ���� �̷�� �ִ� ���ڴ� 0 �̻� 9,999 ������ �����Դϴ�.

  #. ����� ��
     triangle	                                                 result
     [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	     30
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[501][501];

int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    //
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                dp[i][j] = getMax(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }

            answer = getMax(answer, dp[i][j]);
        }
    }
    //
    return answer;
}

void init(vector<vector<int>> &triangle)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j <= i; j++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        triangle.push_back(v);
    }
}

int main()
{
    vector<vector<int>> triangle;

    init(triangle);
    cout << solution(triangle) << "\n";

    return 0;
}