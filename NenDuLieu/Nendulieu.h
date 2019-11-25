#pragma once
#ifndef _NENDULIEU_H_
#define _NENDULIEU_H_

struct Node
{
	int tanso;
	Node* left, * right;
};

//Hàm đọc file và đếm số kí tự cùng tần số tương ứng
void DocFile(string tenFile, vector<char>& arr_kitu, vector<int>& arr_tanso);

// Hàm tạo node cơ sở 
void TaoNodeCoSo(Node* pRoot, int data);

// Hàm tạo node co 2 con
void TaoNode(Node* pRoot, Node* left, Node* right);

//Hàm tìm vị trí Node có data nho nhat trong danh sách Node
int Min(vector<Node*> arr_Node);

// Hàm tìm vị trí có data nho thu 2 trong danh sach Node
int Min2(vector<Node*> arr_Node);

// Hàm tạo cây.
void TaoCay(vector<int> arr_tanso, vector<Node*>& arr_Node);

#endif // !_NENDULIEU_H_
