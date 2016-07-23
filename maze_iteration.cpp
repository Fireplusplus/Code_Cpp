#include <iostream>
#include <stdio.h>
#include <stack>

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

	addr next;
	
	std::stack<addr> s;
	s.push(_pre);
	s.push(_cur);

	while (!s.empty())
	{
		addr now = s.top();
		s.pop();
		addr pre = s.top();
		s.push(now);

		if ((0 == now.x || 9 == now.x || 0 == now.y || 9 == now.y) && (9 != now.y && 6 != now.x))
			return now;
	
		//朝左走
		if ('1' == _map[now.y][now.x - 1])	//1:通路
		{
			next.y = now.y;
			next.x = now.x - 1;
			_map[now.y][now.x] = '2';
		}
		//朝前走
		else if ('1' == _map[now.y - 1][now.x])
		{
			next.y = now.y - 1;
			next.x = now.x;
			_map[now.y][now.x] = '2';
		}
		//朝右走
		else if ('1' == _map[now.y][now.x + 1])
		{
			next.y = now.y;
			next.x = now.x + 1;
			_map[now.y][now.x] = '2';	
		}
		//朝后走
		else if ('1' == _map[now.y + 1][now.x])
		{
			next.y = now.y + 1;
			next.x = now.x;
			_map[now.y][now.x] = '2';	
		}
		//回退
		else if ('2' == _map[pre.y][pre.x])	//2:旧路
		{
			s.pop();
			next = s.top();
			s.pop();
			_map[now.y][now.x] ='3';		//3:走过不通
		}
		else
		{
			return in;			//不通	
		}
		s.push(next);
	}
	return in;
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
