/*
  #. [ ��ȭ��ȣ ��� ]
  #. ���� ����
     ��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
     ��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

     ������ : 119
     ���ؿ� : 97 674 223
     ������ : 11 9552 4421

     ��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, 
     � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���� ����
     phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
     �� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.

  #. ����� ����
                      phone_book	return
     [119, 97674223, 1195524421]	 false
                   [123,456,789]	  true
            [12,123,1235,567,88]	 false
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    //
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++)
    {
        string key = phone_book[i];
        for (int j = i + 1; j < phone_book.size(); j++)
        {
            if (key == phone_book[j].substr(0, key.size() - 1))
                return false;
        }
    }
    //
    return answer;
}

int main(void)
{
    vector<string> v = { "119", "97674223", "1195524421" };
    
    cout << solution(v) << "\n";
    return 0;
}