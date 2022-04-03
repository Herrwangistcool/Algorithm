/* ************************************************************************
> File Name:     娜神平衡_v2.cpp
> Author:        Daniel Wang
> mail:          herrwangistcool@foxmail.com
> Created Time:  Tue Mar 29 23:39:47 2022
> Description:   
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
vector<int> arr_A, arr_B;
int n, r, index_A, index_B;

bool check() {//判断每种情况是否符合题目
	int x = 0, y = 0, sumA = 0, sumB = 0;
	sumA = arr_A[x++];	//把A数组的第一位的值赋给sumA，也是输入数据中最小的值
	while (abs(sumA - sumB) <= r) {	//循环条件是A，B数组之和小于r
		// sumA加上A数组第二个元素的值后再减B数组的和小于r，并且当前索引小于数组A的长度
		if (abs(sumA + arr_A[x] - sumB) <= r && x + 1 <= index_A) {
			sumA = sumA + arr_A[x++];
		}else if (abs(sumA - arr_B[y] - sumB) <= r && y + 1 <= index_B) {
			sumB += arr_B[y++];
		}else{
            break;
        }
	}
	// 当while循环结束后，如果当前索引等于各自数组长度，说明符合条件，返回true
	if (x == index_A && y == index_B)
		return true;
	return false;
}
void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
	cin >> n >> r;
    int N[n];
	for (int i = 0; i < n; i++)
		cin >> N[i];
	// 保存输入的第一位
	int first = N[0];
	// 给输入数据排序
	sort(N, N + n);
	for (int i = 1; i < (1 << n) - 1; i++) {//除去两个不存在的情况
	// 把1向右移动n位，每一个二进制位用0和1代表当前在哪个数组
		index_A = index_B = 0;	//A和B数组的索引初始化
		for (int j = 0; j < n; j++) {
			// 判断每一个二进制位，如果是1就放到A数组，否则放到B数组
			if ((1 << j)&i){
                ++index_A;
				arr_A.push_back(N[j]);
            }else{
                ++index_B;
                arr_B.push_back(N[j]);
            }
		}
		if (check()) {//符合条件输出数组
			// 如果输入的第一位在数组A中，先输出数组A，否则先输出数组B
            if(find(arr_A.begin(), arr_A.end(), first)!=arr_A.end()){
                print(arr_A);
                print(arr_B);
            }else{
                print(arr_B);
                print(arr_A);
            }
			break;
		}
        arr_A.clear();
        arr_B.clear();
	}
	return 0;
}
