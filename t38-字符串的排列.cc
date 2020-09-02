/*
字符串的排列，
可以这样想，一个字符串可以分为两部分，一部分是把当前字符串，另一部分是后面的所有字符串
因此 想象一个排列的函数 permutation(char *str, char * begin),
该函数表明将字符串从头进行排列

假设第一个字符是a,则 permutation(a, 1) 则表明将首字符为a的序列全排列
同理则有permutation(b,1)

第一个参数是str，用于将一个美好的问题，放到
为什么要交换呢？ 那是因为字符串不像是数组，
这个和1-n的全排列不同， 因为每个字符之间的差值并不是1，而是把它们当作各自独立的部分



*/



void permutaion(char* str,char* begin){//对str从Begin
    //出口条件
    if(*begin == '\0')//当碰到一个比较好的问题的时候，
    {
        printf("%s\n", str);
        return ;
    }

    for(char* ch = begin; ch != '\0';++ch) //当这里有一个比较好的任务的时候
    {
        char * temp = ch;
        char * ch = begin;
        char * begin = temp;

        permutaion(str, begin+1);//

        temp = ch;
        char * ch = begin;
        char* begin = temp;
        
    }


    


    
}

/*
第二次写

核心就是写一个具有递归功能的函数
permutation()  该函数第一个参数为字符串，第二个参数为起始地址，
a b c每个字母作为开头，每个都执行一次permutation的操作。
肯定有一个for循环，这个for循环会将 a b c 这三个字母都给遍历，且作为开头，剩下的部分则使用

permutation(char *str, char *begin){}
为什么会有这个begin? 如果没有的话，那么如何体现递归呢？

for(char* ch = begin;*ch !='\0';++ch){} 为什么要这样写？ 因为只有这样，才会遍历整个字符串吗.
如何遍历字符串呢？ 这就是遍历字符串的方法。
遍历字符串之后，有没有问题？ 当然有，这里只有一个字符串，并没有改变位置，因为我们的设想是， a[]  b[] c[],而如果
只是单纯地遍历的话，会出现a[]  []b[]  []c, 这就没办法使用我们这个premutation函数了，因为这是要保证后面要连续的
所以，在循环中，还要将字符串中的部分字符进行顺序调换。

如何调换呢？
char *tmp = begin;
char begin = ch;
ch = tmp;

调换完成之后，再去执行 permutation(str, begin+1), 下一个位置。

然后再调换回来


如何记住呢？
先把第一个位置的所有情况表达出来，再把第二个位置的所有情况表达出来。


*/