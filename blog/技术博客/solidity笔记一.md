## 参考资料
solidity语言学习https://solidity-cn.readthedocs.io/zh/develop/solidity-by-example.html
语言学习2https://www.qikegu.com/docs/4834



### solidity映射类型
mapping(unit=>uint)stateVar;
### solidity函数的格式
以function开头 接上函数名和参数 public returns(类型 形参)，例如：
```
function vote(uint proposal) public return()
```
## 报错解决
```
Data location must be "memory" or "calldata" for parameter in function, but none was given.
```
这是由于solidity版本更新导致的，在参数中的string后加上memory即可解决。https://blog.csdn.net/zqq_2016/article/details/103802482

## 日记
solidity的监控器要有哪些函数？
automonitor将solidity监控器的数据结构写出来，然后将每个字符输入进这些数据结构中。
应该有一个函数叫做 init()
init()函数便是将监控器的各个状态以及需要检测的字符给输入其中。

得到的event，在automonitor中解析，然后输入到solidity代码中。
RPN是vecotr<string> 是一个字符串动态数组。逆波兰表达式

自动机生成模式是，每次输入LTL，都会有一个新的监控器合约生成。该合约执行后能够init(),并且可以得到。

solidity基础语法：https://www.jianshu.com/p/5ab811e5cbe3
