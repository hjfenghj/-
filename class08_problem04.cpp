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
			bool flag = true;//�Ƿ���dp[i-1]��Ӱ�췶Χ�ڣ��ҵ�Arr[i]
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

//pre����i-1��β������ظ��ִ��ĳ��ȣ���iλ�ø���dp[i]��ʱ��
//���dp[i-1]Ӱ��ķ�Χ�ڳ�����arr[i].��ôdp[i] = i - temp;
//���dp[i-1]Ӱ��ķ�Χ��û�г���arr[i],��ôdp[i] = i-temp,��ʱ���temp����dp[i-1]������С����ǰ��һ����iλ�õ�dp[i]Ҳ��������Ӱ��
class PROBLEM03_2
{
public:
	int get_res(string str)
	{
		map<int,int> M; //����ÿһ���ַ���һ�����ֵ�λ��,�����ַ���ascii��Χ��0-255
		for (int i = 0; i < 256 ; i++)
		{
			M[i] = -1;
		}

		int pre = -1;//iλ����ǰ��dp[i]�������λ��
		int cur = 0;//�ַ���һ�γ��ֵ�λ��
		int ans = INT_MIN;
		for (int i = 0; i < str.size(); i++)
		{
			pre = max(pre, M[str[i]]);//����iλ�ý���λ�ã���Ϊ�µ�pre
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