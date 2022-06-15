#include<iostream>
#include<vector>

using namespace std;

//等概率返回1-5
int f(int a,int b)
{
	return (rand() % (b - a + 1)) + a;
}
 
//把f函数改为0，1产生器
int get_r01()
{
	int v = 0;
	do
	{
		v = f(1, 5);
	} while (v == 3);
	return v < 3 ? 0 : 1;
}
//等概率返回1-7;
int g()
{
	int temp;
	do
	{
		temp = (get_r01() << 2) + (get_r01() << 1) + get_r01();
	} while (temp == 7);
	return temp + 1;
}

int main()
{

}