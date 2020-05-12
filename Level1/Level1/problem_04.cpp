/*
  #. 체육복(Greedy Algorithm)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //
    //1. check 각인원마다 체육복있는지 초기화
    vector<int> check(n, 1);
    for (int i = 0; i < lost.size(); i++)
        check.at((lost.at(i) - 1))--;

    for (int i = 0; i < reserve.size(); i++)
        check.at(reserve.at(i) - 1)++;

    
    //for (int i = 0; i < check.size(); i++)
    //    cout << check.at(i) << " ";
    
    //2. 실질적인 검사
    for (int i = 0; i < n - 1; i++)
    {
        if (check.at(i) == 0)  // if no wear
        {
            if (i != 0 && check.at(i - 1) == 2)        // if first index
            {
                check.at(i - 1)--;
                check.at(i)++;
            }

            else if(i != check.size() - 1 && check.at(i + 1) == 2)               //if index starts from 1
            {
                check.at(i + 1)--;
                check.at(i)++;
            }
        }
    }

    for (int i = 0; i < check.size(); i++)
    {
        cout << check.at(i) << " ";
        if (check.at(i) >= 1)
            answer++;
    }
    cout << "\n";
    cout << answer << "\n";
    //
    
    return answer;
}

int main()
{
    int n = 5;
    vector<int> lost = { 2,4 };
    vector<int> reserve = { 1,3,5 };
    solution(n, lost, reserve);

    int n2 = 7;
    vector<int> lost2 = { 2,3,4,5 };
    vector<int> reserve2 = { 6 };
    solution(n2, lost2, reserve2);

    int n3 = 3;
    vector<int> lost3 = {3};
    vector<int> reserve3 = {1};
    solution(n3, lost3, reserve3);

    return 0;
}
