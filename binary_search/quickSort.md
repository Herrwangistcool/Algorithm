# 快速排序

## 算法简介
排序算法的思想非常简单，在待排序的数列中，我们首先要找一个数字作为基准数（这只是个专用名词）。为了方便，我们一般选择第 1 个数字作为基准数（其实选择第几个并没有关系）。接下来我们需要把这个待排序的数列中小于基准数的元素移动到待排序的数列的左边，把大于基准数的元素移动到待排序的数列的右边。这时，左右两个分区的元素就相对有序了；接着把两个分区的元素分别按照上面两种方法继续对每个分区找出基准数，然后移动，直到各个分区只有一个数时为止。

## 算法步骤拆分
1. 设定比较基准  
   ```C++
   //将排序开始时的位置赋给i，将排序终止位置赋给j
    int i=l, j=r;
    int key=l;  //key指向初始位置，用于作为第一个比较基准
   ```
2. 从数列右边开始找比基准数小的，从左边找比基准数大的，并交换位置     
   ```C++
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
   ```
3. 分别对基准前和基准后的数列进行排序
   ```C++
   //以此时的a[i]为分界线，前面的一定比a[i]小，后面的一定比a[i]大
    swap(num[key],num[i]);
    // 递归调用QuickSort分别给a[i]前后a[i]后的数组排序
    QuickSort(num,l,i-1);
    QuickSort(num,i+1,r);
   ```

## 复杂度分析
如果每次划分得到的子问题大小都相等，即每个子问题的规模都等于n/2，那么在这个实例下时间复杂度函数的递推方程是：  
$$
\begin{cases}
    T(n)=2T(\frac{n}{2})+O(n) \\
    T(1)=0
\end{cases}
$$
根据主定理，该方程的解是T(n)=O(nlogn)  
考虑一种极端不均衡的情况，即划分后两个子问题的规模一个是0，另一个是n-1的情况。当输入是从小到大正序排列，或者是从大到小逆序排列时就会呈现这种分布，这时的时间复杂度递推方程是：  
$$
\begin{cases}
    T(n)=T(n-1)+O(n) \\
    T(1)=0
\end{cases}
$$
根据迭代归纳，得到它的解为$T(n^2)$，这对应了快速排序的最坏情况，即$W(n)=O(n^2)$

## 完整代码：
```C++
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
```