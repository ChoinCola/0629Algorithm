#include <iostream>

using namespace std;

struct Node
{
	int Data;

	Node* NextNode;
};

class Stack
{
private:
	Node* list = NULL; // 스텍의 배열을 가리킴
	Node* top = NULL; // 스텍의 제일위 요소 가리키게 만듬

public:
	Stack();
	~Stack();

	void Push(Node* node);
	Node* Pop();

	int Size();
	bool IsEmpty();

	static Node* CreateNode(int data);
	static void DestoryNode(Node** node);
};

Stack::Stack()
{}
Stack::~Stack()
{
	// pop을 계속 호출함으로써 모든 스텍을 제거하도록 만든다.
	while (IsEmpty() == false)
	{
		Node* node = Pop();
		DestoryNode(&node);
	}
	list = NULL;
	top = NULL;
}

void Stack::Push(Node * node)
{
	if (list != NULL) // 현재 스텍이 비어있지 않다면,
	{
		Node* tail = list; // 스텍의 끝 까지 이동할 포인터.
		// 마지막에서 끝부분에 값을 넣는다.
		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
		// tail 의 마지막 NULL에 node를 연결한다.
	}
	else // 스텍이 비어있다면
	{
		list = node;
	}
}

Node* Stack::Pop()
{
	// 데이터를 반환하고 날리면 된다.
	if (list == top) // 배열이 한개뿐 이라면,
	{
		list = NULL;
		top = NULL;
	}
	else
	{
		Node* tail = list;
		while (tail != NULL && tail->NextNode != top)
		{
			tail = tail->NextNode;
		}

		top = tail;
		// 맨위 노드와의 연결을 분리하고,
		// 맨 위 노드를 반환한다.
		tail->NextNode = NULL;
	}

	return top;
}

int Stack::Size()
{
	int count = 0;
	Node* node = list;

	while (node != NULL)
	{
		node = node->NextNode;
		count++;
	}
	return count;
}

bool Stack::IsEmpty()
{
	return list == NULL;
}

Node* Stack::CreateNode(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->NextNode = NULL;
	// 만들어졌을 때는 다음 노드가 없음으로 NULL로 처리
	return node;
}

void Stack::DestoryNode(Node** node)
{
	delete* node;
	*node = NULL;
	// 데이터를 해제하기 위해서 이중포인터로 가져와야 한다.
}


int main()
{
	Stack stack;
	stack.Push(Stack::CreateNode(10));
	stack.Push(Stack::CreateNode(20));
	stack.Push(Stack::CreateNode(30));
	stack.Push(Stack::CreateNode(40));

	int count = stack.Size();
	cout << "Size : " << count << endl;

	for (int i = 0; i < count; i++)
	{
		if (stack.IsEmpty() == true)
			break;

		Node* temp = stack.Pop();
		cout << "pop : " << temp->Data << endl;
		Stack::DestoryNode(&temp);
	}


	return 0;
}