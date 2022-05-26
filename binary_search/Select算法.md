# Select算法
- [Select算法](#select算法)
  - [一、问题描述](#一问题描述)
  - [二、算法思路](#二算法思路)
  - [三、算法步骤分解](#三算法步骤分解)
    - [1. 排序部分](#1-排序部分)
    - [2. 分治法求m*](#2-分治法求m)
  - [四、复杂度分析](#四复杂度分析)
  - [附：完整程序](#附完整程序)

---
## 一、问题描述
给出一组数，选第k小的数  
  
---
## 二、算法思路
> 以S中的某个元素m* 作为标准将S划分成两个子数组S1和S2，其中S1中的元素比m* 小，  
> S2中的元素比m* 大。这样如果k小于等于S1的元素个数 就在S1中找第k小，如果k=S1中元素个数加1 ，  
> 那m* 就是要找的数，如果k大于S1中元素个数加1，说明k在S2中，要在S2中找第(k-S1中元素个数-1)个数  


> 采用分治法找m*，将数组S分组，5个元素一组，共分成[n/5]组。在每组中寻找本组的中位数，  
> 然后将这些中位数放到一个集合M中，最后在M中调用选择算法选出一个M的中位数，即我们要找的m*
  
---
## 三、算法步骤分解

### 1. 排序部分
算法中寻找中位数需要排序，这里采用了归并排序来完成这一工作，具体代码如下：  
```C++
void merge(int a[], int left, int mid, int right){
    int i,k;
    // 开一个临时数组，用来存放排序后的数组
    int *tmp=(int *)malloc((right-left+1)*sizeof(int));
    // 把数组一分为二，左边为[left1,left2]，右边为[right1,right2]
    int left1=left;
    int left2=mid;
    int right1=mid+1;
    int right2=right;
    // 开始排序，直到其中一个数组到达边界
    for(k=0; left1<=left2 && right1<=right2;k++){
        // 左右两边分别丛头开始比较，哪个小，就把哪个放入临时数组
        if(a[left1]<=a[right1]){
            // 比较完一次，当前指针后移
            tmp[k]=a[left1++];
        }else{
            tmp[k]=a[right1++];
        }
    }
    // 如果左边还有元素，则将左边的元素全部插入到临时数组中
    if(left1<=left2){
        for(i=left1; i<=left2; i++){
            tmp[k++]=a[i];
        }
    }
    // 同理，如果右边还有元素，则将右边剩下的元素全部插入到临时数组中
    if(right1<=right2){
        for(i=right1;i<=right2;i++){
            tmp[k++]=a[i];
        }
    }
    // 将临时数组的数据赋给a
    for(i=0; i<right-left; i++){
        a[left+i]=tmp[i];
    }
    free(tmp);
    return;
}

void merge_sort(int a[], int begin, int end){
    int mid;
    if(begin<end){
        // 递归调用归并排序
        mid=(end+begin)/2;
        merge_sort(a,begin,mid);
        merge_sort(a,mid+1,end);
        merge(a,begin,mid,end);
    }
    return;
}
```
另外说明一下，虽然归并排序的思想比较容易理解，但实际从头写起的话还是很耗费时间，我这里的代码也是参考了别人的贴子。

### 2. 分治法求m*
- 将数组划分成5个一组，每组中位数存入中位数数组m里
 ```C++
 int s=n/5;  //5个数一组，共s组
 int *m=new int[s];  //中位数数组
 for(i=0; i<s; i++){
   merge_sort(a,left+i*5,left+i*5+5-1);    //5个分为一组进行排序
    m[i]=a[left+i*5+2]; //每组中位数存入中位数数组m里
}
 ```

 - 中位数数组排序，选出数组m中的中位数mid
```C++
merge_sort(m,0,i-1);    //将中位数数组进行排序
int mid=m[i/2];
```

- 创建3个数组，分别存放比mid小的，和mid相等的，比mid大的
```C++
/*创建3个数组，并定义他们的初始下标num1,num2,num3*/
int *a1=new int[n];
int *a2=new int[n];
int *a3=new int[n];
int num1=0, num2=0, num3=0;

/*分别与mid比较，确定放入哪个数组*/
for(int i=left; i<right; i++){
    if(a[i]<mid){
        a1[num1++]=a[i];
    }else if(a[i]==mid){
        a2[num2++]=a[i];
    }else{
        a3[num3++]=a[i];
    }
}
```

- 将k与上面三个数组中的元素个数进行比较，确定子问题的范围
```C++
if(num1>=k){
    // 若第k小于num1，说明k值在num1中，继续递归select
    return select(a1,0,num1,k);
}
if(num1+num2>=k){
    // 若k在num1和num1+num2之间，k值只可能刚好是mid
    return mid;
}else{
    // 当k大于num1+num2说明，此时的子问题转变成了在S2中找第(k-S1中元素个数-1)个数
    return select(a3,0,num3,k-num1-num2);
}
```

---
## 四、复杂度分析
- 假设n是5的倍数，且n/5是奇数，即n/5=2r+1，于是得到|A|+|D|=2r，|B|=|C|=3r+2, n=10r+5   
  注此处的|A|,|B|,|C|,|D|指的是被m*分隔开的四个区域
- 如果A和D的元素都小于m* ，那么它们的元素都加入到S1中，且下一步算法又在这个最大的子问题上进行递归调用，  
  这对应了归约后子问题规模的上限，正好是算法时间复杂度分析的最坏情况。此时的子问题大小是  
  |A|+|D|+|C|=7r+2=$\frac{7(n-5)}{10}$+2=$\frac{7n}{10}$-1.5<$\frac{7n}{10}$
- 上述式子表明问题规模不超过原问题规模的7/10.根据这个关系可以推出最坏情况下的时间复杂度递推式  
  $W(n)\leq W(\frac{n}{5})+W(\frac{7n}{10})+tn$
- 方程右边的第一项是算法递归调用找m* 的时间，此时子问题的规模是n/5，第二项是递归求解子问题的代价，  
  而子问题的最大规模不超过7n/10，剩下的tn是算法在构造m数组和跟mid比较大小的时间，这里的t是某个常数。
- 根据该方程的递归树，得到
  $W(n)\leq tn+0.9tn+0.9^{0.2}tn+...=tn(1+0.9+0.9^{0.2}+...)=O(n)$  
  注：该递归方程树见算法设计与分析(屈婉玲等编著 第二版)第44页的图2.6


---
## 附：完整程序
以下是完整的代码，也可以在文件夹中找到名为merge_sort.cpp的文件，里面也有源码
```C++
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int i,k;
    // 开一个临时数组，用来存放排序后的数组
    int *tmp=(int *)malloc((right-left+1)*sizeof(int));
    // 把数组一分为二，左边为[left1,left2]，右边为[right1,right2]
    int left1=left;
    int left2=mid;
    int right1=mid+1;
    int right2=right;
    // 开始排序，直到其中一个数组到达边界
    for(k=0; left1<=left2 && right1<=right2;k++){
        // 左右两边分别丛头开始比较，哪个小，就把哪个放入临时数组
        if(a[left1]<=a[right1]){
            // 比较完一次，当前指针后移
            tmp[k]=a[left1++];
        }else{
            tmp[k]=a[right1++];
        }
    }
    // 如果左边还有元素，则将左边的元素全部插入到临时数组中
    if(left1<=left2){
        for(i=left1; i<=left2; i++){
            tmp[k++]=a[i];
        }
    }
    // 同理，如果右边还有元素，则将右边剩下的元素全部插入到临时数组中
    if(right1<=right2){
        for(i=right1;i<=right2;i++){
            tmp[k++]=a[i];
        }
    }
    // 将临时数组的数据赋给a
    for(i=0; i<right-left; i++){
        a[left+i]=tmp[i];
    }
    free(tmp);
    return;
}

void merge_sort(int a[], int begin, int end){
    int mid;
    if(begin<end){
        // 存疑
        mid=(end+begin)/2;
        merge_sort(a,begin,mid);
        merge_sort(a,mid+1,end);
        merge(a,begin,mid,end);
    }
    return;
}

int select(int a[], int left, int right, int k){
    int n=right-left;
    if(n<5){
        // 若少于5个不用分组直接二分归并后输出中位数
        merge_sort(a,left,right-1);
    }
    int i;
    int s=n/5;  //5个数一组，共s组
    int *m=new int[s];  //中位数数组
    for(i=0; i<s; i++){
        merge_sort(a,left+i*5,left+i*5+5-1);    //5个分为一组进行排序
        m[i]=a[left+i*5+2]; //每组中位数存入中位数数组m里
    }
    merge_sort(m,0,i-1);    //将中位数数组进行排序
    int mid=m[i/2];
    int *a1=new int[n];
    int *a2=new int[n];
    int *a3=new int[n];
    int num1=0, num2=0, num3=0;
    for(int i=left; i<right; i++){
        if(a[i]<mid){
            a1[num1++]=a[i];
        }else if(a[i]==mid){
            a2[num2++]=a[i];
        }else{
            a3[num3++]=a[i];
        }
    }
    if(num1>=k){
        // 若第k小于num1，说明k值在num1中，继续递归select
        return select(a1,0,num1,k);
    }
    if(num1+num2>=k){
        // 若k在num1和num1+num2之间，k值只可能刚好是mid
        return mid;
    }else{
        // 注意，因为前面已经占据了num1+num2值，所以在mid后面的值中找k值时要剪掉num1+num2个数
        return select(a3,0,num3,k-num1-num2);
    }
}

int main(){
    int n;
    int k;
    int a[1000];
    cout<<"输入数组大小: ";
    cin>>n;
    cout<<"输入数据: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"输入所求的第几个元素: ";
    cin>>k;
    cout<<"第"<<k<<"小元素: ";
    cout<<select(a,0,n,k)<<endl;
    return 0;
}
```