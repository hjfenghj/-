#include<iostream>
#include<vector>

using namespace std;


vector<int> operator+(vector<int> Arr1,vector<int> Arr2)
{
	vector<int> res(Arr2.size(), 0);
	for (int i = 0; i < Arr1.size(); i++)
	{
		res[i] = Arr1[i] + Arr2[i];
	}
	return res;
}
class PROBLEM07
{
public:
	int process(vector<int> Arr)
	{
		int cur = 0;
		int ans = INT_MIN;
		if (Arr.size() <= 0)
			return 0;
		for (auto n : Arr)
		{
			cur += n;
			ans = max(ans, cur);
			cur = cur < 0 ? 0 : cur;
		}
		return ans;
	}


	int get_res(vector<vector<int>> Arr)
	{
		int ans = INT_MIN;
		int row = Arr.size();
		int col = Arr[0].size();
		for (int i = 0; i < row; i++)
		{
			ans = max(ans, process(Arr[i]));
			for (int j = i+1; j < col; j++)
			{
				ans = max(ans, process(Arr[i] + Arr[j]));
			}
		}
		return ans;
	}
};

