/*
LRU 是Latest recently used的缩写，意为最近使用过的。
cache是缓存。LRU cache是指用LRU算法对缓存进行存取。
LRU基于这样的假设，如果一块内存近期没有使用，则以后也会较少使用。

题目中的要求是O(1)。
如果使用数组，那时间复杂度为O(n),  

LRU的数据结构核心有两个，
一个是双向链表，一个是hashmap，
双向链表中要存储哪些内容呢？
一个是key,一个是value

首先是声明双向链表，其实是haspmap的value要存储什么东西
value当然是当前节点。
另外，双向链表中存储的是key, 也就是说，通过这个key，能够将

所谓的哨兵，其实是头指针和尾指针两个指针而已。并没有用头尾节点。
只是指向了它们。

hashmap中存储的是双向链表的节点，key实际上是内存地址。
head和tail都是指针，而不是节点，是指向 mylistnode节点类型的指针
所以，会有一种

通过key，快速找到Data,Data中有值，以及节点的地址。指向该节点的指针
只要通过key，就可以快速找到Data了


int get(int key){

}
先从key中拿取

void put(int key, int value)函数

首先判断是否存在key,这个key是hashmap中的
如果不存在，就将其放入。
如果存在，那就更新


首先建立两个数据结构，双向链表和hashmap,其中map不需要自己再去设立了

然后建立一个LRUchache的数据结构，
hashmap中是用什么的
注意，这里面的缓存的值是存放在双向链表上面的，而不是存放在hashmap上的，否则

hashmap中存储的是节点地址，
如果取节点，先从hashmap中看是否存在该key,存在的话就得到该节点地址，


为什么双向链表节点要有key? 
    因为在删除尾部节点的时候，需要知道尾部节点的key，这时候
    指向尾部节点的
*/
/*
struct mylinknode{
    int key, value;
    mylinknode* prev, next;
    mylinknode():key(0),value(0), prev(nullptr),next(nullptr){}
    mylinknode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr) {}
};

class LRUCache{
    private:
    unordered_map<int, mylinknode*> cache;
    mylinknode* head;
    mylinknode* tail;

    int size;//这个size是已经存储的容量
    int capacity;//capacity是总容量

    public:
    //初始化只是将capacity赋值并且将两个哨兵节点生成并且互相指向。
    LRUCache(int _capacity):capacity(_capacity),size(0){
        head = new mylinknode();
        tail = new mylinknode();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key){//首先是判断cache中的内容存不存在
        if(!cache.get(key)){
            return -1;
        }//如果存在,哈希表存储的是节点的地址，就把该节点移动到队头部。

        mylinknode* node = cache[key];//将cache的key变为
        moveToHead(node);

        return node->value;//返回缓存中的内容。缓存就是双向链表。

    }

    void put(int key, int value){
        if(!cache.get(key)){
            //如果key不存在，则创建一个新的节点
            mylinknode* node = new mylinknode(key, value);

            cache[key] = node;

            addTohead(node);

            ++size;
            if(size > capacity){
                mylinknode* removed = removeTail();//删除尾节点
                cache.erase(removed->key);

                delete removed;
                --size;
            }
        }else{
            mylinknode* node = cache[key];
            node->value = value;

            moveTohead(node);
        }

    }
}
*/

/*
首先是将 

*/
/*
struct mylistnode
{
    int key, value;
    mylistnode *prev;
    mylistnode *next;
    mylistnode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    mylistnode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int size;
    int capacity;
    unordered_map<int, *mylistnode> cache;

    mylistnode *head;
    mylistnode *tail;

public:
    LRUCache(int _capacity) : capacity(_capacity)
    {
        //构造的时候要将收尾指针相互指向
        //在private中声明的是指针，在构造的时候必须用
        head = new mylistnode();
        tail = new mylistnode();

        head->next = tail;
        tail->prev = head;
    }

    //如果key不存在，就返回空，如果存在，就
    //从cache上找到节点地址，然后将其值返回，同时将该节点放于头部。
    int get(int key)
    {
        if (!cache.get(key))
        {
            return -1;
        }

        mylistnode *node = cache[key];
        moveToHead(node);

        return node->value;
    }
    //首先查看是否拥有key,如果没有，就放入，并且看size大小，如果抄了，就将尾节点删除。
    //如果有了，那就更改key的值，并且将其放入头节点。
    void put(int key, int value)
    {
        if (!cache.get(key))
        {
            mylistnode *node = new mylistnode(key, value);
            cache[key] = node;

            size++;
            addTohead(node);
            if (size > capacity)
            {
                mylistnode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        else
        {
            mylistnode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    //添加至头节点
    void addTohead(mylistnode *node)
    {
        mylistnode *tmp = head->prev;
        tmp->next = node;
        node->prev = tmp;
        node->next = head;
        head->prev = node;
    }

    //移动至头节点，首先删除
    void moveToHead(mylistnode *node)
    {
        //首先将原来的部位删除
        node->prev->next = node->next;
        node->next->prev = node->prev;

        addTohead(node);
    }

    //删除尾节点,因为
    mylistnode *removeTail()
    {
        mylistnode *res = tail->next;

        tail->next = res->next;
        res->next->prev = tail;
        res->next = nullptr;
        res->prev = nullptr;

        return res;
    }
};*/

#include<unordered_map>

struct mylistnode
{
    int key, value;

    mylistnode *prev;
    mylistnode *next;

    mylistnode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    mylistnode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    int size;

    mylistnode* head;
    mylistnode* tail;

    unordered_map<int, struct mylistnode*>  cache;

    
public:

    LRUCache(int _capacity):size(0),capacity(_capacity){
        head = new mylistnode();//这就是两个mylistnode的好处。
        tail = new mylistnode();

        tail->next = head;
        head->prev = tail;
    }

    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        mylistnode* node = cache[key];
        MoveToHead(node);

        return node->value;
    }
    void put(int key, int value){
        if(!cache.count(key)){
            mylistnode* node = new mylistnode(key, value);
            
            cache[key] = node;
            addTohead(node);

            ++size;

            if(size > capacity){
                mylistnode* removed =  RemoveTail();
                cache.erase(removed->key);

                delete removed;
                --size;
            }

        }
    }

    void addTohead(mylistnode* node){
        
    }
    void MoveToHead(mylistnode* node){

    }
    mylistnode* RemoveTail(){

    }
};