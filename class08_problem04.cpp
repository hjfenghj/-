#include<iostream>
#include<vector>
#include<map>
using namespace std;

class PROBLEM03_1
{
public:
	int get_res(string str)
	{
		vector<int> dp(str.size(), 0);
		dp[0] = 1;
		int ans = INT_MIN;
		for (int i = 1; i < str.size(); i++)
		{
			int j = 1;
			bool flag = true;//是否在dp[i-1]的影响范围内，找到Arr[i]
			while (j <= dp[i-1])
			{
				if (str[i - j] == str[i])
				{
					dp[i] = j;
					flag = false;
					break;
				}
				j++;
			}
			if(flag)
				dp[i] = dp[i - 1] + 1;

			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

//pre代表i-1结尾的最长无重复字串的长度，在i位置更新dp[i]的时候
//如果dp[i-1]影响的范围内出现了arr[i].那么dp[i] = i - temp;
//如果dp[i-1]影响的范围内没有出现arr[i],那么dp[i] = i-temp,这时候的temp就是dp[i-1]包含的小区域前的一个，i位置的dp[i]也不能跳过影响
class PROBLEM03_2
{
public:
	int get_res(string str)
	{
		map<int,int> M; //储存每一个字符上一个出现的位置,所有字符的ascii范围是0-255
		for (int i = 0; i < 256 ; i++)
		{
			M[i] = -1;
		}

		int pre = -1;//i位置往前跳dp[i]步到达的位置
		int cur = 0;//字符上一次出现的位置
		int ans = INT_MIN;
		for (int i = 0; i < str.size(); i++)
		{
			pre = max(pre, M[str[i]]);//距离i位置近的位置，作为新的pre
			ans = max(ans, i - pre);
			M[str[i]] = i;
		}
		return ans;
	}
};

int main()
{
	string str = "abcabcbb";
	PROBLEM03_2 P;
	int ans = P.get_res(str);
	cout << ans << endl;
	return 0;
}