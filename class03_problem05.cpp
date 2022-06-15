#include<iostream>
#include<vector>

using namespace std;

class PROBLEM05
{
public:
	int flag = false;//�Ƿ��ҵ��ı�־
	//�����к�,���downһֱû�ҵ�������-1
	int Down(vector<vector<int>> Arr, int i, int j, int target)
	{
		while (i < Arr.size())
		{
			if (Arr[i][j] > target)
				return i;
			else if (Arr[i][j] == target)
				flag = true;
			i++;
		}
		return -1;
	}
	//������,���downһֱû�ҵ�������-1
	int Left(vector<vector<int>> Arr, int i, int j, int target)
	{
		while (j >= 0)
		{
			if (Arr[i][j] < target)
				return j;
			else if (Arr[i][j] == target)
				flag = true;
			j--;
		}
		return -1;
	}
	bool process(vector<vector<int>> Arr, int aim)
	{
		int L1 = Arr.size();
		int L2 = Arr[0].size();
		//��Ϊȫ�ֵı���,ʵʱ���µ�ǰλ��
		int idx_r = 0;
		int idx_c = L2 - 1;
		while (!flag && idx_r != -1 && idx_c != -1)
		{
			if (Arr[idx_r][idx_c] == aim)
				return true;
			//С�ڵ�ǰֵ�������أ���������Ŀ��ֵ����
			else if (Arr[idx_r][idx_c] < aim)
				idx_r = Down(Arr, idx_r, idx_c, aim);
			//���ڵ�ǰֵ��������, ����С�ڵ�ǰֵ����
			else
				idx_c = Left(Arr, idx_r, idx_c, aim);
		}
		return flag;
	}
};


class PROBLEM05_2
{
public:
	bool process(vector<vector<int>> Arr, int target)
	{
		int row = 1;
		int col = Arr[0].size()-1;
		while (row < Arr.size() && col > -1)
		{
			if (Arr[row][col] == target)
				return true;
			else if (Arr[row][col] > target)
				col--;
			else
				row++;
		}
		return false;
	}
};

int main()
{
	vector<vector<int>> Arr = { {1,4,7,9},
							    {3,7,9,12},
							    {5,9,11,16},
							    {7,13,18,21} };
	int aim = 11;
	PROBLEM05 P;
	int res = P.process(Arr, aim);
	cout << res << endl;
	return 0;
}