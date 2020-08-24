#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/*
    #. C++에서 문자열 쪼개기 Java의 StringTokenizer처럼..
	   - strtok_s(char* str, " ")를 사용한다.
	   - strtok는 구분 문자를 찾으면, 해당 자리에 nullptr을 삽입한다.
	     이후, nullptr다음 자리부터 다시 구분문자까지의 문자열의 포인터를 반환한다.


*/
string solution(string str)
{
	string answer = "";
	//
	vector<int> v;

	//1. string을 char*로 변환해야한다. null문자를 포함하여 동적할당한다.
	char* c = new char[str.length() + 1];
	//2. 그냥 c_str()을 사용하면 안되고, 다음과 같이 원본 복사 후 사용.
	strcpy_s(c, str.length() + 1,str.c_str());

	//3. context는 쪼개고 남은 문자열의 주소
	char* context = nullptr;
	char* ptr = strtok_s(c, " ", &context);
	while (ptr != nullptr)
	{
		//c_str을 다시 string형으로 변환.
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