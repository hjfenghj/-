#include<iostream>
#include<vector>
#include<string>

using namespace std;

//̰�Ľⷨ
class PROBLEM05_1
{
public:
	int get_res(string str)
	{
		int ans = 0;
		int idx = 0;
		while (idx < str.size())
		{
			if (str[idx] == 'X')
				idx++;
			else //str[idx]=='.'
			{
				ans++;//����
				if (idx + 1 == str.size())//idxλ�������һ��λ��
					return ans;
				else //idx�������һ��λ��
				{
					if (str[idx + 1] == 'X')
						idx += 2;
					else
						idx = idx + 3;
				}
			}
		}
		return ans;
	}
};



int main()
{
	string str = "...X.X.X..XX.XX.X.X.X.X.XX.XXX.X.XXX.XX";
	PROBLEM05_1 P;
	int res = P.get_res(str);
	cout << res << endl;
	return 0;
}

