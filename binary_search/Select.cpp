/*
 *@Author: Daniel Wang
 *@Date: 2022-04-28 10:14:02
 *@Description: 在n个元素的数组中查找第k小的元素
 (1) 当规模小于阈值时，直接用排序算法返回结果。

(2) 当n大于阈值时，把n个元素划分为5个元素一组的n/5组，排除剩余元素（不会有影响，这里只是为了求中项mm），分别排序，然后挑出每一组元素的中间值，再在所有的中间值中，递归调用本算法，挑出中间值mm。

(3) 把元素划分为A1、A2、A3三组，分别包含小于、等于、大于mm的元素。

(4)分三种情况：

若A1的元素数量大于等于K，即第K个元素在第一组内：在A1中递归查找第k小元素。

若A1、A2元素个数之和大于等于K，即中项mm为第K个元素：返回mm

否则，第K个元素在第三组：在A3中递归寻找第（k-|A1、A2元素数量之和|）小元素。
*/

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
