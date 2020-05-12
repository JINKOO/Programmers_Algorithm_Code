/*
  #. 나누어 떨어지는 숫자 배열
  #. 문제 설명
     array의 각 element 중 divisor로 나누어 떨어지는 값을 
     오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
     divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.

  #. 제한사항
     arr은 자연수를 담은 배열입니다.
     정수 i, j에 대해 i ≠ j 이면 arr[i] ≠ arr[j] 입니다.
     divisor는 자연수입니다.
     array는 길이 1 이상인 배열입니다.

  #. 입출력 예
     arr	         divisor	   return
     [5, 9, 7, 10]	       5  	   [5, 10]
     [2, 36, 1, 3]	       1	   [1, 2, 3, 36]
           [3,2,6]	      10	   [-1]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> arr)
{
    vector<int>::iterator iter;
    for (iter = arr.begin(); iter != arr.end(); iter++)
        cout << *iter << " ";
    cout << "\n";
}

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;
    //
    sort(arr.begin(), arr.end());
    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
    {
        if (*iter % divisor == 0)
            answer.push_back(*iter);
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    
    //
    return answer;
}

int main()
{
    int d1 = 5, d2 = 1, d3 = 10;

    vector<int> v1 = { 5,9,7,10 };
    print(solution(v1, d1));
    vector<int> v2 = { 2,36,1,3 };
    print(solution(v2, d2));
    vector<int> v3 = { 3,2,6 };
    print(solution(v3, d3));

    return 0;
}