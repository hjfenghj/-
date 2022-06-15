#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v)
	{
		val = v;
		left = nullptr;
		right = nullptr;
	}
};

class returnType
{
public:
	int leftval;
	int rightval;
	int val;
	returnType(int lv,int rv,int v)
	{
		leftval = lv;
		rightval = rv;
		val = v;
	}
};


class PROBLEM07_1
{
public:
	int Process1(TreeNode* node)
	{
		int maxval = 0;
		map<TreeNode*, int> maphash;//表示根节点到某节点的权重map
		if (node != nullptr)
		{
			stack<TreeNode*> st;
			st.push(node);
			while (!st.empty())
			{
				TreeNode* cur = st.top();
				st.pop();
				maphash.emplace(cur, cur->val);

				if (cur->left == nullptr && cur->right == nullptr)
				{
					maxval = max(maxval, maphash.find(cur)->second);
				}
				if (cur->right)
				{
					maphash.emplace(cur->right, maphash.find(cur)->second + cur->right->val);
					st.push(cur->right);
				}
				if (cur->left)
				{
					maphash.emplace(cur->left, maphash.find(cur)->second + cur->left->val);
					st.push(cur->left);
				}
			}
		}
		return maxval;
	}

	void main_1(TreeNode* node)
	{
		int ans = Process1(node);
		cout << ans << endl;
		return;
	}
};

class PROBLEM07_2
{
public:
	//pre代表此节点以前的权重和
	int process2(TreeNode* node, int pre)
	{
		if (node == nullptr)
			return INT_MIN;
		if (node->left == nullptr && node->right == nullptr)
			return pre + node->val;
		int leftres = process2(node->left, pre + node->val);
		int rightres = process2(node->right, pre + node->val);
		return max(leftres, rightres);
	}

	void main_2(TreeNode* node)
	{
		cout << process2(node, 0) << endl;
		return;
	}
};

class PROBLEM07_3
{
public:
	returnType process3(TreeNode* node)
	{
		if (node == nullptr)
		{
			return returnType(0, 0, 0);
		}
		returnType leftinfo = process3(node->left);
		returnType rightinfo = process3(node->right);
		int leftval = max(leftinfo.leftval, leftinfo.rightval) + leftinfo.val;
		int rightval = max(rightinfo.leftval, rightinfo.rightval) + rightinfo.val;
		return returnType(leftval, rightval, node->val);

	}

	void mian_3(TreeNode* node)
	{
		returnType res = process3(node);
		cout << max(res.leftval, res.rightval) + res.val << endl;
		return;
	}
};


int main()
{
	TreeNode node = TreeNode(4);
	TreeNode node1 = TreeNode(1);
	TreeNode node2 = TreeNode(5);
	TreeNode node3 = TreeNode(-7);
	TreeNode node4 = TreeNode(3);

	TreeNode* head = &node;

	head->left = &node1;
	head->left->right = &node2;
	head->right = &node3;
	head->right->left = &node4;

//第一种方式就是普通的解，使用中序遍历的思想
//后两种方法是树形dp解法
	PROBLEM07_1 P1;
	PROBLEM07_2 P2;
	PROBLEM07_3 P3;
	P1.main_1(head);
	P2.main_2(head);
	P3.mian_3(head);
	return 0;
}