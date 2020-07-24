/*
    #. [ ���α׷��ӽ�_���̽�ƽ Level 2 ]
 *  
 *  #. ���� ����
 *     ���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
 *     ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA
 *     ���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.
 *     
 *     �� - ���� ���ĺ�
 *     �� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
 *     �� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
 *     �� - Ŀ���� ���������� �̵�
 *     
 *     ���� ��� �Ʒ��� ������� JAZ�� ���� �� �ֽ��ϴ�.
 *     - ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
 *     - ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
 *     - ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
 *     ���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
 *     
 *     ������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.
 *  
 *  #. ���� ����
 *     - name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
 *     - name�� ���̴� 1 �̻� 20 �����Դϴ�.
 *  
 *  #. ����� ��
 *       name   return
 *     JEROEN	    56
 *        JAN	    23
 *        
 */

/*
   #. Greedy�� ���.
      -->, <--, --><-- �̵� ���� �� �ּڰ��� ã�´�.

*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) 
{
    int answer = 0;
    //
    int min = 0;
    //1. ���� ��ƽ �̵�.
    for (int i = 0; i < name.length(); i++) 
    {
        char c = name[i];
        if (c != 'A') 
        {
            int sub1 = c - 'A';
            int sub2 = 'Z' - c + 1;
            answer += (sub1 < sub2 ? sub1 : sub2);
        }
    }

    //2. �¿� Ŀ�� �̵�.
    min = name.length();
    for (int i = 0; i < name.length(); i++)
    {
        char c = name[i];
        int next = i + 1;
        if (c != 'A')
        {
            while (next < name.length() && name[next] == 'A')
                next++;
            int move = (i * 2) + name.length() - next;
            if (min > move)
                min = move;
        }
    }

    answer += min;
    //
    return answer;
}

int main()
{

    cout << solution("JAZ") << "\n";
    cout << solution("JAN") << "\n";
    cout << solution("AAJAAAZAAA") << "\n";
    cout << solution("JEROEN") << "\n";

    return 0;
}