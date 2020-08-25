/*
  #. [ 프로그래머스_정수 삼각형 Level 3 ]

     7
     3 8
     8 1 0
     2 7 4 4
     4 5 2 6 5

  #. 위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.
     삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 
     거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

  #. 제한사항
     - 삼각형의 높이는 1 이상 500 이하입니다.
     - 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.

  #. 입출력 예
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