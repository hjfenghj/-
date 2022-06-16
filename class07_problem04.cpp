#include<iostream>
#include<vector>

using namespace std;

class PROBLEM04
{
public:

	// pre 表示已经花费的C币    可变
	// end 表示目的积分       
	// add 表示点赞一次花费的C币
	// mul 表示送礼一次花费的C币
	// del 表示私聊一次花费的C币
	// cur 表示目前到达的积分     可变
 	// coinlimit 表示花费不会超过coinlimit个C币
	// endlimit  表示积分不会超过endlimit个积分
	int process1(int pre, int end, int add, int mul, int del, int cur, int coinlimit, int endlimit)
	{
		//无效解
		if (cur >= endlimit || cur<0)
			return INT_MAX;
		if (pre >= coinlimit)
			return INT_MAX;

		if (cur == end)
			return pre;
		//三种情况
		int ans = INT_MAX;
		int p1 = process1(pre + add, end, add, mul, del, cur + 2, coinlimit, endlimit);
		if (p1 != INT_MAX)
			ans = min(ans, p1);

		int p2 = process1(pre + mul, end, add, mul, del, cur * 2, coinlimit, endlimit);
		if (p2 != INT_MAX)
			ans = min(ans, p2);

		int p3 = process1(pre + del, end, add, mul, del, cur - 2, coinlimit, endlimit);
		if (p3 != INT_MAX)
			ans = min(ans, p3);

		return ans;
	}

	//动态规划解
	int proecess2()
	{

	}
};

int main()
{
	int pre = 0;
	int end = 100;
	int add = 1;
	int mul = 2;
	int del = 6;
	int cur = 4;
	int coinlimit = (end - cur) / 2;
	int endlimit = 2 * end;
	PROBLEM04 P;
	int ans = P.process1(pre, end, add, mul, del, cur, coinlimit, endlimit);
	cout << ans << endl;
	return 0;
}