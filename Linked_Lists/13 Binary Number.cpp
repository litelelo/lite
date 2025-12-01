#include <iostream>
#include <vector>
using namespace std;

typedef struct DLL{
    int bit;
    struct DLL *next;
    struct DLL *prev;
} *node;

node first = NULL;
node first2 = NULL;

node accept(){
    node a = new DLL;
    do{
        cout << "\nEnter a bit: ";
        cin >> a->bit;

        if(!(a->bit == 1 || a->bit == 0)){
            cout << "Invalid input.";
        }
    } while(!(a->bit == 1 || a->bit == 0));
    a->next = NULL;
    a->prev = NULL;

    return a;
}

void addbit(node &f){
    node newnode = accept();

    if(f == NULL){
        f = newnode;
    }
    else{
        node temp = f;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
        
    cout << "Bit added.";
}

void display(node &f){
    if(f == NULL){
        cout << "\nNo bits entered yet.";
        return;
    }

    node temp = f;
    while(temp != NULL){
        cout << temp->bit << " ";
        temp = temp->next;
    }
}

void complement(){
    if(first == NULL){
        cout << "\nNo bits to complement.";
        return;
    }

    node temp = first;
    cout << "\nOne's complement is: \n";
    while(temp != NULL){
        int tempbit = temp->bit == 0 ? 1 : 0;
        cout << tempbit << " ";
        temp = temp->next;
    }

    cout << "\nTwo's complement is: \n";

    node tail = first;
    while(tail->next != NULL){
        tail = tail->next;
    }
    
    int carry = 1;  
    node current = tail;
    
    int size = 0;    
    temp = first;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    vector<int> result(size);
    
    for(int i = size-1; i >= 0; i--){
        int flippedBit = (current->bit == 0) ? 1 : 0;  
        int sum = flippedBit + carry;                  
        
        result[i] = sum % 2;                           
        carry = sum / 2;                               
        
        current = current->prev;                       
    }

    for(int i = 0; i < size; i++){
        cout << result[i] << " ";
    }
}

void addition(){
    if(first == NULL || first2 == NULL){
        cout << "\nBoth binary numbers must be entered first.";
        return;
    }
    
    // Find tails of both numbers
    node tail1 = first;
    while(tail1->next != NULL){
        tail1 = tail1->next;
    }
    
    node tail2 = first2;
    while(tail2->next != NULL){
        tail2 = tail2->next;
    }

    int size1 = 0, size2 = 0;
    node temp = first;
    while(temp != NULL){
        size1++;
        temp = temp->next;
    }
    
    temp = first2;
    while(temp != NULL){
        size2++;
        temp = temp->next;
    }
    
    int maxSize = (size1 > size2) ? size1 : size2;
    vector<int> result(maxSize + 1, 0);
    
    int carry = 0;
    node current1 = tail1;
    node current2 = tail2;
    int pos = maxSize; 
    
    while(current1 != NULL || current2 != NULL || carry > 0){
        int bit1 = (current1 != NULL) ? current1->bit : 0;
        int bit2 = (current2 != NULL) ? current2->bit : 0;
        
        int sum = bit1 + bit2 + carry;
        result[pos] = sum % 2;
        carry = sum / 2;
        
        if(current1 != NULL) current1 = current1->prev;
        if(current2 != NULL) current2 = current2->prev;
        pos--;
    }
    
    cout << "\nSum is: ";
    bool started = false;
    for(int i = 0; i <= maxSize; i++){
        if(result[i] == 1) started = true;
        if(started) cout << result[i] << " ";
    }
    if(!started) cout << "0 ";  // Handle case where sum is 0
}

int main(){
    int c;

    do{
        cout << "\n\nWhat operation would you like to perform:\n 1. Add a bit\n 2. Display binary number\n 3. Display one's and two's complement\n 4. Add two binary numbers\n 5. Exit\nYour choice: ";
        cin >> c;

        switch(c){
            case 1:
                addbit(first);
                break;
            
            case 2:
                display(first);
                break;

            case 3:
                complement();
                break;
            
            case 4:
                cout << "\nEnter second binary number: \n";
                while(first2 != NULL){
                    node temp = first2;
                    first2 = first2->next;
                    delete temp;
                }
                first2 = NULL;
                
                int numBits;
                cout << "How many bits for second number? ";
                cin >> numBits;
                
                for(int i = 0; i < numBits; i++){
                    addbit(first2);
                }
                
                cout << "\nThe first number: ";
                display(first);
                cout << "\nThe second number: ";
                display(first2);
                
                addition();
                break;

            default: cout << "\nInvalid input.";
        }
    } while(c != 5);
}
// Doubly linked list to store binary number with 1's complement, 2's complement, and binary addition | Time: O(n) where n is number of bits