/*
二分查找法的代码会写吗

有两个函数，首先是找到第一个K，然后是找到最后一个K，
接着，
第一个k,找中间数m, 如果m大于K的话，说明找左边
如果m小于K的话，说明找右边。
而如果m == k的话，那就先找

两个递归函数，一个找第一个K，另一个找最后一个K,每个函数都要有开始位置和结束位置
FindFstK(int array[], int begin, int end, int k);
FindLstK(int array[], int begin, int end, int k);
其中每一个函数用二分法表示，

发现最后一个的思路也是如此，就是将，如果mid是最后一个则必然这个end就找道
如果mid < length 且

这个其实是分治，分治和递归其实有一些不同，因为这里到最后一步，其实是最后一次递归得到了边界的值
然后层层返回的。

在return处写上函数来递归，表明，最后一次递归得到的数，就是总体上需要的数。


*/
/*
int FindFsk(int array[], int length, int begin, int end, int k)
{
    if (begin > end)
        return -1;

    int mid = (end + begin) / 2;
    int midata = array[mid];

    if (midata > k)
    { //不用重复计算Mid，因为你是用递归的方法来计算
        end = mid - 1;
    }
    else if (midata < k)
    {
        begin = mid + 1;
    }
    else
    {
        //如果是等于，那就看这个k是不是第一个，如果是第一个，那就直接返回，如果不是第一个，那第一个必然在左侧。只要把end赋值为mid就可以了
        //这里的问题是，如果是开头，则必然是第一个，那么mid 为0， 如果是mid > 1且不为k的话，则说明也是第一个了
        if (mid == 0 || mid > 1 && array[mid - 1] != k)
        {
            return k;
        }
        else
        {
            end = mid - 1;
        }
    }

    return FindFsk(array, length, begin, end, k);
}

int FindLsk(int array[], int length, int begin, int end, int k)
{
    if (begin > end)
        return -1;

    int mid = (begin + end) / 2;
    int midata = array[mid];

    if (midata > k)
    {
        end = mid - 1;
    }
    else if (midata < k)
    {
        begin = mid + 1;
    }
    else
    {
        if(mid = length-1 || mid<length-1 && array[mid+1] != k)
        {
            return mid;
        }else{
            begin = mid + 1;
        }
    }

    return FindLsk(array, length, begin, end, k);
}

int GetNumbersOfK(int *data, int length, int k){
    int number = 0;

    if(data == nullptr && length >0){
        int first = FindFsk(data, length, 0, length -1, k);
        int last = FindLsk(data, length, 0, length-1, k);

        if(first > -1 && last > -1){
            number = last - first +1 ;
        }
    }

    return number;
}*/

int FindFsk(int *data, int length, int begin, int end, int k)
{
    if (begin > end)
        return -1;

    int mid = (begin + end) / 2;
    int midata = data[mid];

    if (midata < k)
    {
        begin = mid + 1;
    }
    else if (midata > k)
    {
        end = mid - 1;
    }
    else{
        if(mid = 0 || mid > 1 && data[mid-1]){
            return mid;
        }else{
            end = mid -1;
        }
    }

    return FindFsk(data, length, begin, end, k);
}

int FindLsk(int *data, int length, int begin, int end, int k){
    if(begin > end){
        return -1;
    }

    int mid = (begin + end)/2;
    int midata = data[mid];

    if(midata > k){
        end = mid -1;
    }else if(midata < k){
        begin = mid + 1;
    }else{
        if(mid = length-1 || mid < (length -1)&& data[mid+1] != k){
            return mid;
        }
        else{
            begin = mid +1;
        }
    }

    return FindLsk(data, length, begin, end, k);
}

int FindNumbersOfN(int *data, int length, int k){
    
    if(length < 0 || data == nullptr) return -1;

    int left = 0;
    int right = 0;

    int number = 0;

    left = FindFsk(data, length, 0, length-1, k);
    right = FindLsk(data, length,0, length-1, k);

    if(left > -1 && right > -1){
        number = left -right +1;
    }

    return number;

}