#include<iostream>
#include<vector>

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
	}
};

class PROBLEM05
{
public:
	int get_depth(TreeNode* node){
		int depth = 0;
		while (node){
			depth++ ;
			node = node->left;
		}
		return depth;
	}
	//N的L次方
	int pown(int N, int L){
		int res = 1;
		int temp = N;
		while (L != 0){
			if (L & 1 == 1){
				res *= temp;
				temp = temp * temp;
			}
			else
				temp = temp * temp;
			L = L >> 1;
		}
		return res;
	}

	int process(TreeNode* node, int depth){
		int ans = 0;
		if (node->left == nullptr && node->right==nullptr)
			return 1;
		//右数的最大深度到达最大深度
		if (get_depth(node->right) == depth - 1){
			node = node->right;
			ans = pown(2, depth - 1) + process(node,depth-1);
		}
		//右树没有到达最大高度，那么这是右树的右树满树
		else if (get_depth(node->right) < depth - 1){
			int L = get_depth(node->right);
			node = node->left;
			ans = pown(2, L) + process(node, depth - 1);
		}
		return ans;
	}

	int get_res(TreeNode* node){
		int d = get_depth(node);//最大深度,全文贯穿
		cout << d << endl;
		int ans = process(node, d);
		return ans;
	}
};
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	//root->right->right = new TreeNode(7);

	PROBLEM05 P;
	int ans = P.get_res(root);
	cout << ans << endl;
	return 0;

}