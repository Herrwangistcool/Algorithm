import numpy as np
import matplotlib.pyplot as plt

PI=np.pi 
#设置三角函数列表
#正弦，余弦，正切，余切，正割，余割，反正弦，反余弦，反正切，反余切
tri_fun_name=['sin','cos','tan','cot','sec','csc','arcsin','arccos','arctan','arccot']
def cot(x):
    return 1/np.tan(x)
def sec(x):
    return 1/np.cos(x)
def csc(x):
    return 1/np.sin(x)
def arccot(x):
    return PI/2-np.arctan(x)

print('Enter a func you want to draw:\t\n')
#对于一个可迭代的（iterable）/可遍历的对象（如列表、字符串），enumerate将其组成一个索引序列，利用它可以同时获得索引和值
for index, item in enumerate(tri_fun_name, 1):
    print(index,":",'%-10s'%item,end='\t')
    if(index%5==0):
        print('\n')

#获取输入
selected=input()
selected=int(selected)
#设置一下文件名
file_name=tri_fun_name[selected-1]

#确定定义域,值域
if selected in [1,2,5,6]:
    x=np.arange(-PI, PI, 0.01)
    x_min=-PI
    x_max=PI
    y_min=-1
    y_max=1
    if selected in [5,6]:
        y_min=-10
        y_max=10
elif selected in [3,4]:
    x=np.arange(-PI/2, PI/2, 0.01)
    x_min=-PI/2
    x_max=PI/2
    y_min=-10
    y_max=10
elif selected in [7,8]:
    x=np.arange(-1, 1, 0.01)
    x_min=-1
    x_max=1
    y_min=-PI/2
    y_max=PI/2
    if selected==8:
        y_min=-PI
        y_max=PI
else:
    x=np.arange(-10, 10 ,0.01)
    x_min=-10
    x_max=10
    y_min=-PI
    y_max=PI

#确定y的值
tri_func=[np.sin,np.cos,np.tan,cot,sec,csc,np.arcsin,np.arccos,np.arctan,arccot]
y=tri_func[selected-1](x)

#改变坐标轴显示方法
ax=plt.gca()
#设置上边和右边无边框
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
#设置x坐标刻度数字或名称的位置
ax.xaxis.set_ticks_position('bottom')
#设置边框位置
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))
#设置标题
plt.title(file_name,fontweight='bold')

#确定绘图范围
plt.axis([x_min,x_max,y_min,y_max])
#设置绘图参数
plt.plot(x,y,color="r",linestyle="-",linewidth=1)

plt.show()

