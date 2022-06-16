#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node(int v)
	{
		value = v;
	}
	Node() {};
};

class returntype
{
public:
	Node* start;
	Node* end;
	returntype(Node* s, Node* e)
	{
		start = s;
		end = e;
	}
};

class PROBLEM01
{
public:
	returntype process(Node* node)
	{
		if (node == nullptr)
			return returntype(nullptr, nullptr);
		returntype leftinfo = process(node->left);
		returntype rightinfo = process(node->right);

		if (leftinfo.end != nullptr)
			leftinfo.end->right = node;
		node->left = leftinfo.end;


		node->right = rightinfo.start;
		if (rightinfo.start != nullptr)
			rightinfo.start->left = node;

		return returntype(leftinfo.start != nullptr ? leftinfo.start : node, rightinfo.end != nullptr ? rightinfo.end : node);
	}
	Node* get_res(Node* node)
	{
		return process(node).start;
	}
};
