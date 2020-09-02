/*
两数之和，使用快慢指针
本题和剑指offer的57题一样，57题有两道题，一道是两数之和，另一道是连续之和。
连续之和并不是指两个数之和，而是指一连串的数之和，因此两道题的快慢指针是不同的。


leetcode的题目中，是返回原来的数组的下标的，而程序排好序之后，原来的数组的顺序就被打乱了
因此，必须要想办法将原来的数组的下标找到。

所以需要一个temp,temp找到值之后，就重新回到nums数组中进行比对，
*/

/*
#include<vector>

using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>&nums, int target){

        //if(nums.size() == 0 ) return res;
        vector<int> res;
        vector<int> temp;
        
        temp = nums;
        int left = 0;
        int right = nums.size() - 1 ;

        
        sort(temp.begin(),temp.end());

        int cursum = temp[left] + temp[right];

        while (left < right)
        {
            if(cursum > target)
            {
                cursum -= temp[right];
                right--;
                cursum += temp[right];
            }else if(cursum < target){
                cursum -=temp[left];
                left++;
                cursum += temp[left];
            }else{
                break;
            }
        }
        
        int n = nums.size() ;
        for(int i = 0; i < n ; ++i){
            if(left < n && nums[i] == temp[left]){
                res.push_back(i);
                left = n;
            }
            else if(right < n && nums[i] == temp[right]){
                res.push_back(i);
                right = n;
            }
            if(left == n && right == n) return res;
        }


        return res;
        
    }
};*/

/*

temp = nums
sort(temp)
n = nums.size()
left = 0
right = n - 1 
cursum = nums[left]+nums[right]

while(left < right)
    if(cursum < target)
        cursum -= nums[left]
        left++
        cursum += nums[left]

    else if cursum > target
        cursum -= nums[right]
        right++
        cursum += nums[right]

for(int i = 0; i < n; ++i)
{
    if(left < n && nums[i] == temp[left])
        left = n
        res.push_back(i)
    else if(right < n && nums[i] == temp[right])
        right = n
        res.push_back(i)
}

return res

如何保证最后一步不重复呢》 只要发现了left被找到，就把left变掉 
只要发现了right被找到，就把right变变掉 

如何保证数组中的左右只被遍历一次呢》
那就是用与运算，如何让left和right只比较一次呢？ left是一个标记，只要让这个标记所代表的表达式为否，就可以让这个条件不要再运算了

本题要注意的是，给的数组并没有排好序，需要手动排序，并且输出的是原数组的下标，因此要对原数组重新进行遍历。


*/
