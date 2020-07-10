/*
  #. [ 프로그래머스_H-Index ]
  #. 문제 설명
     H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 
     어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 
     위키백과1에 따르면, H-Index는 다음과 같이 구합니다.
     
     어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 
     h의 최댓값이 이 과학자의 H-Index입니다.

     어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 
     이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

  #. 제한사항
     - 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
     - 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

  #. 입출력 예
           citations	return
     [3, 0, 6, 1, 5]	     3
    
  #. 입출력 예 설명
     이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 
     그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

※ 공지 - 2019년 2월 28일 테스트 케이스가 추가되었습니다.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    //
    sort(citations.begin(), citations.end());
    int max_h = citations[citations.size() - 1];
    vector<int> v;
    for (int h = 1; h <= max_h; h++)
    {
        int count1 = 0;
        int count2 = 0;
        for (int j = 0; j < citations.size(); j++)
        {
            if (h <= citations[j])
                count1++;
            else
                count2++;
        }
        if (h <= count1 && h >= count2)
            v.push_back(h);
    }

    if (v.empty())
        answer = 0;
    else  // citations를 정렬하였으므로, v에 오름차순으로 값이 삽입되기 때문에 최댓값은 마지막 원소이다. 
        answer = v[v.size() - 1];
    //
    return answer;
}

int main()
{

    cout << solution({ 3, 0, 6, 1, 5 }) << "\n";

    return 0;
}