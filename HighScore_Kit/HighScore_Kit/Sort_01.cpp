/*
  #. [ ���α׷��ӽ�_K��°�� ]
  #. ���� ����
     �迭 array�� i��° ���ں��� j��° ���ڱ��� �ڸ��� �������� ��, k��°�� �ִ� ���� ���Ϸ� �մϴ�.
     ���� ��� array�� [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3�̶��
     
     1. array�� 2��°���� 5��°���� �ڸ��� [5, 2, 6, 3]�Դϴ�.
     2. 1���� ���� �迭�� �����ϸ� [2, 3, 5, 6]�Դϴ�.
     3. 2���� ���� �迭�� 3��° ���ڴ� 5�Դϴ�.
     
     �迭 array, [i, j, k]�� ���ҷ� ���� 2���� �迭 commands�� �Ű������� �־��� ��, 
     commands�� ��� ���ҿ� ���� �ռ� ������ ������ �������� �� ���� ����� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���ѻ���
     - array�� ���̴� 1 �̻� 100 �����Դϴ�.
     - array�� �� ���Ҵ� 1 �̻� 100 �����Դϴ�.
     - commands�� ���̴� 1 �̻� 50 �����Դϴ�.
     - commands�� �� ���Ҵ� ���̰� 3�Դϴ�.
  
  #. ����� ��
                     array	                        commands	   return
     [1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	[5, 6, 3]

  #. ����� �� ����
     - [1, 5, 2, 6, 3, 7, 4]�� 2��°���� 5��°���� �ڸ� �� �����մϴ�. [2, 3, 5, 6]�� �� ��° ���ڴ� 5�Դϴ�.
     - [1, 5, 2, 6, 3, 7, 4]�� 4��°���� 4��°���� �ڸ� �� �����մϴ�. [6]�� ù ��° ���ڴ� 6�Դϴ�.
     - [1, 5, 2, 6, 3, 7, 4]�� 1��°���� 7��°���� �ڸ��ϴ�. [1, 2, 3, 4, 5, 6, 7]�� �� ��° ���ڴ� 3�Դϴ�.
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    //
    for (int c = 0; c < commands.size(); c++)
    {
        int i = commands[c][0];
        int j = commands[c][1];
        int k = commands[c][2];

        vector<int> temp;
        for (int k = i - 1; k <= j - 1; k++)
            temp.push_back(array[k]);

        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k-1]);
    }
    //
    return answer;
}

void printResult(vector<int> v)
{
    for (int i : v)
        cout << i << " ";

    cout << "\n";
}

int main()
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commmands = { {2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 }};

    printResult(solution(array, commmands));

    return 0;
}