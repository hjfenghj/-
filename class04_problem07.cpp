#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PROBLEM07
{
public:
	string s;
	string m;
	vector<int> nexts;
	PROBLEM07(string str, string match)
	{
		s = str;
		m = match;
		nexts.resize(m.size());
	}

	//产生匹配字符串的nexts数组
	void get_nexts()
	{
		nexts[0] = -1;
		nexts[1] = 0;
		s = s + s;
		if (m.size() < 2)
			return;
		int curidx = 2;
		int cm = nexts[curidx - 1];
		while (curidx < m.size())
		{
			if (m[curidx - 1] == m[cm])
			{
				nexts[curidx++] = ++cm;
			}
			else if (cm > 0)
				cm = nexts[cm];
			else
				nexts[curidx++] = 0;
		}
		return;
	}
	//返回b在字符串在a+a字符串中的第一个位置
	int get_index()
	{
		int i = 0;
		int j = 0;
		while (i < s.size() && j < m.size())
		{
			if (s[i] == m[j])
			{
				i++;
				j++;
			}
			else if (j == 0)
				i++;
			else
				j = nexts[j];
		}
		return j == m.size() ? i - j : -1;
	}

	bool get_res()
	{
		get_nexts();
		int ans = get_index();
		return ans == -1 ? false : true;

	}
};

int main()
{
	string a = "1ab2";
	string b = "ab12";

	if (a.size() != b.size())
		return false;
	if (a.size() == 1 && b.size() == 1 && a == b)
		return true;


	PROBLEM07 P(a,b);
	cout << P.get_res() << endl;
	return 0;
}