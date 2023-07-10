#include <iostream>

using namespace std;

template<typename T>
class Queue
{
public:
	struct Node
	{
		T Data;
		// 단일연결 리스트 를 통해 구현
		Node* Next;
		//큐 에서는 넣고 빼고 지우고 가능하다. 구현한다.
	};

private:
	int count = 0;
	// 보관 개수

	Node* front = NULL;// 가장 앞 변수 만들고 NULL로 초기화
	//Q 는 FIFO 구조 이기 때문에 front는 빼낼 값.
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
			// 비어있는 경우 에는,
			front = node;
			rear = node;
			// 처음과 끝을 한개의노드로 정해준다.
			count++; // count 에 1을 해서 1개라고 표시

			return;
		}

		rear->Next = node; // 한개 추가하면, 뒤의 다음값은, node가 되어야 한다.
		rear = node;// 뒤를 node로 설정해준다.

		count++;
	}

	Node* Dequeue()
	{
		// 노드를 제거하고 반환하는 형식을 만든다.
		Node* node = front;// 큐에서 제거해서 반환될 노드
		if (front->Next == NULL) // 큐에 남은 값이 없을 경우.
		{
			front = rear = NULL;
		}
		else
		{
			front = front->Next; // 큐가 한개초과 일 경우, Next를 front로 넣어준다.
		}

		count--;

		return node;
	}

	int Size() { return count; }

	bool IsEmpty() {
		return front == NULL; // 비어있는지 확인
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