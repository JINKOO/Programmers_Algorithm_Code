/*
  #. array에서 i~j원 소 추출 후
     정렬 한 다음
     k번째 원소 뽑기
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    //
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> v = commands[i];
        vector<int> temp;
        for (int j = v[0]; j <= v[1]; j++)
            temp.push_back(array[j - 1]);
        sort(temp.begin(), temp.end());

        for (int k = 0; k < temp.size(); k++)
        {
            if (k == v[2] - 1)
            {
                answer.push_back(temp[k]);
                break;
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << "\n";
    //
    return answer;
}
int main()
{
    vector<int> array = {1,5,2,6,3,7,4};
    vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };

    solution(array, commands);

    return 0;
}