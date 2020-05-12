/*
  #. [ ����� ���� ]
  
  #. ���� ����
     ����� ������ ��� ���� ũ�Ⱑ ���� �� ����� ���� ��, ���� ���� ���� ���� ���� ����� �˴ϴ�. 
     2���� ��� arr1�� arr2�� �Է¹޾�, ��� ������ ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

  #. ���� ����
     ��� arr1, arr2�� ��� ���� ���̴� 500�� ���� �ʽ��ϴ�.
  
  #. ����� ��
              arr1	         arr2   	   return
     [[1,2],[2,3]]	[[3,4],[5,6]]	[[4,6],[7,9]]
         [[1],[2]]	    [[3],[4]]	    [[4],[6]]
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    //
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < arr1[i].size(); j++)
            v.push_back(arr1[i][j] + arr2[i][j]);
        answer.push_back(v);
    }
    //
    return answer;
}

void printResult(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer.at(i).size(); j++)
            cout << answer[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> arr1 = { {1,2}, {2,3} };
    vector<vector<int>> arr2 = { {4,5}, {6,7} };
    printResult(solution(arr1, arr2));
    printResult(solution({ { 1 }, { 2 } }, { { 3 }, { 4 } }));
    
    return 0;
}










