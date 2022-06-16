#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
//
using namespace std;
//
//class PROBLEM06
//{
//	static bool cmp(pair<int const, int> P1, pair<int const, int> P2)
//	{
//		////参数1是堆顶到堆底降序(因为参数1是负数)，参数2堆顶到堆降序
//		return P1.first != P2.first ? P2.first > P1.first : P2.second > P1.second;
//	}
//public:
//	//All_Times   表示时间限制
//	//used_times  表示每个任务需要消耗的天数
//	//get_moneys  表示每个任务得到的回报
//	//D_arr       表示两项任务之间的依赖关系,假如D_arr[0][3] = 1表示任务0是任务3的先修任务
//	void get_res(int All_Times, vector<int> use_times, vector<int> get_money, vector<vector<int>> D_arr)
//	{
//		int L = use_times.size();
//		int end=0;//最后一个节点
//		//使用map储存任务之间的依赖关系
//		map<int, vector<int>> parents;//使用map,方便查找
//		for (int i = 0; i < D_arr.size(); i++)
//		{
//			bool flag = true;
//			for (int j = 0; j < D_arr.size(); j++)
//			{
//				if (D_arr[i][j] == 1)
//				{
//					parents[j].push_back(i);
//					flag = false;
//				}
//			}
//			if (flag)
//				end = i;
//		}
//
//		for (int i = 0; i < 8; i++)
//		{
//			if (parents.find(i) != parents.end())
//			{
//				auto cur = parents.find(i)->second;
//				for (int j = 0; j < cur.size(); j++)
//					cout <<i << "          "<< cur[j] << " ";
//				cout << endl;
//			}
//		}
//		//储存每个节点到任务结束需要的一系列(时间，回报)对
//		map<int,map<int, int>>  t_m_vec;
//		
//		cout << end << endl;
//		queue<int> Q;//遍历所有的节点
//		t_m_vec[end].emplace(-use_times[end], get_money[end]);//使用-use_times是为了下文使用lower_bound函数
//		Q.push(end);
//		int ssss = 1;
//		while (!Q.empty())
//		{
//			int cur = Q.front();
//			Q.pop();
//			for (int c : parents[cur])//表里cur的所有父亲节点，更新父亲节点id对应的t_m_vec
//			{
//				cout << parents[cur].size() << endl;
//				for (auto t_m : t_m_vec.find(cur)->second)
//				{
//					ssss++;
//					int newtime = use_times[c] + abs(t_m.first);
//					int new_money = get_money[c] + t_m.second;
//					t_m_vec[c].emplace(-newtime, new_money);
//				}
//				Q.push(c);
//			}
//		}
//		cout << ssss << endl;
//
//		priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> clean_SET(cmp);//第一次数据清洗，将所有的map中所有pair数据根据pair的首元素进行升序排列
//		for (auto tm : t_m_vec)
//		{
//			for (auto m : tm.second)
//			{
//				clean_SET.push(make_pair(m.first, m.second));
//			}
//		}
//
//		cout << clean_SET.size() << endl;
//		
//		map<int,int> All_Map; //第二次数据清洗，保留时间多，钱数也多的数据;
//		int allsize = 1;
//		auto cur = clean_SET.top();
//		clean_SET.pop();
//		All_Map.emplace(cur.first, cur.second);
//		while (!clean_SET.empty())
//		{
//			if (cur.first != clean_SET.top().first && cur.second < clean_SET.top().second)
//			{
//				allsize++;
//				cur = clean_SET.top();
//				All_Map.emplace(cur.first, cur.second);
//			}
//			clean_SET.pop();
//		}
//		cout << allsize << endl;
//
//		for (auto at : All_Map)
//		{
//			cout << at.first << " " << at.second << endl;
//		}
//
//
//
//
//		int ans = INT_MIN;
//		int T = -All_Times;
//		int old_ans;
//		for(int K = All_Times; K > 0; K--)
//		{
//			if (All_Map.lower_bound(-K) != All_Map.end())
//			{
//				ans = max(ans, All_Map.lower_bound(-K)->second);
//				T = max(T, All_Map.lower_bound(-K)->first);
//				break;
//			}
//
//			
//		}
//		cout << ans << " " << -T << endl;
//		return;
//	}
//};
//
//int main()
//{
//	int allTime = 10;
//	vector<int> revenue = { 2000, 4000, 2500, 1600, 3800, 2600, 4000, 3500 };
//	vector<int> times = { 3, 3, 2, 1, 4, 2, 4, 3 };
//	vector<vector<int>> dependents = {
//			{ 0, 1, 1, 0, 0, 0, 0, 0 },
//			{ 0, 0, 0, 1, 1, 0, 0, 0 },
//			{ 0, 0, 0, 1, 0, 0, 0, 0 },
//			{ 0, 0, 0, 0, 1, 1, 1, 0 },
//			{ 0, 0, 0, 0, 0, 0, 0, 1 },
//			{ 0, 0, 0, 0, 0, 0, 0, 1 },
//			{ 0, 0, 0, 0, 0, 0, 0, 1 },
//			{ 0, 0, 0, 0, 0, 0, 0, 0 } };
//
//	PROBLEM06 P;
//	P.get_res(allTime, times, revenue, dependents);
//	return 0;
//}


