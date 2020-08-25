/*
   #. [ ���α׷��ӽ�_�Ҽ� ã�� Level 2 ]
   
   #. ���� ����
      ���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�. ����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.
      �� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, ���� �������� ���� �� �ִ� �Ҽ��� �� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.
      
   #. ���ѻ���
      - numbers�� ���� 1 �̻� 7 ������ ���ڿ��Դϴ�.
      - numbers�� 0~9���� ���ڸ����� �̷���� �ֽ��ϴ�.
      - 013�� 0, 1, 3 ���ڰ� ���� ���� ������ ������ִٴ� �ǹ��Դϴ�.
      
   #. ����� ��
      numbers	return
           17	     3
          011	     2
          
   #. ����� �� ����
      ���� #1
      [1, 7]���δ� �Ҽ� [7, 17, 71]�� ���� �� �ֽ��ϴ�.
      
      ���� #2
      [0, 1, 1]���δ� �Ҽ� [11, 101]�� ���� �� �ֽ��ϴ�.
      
      11�� 011�� ���� ���ڷ� ����մϴ�.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
    if (n == 0 || n == 1)
        return false;
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_all_contained(int n, string number)
{
    string temp = to_string(n);
    bool check[7] = { false, };
    int count = 0;

    for (int i = 0; i < temp.length(); i++)
    {
        for (int j = 0; j < number.length(); j++)
        {
            if (temp[i] == number[j] && !check[j])
            {
                check[j] = true;
                count++;
                break;
            }
        }
    }

    return count == temp.length() ? true : false;
}

int solution(string numbers) 
{
    int answer = 0;
    //
    sort(numbers.begin(), numbers.end(), greater<char>());
    int max_num = stoi(numbers);

    int n = max_num;
    while (n != 0)
    {
        if (is_prime(n) && is_all_contained(n, numbers))
            answer++;
        n--;
    }
    //
    return answer;
}

int main()
{
    cout << solution("17") << "\n";
    cout << solution("011") << "\n";

    return 0;
}