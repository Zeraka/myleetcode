
//第2遍。
#include <algorithm>
//#include<algorithm> #include<algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Automaton
{
public:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "number", "other"}},
        {"signed", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int sign = 1;
    long long res = 0;

    int get_col(char c)
    { //转条件为数？
        if (isspace(c))
            return 0;
        if (c == '+' || c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

    void get(char c)
    { //状态更新函数
        state = table[state][get_col(c)];

        if (state == "number")
        {
            res = res * 10 + c - '0';

            //比较绝对值。
            res = sign == 1 ? min(res, (long long)INT_MAX) : min(res, -(long long)INT_MAX);
        }

        if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution
{
    int myAtoi(string str)
    {
        Automaton automaton;

        for (char c : str)
        {
            if (automaton.state != "end")
                automaton.get(c);
            else
            {
                    break;
            }
            
        }

        return automaton.res * automaton.sign;//最后结果是相乘。

    }
};