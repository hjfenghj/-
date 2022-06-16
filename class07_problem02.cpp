#include<iostream>
#include<vector>

using namespace std;

class PROBLEM02
{
public:

	void get_res(vector<int>& Arr)
	{
		for (int i = 0; i < Arr.size(); i++)
		{
			process(Arr[i], Arr);
		}
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] != i + 1)
				cout << i+1 << " ";
		}
		return;
	}
	void process(int val, vector<int>& Arr)
	{
		while (Arr[val - 1] != val)
		{
			int temp = Arr[val - 1];
			Arr[val - 1] = val;
			val = temp;
		}
	}
};

int main()
{
	vector<int> Arr = { 3,2,1,7,3,6,2 };
	PROBLEM02 P;
	P.get_res(Arr);
	return 0;
}