/*
数组中数值和下标相等的元素。
由于是递增数组。所以使用二分查找法是必然的
第一次查找，如果发现value大于index,由于value和index都是递增的，因此，右半部分必然不用看
如果value小于index，则左半部分也不用看
重复以上，直到找到value == index ，或者 是mid 结束.

本题有什么有意思的地方呢？ 
*/

int valueeqindex(int *data, int length,int left, int right){
    if(data == nullptr || length < 1 || left > right) return -1;

    int mid = (left + right)/2;

    while(left <= right){
        if(data[mid] > mid){
            right = mid - 1;
        }else if(data[mid] < mid){
            left = mid + 1;
        }else{
            return mid;
        }
        mid = (left+ right)/2;
    }

    return -1;

}