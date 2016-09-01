/*
 * 写一段代码，判断一个包括'{','[','(',')',']','}'的表达式是否合法
 * 给定一个表达式A,请返回一个bool值，代表它是否合法。
 */

class ChkExpression
{
public:
	bool chkLegal(string A)
	{
		// write code here
		stack<char> s;
		const char *cur = A.c_str();

		while (*cur)
		{
			if (*(cur + 1) != '\0')
			{
				if (IsSig(*cur) && IsSig(*(cur + 1)))
					return false;
			}

			if (*cur == '[' || *cur == '(' || *cur == '{')
				s.push(*cur);
			else if (*cur == ']' || *cur == ')' || *cur == '}')
			{
				if (!s.empty())
				{
					if (*cur == s.top())
						s.pop();
					else
						return false;
				}
				else
					return false;
			}
			cur++;
		}
		if (s.empty())
			return true;
		else
			return false;
	}

	bool IsSig(char ch)
	{
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			return true;
		return false;
	}
};