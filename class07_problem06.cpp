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
//		////����1�ǶѶ����ѵ׽���(��Ϊ����1�Ǹ���)������2�Ѷ����ѽ���
//		return P1.first != P2.first ? P2.first > P1.first : P2.second > P1.second;
//	}
//public:
//	//All_Times   ��ʾʱ������
//	//used_times  ��ʾÿ��������Ҫ���ĵ�����
//	//get_moneys  ��ʾÿ������õ��Ļر�
//	//D_arr       ��ʾ��������֮���������ϵ,����D_arr[0][3] = 1��ʾ����0������3����������
//	void get_res(int All_Times, vector<int> use_times, vector<int> get_money, vector<vector<int>> D_arr)
//	{
//		int L = use_times.size();
//		int end=0;//���һ���ڵ�
//		//ʹ��map��������֮���������ϵ
//		map<int, vector<int>> parents;//ʹ��map,�������
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
//		//����ÿ���ڵ㵽���������Ҫ��һϵ��(ʱ�䣬�ر�)��
//		map<int,map<int, int>>  t_m_vec;
//		
//		cout << end << endl;
//		queue<int> Q;//�������еĽڵ�
//		t_m_vec[end].emplace(-use_times[end], get_money[end]);//ʹ��-use_times��Ϊ������ʹ��lower_bound����
//		Q.push(end);
//		int ssss = 1;
//		while (!Q.empty())
//		{
//			int cur = Q.front();
//			Q.pop();
//			for (int c : parents[cur])//����cur�����и��׽ڵ㣬���¸��׽ڵ�id��Ӧ��t_m_vec
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
//		priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> clean_SET(cmp);//��һ��������ϴ�������е�map������pair���ݸ���pair����Ԫ�ؽ�����������
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
//		map<int,int> All_Map; //�ڶ���������ϴ������ʱ��࣬Ǯ��Ҳ�������;
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
		//����1�ǶѶ����ѵ׽���(��Ϊ����1�Ǹ���)������2�Ѷ����ѽ���
		return P1.first != P2.first ? P2.first > P1.first : P2.second > P1.second;
	}
public:
	//All_Times   ��ʾʱ������
	//used_times  ��ʾÿ��������Ҫ���ĵ�����
	//get_moneys  ��ʾÿ������õ��Ļر�
	//D_arr       ��ʾ��������֮���������ϵ,����D_arr[0][3] = 1��ʾ����0������3����������
	void get_res(int All_Times, vector<int> use_times, vector<int> get_money, vector<vector<int>> D_arr)
	{
		int L = use_times.size();
		int end = 0;//���һ���ڵ�
		//ʹ��map��������֮���������ϵ
		map<int, vector<int>> parents;//ʹ��map,�������
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
		//����ÿ���ڵ㿪ʼ�����������Ҫ��һϵ��(ʱ�䣬�ر�)��
		map<int, map<int, int>>  t_m_vec;
		queue<int> Q;//�������еĽڵ�
		t_m_vec[end].emplace(-use_times[end], get_money[end]);//ʹ��-use_times��Ϊ������ʹ��lower_bound����
		Q.push(end);
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			for (int c : parents[cur])//����cur�����и��׽ڵ㣬���¸��׽ڵ�id��Ӧ��t_m_vec
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
		//��һ��������ϴ�������е�map������pair���ݸ���cmp��������
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> clean_SET(cmp);
		for (auto tm : t_m_vec)
		{
			for (auto m : tm.second)
			{
				clean_SET.push(make_pair(m.first, m.second));
			}
		}


		//�ڶ���������ϴ������ʱ��࣬�ر�Ҳ�������;
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

		//Ѱ�ҽ��
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