#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 먼저 방문한 노드의 상하좌우를 먼저 탐색하고.
// 전부 탐색한 다음 노드로 처리하러 이동한다.
// FIFO구조.

bool visited[9];
vector<int> graph[9];

void bfs(int start) // 시작 노드를 넣어주고 시작한다.
{
	queue<int> q;
	q.push(start); // 시작노드 넣어줌.
	// 이 시작노드는 방문처리가 된다.
	visited[start] = true;
	// 방문했다는 의미를 가지는 배열을 따로 만들어준다.

	while (!q.empty()) {
		int x = q.front();
		// 가장 앞의 요소. 가장 오래된 요소. 가져옴
		// 가장 처음 들어간 요소

		q.pop(); 
		// 가져온다음 빼준다.
		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++)
		{// 현재 순환하는 graph의 size를 탐색한다.
		 // 그 후, 해당 graph에 연결되어있는 노드를전부 탐색
			int y = graph[x][i];
			// y 에 해당 번째의 i를 박아넣는다.
			if (!visited[y])
			{// 만약, 해당번째의 i가 방문한적 이 없다면,
				q.push(y);
				// q에 push하여 넣어주고,
				visited[y] = true;
				// 방문록을 작성한다.
			}
		}
	}
}

int main()
{
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);

	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	graph[4].push_back(3);
	graph[4].push_back(5);

	graph[5].push_back(3);
	graph[5].push_back(4);

	graph[6].push_back(7);

	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	graph[8].push_back(1);
	graph[8].push_back(7);

	bfs(1);

	return 0;
}

/*
	맵크기 입력, 맵 입력 받을 때,
	1 0 1 0 1 0
	1 1 1 1 1 1
	0 0 0 0 0 1
	1 1 1 1 1 1
	1 1 1 1 1 1
	길이 있을 떄, 좌측상단 부터 우측 하단까지의
	가장 가까운 길을 찾는다.
	=> 10이 찍일 수 있도록,
*/