#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

using namespace std;
using namespace boost::filesystem;

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