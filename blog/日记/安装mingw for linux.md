# ubuntu安装mingw-w64 for linux
```
git clone https://github.com/Zeranoe/mingw-w64-build
cd mingw-w64-build
```
在执行脚本的路径创建src和bld目录。
```
$ mkdir src
$ mkdir bld
```
执行该脚本
```
$ ./mingw-w64-build x86_64 # 在linux上安装适用于windows64的mingw。
```
提示缺少 bison flex svn makeinfo
执行以下指令：
```
sudo apt install bison flex subversion texinfo
```
重新执行该脚本。