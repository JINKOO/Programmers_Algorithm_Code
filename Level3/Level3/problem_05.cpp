/*
   #. [ 프로그래머스_방문 길이 Level 3 ] 
   
   #. 문제 설명
      게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.
      U: 위쪽으로 한 칸 가기
      D: 아래쪽으로 한 칸 가기
      R: 오른쪽으로 한 칸 가기
      L: 왼쪽으로 한 칸 가기
      캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 
      좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.
      
      예를 들어, ULURRDLLU로 명령했다면
      1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.
      8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다.
      
      이때, 우리는 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하려고 합니다. 
      예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. 
      (8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)
      단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.
      
      예를 들어, LULLLLLLU로 명령했다면
      1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다. 다시 9번 명령어대로 움직입니다.
      이때 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.
      
      명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.
      
      
   #. 제한사항
      - dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
      - dirs의 길이는 500 이하의 자연수입니다.

   #. 입출력 예
           dirs	    answer
      ULURRDLLU	         7
*/


/*
    #. 풀이법.
       - 도대체 4차원 배열을 어떻게 생각한 것인지....
       - 처음에 check를 2차원 배열로 선언했을 때, 다음 가야할 곳이 방문 처리되어 아예 못가는 상황이 발생한다.
         이를 해결하기 위해 4차원 배열을 사용한다.
         [i][j][ni][nj]의 의미 = 캐릭터가 움직인 경로
         점이 아니라, 길이기 때문에 양방향 모두 신경써야 한다.

*/
#include <string>
#include <iostream>
using namespace std;

bool check[11][11][11][11]; //현재 i, j에서 nexti, nextj의 경로 지나왔는지 판별

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int solution(string dirs) 
{
    int answer = 0;
    //

    //1. 초기 i, j
    int i = 0;
    int j = 0;

    //2. 시작 위치
    int ni = 5;
    int nj = 5;

    int index = 0;
    for (int k = 0; k < dirs.length(); k++)
    {
        i = ni;
        j = nj;
        if (dirs[i] == 'U')
            index = 0;
        else if (dirs[i] == 'D')
            index = 1;
        else if (dirs[i] == 'L')
            index = 2;
        else if (dirs[i] == 'R')
            index = 3;

        ni = i + di[index];
        nj = j + dj[index];

        //다음 이동 좌표가 범위안에 있을때
        if (0 <= ni && ni <= 10 && 0 <= nj && nj <= 10)
        {
            //처음 온 길이면,
            if (!check[i][j][ni][nj])
            {
                //양방향 모두 true로 만들어 준다. 즉, 현재까지 온 길을 true로 만든다.
                check[i][j][ni][nj] = true;
                check[ni][nj][i][j] = true;
                answer++;
            }
        }
        //다음 이동 좌표가 범위안에 없으면, 이전 i, j로 되돌려야한다.
        else
        {
            ni -= di[index];
            nj -= dj[index];
        }
    }
    //
    return answer;
}

int main()
{
    cout << solution("ULURRDLLU") << "\n";
    cout << solution("LULLLLLLU") << "\n";

    return 0;
}