/*
 *@Author: Daniel Wang
 *@Date: 2022-05-12 02:46:37
 *@Description: 快速排序的工作原理是通过 分治 的方式来将一个数组排序。

快速排序分为三个过程：

将数列划分为两部分（要求保证相对大小关系）；
递归到两个子序列中分别进行快速排序；
不用合并，因为此时数列已经完全有序。
*/

#include<bits/stdc++.h>
using namespace std;
int num[10010];

void QuickSort(int num[], int l, int r){
    if(l>=r){
        //确保开始位置在终止位置之前
        return;
    }
    //将排序开始时的位置赋给i，将排序终止位置赋给j
    int i=l, j=r;
    int key=l;  //key指向初始位置，用于作为第一个比较基准
    while(j>i){
        while(j>i && num[j]>=num[key]){
            j--;    //从末尾开始向前比较
        }
        while(j>i && num[i]<=num[key]){
            i++;    //从开头向后比较
        }
        //交换此时i和j的位置
        swap(num[i],num[j]);
    }
    //以此时的a[i]为分界线，前面的一定比a[i]小，后面的一定比a[i]大
    swap(num[key],num[i]);
    // 递归调用QuickSort分别给a[i]前后a[i]后的数组排序
    QuickSort(num,l,i-1);
    QuickSort(num,i+1,r);
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0; i<n; i++){
            cin>>num[i];
        }
        QuickSort(num,0,n-1);
        for(int i=0; i<n; i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}