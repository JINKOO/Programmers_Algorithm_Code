/*
  #. [ 프로그래머스_영어 끝말잇기 Level 2 ]
  #. 문제 설명
     1부터 n까지 번호가 붙어있는 n명의 사람이 영어 끝말잇기를 하고 있습니다. 
     영어 끝말잇기는 다음과 같은 규칙으로 진행됩니다.
     
     - 1번부터 번호 순서대로 한 사람씩 차례대로 단어를 말합니다.
     - 마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작합니다.
     - 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
     - 이전에 등장했던 단어는 사용할 수 없습니다.
     - 한 글자인 단어는 인정되지 않습니다.
     
     다음은 3명이 끝말잇기를 하는 상황을 나타냅니다.
     tank → kick → know → wheel → land → dream → mother → robot → tank
     
     위 끝말잇기는 다음과 같이 진행됩니다.
     - 1번 사람이 자신의 첫 번째 차례에 tank를 말합니다.
     - 2번 사람이 자신의 첫 번째 차례에 kick을 말합니다.
     - 3번 사람이 자신의 첫 번째 차례에 know를 말합니다.
     - 1번 사람이 자신의 두 번째 차례에 wheel을 말합니다.
     
     (계속 진행)
     끝말잇기를 계속 진행해 나가다 보면, 3번 사람이 자신의 세 번째 차례에 말한 tank 라는 단어는 
     이전에 등장했던 단어이므로 탈락하게 됩니다.
     
     사람의 수 n과 사람들이 순서대로 말한 단어 words 가 매개변수로 주어질 때, 
     가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 return 하도록 solution 함수를 완성해주세요.

  #. 제한 사항
     - 끝말잇기에 참여하는 사람의 수 n은 2 이상 10 이하의 자연수입니다.
     - words는 끝말잇기에 사용한 단어들이 순서대로 들어있는 배열이며, 길이는 n 이상 100 이하입니다.
     - 단어의 길이는 2 이상 50 이하입니다.
     - 모든 단어는 알파벳 소문자로만 이루어져 있습니다.
     - 끝말잇기에 사용되는 단어의 뜻(의미)은 신경 쓰지 않으셔도 됩니다.
     - 정답은 [ 번호, 차례 ] 형태로 return 해주세요.
     - 만약 주어진 단어들로 탈락자가 생기지 않는다면, [0, 0]을 return 해주세요.

  #. 입출력 예
     n	                                                                     words	result
     3	               [tank, kick, know, wheel, land, dream, mother, robot, tank]	 [3,3]
     5	              [hello, observe, effect, take, either, recognize, encourage, 
           ensure, establish, hang, gather, refer, reference, estimate, executive]	 [0,0]
     2	                               [hello, one, even, never, now, world, draw]	 [1,3]
     
  #. 입출력 예 설명
  #. 입출력 예 #1
     3명의 사람이 끝말잇기에 참여하고 있습니다.
     
     1번 사람 : tank, wheel, mother
     2번 사람 : kick, land, robot
     3번 사람 : know, dream, tank
     
     와 같은 순서로 말을 하게 되며, 3번 사람이 자신의 세 번째 차례에 말한 tank라는 단어가 
     1번 사람이 자신의 첫 번째 차례에 말한 tank와 같으므로 3번 사람이 자신의 세 번째 차례로 말을 할 때 처음 탈락자가 나오게 됩니다.

  #. 입출력 예 #2
     5명의 사람이 끝말잇기에 참여하고 있습니다.
     
     - 1번 사람 : hello, recognize, gather
     - 2번 사람 : observe, encourage, refer
     - 3번 사람 : effect, ensure, reference
     - 4번 사람 : take, establish, estimate
     - 5번 사람 : either, hang, executive
     
     와 같은 순서로 말을 하게 되며, 이 경우는 주어진 단어로만으로는 탈락자가 발생하지 않습니다. 
     따라서 [0, 0]을 return하면 됩니다.

  #. 입출력 예 #3
     2명의 사람이 끝말잇기에 참여하고 있습니다.
     
     1번 사람 : hello, even, now, draw
     2번 사람 : one, never, world
     
     와 같은 순서로 말을 하게 되며, 1번 사람이 자신의 세 번째 차례에 'r'로 시작하는 단어 대신, 
     n으로 시작하는 now를 말했기 때문에 이때 처음 탈락자가 나오게 됩니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    //
    vector<string> v;
    for (int i = 0; i < words.size(); i++)
    {
        string curr = words[i];
        if (v.empty())
        {
            v.push_back(curr);
            continue;
        }

        string prev = v.back();
        if (find(v.begin(), v.end(), curr) == v.end() && prev[prev.length() - 1] == curr[0])
            v.push_back(curr);
        else
        {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
    }
    //
    return answer;
}

void printResult(vector<int> answer)
{
    cout << "[" << answer[0] << " " << answer[1] << "]\n";
}

int main()
{

    printResult(solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" }));
    
    return 0;
}