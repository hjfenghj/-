#include<iostream>
#include<vector>

using namespace std;


class PROBLEM01_1
{
/*
* 假设绳子左端刚好把某节点发改完毕，比如说数组[2,4,....]，假设绳子左端刚好压在第1个节点上，和第三个节点上
* 根据绳子右端到达的位置更新结果
*/
public:
	int process_1(vector<int> Arr, int L)
	{
		int start = 0;
		int end = 0;
		int res = 0;//绳子覆盖的节点数量
		for (int i = 0; i < Arr.size(); i++)
		{
			if (L < Arr[i])
				break;
			end = i;//绳子末尾覆盖到的节点
		}
		res = end - start + 1;//绳子从首节点出发覆盖的节点数

		int LL = L - Arr[end];//绳子覆盖最后一个节点后还剩余多长

		for (int start = 1; start < Arr.size(); start++)
		{
			//左端右移,增加绳子剩余的长度,注意数组的格式为累加值
			if (start == 1)
				LL = LL + Arr[start - 1];
			else
				LL = LL + (Arr[start - 1] - Arr[start - 2]);


			int temp = res - 1;
			while (LL >= (Arr[end + 1] - Arr[end]))
			{
				temp++;
				end++;
				if (end + 1 == Arr.size())
				{
					return res;
				}
				LL = LL - (Arr[end + 1] - Arr[end]);
			}
			res = max(temp, res);
		}
		return res;
	}

	void mian_1(vector<int> Arr,int len)
	{
		int res = process_1(Arr, len);
		cout << res << endl;
		return;
	}
};

class PROBLEM01_2
{
/*
* 假设绳子右端刚好覆盖完某节点，求绳子左端所在位置
* 设定绳子右端节点位置，根据左端位置位置更新结果
*/
public:
	//返回列表中索引R以前部分第一个大于等于某值的索引
	//val表示寻找的目标值
	int process_2(vector<int> Arr, int val, int R)
	{
		int L = 0;
		int index = R;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (Arr[mid] >= val)
			{
				index = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		return index;
	}

	void main_2(vector<int> Arr, int len)
	{
		int max_L = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			max_L = max(max_L, i - process_2(Arr, Arr[i] - len, i) + 1);
		}
		cout << max_L << endl;
		return;
	}
	
};

class PROBLEM01_3
{
/*
* 第一种方法的递归写法
*/
public:
	//Arr 原始节点数组的变换，新的数组表示每个元素代表i-1位置到i位置的节点数
	//L_ptr 绳子左侧完全压到的节点
	//R_ptr 绳子右侧完全压倒的节点
	//len  在除去start到end的范围后,绳子还剩余的长度
	//res  表示覆盖的节点数
	//代表绳子从Arr索引L_ptr出发，到R_ptr结束还剩下Len的富余，前闭后开[L_ptr,R_ptr)
	int process_3(vector<int> Arr, int L_ptr, int R_ptr, int Len, int res)
	{
		if (R_ptr >= Arr.size())
			return res;											   
		int r = 0;
		if (Len < Arr[R_ptr])
			r = process_3(Arr, L_ptr + 1, R_ptr, Len + Arr[L_ptr], max(res, R_ptr - L_ptr + 1));
		else if (Len >= Arr[R_ptr])
			r = process_3(Arr, L_ptr, R_ptr + 1, Len - Arr[R_ptr], max(res, R_ptr - L_ptr));
		return r;
	}

	void main_3(vector<int> Arr, int len)
	{
		vector<int> new_arr(Arr.size(), 0);
		new_arr[0] = Arr[0];
		for (int i = 1; i < Arr.size(); i++)
			new_arr[i] = Arr[i] - Arr[i - 1];

		int ans = process_3(new_arr,0,0,len,0);
		cout << ans << endl;
		return;
	}
};

int main()
{
	vector<int> Arr = { 0, 13, 24, 35, 46, 57, 60, 72, 87 };
	int len = 8;
	PROBLEM01_1 P1;
	P1.mian_1(Arr, len);
	PROBLEM01_2 P2;
	P2.main_2(Arr, len);
	PROBLEM01_3 P3;
	P3.main_3(Arr, len);
	return 0;
}
