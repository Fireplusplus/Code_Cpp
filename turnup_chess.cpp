/*
 * 在4x4的棋盘上摆满了黑白棋子，黑白两色的位置和数目随机其中左上角坐标
 * 为(1,1),右下角坐标为(4,4),现在依次有一些翻转操作，要对一些给定支点
 * 坐标为中心的上下左右四个棋子的颜色进行翻转，请计算出翻转后的棋盘颜色。
 * 给定两个数组A和f,分别为初始棋盘和翻转位置。其中翻转位置共有3个。
 * 请返回翻转后的棋盘。
 */

class Flip 
{
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) 
    {
        // write code here
        for (int i = 0; i < f.size(); i++)
        {
            int x = f[i][0] - 1;
            int y = f[i][1] - 1;
                      
            // up
            if (x >= 0 && x < 4 && y-1 >= 0 && y-1 < 4)
                A[x][y-1] ^= 1;
            // down
            if (x >= 0 && x < 4 && y+1 >= 0 && y+1 < 4)
                A[x][y+1] ^= 1;
            // left
            if (x-1 >= 0 && x-1 < 4 && y >= 0 && y < 4)
                A[x-1][y] ^= 1;
            // right
            if (x+1 >= 0 && x+1 < 4 && y >= 0 && y < 4)
                A[x+1][y] ^= 1;
        }
        return A;
    }
};
