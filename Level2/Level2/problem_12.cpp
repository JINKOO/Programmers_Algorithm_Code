/*
  #. [ 프로그래머스_행렬의 곱셈 Level 2 ]

  #. 문제 설명
     2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.

  #. 제한 조건
     - 행렬 arr1, arr2의 행과 열의 길이는 2 이상 100 이하입니다.
     - 행렬 arr1, arr2의 원소는 -10 이상 20 이하인 자연수입니다.
     - 곱할 수 있는 배열만 주어집니다.

  #. 입출력 예
                                  arr1	                             arr2	                                    return
              [[1, 4], [3, 2], [4, 1]]	                 [[3, 3], [3, 3]]	            [[15, 15], [15, 15], [15, 15]]
     [[2, 3, 2], [4, 2, 4], [3, 1, 4]]	[[5, 4, 3], [2, 4, 1], [3, 1, 1]]	[[22, 22, 11], [36, 28, 18], [29, 20, 14]]
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
   #. 나의 접근법.
      - 단순한 문제를 너무 어렵게 생각하였다.
      - bruteforce로 푼다.
*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    //
    //1. 우선 answer의 범위 만큼 이중반복.
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int sum = 0;
            for (int k = 0; k < arr2.size(); k++) //여기서 k는 (2*3)행렬 * (3*4)행렬일 때, 3번 반복이다.
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