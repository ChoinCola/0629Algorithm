#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� �湮�� ����� �����¿츦 ���� Ž���ϰ�.
// ���� Ž���� ���� ���� ó���Ϸ� �̵��Ѵ�.
// FIFO����.

bool visited[9];
vector<int> graph[9];

void bfs(int start) // ���� ��带 �־��ְ� �����Ѵ�.
{
	queue<int> q;
	q.push(start); // ���۳�� �־���.
	// �� ���۳��� �湮ó���� �ȴ�.
	visited[start] = true;
	// �湮�ߴٴ� �ǹ̸� ������ �迭�� ���� ������ش�.

	while (!q.empty()) {
		int x = q.front();
		// ���� ���� ���. ���� ������ ���. ������
		// ���� ó�� �� ���

		q.pop(); 
		// �����´��� ���ش�.
		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++)
		{// ���� ��ȯ�ϴ� graph�� size�� Ž���Ѵ�.
		 // �� ��, �ش� graph�� ����Ǿ��ִ� ��带���� Ž��
			int y = graph[x][i];
			// y �� �ش� ��°�� i�� �ھƳִ´�.
			if (!visited[y])
			{// ����, �ش��°�� i�� �湮���� �� ���ٸ�,
				q.push(y);
				// q�� push�Ͽ� �־��ְ�,
				visited[y] = true;
				// �湮���� �ۼ��Ѵ�.
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
	��ũ�� �Է�, �� �Է� ���� ��,
	1 0 1 0 1 0
	1 1 1 1 1 1
	0 0 0 0 0 1
	1 1 1 1 1 1
	1 1 1 1 1 1
	���� ���� ��, ������� ���� ���� �ϴܱ�����
	���� ����� ���� ã�´�.
	=> 10�� ���� �� �ֵ���,
*/