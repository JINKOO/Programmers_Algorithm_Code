/*
  #. [ 프로그래머스_땅따먹기 Level 2 ]

  #. 문제 설명
     땅따먹기 게임을 하려고 합니다. 땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고, 
     모든 칸에는 점수가 쓰여 있습니다. 1행부터 땅을 밟으며 한 행씩 내려올 때, 
     각 행의 4칸 중 한 칸만 밟으면서 내려와야 합니다. 
     단, 땅따먹기 게임에는 한 행씩 내려올 때, 같은 열을 연속해서 밟을 수 없는 특수 규칙이 있습니다.

     예를 들면,

     | 1 | 2 | 3 | 5 |

     | 5 | 6 | 7 | 8 |

     | 4 | 3 | 2 | 1 |

     로 땅이 주어졌다면, 1행에서 네번째 칸 (5)를 밟았으면, 2행의 네번째 칸 (8)은 밟을 수 없습니다.
     마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 return하는 solution 함수를 완성해 주세요. 
     위 예의 경우, 1행의 네번째 칸 (5), 2행의 세번째 칸 (7), 3행의 첫번째 칸 (4) 땅을 밟아 16점이 최고점이 되므로 
     16을 return 하면 됩니다.

  #. 제한사항
     - 행의 개수 N : 100,000 이하의 자연수
     - 열의 개수는 4개이고, 땅(land)은 2차원 배열로 주어집니다.
     - 점수 : 100 이하의 자연수
     
  #. 입출력 예
                                land	answer
     [[1,2,3,5],[5,6,7,8],[4,3,2,1]]	    16
*/

/*
   #. 나의 풀이법.
      - 백준에서 풀어본 문제('RGB 거리_1149번')와 비슷하여서 DP라는 것을 바로 알았다.
      - 중요한 점은, 매 단계에서 반드시 최댓값을 선택하는 것이 결과값이 최댓값이 되진 않는다.
      - 메모이제이션으로 푼다. bottom-up방식.
      - dp[N][4] 이고, land[][]가 cost에 해당한다.

*/
#include <iostream>
#include <vector>
using namespace std;

int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    //
    int n = land.size();
    /*
      0. dp이차원 백터 선언(Memoization), 이전 단계에서 어떤 것을 선택하느냐에 4가지 경우의 수를 따지고
         각 자리에 현재까지의 최대 누적 점수 저장.
         n + 1이유 : 1부터 지정하기 위해
    */
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    
    //1. base_case :: dp[1]은 land[0]의 값 그대로.
    for (int i = 0; i < 4; i++)
        dp[1][i] = land[0][i];

    //2. 이전 단계에서 어느 값을 선택했냐에 따라, 현재값과 더하여 최댓값을 구한다.
    //   이때, 4열이므로, 4가지 경우를 모두 따져야 한다.

    for (int i = 2; i <= n; i++)
    {
        /*
           3. i=2일 때
              dp[2][0] = getMax([1][1], [1][2], [1][3]) + 현재 위치 값 
        */
        dp[i][0] = getMax(getMax(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][3]) + land[i - 1][0];
        dp[i][1] = getMax(getMax(dp[i - 1][0], dp[i - 1][2]), dp[i - 1][3]) + land[i - 1][1];
        dp[i][2] = getMax(getMax(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][3]) + land[i - 1][2];
        dp[i][3] = getMax(getMax(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + land[i - 1][3];
    }

    answer = getMax(getMax(getMax(dp[n][0], dp[n][1]), dp[n][2]), dp[n][3]);

    //
    return answer;
}

int main()
{
    vector<vector<int>> land = { {1,2,3,5}, {5,6,7,8}, {4,3,2,1} };
    cout << solution(land) << "\n";

    vector<int> v = { 1,2,3,4,5 };
    cout << v.back() << "\n";
    return 0;
}