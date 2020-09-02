/*
就是在n-1的位置中找0~n-1的数字，会不会有一个比较好的
本题就是考察二分查找法的灵活运用

因为是从0开始的，所以，在遇到缺失的那个数之前，下标和值是一一对应的
只要找到第一个不同的数，则该数必然是缺失的数字，

因此我们用二分查找法，
下标和内容都二分， 分别得到m1和m2,  如果m1,m2相等，则表明该数在后面
    则二分下一步，得到
如果不等，则代表该中位数之前就已经发生了错位，所以要再前一部分进行二分。

如何找到第一个不等的数字呢？
第一个不等的数字的前一个，恰好下标和值就相等，因此，只要碰到不等的，就这样比较一下，
直到碰到相等的，
这里的条件就是，用
不过二分查找并不一定非要递归
二分查找要注意的是边界条件，比如mid == 0 或者mid == length 这类，这个一定要注意的

*/
int findLostnum(const int *numbers, int length)
{

    if (numbers == nullptr || length <= 0)
        return -1;
    int begin = 0;
    int end = length - 1;
    int mid = (begin + end) / 2;

    while (begin <= end)
    {
        if (mid == numbers[mid])
        {
            begin = mid + 1;
            mid = (begin + end) / 2;
        }else{
            if(mid == 0 || mid - 1 == numbers[mid -1 ]){//
                return mid;
            }
            else{
                end = mid - 1;
            }
        }
    }

    if(begin == length)
    {
        return length;//这是啥意思？？ 
    }
    return -1; //没找到，说明没有
}
