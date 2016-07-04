#include <iostream>
#include <memory>

using namespace std;

//old
template <typename T>
class old_AutoPtr
{
public:
	explicit old_AutoPtr(T *ptr = NULL)
		: _ptr(ptr)
		, _owner(true)
	{
	}

	old_AutoPtr(old_AutoPtr &ap)
		: _ptr(ap._ptr)
		, _owner(true)
	{
		ap._ptr = NULL;
		ap._owner = true;
	}

	old_AutoPtr & operator=(old_AutoPtr &ap)
	{
		if (this != &ap)
		{
			if (_owner && NULL != _ptr)
			{
				delete _ptr;
			}
			_ptr = ap._ptr;
			_owner = true;
			ap._ptr = NULL;
			ap._owner = false;
		}
		return *this;
	}

	T operator*()
	{
		return *_ptr;
	}

	T * operator->()
	{
		return _ptr;
	}

	~old_AutoPtr()
	{
		if (_owner && NULL != _ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}

private:
	T *_ptr;
	bool _owner;
};

template <typename T>
class AutoPtr
{
public:
	explicit AutoPtr(T *ptr = NULL)
		: _ptr(ptr)
	{
		cout << "AutPtr()" << endl;
	}
	
	AutoPtr(AutoPtr &ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	AutoPtr & operator=(AutoPtr &ap)
	{
		if (this != &ap)
		{
			if (NULL != _ptr)
			{
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	
	T operator*()
	{
		return *_ptr;
	}

	T * operator->()
	{
		return _ptr;
	}
	
	~AutoPtr()
	{
		cout << "~AutPtr()" << endl;
		if (NULL != _ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}

private:
	T *_ptr;
};

template <typename T>
class AutoPtrArray
{
public:
	explicit AutoPtrArray(T *ptr = NULL)
		: _ptr(ptr)
	{}

	AutoPtrArray(AutoPtrArray &ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	AutoPtrArray & operator=(AutoPtrArray &ap)
	{
		if (this != &ap)
		{
			if (NULL != _ptr)
			{
				delete[] _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	T operator*()
	{
		return *_ptr;
	}

	T * operator->()
	{
		return _ptr;
	}

	~AutoPtrArray()
	{
		if (NULL != _ptr)
		{
			delete[] _ptr;
			_ptr = NULL;
		}
	}

private:
	T *_ptr;
};

template <typename T>
class scopedPtr
{
public:
	explicit scopedPtr(T *ptr = NULL)
		: _ptr(ptr)
	{}

	T operator*()
	{
		return *_ptr;
	}

	T * operator->()
	{
		return _ptr;
	}

	~scopedPtr()
	{
		if (NULL != _ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}

private:
	scopedPtr(scopedPtr &ap);
	scopedPtr & operator=(scopedPtr &ap);
private:
	T *_ptr;
};

template <typename T>
class scopedPtrArray
{
public:
	explicit scopedPtrArray(T *ptr = NULL)
		: _ptr(ptr)
	{}

	T operator*()
	{
		return *_ptr;
	}

	T * operator->()
	{
		return _ptr;
	}

	~scopedPtrArray()
	{
		if (NULL != _ptr)
		{
			delete[] _ptr;
			_ptr = NULL;
		}
	}

private:
	scopedPtrArray(scopedPtrArray &ap);
	scopedPtrArray & operator=(scopedPtrArray &ap);
private:
	T *_ptr;
};

template <typename T>
class SharedPtr
{
public:
	SharedPtr(T *ptr = NULL)
		: _ptr(ptr)
		, _pCount(NULL)
	{
		if (NULL != _ptr)
		{
			_pCount = new int(1);
		}
	}

	SharedPtr(const SharedPtr &sp)
		: _ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		if (NULL != _ptr)
		{
			++(*_pCount);
		}
	}

	SharedPtr & operator=(const SharedPtr &sp)
	{
		if (this != &sp)
		{
			Realease();
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			if (NULL != _ptr)
			{
				++(*_pCount);
			}
			return *this;
		}
	}

	T & operator*()
	{
		return *_ptr;
	}

	T * operator->()
	{
		return _ptr;
	}

	~SharedPtr()
	{
		Realease();
	}

	int GetRef()
	{
		return *_pCount;
	}
private:
	void Realease()
	{
		if (NULL != _ptr && 0 == --(*_pCount))
		{
			delete _ptr;
			delete _pCount;
		}
	}


private:
	T *_ptr;
	int *_pCount;
};

void fun()
{
	AutoPtr<int> ap(new int(1));
	AutoPtr<int> ap1 = ap;
	cout << *ap << endl; //error
}

void fun1()
{
	scopedPtr<int> ap(new int(1));
	//scopedPtr<int> ap1 = ap; //不允许调用拷贝构造或赋值运算符,不能满足使用条件
	cout << *ap << endl;
}


struct Node
{
	int data;
	//SharedPtr<Node> pNext;
	//SharedPtr<Node> pPre;
	weak_ptr<Node> pNext;
	weak_ptr<Node> pPre;

	Node()
		: data(0)
		//, pNext(NULL)
		//, pPre(NULL)
	{}
};
//循环引用引发的问题--->弱指针
void fun2()
{
	//SharedPtr<Node> p1(new Node);
	//SharedPtr<Node> p2(new Node);

	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	p1->pNext = p2;  //count = 2
	p2->pPre = p1;	//count = 2

}


int main()
{
	fun2();

	return 0;
}