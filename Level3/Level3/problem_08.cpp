/*
   #. [ ���α׷��ӽ�_�ܾ� ��ȯ Level 3 ]
   
   #. ���� ����
      �� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. 
      �Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.
      
      1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
      2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
      
      ���� ��� begin�� hit, target�� cog, words�� [hot,dot,dog,lot,log,cog]��� 
      hit -> hot -> dot -> dog -> cog�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.
      
      �� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
      
   #. ���ѻ���
      - �� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
      - �� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
      - words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
      - begin�� target�� ���� �ʽ��ϴ�.
      - ��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.
      
   #. ����� ��
      begin	target	                         words	return
        hit	   cog	[hot, dot, dog, lot, log, cog]	     4
        hit	   cog	     [hot, dot, dog, lot, log]	     0
        
   #. ����� �� ����
      ���� #1
      ������ ���� ���� �����ϴ�.
      ���� #2
      target�� cog�� words �ȿ� ���� ������ ��ȯ�� �� �����ϴ�.
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool check[50];

bool is_one_diff(string &str1, string &str2)
{
    int count = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            count++;
    }
    return count == 1 ? true : false;
}

int bfs(string begin, string target, vector<string> words)
{
    //1. int���� ���� �ܾ �� ��° ��ȯ���� ����ϴ� ����.
    queue <pair<int, string>> q;

    q.push(make_pair(0, begin));
    
    while (!q.empty())
    {
        pair<int, string> p = q.front();
        int curr_rec = p.first;
        string curr_str = p.second;
        q.pop();

        if (curr_str == target)
            return curr_rec;

        for (int i = 0; i < words.size(); i++)
        {
            //���� �ܾ�� ���� �ϳ��� �ٸ���, ���� �湮���� ���� �ܾ��̸�,
            if (is_one_diff(curr_str, words[i]) && !check[i])
            {
                //�湮ó���ϰ�
                check[i] = true;
                //ť�� �����ϴµ�, ��ȯ ���� 1������Ű�� �����Ѵ�.
                q.push(make_pair(curr_rec + 1, words[i]));
            }
        }
    }
    //target�ܾ ���� �� ������ return 0
    return 0;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    //
    answer = bfs(begin, target, words);
    //
    return answer;
}

int main()
{

    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << "\n";
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log"}) << "\n";

    return 0;
}