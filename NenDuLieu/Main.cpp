#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Nendulieu.h"

int main()
{
	NenTapTin("TapTin.txt");
	cout << "Da nen tap tin!\n";

	NenThuMucTapTin("ThuMucTapTin");
	cout << "Da nen thu muc tap tin!\n";

	system("pause");
	return 0;
}