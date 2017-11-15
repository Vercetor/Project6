//**************************************************
// AUTHOR: Colin Powers
// DATE: 11/11/17
// PROGRAM NAME: Project 6
// PROGRAM DESCRIPTION: Hash Table
//**************************************************

#pragma once
#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// Hash table size as a constant of 128.
const int TABLE_SIZE = 128;

// Create a class for Hash Entry
class hashEntry
{
public:
	// values for hash entry.
	string key;
	string value;

	hashEntry(string key, string value)
	{
		this->key = key;
		this->value = value;
	}// END OF HASH ENTARY
};// END OF HASH ENTRY CLASS


// Create the hash table/map decleration
class hTable
{

private:
	hashEntry **table;

public:
	hTable()
	{
		table = new hashEntry *[TABLE_SIZE];
		for (int ix = 0; ix < TABLE_SIZE; ix++)
		{
			table[ix] = NULL;
		}
	}

	// Hash Function
	string hashFunction(string key)
	{
		return key % TABLE_SIZE;
	}

	// Insert
	string insert(string key, string value)
	{
		string hash = hashFunction(key);

		while (table[hash] != NULL && table[hash]->key != key)
		{
			hash = hashFunction(hash + 1);
		}

		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new hashEntry(key, value);
	}

	string search(string key)
	{
		string hash = hashFunction(key);
		while (table[hash] != NULL && table[hash]->key != key)
		{
			hash = hashFunction(hash + 1);
		}
		if (table[hash] == NULL)
			return -1;
		else
			return table[hash]->value;
	}



};// END HASHMAP


#endif 
