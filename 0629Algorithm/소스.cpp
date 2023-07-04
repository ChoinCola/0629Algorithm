#include <iostream>
#include <vector>
#include <list>

class Point
{
public:
	int P_X;
	int P_Y;

	bool Chack_IO;
	bool Chack_Type;

	Point* UP;
	Point* Down;
	Point* Left;
	Point* Right;

	Point()
	{
		Chack_IO =		false;
		Point* UP =		nullptr;
		Point* Down =	nullptr;
		Point* Left =	nullptr;
		Point* Right =	nullptr;
	}
};

class MAP : public Point
{
	int M_X;
	int M_Y;
	bool* input_map;

	Point* Start_P;
	std::vector<Point*> Line_Map;

	int Count_Search;

public:
	MAP(int M_X, int M_Y, bool* input_map) : M_X(M_X), M_Y(M_Y), input_map(input_map)
	{}

	void Create_MAP()
	{
		std::vector<Point*> defYline;
		std::vector<Point*> defXline;

		// 맵 생성 기반 위치좌표
		Point* defP;

		// 맵 생성
		for (int i = 0; i < M_Y; i++) {
			for (int j = 0; j < M_X; j++) {
				Point* def = new Point;
				defP = def;
				defXline.push_back(def);
				Line_Map.push_back(def);
			}
			defYline.push_back(defP);
		}
		Start_P = *defXline.begin();
		// 전체 맵 제작

		for (auto iter = defXline.begin(); iter != defXline.end(); iter++)
			if (iter != defXline.end())
				iter->Right = *(iter++); // 오른쪽

		for (auto iter = defXline.end(); iter != defXline.begin(); iter--)
			if (iter != defXline.begin())
				iter->Left = *(iter--); // 왼쪽

		for (auto iter = defYline.begin(); iter != defYline.end(); iter++) {
			iter->Right->Left = nullptr; // Y좌표기준 우측끝의 바로 오른쪽의 왼쪽은 비어있어야함.
			iter->Right = nullptr; // Y좌표 기준 우측끝의 오른쪽은 비어있어야함.
		}
		
		for (auto iter = defYline.begin(); iter != defYline.end(); iter++) {
			if(iter != defYline.end())
				for (int i = 0; i < M_X; i++) {
					((*iter) + i)->Down = ((*(iter++)) + i); // 밑을 연결하기
				}
		}

		for (auto iter = defYline.end(); iter != defYline.begin(); iter++) {
			if (iter != defYline.begin())
				for (int i = 0; i < M_X; i++) {
					((*iter) + i)->UP = ((*(iter++)) + i); // 위를 연결하기
				}
		}
	}

	void Search_Map()
	{
		std::vector<Point> Warm;

		for (int i = 0; i < M_X * M_Y; i++) {
			while (true) {
				if(Start)
				if(Start_P->Right->Chack_IO == false)
			}
			Start_P = Line_Map;
		}
	}

	void Searcher(std::vector<Point>::iterator P, int &count)
	{
	}
};

int main()
{


	return 0;
}