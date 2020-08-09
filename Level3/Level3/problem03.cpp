/*
   #. [ 프로그래머스_베스트 앨범 Level 3 ]

   #. 문제 설명
      스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 
      노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
      
      속한 노래가 많이 재생된 장르를 먼저 수록합니다.
      장르 내에서 많이 재생된 노래를 먼저 수록합니다.
      장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
      
      노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 
      베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.
      
   #. 제한사항
      - genres[i]는 고유번호가 i인 노래의 장르입니다.
      - plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
      - genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
      - 장르 종류는 100개 미만입니다.
      - 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
      - 모든 장르는 재생된 횟수가 다릅니다.
      
   #. 입출력 예
                                     genres	                     plays	      return
      [classic, pop, classic, classic, pop]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]

   #. 입출력 예 설명
      classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.
      고유 번호 3: 800회 재생
      고유 번호 0: 500회 재생
      고유 번호 2: 150회 재생
      
      pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.
      고유 번호 4: 2,500회 재생
      고유 번호 1: 600회 재생
      따라서 pop 장르의 [4, 1]번 노래를 먼저, classic 장르의 [3, 0]번 노래를 그다음에 수록합니다.
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Music
{
public:
    int index;
    string genre;
    int plays;

    Music(int index, string genre, int plays)
    {
        this->index = index;
        this->genre = genre;
        this->plays = plays;
    }
};

bool myCompare(const pair<string, int> &p1, const pair<string, int> &p2)
{
    return p1.second > p2.second;
}

bool myCompare2(const Music* m1, const Music* m2)
{
    return m1->plays > m2->plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    //

    map<string, int> genres_map;
    vector<pair<string, int>> sorted_v;
    vector<Music*> music_v;

    for (int i = 0; i < genres.size(); i++)
    {
        if (genres_map.find(genres[i]) != genres_map.end())
            genres_map[genres[i]] += plays[i];
        else
            genres_map.insert(make_pair(genres[i], plays[i]));

        music_v.push_back(new Music(i, genres[i], plays[i]));
    }

    map<string, int>::iterator iter;

    for (iter = genres_map.begin(); iter != genres_map.end(); iter++)
        sorted_v.push_back(make_pair(iter->first, iter->second));

    sort(sorted_v.begin(), sorted_v.end(), myCompare);
  
    vector<pair<string, int>>::iterator iter2;
    for (iter2 = sorted_v.begin(); iter2 != sorted_v.end(); iter2++)
    {
        string genre_key = iter2->first;
        vector<Music*> temp_v;
        for (int i = 0; i < music_v.size(); i++)
        {
            if (genre_key == music_v[i]->genre)
                temp_v.push_back(music_v[i]);
        }

        if (temp_v.size() >= 2)
        {
            sort(temp_v.begin(), temp_v.end(), myCompare2);
            answer.push_back(temp_v[0]->index);
            answer.push_back(temp_v[1]->index);
        }
        else if (temp_v.size() == 1)
            answer.push_back(temp_v[0]->index);
    }
    //
    return answer;
}

void printResult(vector<int> answer)
{
    for (int i : answer)
        cout << i << " ";
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    printResult(solution(genres, plays));
    
    return 0;
}