#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string encryptCaesar(const string &plaintext, int shift) {
  string ciphertext = "";

  for (char ch : plaintext) {
    if (isalpha(ch)) {
      char base = islower(ch) ? 'a' : 'A';
      ciphertext += static_cast<char>((ch - base + shift + 26) % 26 + base);
    } else {
      ciphertext += ch;
    }
  }

  return ciphertext;
}

string decryptCaesar(const string &ciphertext, int shift) {
  // Decryption is the same as encryption with a negative shift
  return encryptCaesar(ciphertext, -shift);
}

void processFile(const string &filename, int shift, bool encrypt) {
  ifstream inputFile(filename);
  if (!inputFile.is_open()) { cerr << "Error opening file: " << filename << endl; return; }

  string content((istreambuf_iterator<char>(inputFile)),
                 istreambuf_iterator<char>());
  inputFile.close();

  string processedContent;
  if (encrypt) {
    processedContent = encryptCaesar(content, shift);
  } else {
    processedContent = decryptCaesar(content, shift);
  }

  ofstream outputFile(filename);
  if (!outputFile.is_open()) {
    cerr << "Error opening file for writing: " << filename << endl;
    return;
  }

  outputFile << processedContent;
  outputFile.close();

  cout << (encrypt ? "Encryption" : "Decryption")
       << " completed. Result written to: " << filename << endl;
}

int main() {
  string filename;
  int shift;
  char choice;

  cout << "Do you want to (E)ncrypt or (D)ecrypt a file? ";
  cin >> choice;

  cout << "Enter the name of the file: ";
  cin >> filename;

  cout << "Enter the Caesar cipher key (an integer): ";
  cin >> shift;

  switch (choice) {
  case 'e':
  case 'E':
    processFile(filename, shift, true);
    break;
  case 'd':
  case 'D':
    processFile(filename, shift, false);
    break;
  default:
    cerr << "Invalid choice. Please enter 'E' or 'D'." << endl;
    break;
  }

  return 0;
}
