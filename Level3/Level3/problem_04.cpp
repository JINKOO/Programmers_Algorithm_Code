#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cost[21];
bool check[21];

vector<vector<int>> result;
vector<int> v;

void dfs(int n, int index, int count)
{
    if (count == n)
    {
        result.push_back(v);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            v.push_back(cost[i]);
            dfs(n, i + 1, count + 1);
            check[i] = false;
            v.pop_back();
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    //
    for (int i = 1; i <= n; i++)
        cost[i] = i;

    dfs(n, 1, 0);

    for (int i = 0; i < result[k-1].size(); i++)
        answer.push_back(result[k-1][i]);

    //
    return answer;
}

void printResult(vector<int> answer)
{
    for (int i : answer)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    printResult(solution(3, 5));

    return 0;
}