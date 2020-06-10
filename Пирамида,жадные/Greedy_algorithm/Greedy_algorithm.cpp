#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool* x = new bool[n];
	int* s = new int[n];
	int* f = new int[n];


	if (n <= 1) {
		cout << n;
	}
	else {

		for (int i = 0; i < n; i++) {
			cin >> s[i] >> f[i];
			x[i] = true;
		}

		for (int i = 0; i < n; i++) {
			for (int j = (n - 1); j >= (i + 1); j--) {
				if (f[j] < f[j - 1]) {
					swap(f[j], f[j - 1]);
					swap(s[j], s[j - 1]);
				}
			}
		}

		int count = 1;
		for (int i = 0; i < n; i++) {
			if (x[i]) {
				for (int j = 0; j < n; j++) {
					if (x[j]) {
						if (f[i] <= s[j]) {
							count++;
							break;
						}
						else x[j] = false;
					}
				}
			}
		}

		cout << count;
	}
}
