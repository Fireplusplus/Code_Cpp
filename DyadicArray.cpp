#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef int DataType;

class DyadicArray
{
	friend ostream & operator<<(ostream &os, DyadicArray &d);


public:
	DyadicArray(int row = 2, int col = 2)
	: _size(0)
	, _row(row)
	, _col(col)
	{
		_data = new DataType[row * col];
	}

	DyadicArray(const DyadicArray & arr)
	: _size(arr._size)
	, _row(arr._row)
	, _col(arr._col)
	{
		_data = new DataType[_row * _col];
		memmove(_data, arr._data, _row * _col * sizeof(DataType));
	}
	
	~DyadicArray()
	{
		delete[] _data;
	}
	
	DataType * operator[](int row)
	{
		return _data + row * _col;
	}
	
	

private:
	DataType *_data;
	int _size;	//实际存放元素个数
	int _row;	
	int _col;	
};

ostream & operator<<(ostream &os, DyadicArray &d)
{
	for (int i = 0; i < d._row; i++)
	{
		for (int j = 0; j < d._col; j++)
		{
			os << d[i][j];
			if (j != d._col - 1)
				os << " ";
		}
		if (i != d._row - 1)
			os << endl;
	}
	
	return os;
}

int main()
{
/*	DyadicArray d1, d2;
	DyadicArray d3(d1);
	
	d1[1][1] = 10;
	cout << d1 << endl;
*/
/*	int *p = new int[10];
	free(p);
*/	
/*	DyadicArray *d4 = new DyadicArray[4];
	free(d4);
*/
/*	DyadicArray *d4 = new DyadicArray;
	delete[] d4;	//多还少还都会崩溃
*/
	return 0;
}
