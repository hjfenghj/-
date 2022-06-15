#include<iostream>
#include<vector>

using namespace std;

class PROBLEM03_1
{
public:
	vector<int> ans;
	//(a,b)���Ͻǵ�,(c,d)���½ǵ�
	void process(vector<vector<int>> Arr,int a,int b,int c,int d)
	{
		//ͬ��
		if (a == c){
			while (b <= d){
				ans.push_back(Arr[a][b]);
				b++;
			}
		}
		//ͬ��
		if (b == d){
			while (a <= c){
				ans.push_back(Arr[a][b]);
				a++;
			}
		}
		//�������
		for (int j = b; j < d;j++)
			ans.push_back(Arr[a][j]);
		for (int i = a; i < c; i++)
			ans.push_back(Arr[i][d]);
		for (int j = d; j > b; j--)
			ans.push_back(Arr[c][j]);
		for (int i = c; i > a; i--)
			ans.push_back(Arr[i][b]);	
		return;
	}
	void get_res(vector<vector<int>> Arr)
	{
		int a = 0;
		int b = 0;
		int c = Arr.size()-1;
		int d = Arr[0].size()-1;
		while (a <= c && b <= d)
		{
			process(Arr, a++, b++, c--, d--);
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}
};


class PROBLEM_03_2
{
public:
	vector<int> ans;
	void get_res(vector<vector<int>> Arr)
	{
		int i = 0;//ʵʱ��¼Ŀǰ��ӡ����λ��
		int j = 0;

		int idx = 0;//��¼�����ǵڼ�Ȧ��0��ʾ��һȦ
		int flag = (min(Arr.size(), Arr[0].size()) + 1) / 2;//һ����Ҫ��ӡ����Ȧ

		while (idx < flag)
		{
			//0+idx��ʾ��ʼ�У��������Ҵ�ӡ��������
			for (j = 0 + idx; j < Arr[0].size() - idx - 1; j++)
				ans.push_back(Arr[i][j]);
			//�������´�ӡ��������
			for (i = 0 + idx; i < Arr.size() - idx - 1; i++)
				ans.push_back(Arr[i][j]);
			//���������ӡ���ݼ���
			for (j; j >= 0 + idx + 1; j--)
				ans.push_back(Arr[i][j]);
			//�������ϴ�ӡ���ݼ���
			for (i; i >= 0 + idx + 1; i--)
				ans.push_back(Arr[i][j]);
			//������ʼλ�ú�Ȧ��
			i++;
			idx++;
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		return;
	}
};

int main()
{
	vector<vector<int>> Arr(4, vector<int>(4, 0));
	for (int i = 0; i < 4; i++)
	{
		Arr[i] = vector<int>{ 1+i*4,2+i*4,3+i*4,4+i*4 };
	}
	for (int i = 0; i < 4; i ++ )
	{
		for (int j = 0; j < 4; j++)
		{
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "================" << endl;

	PROBLEM03_1 P1;
	P1.get_res(Arr);
	cout << "================" << endl;

	PROBLEM_03_2 P2;
	P2.get_res(Arr);
	return 0;
}