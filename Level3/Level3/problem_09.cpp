/*
   #. [ ���α׷��ӽ�_ ������ Level 3 ]
   
   #. ���� ����
      �־��� �װ����� ��� �̿��Ͽ� �����θ� ¥���� �մϴ�. �׻� ICN ���׿��� ����մϴ�.
      �װ��� ������ ��� 2���� �迭 tickets�� �Ű������� �־��� ��, �湮�ϴ� ���� ��θ� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
      
   #. ���ѻ���
      - ��� ������ ���ĺ� �빮�� 3���ڷ� �̷�����ϴ�.
      - �־��� ���� ���� 3�� �̻� 10,000�� �����Դϴ�.
      - tickets�� �� �� [a, b]�� a ���׿��� b �������� ���� �װ����� �ִٴ� �ǹ��Դϴ�.
      - �־��� �װ����� ��� ����ؾ� �մϴ�.
      - ���� ������ ��ΰ� 2�� �̻��� ��� ���ĺ� ������ �ռ��� ��θ� return �մϴ�.
      - ��� ���ø� �湮�� �� ���� ���� �־����� �ʽ��ϴ�.
      
  #. ����� ��
     tickets	                                                    return
     [[ICN, JFK], [HND, IAD], [JFK, HND]]	                                  [ICN, JFK, HND, IAD]
     [[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL,SFO]]	[ICN, ATL, ICN, SFO, ATL, SFO]
     
  #. ����� �� ����
     ���� #1
     [ICN, JFK, HND, IAD] ������ �湮�� �� �ֽ��ϴ�.
     ���� #2
     [ICN, SFO, ATL, ICN, ATL, SFO] ������ �湮�� ���� ������ [ICN, ATL, ICN, SFO, ATL, SFO] �� ���ĺ� ������ �ռ��ϴ�.
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
    //des�� route�� ����.
    route.push_back(des);

    //���� ��ΰ� tickets,size()�̸�, �ĺ� ��ΰ� �ǹǷ�, result�� ����.
    if (count == tickets.size())
    {
        result.push_back(route);
        return;
    }

    //��ΰ� �� �� �ִ� ��� ��� üũ.
    for (int i = 0; i < tickets.size(); i++)
    {
        //���� ��η� �̾��� �� �ְ�, ���� ������� ���� �װ����̸�,
        if (des == tickets[i][0] && check[i] == false)
        {
            //���� �װ��� �湮ó��
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
    //1. ������ �׻� ICN�����̴�.
    for (int i = 0; i < tickets.size(); i++)
    {
        vector<bool> check(tickets.size(), false);
        if (tickets[i][0] == "ICN" && !check[i])
        {
            route.push_back("ICN");
            dfs(tickets, check, i, tickets[i][1], 1);
            //�� �ٸ� ICN���� �����ϴ� ��� Ž�� ���� route�� ����ش�.
            route.clear();
        }
    }

    //2. ICN���� �����ϴ� ��ε��� ����ִ� result�� ���ĺ� �� ����
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