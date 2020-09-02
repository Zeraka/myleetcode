/*
和为s的数字，会有什么呢？
大小指针，分别从两处进行求和，既然是排好序的，那就不会有

本题的思路，就在于，左右指针分别进行扩展，
*/

void findnumbersinsum(int data[], int length, int *begin,int *end, int sum){
    if(data == nullptr || begin == nullptr || end == nullptr || length < 1) return ;

    begin = data;
    end = data + length -1;

    int left = 0;
    int right = length -1 ;

    
    while( left <= right){
        long long cursum = left + right;

        if (cursum == sum){
            //printf("%d + %d", data[left], data[right]);
            *begin = data[left];
            *end = data[right];
            break;
        }else if(cursum < sum){
            left++;
        }else{
            right++;
        }
    }
    return ;
}