/*
  #. [ 프로그래머스_구명보트 Level 2 ]
  #. 문제 설명
     무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 
     구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.
     
     예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 
     2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 
     구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.
     
     구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.
     
     사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 
     모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

  #. 제한사항
     - 무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
     - 각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
     - 구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
     - 구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.
 
  #. 입출력 예
              people	limit	return
    [70, 50, 80, 50]	  100	     3
        [70, 80, 50]	  100	     3
*/

/*
  #. 나의 풀이법.
     - 처음 오름차순으로 정렬하고, boat라는 vector를 사용하여 몸무게가 가장 낮은 사람부터 차례대로 
       limit  범위에 맞게 삽입하였다. --> 틀린 방식
       ex). 50 50 70 80 이고, limit가 130인 경우에 최솟값은 2이지만, 내가 한 방식은 3이 나온다.
  
  #. 풀이
     - Greedy한 방식 '가장 가벼운 사람 + 가장 무거운 사람 <= limit'
     - > limit이면, 무거운 사람을 먼저 보낸다.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    //
    //0. 오름 차순 정렬. greedy
    sort(people.begin(), people.end());

    //1. 가장 가벼운 사람, 가장 무거운 사람 index
    int less = 0;
    int more = people.size() - 1;

    while (less <= more)
    {
        //가장 가벼운 사람과 가장  무거운 사람 무게 제한에 알걸리면, 각 index조정.
        if (people[less] + people[more] <= limit)
        {
            less++;
            more--;
        }

        //limit를 초과하면, 무거운 사람을 먼저 보낸다.
        else
            more--;

        answer++;
    }
    //
    return answer;
}

int main()
{

    cout << solution({ 70, 50, 80, 50 }, 100) << "\n";
    cout << solution({ 70, 50, 80, 50 }, 130) << "\n";
    return 0;
}