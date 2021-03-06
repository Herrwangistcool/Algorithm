# 算法
用于记录常用算法
# 算法分析基础

## 算法分析框架
### 分析什么？
- 算法消耗的时间（时间复杂度或时间效率）
- 算法消耗的空间（空间复杂度或空间效率）
- 其他因素(误差、算法的简单性和一般性等)
---
输入规模的度量(Input Size)
- 算法能够处理的输入数据单元的数量
- 输入数据单元是算法能够处理的基本单元
- 输入数据单元不一定是存储单元
- 例：数组、图、矩阵和素数筛选
  
输入规模的度量所依赖的参数n是复杂度函数f(n)的自变量

---
算法时间的度量
- 物理时间T(n):秒，分钟、小时、天、月和年。
- 理论时间C(n):Basic Operation的次数

Basic Operation: 算法中最耗时的操作，最重要的操作，对总的运行时间贡献最大的操作。例如：乘法，除法以及比较等。

---
算法空间的度量（空间复杂度或效率）
- 除输入数据以外所消耗的空间
- 物理空间S(n):比特，字节等。
- 理论空间C(n):数据逻辑单元的数量（与输入数据规模的度量方式一样）

$S(n)≈C_{sp}C(n)，其中C_{sp}$是一个与本地计算机有关的常数

---
增长量级
- 表示一类函数的增长趋势
- 常见的增长量级

增长量级乘以常数，增长量级不变

---
算法的最优、最差和平均效率
- $C_{avg}(n)=\frac{p(n+1)}{2}+n(1-P)$，P是查找成功的概率
---

### 渐进符号与基本复杂度类型

假设某问题存在两种算法$A_1$和$A_2$,他们的复杂度分别是$f_1(n)和f_2(n)$；
渐进关系；
- 如果$f_1(n)比f_2(n)$增长的快，那么算法$A_2比A_1$好
- 如果$f_1(n)比f_2(n)$增长的慢，那么算法$A_1$比$A_2$好

渐进上界记号O
- $O(g(n))={t(n) | 存在正常数c和n_0, 使得对所有n\geq n_0,有0\leq t(n)\leq cg(n)}$

非紧确渐近上界记号o
- $o(g(n))={t(n) | 对任意正常数c，存在n_0,使得对所有n\geq n_0, 有0\leq t(n) < cg(n)}$

渐近下界记号Ω

非紧确渐近下界记号$\omega$


渐近紧界记号$\Theta$


---
## 非递归和递归算法的复杂度分析

### 主定理
设a>=1,b>1为常数，f(n)为函数，T(n)为非负整数，且T(n)=aT(n/b)+f(n)  
则有以下结果：  


## 算法的经验分析和可视化分析