def FindGreatSumOfSubArray(list):
    Sum = 0
    MaxSum = 0
    i=0
    
    while i < len(list):
        Sum = list[i] + Sum
        if Sum > MaxSum :
            MaxSum = Sum
        if Sum < 0 :
            i=i+1
            Sum=0
            Sum=list[i]+Sum
        i= i+1
    return MaxSum

list=[1,-2,3,10,-4,7,2,-5]

print(FindGreatSumOfSubArray(list))