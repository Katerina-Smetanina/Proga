
#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<map>
#include<set>

#define max 1000000000
using namespace std;

int main() {
	int n, f, s;
	set<pair<int, int>>makePair;
	cin >> n >> s >> f;
	s--; f--;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	vector<int> d(n,max);
	vector <bool> b(n,1);

	for (int i = 0; i < n; i++) {
		d[i] = max;
		b[i] = true;

		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] < 0)
				a[i][j] = max;
		}
	}

	d[s] = 0;
	makePair.insert(make_pair(0, s));

	while (!makePair.empty()) {
		int i = makePair.begin()->second;
		b[i] = false;
		makePair.erase(makePair.begin());
		for (int j = 0; j < n; ++j)
			if (b[j] && d[j] > d[i] + a[i][j]) {
				makePair.erase(make_pair(d[j], j));
				d[j] = d[i] + a[i][j];
				makePair.insert(make_pair(d[j], j));
			}
	}
	if (d[f] < max) {
		cout << d[f];
	}
	else
		cout << -1;
}