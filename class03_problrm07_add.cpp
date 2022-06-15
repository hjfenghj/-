#include<iostream>
#include<vector>
#include<queue>
#include<map>


using namespace std;

class Node
{
public:
	string str;
	int times;
	Node(string s)
	{
		str = s;
		times = 1;
	}
	Node()
	{
		str = "wuming";
		times = 1;
	}
};

class PROBLEM07
{
public:
	map<string, Node> maptime;//��Ƶ��
	map<string, int> heaplocal;//��λ�ø���
	vector<Node> heap;
	int K;//��Ŀǰ�ĳ���
	PROBLEM07(int size)
	{
		heap.resize(size);
		K = 0;
	}

	void add(string s)
	{
		Node cur = Node(s);
		int local_idx = -1;   //��ʼ���½�����ַ����Ķ�λ��Ϊ-1;
		//��Ƶ�����
		//����¼�����ַ���ǰ���ֹ�����ôһ���������Ķ�λ��
		if (maptime.find(s) != maptime.end())
		{
			maptime[s].times++;
			local_idx = heaplocal[s];
		}
		//����¼�����ַ���ǰû���ֹ�
		else
		{
			maptime.emplace(s, cur);
			heaplocal.emplace(s, -1);
		}
		//�½�����ַ������ڶ���
		if (local_idx == -1)
		{
			//���Ѿ�����
			if (heap.size() == K)
			{
				//����Ԫ�صĴ������԰ѶѶ��ɷ�
				if (maptime[s].times > heap[0].times)
				{
					heaplocal[heap[0].str] = -1;
					heap[0] = maptime[s];
					heapify(0, K);//�Ѷ�Ԫ���³���K�����ʱ�Ķѳ���
				}
			}
			//�ѻ�û����
			else
			{
				heaplocal[s] = K;
				heap[K] = maptime[s];
				heap_insert(K++);//�ѵ�Ԫ���ϸ�
			}
		}
		//�½�����ַ��ڶ���
		else
		{
			heapify(local_idx, K);//��local_idxλ���³�
		}
	}

	void swap(int idx1,int idx2)
	{
		Node temp;
		temp = heap[idx1];
		heap[idx1] = heap[idx2];
		heap[idx2] = temp;

		heaplocal[heap[idx1].str] = idx2;
		heaplocal[heap[idx2].str] = idx1;

	}
	//�³�
	void heapify(int s_idx, int e_idx)
	{
		int L = s_idx * 2 + 1;
		int R = s_idx * 2 + 2;
		int smallest = s_idx;
		while (L < e_idx)
		{
			if (heap[L].times < heap[s_idx].times)
			{
				smallest = L;
			}
			if (R < e_idx && heap[R].times < heap[smallest].times)
				smallest = R;
			if (smallest != s_idx)
				swap(smallest, s_idx);
			else
				break;
			s_idx = smallest;
			L = s_idx * 2 + 1;
		    R = s_idx * 2 + 2;

		}
	}

	//Ԫ���ϸ�
	void heap_insert(int s_idx)
	{
		while (s_idx != 0)
		{
			int parent = (s_idx - 1) / 2;
			if (heap[s_idx].times < heap[parent].times)
			{
				swap(parent, s_idx);
				s_idx = parent;
			}
			else
				break;
		}
		return;
	}

	void print_topK_str()
	{
		cout << "now top 2 is:" << " ";
		for (int i = 0; i < heap.size(); i++)
		{
			cout << heap[i].str << " ";
		}
		cout << endl;
	}
};

int main()
{
	vector<string>  S{ "a","b","c","f","s","a","b","c","r","a","b","f","f","f","f","f","s","s","s" };
	PROBLEM07 P(2);
	for (int i = 0; i < S.size(); i++)
	{
		P.add(S[i]);
		P.print_topK_str();
	}
	return 0;
}