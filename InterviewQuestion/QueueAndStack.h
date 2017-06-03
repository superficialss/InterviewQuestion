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
//���������żλʵ������ջ
class CTwoStackWithArr1
{
public:
	CTwoStackWithArr1()
		:_array(NULL)
		, _index1(0)
		, _index2(1)
		,_capacity(0)
	{}

	void Push1(const int& x)
	{
		_CheckCapacity();
		_array[_index1] = x;
		_index1 += 2;
	}

	void Push2(const int& x)
	{
		_CheckCapacity();
		_array[_index2] = x;
		_index2 += 2;
	}

	void Pop1()
	{
		if (_index1 != 0)
		{
			_index1 -= 2;
		}
		else
		{
			cout << "The stack1 is empty!" << endl;
			exit(1);
		}
	}

	void Pop2()
	{
		if (_index2 != 1)
		{
			_index2 -= 2;
		}
		else
		{
			cout << "The stack2 is empty!" << endl;
			exit(2);
		}
	}

	int Top1()
	{
		assert(_index1 != 0);
		return _array[_index1 - 2];
	}

	int Top2()
	{
		assert(_index2 != 1);
		return _array[_index2 - 2];
	}

	int Size1()
	{
		return _index1 / 2;
	}

	int Size2()
	{
		return (_index2 - 1) / 2;
	}

	bool Empty1()
	{
		return !Size1();
	}

	bool Empty2()
	{
		return !Size2();
	}

	~CTwoStackWithArr1()
	{
		delete[] _array;
	}

protected:
	void _CheckCapacity()
	{
		if (_index1 >= _capacity || _index2 >= _capacity)
		{
			int newcapacity = 2 * _capacity + 3;
			int* newarray = new int[newcapacity];
			
			for (int i = 0; i < _index1; ++i)
			{
				newarray[i] = _array[i];     //����ż��ջ������
			}

			for (int i = 1; i < _index2; ++i)
			{
				newarray[i] = _array[i];          //��������ջ������
			}

			delete[] _array;
			_capacity = newcapacity;
			_array = newarray;
		}
	}
protected:
	int* _array;
	int _index1;
	int _index2;
	int _capacity;
};

void TestCTwoStackWithArr1()
{
	CTwoStackWithArr1 s;
	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);

	//żջ
	while (!s.Empty1())
	{
		cout << s.Top1() << " ";
		s.Pop1();
	}
	cout << endl;

	s.Push2(10);
	s.Push2(9);
	s.Push2(8);
	s.Push2(7);

	//��ջ
	while (!s.Empty2())
	{
		cout << s.Top2() << " ";
		s.Pop2();
	}
	cout << endl;
}

//��������м�ֿ���ʵ������ջ
class CTwoStackWithArr2
{
public:
	CTwoStackWithArr2()
		:_array(NULL)
		,_index1(0)
		,_index2(0)
		,_capacity(0)
	{}

	void Push1(const int& x)
	{
		_CheckCapacity();
		_array[_index1] = x;
		--_index1;
	}

	void Push2(const int& x)
	{
		_CheckCapacity();
		_array[_index2] = x;
		++_index2;
	}

	void Pop1()
	{
		if (_index1 < _capacity/2)
		{
			_index1++;
		}
		else
		{
			cout << "The stack1 is empty!" << endl;
			exit(1);
		}
	}

	void Pop2()
	{
		if (_index2 != _capacity/2)
		{
			_index2--;
		}
		else
		{
			cout << "The stack2 is empty!" << endl;
			exit(2);
		}
	}

	int Top1()
	{
		return _array[_index1 + 1];
	}

	int Top2()
	{
		return _array[_index2 - 1];
	}

	int Size1()
	{
		int mid = _capacity >> 1;
		return mid - 1 - _index1;
	}

	int Size2()
	{
		int mid = _capacity >> 1;
		return mid - _index2;
	}

	bool Empty1()
	{
		return !Size1();
	}

	bool Empty2()
	{
		return !Size2();
	}

	~CTwoStackWithArr2()
	{
		delete[] _array;
	}

protected:
	void _CheckCapacity()
	{
		if (_index1 < 0 || _index2 == _capacity)
		{
			int newcapacity =  _capacity * 2 + 3;
			int* newarray = new int[newcapacity];
			int mid = _capacity / 2;
			int NewMid = newcapacity / 2;

			for (int i = mid; i >= 0 && _capacity > 0; --i)
			{
				newarray[NewMid--] = _array[i];
			}

			for (int i = mid; i < _capacity; ++i)
			{
				newarray[NewMid++] = _array[i];
			}

			delete[] _array;
			_capacity = newcapacity;
			_array = newarray;
			_index1 = NewMid - (mid - _index1);
			_index2 = NewMid + (_index2 - mid) + 1;
		}
	}

protected:
	int* _array;
	int _index1;
	int _index2;
	int _capacity;
};

void TestCTwoStackWithArr2()
{
	CTwoStackWithArr2 s;
	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);

	while (!s.Empty1())
	{
		cout << s.Top1() << " ";
		s.Pop1();
	}
	cout << endl;

	s.Push2(10);
	s.Push2(9);
	s.Push2(8);
	s.Push2(7);

	while (!s.Empty2())
	{
		cout << s.Top2() << " ";
		s.Pop2();
	}
	cout << endl;
}