#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

typedef struct SLL{
    int prn;
    char name[50];
    char desig[50];

    struct SLL *next;
}*node;

node first = NULL;
node first2 = NULL;

node accept(){
    node a = new SLL;
    cout << "\nEnter PRN: ";
    cin >> a->prn;
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(a->name, 50);
    strcpy(a->desig, "Member");
    a->next = NULL;
    return a;
}

void acceptmember(){
    node newnode = accept();
    
    if(first == NULL){
        strcpy(newnode->desig, "President");
        first = newnode;
    }
    else {
        node a = first;
        while (a->next != NULL){
            a = a->next;
        }
        a->next = newnode;
    }
}

void display(){
    int i = 1;
    node temp = first;
    cout << "\n----------------------------- VERTEX CLUB MEMBERS -------------------------------\n";
    cout << setw(5) << "S.NO" << setw(15) << "PRN" << setw(30) << "NAME" << setw(30) << "DESIGNATION" << endl;

    while(temp != NULL){
        if(temp->next == NULL){
            strcpy(temp->desig, "Secretary");
        }
        cout << setw(5) << i << setw(15) << temp->prn << setw(30) << temp->name << setw(30) << temp->desig << endl;
        temp = temp->next; 
        i++;
    }
}

void search(){
    int checkprn, counter=0;
    cout << "\nEnter PRN of member to search for: ";
    cin >> checkprn;

    node temp = first;
    while (temp->prn != checkprn && temp->next != NULL){
        temp = temp->next;
        counter++;
    }

    if(temp->prn == checkprn){
        cout << "\nMember found at position " << counter << "! Details: " << endl;
        cout << "PRN: " << temp->prn << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Designation: " << temp->desig << endl;
    }
    else{
        cout << "\nMember not in list.";
    }
}

void membercount(){
    int count = 0;

    node temp = first;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    cout << "\nNumber of members in the club: " << count;
}

void listconcat(){
    int choice = 1;

    cout << "\nCreating new list of members to be added.\nAdd members:\n";
    do{
        node newnode = accept();
    
        if(first2 == NULL){
            first2 = newnode;
        }
        else {
            node a = first2;
            while (a->next != NULL){
                a = a->next;
            }
            a->next = newnode;
        }

        cout << "\nWould you like to add another member? (enter 0 for no): ";
        cin >> choice;
    } while (choice == 1);

    cout << "\nDisplaying new members:";

    int i = 1;
    node temp = first2;
    cout << "\n--------------------------------- NEW MEMBERS -----------------------------------\n";
    cout << setw(5) << "S.NO" << setw(15) << "PRN" << setw(30) << "NAME" << setw(30) << "DESIGNATION" << endl;

    while(temp != NULL){
        cout << setw(5) << i << setw(15) << temp->prn << setw(30) << temp->name << setw(30) << temp->desig << endl;
        temp = temp->next; 
        i++;
    }

    if(first == NULL){
        first = first2;
    } 
    else if(first->next == NULL){
        first->next = first2;
    }
    else {
        node ogtemp = first;
        while(ogtemp->next->next != NULL){  // Stop at second last
            ogtemp = ogtemp->next;
        }

         node secretary = ogtemp->next;
        
        // Connect second last to new list
        ogtemp->next = first2;
        
        // Find end of new list and connect to Secretary
        node newListEnd = first2;
        while(newListEnd->next != NULL){
            newListEnd = newListEnd->next;
        }
        newListEnd->next = secretary;
    }

    first2 = NULL;

    cout << "\n\nConcatenation complete. Updated member list:";
    display();
}

void bubblesort(){
    int swapped;
    
    do{
        swapped = 0;
        node temp = first;
        node last = nullptr;

        while(temp->next != NULL){
            if(temp->prn > temp->next->prn){
                int x = temp->prn;
                temp->prn = temp->next->prn;
                temp->next->prn = x;

                swapped = 1;
            }

            temp = temp->next;
        }

        last = temp;
    } while(swapped != 0);

    display();
} 

void reverselist(){
    if(first == NULL){
        cout << "\nList is empty.\n";
        return;
    }
    
    if(first->next == NULL){
        cout << "\nOnly one member in the list! Already reversed.\n";
        return;
    }
    
    node prev = NULL;
    node current = first;
    node next = NULL;
    
    while(current != NULL){
        next = current->next;    
        current->next = prev;   
        prev = current;          
        current = next;          
    }
    
    first = prev;  
    
    cout << "\nMember list reversed successfully. Reversed member list:\n";
    int i = 1;
    node temp = first;
    cout << "\n----------------------------- VERTEX CLUB MEMBERS -------------------------------\n";
    cout << setw(5) << "S.NO" << setw(15) << "PRN" << setw(30) << "NAME" << setw(30) << "DESIGNATION" << endl;

    while(temp != NULL){
        cout << setw(5) << i << setw(15) << temp->prn << setw(30) << temp->name << setw(30) << temp->desig << endl;
        temp = temp->next; 
        i++;
    }
}

int main(){
    int c, cont=1;

        do{
            cout << "------- VERTEX CLUB MENU ------\n1. Add members\n2. Display members\n3. Search for member\n4. Display member count\n5. Add list of new members\n6. Sort members by PRN\n7. Reverse member list\n Your choice: ";
            cin >> c;

            switch(c){
                case 1: 
                    acceptmember();
                    break;
                
                case 2:
                    display();
                    break;

                case 3:
                    search();
                    break;

                case 4: 
                    membercount();
                    break;

                case 5:
                    listconcat();
                    break;

                case 6:
                    bubblesort();
                    break;

                case 7:
                    reverselist();
                    break;

                default: cout << "\nInvalid choice";
            }

            cout << "\nDo you want to perform another operation? (0 for no, 1 for yes): ";
            cin >> cont;
        } while (cont != 0);

    return 0;
}
// Singly linked list for Vertex Club with President/Secretary, operations: add, delete, count, display, concatenate, sort, reverse | Time: O(n) for most ops