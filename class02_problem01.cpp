#include<iostream>
#include<vector>
#include<set>


using namespace std;
int main()
{
	vector<int> Arr = { 3,5,2,7,0,0,2 };
	int offset = 2;
	int res = 0;
	set<int> S;//set是个有序表
	for (int i = 0; i < Arr.size(); i++)
		S.insert(Arr[i]);
	for (int s : S)
	{
		if (S.find(s + offset) != S.end())
			res++;
	}
	cout << res << endl;
	return 0;
}