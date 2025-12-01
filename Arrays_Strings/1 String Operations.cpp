#include <iostream>
using namespace std;

int length(char s[50]){
    int length = 0;

    while(s[length] != '\0'){
        length++;
    }

    s[length] = '\0';

    return length;
}

int copy(char s[50]){
    char copy[50];
    int i = 0;

    while(s[i] != '\0'){
        copy[i] = s[i];
        i++;
    }

    copy[i] = '\0';
    cout << "\nCopied string: " << copy << endl;

    return 0;
}

int reverse(char s[50]){
    int len = length(s);

    int start = 0;
    int end = len -1;
    char temp;

    while(start<end){
        temp = s[start];
        s[start] =  s[end];
        s[end] = temp;
        start++;
        end--;
    }

    s[len] = '\0'; 
    cout << "\nReversed string: " << s << endl;

    return 0;
}

int concatenate(char s[50]){
    char s1[50];
    cout << "\nEnter another string to concatenate to the end of the first string: ";
    cin >> s1;
    
    int len = length(s);
    int i = 0;

    while (s1[i] != '\0'){
        s[len + i] = s1[i];
        i++;
    }

    s[len + i] = '\0';
    cout << "\nConcatenated string: " << s << endl;

    return 0;
}

int substring(char s[50]){
    char sub[50];
    cout << "\nEnter a substring to find in the string: ";
    cin >> sub;

    int slen = length(s);
    int sublen = length(sub);

    if (sublen > slen) {
        cout << "Substring not found!" << endl;
        return 0;
    }

    bool found = false;
    
    for (int i = 0; i<=slen-sublen; i++){
        bool match = true;

        for (int j = 0; j < sublen; j++) {
            if (s[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        
        if (match){
            cout << "Substring found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Substring not found." << endl;
    }

    return 0;
}

int main() {
    char s[50];
    cout << "Enter a string: ";
    cin >> s;

    int choice;

    do
    {
        cout << "\nWhat operation would you like to perform? \n 1. Find length of string\n 2. Copy to another string\n 3. Reverse string\n 4. Concatenate with another string\n 5. Find a substring in the entered string\nYour choice: ";
        cin >> choice;
        int len;
        switch(choice){
            case 1:
                len = length(s);
                cout << "\nLength of the string: " << len << endl;
                break;

            case 2:
                copy(s);
                break;

            case 3:
                reverse(s);
                break;

            case 4:
                concatenate(s);
                break;

            case 5:
                substring(s);
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Would you like to perform another operation? (Enter 0 for no, 1 for yes): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting the program. Thanks!" << endl;
        }
    } while (choice != 0);
    

}
// String operations (length, copy, reverse, concatenate, substring) using char arrays | Time: O(n) for each operation

