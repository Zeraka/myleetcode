void *zmq_socket(void *context,int type)函数是zmq的核心API，意为创建ZMQ套接字。并以一个任意指针返回该socket。type参数指明了要创建的socket类型，该类型决定了在进行传输时候此socket上执行的语义。
https://www.cnblogs.com/fengbohello/p/4354989.html

## 函数实现原理
```
void *zmq_socket (void *ctx_, int type_)
{
    if (!ctx_ || !((zmq::ctx_t*) ctx_)->check_tag ()) {
        errno = EFAULT;
        return NULL;
    }
    zmq::ctx_t *ctx = (zmq::ctx_t*) ctx_;
    zmq::socket_base_t *s = ctx->create_socket (type_);
    return (void *) s;
}
```
首先判断ctx是否错误，若有错误则返回NULL。
zmq::ctx_t 类产生context对象。
该对象由 zmq_init(1)产生.
```
void *context = zmq_init(1);
```
zmq_init的作用是创建一个IO线程
```
void *zmq_init (int io_threads_)
{
    if (io_threads_ >= 0) { //线程数大于等于0
        void *ctx = zmq_ctx_new ();//创建context即线程上下文类对象
        zmq_ctx_set (ctx, ZMQ_IO_THREADS, io_threads_);//线程的上下文
    }
    errno = EINVAL;
    return NULL;   
}
```
zmq_ctx_new() 的核心部分是zmq::ctx_t *ctx = new(std::nothrow)zmq::ctx_t;
alloc_assert(ctx)意为检查ctx的内存分配是否成功。

## zmq的线程上下文结构体有哪些内容？
