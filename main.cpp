#include <fstream>
#include <iostream>
using namespace std;

// Enumeration representing the two types of cipher operations
enum CipherOperation {
  Encryption, ///< Represents the encryption operation
  Decryption  ///< Represents the decryption operation
};

// Struct to hold information required for ciphering
struct CipherData {
  string filename;        ///< Path to the file that will be modified
  unsigned short int key; ///< The cipher key to use
  CipherOperation type; ///< Type of operation to perform (Encryption or Decryption)
};

// Checks whether the specified file exists or not
// @param path Path to the file
// @return true if the file exists, false otherwise
bool does_file_exist(string path);

// Prompts the user for input to populate the CipherData struct
// If any of the provided data is invalid, the program will exit
// @return A CipherData struct with user-provided information
CipherData get_cipher_info();

// Reads the entire content of a file
// @param path Path to the file
// @return The content of the given file as a string
string get_file_content(string path);

// Encrypts the content by shifting each character forward by 'n' positions,
// where 'n' is the key
// @param content The content to be encrypted
// @param key The encryption key
void encrypt(string &content, int key);

// Decrypts the content by shifting each character backward by 'n' positions,
// where 'n' is the key
// @param content The content to be decrypted
// @param key The decryption key
void decrypt(string &content, int key);

// Writes the provided content to the specified file
// @param content The content to be written
// @param path Path to the file
void write_to_file(string content, string path);

int main() {
  CipherData info = get_cipher_info();

  // Read the content of the file
  string content = get_file_content(info.filename);

  // Perform encryption or decryption based on user choice
  if (info.type == CipherOperation::Encryption) {
    encrypt(content, info.key);
  } else {
    decrypt(content, info.key);
  }

  // Write the modified content back to the file
  write_to_file(content, info.filename);

  return 0;
}

bool does_file_exist(string path) {
  ifstream file(path);
  return file.good();
}

CipherData get_cipher_info() {
  CipherData cipher_info;

  char choice;

  cout << "Enter 'E' for Encryption or 'D' for Decryption: ";
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
    // Exit if the choice is invalid
    cout << choice << " is not a valid choice" << endl;
    exit(1);
  }

  cout << "Enter file name: ";
  cin >> cipher_info.filename;
  // Exit if the file doesn't exist
  if (!does_file_exist(cipher_info.filename)) {
    cout << "Error: the \"" << cipher_info.filename << "\" file doesn't exist"
         << endl;
    exit(2);
  }

  cout << "Enter cipher key: ";
  cin >> cipher_info.key;

  return cipher_info;
}

string get_file_content(string path) {
  ifstream file;
  file.open(path, ios::in);

  if (!file.is_open()) {
    cout << "Error: Unable to open file " << path << endl;
    exit(3);
  }

  string line, content;

  // Read each line from file and store it in content
  while(getline(file, line)) {
    content += line + '\n';
  }

  return content;
}

void encrypt(string &content, int key) {
  // Get the length of the content
  int length = content.length();

  // Loop through each character in the content
  for (int i = 0; i < length; i++) {
    // Get the current character
    char &ch = content[i];

    // Encrypt only alphabetic characters
    if (isalpha(ch)) {
      // Determine the case (uppercase or lowercase) of the character
      char base = isupper(ch) ? 'A' : 'a';

      // Apply the Caesar cipher encryption formula
      ch = ((ch - base + key) % 26) + base;
    }
  }
}

void decrypt(string &content, int key) {
  // Get the length of the content
  int length = content.length();

  // Loop through each character in the content
  for (int i = 0; i < length; i++) {
    // Get the current character
    char &ch = content[i];

    // Decrypt only alphabetic characters
    if (isalpha(ch)) {
      // Determine the case (uppercase or lowercase) of the character
      char base = isupper(ch) ? 'A' : 'a';

      // Apply the Caesar cipher decryption formula
      ch = ((ch - base - key + 26) % 26) + base;
    }
  }
}

void write_to_file(string content, string path) {
  ofstream file;
  file.open(path, ios::out);

  if (!file.is_open()) {
    cout << "Error: Unable to open file for writing" << endl;
    exit(4);
  }

  // Write the modified content to the file
  file << content;
  file.close();
}
