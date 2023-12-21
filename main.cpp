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
  // TODO(hammadmajid): check if the file exits

  cout << "Enter cipher key: ";
  cin >> cipher_info.key;

  return cipher_info;
}

int main() {
  CipherInfo info = get_cipher_info();

  return 0;
}