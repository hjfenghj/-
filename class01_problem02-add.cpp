#include<iostream>
#include<vector>
using namespace std;


class PROBLEM02_cow_eat_grown
{
public:
	//使用一些列数据打表处理，找到规律，如果给定的N为1个亿，使用迭代递归就会非常耗时间
	//使用打表法占到规律以后，就可以直接得到结果
	int get_res(int N)
	{
		if (N < 5)
		{
			return (N == 0 || N == 2) ? 0 : 1;//0代表后手赢，1代表先手赢
		}
		//N > 5的时候
		int t = 1;//表示从吃一份开始
		while (t <= N)
		{
			//A牛吃完以后，B牛从剩余的草中开始吃，如果从剩余的草中开始,B牛赢了，就表示原始数据中A牛赢了
			if (get_res(N - t) == 0)
				return 1;

			//防止t*4越界
			if (t > N / 4)
				break;
			t *= 4;
		}
		return 0;
	}

	//使用打表法得到的规律
	int get_res2(int N)
	{
		if (N % 5 == 0 || N % 5 == 2)
			return 0;//代表后手赢
		return 1;
	}
};


int main()
{
	int N = 50;
	PROBLEM02_cow_eat_grown P;
	for (int i = 0; i < 50; i++)
	{
		cout << i <<  " " << P.get_res(i) << endl;
	}

	int res = P.get_res2(100000);
	cout << res<< endl;
	return 0;
}