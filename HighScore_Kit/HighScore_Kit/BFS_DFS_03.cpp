/*
  #. [ �ܾ� ��ȯ ]

  #. ���� ����
     �� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. 
     �Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

     1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
     2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
     
     ���� ��� begin�� hit, target�� cog, words�� [hot,dot,dog,lot,log,cog]��� 
     hit -> hot -> dot -> dog -> cog�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.
     
     �� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, 
     �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���ѻ���
     - �� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
     - �� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
     - words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
     - begin�� target�� ���� �ʽ��ϴ�.
     - ��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.

  #. ����� ��
     begin	   target	                         words	return
       hit	     cog	[hot, dot, dog, lot, log, cog]	     4
       hit	     cog	     [hot, dot, dog, lot, log]	     0

  #. ����� �� ����
     - ���� #1
       ������ ���� ���� �����ϴ�.
     
     - ���� #2
       target�� cog�� words �ȿ� ���� ������ ��ȯ�� �� �����ϴ�.
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

int check[50];


int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    //
    
    //
    return answer;
}