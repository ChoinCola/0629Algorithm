#include <iostream>
#include <list>

using namespace std;

// 무식하게 탐색한다.
// 완전탐색 알고리즘.
// 모든 경우의 수를 전부 탐색한다.
// 백트래킹 = 의미없는 경우는 제외하고 전부 탐색한다.
// 진행하는게 의미없는 조건을 찾아야 한다.

// 제외해줘야 하기 때문에 처리 자체가 불가능 해질 수 있다.

/*
	10개의 숫자가 있다.
	7 15 21 8 14 25 10 11 17 5

	이 중 숫자가 딱 100이 되는 8개의 숫자 찾기
	예외처리 해주면서,
	어떻게 해줘야 최대한 이 반복문을 줄일 수 있는지 생각해보기.

	의미 없는 경우
	
	배열은 먼저 sort한 뒤, 작은숫자대로 더한다.
	그러나 남은 덧셈 수가 남아있는수 보다 작을 경우 의미가 없기 때문에 전 수는 빼낸다.
	빼낸 뒤 나머지를 덧셈 해준다.

	왼쪽부터 오른쪽까지 다 계산해야한다.

	왼쪽부터 다 더하면서 가다가 결과가 안나왔을 시 전 것을 빼고 바로 다음꺼를 더해서 계산

	순방향 정렬을 한 뒤 완전탐색을 시도하였을 경우,
	임의의 모든 값을 순환시키는것 보다 약 O^n/2 만큼 더 줄어들 수 있다.

*/

auto Chack_dup(int arr[] ,int size ,int a) -> bool
{
	for (int i = 0; i < size; i++)
		if (arr[i] == a) return false;
	return true;
}

auto Array_Sum(int arr[], int size) -> int
{
	int result = 0;
	for (int i = 0; i < size; i++) result += arr[i];
	return result;
}

auto PRINT(int arr[], int size, string str) -> void
{
	cout << str;

	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) cout << arr[i] << " ";
	}

	cout << "\tSUM : " << Array_Sum(arr, size) << endl;
}

auto BruteForce(int arr[], int start, int end, int count = 0) -> bool
{
	static int result[8] = { 0 };
	static int stic_i = 0;

	// 10^10 차원의 8개의 점으로 이루어진 선 한줄을 찾아야한다.
	for (int i = start; i <= end; i++) { // 10^10차원을 제귀를 통해 전개한다.
		if (count == 8) break; // count == 8 이 됨은, 들어간 배열이 가득 찼다는 의미이다. 그럼으로 전개된 차원을 탈출
		if (Chack_dup(result, 8, arr[i])) { // 중복값을 체크하여, 현재값에 진입해 있는지 확인한다.
			result[count] = arr[i]; // 현재 차원위치에 지정된 값을 삽입해준다.
			BruteForce(arr, start + 1, end, count + 1); // 재귀를 사용하여 다음 차원위치로 이동해준다.
		}
	}

	int Asum = Array_Sum(result, 8); // 현재 결과에 있는 모든 데이터를 더해준다.

	if (Asum == 100) { // 모든 데이터를 더했을 때 100이 나올경우,
		PRINT(result, 8, "RESULT : "); exit(0); // 결과를 출력

		if (start >= end) { return 0; }
		// start가 end보다 크거나 같을경우, 10^10 차원순환이 전부 완료되었을 경우, 
		// 순환완료한 재귀의 기입된 배열데이터는 의미가 없어지기 때문에 0을 반환하고 종료해준다.
		else if (Asum != 100 && count == 8) {
			// Asum 이 100이 아니고 count가 8일경우, 위의 if문에 해당이 안되기 때문에 차원순환이 전부 종료되지 않아
			// 남은 차원을 전부 순환시켜주어야 한다.
			result[count] = 0; // 현재 가득 찬 배열은 100을 만들어내지 못함으로 0으로 초기화시켜준다.
			BruteForce(arr, start + 1, end, count - 1);
			// 현재 남은 배열을 전부 순환시켜주기 위해 count를 1 줄여 마지막 값을 다음으로 넘길 수 있게 하고,
			// 다음 배열위치로 넘겨준다.
		}

		return 0;
	}
}

int main()
{
	int arr[] = { 7, 15, 21, 8, 14, 25, 10, 11, 17, 5 };
	BruteForce(arr,0, 9);
	return 0;
}