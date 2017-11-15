//**************************************************
// AUTHOR: Colin Powers
// DATE: 11/11/17
// PROGRAM NAME: Project 6
// PROGRAM DESCRIPTION: Hash Table
//**************************************************

#include "stdafx.h"
#include "hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// Function Prototype
string change(string str);

int main()
{
	// variables
	string key, value;
	string choice;
	
	// constructor
	hTable hTable;


	cout << "Which element would you like to search?" << endl;
	cin >> key;
	if (hash.search(key) == -1)
	{
		cout << "Word not found." << endl;
	}

	else
	{
		cout << "Word found!!!" << endl;
	}


	// open file called data.txt.
	ifstream fin;
	fin.open("data.txt");


	// while file isnt at the end then fill.
	while (!fin.eof()) {
		fin >> value;
		hTable.insert(change(value), key); // change for hash
	}


	


	// Close file
	fin.close();
	return 0;

}// END OF MAIN FUNCTION

 //******************************************************
 //*** Method Name: change
 //*** Method Author: Colin Powers
 //******************************************************
 //*** Purpose of the Method: Removes punctuation from words
 //*** Method parameters: string str
 //*** Return value: string
 //******************************************************
 //*** Date: 10/6/2017
 //******************************************************

string change(string str) {
	string temp = "";

	for (int ix = 0; ix < str.length(); ix++) {
		if (!ispunct(str[ix])) {
			temp += tolower(str[ix]);
		}
	}

	return temp;
} // END OF CHANGE FUNCTION