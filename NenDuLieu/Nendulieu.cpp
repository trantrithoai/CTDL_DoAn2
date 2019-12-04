#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

#include "Nendulieu.h"

//Hàm đọc file và đếm số kí tự cùng tần số tương ứng
//Hàm trả về 0 nếu không đọc được file và bỏ qua không đọc file đã nén
int DocFile(string tenFile, string& str, vector<char>& arr_kitu, vector<int>& arr_tanso)
{
	ifstream FileIn;
	FileIn.open(tenFile, ios_base::in);

	if (FileIn.fail())
	{
		cout << "Khong mo duoc file nay!" << endl;
		return 0;
	}

	if (tenFile.find("_Nen.txt") != -1)
		return 0;

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

	return 1;
}

// Hàm tạo node cơ sở 
void TaoNodeCoSo(Node* p, int data, char kitu)
{
	p->tanso = data;
	p->kitu = kitu;
	p->duongdi = "";
	p->left = p->right = NULL;
}

// Hàm ghép 2 node.
void GhepNode(Node* p, Node* left, Node* right)
{
	p->tanso = left->tanso + right->tanso;
	p->kitu = NULL;
	p->duongdi = "";
	p->left = left;
	p->right = right;
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
	int min2 = 0;

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

// Hàm tạo cây huffman
void TaoCay(vector<int> arr_tanso, vector<char> arr_kitu, vector<Node*>& arr_Node)
{
	for (int i = 0; i < arr_tanso.size(); i++)
	{
		Node* p = new Node;
		TaoNodeCoSo(p, arr_tanso[i], arr_kitu[i]);
		arr_Node.push_back(p);
	}

	while (arr_Node.size() > 1)
	{
		Node* p = new Node;

		int min = Min(arr_Node);
		int min2 = Min2(arr_Node);

		GhepNode(p, arr_Node[min], arr_Node[min2]);
		arr_Node.push_back(p);

		arr_Node.erase(arr_Node.begin() + min);

		if (min2 > min)
			arr_Node.erase(arr_Node.begin() + min2 - 1);
		else
			arr_Node.erase(arr_Node.begin() + min2);
	}
}

//Hàm tạo mã là đường đi cho mỗi node trong cây huffman
void TaoMa(Node* p)
{
	if (p->left != NULL)
	{
		p->left->duongdi = p->duongdi + "0";
		p->right->duongdi = p->duongdi + "1";
		TaoMa(p->left);
		TaoMa(p->right);
	}
}

//Hàm tìm mã đường đi của node chứa kí tự x
void TimMa(Node* p, char x, string& str)
{
	if (p != NULL)
	{
		TimMa(p->left, x, str);

		if (p->kitu == x)
		{
			str = p->duongdi;
			return;
		}

		TimMa(p->right, x, str);
	}
}

//Hàm tạo danh sách mã đường đi
void TaoBangMa(vector<string>& arr_bangma, vector<char> arr_kitu, Node* p)
{
	TaoMa(p);

	arr_bangma.resize(arr_kitu.size());

	for (int i = 0; i < arr_kitu.size(); i++)
	{
		string str;

		TimMa(p, arr_kitu[i], str);

		arr_bangma[i] = str;
	}
}

//Hàm nén tập tin
void NenTapTin(string tenFile)
{
	vector<char> arr_kitu;
	vector<int> arr_tanso;

	string str;
	if (DocFile(tenFile, str, arr_kitu, arr_tanso) == 0)
		return;

	vector<Node*> arr_Node;

	TaoCay(arr_tanso, arr_kitu, arr_Node);

	vector<string> arr_bangma;

	TaoBangMa(arr_bangma, arr_kitu, arr_Node[0]);

	
	string myfile = tenFile.insert(tenFile.length() - 4, "_Nen");

	ofstream FileOut;

	FileOut.open(myfile);

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < arr_kitu.size(); j++)
		{
			if (str[i] == arr_kitu[j])
			{
				FileOut << arr_bangma[j];
				break;
			}
		}
	}

	FileOut.close();

	delete arr_Node[0];
}

//Hàm nén tập tin trong thư mục
void NenTapTin_ThuMuc(string tenFile)
{
	vector<char> arr_kitu;
	vector<int> arr_tanso;

	string str;
	if (DocFile("D:/Do an 2_CTDL/18120581_18120560/NenDuLieu/ThuMucTapTin/" + tenFile, str, arr_kitu, arr_tanso) == 0)
		return;

	vector<Node*> arr_Node;

	TaoCay(arr_tanso, arr_kitu, arr_Node);

	vector<string> arr_bangma;

	TaoBangMa(arr_bangma, arr_kitu, arr_Node[0]);


	string myfile = tenFile.insert(tenFile.length() - 4, "_Nen");

	ofstream FileOut;

	FileOut.open("D:/Do an 2_CTDL/18120581_18120560/NenDuLieu/ThuMucTapTin/" + myfile);

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < arr_kitu.size(); j++)
		{
			if (str[i] == arr_kitu[j])
			{
				FileOut << arr_bangma[j];
				break;
			}
		}
	}

	FileOut.close();

	delete arr_Node[0];
}

//Hàm nén thư mục chứa nhiều tập tin
void NenThuMucTapTin(const string& name)
{
	string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;

	vector<string> arr_file;

	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			arr_file.push_back(data.cFileName);

		} while (FindNextFile(hFind, &data) != 0);

		FindClose(hFind);
	}
	
	for (int i = 2; i < arr_file.size(); i++)
	{
		NenTapTin_ThuMuc(arr_file[i]);
	}
}
