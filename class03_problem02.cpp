#include<iostream>
#include<vector>
using namespace std;

class PROBLEM02
{
public:
    vector<int> ans;
    void process(vector<vector<int>> Arr,int a,int b,int c,int d,bool flag)
    {
        //从右上角角往左下角移动
        if (flag)
        {
            while (a != c+1)
                ans.push_back(Arr[a++][b--]);
        }
        //从左下角往右上角移动
        else
        {
            while (c != a - 1)
                ans.push_back(Arr[c--][d++]);
        }
        return;
    }

    void get_res(vector<vector<int>> Arr)
    {
        bool flag = true;
        int Lx = 0;
        int Ly = 0;
        int Dx = 0;
        int Dy = 0;
        while (Lx != Arr.size())
        {
            process(Arr, Lx, Ly, Dx, Dy, flag);

            //两个指针坐标迁移
            Lx = Ly == Arr[0].size() - 1 ? Lx+1 : Lx;
            Ly = Ly == Arr[0].size()-1 ? Ly : Ly+1;
            Dy = Dx == Arr.size() - 1 ? Dy+1 : Dy;
            Dx = Dx == Arr.size() - 1 ? Dx : Dx+1;

            flag = !flag;
        }
        return;
    }
};

int main()
{
    vector<vector<int>> Arr(4, vector<int>(4, 0));
    for (int i = 0; i < 4; i++)
    {
        Arr[i] = vector<int>{ 1 + i * 4,2 + i * 4,3 + i * 4,4 + i * 4 };
    }
    for (int i = 0; i < Arr.size(); i++)
    {
        for (int j = 0; j < Arr[0].size(); j++)
        {
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "==============" << endl;
    PROBLEM02 P;
    P.get_res(Arr);
    for (int i = 0; i < P.ans.size(); i++)
        cout << P.ans[i] << " ";
    return 0;
}