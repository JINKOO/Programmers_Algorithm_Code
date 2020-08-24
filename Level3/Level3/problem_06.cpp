/*
   #. [ 프로그래머스_야근 지수 Level 3 ]
   
   #. 문제 설명
      회사원 Demi는 가끔은 야근을 하는데요, 야근을 하면 야근 피로도가 쌓입니다. 
      야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값입니다. 
      Demi는 N시간 동안 야근 피로도를 최소화하도록 일할 겁니다. Demi가 1시간 동안 작업량 1만큼을 처리할 수 있다고 할 때, 
      퇴근까지 남은 N 시간과 각 일에 대한 작업량 works에 대해 야근 피로도를 최소화한 값을 리턴하는 함수 solution을 완성해주세요.
      
   #. 제한 사항
      - works는 길이 1 이상, 20,000 이하인 배열입니다.
      - works의 원소는 50000 이하인 자연수입니다.
      - n은 1,000,000 이하인 자연수입니다.
      
   #. 입출력 예
          works	  n	  result
      [4, 3, 3]	  4	      12
      [2, 1, 2]	  1	       6
          [1,1]	  3	       0
          
   #. 입출력 예 설명
      입출력 예 #1
      n=4 일 때, 남은 일의 작업량이 [4, 3, 3] 이라면 야근 지수를 최소화하기 위해 4시간동안 일을 한 결과는 [2, 2, 2]입니다. 
      이 때 야근 지수는 2의2승 + 22 + 22 = 12 입니다.
      
      입출력 예 #2
      n=1일 때, 남은 일의 작업량이 [2,1,2]라면 야근 지수를 최소화하기 위해 1시간동안 일을 한 결과는 [1,1,2]입니다. 
      야근지수는 1의2승 + 12 + 22 = 6입니다.
      
      입출력 예 #3
      n=3일 때, 남은 일의 작업량이 n보다 모두 작으므로 야근 지수는 0입니다.
*/

/*
   #. 풀이법.
      - 우선순위 큐를 사용해야하는지 감이 않왔다....
      - 야근 지수를 최소화 하려면, 가장 많은 작업량이 남은 작업을 최소화 시켜야한다.
      - 우선 순위 큐를 이용한다. 이때 내림차순으로 선언
      - 우선 순위 큐의 top은 항상 max 작업량이고 n이 0이 될 때까지 -1해준다.
      - 이후 정답 도출.

*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) 
{
    long long answer = 0;
    //
    //1. 우선순위 큐 내림차순 방식으로 선언한다.
    priority_queue<int, vector<int>, less<int>> pq;

    //2. 작업량을 pq에 삽입한다. 가장 작업량이 많은 것이 top에 있다.
    for (int i = 0; i < works.size(); i++)
        pq.push(works[i]);

    //3. n=0이 될 때까지 pq의 top()을 꺼내 -1하고 다시 pq에 삽입한다.
    while (n != 0)
    {
        int max = pq.top();
        pq.pop();
        //pq.top()이 0보다 작거나 같으면, 야근 지수는 0이다. 즉 일을 n보다 빨리 끝낸다.
        if (max <= 0)
            break;
        pq.push(max - 1);
        n--;
    }

    while (!pq.empty())
    {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    //
    return answer;
}

int main()
{
    cout << solution(4, {4, 3, 3}) << "\n";
    cout << solution(1, { 2, 1, 2 }) << "\n";
    cout << solution(3, { 1, 1 }) << "\n";
    return 0;
}