#include<iostream>
#include<vector>
using namespace std;


//打表法的应用

class PROBLEM02
{
public:
	//k2>k1
	int process(int k1,int k2,int S)
	{
		int res = 0;
		int num1 = 0;

		int num2 = S / k2;
		int t = 0;//最小公倍数初始化

		//求最小公倍数
		for (int i = 1; i <= k2; i++)   //从1到m倍尝试
		{
			t = k1 * i;
			if ((k1 * i) % k2 == 0)
				break;
		}
		int remain = S - num2 * k2;//全部使用大袋子的话,剩余几个苹果
		while (remain % k1 != 0)
		{
			k2--;
			remain += k2;        //更新剩余的苹果数
			if (remain / t > 0)
			{
				cout << -1 << endl;
				return -1;
			}
		}
		num1 = remain / k1;     //使用num1个小袋子

		res = num1 + num2;
		cout << res << endl;
		S++;

		
		return 0;
	}

	void main_1(int k1, int k2, int SS)
	{
		int S = 1;
		while (S < SS)
		{
			int ans = process(k1, k2, S);
			cout << ans << endl;
			S++;
		}

		return;
	}

};
int main()
{
	int k1 = 6;
	int k2 = 8;
	k1 = min(k1, k2);
	k2 = max(k1, k2);
	int S = 102;
	PROBLEM02 P;
	P.main_1(k1, k2, S);
	return 0;
	
	
}
