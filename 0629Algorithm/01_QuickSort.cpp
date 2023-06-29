/*
	Big O ǥ���
	O(1), O(logn), O(n), O(nlogn), O(n^2), O(2^n), O(n!)
	
	�Ǻ��� ���� ����, ���� �߾� ���� �ϳ��� ���Ѵ�.

	L�� R�̶�� �Ͽ�, ���� ���� �����ʰ��� �����Ѵ�.
	
	�Ǻ��� L�� R�� ���Ͽ� ���������� ū�� Ȯ���ϰ�
	
	�� ���������� �̵��Ѵ�.
	�׷��ٰ� �� ū���� �����ʰ� �̵��Ѵ�.

*/

#include <iostream>

using namespace std;

void QuickSort(int* arr, int start, int end)
{
	if(start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while(arr[left] < arr[pivot] && left <= end)
			left++; // ������ �̵���Ų��.
		while (arr[right] > arr[pivot] && right >= start)
			right--; // ������ �̵���Ų��.

		if(left >= right) break;

		swap(arr[left], arr[right]);
	}
	swap(arr[pivot], arr[right]);
	
	QuickSort(arr, start, right - 1);
	QuickSort(arr, right + 1, end);

}

void Print(int* arr, int size, string str)
{
	cout << str << endl;
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

}

int main()
{
	int arr[10];
	
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	Print(arr, 10, "PREV : ");
	QuickSort(arr, 0, 9);
	Print(arr, 10, "NEXT : ");
	return 0;
}

// ������ �Ǻ����� ����� ����� ��� �� �����ؿ���.