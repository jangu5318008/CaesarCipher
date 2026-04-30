#include <iostream>
#include "CaesarCipher.h"   
#include <fstream>

using namespace std;

int main() {


    

    int n;
    string text, input, encrypted, decrypted, cipherText;


    while (true) {
        cout << "Input each line of text, followed by enter. Input 'q' to quit" << '\n';
        getline(cin, input);
        if (input == "q") {
            break;
        }
        else {
            text += input + '\n'; 
        }
    }
            while (true) {
                cout << "Input the key (integer): " << '\n';
                if (cin >> n) {
                    cout << '\n';
                    break;
                }
                    cout << "Invalid key. Please enter a non-negative integer." << endl;
                    cin.clear();
                    //will only ignore up to 10k characters
                    cin.ignore(10000, '\n');
                }


          


            CaesarCipher cipher(n);
            encrypted = cipher.encrypt(text);
            //cout << "Cipher: " << encrypted << endl;

            ofstream outFile("cipher.txt");
            outFile << encrypted;
            outFile.close();

            ifstream inFile("cipher.txt");
            while (getline(inFile, input)) {
                cipherText += input + '\n';
            }
            inFile.close();

            cout << "Cipher: " << '\n' << cipherText << endl;
            decrypted = cipher.decrypt(cipherText);
            cout << "Decipher: " << '\n' << decrypted << endl;





    return 0;
}



/* TO DO
Open an ofstream

    Output the encrypted text to the stream
    Close the file

Open an ifstream

    Construct an empty string for the cipherText 
    To preserve whitespace, use getline to read one line at a time
    Concatenate each line followed by a '\n' onto cipherText
*/