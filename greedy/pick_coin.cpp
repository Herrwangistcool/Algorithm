/* ************************************************************************
> File Name:     pick_coin.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Mon Mar 14 19:52:22 2022
> Description:   有一个N x N的方格,每一个格子都有一些金币,只要站在格子里就能拿到里面的金币。你站在最左上角的格子里,每次可以从一个格子走到它右边或下边的格子里。请问如何走才能拿到最多的金币。
                 输入格式第一行输入一个正整数n。
             　　以下n行描述该方格。金币数保证是不超过1000的正整数。
                 输出格式最多能拿金币数量。
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
void print_grids(vector<vector<int>>& grids);


int main(){
    cin>>n;
    vector< vector<int> > grids(n, vector<int>(n));
    vector< vector<int> > state(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grids[i][j];
            state[i][j]=-1;
        }
    }
    cout<<walk(grids, state,0,0)<<endl;
    return 0;
}


void print_grids(vector< vector<int> >& grids){
    for(int i=0; i<grids.size(); i++){
        for(int j=0; j<grids[i].size(); j++){
            cout<<grids[i][j];
        }
        cout<<"\n";
    }
}
