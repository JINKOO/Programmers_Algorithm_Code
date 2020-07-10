/*
  #. [ 프로그래머스_카펫 Level 2]
  
  #. Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 
     테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
     
     Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 
     전체 카펫의 크기는 기억하지 못했습니다.
     
     Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 
     카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

  #. 제한사항
     - 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
     - 노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
     - 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
  
  #. 입출력 예
     brown	yellow	 return
        10	     2	 [4, 3]
         8	     1	 [3, 3]
        24	    24	 [8, 6]
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
   #. 나의 접근 법.
      - 1. yellow의 약수를 구하고, width >= height일 때에만, 임시 vector에 삽입.
      - 2. 이 vector에서 brown의 개수와 맞는 것이 답이다.
        brown의 개수 : ((yellow의 width + 2) * 2 + (yellow의 height + 2) * 2) - 4

        B B B B B B
        B Y Y Y Y B
        B B B B B B
      
      - 한번에 성공

      2번 부분이 '완전 탐색' 부분인듯
*/
vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    //
    vector<pair<int, int>> v;
    //1. yellow의 약수 판별 == 가로, 세로 개수 파악.
    int width, height;
    for (int i = 1; i <= yellow; i++)
    {
        width = 0;
        height = 0;
        //1.1약수이면, 가로 >= 세로인 경우vector에 삽입.
        if (yellow % i == 0)
        {
            height = i;
            width = yellow / i;
            if (width >= height)
                v.push_back(make_pair(width, height));
            else 
                //(12인 경우(3,4), (4,3))가 존재하는데 이 때 뒤에 것은 생각하지 않음. 
                break;
        }
    }

    //2. v에서 brown의 개수와 맞는 경우 찾고 answer에 삽입.
    for (int i = 0; i < v.size(); i++)
    {
        int yw = v[i].first + 2;
        int yh = v[i].second + 2;
        if (((yw * 2 + yh * 2) - 4) == brown)
        {
            answer.push_back(yw);
            answer.push_back(yh);
            break;
        }
    }
    //
    return answer;
}

void printResult(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << "\n";
}

int main()
{

    printResult(solution(10, 2));
    printResult(solution(8, 1));
    printResult(solution(24, 24));

    return 0;
}