/*
输入一个正数s，

总体思路是什么？ 
总体思路就是用
由于是正数序列，已经排好序了，
就是用滑动窗口法来解决，使用滑动窗口法，小于s时，就扩大右侧，大于s时就减小左侧，直到左右相等？ 
不用直到左右相等，只要左侧大于某个数就可以，这个数由s得到，
即s+1/2,因为处  如果 left = （s + 1）/2, 
则，2left = s + 1, left + left = s + 1,  故left + right > s
因此，left 只要小于 s+1的二分之一即可。
因此只需要两个函数。
*/
/*
void Findsqueue(int sum){
    
    if(sum <3 ) return ;//因为至少含有两个数，因此，不会有


    int left = 1;
    int right =2;
    int mid = (sum+1)/2;

    int cursum = left + right;//由于每次只会增加或者减少一个数，因此，不会有

    while(left < mid){
        if(cursum < sum)
        {//因为滑动是都向右边滑动，右侧滑动会导致增大，左侧滑动会导致和减小。
            right++;
            cursum += right;
        }
        else if(cursum > sum){
            
            left++;
            cursum -= left;
        }else{
            print(left,right);
            right++;
        }
    }

}
int print(int left, int right)
{
    for(int i = left; i <= right; ++i){
        printf("%d ", i);
    }
    printf("\n");
}
*/

void findnumebersinsum(int sum){
    if (sum < 3) return;

    int left = 1;
    int right =2;
    int mid = (sum+1)/2;

    int cursum = left + right;

    while(left < mid){
        if(cursum == sum){
            Print(left,right);
            right++;
        }else if(cursum > sum){
            cursum -=left;
            left++;
        }else{
            right++;
            cursum +=right;
        }
    }
    return ;
}//我的代码明显比剑指offer要好