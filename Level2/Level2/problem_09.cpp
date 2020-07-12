/*
  #. [ 프로그래머스_더 맵게 ]
  
  #. 문제 설명
     매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 
     모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.
     
     섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
     
     Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
     Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 
     모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

  #. 제한 사항
     - scoville의 길이는 2 이상 1,000,000 이하입니다.
     - K는 0 이상 1,000,000,000 이하입니다.
     - scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
     - 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.

  #. 입출력 예
                scoville	K	return
     [1, 2, 3, 9, 10, 12]	7	     2

  #. 입출력 예 설명
     스코빌 지수가 1인 음식과 2인 음식을 섞으면 음식의 스코빌 지수가 아래와 같이 됩니다.
     새로운 음식의 스코빌 지수 = 1 + (2 * 2) = 5
     가진 음식의 스코빌 지수 = [5, 3, 9, 10, 12]
     
     스코빌 지수가 3인 음식과 5인 음식을 섞으면 음식의 스코빌 지수가 아래와 같이 됩니다.
     새로운 음식의 스코빌 지수 = 3 + (5 * 2) = 13
     가진 음식의 스코빌 지수 = [13, 9, 10, 12]
     
     모든 음식의 스코빌 지수가 7 이상이 되었고 이때 섞은 횟수는 2회입니다.
*/

/*
   #. 나의 접근법.
      - 초반에 queue를 사용해서 풀려고 하였다.
      - 예전 자료구조때 heap은 우선순위 큐를 사용하여 정렬상태를 유지한다는 생각이나서
        우선순위 큐 사용.
      - 우선 순위 큐를 사용함으로써, 정렬 상태를 유지 할 수 있다. 여기서는 오름차순..
        scoville의 원소들을 우선순위 큐에 삽입한다.

        이후, pq의 top원소와 K를 비교하여, 
        1. K보다 크거나 같으면 그냥 pop하고,
        2. 아니면 mix해야한다. 이때, pop을 한번 더한다. 또 이때, pq가 empty이면, 더 이상
           K이상으로 만들 수 없는 음식이다. 따라서 -1 return한다.

   #. prioity_queue는 정렬 상태를 유지한다. 이를 명심하자.
   #. 문제를 보고 queue가 아닌, priority_queue를 사용해야하는 이유...
      --> 문제에서 scoville지수를 계산 할 때, 가장 최솟값과, 2번째 작은 값을 기반으로 계산하기 때문,
      우선순위 queue는 정렬 상태를 유지한다.

      cf).
      priority_queue<int, vector<int>, greater<int>>  //여기서 greater<int>는 오름차순.
      sort(v.begin(), v.end(), greater<int>())        //여기서 greater<int>()는 내림차순.
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int mix(int food1, int food2)
{
    return food1 + (food2 * 2);
}

/*
void print(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
*/

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    //
    //우선순위 큐를 사용하여, 정렬 상태를 유지한다.
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (!pq.empty())
    {
        //top값 임시저장
        int temp = pq.top();
        //이 값이 K보다 크면 pop
        if (temp >= K)
            pq.pop();
        else
        {
            //우선 pop
            pq.pop();
            //pop했는데, 큐가 비어있다는 것은, K이상인 값으로 만들 수 없다는 의미
            //즉 더이상 mix연산을 진행할 수 없음.
            if (!pq.empty())
            {
                int new_s = mix(temp, pq.top());
                pq.pop();
                answer++;
                pq.push(new_s); //이때, 맨 뒤에 삽입이 아니라, 정렬 상태(오름차순)를 맞춰 삽입된다.
                //print(pq);
            }

            else
                return -1;
        }
    }
    //
    return answer;
}

int main()
{

    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;
    cout << solution(scoville, K) << "\n";
    cout << solution(scoville, 1000000000) << "\n";

    return 0;
}