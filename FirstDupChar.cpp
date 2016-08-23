/*
 * 对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
 * 给定一个字符串(不一定全为字母)A及它的长度n。
 * 请返回第一个重复出现的字符。保证字符串中有重复字符，
 * 字符串的长度小于等于500。
 */

class FirstRepeat 
{
public:
    char findFirstRepeat(string A, int n) 
    {
        // write code here
        char cnt[256];
        memset(cnt, '\0', sizeof(cnt));
        int i = 0;
        for (; i < n; i++)
        {
            cnt[A[i]]++;          
        }
        
        for (i = 0; i < n; i++)
        {
            if (cnt[A[i]] > 1)
            	return A[i];
        }
        return 0;
    }
};
