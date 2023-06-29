#include <iostream>

using namespace std;

auto SWAP(int& a, int& b) -> void
{
	int def;
	def = a;
	a = b;
	b = def;
}

auto PRINT(int arr[], int size, string str) -> void
{
	cout << str;

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;
}

auto QuickSort(int arr[], int start, int end) -> void
{
	if (start >= end) return;

	int cstart = start;
	int cend = end;
	int& Pivot = arr[(end + start) / 2];

	while (start <= end)
	{
		while (arr[start] < Pivot && start <= end)
			start++; // 작으면 이동시킨다.
		while (arr[end] > Pivot && end >= start)
			end--; // 크면 이동시킨다.

		if (start >= end) break;

		SWAP(arr[start], arr[end]);
	}
	SWAP(Pivot, arr[end]);

	QuickSort(arr, cstart, Pivot-1);
	QuickSort(arr, Pivot+1, cend );
}

int main()
{
	int arr[10] = { 9,5,6,8,3,2,4,7,1,0 }; // 정렬 전 배열
	PRINT(arr, 10, "정렬 전 : ");
	QuickSort(arr, 0, 9);
	PRINT(arr,10,"정렬 후 : ");
	return 0;
}