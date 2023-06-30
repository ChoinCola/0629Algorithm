#include <iostream>

using namespace std;

// 깊이 우선 탐색
// 내가 갈 수 있는 대로 최대한 들어가는 방식.
// 불필요한 경우를 차단하거나 그런건 없다.
// 그래서 경우의 수를 줄일 수 없다.
// 제귀로 들어가는 방법과 스텍으로 들어가는 방법이 있다.

template<typename T>
class Graph
{
public:

	struct Node;
	struct Edge // 간선 제작
	{
		Node* Start = NULL;
		Node* Target = NULL;
		Edge* Next = NULL;
	};
	struct Node
	{
		T Data;
		int Index = -1;
	
		Node* Next = NULL; // 다음 노드에 대한 포인터
		Edge* Edge = NULL; // 다음 간선에 대한 포인터
		
		bool Visited = false; // 방문 여부에 대한 결과
	};

private:
	Node* Head = NULL;
	int Count = 0;

public:
	static Edge* CreateEdge(Node* start, Node* target)
	{
		Edge* edge = new Edge(); // 동적할당.
		edge->Start = start;
		edge->Target = target;

		return edge;
	}
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;

		return node;
	}

public:
	void AddNode(Node* node)
	{
		Node* nodeList = Head; // Head = 연결리스트에서 머리를 구현한다.

		if (nodeList != NULL)
		{
			while (nodeList->Next != NULL)
			{
				nodeList = nodeList->Next;
			}
			nodeList->Next = node; // 새로운 노드가 연결리스트 끝에 위치하게 된다.
		}
		else
		{
			Head = node;
		}

		node->Index = Count++;
	}

	void AddEdge(Node* node, Edge* edge)
	{
		if (node->Edge != NULL)
		{
			Edge* edgeList = node -> Edge;
			while (edgeList->Next != NULL)
			{
				edgeList = edgeList->Next;
			}

			edgeList->Next = edge;
		}
		else
		{
			node->Edge = edge;
		}
	}

	void Print()
	{
		Node* node = NULL;
		Edge* edge = NULL;
		if((node = Head) == NULL) // 헤드가 없다면 정보가 없으니까 종료
			return;
		while (node != NULL)
		{
			cout << node -> Data << " : ";
			if ((edge = node->Edge) == NULL)
			{
				node = node->Next;
				cout << endl;

				continue;
			}

			while (edge != NULL)
			{
				cout << edge->Target->Data;
				edge = edge->Next;
			}

			cout << endl;

			node = node->Next;
		}

		cout << endl;
	}

	void DFS(Node* node)
	{
		cout << node->Data;

		node->Visited = true;

		Edge* edge = node->Edge;

		while (edge != NULL)
		{
			if(edge->Target != NULL && edge->Target->Visited == false)
				DFS(edge->Target);
			edge = edge->Next; // 간선이 하나가 아니기 떄문에, 다음 간선도 체크해주는 부분을 만들어주어야 한다.
		}
	}
};

typedef Graph<char> G;

int main()
{
	G graph;

	G::Node* n1 = G::CreateNode('A');
	G::Node* n2 = G::CreateNode('B');
	G::Node* n3 = G::CreateNode('C');
	G::Node* n4 = G::CreateNode('D');
	G::Node* n5 = G::CreateNode('E');

	graph.AddNode(n1);
	graph.AddNode(n2);
	graph.AddNode(n3);
	graph.AddNode(n4);
	graph.AddNode(n5);
	
	graph.AddEdge(n1, G::CreateEdge(n1, n2));
	graph.AddEdge(n1, G::CreateEdge(n1, n3));
	graph.AddEdge(n1, G::CreateEdge(n1, n4));
	graph.AddEdge(n1, G::CreateEdge(n1, n5));
	
	graph.AddEdge(n2, G::CreateEdge(n2, n1));
	graph.AddEdge(n2, G::CreateEdge(n2, n3));
	graph.AddEdge(n2, G::CreateEdge(n2, n5));

	graph.AddEdge(n3, G::CreateEdge(n3, n1));
	graph.AddEdge(n3, G::CreateEdge(n2, n2));

	graph.AddEdge(n4, G::CreateEdge(n4, n1));
	graph.AddEdge(n4, G::CreateEdge(n4, n5));

	graph.AddEdge(n5, G::CreateEdge(n2, n1));
	graph.AddEdge(n5, G::CreateEdge(n2, n2));
	graph.AddEdge(n5, G::CreateEdge(n2, n4));

	graph.Print();

	graph.DFS(n1);







	return 0;
}

/*

	4 5 행렬을 받아온다.

	0과 1로 맵을 그려준다.

	0 0 1 1 0
	0 1 0 1 1 
	1 0 1 0 1
	0 0 1 1 0 
	1로 묶인 0이 6개

	=6
	이 출력되게.
	코드 만들어보기

*/