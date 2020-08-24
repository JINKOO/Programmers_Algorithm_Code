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

bool myCompare(const pair<string, int> &p1, const pair<string, int> &p2)
{
    return p1.second > p2.second;
}

bool myCompare2(const pair<int, pair<string, int>>& p1, const pair<int, pair<string, int>>& p2)
{
    return p1.second.second > p2.second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    //
    map<string, int> genreMap;
    vector<pair<int, pair<string, int>>> musicList;
    vector<pair<string, int>> genreV;

    for (int i = 0; i < genres.size(); i++)
    {
        if (genreMap.find(genres[i]) != genreMap.end())
            genreMap[genres[i]] += plays[i];
        else
            genreMap.insert(make_pair(genres[i], plays[i]));

        musicList.push_back(make_pair(i, make_pair(genres[i], plays[i])));
    }

    //�帣�� plays�� ���� �������� �������� �����ؾ� �Ѵ�.
    //map�� value�������� �����ϱ� ���ؼ��� vector�� ġȯ�ϰ� vector�� �����Ѵ�.
    map<string, int>::iterator it;
    for (it = genreMap.begin(); it != genreMap.end(); it++)
        genreV.push_back(make_pair(it->first, it->second));

    sort(genreV.begin(), genreV.end(), myCompare);

    vector<pair<string, int>>::iterator it2;
    for (it2 = genreV.begin(); it2 != genreV.end(); it2++)
    {
        string genre = it2->first;
        vector<pair<int, pair<string, int>>> musicInGenre;
        for (int i = 0; i < musicList.size(); i++)
        {
            if (genre == musicList[i].second.first)
                musicInGenre.push_back(musicList[i]);
        }

        if (musicInGenre.size() >= 2)
        {
            sort(musicInGenre.begin(), musicInGenre.end(), myCompare2);
            answer.push_back(musicInGenre[0].first);
            answer.push_back(musicInGenre[1].first);
        }

        else if (musicInGenre.size() == 1)
            answer.push_back(musicInGenre[0].first);
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