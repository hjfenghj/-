#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;

class Node
{
public:
	string str;
	int times;
	Node(string s, int t)
	{
		str = s;
		times = t;
	}
};

class PROBLEM07
{
public:
	static bool compare(Node N1, Node N2)
	{
		return N2.times > N1.times;
	}

	vector<string> get_res(vector<string> S,int T)
	{
		//词频统计
		map<string, int> M;
		for (auto str : S)
		{
			if (M.find(str) != M.end())
				M[str]++;
			else
				M[str] = 1;
		}
		//使用小根堆
		priority_queue<Node,vector<Node>,decltype(&compare)> PQ(compare);
		for (auto kv : M)
		{
			if (PQ.size() < T)
			{				
				PQ.emplace(Node(kv.first, kv.second));
			}
			else
			{
				if (PQ.top().times < kv.second)
				{
					PQ.pop();
					PQ.emplace(Node(kv.first, kv.second));
				}
			}
		}
		vector<string> res;
		for (int i = 0; i < T;i++)
		{
			res.push_back(PQ.top().str);
			PQ.pop();
		}
		return res;
	}
};

int main()
{
	vector<string>  S{ "a","b","c","f","s","a","b","c","r","a","b","f","f","f","f","f","s","s","s" };
	PROBLEM07 P;
	vector<string> res = P.get_res(S, 2);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}