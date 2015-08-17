#include "Encryptor.hpp"

Encryptor::Encryptor(string key, bool directory){
	this->key = key;
	this->directory = directory;
}
int Encryptor::fileEncrypt(string path){
	/*string fileName = fileNameEncrypt(path);
	for (int i = 0; i < fileName.length(); i++){
		char key_char = key.at(i%key.length());
		int value = int (key_char);
		int shifted_value = int(fileName.at(i)) + int(key_char);
		char new_char = char(shifted_value);
		cerr << shifted_value << endl;
	}*/
	ifstream is(path); //open stream to read in the file.
	ofstream os("temp"); //open stream to the file to write to
	int key_length = key.length();
	int current_location = 0;
	char c;			   //current character
	while(is.get(c)){

		char key_char = key.at(current_location);
		int value = int(key_char);
		int shifted_value = (int(c) + int(key_char)) % 256;
		//cout << shifted_value << endl;
		char new_char = char(shifted_value);
		//cout << c << key_char << new_char << endl;

		os.put(new_char);
		current_location++;
		current_location = current_location % key_length;
	}
	//these are C functions
	remove(path.c_str());
	rename("temp", path.c_str());

}
string Encryptor::fileNameEncrypt(string path){
	int backslashPosition = path.find_last_of("/");
 	string fileName = path.substr(backslashPosition+1, path.length());
 	cerr << fileName << endl;
 	return fileName;
}
void Encryptor::startEncryption(string path){
	//If this is a directory, handle here file by file
	if (this->directory){


	}
	//If it is a single file, send to fileEncrypt from here.
	else{
		fileEncrypt(path);
	}
}

