#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Job
{
public:
	int money;
	int hard;
	Job(int m,int h)
	{
		money = m;
		hard = h;
	}
};

class PROBLEM02
{
public:
	priority_queue<Job> Jobarr;//将给的工作数组排序
	map<int,int> JobArr_dowm;////工作降采样，同样的难度保留钱多的，难度表达钱也需要变大

	//将所有的工作存入哈希表，且每种工作只留下报酬最多的
	static bool cmp(Job J1, Job J2)
	{
		//难度大的在后，难度相同的钱数多的在前
		return J1.hard == J2.hard ? J2.money < J2.money : J2.hard > J1.hard;
	}

	void get_sort_Jobarr(vector<Job> Arr)
	{
		for (int i = 1; i < Arr.size(); i++)
		{
			Jobarr.push(Arr[i]);
		}

		//工作降采样，同样的难度保留钱多的，不同难度但是钱相等，就保留困难等级低的
		JobArr_dowm.emplace(-Jobarr.top().hard, Jobarr.top().money);
		Job cur = Jobarr.top();
		Jobarr.pop();
		while (!Jobarr.empty())
		{
			if (Jobarr.top().hard != cur.hard && Jobarr.top().money > cur.money)
			{
				cur = Jobarr.top();
				Jobarr.pop();
				JobArr_dowm.emplace(-cur.hard, cur.money);
			}
		}
	}
	int get_res(vector<int> ability)
	{
		vector<int> ans(ability.size(), 0);
		int res = 0;
		for (int i = 0; i < ability.size(); i++)
		{
			//lower_bound表示找到大于等于给定值得第一个元素，因为我们需要找到小于等于工作能力得第一分工作
			//所以加了负号；
			if (JobArr_dowm.lower_bound(-ability[i]) != JobArr_dowm.end())
			{
				ans[i] = JobArr_dowm.upper_bound(-ability[i])->second;
				res += JobArr_dowm.upper_bound(-ability[i])->second;
			}
		}
		cout << res << endl;
		return 0;
	}
};