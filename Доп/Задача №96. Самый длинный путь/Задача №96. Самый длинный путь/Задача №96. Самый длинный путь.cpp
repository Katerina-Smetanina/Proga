#include <iostream>
#define INF 1000
using namespace std;

int main() {
	int n;
	cin >> n;

	int** mass = new int* [n];
	for (int i = 0; i < n; i++)
		mass[i] = new int[n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) 
			cin >> mass[i][j];

			if (mass[i][j] < 0)
				mass[i][j] = INF;
	}

	for (int k = 0; k < n; k++) {    // main
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mass[i][j] > mass[i][k] + mass[k][j])
					mass[i][j] = mass[i][k] + mass[k][j];
	}

	int dist = 0;

	for (int i = 0; i < n; i++) {  //print
		for (int j = 0; j < n; j++)
			if (mass[i][j]<INF && mass[i][j]>dist)
				dist = mass[i][j];
	}
	cout << dist;
}