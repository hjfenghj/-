#include<iostream>
#include<vector>
using namespace std;


class PROBLEM02_cow_eat_grown
{
public:
	//ʹ��һЩ�����ݴ�����ҵ����ɣ����������NΪ1���ڣ�ʹ�õ����ݹ�ͻ�ǳ���ʱ��
	//ʹ�ô��ռ�������Ժ󣬾Ϳ���ֱ�ӵõ����
	int get_res(int N)
	{
		if (N < 5)
		{
			return (N == 0 || N == 2) ? 0 : 1;//0�������Ӯ��1��������Ӯ
		}
		//N > 5��ʱ��
		int t = 1;//��ʾ�ӳ�һ�ݿ�ʼ
		while (t <= N)
		{
			//Aţ�����Ժ�Bţ��ʣ��Ĳ��п�ʼ�ԣ������ʣ��Ĳ��п�ʼ,BţӮ�ˣ��ͱ�ʾԭʼ������AţӮ��
			if (get_res(N - t) == 0)
				return 1;

			//��ֹt*4Խ��
			if (t > N / 4)
				break;
			t *= 4;
		}
		return 0;
	}

	//ʹ�ô���õ��Ĺ���
	int get_res2(int N)
	{
		if (N % 5 == 0 || N % 5 == 2)
			return 0;//�������Ӯ
		return 1;
	}
};


int main()
{
	int N = 50;
	PROBLEM02_cow_eat_grown P;
	for (int i = 0; i < 50; i++)
	{
		cout << i <<  " " << P.get_res(i) << endl;
	}

	int res = P.get_res2(100000);
	cout << res<< endl;
	return 0;
}