#include<iostream>
#include<vector>
using namespace std;
char a;
bool found = false;
int main(){
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    cout << "Enter the character : ";
    cin >> a;
    for (int i = 0; i < vowels.size(); i++) {
        if (vowels[i] == a) {
            found = true;
        }
    }
    if (found == true) {
        cout << "The character is a vowel";
    }
    else {
        cout << "The character is a consonant";
    }
    return 0;
}