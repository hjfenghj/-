#include<iostream>
#include<vector>

using namespace std;

class PROBLEM06
{
public:
	int get_res(vector<int> Arr)
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

		//for (int i = 0; i < Arr.size(); i++)
		//{
		//	if (cur < 0 && Arr[i] >= 0)
		//	{
		//		cur = Arr[i];
		//	}
		//	else
		//	{
		//		cur = cur + Arr[i];
		//	}
		//	ans = max(cur, ans);
		//}
		return ans;
	}
};

int main()
{
	vector<int> Arr = { -2, -3, -5, 40, -10, -10, 100, 1 };
	PROBLEM06 P;
	int res = P.get_res(Arr);
	cout << res << endl;
	return 0;
}