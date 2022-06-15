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
	vector<int> eat_all;//��ʾÿ���˶��õ�����ʱ���ʱ��
	
	static bool cmp(Node N1, Node N2)
	{
		return N2.timestamp + N2.id > N1.timestamp + N1.id;
	}

	//�õ�N����ÿ�����õ�����ʱ���ʱ��
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

	//������̵�ʱ��,�ݹ鱩��������
	//Arr��ÿ�����õ�������Ҫ�ȴ���ʱ��
	//a��ʾʹ�û���ϴ����һ����Ҫ��ʱ
	//b��ʾʹ�ûӷ�ϴ������ʱ
	//idx��ʾ��idx���˵ı��ӿ�ʼ�����һ�����Ӹɾ���Ҫ����С��ʱ
	//wirtimϴ���µ�һ��������Ҫ�ȴ���ʱ��
	int process1(vector<int> Arr, int a, int b, int idx, int witim)
	{
		/*if (idx == Arr.size())
			return 0;*/
		if (idx == Arr.size() - 1)
		{
			return min(max(Arr[idx], witim) + a, Arr[idx] + b);
		}
		//ѡ��ʹ�ÿ��Ȼ�ϴ��ǰ���׸����ӣ�һ��������Ҫ��ʱa
		int use_time = max(Arr[idx],witim) + a;
		int next_time = process1(Arr, a, b, idx + 1, use_time);
		int a_t = max(use_time, next_time);

		//ѡ��ʹ�ûӷ�ϴ��ǰ���׸����ӣ�һ�����Ӻ�ʱb
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


	//�����ݹ��Ϊ��̬�滮
	//dp[0][0]��ʾ�ӵ�1���˵��õ����ʱ�俪ʼ����ʼ�ȴ�ʱ��Ϊ0ʱ����ϴ��Ϊֹ��ʱ��
	int process2(vector<int> Arr,int a,int b)
	{
		int N = Arr.size();
		int raw = N;
		int col = Arr[N - 2] + (N - 1) * a;
		vector<vector<int>> dp(raw, vector<int>(col, 0));
		//�����ϱ߱����ݹ鷽����basecase��������д����N�е�����
		for(int j = 0;j<col;j++)
			dp[N-1][j] = min(max(Arr[N-1], j) + a, Arr[N-1] + b);
		//��������д��
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