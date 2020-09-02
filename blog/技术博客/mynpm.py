'''
本脚本用于npm的自动使用。能够自动解决配置时候的错误
'''
import subprocess

password = '1234.com'

def command(inputstr):
    
    
    
    myargs = ['sudo','npm','install','--registry','https://registry.npm.taobao.org']

    ret = subprocess.run(myargs)
    print(ret)

if __name__=="__main__":
    
'''
ret = subprocess.run(['ls','-l']) #参数是list类型
print(ret)
'''

