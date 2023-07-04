#include <iostream>

using namespace std;

// ���� �켱 Ž��
// ���� �� �� �ִ� ��� �ִ��� ���� ���.
// ���ʿ��� ��츦 �����ϰų� �׷��� ����.
// �׷��� ����� ���� ���� �� ����.
// ���ͷ� ���� ����� �������� ���� ����� �ִ�.

template<typename T>
class Graph
{
public:

	struct Node;
	struct Edge // ���� ����
	{
		Node* Start = NULL;
		Node* Target = NULL;
		Edge* Next = NULL;
	};
	struct Node
	{
		T Data;
		int Index = -1;
	
		Node* Next = NULL; // ���� ��忡 ���� ������
		Edge* Edge = NULL; // ���� ������ ���� ������
		
		bool Visited = false; // �湮 ���ο� ���� ���
	};

private:
	Node* Head = NULL;
	int Count = 0;

public:
	static Edge* CreateEdge(Node* start, Node* target)
	{
		Edge* edge = new Edge(); // �����Ҵ�.
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
		Node* nodeList = Head; // Head = ���Ḯ��Ʈ���� �Ӹ��� �����Ѵ�.

		if (nodeList != NULL)
		{
			while (nodeList->Next != NULL)
			{
				nodeList = nodeList->Next;
			}
			nodeList->Next = node; // ���ο� ��尡 ���Ḯ��Ʈ ���� ��ġ�ϰ� �ȴ�.
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
		if((node = Head) == NULL) // ��尡 ���ٸ� ������ �����ϱ� ����
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
			edge = edge->Next; // ������ �ϳ��� �ƴϱ� ������, ���� ������ üũ���ִ� �κ��� ������־�� �Ѵ�.
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

	4 5 ����� �޾ƿ´�.

	0�� 1�� ���� �׷��ش�.

	0 0 1 1 0
	0 1 0 1 1 
	1 0 1 0 1
	0 0 1 1 0 
	1�� ���� 0�� 6��

	=6
	�� ��µǰ�.
	�ڵ� ������
	
	1. �迭 ��ü�� Ž���Ѵ�.
	2. �������� �ð�������� �����Ͽ� �̵��Ѵ�.
	3. ������ �� �ִ� ���� 0�� �̵��غ��� �ʾҴ���.
	4. ������ �� �ִٸ� �����Ѵ�.
	5. ������ �� ���ٸ� ���� �̵��ߴ� �� ���� ��ĭ �̵��Ѵ�.
	6. �̵��ߴ� �� ���� ������ �� ����. �����¿� �� �˻��Ͽ� �̵��� �� �ִ��� �˻��Ѵ�.
	7. �� �� �ִٸ�, 4������ �ٽ� �ݺ����ش�.
	8. 7������ ���� ������ �Ͽ��µ��� �̵��� �� �ִ°��� �������� �ʴ´ٸ�, ���������� 1�� �����ְ� ������ ����ĭ�� �˻����ش�.

	N. �̵� ��, ������ ���� ������ ����� �ʵ��� ���ش�.
	N. ��ǥ���� ���� �����ϱ⺸�ٴ�, x�� y��ǥ�� �����Ͽ� ��ǥ�̵������ ����ϸ� ����.
	N. �̵� ��, �ִ�XY�� ����ٸ�, �̵����� ���ϴ°� ���� ����Ѵ�.
*/