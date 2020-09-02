/*
设计一个快速幂函数
quickMul
double quickMul(double x,long long N)
如果N为0，则返回1
如果N为奇数, 则 double cur = quickMul(x，N/2),cur*=cur;
如果N为偶数，则double cur = qucikMul(x,N/2)*quick,cur = cur*cur*x;
不过代码可以更加精炼一些，比如,将其变为 double y = quickMul(x,n/2),
然后直接 return (N % 2 == 1)?y*y*x:y*y;

对于这类奇偶判断，二选一的情况，三目运算符最适合。

myPow函数中判断正负号
如果是正数就 返回 quickMul(x,n)如果是负数就返回

此题关键是分离，核心的计算函数只取正幂，对负数的判断则使用外面一层进行。
*/
class Solution{
    public:
    double quickMul(double x, long long  n )
    {
        if(n == 0) return 1;

        double y = quickMul(x,n/2);
        return (n%2==1)?y*y*x:y*y;
    }

    double myPow(double x, long long n)
    {
        long long  N = n;
        return (N >=0)?quickMul(x,N):1.0/quickMul(x,-N);//使用double的目的就是强制类型转换，计算的时候要用
    }
};