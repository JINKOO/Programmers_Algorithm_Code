/*
  #. [ ���α׷��ӽ�_�Ҽ� ã�� Level 2 ]
  #. ���� ����
     ���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�. ����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.
     �� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, ���� �������� ���� �� �ִ� �Ҽ��� �� ������ 
     return �ϵ��� solution �Լ��� �ϼ����ּ���.

  #. ���ѻ���
     - numbers�� ���� 1 �̻� 7 ������ ���ڿ��Դϴ�.
     - numbers�� 0~9���� ���ڸ����� �̷���� �ֽ��ϴ�.
     - 013�� 0, 1, 3 ���ڰ� ���� ���� ������ ������ִٴ� �ǹ��Դϴ�.
 
  #. ����� ��
     numbers	return
          17	     3
         011         2

  #. ����� �� ����
     - ���� #1
       [1, 7]���δ� �Ҽ� [7, 17, 71]�� ���� �� �ֽ��ϴ�.

     - ���� #2
       [0, 1, 1]���δ� �Ҽ� [11, 101]�� ���� �� �ֽ��ϴ�.
       11�� 011�� ���� ���ڷ� ����մϴ�.
*/

/*
  #. ���� ���ٹ�.
     - numbers���ڿ��� �ϳ��� �ɰ��� ��� ����� ���� ���Ͽ� ������ ��ȯ ��,
       vector<int>�� �־ �Ҽ����� �Ǻ��Ϸ��� ��. --> ����.

  #. Ǯ��
     - '���� Ž��' �����̴�. ���� Ž���� ��� �κп� �����ų ������.
     - �켱 numbers�� �ִ� ���ڹ��ڷ� ���� �� �ִ� �ִ� ������ �����,
       1. 2 ~ max���� �ݺ��ϸ鼭,
       2. �Ҽ����� �Ǻ��ϰ�,
       3. �ش� �Ҽ��� ���� numbers�� ���Ե� �������� �Ǻ��Ѵ�.

       ==> 1 ~ 3 �κ��� ����Ž��..
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//�Ҽ� �Ǻ��� �־ ���� ���� ����̴�.
//�����佺�׳׽��� ü���� ���� ��..??
bool isPrime(int n)
{
    if (n == 0)
        return false;
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool contain(string numbers, int n)
{
    string s = to_string(n);
    //1. count�� s�� length()�� ���ٴ� �ǹ� = �ش� �Ҽ��� n�� numbers�� ��� ���ԵǾ��ִ�.
    int count = 0;

    //2. numbers�� s�� �� index�� ���ϴµ�, ���� �ڸ����� �Ǵ��ϱ� ���Ͽ�, 
    vector<bool> check(numbers.length(), false);

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < numbers.length(); j++)
        {
            if (s[i] == numbers[j] && check[j] == false)
            {
                check[j] = true;
                count++;
                // break�� �Ŵ� ���� : �ϴ� ���� �� ã���� break�����ν�, 
                // 11�� ���� n�� �Ѿ���� ��, �տ� 1�� �ڿ� 1�� ���ÿ� count�Ǵ� ���� ���´�. 
                break;
            }
        }
    }
    //3. count�� s�� length()�� ���ٴ� �ǹ� = �ش� �Ҽ��� n�� numbers�� ��� ���ԵǾ��ִ�.
    return count == s.length() ? true : false;
}

bool myCompare(char c1, char c2) 
{
    return c1 > c2;
}

int solution(string numbers) {
    int answer = 0;
    //
    //1. numbers���� ���� �ִ��� ã�´�.
    int max = 0;
    //1.1 �ִ��� ���� ã�� ���� �������� �����Ѵ�.
    sort(numbers.begin(), numbers.end(), myCompare);
    max = stoi(numbers);

    //2. 2 ~ max���� �Ҽ� ã��, �� �Ҽ��� ���� numbers�� ����ֳ� check�Ѵ�.
    for (int i = 2; i <= max; i++)
    {
        //2.2 �Ҽ��̸�,
        if (isPrime(i))
        {
            //2.3 �ش� �Ҽ���, numbers�� ���ԵǾ��ִ� �������� check�Ѵ�.
            if (contain(numbers, i))
                answer++;
        }
    }
    //
    return answer;
}

int main()
{
    cout << solution("17") << "\n";
    cout << solution("011") << "\n";
    cout << solution("012342") << "\n";

    return 0;
}