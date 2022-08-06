#include "FileUpdation.h"

FileUpdation::FileUpdation() {
	this->name = "";
	this->coins = 0;
}
FileUpdation::FileUpdation(string name, int coins) {
	this->name = name;
	this->coins = coins;
}
void FileUpdation::Reading() {
	FileUpdation F1;
	ifstream Ofile("Data.bin");
	while (!Ofile.eof())
	{
		Ofile.read((char*)&F1, sizeof(F1));
		if (!Ofile.eof())
		{
			F1.Display();
		}
	}
	Ofile.close();
}
void FileUpdation::Writing(FileUpdation par) {
	ofstream Ifile("Data.bin",ios::app);
	Ifile.write((char*)&par, sizeof(par));
	Ifile.close();
}
void FileUpdation::SetName() {
	cout << "Enter the Player's name: ";
	getline(cin, name);
}
void FileUpdation::SetCoin(int Collected) {
	this->coins = Collected;
}

void FileUpdation::Display() {
	cout << name << "\t" << coins<<endl;
}