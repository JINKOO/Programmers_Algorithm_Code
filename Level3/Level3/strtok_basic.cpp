#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/*
    #. C++���� ���ڿ� �ɰ��� Java�� StringTokenizeró��..
	   - strtok_s(char* str, " ")�� ����Ѵ�.
	   - strtok�� ���� ���ڸ� ã����, �ش� �ڸ��� nullptr�� �����Ѵ�.
	     ����, nullptr���� �ڸ����� �ٽ� ���й��ڱ����� ���ڿ��� �����͸� ��ȯ�Ѵ�.


*/
string solution(string str)
{
	string answer = "";
	//
	vector<int> v;

	//1. string�� char*�� ��ȯ�ؾ��Ѵ�. null���ڸ� �����Ͽ� �����Ҵ��Ѵ�.
	char* c = new char[str.length() + 1];
	//2. �׳� c_str()�� ����ϸ� �ȵǰ�, ������ ���� ���� ���� �� ���.
	strcpy_s(c, str.length() + 1,str.c_str());

	//3. context�� �ɰ��� ���� ���ڿ��� �ּ�
	char* context = nullptr;
	char* ptr = strtok_s(c, " ", &context);
	while (ptr != nullptr)
	{
		//c_str�� �ٽ� string������ ��ȯ.
		string str = ptr;
		v.push_back(stoi(str));
		ptr = strtok_s(nullptr, " ", &context);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	//
	return answer;
}

int main()
{

	cout << solution("-4 -3 -2 -1") << "\n";

	return 0;
}