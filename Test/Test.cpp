// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <StringFuncs.h>
#include <iostream>

using namespace std;
using namespace RlibC_String;

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "Hola.Adios.Hello.Bye";
	vector<string> v;
	v = StringFuncs::split(s, "Hy");
	for(int i=0; i<v.size(); i++){
		cout << v.at(i) << endl;
	}

	system("pause");

	int state = StringFuncs::isInCharString(s, "Hello");

	cout << state << endl;

	system("pause");

	string file = "C:\\Users\\rdcelis\\Desktop\\test\\save.txt";

	StringFuncs::saveDATA(file, s, true);

	system("pause");

	return 0;
}

