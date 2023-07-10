#include <iostream>
#include <stack>
#include <queue>
// 기본적인 트리구조 구축
using namespace std;

template<typename T>
class Tree
{
public:
	struct Node
	{
		T Data;

		Node* LeftChild;
		Node* RightSibling;
		~Node()
		{
			Data = 0;

			LeftChild = NULL;
			RightSibling = NULL;
		}
	};
public:
	stack<Node*>* Stack() { return &stack; }
	queue<T>* Queue() { return &queue; }
private:
	queue<T> queue;
	// 출력하는데 활용
	stack<Node*> stack;
	// 트리노드 순회, 노드 삭제하는데 활용
public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->LeftChild = node->RightSibling = NULL;

		return node;
	}

	static void DestoryNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}
public:
	void Addchild(Node* parent, Node* child)
	{
		if (parent->LeftChild == NULL)
		{
			parent->LeftChild = child;
			
			return;
		}

		Node* node = parent->LeftChild;
		
		while (node->RightSibling != NULL)
		{
			node = node->RightSibling;
			// 노드의 오른쪽으로 계속 이동
		}

		node->RightSibling = child;
		// 계속 이동한 노드의 최우측끝 에 값을 삽입한다.
	}

	void PrintNode(Node* node, int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";

		cout << node->Data << endl;
		queue.push(node->Data);
		stack.push(node);

		if (node->LeftChild != NULL) // leftChild가 있는지 확인 있다면, 제귀
			PrintNode(node->LeftChild, depth + 1);

		if (node->RightSibling != NULL) // 오른쪽이 존재하는지 확인, 있다면 제귀
			PrintNode(node->RightSibling, depth);
	}
};

int main()
{
	Tree<char> tree;

	Tree<char>::Node* A = Tree<char>::CreateNode('A');
	Tree<char>::Node* B = Tree<char>::CreateNode('B');
	Tree<char>::Node* C = Tree<char>::CreateNode('C');
	Tree<char>::Node* D = Tree<char>::CreateNode('D');
	Tree<char>::Node* E = Tree<char>::CreateNode('E');
	Tree<char>::Node* F = Tree<char>::CreateNode('F');
	Tree<char>::Node* G = Tree<char>::CreateNode('G');
	Tree<char>::Node* H = Tree<char>::CreateNode('H');
	Tree<char>::Node* I = Tree<char>::CreateNode('I');
	Tree<char>::Node* J = Tree<char>::CreateNode('J');
	Tree<char>::Node* K = Tree<char>::CreateNode('K');

	tree.Addchild(A, B);
	tree.Addchild(B, C);
	tree.Addchild(B, D);
	tree.Addchild(D, E);
	tree.Addchild(D, F);

	tree.Addchild(A, G);
	tree.Addchild(G, H);

	tree.Addchild(A, I);
	tree.Addchild(I, J);
	tree.Addchild(I, K);

	tree.PrintNode(A, 0);

	while (tree.Queue()->empty() == false)
	{
		cout << tree.Queue()->front() << endl;
		tree.Queue()->pop();
	}
	cout << endl << endl;

	while (tree.Stack()->empty() == false)
	{
		Tree<char>::Node* node = tree.Stack()->top();
		tree.Stack()->pop();

		Tree<char>::DestoryNode(&node);
	}

	return 0;
}