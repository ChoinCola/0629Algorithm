#include <iostream>
#include <Windows.h>

using namespace std;

class Interface
{
public:
	virtual void Create_Map(int[], int ,int) = 0;
	virtual void Search_Map(int, int) = 0;
	virtual void APrint_Map() = 0;
};


class Point
{
public:
	int x;
	int y;

	int now;
	bool visited;

	Point() : visited(false) {}
	~Point() { delete this; }
};

class WordMap : public Interface
{
	int Width; // 가로
	int Length; // 세로

	int Count_Road;
	Point* Map;

public:

	WordMap() : Count_Road(0) {};

	auto Chack_Move(const int StartX,	const int StartY,
					const int MoveX,	const int MoveY	) -> bool
	{
		if (Map[(StartX + MoveX) + ((StartY + MoveY) * Width)].now == 1 &&
			Map[(StartX + MoveX) + ((StartY + MoveY) * Width)].visited == 0 &&
			(StartX + MoveX) < Width	&& (StartX + MoveX) >= 0 &&
			(StartY + MoveY) < Length	&& (StartY + MoveY) >= 0) {
			return true;
		}
		return false;
	}

	void Create_Map(int map[], const int Width, const int Length) override {
		this->Width = Width;
		this->Length = Length;

		Map = new Point[Width * Length];

		for (int i = 0; i < Length; i++) {
			for (int j = 0; j < Width; j++) {
				Map[j + (i*Width)].now = map[j + (i * Width)];
				Map->x = i;
				Map->y = j;
			}
		}
	}
	void Search_Map(const int StartX, const int StartY) override {
		Sleep(500);
		system("cls");
		APrint_Map();
		if (StartX >= Width - 1 && StartY >= Length - 1) {
			Count_Road++;
			Map[StartX + (StartY * Width)].visited = 1;
			Sleep(500);
			system("cls");
			APrint_Map();
			return;
		}
		else if (Chack_Move(StartX, StartY, 1, 0)) {
			Count_Road++;
			Map[StartX + (StartY * Width)].visited = 1;
			Search_Map(StartX + 1, StartY);		
		} // 오른쪽
		else if (Chack_Move(StartX, StartY, 0, 1)) {
			Count_Road++;
			Map[StartX + (StartY * Width)].visited = 1;
			Search_Map(StartX, StartY + 1);
		}// 아래
		else if (Chack_Move(StartX, StartY, -1, 0)) {
			Count_Road++;
			Map[StartX + (StartY * Width)].visited = 1;
			Search_Map(StartX - 1, StartY);
		}// 왼쪽
		else if (Chack_Move(StartX, StartY, 0, -1)) {
			Count_Road++;
			Map[StartX + (StartY * Width)].visited = 1;
			Search_Map(StartX, StartY - 1);
		}// 위
		else {
			std::cout << "탐색실패" << std::endl;
			return;
		}

		return;
	}
	void APrint_Map() override {

		std::cout << "맵 " << std::endl;
		for (int i = 0; i < Length; i++) {
			for (int j = 0; j < Width; j++) {
				cout << Map[j + (i * Width)].now << ' ';
			}
			cout << endl;
		}
		cout << endl;
		std::cout << "이동 경로" << std::endl;
		for (int i = 0; i < Length; i++) {
			for (int j = 0; j < Width; j++) {
				if (Map[j + (i * Width)].visited == 1)
					std::cout << "■";
				else
					std::cout << "0 ";
			}
			cout << endl;
		}
		std::cout << "이동 횟수 : " << Count_Road << std::endl;
	}

};


int main()
{
	int arr[] = {	1, 0, 1, 0, 1, 0,
					1, 1, 1, 1, 1, 1,
					0, 0, 0, 0, 0, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1 };
	WordMap Map;
	Map.Create_Map(arr, 6, 5);
	Map.Search_Map(0, 0);
	return 0;
}