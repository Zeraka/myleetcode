/*
将两个有序数组合并

nums1 = [1,2,3,0,0,0]  m = 3
nums2 = [2,5,6]  n = 3
m和n分别代表每个数组的元素数量，这个有啥用吗？

输出：[1,2,2,3,5,6]

本题的特殊之处是要求将新的结果放到nums1上面，
nums1后面的0表示为空

思路：
    三指针，分别指向nums1的含有元素的末尾，nums1的第m+n-1个位置以及nums的第n-1个位置。
    nums1[m-1]
    nums2[n-1]
    nums1[m+n-1]

    只要有一个先为0，则停止比较

参数中有m和n，这就是为了将自己id

*/
#include <vector>
#include <iostream>
using namespace std;

/*
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> res;
        int i = m + n - 1 ;
        m--;
        n--;

        while (n >= 0)
        {
            while (m >= 0 && nums1[m] > nums2[n])//当num1的最后一个数大于nums2的最后一个数的时候，如果不是则跳出，
            {
                swap(nums1[i--], nums1[m--]);//将nums1的最后非空位的数移动到最后空位。
            }
            swap(nums1[i--], nums2[n--]);//将num2的后一位放入
        }
    }
};
*/

/*
参数m位nums1的非空位的数目，n为nums2的数目
将nums1的第m--个和nums2的第n--个进行比较，谁大，谁就被放到nums1[i--]的位置上去，而i = m + n -1

如果m先变为0的话，则剩余的n全部放到nums1[i--]中，如果n先变为0的话，则不用放了，因为nums1本来就有m了。
所以n>=0为外循环。 

此答案非常精简，因此很棒。

*/
/*
class Solution{
    public:
    void merge(vector<int> nums1,int m, vector<int> nums2, int n){

        int i = m + n -1;
        m--;
        n--;

        while(n >= 0){
            while(m>=0 && nums1[m]>nums2[n]){
                swap(nums1[m--],nums2[i--]);
            }
            swap(nums2[n--], nums1[i--]);
        }
    }
}*/

class Solution{
    void merge(vector<int> nums1, int m,vector<int> nums2,int n){
        int i = m +n-1;

        m--;
        n--;

        while(n>=0){
            while(m>=0&&nums1[m]>nums2[n]){
                swap(nums1[m--],nums1[i--]);
            }
            swap(nums1[n--],nums1[i--]);
        }
    }

}
