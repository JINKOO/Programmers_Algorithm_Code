/*
  #. 모의고사
*/

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> p1 = { 1,2,3,4,5 };
vector<int> p2 = { 2,1,2,3,2,4,2,5 };
vector<int> p3 = { 3,3,1,1,2,2,4,4,5,5 };

int findMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //
    //수포자 3명에 대한 점수 vector
    vector<int> scores(3);
    for (int i = 0; i < answers.size(); i++)
    {
        //각각의 수포자에 대한 비교이므로 if문을 사용(if ~ else if) 하면 노노.
        if (answers.at(i) == p1.at(i % 5))
            scores.at(0)++;
        if (answers.at(i) == p2.at(i % 8))
            scores.at(1)++;
        if (answers.at(i) == p3.at(i % 10))
            scores.at(2)++;
    }

    for (int i = 0; i < scores.size(); i++)
        cout << scores.at(i) << " ";
    cout << "\n";

    int maxScore = findMax(findMax(scores.at(0), scores.at(1)), scores.at(2));
    cout << maxScore << "\n";
    for (int i = 0; i < scores.size(); i++)
    {
        if (scores.at(i) >= maxScore)
            answer.push_back(i + 1);
    }
    //
    return answer;
}

int main()
{
    vector<int> a = { 1,3,2,4,2 };
    vector<int> answer = solution(a);

    for (int i = 0; i < answer.size(); i++)
        cout << answer.at(i) << " ";
    cout << "\n";
    
    return 0;
}
