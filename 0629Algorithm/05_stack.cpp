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
		// 메모리 초기화 해주는 함수.
		// 메모리 시작 주소 기입,
		// 메모리 사이즈 기입한다.
		// 0으로 모든 메모리를 초기화해주는 함수,
	}

	void Push(T value)
	{
		assert(top + 1 < MAXSTACKCOUNT);
		// Stack이 가득차지 않았다면,
		values[++top] = value; // values라는 배열에 1씩 더해주면서 올려준다.
	}
	T Pop()
	{
		assert(Empty() == false);

		T val = values[top--];

		return val; // 맨 위의 요소를 제거하고 그 요소를 반환해준다.
	}
	T Front()
	{
		return values[top]; // 맨 위의 값을 반환해준다.
	}
	T back()
	{
		assert(top > -1);
		return values[0]; // 배열의 가장 뒤의 값을 반환한다.
		// 배열이 비어있는지 또한 확인한다.
	}

	bool Empty()
	{ // 배열이 비어있는지, top이 0보다 작으면 비어있다는 의미 이기 때문에,
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