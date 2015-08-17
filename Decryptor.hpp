#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Decryptor{
string key;
bool directory;

public:
	Decryptor(string key, bool directory);
	int fileDecrypt(string path);
	bool getDirectory();
	void startDecryption(string path);

};