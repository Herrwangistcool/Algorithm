# 二分查找
### 二分搜索例子  
输入：排好序数组T，数x  
输出：j //如果x在T中，j为下标，否则为0
```
l<-1;r<-n
while l<=r do
    m<-(l+r)/2
    if T[m]=x then return m //x恰好等于中位元素
    else if T[m]>x then r<-m-1
        else l<-m+1
return 0
```
### 时间复杂度分析
二分检索最坏情况下的时间复杂度W(n)满足  
> W(n)=W(n/2)+1  
> W(1)=1  

可以解出W(n)=logn+1  

二分归并排序最坏情况下时间复杂度W(n)满足  
> W(n)=2W(n/2)+n-1  
> W(1)=0  

可以解出W(n)=nlogn-n+1

## 分支算法的一般性描述
分治算法Divide-and-Conquer(P)
1. if |P|<=c then S(P)
2. divide P into P1,P2...Pk
3. for i<-1 to k
4. &nbsp;&nbsp;&nbsp;&nbsp;yi<-Divide-and-Conquer(Pi)
5. return Merge(y1,y2,...yk)

时间复杂度递推方程  
W(n)=W(|P1|)+W(|P2|)+...W(|Pn|)

### 幂乘计算  
问题：设a是给定实数，计算$a^n$,n为自然数  
分治法  
$$
    a^n =
    \begin{cases}
    a^{n/2}*a^{n/2},  & \text{n为偶数} \\
    a^{n-1/2}*a^{n-1/2}*a, & \text{n为奇数}
    \end{cases}
$$

### 改进分治算法的途径  
通过代数变换，减少子问题的个数  
位乘问题  大质数相乘  


$$ 
\begin{pmatrix} A_{11} & A_{12} \\ A_{21} & A_{22} \\ \end{pmatrix} 
$$

