#include<iostream>
#include<vector>
#include<set>
#include <algorithm>

using namespace std;


/*******************
* 得到两个集合两个集合已经是有序的集合，直接使用下边的code处理
********************/
class PROBLEM02_1
{
public:	
	//计算两个数组的平均值
	vector<float> get_mean(set<int> SET1, set<int> SET2)
	{
		vector<float> res_mean(2, 0);
		float S1 = 0;
		float S2 = 0;
		for (int s1 : SET1)
			S1 += s1;
		for (int s2 : SET2)
			S2 += s2;
		res_mean[0] = S1 / SET1.size();
		res_mean[1] = S2 / SET2.size();
		return res_mean;
	}

	//从某范围中去除数组中满足的最小值
	//找到数组中大于M的最小元素,找不到返回-1
	int get_minval(set<int> Arr, vector<float> M)
	{
		//找到数组Arr中大于小均值的第一个数，如果这个数大于等于大均值返回-1;
		int f1 = int(M[0]) + 1;
		int f2 = int(M[1]);
		for (f1; f1 < f2; f1++)
		{
			if (Arr.find(f1) != Arr.end())
			{
				return f1;
			}
		}
		return -1;
	}

	//调整两个数组元素
	//将元素从前者取出，放入后者中
	vector<float> change_Arr(set<int>& SET1, set<int>& SET2, int C)
	{
		SET2.insert(C);
		SET1.erase(C);
		vector<float> new_mean(2, 0);
		new_mean = get_mean(SET1, SET2);
		return new_mean;
	}

	int get_res(set<int>& SET1, set<int>& SET2)
	{
		int ans = 0;
		vector<float> M = get_mean(SET1, SET2);
		if (M[0] == M[1])
			return 0;
		while (M[0] != M[1])
		{
			if (M[0] < M[1])
			{
				int temp = get_minval(SET2, M);
				//如果找不到能拿出的目标元素,就退出
				if (temp == -1)
					break;
				//调整两个数组
				change_Arr(SET2, SET1, temp);
				//更新均值数组
				M = get_mean(SET1, SET2);
			}
			else
			{
				int temp = get_minval(SET1, M);
				if (temp == -1)
					break;
				//调整两个数组
				change_Arr(SET1, SET2, temp);
				//更新均值数组
				M = get_mean(SET1, SET2);
			}
			ans++;
		}
		return ans;
	}
};


class PROBLEM02_2
{
public:
	//计算两个数组的平均值
	vector<float> get_mean(set<int> SET1, set<int> SET2)
	{
		vector<float> res_mean(2, 0);
		float S1 = 0;//注意和使用float，否则除于长度求出的均值会损失小数部分
		float S2 = 0;
		for (int s1 : SET1)
			S1 += s1;
		for (int s2 : SET2)
			S2 += s2;
		res_mean[0] = S1 / SET1.size();
		res_mean[1] = S2 / SET2.size();
		return res_mean;
	}

	//从某范围中去除数组中满足的最小值
	//找到数组中大于L的最小元素,找不到返回-1
	int get_minval(set<int> Arr, vector<float> M)
	{
		int ans = 0;
		if (Arr.upper_bound(int(M[0])) != Arr.end())
		{
			ans = *Arr.upper_bound(int(M[0]));
			ans = ans < int(M[1]) ? ans : -1;
		}
		return ans;
	}

	//调整两个数组的均值
	//将元素从前者取出，放入后者中
	vector<float> change_Arr(set<int>& SET1, set<int>& SET2, int C)
	{
		SET2.insert(C);
		SET1.erase(C);
		vector<float> new_mean(2, 0);
		new_mean = get_mean(SET1, SET2);
		return new_mean;
	}

	int get_res(set<int>& SET1, set<int>& SET2)
	{
		int ans = 0;
		vector<float> M = get_mean(SET1, SET2);
		if (M[0] == M[1])
			return 0;
		while (M[0] != M[1])
		{
			if (M[0] < M[1])
			{
				int temp = get_minval(SET2, M);
				//如果找不到能拿出的目标元素,就退出
				if (temp == -1)
					break;
				//在老均值基础上改变均值
				if (SET1.find(temp) != SET1.end())
					continue;//进入下个循环
				else
					M[0] = (M[0] * SET1.size() + temp) / (SET1.size() + 1);

				M[1] = (M[1] * SET2.size() - temp) / (SET2.size() - 1);

				//调整数组
				change_Arr(SET2, SET1, temp);
			}
			else
			{
				int temp = get_minval(SET1, M);
				if (temp == -1)
					break;
				//在以上的均值基础上改变均值
				if (SET2.find(temp) != SET2.end())
					continue;
				else
					M[1] = (M[1] * SET2.size() + temp) / (SET2.size() + 1);

				M[0] = (M[0] * SET1.size() - temp) / (SET1.size() - 1);
				change_Arr(SET1, SET2, temp);
			}
			ans++;
		}
		return ans;
	}
};

/*******************
* 输入两个数组，且不知是否有序
********************/
class Problem02_3
{
public:
	int get_res(vector<int>& Arr1, vector<int>& Arr2)
	{
		int ops = 0;
		float sum1 = 0;
		for (int i = 0; i < Arr1.size(); i++)
			sum1 += Arr1[i];
		float sum2 = 0;
		for (int i = 0; i < Arr2.size(); i++)
			sum2 += Arr2[i];
		if (avg(sum1, Arr1.size()) == avg(sum2, Arr2.size()))
			return 0;

		vector<int> maxArr;
		vector<int> minArr;
		float maxsum= 0;
		float minsum = 0;
		//重定向均值较大的数组 
		//重定向均值较大的数组的总和
		if (avg(sum1, Arr1.size()) > avg(sum2, Arr2.size()))
		{
			maxArr = Arr1;
			maxsum = sum1;
			minArr = Arr2;
			minsum = sum2;
		}
		else
		{
			maxArr = Arr2;
			maxsum = sum2;
			minArr = Arr1;
			minsum - sum1;
		}
		//较大的数组数组排序
		sort(maxArr.begin(), maxArr.end());
		set<int> setmin;//较小的数组集合化，默认是递增的集合
		for (int n : minArr)
			setmin.insert(n);

		float maxlen = maxArr.size();
		float minlen = minArr.size();

		for (int i = 0; i < maxArr.size(); i++)
		{
			float cur = float(maxArr[i]);
			if (cur < avg(maxsum, maxlen) && cur > avg(minsum, minlen) && setmin.find(cur) != setmin.end())
			{
				sum1 -= cur;
				maxlen--;
				sum2 += cur;
				minlen++;
				ops++;
			}
		}
		return ops;
	}


	float avg(float S, int L)
	{
		return S / L;
	}

};


int main()
{
	set<int> SET1 = { 1,2,5 };
	set<int> SET2 = { 2,3,4,5,6 };
	set<int> SET3 = { 1,2,5 };
	set<int> SET4 = { 2,3,4,5,6 };
	PROBLEM02_1 P1;
	PROBLEM02_2 P2;
	cout << P1.get_res(SET1,SET2) << endl;
	cout << P2.get_res(SET3,SET4) << endl;

	vector<int> Arr1 = { 1,2,5 };
	vector<int> Arr2 = { 2,3,4,5,6 };
	Problem02_3 P3;
	cout << P3.get_res(Arr1, Arr2) << endl;
	return 0;
}
