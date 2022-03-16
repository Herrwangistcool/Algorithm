/* ************************************************************************
> File Name:     heap.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Tue Mar 15 23:43:49 2022
> Description:   Basic usage of heap   
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_heap(vector<int> &v){
    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> example={
        10,30,22,6,15,9
    };

    //建立小顶堆
    make_heap(example.begin(), example.end(), greater<int>());
    print_heap(example);

    //建立大顶堆
    make_heap(example.begin(), example.end(), less<int>());
    print_heap(example);
    return 0;
}
