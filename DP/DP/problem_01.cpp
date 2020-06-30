/*
  #. [ Ÿ�� ��Ĺ� ] - �ڵ��׽�Ʈ ������Kit
  
  #. ���� ����
     �뱸 �޼������� � �� ������ �ֱٿ� ���� ���� Ÿ�� ��Ĺ��� ���� �Ǿ���. 
     Ÿ�� ��Ĺ��� ���簢�� Ÿ���� �ٿ� ���� ���¿��µ�, 
     �� ���� 1�� ���簢�� Ÿ�Ϻ��� �����Ͽ� ��ġ �޹������� ���� ���ó�� ���� ū Ÿ���� ���� ���¿���. 
     Ÿ�� ��Ĺ��� �Ϻθ� �׸��� ������ ����.
     
     �׸����� Ÿ�Ͽ� ���� ���� �� Ÿ���� �� ���� ���̸� ��Ÿ����. 
     Ÿ�� ��Ĺ��� �����ϴ� ���簢�� Ÿ�� �� ���� ���̸� ���� Ÿ�Ϻ��� �����Ͽ� ���ʷ� ������ ������ ����.

     [1, 1, 2, 3, 5, 8, .]
     
     ������ ���� �̷��� Ÿ�ϵ�� �����Ǵ� ū ���簢���� �ѷ��� �ñ�������. 
     ���� ���, ó�� �ټ� ���� Ÿ���� �����ϴ� ���簢��(������ ���������� ǥ���� ���簢��)�� �ѷ��� 26�̴�.
     
     Ÿ���� ���� N�� �־��� ��, N���� Ÿ�Ϸ� ������ ���簢���� �ѷ��� return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

  #. ���� ����
     - N�� 1 �̻� 80 ������ �ڿ����̴�.

  #. ����� ��
     N	  return
     5	      26
     6	      42
*/

#include <iostream>
using namespace std;

typedef long long ll;

ll dp[81];

ll solution(int N)   //N�� ��°�� �ƴ϶� Ÿ���� �����̴�.
{
    ll answer = 0;
    //
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    answer = 2 * (dp[N] + dp[N + 1]); 

    //
    return answer;
}

int main()
{

    int N;
    cin >> N;

    cout << solution(N) << "\n";
}