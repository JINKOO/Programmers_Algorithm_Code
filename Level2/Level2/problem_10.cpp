/*
  #. [ ���α׷��ӽ�_ī�� Level 2]
  
  #. Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� 
     �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.
     
     Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, 
     ��ü ī���� ũ��� ������� ���߽��ϴ�.
     
     Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� 
     ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���ѻ���
     - ���� ������ �� brown�� 8 �̻� 5,000 ������ �ڿ����Դϴ�.
     - ����� ������ �� yellow�� 1 �̻� 2,000,000 ������ �ڿ����Դϴ�.
     - ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.
  
  #. ����� ��
     brown	yellow	 return
        10	     2	 [4, 3]
         8	     1	 [3, 3]
        24	    24	 [8, 6]
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
   #. ���� ���� ��.
      - 1. yellow�� ����� ���ϰ�, width >= height�� ������, �ӽ� vector�� ����.
      - 2. �� vector���� brown�� ������ �´� ���� ���̴�.
        brown�� ���� : ((yellow�� width + 2) * 2 + (yellow�� height + 2) * 2) - 4

        B B B B B B
        B Y Y Y Y B
        B B B B B B
      
      - �ѹ��� ����

      2�� �κ��� '���� Ž��' �κ��ε�
*/
vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    //
    vector<pair<int, int>> v;
    //1. yellow�� ��� �Ǻ� == ����, ���� ���� �ľ�.
    int width, height;
    for (int i = 1; i <= yellow; i++)
    {
        width = 0;
        height = 0;
        //1.1����̸�, ���� >= ������ ���vector�� ����.
        if (yellow % i == 0)
        {
            height = i;
            width = yellow / i;
            if (width >= height)
                v.push_back(make_pair(width, height));
            else 
                //(12�� ���(3,4), (4,3))�� �����ϴµ� �� �� �ڿ� ���� �������� ����. 
                break;
        }
    }

    //2. v���� brown�� ������ �´� ��� ã�� answer�� ����.
    for (int i = 0; i < v.size(); i++)
    {
        int yw = v[i].first + 2;
        int yh = v[i].second + 2;
        if (((yw * 2 + yh * 2) - 4) == brown)
        {
            answer.push_back(yw);
            answer.push_back(yh);
            break;
        }
    }
    //
    return answer;
}

void printResult(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << "\n";
}

int main()
{

    printResult(solution(10, 2));
    printResult(solution(8, 1));
    printResult(solution(24, 24));

    return 0;
}