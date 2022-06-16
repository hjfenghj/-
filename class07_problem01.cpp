#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PROBLEM01
{
public:
	//求得数字的长度
	vector<string> S{ "W","Q","B","S","L" };
	vector<string> S_19 = { "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
							"Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
							"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
							"Eighteen ", "Nineteen " };

	vector<string> S_0 = { "Twenty ", "Thirty ", "Forty ", "Fifty ",
							"Sixty ", "Seventy ", "Eighty ", "Ninety " };

	string str_res = "";

	int pown(int N, int L)
	{
		int res = 1;
		int temp = N;
		while (L != 0)
		{
			
			if (L & 1 == 1)
			{
				res *= temp;
				temp = temp * temp;
			}
			else
				temp = temp * temp;
			L = L >> 1;
		}
		return res;
	}
	//求出每位的数字,并添加单位变成字符串
	string get_string(int N)
	{
		if (N <= 19)
			return S_19[N-1];
		else if (N / 10 / 10 == 0)
			return S_0[N / 10 % 10 - 2];

		//其他情况
		int idx = 4;
		int L = 0;//数字的长度
		while (N / pown(10, idx) == 0)
		{
			idx--;
		}
		L = idx;

		while (L >= 0)
		{
			int cur = N / pown(10, L);
			char flag = 'L';

			if (cur == 0 && str_res[str_res.size() - 1] == flag)
				goto FFF;
			else if (cur == N)
				str_res += to_string(cur);
			else if(cur==0)
				str_res +=  S[4];
			else
				str_res += to_string(cur) + S[4 - L];

			FFF:
			N = N % pown(10,L);
			L = L - 1;
		}
		return str_res;
	}
};

int main()
{
	int  N = 19120;
	PROBLEM01 P;
	string str = P.get_string(N);
	string new_str(str.begin(), str.end() - 1);
	cout << ((str[str.size()-1] == '0') ? new_str : str )<< endl;;
	return 0;
}