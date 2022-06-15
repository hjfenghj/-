#include<iostream>
#include<vector>

using namespace std;

//预处理技巧

void pre_process(vector<vector<int>> Arr,vector<vector<int>>& temp1, vector<vector<int>>& temp2)
{
	int L1 = Arr.size();
	int L2 = Arr[0].size();
	//从左下角开始,按每行自右往左遍历
	for (int i = L1 - 1; i >= 0; i--)
	{
		int s = 0;
		for (int j = L2 - 1;j >= 0; j--)
		{
			if (Arr[i][j] == 1)
				s++;
			else
				s = 0;
			temp1[i][j] = s;
		}
	}
	for (int i = L2 - 1; i >= 0; i--)
	{
		int s = 0;
		for (int j = L1 - 1; j >= 0; j--)
		{
			if (Arr[i][j] == 1)
				s++;
			else
				s = 0;
			temp2[i][j] = s;
		}
	}
}
int main()
{
	vector<vector<int>>  Arr;//输入数组
	vector<vector<int>> temp1;//辅助数组1,储存元素右侧连续1的个数
	vector<vector<int>> temp2;//辅助数组2,储存元素下侧连续1的个数
	pre_process(Arr, temp1, temp2);
	int L1 = Arr.size();//行
	int L2 = Arr[0].size();//列
	int res = 0;

	for (int i = 0; i < L1; i++)
	{
		for (int j = 0; j < L2; j++)
		{
			if (Arr[i][j] == 0)
				continue;
			//遍历不同的边长
			for (int B = 1; B < L1 - i && B < L2 - j; B++)//设置边长的阈值
			{
				//判断左上角坐标为(i,j),边长为B的正方向的四条边是否全为1
				bool b1 = (temp1[i][j] >= B && temp2[i][j] >= B) ? 1 : 0;
				bool b2 = temp2[i][j + B - 1] >= B ? 1 : 0;
				bool b3 = temp1[i + B - 1][j] >= B ? 1 : 0;
				bool b = b1 & b2 & b3;
				if (b == 1)
					res = max(res, B);
			}
		}
	}
	cout << res << endl;
	return 0;
}
