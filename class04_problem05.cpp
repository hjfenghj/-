#include<iostream>
#include<vector>
#include<stack>
using namespace std;



class PROBLEM05_1
{
public:
	int get_res(vector<int> Arr)
	{
		int Len = Arr.size();
		int maxR = Arr[0];
		int maxL = Arr[Len - 1];
		int L = 1;
		int R = Len - 1;
		int ans = 0;
		while (L != R)
		{
			//从左往右遍历
			if (maxR > maxL)
			{
				if (Arr[L] < maxL)
				{
					ans += maxL - Arr[L];
				}
				else
					maxL = Arr[L];
				L++;
			}
			//从右往左遍历
			else
			{
				if (Arr[R] < maxR)
				{
					ans += maxR - Arr[R];
				}
				else
					maxR = Arr[R];
				R--;
			}
		}
		return ans;
	}
};


class PROBLEM05_2
{
public:
	stack<int> st;//储存数组元素的索引
	vector<int>  L_Arr;//元素i左边第一个大于自身的元素的索引
	vector<int>  R_Arr;//元素i右边第一个大于自身的元素的索引
	int ans = 0;
	int get_res(vector<int> Arr)
	{
		st.push(0);
		L_Arr.resize(Arr.size());
		R_Arr.resize(Arr.size());
		for (int i = 1; i < Arr.size(); i++)
		{
			if (Arr[st.top()] > Arr[i])
				st.push(i);
			else
			{
				while (Arr[st.top()] <= Arr[i])
				{
					int temp = st.top();
					R_Arr[temp] = i;
					st.pop();
					if (st.empty())
						break;
					L_Arr[temp] = st.top();
				}
				st.push(i);
			}
		}

		while (!st.empty())
		{
			int temp = st.top();
			st.pop();
			if (st.empty())
				break;
			L_Arr[temp] = st.top();
		}
		for (int i = 1; i < Arr.size()-1; i++)
		{
			if (L_Arr[i] == 0 && R_Arr[i] == 0)
				continue;
			else
			{
				ans += (R_Arr[i] - L_Arr[i] - 1) * (min(Arr[L_Arr[i]], Arr[R_Arr[i]]) - Arr[R_Arr[i] - 1]);
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> Arr = {3,1,2,5,2,4};
	PROBLEM05_1 P1;
	int res = P1.get_res(Arr);
	cout << res << endl;
	PROBLEM05_2 P2;
	int res2 = P2.get_res(Arr);
	cout << res2 << endl;
	return 0;
}