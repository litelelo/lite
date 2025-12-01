#include <iostream>
#include <iomanip>
using namespace std;

typedef struct SLL{
    int prn;
    char name[50];
    struct SLL *next;
} *node;

node firstA = NULL;
node firstB = NULL;
int totalStudents = 0;

node accept(){
    node a = new SLL;
    cout << "PRN: ";
    cin >> a->prn;
    cout << "Name: ";
    cin.ignore();
    cin.getline(a->name, 50);
    a->next = NULL;
    return a;
}

void addCricket(){
    node newnode = accept();

    if(firstA == NULL){
        firstA = newnode;
    }
    else{
        node a = firstA;
        while(a->next != NULL){
            a = a->next;
        }

        a->next = newnode;
    }
}

void addFootball(){
    node newnode = accept();

    if(firstB == NULL){
        firstB = newnode;
    }
    else{
        node b = firstB;
        while(b->next != NULL){
            b = b->next;
        }

        b->next = newnode;
    }
}

void displayCricket(){
    node temp = firstA;
    int i=1;

    cout << "\nStudents who play cricket (set A): \n";
    cout<< setw(5) << "S.NO" << setw(10) << "PRN" << setw(20) << "NAME" << endl;

    while(temp != NULL){
        cout << setw(5) << i << setw(10) << temp->prn << setw(20) << temp->name << endl;
        temp = temp->next;
        i++;
    }
}

void displayFootball(){
    node temp = firstB;
    int i=1;

    cout << "\nStudents who play football (set B): \n";
    cout<< setw(5) << "S.NO" << setw(10) << "PRN" << setw(20) << "NAME" << endl;

    while(temp != NULL){
        cout << setw(5) << i << setw(10) << temp->prn << setw(20) << temp->name << endl;
        temp = temp->next;
        i++;
    }
}

// Function to check if a student exists in a list by PRN
bool isStudentInList(node head, int prn) {
    node temp = head;
    while (temp != NULL) {
        if (temp->prn == prn) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void displayBothSports() {
    node temp = firstA;
    int count = 0;
    
    cout << "\nStudents who like BOTH Cricket AND Football:\n";
    cout << setw(5) << "S.NO" << setw(10) << "PRN" << setw(20) << "NAME" << endl;
    cout << "--------------------------------------------\n";
    
    while (temp != NULL) {
        if (isStudentInList(firstB, temp->prn)) {
            count++;
            cout << setw(5) << count << setw(10) << temp->prn << setw(20) << temp->name << endl;
        }
        temp = temp->next;
    }
    
    if (count == 0) {
        cout << "No students like both Cricket and Football.\n";
    } else {
        cout << "Total students who like both sports: " << count << endl;
    }
}

void displayEitherButNotBoth() {
    int count = 0;
    
    cout << "\nStudents who like EITHER Cricket OR Football but NOT both:\n";
    cout << setw(5) << "S.NO" << setw(10) << "PRN" << setw(20) << "NAME" << setw(15) << "SPORT" << endl;
    cout << "--------------------------------------------------------------\n";
    
    node temp = firstA;
    while (temp != NULL) {
        if (!isStudentInList(firstB, temp->prn)) {
            count++;
            cout << setw(5) << count << setw(10) << temp->prn << setw(20) << temp->name << setw(15) << "Cricket Only" << endl;
        }
        temp = temp->next;
    }
    
    temp = firstB;
    while (temp != NULL) {
        if (!isStudentInList(firstA, temp->prn)) {
            count++;
            cout << setw(5) << count << setw(10) << temp->prn << setw(20) << temp->name << setw(15) << "Football Only" << endl;
        }
        temp = temp->next;
    }
    
    if (count == 0) {
        cout << "No students like only one sport.\n";
    } else {
        cout << "Total students who like either but not both: " << count << endl;
    }
}

void displayNeither() {
    cout << "\nStudents who like NEITHER Cricket NOR Football:\n";
    
    int totalCricket = 0, totalFootball = 0, totalBoth = 0;
    
    node temp = firstA;
    while (temp != NULL) {
        totalCricket++;
        temp = temp->next;
    }
    
    temp = firstB;
    while (temp != NULL) {
        totalFootball++;
        temp = temp->next;
    }
    
    temp = firstA;
    while (temp != NULL) {
        if (isStudentInList(firstB, temp->prn)) {
            totalBoth++;
        }
        temp = temp->next;
    }
    
    int totalUnique = totalCricket + totalFootball - totalBoth;
    int neither = totalStudents - totalUnique;
    
    cout << "Students who play Cricket: " << totalCricket << endl;
    cout << "Students who play Football: " << totalFootball << endl;
    cout << "Students who play both: " << totalBoth << endl;
    cout << "Total unique students who play at least one sport: " << totalUnique << endl;
    cout << "Students who like NEITHER Cricket NOR Football: " << neither << endl;
}

int main(){
    int c1 = 0, c2 = 0, choice;

    cout << "=== CRICKET AND FOOTBALL STUDENT MANAGEMENT SYSTEM ===\n";
    
    cout << "Enter total number of students in class: ";
    cin >> totalStudents;
    
    cout << "\nEnter details of students who play cricket: \n";
    do{
        addCricket();
        cout << "\nWould you like to add another student? (Enter 0 to quit, 1 to continue): ";
        cin >> c1;
    } while (c1!=0);

    cout << "\nEnter details of students who play football: \n";
    do{
        addFootball();
        cout << "\nWould you like to add another student? (Enter 0 to quit, 1 to continue): ";
        cin >> c2;
    } while (c2!=0);

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Display Cricket players\n";
        cout << "2. Display Football players\n";
        cout << "3. Display students who like BOTH Cricket AND Football\n";
        cout << "4. Display students who like EITHER Cricket OR Football but NOT both\n";
        cout << "5. Display number of students who like NEITHER Cricket NOR Football\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayCricket();
                break;
                
            case 2:
                displayFootball();
                break;
                
            case 3:
                displayBothSports();
                break;
                
            case 4:
                displayEitherButNotBoth();
                break;
                
            case 5:
                displayNeither();
                break;
                
            case 6:
                cout << "\nThank you for using the Cricket-Football Management System!\n";
                break;
                
            default:
                cout << "\nInvalid choice! Please try again.\n";
                break;
        }
        
    } while (choice != 6);

    return 0;
}
// Singly linked lists for set operations (union, intersection, difference) on Cricket and Football student sets | Time: O(n×m) for set operations