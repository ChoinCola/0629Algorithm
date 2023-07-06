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
	Node* list = NULL; // ������ �迭�� ����Ŵ
	Node* top = NULL; // ������ ������ ��� ����Ű�� ����

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
	// pop�� ��� ȣ�������ν� ��� ������ �����ϵ��� �����.
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
	if (list != NULL) // ���� ������ ������� �ʴٸ�,
	{
		Node* tail = list; // ������ �� ���� �̵��� ������.
		// ���������� ���κп� ���� �ִ´�.
		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
		// tail �� ������ NULL�� node�� �����Ѵ�.
	}
	else // ������ ����ִٸ�
	{
		list = node;
	}
}

Node* Stack::Pop()
{
	// �����͸� ��ȯ�ϰ� ������ �ȴ�.
	if (list == top) // �迭�� �Ѱ��� �̶��,
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
		// ���� ������ ������ �и��ϰ�,
		// �� �� ��带 ��ȯ�Ѵ�.
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
	// ��������� ���� ���� ��尡 �������� NULL�� ó��
	return node;
}

void Stack::DestoryNode(Node** node)
{
	delete* node;
	*node = NULL;
	// �����͸� �����ϱ� ���ؼ� ���������ͷ� �����;� �Ѵ�.
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