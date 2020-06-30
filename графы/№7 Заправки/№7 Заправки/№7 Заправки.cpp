#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,s = 0,val = 10000;
	cin >> N;
	int f = N - 1;

	vector<int> cost(N);

	for (int i = 0; i < N; i++) 
		cin >> cost[i];

	vector<vector<pair<int, int>>> pairMass(N);
	vector<int> mas(N, val);
    vector<int> mass(N);

	mas[s] = 0;
	vector<bool> check(N);
	int M; cin >> M;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		//n1--; n2--;
		pairMass[n1].push_back(make_pair(n2, cost[n1]));
		pairMass[n2].push_back(make_pair(n1, cost[n2]));
	}

	for (int i = 0; i < N; i++) {
		int v = -1;
		for (int j = 0; j < N; j++) {
			if (!check[j] && (v == -1 || mas[j] < mas[v]))
				v = j;
		}
		if (mas[v] == val) 
			break;

		check[v] = true;

		for (int j = 0; j < pairMass[v].size(); j++) {

			int to = pairMass[v][j].first;
			int len = pairMass[v][j].second;

			if (mas[v] + len < mas[to]) {
				mas[to] = mas[v] + len;
				mass[to] = v;
			}
		}
	}
	if (mas[f] == val)
		cout << -1;
	else 
		cout << mas[f];

}