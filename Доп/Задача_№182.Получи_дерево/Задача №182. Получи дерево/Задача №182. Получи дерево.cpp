#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> mass(n - 1);
	vector<int> color(n);
	vector<vector<int>> table(n, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		table[a][b] = 1;
	}

	for (int i = 0; i < n; i++)
		color[i] = i;
	for (int i = 0; i < n - 1; i++)
		mass[i] = make_pair(-1, -1);

	for (int k = 0; k < n - 1; k++){
		int max, i_col, j_col;
		max = INT32_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (table[i][j] != 0 && color[i] != color[j] && table[i][j] < max)
				{
					max = table[i][j];
					mass[k].first = i;
					mass[k].second = j;
					i_col = color[i];
					j_col = color[j];
				}
			}
		}
		if (mass[k].first > mass[k].second)
			swap(mass[k].first, mass[k].second);
		for (int i = 0; i < n; i++)
			if (color[i] == j_col) 
				color[i] = i_col;
	}
	for (int i = 0; i < n - 1; cout << mass[i].first + 1 << ' ' << mass[i].second + 1 << endl, i++);
}