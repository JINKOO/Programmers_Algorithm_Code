/*
  #. [ ���α׷��ӽ�_����� ���� Level 2 ]

  #. ���� ����
     2���� ��� arr1�� arr2�� �Է¹޾�, arr1�� arr2�� ���� ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

  #. ���� ����
     - ��� arr1, arr2�� ��� ���� ���̴� 2 �̻� 100 �����Դϴ�.
     - ��� arr1, arr2�� ���Ҵ� -10 �̻� 20 ������ �ڿ����Դϴ�.
     - ���� �� �ִ� �迭�� �־����ϴ�.

  #. ����� ��
                                  arr1	                             arr2	                                    return
              [[1, 4], [3, 2], [4, 1]]	                 [[3, 3], [3, 3]]	            [[15, 15], [15, 15], [15, 15]]
     [[2, 3, 2], [4, 2, 4], [3, 1, 4]]	[[5, 4, 3], [2, 4, 1], [3, 1, 1]]	[[22, 22, 11], [36, 28, 18], [29, 20, 14]]
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
   #. ���� ���ٹ�.
      - �ܼ��� ������ �ʹ� ��ư� �����Ͽ���.
      - bruteforce�� Ǭ��.
*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    //
    //1. �켱 answer�� ���� ��ŭ ���߹ݺ�.
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int sum = 0;
            for (int k = 0; k < arr2.size(); k++) //���⼭ k�� (2*3)��� * (3*4)����� ��, 3�� �ݺ��̴�.
            {
                sum+=arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    //
    return answer;
}

void printResult(vector<vector<int>> v)
{
    for (vector<int> e : v)
    {
        for (int i : e)
            cout << i << " ";
        cout << "\n";
    }
}

int main(void)
{
    vector<vector<int>> arr1 = {{ 1, 4},{3, 2},{4, 1}};
    vector<vector<int>> arr2 = { {3, 3},{3, 3} };
    
    printResult(solution(arr1, arr2));
       
    return 0;
}