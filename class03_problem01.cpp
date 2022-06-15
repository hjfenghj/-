#include<iostream>
#include<vector>

using namespace std;
 
int get_res(vector<int> Arr)
{
	int ans = 0;
	int LeftSum = 0;//当前索引左侧元素和
	int AllSum = 0;
	for (int i = 0; i < Arr.size(); i++)
	{
		AllSum += Arr[i];
	}
	int avg = AllSum / Arr.size();
	int RightSum = AllSum - LeftSum; //当前索引左侧元素和,起始索引为-1

	for (int i = 0; i < Arr.size(); i++)
	{
		RightSum = RightSum - Arr[i] - LeftSum;
		if (i > 0)
			LeftSum = LeftSum + Arr[i - 1];
		int L = (i > 0) ? LeftSum - avg * (i - 1) : 0;
		int R = RightSum - avg * (Arr.size() - i - Arr[i]);
		if (R > 0 && L > 0)
			ans = max(ans, R + L);
		else
			ans = max(ans, max(abs(R), abs(L)));
	}
	return ans;
}