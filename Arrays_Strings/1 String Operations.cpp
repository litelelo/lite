#include <iostream>
using namespace std;

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void stringCopy(char source[], char dest[]) {
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

void stringReverse(char str[]) {
    int len = stringLength(str);
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void stringConcat(char str1[], char str2[]) {
    int len1 = stringLength(str1);
    int i = 0;
    while (str2[i] != '\0') {
        str1[len1 + i] = str2[i];
        i++;
    }
    str1[len1 + i] = '\0';
}

int main() {
    char str1[100], str2[100], str3[100];
    
    cout << "Enter string 1: ";
    cin >> str1;
    
    cout << "Length of string 1: " << stringLength(str1) << endl;
    
    stringCopy(str1, str3);
    cout << "Copied string: " << str3 << endl;
    
    stringReverse(str1);
    cout << "Reversed string 1: " << str1 << endl;
    stringReverse(str1); 
    
    cout << "Enter string 2: ";
    cin >> str2;
    
    stringConcat(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
    
    return 0;
}
// String operations: length, copy, reverse, concat without built-in functions | Time: O(n)
