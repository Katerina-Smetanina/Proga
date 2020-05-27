// C++ program to sort an array using bucket sort 
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

int firstDigit(vector<int> arr,int i)
{
	int bi;
	do
	{
		bi = arr[i];
		arr[i] /= 10;
	} while (arr[i]);
	return bi;
}

// Function to sort arr[] of size n using bucket sort 
void bucketSort(vector<int>& arr, int n){
	int bucket = (n + 1) / 2;
	vector<vector<int>> b(bucket);

	int min = arr[0];
	int max = arr[0];
	float del;

	for (int i = 0; i < n; i++) {
		if (min > arr[i])
			min = arr[i];
		else if (max < arr[i])
			max = arr[i];
	}
	int range = max - min;
	del = (max - min) / (bucket);

	 
	 for (int i = 0; i < n; i++) {
		int index = -1;
		index = (int)((arr[i] - min) / del);
		b[index >= bucket ? bucket - 1 : index].push_back(arr[i]);
	}

	/*for (int i = 0; i < n; i++){
 		int bi = (firstDigit(arr,i));
		b[bi].push_back(arr[i]);
	}*/

	
	for (int i = 0; i < bucket; i++)
		sort(b[i].begin(), b[i].end());

	
	for (int i = 0, index = 0; i < bucket; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

/* Driver program to test above funtion */
int main()
{
	int n;
	int l;
	cin >> n; 
	vector<int> arr;
	 
	for (int i = 0; i < n; i++) {
		cin >> l;
		arr.push_back(l);
	}
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
