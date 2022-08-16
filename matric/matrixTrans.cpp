/* ************************************************************************
> File Name:     matrixTrans.cpp
> Author:        Daniel Wang
> mail:          herrwangistcool@foxmail.com
> Created Time:  Tue Aug 16 21:00:06 2022
> Description:   
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
const int N = 100;

int main() {
    int a[N][N];
    int i, j, n;
    cin >> n;       // 输入
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++)
            swap(a[i][j], a[j][i]);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << setw(5) << a[i][j];     // 控制每个数据输出占5个字符宽度
        }
        cout << endl;
    }
    return 0;
}
