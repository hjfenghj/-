#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

class PROBLEM04
{
public:
	vector<int> pre;//前序数组
	vector<int> in;//中序数组
	vector<int> pos;//后序数组
	map<int, int> M;//用于查找中序数组的元素
	PROBLEM04(vector<int> p, vector<int> I)
	{
		pre = p;
		in = I;
		pos.resize(in.size());
	}
	//将中序数组转换为map储存,方便查找元素在原始的数组中的索引
	void vec2map()
	{
		for (int i = 0; i < in.size(); i++)
		{
			M.emplace(in[i], i);
		}
	}

	//递归思路1
	//把pre的[p1,p2]位置和in的[n1,n2]位置的元素取出来放在pos的[pos1,pos2位置上]
	void process_1(int p1, int p2, int n1, int n2, int pos1, int pos2)
	{
		if (p1 > p2)
			return;
		//根据前序遍历和后序遍历的顺序，将前序数组的第一个元素给后序数组pos的最后一个元素
		pos[pos2] = pre[p1];//将前序的首元素 给后序的末尾元素
		int find = M[pre[p1]];//找到中序中当前节点的位置，把中序数组一分为二

		process1(p1 + 1, p1 + find - n1, n1, find - 1, pos1, pos1 + find - n1 -1);
		process1(p1 + find - n1 + 1, p2, find + 1, n2, pos1 + find - n1, pos2 - 1);
		return;
	}

	//递归思路2
	//返回下次需要归为的位置,从pre的[p1,p2]位置，in的[n1,n2]位置取出元素放在pos的pos2位置
	int process_2(int p1, int p2, int n1, int n2, int pos2)
	{
		if (p1 > p2)
			return pos2;
		pos[pos2--] = pre[p1];
		int find = M[pre[p1]];

		pos2 = process2(p1 + 1, p1 + find - n1, n1, find - 1, pos2);
		return process2(p1 + find - n1 + 1, p2, find + 1, n2, pos2);
	}
};


class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) { val = v; }
	TreeNode() {};
};

class PROBLEM04_2
{
public:

	TreeNode* create_tree(vector<int> pre,vector<int> in)
	{
		if (pre.size() == 0 || in.size() == 0)
			return nullptr;
		TreeNode* cur = new TreeNode(pre[0]);
		if (pre.size() == 1)
			return cur;
		int idx = 0;//找到中序数组中目前节点的位置
		for (idx; idx < in.size(); idx++)
		{
			if (in[idx] == pre[0])
				break;
		}
		vector<int> left_in(in.begin(), in.begin() + idx);
		vector<int> right_in(in.begin() + idx+1, in.end());

		vector<int> left_pre(pre.begin() + 1, pre.begin() + 1 + left_in.size());
		vector<int> right_pre(pre.begin() + 1 + left_in.size(), pre.end());

		cur->left = create_tree(left_pre, left_in);
		cur->right = create_tree(right_pre, right_in);

		return cur;
	}
	//树的后序遍历
	void get_res(TreeNode* node)
	{
		vector<int> pos;
		stack<TreeNode*> st;
		st.push(node);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if(cur != nullptr)
			{
				st.push(cur);
				st.push(nullptr);
				if(cur->right) st.push(cur->right);
				if(cur->left) st.push(cur->left);
			}
			else
			{
				pos.push_back(st.top()->val);
				st.pop();
			}
		}
		for (int i = 0; i < pos.size(); i++)
			cout << pos[i] << " ";
		cout << endl;
		return;
	}
};

int main()
{
	vector<int> pre = {1,2,4,5,3,6,7};
	vector<int> in = { 4,2,5,1,6,3,7 };
	int L = pre.size();

	PROBLEM04 P(pre,in);
	P.vec2map();
	P.process_1(0, L - 1, 0, L - 1, 0, L - 1);
	for (int i = 0; i < L; i++)
		cout << P.pos[i] << " ";
	cout << endl;


	PROBLEM04 P1(pre, in);
	P1.vec2map();
	P1.process_2(0, L - 1, 0, L - 1, L - 1);
	for (int i = 0; i < L; i++)
		cout << P1.pos[i] << " ";
	cout << endl;

	PROBLEM04_2 P2;
	TreeNode* node = P2.create_tree(pre, in);
	P2.get_res(node);
	return 0;
}