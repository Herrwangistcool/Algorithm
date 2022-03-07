"'---Title:     第10002个素数---------------'"
"'---Author:    Daniel Wang-----------------'"
"'---Mail:      herrwangistcool@foxmail.com-'"
"'---Desp:      from the begin_number find a'"
"'--------------Prime_number----------------'"

class Prime_num:
    def __init__(self, begin=3, index=100):
        #begin为起始数字，index为第几个素数，即begin后素数的序号
        self.begin=begin
        self.index=index

    def Prime_Generate(self):
        count=1
        tmp=self.begin  #初始化
        while count<self.index:
            right_edge=int(tmp**0.5)
            #将循环的右边缘设为每次要判断的数的开方，因为如果该数不是素数，则必然有一个因数是小于等于其开方的
            for i in range(2, right_edge+1):
                if tmp%i==0:
                #判断是否有因子
                    break
            else:
                count+=1
                if count==self.index:
                    print(tmp)
            tmp+=2    #每次加2，因为偶数肯定不是质数


result=Prime_num(3,10002)
result.Prime_Generate()


