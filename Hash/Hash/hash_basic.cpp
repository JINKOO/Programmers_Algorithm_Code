#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
using namespace stdext;
using namespace std;

int main()
{
	unordered_map<string, string> hash1;
	unordered_multimap<string, string> hash2;

	//insert
	hash1.insert(unordered_map<string, string>::value_type("Elite", "NIKE"));
	hash1.insert(unordered_map<string, string>::value_type("Men", "GUESS"));
	hash1.insert(hash1.begin(), unordered_map<string, string>::value_type("Kids", "Adiddas"));
	hash2.insert(hash1.begin(), hash1.end());
	
	//중복 허용 X
	hash1.insert(unordered_map<string, string>::value_type("Men", "New Balance"));
	
	//순회
	unordered_map<string, string>::iterator iter1;
	for (iter1 = hash1.begin(); iter1 != hash1.end(); iter1++)
		cout << iter1->first << " " << iter1->second << "\n";

	//search Using KEY
	//1. value값을 변경 가능 
	//2. value값을 변경 불가능 (함수 리턴 타입 const)
	//3. Key값은 변경 불가
	unordered_map<string, string>::iterator iter2 = hash2.find("Men");
	if (iter2 != hash2.end()) //찾았다면 실행 된다.
		iter2->second = "PUMA"; //Value의 값 변경.

	//Key 중복 허용
	hash2.insert(unordered_multimap<string, string>::value_type("Men", "New Balance"));

	unordered_map<string, string>::iterator iter3;
	for (iter3 = hash2.begin(); iter3 != hash2.end(); iter3++)
		cout << iter3->first << " " << iter3->second << "\n";

	cout << "============================" << "\n";
	map<string, int> map1;
	map1.insert(make_pair("for", 3));
	map1["each"] = 5;
	cout << map1.size() << "\n";
	cout << map1["for"] << "\n";
	cout << map1["each"] << "\n";
	return 0;
}