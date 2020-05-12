/*
  #. 같은 숫자는 싫어
  #. 문제 설명
     배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 
     이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 
     단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 
     예를 들면,
     arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
     arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
     배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

  #. 제한사항
  배열 arr의 크기 : 1,000,000 이하의 자연수
  배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수

  #. 입출력 예
     arr	            answer
     [1,1,3,3,0,1,1]	[1,3,0,1]
     [4,4,4,3,3]	    [4,3]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
  unique() :: 인접한 중복 원소 제거 but 뒤에 변하지 않는 부분 반환 
*/
vector<int> solution2(vector<int> arr)
{
    vector<int> answer;
    //
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    //
    return answer;
}

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    //
    int i = 0, j;
    while(i < arr.size())
    {
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] != arr[j])
                break;
        }
        i = j;
        answer.push_back(arr[j-1]);
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    cout << "\n";
    
    //
    return answer;
}

int main()
{
    vector<int> v = { 1,1,3,3,0,1,1 };
    vector<int> v2 = { 4,4,4,3,3 };
    
    //solution(v);
    //solution2(v2);

    solution2(v);
    solution2(v2);

    return 0;
}