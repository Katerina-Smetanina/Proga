// pyramid.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& heap, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && heap[l] > heap[largest])
		largest = l;

	if (r < n && heap[r] > heap[largest])
		largest = r;

	if (largest != i)
	{
		swap(heap[i], heap[largest]);
		heapify(heap, n, largest);
	}
}

void sort_heap(vector<int>& heap, int n) {

	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(heap, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(heap[0], heap[i]);
		heapify(heap, i, 0);
	}

}


int main()
{
	vector<int> heap;
	int n,a;
	cin >> n;
	 
	for (int i = 0; i < n; i++) {
		cin >> a;
		heap.push_back(a);
	}

	sort_heap(heap, n);

	for (int i = 0; i < n; i++)
		cout << heap[i] << " ";


}

