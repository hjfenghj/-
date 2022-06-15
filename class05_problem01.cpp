#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//递归加回溯写法
class PROBLEM01
{
public:
	//idx代表目前字符串的长度
	//s目前字符串
	//N目标长度
	int get_res(vector<char> s, int N, int idx)
	{
		int ans = 0;
		//截至条件，每一个达到目标的叶节点
		if (s.size() == N)
			return 1;
		//上一个字符为'1'，下一个字符有两种情况
		if (s[idx - 1] == '1')
		{
			s.push_back('1');
			ans += get_res(s, N, idx + 1);
			//回溯
			s[idx] = '0';
			ans += get_res(s, N, idx + 1);

		}
		//上一个字符为'0',下一个字符只有一种情况
		if (s[idx - 1] == '0')
		{
			s.push_back('1');
			ans += get_res(s, N, idx + 1);
		}
		return ans;
	}

	int MAIN(int T)
	{
		int ans = 0;
		vector<char> Arr1;
		Arr1.push_back('0');
		PROBLEM01 P1;
		ans = P1.get_res(Arr1, T, 1);
		Arr1[0] = '1';
		ans += P1.get_res(Arr1, T, 1);
		cout << ans << endl;
		return 0;
	}
};

//斐波那契数列写法,复杂度O(N)
class PROBLEM01_2
{
public:
	int get_res(int N)
	{
		vector<int> res(N+1,0);
		res[0] = 1;
		res[1] = 2;
		for (int i = 2; i <= N; i++)
		{
			res[i] = res[i - 1] + res[i - 2];
		}
		cout << res[N] << endl;
		return 0 ;
	}
};


//斐波那契数列进阶模式，复杂度O(logN)
class PROBLEM01_3
{
public:
	int get_res(int N)
	{
		vector<vector<int>> M = { {1,1},{1,0} };//初始转换矩阵
		vector<int> base = { 3,2 };//起始项
		
		vector<vector<int>> M_N1(M.size(), vector<int>(M.size(), 0));//最终的转化矩阵
		//初始化为对角矩阵
		for (int i = 0; i < M.size(); i++)
			M_N1[i][i] = 1;

		int temp = N - 2;//转换矩阵需要N-2次方
		while (temp != 0)
		{
			if (temp & 1 == 1)
			{
				M_N1 = POW(M_N1, M);
				M = POW(M, M);
			}
			else
				M = POW(M, M);
			temp = temp >> 1;
		}

		vector<int> res = DOT(base, M_N1);
		return res[0];
	}
	vector<vector<int>> POW(vector<vector<int>> Arr1, vector<vector<int>> Arr2)
	{
		vector<vector<int>> res(Arr1.size(),vector<int>(Arr2[0].size(),0));
		for (int i = 0; i < Arr1.size(); i++)
		{
			for (int j = 0; j < Arr2.size(); j++)
			{
				for(int k=0;k<Arr1[0].size();k++)
					res[i][j] += Arr1[i][k] * Arr2[k][j];
			}
		}
		return res;
	}

	vector<int> DOT(vector<int> Arr, vector<vector<int>> M)
	{
		int L = Arr.size();
		vector<int> res(L, 0);
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < L; j++)
			{
					res[i] += Arr[j] * M[j][i];
			}
		}
		return res;
	}
	
};

int main()
{
	int T = 4;
	PROBLEM01 P;
	P.MAIN(4);
	PROBLEM01_2 P2;
	P2.get_res(4);
	PROBLEM01_3 P3;
	cout << P3.get_res(4) << endl;
	return 0;
}