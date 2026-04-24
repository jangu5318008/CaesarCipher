#include <iostream>
#include "CaesarCipher.h"   
#include <fstream>

using namespace std;

int main() {

    int n;
    string text;
    string input;


    while (true) {
        cout << "Input each line of text, followed by enter. Input 'q' to quit";
        getline(cin, input);
        if (input == "q") {
            break;
        }
        else {
            text = input + '\n'; 

        }
    }
            while (true) {
                cout << "Input the key (integer): ";
                cin >> n;
                if (n < 0) {
                    cout << "Invalid key. Please enter a non-negative integer." << endl;
                    cin.clear();
                    //will only ignore up to 10k characters
                    cin.ignore(10000, '\n');

                }

            }

            CaesarCipher cipher(n);
            string encrypted = cipher.encrypt(input);
            cout << "Encrypted: " << encrypted << endl;
            string decrypted = cipher.decrypt(encrypted);
            cout << "Decrypted: " << decrypted << endl;





    return 0;
}