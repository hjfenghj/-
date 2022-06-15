#include<iostream>
#include<vector>

using namespace std;

int process1(int N)
{
	int res = 0;
	if (N < 2)
		return 1;
	else if (N == 2)
		return 2;
	for (int i = 0; i <= N - 1; i++)
	{
		int leftnum = process1(i);
		int rightnum = process1(N - i - 1);
		res += (leftnum * rightnum);
	}
	return res;
}


int process2(int N)
{
	int res = 0;
	if (N < 2)
		return 1;
	else if (N == 2)
		return 2;
	vector<int> dp(N, 1);


	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
			dp[i] += (dp[j] * dp[i-j-1]);
	}
	return dp[N - 1];
}

int main()
{
	int N = 10;
	int res1 = process1(10);
	int res2 = process2(10);
	cout << res1 << " " <<res2<<endl;

	return 0;
}
