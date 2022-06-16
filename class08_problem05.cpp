#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PROBLEM05
{
public:
	int ic;
	int dc;
	int rc;
	PROBLEM05(int i, int d, int r)
	{
		ic = i;
		dc = d;
		rc = r;
	}

	int get_res(string str1, string str2)
	{
		int L1 = str1.size();
		int L2 = str2.size();
		vector<vector<int>> dp(L1+1, vector<int>(L2+1, 0));
		dp[0][0] = 0;

		for (int i = 1; i <= L2; i++)
			dp[0][i] = ic * i;
		for (int i = 1; i <= L1; i++)
			dp[i][0] = dc * i;

		for (int i = 1; i <= L1; i++)
		{
			for (int j = 1; j <= L2; j++)
			{
				
				//仿照力扣72题的思路，力扣72是求操作数；
				if (str1[i-1]-str2[j-1] == 0)
					dp[i][j] = min(dp[i - 1][j] + dc, min(dp[i][j - 1] + ic, dp[i - 1][j - 1]));
				else
					dp[i][j] = min(dp[i - 1][j] + dc, min(dp[i][j - 1] + ic, dp[i - 1][j - 1]+rc));
			}
		}
		return dp[L1][L2];
	}
};

int main()
{
	string s1 = "abd";
	string s2 = "add";
	PROBLEM05 P(5,3,2);
	int ans = P.get_res(s1,s2);
	cout << ans << endl;
	return 0;
}