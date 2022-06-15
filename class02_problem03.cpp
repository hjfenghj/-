#include<iostream>
#include<vector>
#include<string>

using namespace std;

int process1(string S,int idx)
{
	if (S[idx] == '0')
		return 0;
	//成功到达最后一个字符，节点返回1
	if (idx == S.size())
		return 1;
	int res = process1(S, idx+1);

	if ((S[idx] - '0') * 10 + (S[idx + 1] - '0') < 27)
		res += process1(S, idx + 2);
	return res;
}

//dp[idx]就便是字符串从索引idx开始到最后位置构成的子连续字符串,有几种转换方式
int process2(string S)
{
	vector<int> dp(S.size()+1, 0);
	int L = S.size();
	dp[L] = 1;
	dp[L - 1] = S[L - 1] == '0' ? 0 : 1;
	for (int i = L - 2; i >= 0; i--)
	{
		if (S[i] == '0')
			dp[i] = 0;
		else
			dp[i] = dp[i+1] + (((S[i] - '0')*10 + S[i+1]-'0') < 27 ? dp[i+2] : 0);
	}
	return dp[0];
}

int main()
{
	string S= "12258";
	int res1 = process1(S, 0);
	int res2 = process2(S);
	cout <<res1 << " " << res2 << endl;
	return 0;
}
