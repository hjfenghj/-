#include<iostream>
#include<vector>

using namespace std;


class PROBLEM01_1
{
/*
* ����������˸պð�ĳ�ڵ㷢����ϣ�����˵����[2,4,....]������������˸պ�ѹ�ڵ�1���ڵ��ϣ��͵������ڵ���
* ���������Ҷ˵����λ�ø��½��
*/
public:
	int process_1(vector<int> Arr, int L)
	{
		int start = 0;
		int end = 0;
		int res = 0;//���Ӹ��ǵĽڵ�����
		for (int i = 0; i < Arr.size(); i++)
		{
			if (L < Arr[i])
				break;
			end = i;//����ĩβ���ǵ��Ľڵ�
		}
		res = end - start + 1;//���Ӵ��׽ڵ�������ǵĽڵ���

		int LL = L - Arr[end];//���Ӹ������һ���ڵ��ʣ��೤

		for (int start = 1; start < Arr.size(); start++)
		{
			//�������,��������ʣ��ĳ���,ע������ĸ�ʽΪ�ۼ�ֵ
			if (start == 1)
				LL = LL + Arr[start - 1];
			else
				LL = LL + (Arr[start - 1] - Arr[start - 2]);


			int temp = res - 1;
			while (LL >= (Arr[end + 1] - Arr[end]))
			{
				temp++;
				end++;
				if (end + 1 == Arr.size())
				{
					return res;
				}
				LL = LL - (Arr[end + 1] - Arr[end]);
			}
			res = max(temp, res);
		}
		return res;
	}

	void mian_1(vector<int> Arr,int len)
	{
		int res = process_1(Arr, len);
		cout << res << endl;
		return;
	}
};

class PROBLEM01_2
{
/*
* ���������Ҷ˸պø�����ĳ�ڵ㣬�������������λ��
* �趨�����Ҷ˽ڵ�λ�ã��������λ��λ�ø��½��
*/
public:
	//�����б�������R��ǰ���ֵ�һ�����ڵ���ĳֵ������
	//val��ʾѰ�ҵ�Ŀ��ֵ
	int process_2(vector<int> Arr, int val, int R)
	{
		int L = 0;
		int index = R;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (Arr[mid] >= val)
			{
				index = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		return index;
	}

	void main_2(vector<int> Arr, int len)
	{
		int max_L = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			max_L = max(max_L, i - process_2(Arr, Arr[i] - len, i) + 1);
		}
		cout << max_L << endl;
		return;
	}
	
};

class PROBLEM01_3
{
/*
* ��һ�ַ����ĵݹ�д��
*/
public:
	//Arr ԭʼ�ڵ�����ı任���µ������ʾÿ��Ԫ�ش���i-1λ�õ�iλ�õĽڵ���
	//L_ptr ���������ȫѹ���Ľڵ�
	//R_ptr �����Ҳ���ȫѹ���Ľڵ�
	//len  �ڳ�ȥstart��end�ķ�Χ��,���ӻ�ʣ��ĳ���
	//res  ��ʾ���ǵĽڵ���
	//�������Ӵ�Arr����L_ptr��������R_ptr������ʣ��Len�ĸ��࣬ǰ�պ�[L_ptr,R_ptr)
	int process_3(vector<int> Arr, int L_ptr, int R_ptr, int Len, int res)
	{
		if (R_ptr >= Arr.size())
			return res;											   
		int r = 0;
		if (Len < Arr[R_ptr])
			r = process_3(Arr, L_ptr + 1, R_ptr, Len + Arr[L_ptr], max(res, R_ptr - L_ptr + 1));
		else if (Len >= Arr[R_ptr])
			r = process_3(Arr, L_ptr, R_ptr + 1, Len - Arr[R_ptr], max(res, R_ptr - L_ptr));
		return r;
	}

	void main_3(vector<int> Arr, int len)
	{
		vector<int> new_arr(Arr.size(), 0);
		new_arr[0] = Arr[0];
		for (int i = 1; i < Arr.size(); i++)
			new_arr[i] = Arr[i] - Arr[i - 1];

		int ans = process_3(new_arr,0,0,len,0);
		cout << ans << endl;
		return;
	}
};

int main()
{
	vector<int> Arr = { 0, 13, 24, 35, 46, 57, 60, 72, 87 };
	int len = 8;
	PROBLEM01_1 P1;
	P1.mian_1(Arr, len);
	PROBLEM01_2 P2;
	P2.main_2(Arr, len);
	PROBLEM01_3 P3;
	P3.main_3(Arr, len);
	return 0;
}
