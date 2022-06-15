#include<iostream>
#include<vector>

using namespace std;

class PROBLEM04
{
public:
	void get_res(vector<vector<int>>& Arr)
	{
		int flag = (min(Arr[0].size(), Arr.size()) + 1)/2;
		int count = 0;//²ãÊý
		int idx1 = 0;
		int idy1 = 0;
		int idx2 = Arr.size()-1;
		int idy2 = Arr[0].size()-1;
		while (count < flag)
		{
			int a = idx1 + count;
			int b = idy1 + count;
			int c = idx2 - count;
			int d = idy2 - count;
			for (int offset = 0; (offset+a) < Arr.size() - count - 1; offset++)
			{
				int temp = 0;
				temp = Arr[a][b + offset];
				Arr[a][b + offset] = Arr[c - offset][b];
				Arr[c - offset][b] = Arr[c][d - offset];
				Arr[c][d - offset] = Arr[a + offset][d];
				Arr[a + offset][d] = temp;
			}
			count++;
		}

		for (int i = 0; i < Arr.size(); i++)
		{
			for (int j = 0; j < Arr[0].size(); j++)
			{
				cout << Arr[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	vector<vector<int>> Arr(4, vector<int>(4, 0));
	for (int i = 0; i < 4; i++)
	{
		Arr[i] = vector<int>{ 1 + i * 4,2 + i * 4,3 + i * 4,4 + i * 4 };
	}
	for (int i = 0; i < Arr.size(); i++)
	{
		for (int j = 0; j < Arr[0].size(); j++)
		{
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==============" << endl;
	PROBLEM04 P;
	P.get_res(Arr);
}