/* ************************************************************************
> File Name:     hex_to_oct.cpp
> Author:        Daniel Wang
> Mail:          Herrwangistcool@foxmail.com
> Created Time:  Fri Mar 11 00:18:35 2022
> Description:   给定n个十六进制正整数，输出它们对应的八进制数。
                 输入的第一行为一个正整数n （1<=n<=10）。
                 接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。
                 难点在于没有合适的数据类型能放下100000长度的十六进制数，所以不能直接用格式输入与输出。
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

/*
    思路：由于输入的十六进制数太大，无法用int long等数据类型存储，所以只能以字符串的形式处理
    先将十六进制转换为二进制，每一位十六进制对应四位二进制。
    随后再将二进制形式的字符串转换为八进制，每三位二进制对应一位八进制。
    在十六进制转换为二进制过程中，如果最终的二进制字符串的位数不是3的倍数，需要在字符串前面补0
*/
string hex_to_oct(string hex_num){
    string bin_num; //存放二进制数字的字符串
    string oct_num; //存放八进制数字的字符串
    for(int i=0; i<hex_num.length(); i++){
        switch(hex_num[i]){
            case '0': bin_num+="0000"; break;
            case '1': bin_num+="0001"; break;
            case '2': bin_num+="0010"; break;
            case '3': bin_num+="0011"; break;
            case '4': bin_num+="0100"; break;
            case '5': bin_num+="0101"; break;
            case '6': bin_num+="0110"; break;
            case '7': bin_num+="0111"; break;
            case '8': bin_num+="1000"; break;
            case '9': bin_num+="1001"; break;
            case 'A': bin_num+="1010"; break;
            case 'B': bin_num+="1011"; break;
            case 'C': bin_num+="1100"; break;
            case 'D': bin_num+="1101"; break;
            case 'E': bin_num+="1110"; break;
            case 'F': bin_num+="1111"; break;
            default:break;
        }
    }

    //给二进制前面补0
    if(bin_num.length()%3==1) bin_num="00"+bin_num;
    if(bin_num.length()%3==2) bin_num="0"+bin_num;
    //如果前三位都是0的需要把0去掉
    if(bin_num.substr(0,3)=="000") bin_num=bin_num.substr(3);

    //二进制转换为八进制
    //从最高位开始，每隔三个字符进行一次转换
    for(int i=0; i<bin_num.length()-2; i+=3){
        //二进制转换为八进制公式：最高位*4+次高为*2+低位
        oct_num+=((bin_num[i]-'0')*4+(bin_num[i+1]-'0')*2+(bin_num[i+2]-'0'))+'0';
        //to_string是C++11支持的特性，蓝桥杯暂不支持，所以用上面的方法转换为字符串
        // oct_num+=to_string((bin_num[i]-'0')*4+(bin_num[i+1]-'0')*2+(bin_num[i+2]-'0'));
    }
    return oct_num;
}

int main(){
    int n;
    cin>>n;
    string hex_num;
    for(int i=0; i<n; i++){
        cin>>hex_num;
        cout<<hex_to_oct(hex_num)<<endl;
    }
    return 0;
}