class PROBLEM06
{
	static bool cmp(pair<int const, int> P1, pair<int const, int> P2)
	{
		//参数1是堆顶到堆底降序(因为参数1是负数)，参数2堆顶到堆降序
		return P1.first != P2.first ? P2.first > P1.first : P2.second > P1.second;
	}
public:
	//All_Times   表示时间限制
	//used_times  表示每个任务需要消耗的天数
	//get_moneys  表示每个任务得到的回报
	//D_arr       表示两项任务之间的依赖关系,假如D_arr[0][3] = 1表示任务0是任务3的先修任务
	void get_res(int All_Times, vector<int> use_times, vector<int> get_money, vector<vector<int>> D_arr)
	{
		int L = use_times.size();
		int end = 0;//最后一个节点
		//使用map储存任务之间的依赖关系
		map<int, vector<int>> parents;//使用map,方便查找
		for (int i = 0; i < D_arr.size(); i++)
		{
			bool flag = true;
			for (int j = 0; j < D_arr.size(); j++)
			{
				if (D_arr[i][j] == 1)
				{
					parents[j].push_back(i);
					flag = false;
				}
			}
			if (flag)
				end = i;
		}
		//储存每个节点开始到任务结束需要的一系列(时间，回报)对
		map<int, map<int, int>>  t_m_vec;
		queue<int> Q;//遍历所有的节点
		t_m_vec[end].emplace(-use_times[end], get_money[end]);//使用-use_times是为了下文使用lower_bound函数
		Q.push(end);
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			for (int c : parents[cur])//表里cur的所有父亲节点，更新父亲节点id对应的t_m_vec
			{
				for (auto t_m : t_m_vec.find(cur)->second)
				{
					int newtime = use_times[c] + abs(t_m.first);
					int new_money = get_money[c] + t_m.second;
					t_m_vec[c].emplace(-newtime, new_money);
				}
				Q.push(c);
			}
		}
		//第一次数据清洗，将所有的map中所有pair数据根据cmp规则排序
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> clean_SET(cmp);
		for (auto tm : t_m_vec)
		{
			for (auto m : tm.second)
			{
				clean_SET.push(make_pair(m.first, m.second));
			}
		}


		//第二次数据清洗，保留时间多，回报也多的数据;
		map<int, int> All_Map; 
		int allsize = 1;
		auto cur = clean_SET.top();
		clean_SET.pop();
		All_Map.emplace(cur.first, cur.second);
		while (!clean_SET.empty())
		{
			if (cur.first != clean_SET.top().first && cur.second < clean_SET.top().second)
			{
				allsize++;
				cur = clean_SET.top();
				All_Map.emplace(cur.first, cur.second);
			}
			clean_SET.pop();
		}

		//寻找结果
		int ans = INT_MIN;
		int T = -All_Times;
		int old_ans;
		for (int K = All_Times; K > 0; K--)
		{
			if (All_Map.lower_bound(-K) != All_Map.end())
			{
				ans = max(ans, All_Map.lower_bound(-K)->second);
				T = max(T, All_Map.lower_bound(-K)->first);
				break;
			}
		}
		cout << ans << " " << -T << endl;
		return;
	}
};

int main()
{
	int allTime = 10;
	vector<int> revenue = { 2000, 4000, 2500, 1600, 3800, 2600, 4000, 3500 };
	vector<int> times = { 3, 3, 2, 1, 4, 2, 4, 3 };
	vector<vector<int>> dependents = {
			{ 0, 1, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 } };

	PROBLEM06 P;
	P.get_res(allTime, times, revenue, dependents);
	return 0;
}