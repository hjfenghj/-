#include<iostream>
#include<vector>

using namespace std;

class PROBLEM04
{
public:

	// pre ��ʾ�Ѿ����ѵ�C��    �ɱ�
	// end ��ʾĿ�Ļ���       
	// add ��ʾ����һ�λ��ѵ�C��
	// mul ��ʾ����һ�λ��ѵ�C��
	// del ��ʾ˽��һ�λ��ѵ�C��
	// cur ��ʾĿǰ����Ļ���     �ɱ�
 	// coinlimit ��ʾ���Ѳ��ᳬ��coinlimit��C��
	// endlimit  ��ʾ���ֲ��ᳬ��endlimit������
	int process1(int pre, int end, int add, int mul, int del, int cur, int coinlimit, int endlimit)
	{
		//��Ч��
		if (cur >= endlimit || cur<0)
			return INT_MAX;
		if (pre >= coinlimit)
			return INT_MAX;

		if (cur == end)
			return pre;
		//�������
		int ans = INT_MAX;
		int p1 = process1(pre + add, end, add, mul, del, cur + 2, coinlimit, endlimit);
		if (p1 != INT_MAX)
			ans = min(ans, p1);

		int p2 = process1(pre + mul, end, add, mul, del, cur * 2, coinlimit, endlimit);
		if (p2 != INT_MAX)
			ans = min(ans, p2);

		int p3 = process1(pre + del, end, add, mul, del, cur - 2, coinlimit, endlimit);
		if (p3 != INT_MAX)
			ans = min(ans, p3);

		return ans;
	}

	//��̬�滮��
	int proecess2()
	{

	}
};

int main()
{
	int pre = 0;
	int end = 100;
	int add = 1;
	int mul = 2;
	int del = 6;
	int cur = 4;
	int coinlimit = (end - cur) / 2;
	int endlimit = 2 * end;
	PROBLEM04 P;
	int ans = P.process1(pre, end, add, mul, del, cur, coinlimit, endlimit);
	cout << ans << endl;
	return 0;
}