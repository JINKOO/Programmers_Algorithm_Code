/*
   #. [ 프로그래머스_이중우선순위큐 Level 3 ]
   
   #. 문제 설명
      이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.
      
      명령어	       수신 탑(높이)
      I 숫자	       큐에 주어진 숫자를 삽입합니다.
      D 1	       큐에서 최댓값을 삭제합니다.
      D -1	       큐에서 최솟값을 삭제합니다.
      
      이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 
      모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.
      
   #. 제한사항
      - operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.
      - operations의 원소는 큐가 수행할 연산을 나타냅니다.
      - 원소는 “명령어 데이터” 형식으로 주어집니다.- 최댓값/최솟값을 삭제하는 연산에서 최댓값/최솟값이 둘 이상인 경우, 하나만 삭제합니다.
      - 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.
      
   #. 입출력 예
      operations	        return
      [I 16,D 1]	        [0,0]
      [I 7,I 5,I -5,D -1]	[7,5]
      
   #. 입출력 예 설명
      16을 삽입 후 최댓값을 삭제합니다. 비어있으므로 [0,0]을 반환합니다.
      7,5,-5를 삽입 후 최솟값을 삭제합니다. 최대값 7, 최소값 5를 반환합니다.
*/


#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    //
    //min_heap선언
    //min_heap을 기준으로 하였다.
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < operations.size(); i++)
    {
        string str = operations[i];
        
        //문자열 쪼개기
        char* c = new char[str.length() + 1];
        strcpy_s(c, str.length() + 1, str.c_str());
        char* context = nullptr;
        char* ptr = strtok_s(c, " ", &context);

        string s[2];
        int j = 0;
        while (ptr != nullptr)
        {
            s[j++] = ptr;
            ptr = strtok_s(nullptr, " ", &context);
        }

        //각 명령어 처리
        if (s[0] == "I")
            min_heap.push(stoi(s[1]));
        else if (s[0] == "D")
        {
            if (!min_heap.empty())
            {
                if (s[1] == "-1")
                    min_heap.pop();
                else if (s[1] == "1")
                {
                    //max_heap선언
                    priority_queue<int, vector<int>, less<int>> max_heap;

                    //min_heap -> max_heap으로 이동시킴.
                    while (!min_heap.empty())
                    {
                        max_heap.push(min_heap.top());
                        min_heap.pop();
                    }

                    //최댓값 pop()
                    max_heap.pop();

                    //다시 max_heap -> min_heap으로 이동시킴
                    while (!max_heap.empty())
                    {
                        min_heap.push(max_heap.top());
                        max_heap.pop();
                    }
                }
            }
        }
    }

    if (min_heap.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    else
    {
        int max;
        int min = min_heap.top();
        stack<int> s;
        while (!min_heap.empty())
        {
            s.push(min_heap.top());
            min_heap.pop();
        }
        max = s.top();
        
        answer.push_back(max);
        answer.push_back(min);
    }
    
    //
    return answer;
}

int main()
{

    vector<int> answer = solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << "\n";

    vector<int> answer2 = solution({ "I 16","D 1" });
    for (int i = 0; i < answer2.size(); i++)
        cout << answer2[i] << " ";
    cout << "\n";
}