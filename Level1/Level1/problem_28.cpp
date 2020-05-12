#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    //
    int x = n;
    int y = m;
    while (1)
    {
        if (y < x)
        {
            int temp = x;
            x = y;
            y = x;
        }
        
        if (y - x <= 0)
        {
            answer.push_back(y);
            break;
        }
        y = y - x;
    }
 
    answer.push_back(answer.at(0) * (n / answer.at(0)) * (m / answer.at(0)));
    //
    return answer;
}

void printResult(vector<int> answer)
{
    for (int i = 0; i < answer.size(); i++)
        cout << answer.at(i) << " ";
    cout << "\n";
}

int main()
{
    printResult(solution(3, 12));
    printResult(solution(12, 18));

    return 0;
}