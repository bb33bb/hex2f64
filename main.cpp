#include <Windows.h>
#include <string>
#include <iostream>
#include "common.h"
#include <iomanip>
union HEXF
{
	DWORD64 hexNum;
	double dobNum;
};
int main(int argc, char* argv[])
{
	checkArgs(argc, argv);
	std::string data = argv[1];
	std::size_t found = data.find(".");
	if (found != std::string::npos)
	{
		//找到"."字符，说明输入的是个double类型
		auto data_d = stod(data);
		HEXF hexf;
		hexf.dobNum = data_d;
		std::cout << std::hex << std::setw(16) << std::setfill('0') << hexf.hexNum;
		return 0;
	}
	else
	{
		auto data_ll = stoll(data, NULL, 16);
		HEXF hexf;
		hexf.hexNum = data_ll;
		std::cout << std::setprecision(16) << hexf.dobNum;
		return 0;
	}
}