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

int main() {
  cout << "Hello, world" << endl;

  return 0;
}