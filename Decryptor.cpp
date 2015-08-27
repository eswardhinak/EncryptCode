#include "Decryptor.hpp"


Decryptor::Decryptor(string key, bool directory){
	this->key = key;
	this->directory = directory;
}
void Decryptor::startDecryption(string path1){
	if (this->directory){
		for (recursive_directory_iterator end, dir(path1); dir!=end; ++dir){
			cout << *dir << endl;
			string dirName = dir->path().string();
			fileDecrypt(dirName);
		}
	}
	else{
		fileDecrypt(path1);
	}
}
int Decryptor::fileDecrypt(string path){
	ifstream is(path);
	ofstream os("temp2");
	int key_length  = key.length();
	int current_location = 0;
	char c;
	while(is.get(c)){
		char keyChar = key.at(current_location);
		int shiftValue = (int(c) - int(keyChar)) % 256;
		cout << shiftValue;
		char inChar = char(shiftValue);
		cout << c << keyChar << inChar << endl;

		os.put(inChar);
		current_location++;
		current_location = current_location % key_length;		
	}
	remove(path.c_str());
	rename("temp2", path.c_str());
}