#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

class PROBLEM04
{
public:
	vector<int> pre;//ǰ������
	vector<int> in;//��������
	vector<int> pos;//��������
	map<int, int> M;//���ڲ������������Ԫ��
	PROBLEM04(vector<int> p, vector<int> I)
	{
		pre = p;
		in = I;
		pos.resize(in.size());
	}
	//����������ת��Ϊmap����,�������Ԫ����ԭʼ�������е�����
	void vec2map()
	{
		for (int i = 0; i < in.size(); i++)
		{
			M.emplace(in[i], i);
		}
	}

	//�ݹ�˼·1
	//��pre��[p1,p2]λ�ú�in��[n1,n2]λ�õ�Ԫ��ȡ��������pos��[pos1,pos2λ����]
	void process_1(int p1, int p2, int n1, int n2, int pos1, int pos2)
	{
		if (p1 > p2)
			return;
		//����ǰ������ͺ��������˳�򣬽�ǰ������ĵ�һ��Ԫ�ظ���������pos�����һ��Ԫ��
		pos[pos2] = pre[p1];//��ǰ�����Ԫ�� �������ĩβԪ��
		int find = M[pre[p1]];//�ҵ������е�ǰ�ڵ��λ�ã�����������һ��Ϊ��

		process1(p1 + 1, p1 + find - n1, n1, find - 1, pos1, pos1 + find - n1 -1);
		process1(p1 + find - n1 + 1, p2, find + 1, n2, pos1 + find - n1, pos2 - 1);
		return;
	}

	//�ݹ�˼·2
	//�����´���Ҫ��Ϊ��λ��,��pre��[p1,p2]λ�ã�in��[n1,n2]λ��ȡ��Ԫ�ط���pos��pos2λ��
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
		int idx = 0;//�ҵ�����������Ŀǰ�ڵ��λ��
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
	//���ĺ������
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