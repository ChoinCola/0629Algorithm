#include<iostream>

class Map
{
	int* arr;
	int size_X;
	int size_Y;

	int count;
public:
	Map(int* arr, int size_X, int size_Y) : size_X(size_X), size_Y(size_Y)
	{
		this->arr = new int[size_X* size_Y];

		for (int i = 0; i < size_X * size_Y; i++) {
			this->arr[i] = arr[i];
		}

		count = 0;
	}

	auto DFS(int X, int Y) -> bool
	{
		if ( X >= size_X || Y >= size_Y || Y < 0 || X < 0 || arr[X + (Y * size_X)] == true) // 범위제한
			return false;

		arr[X + (Y * size_X)] = 2;

		if (arr[X + (Y * size_X) + 1] == false) // 오른쪽이 0 일경우
			DFS(X + 1, Y);
		if (arr[X + (Y * size_X) - size_X] == false) // 위가 0 일경우
			DFS(X, Y - 1);
		if (arr[X + (Y * size_X) + size_X] == false) // 아래가 0 일경우
			DFS(X, Y + 1);


		return true;
	}

	auto Searching() -> void
	{
		for (int i = 0; i < size_Y; i++)
			for (int j = 0; j < size_X; j++)
			{
				if(arr[j + (i*size_X)] == 0) count += DFS(j, i);
			}
		std::cout << "값 : " << count << std::endl;
	}
	auto Print_ALL() -> void
	{
		std::cout << "배열\n";
		for (int i = 0; i < size_Y; i++) {
			for (int j = 0; j < size_X; j++) {
				std::cout << arr[j + (i * size_X)] << " ";
			}
			std::cout << std::endl;
		}

	}
};

int main()
{
	int arr[5][5] = {   0, 0, 0, 1, 1,
						0, 0, 1, 0, 0,
						1, 1, 1, 1, 0,
						0, 0, 1, 1, 1,
						1, 1, 1, 0, 1 };

	Map map(arr[0],5,5);

	map.Print_ALL();
	map.Searching();
	return 0;
}