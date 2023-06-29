/*
	Big O 표기법
	O(1), O(logn), O(n), O(nlogn), O(n^2), O(2^n), O(n!)
	
	피봇을 가장 좌측, 가장 중앙 둘중 하나로 정한다.

	L과 R이라고 하여, 왼쪽 가장 오른쪽값을 결정한다.
	
	피봇이 L과 R을 비교하여 가장작은지 큰지 확인하고
	
	더 작은쪽으로 이동한다.
	그러다가 더 큰쪽을 작은쪽과 이동한다.

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
			left++; // 작으면 이동시킨다.
		while (arr[right] > arr[pivot] && right >= start)
			right--; // 작으면 이동시킨다.

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

// 과제는 피봇값을 가운데로 잡았을 경우 로 제작해오기.