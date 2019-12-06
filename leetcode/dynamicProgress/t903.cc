#include <string>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Array;
typedef vector<Array> Arraybucket;

#define MOD 1000000007
/*
int numPermsDISequence(std::string S)
{
        int M = MOD;
        //第一维表示取到S的第几个字母，第二维表示取值，例如0，1，2，3,dp[i][3]结尾取3
        vector<vector<int>> dp(S.size()+1,vector<int>(S.size()+1,0));
        dp[0][0] = 1;
        for(int i = 0;i<S.size();i++){
            if(S[i] == 'I'){
                for(int j = 1;j<=i+1;j++){
                    dp[i+1][j] = (dp[i+1][j-1]+dp[i][j-1])%M;
                }
            }else{
                for(int j = i;j>=0;j--){
                    dp[i+1][j] = (dp[i+1][j+1]+dp[i][j])%M;
                }
            }
        }
        int res = 0;
        for(int i = 0;i<dp.size();i++){
            res=(res+dp[dp.size()-1][i])%M;
            std::cout<<"dp "<<dp.size()-4<<" "<<i<<" is: "<<dp[dp.size()-4][i]<<std::endl;
        }


        return res;    }

*/

int numPermsDISequence(std::string S)
{
  int M = MOD;
  int N=S.length();
  //第一维表示取到S的第几个字母，第二维表示取值，例如0，1，2，3,dp[i][3]结尾取3
  vector<vector<int>> dp(S.size() + 1, vector<int>(S.size() + 1, 0));
  dp[0][0] = 1;//why?

  int res = 0;
 
  for (int i = 1; i <= N; i++)//从头开始计算个数
  {
    for (int j = 0; j <= N; j++)//
    {
      if (S[i - 1] == 'D')
      {
        for (int k = j; k < i; ++k)
        {
          dp[i][j] += dp[i - 1][k];//
          dp[i][j] %= MOD;
        }
      }
      else
      {
        for (int k = 0; k < j; ++k)
        {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= MOD;
        }
      }
    }
  }

  for (int i = 0; i < dp.size(); i++)
  {
    res = (res + dp[dp.size() - 1][i]) % M;
    std::cout << "dp " << dp.size() - 4 << " " << i << " is: " << dp[dp.size() - 4][i] << std::endl;
  }
  return res;
}

int main()
{
  std::string S = "DID";
  int count = 0;
  count = numPermsDISequence(S);
  std::cout << "value is " << count << std::endl;
}
