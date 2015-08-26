/**
	Basic Stream Cipher and Vigener Cipher Encryption of Source Code. 
**/

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <dirent.h>
#include "Encryptor.hpp"
#include "Decryptor.hpp"
using namespace std;

int decryptDirectory(string, string);
int encryptDirectory(string, string);
int decryptFile(string, string);
int encryptFile(string, string);
string getKey();

/*
	Entry point into this program. 
*/
int main(int argc, char ** argv){
	cout << "Starting program..." << endl;
	char choice;
	do {
		cout << "(e)ncrypt or (d)ecrypt";
		cin >> choice;							//encryption mode vs decryption mode
	}while(choice != 'e' && choice != 'd');

	cout << "Enter path:  ";
	string path;
	cin >> path; 							//get path to source code

	const char * path_c = path.c_str();
	struct stat s;
	if (stat(path_c, &s) == 0){
		if (s.st_mode & S_IFDIR){
		//This is a directory
		cerr << "This is a directory.";
		string key = getKey();
		if (choice == 'e')
			encryptDirectory(path, key);
		else
			decryptDirectory(path, key);

		}
		else if (s.st_mode & S_IFREG){
		//Just a file
		cerr << "This is a file.";
		string key = getKey();
		if (choice == 'e')
			encryptFile(path, key);
		else
			decryptFile(path, key);
		}
		else{
		//something else
		cerr << "This isn't a file or a directory.\n";
		return 0;
		}
	}
	else{
		cerr << "File/Directory doesn't exist.\n";
		return 0;
	}

}

string getKey(){
	string key;
	cout << "Enter key: ";
	cin >> key;
	return key;
}

int encryptDirectory(string path, string key){
	Encryptor * encryptor = new Encryptor(key, true);
	encryptor->startEncryption(path);

}
int encryptFile(string path, string key){
	Encryptor * encryptor = new Encryptor(key, false);
	encryptor->startEncryption(path);
}
int decryptDirectory(string path, string key){
	return 0;
}
int decryptFile(string path, string key){
	Decryptor * decryptor = new Decryptor(key, false);
	decryptor -> startDecryption(path);
	return 0;
}









