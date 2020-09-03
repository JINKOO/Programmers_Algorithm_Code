/*
   #. [ 프로그래머스_ 여행경로 Level 3 ]
   
   #. 문제 설명
      주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 ICN 공항에서 출발합니다.
      항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
      
   #. 제한사항
      - 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
      - 주어진 공항 수는 3개 이상 10,000개 이하입니다.
      - tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
      - 주어진 항공권은 모두 사용해야 합니다.
      - 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
      - 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
      
  #. 입출력 예
     tickets	                                                    return
     [[ICN, JFK], [HND, IAD], [JFK, HND]]	                                  [ICN, JFK, HND, IAD]
     [[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL,SFO]]	[ICN, ATL, ICN, SFO, ATL, SFO]
     
  #. 입출력 예 설명
     예제 #1
     [ICN, JFK, HND, IAD] 순으로 방문할 수 있습니다.
     예제 #2
     [ICN, SFO, ATL, ICN, ATL, SFO] 순으로 방문할 수도 있지만 [ICN, ATL, ICN, SFO, ATL, SFO] 가 알파벳 순으로 앞섭니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> route;
vector<vector<string>> result;

void dfs(vector<vector<string>> tickets, vector<bool>& check, int index, string des, int count)
{
    //des를 route에 삽입.
    route.push_back(des);

    //만약 경로가 tickets,size()이면, 후보 경로가 되므로, result에 삽입.
    if (count == tickets.size())
    {
        result.push_back(route);
        return;
    }

    //경로가 될 수 있는 모든 경우 체크.
    for (int i = 0; i < tickets.size(); i++)
    {
        //다음 경로로 이어질 수 있고, 아직 사용하지 않은 항공권이면,
        if (des == tickets[i][0] && check[i] == false)
        {
            //현재 항공권 방문처리
            check[index] = true;
            dfs(tickets, check, i, tickets[i][1], count + 1);
            check[index] = false;
            route.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer;
    //
    //1. 시작은 항상 ICN부터이다.
    for (int i = 0; i < tickets.size(); i++)
    {
        vector<bool> check(tickets.size(), false);
        if (tickets[i][0] == "ICN" && !check[i])
        {
            route.push_back("ICN");
            dfs(tickets, check, i, tickets[i][1], 1);
            //또 다른 ICN으로 시작하는 경로 탐색 위해 route를 비워준다.
            route.clear();
        }
    }

    //2. ICN으로 시작하는 경로들이 들어있는 result를 알파벳 순 정렬
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    answer = result[0];
    //
    return answer;
}

void printResult(vector<string> answer)
{
    for (string s : answer)
        cout << s << " ";
    cout << "\n";
}

int main()
{
    printResult(solution({{ "ICN", "JFK" }, { "HND", "IAD" }, { "JFK", "HND" }}));
    printResult(solution({{"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"}}));

    return 0;
}