
## is-a是什么意思？
    is-a似乎是一种设计模式？ 总之用一种特别的方法，可以看到说，
    使用
    撒地


使用可重用的代码。
面向对象的主要目的就是提供可重用的代码


# 为什么要面向对象？
    主要目的就是代码重用，如果是C++。
    
#虚拟内存具体是什么时间分配的？

#缺页中断又是什么？

1.ngnix服务器建立连接失败有哪些可能
    请求的header过大， nginx的默认header长度上限是4k,如果超过了
    这个值nginx会直接
Nginx服务器错误一般有以下几点原bai因：

1、请求的duheader过大。nginx默认的header长度上zhi限是4k，如果超过了这个值,nginx会直接返回400错误dao.

解决方法：配置nginx.conf相关设置。可以通过以下2个参数来调整header上限：

client_header_buffer_size 16k；large_client_header_buffers 4 16k。

2、上传文件过程中出现错误。这时浏览器显示“413 Request Entity Too Large”。这是因为没有设置client_max_body_size，这个参数默认只是1M，也就是说发布的文章内容大小不能超过1M。

解决方法：增加如下两行到nginx.conf的http{}段， 增大nginx上传文件大小限制：设置允许发布内容为8M：client_max_body_size 8M；client_body_buffer_size 128k。

另外如果运行的是php，那么还要检查php.ini，这个大小client_max_body_size要和php.ini中的如下值的最大值一致或者稍大，这样就不会因为提交数据大小不一致出现的错误：post_max_size = 8M；upload_max_filesize = 6M。

修改完配置后，别忘记重新加载。

3、客户端在为等到服务器相应返回前就关闭了客户端描述符。一般出现在客户端设置超时后，服务器主动关闭。

解决方法：根据实际Nginx后端服务器的处理时间修改客户端超时时间。

4、脚本错误（php语法错误、lua语法错误）。

解决方法：查看nginx_err_log php_err_log。

5、访问量过大，系统资源限制，不能打开过多文件。 磁盘空间不足。（access log开启可能导致磁盘满溢，服务器主动关闭）。

解决方法：修改/etc/sysctl.conf文件，并使用下面的命令确认： #sysctl -p。要使 limits.conf 文件配置生效，必须要确保 pam_limits.so 文件被加入到启动文件中。

6、后端服务无法处理，业务中断。

解决方法：从后端日志获取错误原因，解决后端服务器问题。

7、后端服务器在超时时间内，未响应Nginx代理请求。

解决方法：根据后端服务器实际处理情况，调正后端请求超时时间。

8、网站页面缓存过大。
解决方法：配置nginx.conf相关设置：fastcgi_buffers 8 128k；send_timeout 60。

2.class test{
int i;
};有一个继承来的虚函数，
test t;
memset(&t.i,0x00,128);
memset(&t.i,0x00,8);
分别会发生什么
3.虚拟内存是具体什么时间分配的，缺页中断是什么
4.gdb的core dump如何配置，backtrace如何追踪（静态和动态


1、不管学的是什么专业，都有一颗对互联网无比热爱，愿意为之付出的心；
2、就是喜欢C、C++这个程序语言，还就爱拿它做项目开发；
3、对网络编程有研究，基本的gdb调试能力？内存泄漏，越界读写等常见问题？对你来说都不是问题；
4、作为一个优秀的程序员，有良好的服务器端编程能力和编程习惯，相关模块设计、文档编写都是小case；
5、十八般武艺样样精通，掌握多线程并发编程技术，掌握各种数据结构和算法；
6、熟悉windows/linux编程环境，如果有MySQL开发经验那就再 好 不 过 啦！！！