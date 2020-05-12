#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
  속도 개선 --> 정렬
*/
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int i;
    for (i = 0; i < completion.size(); i++)
    {
        if (participant.at(i) != completion.at(i))
        {
            answer = participant.at(i);
            break;
        }
    }

    if (i == completion.size())
        answer = participant.at(i);

    cout << answer << "\n";
    //
    return answer;
}

int main()
{
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "kiki", "eden" };

    solution(participant, completion);

    vector<string> p2 = { "mislav", "stanko", "mislav", "ana" };
    vector<string> c2 = { "stanko", "ana", "mislav" };

    solution(p2, c2);

    return 0;
}