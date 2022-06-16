#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PROBLEM03
{
public:
	//以idx字符开始,长度为Len的字符串的数量，,idx表示字符在[a,...,Z]中的位置
	int f(int idx, int Len)
	{
		int sum = 0;
		if (Len == 1)
			return 1;

		for (int i = idx+1; i <= 26; i++)
		{
			sum += f(i, Len-1);
		}
		return sum;
	}
	//得到长度为len的字符串有几个
	int g(int len)
	{
		int sum = 0;
		for (int i = 1; i <= 26; i++)
			sum += f(i, len);
		return sum;
	}
	int process(string str)
	{
		int ans = 0;
		int L = str.size();
		for (int i = 1; i < L; i++)
		{
			ans += g(i);
		}

		int first = str[0] - 'a' + 1;
		for (int i = 1; i < first; i++)
			ans += f(i,L);


		int pre = first;
		for (int i = 1; i < L; i++)
		{
			int newL = str[i] - 'a' + 1;
			for (int j = pre + 1; j < newL; j++)
			{
				ans += f(j, L - i);
			}
			pre = newL;
		}
		return ans + 1;
	}
};

int main()
{
	string str = "ab";
	PROBLEM03 P;
	int ans = P.process(str);
	cout << ans << endl;
	return 0;
}