#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//检查命令行参数
void checkArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "usage : " << argv[0] << " doubleNumber" << std::endl;
		std::cout << "usage : " << argv[0] << " hexNumber" << std::endl;
		std::quick_exit(0);
	}
}

std::string& str_trim(std::string& s, std::string pattern)
{
	if (s.empty())
	{
		return s;
	}
	s.erase(0, s.find_first_not_of(pattern));
	s.erase(s.find_last_not_of(pattern) + 1);
	return s;
}
void str_replace(std::string& strBig, const std::string& strsrc, const std::string& strdst)
{
	std::string::size_type pos = 0;
	std::string::size_type srclen = strsrc.size();
	std::string::size_type dstlen = strdst.size();
	while ((pos = strBig.find(strsrc, pos)) != std::string::npos)
	{
		std::cout << "	[+]原始字符串:" << strBig << std::endl;
		strBig.replace(pos, srclen, strdst);
		pos += dstlen;
		std::cout << "	[-]替换后字符串:" << strBig << std::endl;
	}
}

