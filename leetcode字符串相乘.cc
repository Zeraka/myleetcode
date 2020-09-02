/*
对算法要十分研究。秋招上不去，多大个事。
字符串相乘，又是一道经典习题
    首先思路是什么？
    字符串相乘非常重要，几乎是必考的题目，应该把题目刷完再说，
    
    有什么好的思路呢？
    
    M位 X N位 得到的数，会有多少位？
     要么M + N位，要么是M+N-1位,所以，
     所以，可以建一个长度为M+N的数组。数组第0位为0， 第m位乘以第n位则是array[m+n-1],拥有一种

     M的第m位乘以 N的第n位， 要添加在什么地方？
     
为什么不用int作为返回值呢？ 因为int的长度是有限制的，而string可以表示非常大的数
int只能表示很小的数字，所以实际上计算器计算大的数据的时候，都是用字符串类型表示的。

如果其中一个字符串是0,则无论如何结果都是0
本题还有一个应该考虑的点，那就是

不要想那么多，无论如何，人都是要竞争的。如果你回到小县城的话。

如何记住字符串相乘呢？
    再练习几遍就记住了。
#字符串相乘的本质是什么？
    先把每一位的字符转变为数字是每一个人都能想到的
    主要问题是乘数相乘的进位规律。
    m位乘以n位最多有m+n位的十进制数。
    
    


*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    string multiply(string num1, string num2){
        if(num1 == "0" || num2 =="0") return 0;

        int m = num1.size();
        int n = num2.size();

        vector<int> arr(m+n,0);
        string res;


        for(int i = 0; i<m;i++){
            for(int j = 0; j < n;j++)
            {
                arr[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            }
        }

        int index = arr[0] == 0 ?0:1;

        for(int i = m+n-1; i>0;--i)
        {
            arr[i-1] += arr[i]/10;
            arr[i] %=10;
        }

        while(index < m+n)
        {
            res.push_back(char(arr[index]+'0'));
            index++;
        }
    //也可以这样进行
       // for(auto& c: res)
       // {
            //c+='0';
      //  }
        return res;
        
    }
};


/*
class Solution{
    public:
    string multiply(string num1, string num2){
        if(num1 == "0" || num2 == "0") return "0";

        //判断输入的字符串是否为数字，当然在这里，默认是符合要求的
        int m = num1.size();
        int n = num2.size();


        vector<char> array(m+n);
        string res;
        for(int i = 0; i < m;m++){
            for(int j = 0; j < n; n++)
            {
                array[i+j+1] += (num1[i] - '0')*(num2[i]-'0');
                
            }
        }

        //对array进行进位处理，从m+n-1位开始，如果该数大于9,则将该数的
        //
        for(int i = m+n-1; i>0 ; --i){
            if(array[i]-'9'>'0')
            {
                array[i-1]+=array[i]-'9';
                res = res + array[i-1];
            }
            
        }
        
        return res;
    }
};
*/
/*
我的代码和正确的代码相比，有什么问题所在呢？
    我写了 vector<char> array(m+n); 这样的初始化的方法是错误的，
    必须是 vector<int> array(m+n);或者是
    auto array = vector<int>(m+n);

    否则就会报溢出的错误，很显然，必须用int,因为不用int的话，得到的数字肯定会使得char类型溢出

    所以用 auto array = vector<int>(m+n);

    第二个错误，是什么呢？
    字符串拼接错误  res = res + array[i-1]; 为什么会错呢？
    因为有一个 res = res+ array[i-1], 
    
    for(int i = m + n -1;i>0;--i){
        array[i-1] +=array[i]/10;
        array[i] %= 10;
    }

    这样便得到了array[i] %= 10; 然后有一个比较好的特点去做。

    当你将数组填充满的时候，你要怎么做 
    首先从数组的末尾开始，通过除以10，得到的数就是需要进位的数
    而和10求余得到的数，就是该数组的这一位的数字，然后再将其变为字符，放入res中去


    string multiply
    string multiply  multiply  multiply multiply multiply
    multiply 
*/
/*
class Solution{
    public:
    string multiply(string num1, string num2){
        if(num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();
        string res;
        vector<int> array = vector<int>(m+n);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; n++){
                array[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            }
        }//将数组填充进 int类型

        //一次性将整个数组进位，
        for(int i = m+n+1; i>0;--i){
            array[i-1] += array[i]/10;
            array[i] %=10;

            
        }

        //判断第0位是否为0，如果为0，就把开始index置为1，

        int index = array[0]==0?1:0;

        //既然已经进位好了，就可以直接将其转化为字符了
        while(index < m+n){
            res.push_back(array[index] + '0');
            index++;
        }

        return res;


    }
};*/
//重写一遍，20分钟内写出来
//正负数啊，0啊，这些情况
//
/*
class Solution{
    string multiply(string num1, string num2){
        if(num1 =="0"|| num2 =="0")  return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int>  arr(m+n,0);//初始化为m+n个0

        string res;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j< n; ++j){
                arr[i+j-1] += (num1.at(i)-'0')*(num2.at(j)-'0');
            }
        }

        //数组每一位进行进位
        for(int i = m+n-1 ; i>0;--i){
            arr[i-1] = arr[i]/10;//如何得到高位呢？那就是
            arr[i] %= 10;

        }

        //接下来，我们要把这个数组中的每一位数转化为字符放到res当中去。

        int index = (arr[0] == 0)? 1:0;
        for(int i = index; i<=arr[m+n-1];++i){
            res.push_back(arr[i] + '0');
        }
        
        return res;
    }
};
*/
