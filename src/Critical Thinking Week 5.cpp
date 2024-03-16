//============================================================================
// Name        : Critical.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


void appendInput(string file) {
	string a;
	cout << "Enter What To Append To The File: " << endl;
	getline(cin, a);

	ofstream outputFile(file, ios::app);
	if (!outputFile) {
			cerr << "Could Not Open File" << endl;
			return;
		}

	outputFile << a;
	outputFile.close();
}

void reverseFile(string file){

	ifstream inFile(file);
	if (!inFile){
			cerr << "Could Not Open File" << endl;
			return;
		}

	stringstream buffer;
	buffer << inFile.rdbuf();

	inFile.close();

	ofstream outFile("CSC450-mod5-reverse.txt");
		if (!outFile){
				cerr << "Could Not Open File" << endl;
				return;
			}

	string s;
	s = buffer.str();

	reverse(s.begin(), s.end());
	outFile << s;

}

int main() {
	string filename = "CSC450_CT5_mod5.txt";

	appendInput(filename);
	reverseFile(filename);

	return 0;
}
