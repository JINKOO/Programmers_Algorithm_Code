/*
  #. [ ��ųƮ�� ]
  #. ���� ����
     ���� ��ų�̶� � ��ų�� ���� ���� ���� ����� �ϴ� ��ų�� ���մϴ�.
     
     ���� ��� ���� ��ų ������ ����ũ �� ����Ʈ�� ��Ʈ �� ����϶�, ����� ������ ���� ����Ʈ�� ��Ʈ�� ����� �ϰ�, 
     ����Ʈ�� ��Ʈ�� ������ ���� ����ũ�� ����� �մϴ�.
     
     �� ������ ���� �ٸ� ��ų(���� ��)�� ������ ������� ��� �� �ֽ��ϴ�.
     ���� ����ũ �� ���� �� ����Ʈ�� ��Ʈ �� ����� ���� ��ųƮ���� ����������, 
     ��� �� ����ũ�� ����Ʈ�� ��Ʈ �� ����ũ �� ���� �� ����� ���� ��ųƮ���� �Ұ����մϴ�.
     
     ���� ��ų ���� skill�� �������� ���� ��ųƮ��1�� ���� �迭 skill_trees�� �Ű������� �־��� ��, 
     ������ ��ųƮ�� ������ return �ϴ� solution �Լ��� �ۼ����ּ���.

  #. ���� ����
     - ��ų�� ���ĺ� �빮�ڷ� ǥ���ϸ�, ��� ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
     - ��ų ������ ��ųƮ���� ���ڿ��� ǥ���մϴ�. ���� ���, C �� B �� D ��� CBD�� ǥ���մϴ�
     - ���� ��ų ���� skill�� ���̴� 1 �̻� 26 �����̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
     - skill_trees�� ���� 1 �̻� 20 ������ �迭�Դϴ�.
     - skill_trees�� ���Ҵ� ��ų�� ��Ÿ���� ���ڿ��Դϴ�.
     - skill_trees�� ���Ҵ� ���̰� 2 �̻� 26 ������ ���ڿ��̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.

  #. ����� ��
     skill	                      skill_trees	return
     "CBD"	["BACDE", "CBADF", "AECB", "BDA"]	     2

  #. ����� �� ����
     - BACDE: B ��ų�� ���� ���� C ��ų�� ���� ����� �մϴ�. �Ұ����� ��ųƮ���ϴ�.
     - CBADF: ������ ��ųƮ���Դϴ�.
     - AECB: ������ ��ųƮ���Դϴ�.
     - BDA: B ��ų�� ���� ���� C ��ų�� ���� ����� �մϴ�. �Ұ����� ��ųƮ���Դϴ�.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(string skill, char c)
{
    for (int i = 0; i < skill.length(); i++)
    {
        if (skill[i] == c)
            return true;
    }
    return false;
}

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    //
    for (int i = 0; i < skill_trees.size(); i++)
    {
        string str = skill_trees[i];
        string temp = "";
        bool flag = true;
        for (int j = 0; j < str.length(); j++)
        {
            if (check(skill, str[j]))
                temp += str[j]; 
        }

        for (int k = 0; k < temp.length(); k++)
        {
            //skill tree������ ������ �߿��ϴ�.
            //������ ���� ������, �ش� ���ڿ��� skill�� �ƴϴ�.
            if (temp[k] != skill[k])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            answer++;
    }
    //
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution("CBD", skill_trees) << "\n";

    return 0;
}