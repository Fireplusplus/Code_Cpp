/*
 * 扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。
 * 牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
 * 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
 * 输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
 * 请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR
 * 基本规则：
 * （1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，
 *　由输入保证两手牌都是合法的，顺子已经从小到大排列；
 * （2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），
 ＊　不考虑拆牌情况（如：将对子拆分成个子）
 * （3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，
 ＊　炸弹之间比较牌面大小；对王是最大的牌；
 * （4）输入的两手牌不会出现相等的情况。
 * 答案提示：
 * （1）除了炸弹和对王之外，其他必须同类型比较。
 * （2）输入已经保证合法性，不用检查输入是否是合法的牌。
 * （3）输入的顺子已经经过从小到大排序，因此不用再排序了.
 * 输入描述:
 * 输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
 * 输出描述:
 * 输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <strings.h>

using namespace std;

int num(const char *buf)
{
	if (buf[1] != '\0')
	{
		if (buf[1] == '0' && *buf == '1')
			return 10;
	}
	if (*buf == 'J')
		return 11;
	else if (*buf == 'Q')
		return 12;
	else if (*buf == 'K')
		return 13;
	else if (*buf == 'A')
		return 14;
	else if (*buf == '2')
		return 15;
	else if (*buf == 'j' || *buf == 'J')
		return 16;
	else
		return *buf - '0';
}

int judge_num(const char *buf)
{
	const char *str = buf;
	// 个子
	// 3~16
	int len = strlen(buf);
	if ((len == 5 && (strcasecmp(buf, "joker") == 0)) ||
		(len == 1) ||
		(*buf == '1' && buf[1] == '0')
		)
	{
		return num(buf);
	}

	// 对子
	// 23~35
	if (len == 3 || (len == 5 && buf[0] == '1' && buf[1] == '0'))
		return num(buf) + 20;

	// 三个
	// 53~55
	if (len == 5 || (len == 8 && buf[0] == '1' && buf[1] == '0'))
		return num(buf) + 50;

	// 顺子
	// 103~115
	if (len >= 9 && (strcasecmp(buf, "joker joker") != 0))
		return num(buf) + 100;

	// 炸弹
	// 503~1000
	return num(buf) + 500;

	// 对王
	return 1000;
}

bool IsIn(int left, int right)
{
	if (left < 20 && right < 20)
		return true;
	if (left < 50 && right < 50)
		return true;
	if (left < 100 && right < 100)
		return true;
	if (left < 500 && right < 500)
		return true;
	if (left > 500 || right > 500)
		return true;
	return false;
}


void call()
{
	char buf1[15];
	char buf2[15];
	memset(buf1, '\0', 15);
	memset(buf2, '\0', 15);
	int index1 = 0;
	int index2 = 0;
	int ch;
	bool flag = true;
	while ((ch = getchar()) != '\n')
	{
		if (ch == '-')
		{
			flag = false;
			continue;
		}
		if (flag)
			buf1[index1++] = ch;
		else
			buf2[index2++] = ch;
	}

	int left = judge_num(buf1);
	int right = judge_num(buf2);

	if (IsIn(left, right))
	{
		if (left > right)
			printf("%s\n", buf1);
		else
			printf("%s\n", buf2);
	}
	else
		printf("ERROR\n");
}

int main()
{
	call();

	return 0;
}