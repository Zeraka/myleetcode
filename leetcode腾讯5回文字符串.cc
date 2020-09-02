/*
回文字符串，此题到底是如何使用动态规划算法的呢？
动态规划并不需要递归，动态规划的核心是具有 状态转移函数。
感觉有点像自动机

自动机理论应该可以成为算法的依据吧。以后成为一个一流算法大师，应该把自动机理论以及算法导论好好研究。总之，就是先把leetcode的题目
做十分深入的研究。

如何用动态规划求 最大回文字符串呢？ 
    因为所有的回文字符串，会


1、根据什么判断此题用动态规划法求解呢？
    每一个字符就是一个状态，一个字符字串，就是从起点状态到终点状态的跳跃。 能跃迁的话
    那就是符合要求的
假设在字符串 str上 任意找两个位置i 和 j， 其中 i <= j, 判断str[i:j]是否为回文字符串
我用dp[i][j]表示是否为回文字符串,

dp[i][j]可以看作是状态机的不同状态。
你可以这么理解， 横坐标为i,纵坐标为j, 原字符是 ababd, 则建立的状态表是


你可以把动态规划法理解为求状态表，状态表是通过状态转移函数确立的。每个状态i都可以跳到状态j，同时
产生一个状态的值，这个状态值就是

这就是以边界为


如何判断动态规划公式是一维还是二维呢？
把字符串，把台阶，等，变为状态，从某个状态跳到某个状态，需要消耗的能量，可以计算出来。
例如 str[i->j]是否为一个回文字符串，你可以理解为是否可以从状态i 跳到 状态j
从i跳到j的状态过程中，发生了一个能量的变化，而这个变化，可以通过dp[i][j]得到
所以，这里，使用了dp[][]二维来表示状态。

如果有一个状态点固定，则可用1维，如果两个状态点都不固定，则必然用二维。




状态的表示？ 

状态转移公式
    从这个状态转移到下一个状态需要什么条件，而这个条件又和其他状态有无关系。
边界条件
    边界条件是什么呢？ 就是单个状态和其他状态无关的转移能量。

如何声明一个nXn的矩阵呢？
vector的声明——关于vector，要好好研究一下。
vector<vector<int>> dp(n,vecttor<int>(n));  第一个n是初始化了vector<vector<int>>的数目。第二个是vector<int>的匿名初始化


总体思路是什么？
    string s中有两个状态i和j,其中i小于j，而

    j从0开始遍历，既然i小于j，那么i就可能有
    如何找到最长子串
    只要有符合要求的dp[i][j],让j+1-i 和res.size()比较一下就行。如果大于的话，就将res 变为 s.substr(i,j-i+1)

    C++中字符求子字符串，s.substr(i, len) 从起始点i开始的长度为len的字符串。
    
*/
/*
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.size(); //首先拿到s的长度

        vector<vector<int>> dp(n, vector<int>(n));

        string res;

        int i = 0; //边界条件怎么写呢？
        for (int j = 0; j < n; ++n)
        {
            for (i = j; i >= 0; --i)
            {

                if (i == j)//边界条件，相等的时候
                {
                    dp[i][j] = 1;
                }
                else if (i + 1 == j)//边界条件，长度为2的子字符串为
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }

                if(dp[i][j] == 1 && (j+i-1)>res.size()){//该部分就是将
                    res = s.substr(i,j-i+1);
                }
            }
        }

        return res;
    }
};
*/

//重写一遍, longestPalindrome longestpalindrome palindrome
//longestPalindrome longestPalindrome

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string res;
        for (int j = 0; j < n; j++)
        {
            for (int i = j; i >= 0; --i)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (i + 1 == j && s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }

                if (dp[i][j] == 1 && j + 1 - i > res.size())
                {
                    res = s.substr(i, j + 1 - i);
                }
            }
        }

        return res;
    }
};