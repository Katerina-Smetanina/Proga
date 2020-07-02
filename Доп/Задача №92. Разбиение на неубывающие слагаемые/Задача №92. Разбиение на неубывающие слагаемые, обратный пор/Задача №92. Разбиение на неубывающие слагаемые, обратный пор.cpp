#include <iostream>
using namespace std;

int a[100];

void posled(int index, int m, int n) {
	if (n == 0){
		for (int i = 0; i < index;i++) 
			cout << a[i] << ' ' ;

		cout << endl;
	}
	else{
		for (int i = n; i >= m; i--){
			a[index] = i;
			posled(index + 1, i, n - i);
		}
	}
}

int main() {
	int n;
	cin >> n;
	posled(0, 1, n);
}