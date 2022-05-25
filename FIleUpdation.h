#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileUpdation
{
private:
	string name;
	int coins;
public:
	FileUpdation(string name, int coins);
	FileUpdation();
	void Reading();
	void Writing(FileUpdation par);
	void SetName();
	void SetCoin(int Collected);
	void Display();
};
