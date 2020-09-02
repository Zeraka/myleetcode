/*
翻转字符串的思路是什么呢？
这里有两点，一点是，将字符串的逆序
字符串的逆序是怎么写的呢？
就是两个指针，分别指向首和尾，然后分别进行调换，首加尾减，直到两者指向同一处

*/
void Reverse(char *begin,char *end){
    if(begin == nullptr || end == nullptr)  return;

    while(begin < end){
        char* tmp = begin;
        begin = end;
        end = tmp;
        begin++;
        end--;
    }
}

char *ReverseSentence(){
    
}