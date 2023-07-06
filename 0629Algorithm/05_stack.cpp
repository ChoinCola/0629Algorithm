#include <iostream>
#include <memory.h>
#include <cassert>

using namespace std;

#define MAXSTACKCOUNT 20

template<typename T>
class Stack
{
private:
	int top = -1;
	T values[MAXSTACKCOUNT];
public:
	Stack()
	{
		memset(values, 0, sizeof(T) * MAXSTACKCOUNT);
		// �޸� �ʱ�ȭ ���ִ� �Լ�.
		// �޸� ���� �ּ� ����,
		// �޸� ������ �����Ѵ�.
		// 0���� ��� �޸𸮸� �ʱ�ȭ���ִ� �Լ�,
	}

	void Push(T value)
	{
		assert(top + 1 < MAXSTACKCOUNT);
		// Stack�� �������� �ʾҴٸ�,
		values[++top] = value; // values��� �迭�� 1�� �����ָ鼭 �÷��ش�.
	}
	T Pop()
	{
		assert(Empty() == false);

		T val = values[top--];

		return val; // �� ���� ��Ҹ� �����ϰ� �� ��Ҹ� ��ȯ���ش�.
	}
	T Front()
	{
		return values[top]; // �� ���� ���� ��ȯ���ش�.
	}
	T back()
	{
		assert(top > -1);
		return values[0]; // �迭�� ���� ���� ���� ��ȯ�Ѵ�.
		// �迭�� ����ִ��� ���� Ȯ���Ѵ�.
	}

	bool Empty()
	{ // �迭�� ����ִ���, top�� 0���� ������ ����ִٴ� �ǹ� �̱� ������,
		return top < 0 ? true : false;
	}
};

int main()
{
	Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Pop();

	stack.Push(40);
	stack.Push(50);

	cout << stack.back() << endl << endl;
	cout << stack.Front() << endl << endl;

	while (stack.Empty() == false)
		cout << stack.Pop() << endl;

	return 0;
}