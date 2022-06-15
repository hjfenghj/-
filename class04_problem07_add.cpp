#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
public:
	int timestamp;
	int id;
	Node(int t, int i)
	{
		timestamp = t;
		id = i;
	}
	Node() {};
};

class PROBLEM07_add
{
public:
	vector<int> eat_all;//表示每个人都拿到咖啡时候的时间
	
	static bool cmp(Node N1, Node N2)
	{
		return N2.timestamp + N2.id > N1.timestamp + N1.id;
	}

	//得到N个人每个人拿到咖啡时候的时间
	void get_eat_all(int N)
	{
		priority_queue<Node, vector<Node>, decltype(&cmp)> minheap(cmp);
		minheap.emplace(Node(0, 2));
		minheap.emplace(Node(0, 3));
		minheap.emplace(Node(0, 7));

		for (int i = 0; i < N; i++)
		{
			Node cur = minheap.top();
			eat_all.push_back(cur.timestamp + cur.id);
			minheap.pop();
			minheap.emplace(Node(cur.timestamp+cur.id,cur.id));
		}
		return;
	}	

	//返回最短的时间,递归暴力处理方法
	//Arr是每个人拿到咖啡需要等待的时间
	//a表示使用机器洗杯子一个需要用时
	//b表示使用挥发洗杯子用时
	//idx表示从idx个人的杯子开始到最后一个杯子干净需要的最小用时
	//wirtim洗当下第一个杯子需要等待的时长
	int process1(vector<int> Arr, int a, int b, int idx, int witim)
	{
		/*if (idx == Arr.size())
			return 0;*/
		if (idx == Arr.size() - 1)
		{
			return min(max(Arr[idx], witim) + a, Arr[idx] + b);
		}
		//选择使用咖啡机洗当前的首个杯子，一个杯子需要耗时a
		int use_time = max(Arr[idx],witim) + a;
		int next_time = process1(Arr, a, b, idx + 1, use_time);
		int a_t = max(use_time, next_time);

		//选择使用挥发洗当前的首个杯子，一个杯子耗时b
		int use_time1 = Arr[idx] + b;
		int next_time2 = process1(Arr, a, b, idx + 1, witim);
		int b_t = max(use_time1, next_time2);

		return min(a_t, b_t);
	}
	void main_1(vector<int> Arr, int a, int b)
	{
		int ans =  process1(eat_all, a, b, 0, 0);
		cout << ans << endl;
		return;
	}


	//暴力递归改为动态规划
	//dp[0][0]表示从第1个人的拿到碗的时间开始，起始等待时间为0时，到洗完为止的时间
	int process2(vector<int> Arr,int a,int b)
	{
		int N = Arr.size();
		int raw = N;
		int col = Arr[N - 2] + (N - 1) * a;
		vector<vector<int>> dp(raw, vector<int>(col, 0));
		//根据上边暴力递归方法的basecase截至条件写出第N行的数据
		for(int j = 0;j<col;j++)
			dp[N-1][j] = min(max(Arr[N-1], j) + a, Arr[N-1] + b);
		//根据依赖写出
		for (int i = N - 2; i >= 0; i--)
		{
			int newcol = Arr[i] + (i + 1) * a;
			for (int j = 0; j < newcol; j++)
			{
				int wash = max(Arr[i], j) + a;
				dp[i][j] = min(max(wash, dp[i + 1][j]), max(Arr[i] + b, dp[i + 1][j]));
			}
		}
		return dp[0][0];
	}

	void main_2(vector<int> Arr, int a, int b)
	{
		int ans = process2(eat_all, a, b);
		cout << ans << endl;
		return;
	}


};

int main()
{
	int N = 10;
	int a = 4;
	int b = 5;
	PROBLEM07_add P;
	P.get_eat_all(N);
	P.main_1(P.eat_all,a,b);
	P.main_2(P.eat_all, a, b);
	return 0;
}