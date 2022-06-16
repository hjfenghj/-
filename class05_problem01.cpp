#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

class Node
{
public:
    string str;
    map<string, Node*> nexts;
    Node(string s)
    {
        str = s;
    }
    Node(string s, Node* N)
    {
        str = s;
        nexts[s] = N;
    }
};

class PROBLEM01
{
public:
    vector<string> string2vec(string str)
    {
        vector<string> vec_path;
        const char* path = str.c_str();
        char* p = strtok(const_cast<char*>(path), "\\");  //const_cast可以去除const的限定
        while (p != NULL)
        {
            vec_path.push_back(p);
            p = strtok(NULL, "\\");
        }
        return vec_path;
    }

    //建立前缀树
    Node* get_tire(vector<string> strs)
    {
        Node* head =new Node(" ");
        Node* cur = head;
        for (string str : strs)
        {
            vector<string> vec_str = string2vec(str);
            for (string vec_s : vec_str)
            {
                if (cur->nexts.find(vec_s) == cur->nexts.end())
                {
                    Node* temp =new Node(vec_s);
                    cur->nexts.emplace(vec_s, temp);
                }
                cur = cur->nexts[vec_s];
            }
            cur = head;
        }   
        return head;
    }

    //从第几级文件夹开始输出
    void print(Node* node, int level)
    {

        if (level != 0)
        {
            cout << setw(2 * (level-1) + node->str.size()) << node->str << endl;
        }
        for (auto cur : node->nexts)
            print(cur.second,level+1);
    }

};

int main()
{
    vector<string> arr_string = { "ac\\b\\cd","ac\\b\\c\\d" };
    PROBLEM01 P;
    Node* node = P.get_tire(arr_string);
    P.print(node, 0);
    return 0;
}