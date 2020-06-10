#include <iostream>
using namespace std;



int main()
{
	int n, k, s, tmp;
	cin >> n >> k >> s;
	int* arr = new int[s];

    tmp = k;
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
		if (arr[i] <= k)
			tmp += arr[i];
		else 
			tmp += k;
	}

	if (n <= k)
	{
		cout << 0;
		return 0;
	}
	else if (tmp < n)
	{
		cout << -1;
		return 0;
	}
	else
	{
		tmp = k;
		
        for (int i = 0; i < s; i++)
		  for (int j = (s - 1); j >= (i + 1); j--)
			if (arr[j] > arr[j - 1])
				swap(arr[j - 1], arr[j]);
		
		for (int i = 0; i < s; i++)
		{
			if (tmp >= n)
			{
				cout << i;
				return 0;
			}
				if (arr[i] <= k)
					tmp += arr[i];
				else
					tmp += k;
		}
		cout << s;
	}
}