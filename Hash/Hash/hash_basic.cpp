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
	
	//�ߺ� ��� X
	hash1.insert(unordered_map<string, string>::value_type("Men", "New Balance"));
	
	//��ȸ
	unordered_map<string, string>::iterator iter1;
	for (iter1 = hash1.begin(); iter1 != hash1.end(); iter1++)
		cout << iter1->first << " " << iter1->second << "\n";

	//search Using KEY
	//1. value���� ���� ���� 
	//2. value���� ���� �Ұ��� (�Լ� ���� Ÿ�� const)
	//3. Key���� ���� �Ұ�
	unordered_map<string, string>::iterator iter2 = hash2.find("Men");
	if (iter2 != hash2.end()) //ã�Ҵٸ� ���� �ȴ�.
		iter2->second = "PUMA"; //Value�� �� ����.

	//Key �ߺ� ���
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