/*
 *@Author: Daniel Wang
 *@Date: 2022-05-11 00:06:09
 *@Description: 锦标赛排序（英文：Tournament sort），又被称为树形选择排序，是 选择排序 的优化版本，堆排序 的一种变体（均采用完全二叉树）。它在选择排序的基础上使用优先队列查找下一个该选择的元素。
 参考链接：https://oi-wiki.org/basic/tournament-sort/
 代码参考链接：https://blog.csdn.net/weixin_44766422/article/details/122235108
*/

using namespace std;
#include<iostream>
 
void pk(int* a, int* b, int bLen, int index, int max)
{
	int left = index * 2;
	int right = index * 2 + 1;
 
	//在满二叉树中迭代地寻找与最大数比较过的数
 
	//当找到存放最大数序号的叶子节点时将其改写为-1
	if (left > bLen || right > bLen)
	{
		b[index - 1] = -1;
		return;
	}
 
	//如果左儿子是最大数则继续递归左儿子，反之递归右儿子
	if (b[left - 1] == max)
	{
		pk(a, b, bLen, left, max);
	}
	else
	{
		pk(a, b, bLen, right, max);
	}
 
	if (a[b[left - 1] - 1] > a[b[right - 1] - 1])
	{
		b[index - 1] = b[left - 1];
	}
	else
	{
		b[index - 1] = b[right - 1];
	}
}
 
int findSecond(int a[], int n)
{
	int x = 1;
	while (x < n)
	{
		x = x << 1;
	}
	int* b = new int[2 * x - 1];
 
	//将b数组中后x个元素装入1到n的标号
	for (int i = 0; i < x; i++)
	{
		if (i < n)
		{
			b[x - 1 + i] = i+1;
		}
		else
		{
			b[x - 1 + i] = -1;
		}
	}
 
	for (int i = 2 * x - 2; i > 0; i-=2)
	{
		if (b[i] < 0)
		{
			if (b[i - 1] >= 0)
			{
				b[(i - 1) / 2] = b[i - 1];
			}
			else
			{
				b[(i - 1) / 2] = -1;
			}
		}
		else
		{
			if (a[b[i] - 1] > a[b[i - 1] - 1])
			{
				b[(i - 1) / 2] = b[i];
			}
			else
			{
				b[(i - 1) / 2] = b[i - 1];
			}
		}
	}
 
	pk(a, b, 2 * x - 1, 1, b[0]);
 
	int second = a[b[0] - 1];
	delete[]b;
 
	return second;
}
 
int main(void)
{
	int a[5] = { 1,8,22,15,3 };
	cout << findSecond(a, 5);
}
