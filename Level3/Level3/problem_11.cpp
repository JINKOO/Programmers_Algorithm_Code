/*
   #. [ ���α׷��ӽ�_���߿켱����ť Level 3 ]
   
   #. ���� ����
      ���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.
      
      ��ɾ�	       ���� ž(����)
      I ����	       ť�� �־��� ���ڸ� �����մϴ�.
      D 1	       ť���� �ִ��� �����մϴ�.
      D -1	       ť���� �ּڰ��� �����մϴ�.
      
      ���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, 
      ��� ������ ó���� �� ť�� ��������� [0,0] ������� ������ [�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���.
      
   #. ���ѻ���
      - operations�� ���̰� 1 �̻� 1,000,000 ������ ���ڿ� �迭�Դϴ�.
      - operations�� ���Ҵ� ť�� ������ ������ ��Ÿ���ϴ�.
      - ���Ҵ� ����ɾ� �����͡� �������� �־����ϴ�.- �ִ�/�ּڰ��� �����ϴ� ���꿡�� �ִ�/�ּڰ��� �� �̻��� ���, �ϳ��� �����մϴ�.
      - �� ť�� �����͸� �����϶�� ������ �־��� ���, �ش� ������ �����մϴ�.
      
   #. ����� ��
      operations	        return
      [I 16,D 1]	        [0,0]
      [I 7,I 5,I -5,D -1]	[7,5]
      
   #. ����� �� ����
      16�� ���� �� �ִ��� �����մϴ�. ��������Ƿ� [0,0]�� ��ȯ�մϴ�.
      7,5,-5�� ���� �� �ּڰ��� �����մϴ�. �ִ밪 7, �ּҰ� 5�� ��ȯ�մϴ�.
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
    //min_heap����
    //min_heap�� �������� �Ͽ���.
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < operations.size(); i++)
    {
        string str = operations[i];
        
        //���ڿ� �ɰ���
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

        //�� ��ɾ� ó��
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
                    //max_heap����
                    priority_queue<int, vector<int>, less<int>> max_heap;

                    //min_heap -> max_heap���� �̵���Ŵ.
                    while (!min_heap.empty())
                    {
                        max_heap.push(min_heap.top());
                        min_heap.pop();
                    }

                    //�ִ� pop()
                    max_heap.pop();

                    //�ٽ� max_heap -> min_heap���� �̵���Ŵ
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