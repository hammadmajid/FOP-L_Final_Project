#include <fstream>
#include <iostream>
using namespace std;

enum CipherOperation {
  Encryption,
  Decryption,
};

struct CipherInfo {
  string filename;
  unsigned short int key;
  CipherOperation type;
};

bool does_file_exits(string path);
CipherInfo get_cipher_info();

int main() {
  CipherInfo info = get_cipher_info();

  return 0;
}

bool does_file_exits(string path) {
  ifstream file(path);
  return file.good();
}

CipherInfo get_cipher_info() {
  CipherInfo cipher_info;

  char choice;

  cout << "Enter \'E\' for Encryption or \'D\' for Decryption: ";
  cin >> choice;

  switch (choice) {
  case 'e':
  case 'E':
    cipher_info.type = CipherOperation::Encryption;
    break;

  case 'd':
  case 'D':
    cipher_info.type = CipherOperation::Decryption;
    break;

  default:
    cout << choice << " is not a valid choice" << endl;
    exit(1);
  }

  cout << "Enter file name: ";
  cin >> cipher_info.filename;
  // handle the case where file doesn't exit
  if (!does_file_exits(cipher_info.filename)) {
    cout << "Error: the \"" << cipher_info.filename << "\" file doesn't exit" << endl;
    exit(2);
  }

  cout << "Enter cipher key: ";
  cin >> cipher_info.key;

  return cipher_info;
}
