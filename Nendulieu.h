#pragma once
#ifndef _NENDULIEU_H_
#define _NENDULIEU_H_

struct Node
{
	int tanso;
	char kitu;
	string duongdi;
	Node* left, * right;
};

//Hàm đọc file và đếm số kí tự cùng tần số tương ứng
//Hàm trả về 0 nếu không đọc được file và bỏ qua không đọc file đã nén
void DocFile(string tenFile, string& str, vector<char>& arr_kitu, vector<int>& arr_tanso);

// Hàm tạo node cơ sở 
void TaoNodeCoSo(Node* p, int data, char kitu);

// Hàm ghép 2 node
void GhepNode(Node* pRoot, Node* left, Node* right);

//Hàm tìm vị trí Node có data nho nhat trong danh sách Node
int Min(vector<Node*> arr_Node);

// Hàm tìm vị trí có data nho thu 2 trong danh sach Node
int Min2(vector<Node*> arr_Node);

// Hàm tạo cây.
void TaoCay(vector<int> arr_tanso, vector<char> arr_kitu, vector<Node*>& arr_Node);

//Hàm tạo mã là đường đi cho mỗi node trong cây huffman
void TaoMa(Node* p);

//Hàm tìm mã đường đi của node chứa kí tự x
void TimMa(Node* p, char x, string& str);

//Hàm tạo danh sách mã đường đi
void TaoBangMa(vector<string>& arr_bangma, vector<char> arr_kitu, Node* p);

//Hàm tính chiều cao cây huffman
int TinhChieuCao(Node* p);

//Hàm nén tập tin
void NenTapTin(string tenFile);

//Hàm giải nén tập tin
void GiaiNenTapTin(string tenFile);

//Hàm nén thư mục chứa nhiều tập tin
void NenThuMucTapTin(const string& name);

//Hàm nén tập tin trong thư mục
void NenTapTin_ThuMuc(string tenFile);

//Hàm giải nén tập tin thư mục
void GiaiNenTapTin_ThuMuc(string tenFile);

#endif // !_NENDULIEU_H_
