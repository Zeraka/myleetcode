/*
C++打开一个新文件，然后向文件内输出

ofstream ofile; 定义一个输出文件，这是内部文件对象，也就是一个存储文件的数据结构
ofile.open("文件路径")  这才会真正地打开一个文件


ofile << "xxxxx" << endl; 向文件中输入一行

为什么要用ofile呢，因为这是输出文件流，是生成一个新的文件
如果要读入已有的文件，则使用 ifstream ifile
*/

ofstream ofile
ofile.open("路径", 打开方式，指定打开文件的保护方式(一般缺省))

关于打开方式，有ios::in和ios::out,
例如 ofile.open("monitor.sol", ios::out);

ifstream ofile

fstream file //既可以输入，又可以输出

ofstream 


