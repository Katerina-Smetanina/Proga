#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>& temp) {
	vector<vector<int>> tmp(10);

	while (tmp[0].size() != temp.size()) {
		int a = 10, b = 1;

		for (int i = 0; i < 10; i++)
			tmp[i].clear();

		for (int i = 0; i < temp.size(); i++)
			tmp[abs(temp[i]) % a / b].push_back(temp[i]);

		a *= 10; b *= 10;

		int j = 0;
		for (int i = 0; i < 10; i++)
			for (int k = 0; k < tmp[i].size(); k++)
				temp[j++] = tmp[i][k];
	}
}


int main()
{
	vector<int> temp;
	int n;
	int l;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> l;
		temp.push_back(l);
	}

	sort(temp);

	for (int i = 0; i < n; i++)
		cout << temp[i] << ' ';

	return 0;
}