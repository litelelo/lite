#include <iostream>
using namespace std;

void bubblesort(int marks[], int n){
    bool swapped;
    for (int pass = 0; pass < n; pass++)
    {
        swapped = false;
        cout<<"Pass"<<pass +1<<endl;
        for (int i = 0; i < n-pass-1; i++)
        {
            if (marks[i]<marks[i+1])
            {
                int temp = marks[i];
                marks[i] = marks[i+1];
                marks [i+1] = temp;
                swapped = true;
            }
            
        }

        cout<< "Marks order: "<<endl;
        for (int k = 0; k < n; k++)
        {
            cout<<marks[k]<<" ";
        }
        cout<<endl;
        
        if (!swapped)
        {
            break;
        }
        
    }
    

}

int main (){
    int marks[100];
    int n ;
    cout<<"Enter no of students: "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the marks of student "<<i<<": "<<endl;
        cin>>marks[i];
    }

    cout<<"Initial marks order: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Marks of student "<<i+1<<": ";
        cout<<marks[i];
        cout<<endl;
    }
    bubblesort(marks,n);
    cout<<"Final marks order: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Marks of Roll no "<<i+1<<": ";
        cout<<marks[i];
        cout<<endl;
    }


    

    return 0;
}
