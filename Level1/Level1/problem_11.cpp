/*
  #. [���ڿ� �� ������� �����ϱ�]
  
  #. ���� ����
     ���ڿ��� ������ ����Ʈ strings��, ���� n�� �־����� ��, 
     �� ���ڿ��� �ε��� n��° ���ڸ� �������� �������� �����Ϸ� �մϴ�. 
     ���� ��� strings�� [sun, bed, car]�̰� n�� 1�̸� �� �ܾ��� �ε��� 1�� ���� u, e, a�� strings�� �����մϴ�.

  #. ���� ����
     strings�� ���� 1 �̻�, 50������ �迭�Դϴ�.
     strings�� ���Ҵ� �ҹ��� ���ĺ����� �̷���� �ֽ��ϴ�.
     strings�� ���Ҵ� ���� 1 �̻�, 100������ ���ڿ��Դϴ�.
     ��� strings�� ������ ���̴� n���� Ů�ϴ�.
     �ε��� 1�� ���ڰ� ���� ���ڿ��� ���� �� ���, ���������� �ռ� ���ڿ��� ���ʿ� ��ġ�մϴ�.
  
  #. ����� ��
     strings	        n	  return
     [sun, bed, car]	1	  [car, bed, sun]
     [abce, abcd, cdx]	2	  [abcd, abce, cdx]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool mySort(string a, string b, int n)
{
    if (a.at(n) != b.at(n))
        return a.at(n) < b.at(n);
    else
        return a < b;
}

void printResult(vector<string> r)
{
    for (vector<string>::iterator iter = r.begin(); iter != r.end(); iter++)
        cout << *iter << " ";
    cout << "\n";
}

vector<string> solution(vector<string> strings, int n) {
    
    vector<string> answer;
    //
    /*answer = strings;
    sort(answer.begin(), answer.end(), mySort);*/

    for (int i = 0; i < strings.size(); i++)
    {
        for (int j = i + 1; j < strings.size(); j++)
        {
            if (strings[j][n] < strings[i][n])
            {
                string temp;
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }

            if (strings[j][n] == strings[i][n])
            {
                string temp;
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
    answer = strings;

    //
    return answer;
}

int main()
{
    vector<string> s = { "sun", "bed", "car" };
    vector<string> s2 = {"abce", "abcd", "cdx"};
    
    printResult(solution(s, 1));
    printResult(solution(s2, 2));

    return 0;
}







