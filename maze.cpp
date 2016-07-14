#include <iostream>
#include <stdio.h>

const int X = 10;
const int Y = 10;

struct addr
{
	int y;	//行
	int x;	//列
};

class maze
{
public:
	maze(FILE *map)
	{
		_map = (char (*)[X])new char[X * Y];
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				fseek(map, i * Y + j + i, SEEK_SET);
				fread(&_map[i][j], sizeof(char), 1, map);
			}
		}
		in.y = 9;
		in.x = 6;
	}
	
	addr play(const addr &_pre, const addr &_cur);

	void print()
	{
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				std::cout << _map[i][j] << " ";				
			}
			std::cout << std::endl;				
		}
	}
	
	~maze()
	{
		if (NULL != _map)
		{
			delete[] _map;
		}
	}

public:
	char (*_map)[X];
	addr in;
};


struct addr maze::play(const addr &_pre, const addr &_cur)
{
	if ((0 == _cur.x || 9 == _cur.x || 0 == _cur.y || 9 == _cur.y) && (9 != _cur.y && 6 != _cur.x))
		return _cur;

	addr cur = _cur;
	addr next;
	
	//朝左走
	if ('1' == _map[cur.y][cur.x - 1])	//1:通路
	{
		next.y = cur.y;
		next.x = cur.x - 1;
		_map[cur.y][cur.x] = '2';
	}
	//朝前走
	else if ('1' == _map[cur.y - 1][cur.x])
	{
		next.y = cur.y - 1;
		next.x = cur.x;
		_map[cur.y][cur.x] = '2';
	}
	//朝右走
	else if ('1' == _map[cur.y][cur.x + 1])
	{
		next.y = cur.y;
		next.x = cur.x + 1;
		_map[cur.y][cur.x] = '2';	
	}
	//朝后走
	else if ('1' == _map[cur.y + 1][cur.x])
	{
		next.y = cur.y + 1;
		next.x = cur.x;
		_map[cur.y][cur.x] = '2';	
	}
	//回退
	else if ('2' == _map[_pre.y][_pre.x])	//2:旧路
	{
		next = _pre;
		_map[cur.y][cur.x] ='3';		//3:走过不通
	}
	else
	{
		return in;	
	}
	return play(cur, next);
}

int main()
{
	FILE *map = fopen("./map.txt", "r");
	maze mz(map);
	mz.print();

	addr ret = mz.play(mz.in, mz.in);

	std::cout << "out: " << ret.y << "," << ret.x << std::endl;

	return 0;
}
