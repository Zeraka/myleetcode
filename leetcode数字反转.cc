/*
字符串反转是通过双指针，而数字反转通过栈。
要注意的是数字反转可能存在溢出问题，溢出是考察的重点。
如果防止溢出呢？
只要比INT_MAX大就会溢出
只要比-INT_MAX小就会溢出。
但是问题在于，如何判断比INT_MAX要大？ 直接判断是不可能的
但是INT_MAX/10还是可以的
INT_MAX是多少2147483647, 所以 INT_MAX/10 是2147483647

res如果是 直接在高位就大于INT_MAX/10，则res最终一定溢出
而res == INT_MAX的时候，res = res*10 + pop的时候 仍有可能会溢出，因为res
*/
class Solution{
    public:
    int reverse(int x)
    {
        int rev = 0;

        while(x)
        {
            int pop = x % 10;
            x /= 10;

            //现在防止溢出。
            if(res > INT_MAX/10 || res == INT_MAX && pop > 7)  return 0;
            if(res < INT_MIN/10 || res == INT_MIN && pop < -8)  return 0;
            rev = rev*10 + pop;
        }
    }
};

class Solution2{
    public:
    int reverse(int x){
        int res;
        while(x)
        {
            int pop = x%10;
            x /=10;

            if(res > INT_MAX/10 || (res == INT_MAX && pop > 7)) return 0;
            if(res < INT_MIN/10 ||(res == INT_MIN && pop < -8)) return 0;
            res =res*10+pop;
        }
    }
};