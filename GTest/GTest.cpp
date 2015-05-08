// GTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include <StringFuncs.h>

#include <iostream>

using namespace std;
using namespace RlibC_String;

string s = "Hola.Adios.Hello.Bye";

TEST(StringFuncs, split){
	vector<string> v, v_expected;
	v = StringFuncs::split(s, ".");
	v_expected.push_back("Hola");
	v_expected.push_back("Adios");
	v_expected.push_back("Hello");
	v_expected.push_back("Bye");
	for(int i=0; i<v.size(); i++){
		EXPECT_STREQ(v_expected.at(i).c_str(), v.at(i).c_str());
	}

	v = StringFuncs::split(s, "Hy");
	v_expected.clear();
	v_expected.push_back("ola.Adios.");
	v_expected.push_back("ello.B");
	v_expected.push_back("e");
	for(int i=0; i<v.size(); i++){
		EXPECT_STREQ(v_expected.at(i).c_str(), v.at(i).c_str());
	}
}

TEST(StringFuncs, isInCharString){
	int state = StringFuncs::isInCharString(s, ".");
	EXPECT_EQ(3, state);
	state = StringFuncs::isInCharString(s, "z");
	EXPECT_EQ(0, state);
	state = StringFuncs::isInCharString(s, "Hello");
	EXPECT_EQ(1, state);

}

TEST(StringFuncs, saveData){
	string filename = "test.txt";
	//Overwrite
	StringFuncs::saveDATA(filename, s, false);
	
	ifstream in;
	in.open(filename, std::ifstream::in);
	int numLines = 0;
	string line;

	getline(in, line);
	numLines++;
	EXPECT_STREQ(s.c_str(), line.c_str());
	
	while(getline(in, line)){ numLines++; };
	EXPECT_EQ(1, numLines);
	in.close();

	//Append
	StringFuncs::saveDATA(filename, s, true);

	in.open(filename, std::ifstream::in);
	numLines = 0;

	getline(in, line);
	numLines++;
	EXPECT_STREQ(s.c_str(), line.c_str());
	getline(in, line);
	numLines++;
	EXPECT_STREQ(s.c_str(), line.c_str());
	
	while(getline(in, line)){ numLines++; };
	EXPECT_EQ(2, numLines);
	in.close();

	//Bad Filename
	try{
		StringFuncs::saveDATA("\\subtest\\bad.txt", s, false);
		FAIL() << "Exception expected --> (ofstream) error while opening file.";	// Test Crash
	}catch(exception& e){
		EXPECT_STREQ("(ofstream) error while opening file.", e.what());				// Test Correct
	}

	remove(filename.c_str());

}

TEST(StringFuncs, trim){
	string s;
	s = StringFuncs::trim("Hola Adios");
	EXPECT_STREQ("HolaAdios", s.c_str());
	s = StringFuncs::trim(s.c_str());
	EXPECT_STREQ(s.c_str(), s.c_str());
	s = StringFuncs::trim("Hola		Adios");
	EXPECT_STREQ("HolaAdios", s.c_str());
	s = StringFuncs::trim("		Hola Adios");
	EXPECT_STREQ("HolaAdios", s.c_str());
	s = StringFuncs::trim("Hola Adios	 ");
	EXPECT_STREQ("HolaAdios", s.c_str());
}

TEST(StringFuncs, toUpperCase){
	EXPECT_STREQ("HOLA ADIOS", StringFuncs::toUpperCase("Hola Adios").c_str());
}

TEST(StringFuncs, toLowerCase){
	EXPECT_STREQ("hola adios", StringFuncs::toLowerCase("Hola Adios").c_str());
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Testing
	testing::InitGoogleTest (&argc, argv);
	cout << "-------------------------" << endl;	
	cout << "RlibC++ Testing" << endl;	
	cout << "-------------------------" << endl;
	cout << endl << "/////////////////////////" << endl;	
	cout << "+String Functions" << endl;	
	cout << "  -split" <<endl;
	cout << "  -isInCharString" <<endl;
	cout << "  -saveData" << endl;
	cout << "  -trim" << endl;
	cout << "  -toUpperCase" << endl;
	cout << "  -toLowerCase" << endl;
	cout << "/////////////////////////" << endl << endl << endl;

	RUN_ALL_TESTS ();
	system("pause");
	return 0;
}

