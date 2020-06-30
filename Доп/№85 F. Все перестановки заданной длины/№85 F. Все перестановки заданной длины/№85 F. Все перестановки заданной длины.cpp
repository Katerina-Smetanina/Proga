#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> posled;

void swapping(int* arr, int n, int k = 0)
{
	if (k == n)
	{
		posled.push_back(0);
		for (int i = 0; i <= n; i++)
		posled[posled.size() - 1] = posled[posled.size() - 1] * 10 + arr[i];
	}
	else
	{
		for (int i = k; i <= n; i++)
		{
			swap(arr[i], arr[k]);
			     swapping(arr, n, k + 1);
			swap(arr[i], arr[k]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n;  i++)
	arr[i] = i + 1;

	swapping(arr, n - 1);
	sort(posled.begin(), posled.end());

	for (int i = 0; i < posled.size(); i++)
	cout << posled[i] << endl;
}