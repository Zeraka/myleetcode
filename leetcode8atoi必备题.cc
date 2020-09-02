/*
本题是典型的自动机解法，DFA。如果不用DFA，就会导致非常臃肿的代码。

程序在每个时刻有一个状态s,每次从序列中输入一个字符c,并根据字符c转移到下一个状态
s',这样，我们只需要建立一个覆盖所有情况的从s与c映射到s'的表格即可解决题目中的问题。


如何用C++建立自动机呢？ 

先建立状态表，四个状态，有start(开始态),signed(符号),in_number(数字态)，"end"结束态。
每读入一个字符，就更新状态。

左侧一列是当前状态会出现的所有的可能值
而最上一行是碰到的条件，其余则是碰到对应的条件后跳转的状态。

C++建立的状态表，是 map<string,vector<string>>, string理解为最左侧的列，而vector<string>理解为行
为。 这样的数据结构的好处是可以表达二维表，且这种二维表的第一维度是字符串而不是数字。

这样的好处是什么？ 
    如果用C语言来建立表，会如何？ 

get_col函数用途就是用数字表示即将跳转的状态，用数字巧妙地表达不同的跳转状态。

table[key]得到的是一个vector<string>， 那么table[key][num]就可以得到下一个跳转状态。

用状态机的好处是，边界条件清晰，不会被一堆if else弄乱。

基本流程是什么？
    建立状态表
    读取字符，更新当前状态
    在当前状态进行操作，然后重新读取字符，更新状态。
    直到字符读取完毕。

如何判断正负号？
    假设默认为正， 设置一个变量为 int sign = 1; 如果在一开始遇到了负号，那么
为什么不用担心正负号出现在非开头的地方？
    因为状态表实际上限定了正负号状态出现的条件，即只有在start状态碰到+/-才会跳转至signed态
    而其余状态下都会变为end
    
//更新state就是从table中取一个状态而已。

*/
/*
class Automaton {
    string state = "start";//用map表示状态机，而不是其他。初始状态为start
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}//最后一个状态，无论如何跳转都会在原地踏步。
    };

    int get_col(char c) {//该函数是根据状态表，
        if (isspace(c)) return 0;//如果是空格，为0
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {//从c中拿取字符。并且更新状态
        state = table[state][get_col(c)];//table[state]，比如start状态有一个
        if (state == "in_number") {//如果跳到了number状态，那么就要将该字符打印出来。其次是判断正负号。
            ans = ans * 10 + c - '0';//
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }//如果为正数，则返回的是ans或者INT_MAX最小值，如果为负数，则返回负的
        else if (state == "signed")//如果是正负号，
            sign = c == '+' ? 1 : -1;
            
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;//声明一个自动机。为什么没有new一个呢？
        for (char c : str)
            automaton.get(c);//遍历拿取字符。
        return automaton.sign * automaton.ans;
    }
};
*/
/*
分情况，
atoi函数，一个字符会遇到哪些情况？
第一个情况是正负号(signed), 第二个是一般数字(number),
第三个是空格(space),第四个是除此之外的所有符号(other)

等一等，你这个为什么状态机设置的有问题？
因为没有开始或者结束。一个状态机必然又start和end的状态

另一个错误是，你把输入当成了状态。 你说的以上四个都是输入的字符的类型
而不是状态类型，前者是条件。条件和状态千万不能对应

字符被分类，实际上是输入的条件，状态你要重新设定。

假设开始状态，输入了一个正负号，会跳到哪一个状态？
如果输入一般数字会跳到哪一个状态。
我先假设有四个状态，然后再看四个状态有哪些可以合并
一个字符跳一个状态。

所以，第一步是首先根据输入条件，确定最小状态数
确定最小状态了之后就可以建立状态表了，状态表很好建立。

接下来，建立状态机。
C++的类中的变量是可以在定义的时候设置初始化值的。
当然，本题只考虑到了单个例子，而没有考虑到多个例子，

getcol函数是用数字表达下标，通过下标便可以取出表中的下一跳的状态。
*/

#include<iostream>
#include<unordered_map>
#include<algorithm> //使用min函数。
using namespace std;

class Automaton{
public:
    string current_state = "start";
    long long res = 0;
    int sign = 1;

    unordered_map<string, vector<string>> table = {
        {"start",{"start","signed","number","end"}},
        {"signed",{"end","end","number","end"}},
        {"number",{"end","end","number","end"}},
        {"end",{"end","end","end","end"}}
    };

    int getcol(char c){
        //如果字符为空格
        if(isspace(c)) return 0;
        if(c == '+' || c == '-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }

   // automaton(string start_state, unordered_map<string, vector<string>> _table):current_state(start_state),table(_table){}

    //有了getcol之后，就要拿到下一跳，然后进行操作了
    void get(char c){
        
        current_state = table[current_state][getcol(c)];//更新状态
        if(current_state == "number"){
            res = res*10 + c - '0';

            //判断符号的正负
            res = sign == 1 ? min(res,(long long)INT_MAX) : min(res,-(long long)INT_MAX);
        }else if(current_state == "signed"){
            sign = c == 1 ? 1: -1;
        }
    }
};
class Solution{
public:
    long long myatoi(string str){

        Automaton automaton;//无论如何，需要声明一个class,如果不声明，就无法调用。
        for(char a:str){//语法糖，使得
            automaton.get(a);
        }

        return automaton.res * automaton.sign;
        
    }


};