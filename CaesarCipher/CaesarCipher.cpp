#include "CaesarCipher.h"
#include <string>

using namespace std;


CaesarCipher::CaesarCipher(int _key) {
    key = (_key % 26);
    while (key < 0) {
        key = key + 26; 
    }

}


string CaesarCipher::encrypt(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
               text[i] = (text[i] - 'a' + key) % 26 + 'a'; 
            }
            else if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + key) % 26 + 'A';
            }
        }
    }
    return text;
}
string CaesarCipher::decrypt(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                text[i] = (text[i] - 'a' + 26 - key) % 26 + 'a';
            }
            else if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + 26 - key) % 26 + 'A';
            }
        }
    }
    return text;
}



