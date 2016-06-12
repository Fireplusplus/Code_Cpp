/* 
 * 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，
 * 他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
 * 对于其中重复的数字，只保留一个，把其余相同的数去掉，
 * 不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，
 * 按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
 * 注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。
 * 输入描述:		     
 * 输入多行，先输入随机整数的个数，再输入相应个数的整数
 * 输出描述:		     	    
 * 返回多行，处理后的结果
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2)
{
    return *(int *)e1 - *(int *)e2;
}

void Sort(int arr[], int n)
{
    qsort(arr, n, sizeof(int), cmp);
    
    int small = 0, i;
    
    for (i = 1; i < n; i++)
    {
        if (arr[i] != arr[small])
        {
            small++;
            arr[small] = arr[i];
        }
    }
    for (i = 0; i <= small; i++)
    	printf("%d\n", arr[i]);
}


int main()
{
    int arr[1000];
    int n;
    
    scanf("%d", &n);
    
    int i = 0;
    while (i < n)
    	scanf("%d", &arr[i++]);
    
    Sort(arr, n);
    
    return 0;
}
