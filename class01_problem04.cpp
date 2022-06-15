#include<iostream>
#include<vector>

using namespace std;

//Ԥ������

void pre_process(vector<vector<int>> Arr,vector<vector<int>>& temp1, vector<vector<int>>& temp2)
{
	int L1 = Arr.size();
	int L2 = Arr[0].size();
	//�����½ǿ�ʼ,��ÿ�������������
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
	vector<vector<int>>  Arr;//��������
	vector<vector<int>> temp1;//��������1,����Ԫ���Ҳ�����1�ĸ���
	vector<vector<int>> temp2;//��������2,����Ԫ���²�����1�ĸ���
	pre_process(Arr, temp1, temp2);
	int L1 = Arr.size();//��
	int L2 = Arr[0].size();//��
	int res = 0;

	for (int i = 0; i < L1; i++)
	{
		for (int j = 0; j < L2; j++)
		{
			if (Arr[i][j] == 0)
				continue;
			//������ͬ�ı߳�
			for (int B = 1; B < L1 - i && B < L2 - j; B++)//���ñ߳�����ֵ
			{
				//�ж����Ͻ�����Ϊ(i,j),�߳�ΪB����������������Ƿ�ȫΪ1
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
