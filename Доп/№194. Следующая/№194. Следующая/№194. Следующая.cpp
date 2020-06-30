#include <iostream>
using namespace std;

void sort(int* posledov, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (posledov[i] < posledov[i - 1])
		{
			int begin = i - 1;
			while (begin >= 0 && posledov[begin] > posledov[begin + 1])
			{
				swap(posledov[begin], posledov[begin + 1]);
				begin--;
			}
		}
	}
}

void next(int* posledov, int n)
{
	if (n > 1)
	{
		int begin = n - 2;

		while (begin >= 0 && posledov[begin] > posledov[begin + 1])
			begin--;
		if (begin >= 0)
			swap(posledov[begin], posledov[begin + 1 + index_max(posledov + begin + 1, n - begin - 1, posledov[begin])]);

		sort(posledov + begin + 1, n - begin - 1);
	}
}

int index_max(int* posledov, int n, int key)
{
	int next = 0;
	for (int i = 1; i < n; i++)
	{
		if (posledov[i] > posledov[next]) 
		next = i;
	}
	for (int i = 1; i < n; i++)
	{
		if (posledov[i] < posledov[next] && posledov[i]>key) next = i;
	}
	return next;
}


int main()
{
	int n;
	cin >> n;
	int* posledov = new int[n];
	for (int i = 0; i < n; i++)
		cin >> posledov[i];

	next(posledov, n);

	for (int i = 0; i < n;i++)
		cout << posledov[i] << ' ';
}