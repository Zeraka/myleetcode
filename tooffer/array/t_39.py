import os
import string


class mylib:
    def MoreThanHalfNum(this, num):
        lookup={}
        print(num)
        n= len(num)
        res=0
        for i in range(n):#First make every key's value become 0
            lookup[str(num[i])]=0

        for i in range(n):#
            lookup[str(num[i])] = lookup[str(num[i])] + 1

        print(lookup)
        for v in lookup.values():
            if v > res:
                res = v
        return res


num=[1,2,3,2,2,2,5,4,2]
ml =mylib()
print("saf")
print(ml.MoreThanHalfNum(num))