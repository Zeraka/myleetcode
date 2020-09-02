/*
海量数据的topK 问题几乎是必考的，因此一定要会它

创建一个大小为K的数据容器，

时间复杂度为O(nlogK)的话，
创建一个大小为K的容器来存储最小的K个数字，接下来每次从输入的n个整数中读入一个数
再重新写一遍。总之，一定要会默写，一定要会默写。
*/

/*
#include <iostream>
#include<vector>
#include<>
using namespace  std;

typedef multiset<int,greater<int>> intset;
typedef multiset<int,greater<int>>::iterator setIterator;

void GetTopK(const vector<int>& data, int k, intset& intset){
    intset.clear();
    if(k < 1 || data.size() < k)
    return ;

    vector<int>::iterator iter = data.begin();

    for(;iter != data.end(); ++iter)
    {
        if(intset.size() < k)
        {
            intset.insert(*iter);
        }else
        {
            setIterator stit= intset.begin(); //一定要把begin()写上去。然后再去
            
            if(*stit > *iter){
                intset.erase(stit);
                intset.insert(*iter);
            }
        }
        
    }
}//14min,不行。再写一次。必须在5min之内写完
*/
/*
#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef multiset<int,greater<int>>  intset;
typedef multiset<int,greater<int>>::iterator itr;
void gettopK(const vector<int>& data, int k, intset& Intset)
{
    Intset.clear();
    if(k < 1|| data.size() < k)
    return;

    vector<int>::const_iterator iter = data.begin();
    for(;iter!=data.end();++iter)
    {
        if( Intset.size() < k)
            Intset.insert(*iter);
            else
            {
                itr itst = Intset.begin();
                if(*iter < *(Intset.begin()))
                {
                    Intset.erase(itst);
                    Intset.insert(*iter);
                }
            }
            
    }
}
*///6min.还行，再练习一遍。 不断练习，像剑指offer中的题目，要能够5min左右就写出来

