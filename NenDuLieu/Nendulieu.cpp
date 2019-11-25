#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Nendulieu.h"

//Hàm đọc file và đếm số kí tự cùng tần số tương ứng
void DocFile(string tenFile, vector<char>& arr_kitu, vector<int>& arr_tanso)
{
	ifstream FileIn;
	FileIn.open(tenFile, ios_base::in);

	string str;
	getline(FileIn, str);

	arr_kitu.push_back(str[0]);

	for (int i = 1; i < str.size(); i++)
	{
		int check = 1;

		for (int j = 0; j < arr_kitu.size(); j++)
		{
			if (str[i] == arr_kitu[j])
			{
				check = 0;
				break;
			}
		}

		if(check == 1)
			arr_kitu.push_back(str[i]);
	}

	for (int i = 0; i < arr_kitu.size(); i++)
	{
		int dem = 0;

		for (int j = 0; j < str.size(); j++)
		{
			if (arr_kitu[i] == str[j])
				dem++;
		}

		arr_tanso.push_back(dem);
	}

	FileIn.close();
}

// Hàm tạo node cơ sở 
void TaoNodeCoSo(Node* pRoot, int data)
{
	pRoot->tanso = data;
	pRoot->left = pRoot->right = NULL;
}

// Hàm tạo node co 2 con
void TaoNode(Node* pRoot, Node* left, Node* right)
{
	pRoot->tanso = left->tanso + right->tanso;
	pRoot->left = left;
	pRoot->right = right;
}

//Hàm tìm vị trí Node có data nho nhat trong danh sách Node
int Min(vector<Node*> arr_Node)
{
	int min = 0;

	for (int i = 1; i < arr_Node.size(); i++)
	{
		if (arr_Node[i]->tanso < arr_Node[min]->tanso)
		{
			min = i;
		}
	}

	return min;
}

// Hàm tìm vị trí có data nho thu 2 trong danh sach Node
int Min2(vector<Node*> arr_Node)
{
	int min = Min(arr_Node);
	int min2;

	for (int i = 0; i < arr_Node.size(); i++)
	{
		if (i != min)
		{
			min2 = i;
			break;
		}
	}

	for (int i = 0; i < arr_Node.size(); i++)
	{
		if (i != min and arr_Node[i]->tanso < arr_Node[min2]->tanso)
			min2 = i;
	}
	return min2;
}

// Hàm tạo cây.
void TaoCay(vector<int> arr_tanso, vector<Node*>& arr_Node)
{
	for (int i = 0; i < arr_tanso.size(); i++)
	{
		Node* p = new Node;
		TaoNodeCoSo(p, arr_tanso[i]);
		arr_Node.push_back(p);
	}

	while (arr_Node.size() > 1)
	{
		Node* p = new Node;

		int min = Min(arr_Node);
		int min2 = Min2(arr_Node);

		TaoNode(p, arr_Node[min], arr_Node[min2]);
		arr_Node.push_back(p);

		arr_Node.erase(arr_Node.begin() + min);

		int min_temp = Min(arr_Node);
		arr_Node.erase(arr_Node.begin() + min_temp);
	}
}

//Hàm tạo bảng mã.
void TaoBangMa(vector<char> arr_tanso, Node* tree, vector<string>& arr_bangma)
{
	for (int i = 0; i < arr_tanso.size(); i++)
	{
		//if(arr_tanso[i] > tree->tanso)
	}
}

void LNR(Node* p)
{

}