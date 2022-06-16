#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class PROBLEM06
{
public:
	string process(string str)
	{
		if (str.size() == 1)
			return str;

		//统计词频
		map<char, int> M;
		for (char s : str)
		{
			M[s]++;
		}

		int idx = 0;

		for (int i=0;i<str.size();i++)
		{
			idx = str[idx] - '0' > str[i] - '0' ? i : idx;//记录经过的字符中acsii最小的字符的位置
			if (--M[str[i]] == 0)
				break;
		}
		string s(1, str[idx]);
		string new_str(str.begin() + idx + 1, str.end());
		new_str.erase(remove(new_str.begin(), new_str.end(), str[idx]), new_str.end());
		return  s + process(new_str);
	}
};

int main()
{
	string str = "dbcacbca";
	PROBLEM06 P;
	string ans = P.process(str);
	cout << ans << endl;
	return 0;
}