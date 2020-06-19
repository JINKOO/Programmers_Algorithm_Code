#include <vector>
#include <string>
#include <iostream>
using namespace std;

void bubbleSort(vector<int> v)
{
	cout << "#. BubbleSort()" << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}

		cout << i + 1 << "회전 :: ";
		for (int e : v)
			cout << e << " ";
		cout << "\n";
	}
}

void insertionSort(vector<int> v)
{
	cout << "#. insertionSort" << "\n";
	for (int i = 1; i < v.size(); i++)
	{
		int key = v[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (key < v[j])
				v[j + 1] = v[j];
			else
				break;
		}
		v[j + 1] = key;

		cout << i + 1 << "회전:: ";
		for (int e : v)
			cout << e << " ";
		cout << "\n";
	}
}

void selectionSort(vector<int> v)
{
	cout << "#. Selection Sort" << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[min] > v[j])
				min = j;
		}

		if (min != i)
		{
			int temp = v[min];
			v[min] = v[i];
			v[i] = temp;
		}
		cout << i + 1 << "회전 :: ";
		for (int e : v)
			cout << e << " ";
		cout << "\n";
	}
}

void merge(vector<int> v, int s, int middle, int end)
{

}

void mergeSort(vector<int> v, int s, int e)
{
	if (s < e)
	{
		int middle = (s + e) / 2;
		mergeSort(v, s, middle);
		mergeSort(v, middle + 1, e);
		merge(v, s, middle, e);
	}
}

int main()
{
	vector<int> v = { 1,5,3,2,0,10 };
	bubbleSort(v);
	insertionSort(v);
	selectionSort(v);
	
	mergeSort(v, 0, v.size() - 1);

	return 0;
}