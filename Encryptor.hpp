#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

using namespace std;

/* Class to encrypt files.*/
class Encryptor{
string key;	
bool directory;

public:
	Encryptor(string key, bool directory);
	int fileEncrypt(string path);
	bool getDirectory();
	void startEncryption(string path);
	string fileNameEncrypt(string path);

};
