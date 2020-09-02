/*
字符串如何反转呢？
    如果是字符数组，那么就很简单，通过双指针的方式，对其进行调换。
    reverseString
    reverseString
    reverseString
    将字符串颠倒过来。
*/

class Solution{
    public:
    void reverseString(vector<char>& s){
        int left = 0;
        int right = s.size() -1 ;

        char tmp ;

        while(left < right){
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left++;
            right--;
        }
    }
};