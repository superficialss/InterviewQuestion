#pragma once

//ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)
class StackWithMin1
{
public:
	void Push(const int& x)
	{
		_stack.push(x);
		if (!_min.empty())
		{
			int tmp = _min.top();
			if (x <= tmp)
			{
				_min.push(x);
			}
		}
		else
		{
			_min.push(x);
		}
	}

	void Pop()
	{
		assert(!_stack.empty());
		if (_stack.top() == _min.top())
		{
			_min.pop();
		}
		_stack.pop();
	}

	int Min()
	{
		if (!_min.empty())
		{
			return _min.top();
		}
	}

protected:
	stack<int> _stack;
	stack<int> _min;          //������С������
};

class StackWithMin2
{
public:
	void Push(const int& x)
	{
		if (_stack.empty() || _stack.top() > x)
		{
			_stack.push(x);
			_stack.push(x);
		}
		else
		{
			int tmp = _stack.top();
			_stack.push(x);
			_stack.push(tmp);
		}

	}

	void Pop()
	{
		assert(!_stack.empty());
		_stack.pop();
		_stack.pop();
	}

	int Min()
	{
		if (!_stack.empty())
		{
			return _stack.top();
		}
	}

protected:
	stack<int> _stack;
};

void TestStackWithMin()
{
	StackWithMin1 s;
	s.Push(4); 
	s.Push(2);
	s.Push(3);
	s.Push(1);
	s.Push(0);
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();

	StackWithMin2 s1;
	s1.Push(4);
	s1.Push(2);
	s1.Push(3);
	s1.Push(1);
	s1.Push(0);
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
	s1.Pop();
}

//ʹ������ջʵ��һ������
//����ͷ��βʵ�ֽ�Ϊ�鷳����ʵ����
class CQueue
{
public:
	void Push(const int& x)
	{
		s1.push(x);
	}

	void Pop()
	{
		assert((!s1.empty()) || (!s2.empty()));
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}

	int Size()
	{
		return s1.size() + s2.size();
	}

	bool Empty()
	{
		return s1.empty() && s2.empty();
	}

protected:
	stack<int> s1;
	stack<int> s2;
};

void TestCQueue()
{
	CQueue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	while (!q.Empty())
	{
		cout << "Size:" << q.Size() << endl;
		q.Pop();
	}
}

// ʹ����������ʵ��һ��ջ
class CStack
{
public:
	void Push(const int& x)
	{
		if (!q1.empty())
		{
			q2.push(x);
			while (!q1.empty())
			{
				q2.push(q1.front());
				q1.pop();
			}
		}
		else
		{
			q1.push(x);
			while (!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
	}

	void Pop()
	{
		if (q1.empty() && q2.empty())
		{
			cout << "The Stack Is Empty!" << endl;
			exit(1);
		}
		else if (q1.empty())
		{
			q2.pop();
		}
		else
		{
			q1.pop();
		}
	}

	int Size()
	{
		return q1.size() + q2.size();
	}

	int Top()
	{
		assert(!q1.empty() || !q2.empty());
		if (q1.empty())
		{
			return q2.front();
		}
		else
		{
			return q1.front();
		}
	}

	bool Empty()
	{
		return q1.empty() && q2.empty();
	}

protected:
	queue<int> q1;
	queue<int> q2;
};

void TestCStack()
{
	CStack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);

	cout << "Size:" << s.Size() << endl;

	while (!s.Empty())
	{
		cout << s.Top() << " ";
		s.Pop();
	}
	cout << endl;
}


// Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ�����У�1, 2, 3, 4, 5������ջ����Ϊ��4, 5, 3, 2, 1��



// һ������ʵ������ջ


