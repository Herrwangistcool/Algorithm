/* ************************************************************************
> File Name:     present.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Sat Mar 12 23:27:58 2022
> Description:   JiaoShou在爱琳大陆的旅行完毕，即将回家，为了纪念这次旅行，他决定带回一些礼物给好朋友。
             　　在走出了怪物森林以后，JiaoShou看到了排成一排的N个石子。
　　             这些石子很漂亮，JiaoShou决定以此为礼物。
　　             但是这N个石子被施加了一种特殊的魔法。
             　　如果要取走石子，必须按照以下的规则去取。
             　　每次必须取连续的2*K个石子，并且满足前K个石子的重量和小于等于S，后K个石子的重量和小于等于S。
             　　由于时间紧迫，Jiaoshou只能取一次。
             　　现在JiaoShou找到了聪明的你，问他最多可以带走多少个石子。 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    vector<int> arr;
    int N,S;
    cin>>N>>S;
    int tmp=0;
    int k=N/2;
    int record;
    for(int i=0; i<N; i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    for(; k>=0; k--){
        for(int i=k; i<N-k; i++){
            if(accumulate(arr.begin()+i-k, arr.begin()+i, 0)<=S && accumulate(arr.begin()+i+1, arr.begin()+i+k+1, 0)<=S){
                record=k;
                cout<<record*2<<endl;
                return 0;
            }
        }
    }
    return 0;
}
