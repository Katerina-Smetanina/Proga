#include<iostream>
using namespace std;

void CountingSort(int a[],int n) {
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int* l = new int[max - min + 1];
	for (int i = 0; i < max + 1 - min; i++) {
		l[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		l[a[i] - min] = l[a[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (l[j - min] != 0) {
			a[i] = j;
			cout << j << " ";
			l[j - min]--;
			i++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	CountingSort(a, n);
}