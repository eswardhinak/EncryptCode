#include "Decryptor.hpp"


Decryptor::Decryptor(string key, bool directory){
	this->key = key;
	this->directory = directory;
}
void Decryptor::startDecryption(string path){
	if (this->directory){

	}
	else{
		fileDecrypt(path);
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