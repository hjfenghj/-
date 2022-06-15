#include<iostream>
#include<string>
#include<vector>
using namespace std;

int get_res(string S)
{
	int res = 0;
	vector<int> dp(S.size(), 0);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == ')')
		{
			int pre = i - 1 - dp[i - 1];
			if (pre >= 0 && S[pre] == '(')
			{
				dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}