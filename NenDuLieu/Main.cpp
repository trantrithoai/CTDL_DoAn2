#include <iostream>
#include <vector>
using namespace std;

#include "Nendulieu.h"

int main()
{
	vector<char> arr_kitu;
	vector<int> arr_tanso;
	DocFile("string.txt", arr_kitu, arr_tanso);

	vector<Node*> arr_Node;

	TaoCay(arr_tanso, arr_Node);

	//vector<string> arr_bangma;


	delete arr_Node[0];

	system("pause");
	return 0;
}