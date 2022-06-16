#include<iostream>
#include<vector>

using namespace std;


class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node(int v)
	{
		val = v;
	}
};
//����һ���ڵ��������ڵ� 
class returntype
{
public:
	Node* maxBSThead;
	int minval;
	int maxval;
	int maxBSTsize;
	returntype(Node* N0,int v1,int v2, int S)
	{
		maxBSThead = N0;
		minval = v1;
		maxval = v2;
		maxBSTsize = S;
	}
};

class PROBLEM02
{
public:
	returntype process(Node* node)
	{
		if (node == nullptr)
			return returntype(nullptr, INT_MAX,INT_MIN,0 );

		returntype leftinfo = process(node->left);
		returntype rightinfo = process(node->right);

		int minval = min(node->val,min(leftinfo.minval, rightinfo.minval));
		int maxval = max(node->val,min(leftinfo.maxval, rightinfo.maxval));

		//������һ�Ͷ�
		int maxBSTsize = max(leftinfo.maxBSTsize, rightinfo.maxBSTsize);
		Node* maxBSThead = leftinfo.maxBSTsize >= rightinfo.maxBSTsize ? leftinfo.maxBSThead : rightinfo.maxBSThead;

		//��������
		if (leftinfo.maxval < node->val && rightinfo.minval > node->val
			&& node->left == leftinfo.maxBSThead && node->right == rightinfo.maxBSThead)
		{
			maxBSTsize = leftinfo.maxBSTsize + rightinfo.maxBSTsize + 1;
			maxBSThead = node;
		}
		return returntype(maxBSThead, minval, maxval, maxBSTsize);
	}

	Node* get_res(Node* node)
	{
		return process(node).maxBSThead;
	}
};