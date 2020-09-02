/*
给定一个字符串，找到它的第一个不重复的字符，并且返回它的索引，
如果不存在，则返回 -1
假定只包含小写字母
用哈希表
从头开始遍历该表，每个字符放入map中
如果下一次出现了重复的字符，就对value++
遍历完以后，再遍历一遍，找到第一个value为1的可以


还有没有更快更省空间的方法？
可以用模拟哈希的方式来解决
小写字母一个就26个，所以可以设计一个26个字符的
数组， 比如 char ch[26],0-25代表a-z
所以遍历字符串 时候，就会有

*/
class Solution{
    public:
    int firstUniqChar(string s)
    {
        map<char, int> hm;

        for(auto &c :s)
        {
            hm[c] +=1;
        }
       
       //再次重头开始遍历
       for(int i = 0; i < s.size();++i)
       {
           if(hm[s[i]] == 1) return i;
       }
       return -1;
    }
};
class Solution2{
    //模拟哈希的方法
    int firstUniqChar(string s)
    {
        int ch[26]= {0};
        for(auto &c:s)
        {
            ch[c-'a']++;
        }
        for(int i = 0;i<s.size();++i)
        {
            if(ch[s[i]-'a']==1)return i;
        }

        return -1;
    }
};