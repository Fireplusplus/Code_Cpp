/*
 * 现在有一个城市销售经理，需要从公司出发，去拜访市内的商家，
 * 已知他的位置以及商家的位置，但是由于城市道路交通的原因，
 * 他只能在左右中选择一个方向，在上下中选择一个方向，
 * 现在问他有多少种方案到达商家地址。
 * 给定一个地图map及它的长宽n和m，其中1代表经理位置，2代表商家位置，
 * -1代表不能经过的地区，0代表可以经过的地区，请返回方案数，
 * 保证一定存在合法路径。保证矩阵的长宽都小于等于10。
 */

class Visit 
{
public:
    int countPath(vector<vector<int> > map, int n, int m) 
    {
        // write code here
        int startx = -1, starty = -1;
        int endx = -1, endy = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1)
                {
                    startx = i;
                    starty = j;
                }
                if (map[i][j] == 2)
                {
                    endx = i;
                    endy = j;
                }
            }
            if (startx != -1 && endx != -1)
                break;
        }
        
        int diffx = startx > endx ? -1 : 1;
        int diffy = starty > endy ? -1 : 1;
        for (int i = startx + diffx; i != endx + diffx; i += diffx)
        	map[i][starty] = map[i][starty] == -1 ? 0 : map[i - diffx][starty];
        for (int i = starty + diffy; i != diffy + endy; i += diffy)
        	map[startx][i] = map[startx][i] == -1 ? 0 : map[startx][i - diffy];
        
        for (int i = startx + diffx; i != endx + diffx; i += diffx)
        {
            for (int j = starty + diffy; j != endy + diffy; j += diffy)
            {
                map[i][j] = map[i][j] == -1 ? 0 : map[i][j - diffy] + map[i - diffx][j];       
            }
        }
        
        return map[endx][endy];
    }
};
