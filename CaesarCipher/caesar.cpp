#include<iostream>
#include <string>
using namespace std;

int main() {
    int shift;
    char message[100];
    
    cout << "Please enter message to encrypt" << endl;
    cin.getline(message, sizeof(message));
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Thank you, now enter shift" << endl;
    cin >> shift;
    bool boolin = false;
    for (int x = 0; x < strlen(message); x++) {
        if (int(message[x]) + shift > 122) {
            int temp = int(message[x]) + shift;
            int newShift = temp - 122;
            message[x] = 97 + newShift - 1;
            boolin = true;
        }
        if (int(message[x]) <= 90) {
            if (int(message[x] + shift > 90)) {
                int temp = int(message[x]) + shift;
                int newShift = temp - 90;
                message[x] = 65 + newShift - 1;
                boolin = true;
            }            
        }
        if (message[x] == 32) {
            continue;
        }
        if (!boolin) {
            message[x] += shift;
        }
        boolin = false;
    }
    
    cout << message << endl;
    return 0;
}