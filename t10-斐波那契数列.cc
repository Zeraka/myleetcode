/*
O(n)的解法，使用动态规划
*/

long long Fb(unsigned n){
    int result[2] = {0,1};
    if(n < 2)  return result[n];

    long long f_0 = 0;
    long long f_1 = 1;
    long long f_b = 0;

    for(int i = 0; i <= n; ++i){
        f_b = f_0 + f_1;
        f_0 = f_1;
        f_1 = f_b;
    }

    return f_b;

}