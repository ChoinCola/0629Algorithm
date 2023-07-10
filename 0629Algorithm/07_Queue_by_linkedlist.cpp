#include <iostream>

using namespace std;

template<typename T>
class Queue
{
public:
	struct Node
	{
		T Data;
		// ���Ͽ��� ����Ʈ �� ���� ����
		Node* Next;
		//ť ������ �ְ� ���� ����� �����ϴ�. �����Ѵ�.
	};

private:
	int count = 0;
	// ���� ����

	Node* front = NULL;// ���� �� ���� ����� NULL�� �ʱ�ȭ
	//Q �� FIFO ���� �̱� ������ front�� ���� ��.
	Node* rear = NULL;

public:
	Queue() {}

	~Queue()
	{

	}

	void Enqueue(Node* node)
	{
		if (front == NULL)
		{
			// ����ִ� ��� ����,
			front = node;
			rear = node;
			// ó���� ���� �Ѱ��ǳ��� �����ش�.
			count++; // count �� 1�� �ؼ� 1����� ǥ��

			return;
		}

		rear->Next = node; // �Ѱ� �߰��ϸ�, ���� ��������, node�� �Ǿ�� �Ѵ�.
		rear = node;// �ڸ� node�� �������ش�.

		count++;
	}

	Node* Dequeue()
	{
		// ��带 �����ϰ� ��ȯ�ϴ� ������ �����.
		Node* node = front;// ť���� �����ؼ� ��ȯ�� ���
		if (front->Next == NULL) // ť�� ���� ���� ���� ���.
		{
			front = rear = NULL;
		}
		else
		{
			front = front->Next; // ť�� �Ѱ��ʰ� �� ���, Next�� front�� �־��ش�.
		}

		count--;

		return node;
	}

	int Size() { return count; }

	bool IsEmpty() {
		return front == NULL; // ����ִ��� Ȯ��
	}
public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}
};

int main()
{
	Queue<int> queue;
	queue.Enqueue(Queue<int>::CreateNode(10));
	queue.Enqueue(Queue<int>::CreateNode(20));
	queue.Enqueue(Queue<int>::CreateNode(30));

	cout << "Size : " << queue.Size() << endl;

	while (queue.IsEmpty() == false)
	{
		Queue<int>::Node* node = queue.Dequeue();
		cout << "Dequeue : " << node->Data << endl;

		Queue<int>::DestroyNode(&node);
	}
	return 0;
}