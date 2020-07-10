/*
  #. [ ���α׷��ӽ�_���� ū �� ]
  #. ���� ����
     0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.
     ���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.

     0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

  #. ���� ����
     - numbers�� ���̴� 1 �̻� 100,000 �����Դϴ�.
     - numbers�� ���Ҵ� 0 �̻� 1,000 �����Դϴ�.
       ������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.
       
  #. ����� ��
               numbers	     return
            [6, 10, 2]	       6210
     [3, 30, 34, 5, 9]	    9534330
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//�񱳱����� ������ ���� ���� �� �� �� �ִ�..
bool myCompare(const string& s1, const string& s2)
{
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    //

    //1. ���ڿ��� ��ȯ�Ͽ� vector�� ����.
    vector<string> v;
    for (int i : numbers)
        v.push_back(to_string(i));

    //2. �������� ����
    sort(v.begin(), v.end(), myCompare);
   
    for (string s : v)
        answer += s;

    //���ڸ��� 0�ΰ�� ó���ؾ��Ѵ�.
    if (answer[0] == '0')
        answer = "0";
    //
    return answer;
}

int main()
{
    cout << solution({ 6, 10, 2 }) << "\n";
    cout << solution({ 3, 30, 34, 5, 9 }) << "\n";
    cout << solution({ 0, 0, 0}) << "\n";

    return 0;
}