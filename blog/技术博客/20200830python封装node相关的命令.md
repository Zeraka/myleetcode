因为经常使用node和npm,但是国内的npm镜像的速度又不理想，因此想到用python来在npm 和 node命令上封装一层。

## 默认添加国内镜像
npm默认镜像在国外，比较慢。因此我们在使用npm的时候会用国内镜像。

使用国内淘宝镜像
```
npm --registry https://registry.npm.taobao.org install express
```

## python执行系统调用的指令
python执行系统指令一共有四种方式
```
# 方法1 
# 该方法成功执行后返回0，否则返回1
import os
os.system('xxxxx')
print(os.system('date'))

# 方法2 os.open()
# 该方法执行命令后会返回执行信息
os.open('date').read() 
print(os.open('date').read())

# 方法3 commands模块
import commands
getoutput()
getstatus()
getstatusoutput()

# 方法4 subprocess模块
# 原理是fork一个新的进程并与之通信。
import subprocess
def runcmd(command):
    ret = subprocess.run(command,shell=true,stdout= subprocess.PIPE,stderr=subprocess.PIPE,encoding='utf-8',timeout=1)

    if ret.returncode = 0:
        print("success",ret)
    else:
        print("error",ret)

runcmd(["dir","/b"])
runcmd("exit 1)
```
### 在python中使用sudo执行subprocess指令
参考此篇文章https://www.jb51.net/article/177149.htm


### python传入参数
https://www.jb51.net/article/177161.htm
```
import sys
def main(args):
    pass

if __name__ == '__main__':
    main(sys.argv) #这个argv就是
```

### remix-ide报错
在sudo后更新node,
```
sudo npm install -g install
```