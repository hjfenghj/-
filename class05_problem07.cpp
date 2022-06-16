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
	priority_queue<Job> Jobarr;//�����Ĺ�����������
	map<int,int> JobArr_dowm;////������������ͬ�����Ѷȱ���Ǯ��ģ��Ѷȱ��ǮҲ��Ҫ���

	//�����еĹ��������ϣ����ÿ�ֹ���ֻ���±�������
	static bool cmp(Job J1, Job J2)
	{
		//�Ѷȴ���ں��Ѷ���ͬ��Ǯ�������ǰ
		return J1.hard == J2.hard ? J2.money < J2.money : J2.hard > J1.hard;
	}

	void get_sort_Jobarr(vector<Job> Arr)
	{
		for (int i = 1; i < Arr.size(); i++)
		{
			Jobarr.push(Arr[i]);
		}

		//������������ͬ�����Ѷȱ���Ǯ��ģ���ͬ�Ѷȵ���Ǯ��ȣ��ͱ������ѵȼ��͵�
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
			//lower_bound��ʾ�ҵ����ڵ��ڸ���ֵ�õ�һ��Ԫ�أ���Ϊ������Ҫ�ҵ�С�ڵ��ڹ��������õ�һ�ֹ���
			//���Լ��˸��ţ�
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