/*
   #. [ ���α׷��ӽ�_����Ʈ �ٹ� Level 3 ]

   #. ���� ����
      ��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�. 
      �뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.
      
      ���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
      �帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
      �帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
      
      �뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, 
      ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
      
   #. ���ѻ���
      - genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
      - plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
      - genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
      - �帣 ������ 100�� �̸��Դϴ�.
      - �帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
      - ��� �帣�� ����� Ƚ���� �ٸ��ϴ�.
      
   #. ����� ��
                                     genres	                     plays	      return
      [classic, pop, classic, classic, pop]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]

   #. ����� �� ����
      classic �帣�� 1,450ȸ ����Ǿ�����, classic �뷡�� ������ �����ϴ�.
      ���� ��ȣ 3: 800ȸ ���
      ���� ��ȣ 0: 500ȸ ���
      ���� ��ȣ 2: 150ȸ ���
      
      pop �帣�� 3,100ȸ ����Ǿ�����, pop �뷡�� ������ �����ϴ�.
      ���� ��ȣ 4: 2,500ȸ ���
      ���� ��ȣ 1: 600ȸ ���
      ���� pop �帣�� [4, 1]�� �뷡�� ����, classic �帣�� [3, 0]�� �뷡�� �״����� �����մϴ�.
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