#include <iostream>
#define MAX 10
using namespace std;

class TwoQueues {
    int arr[MAX];
    int f1, r1, f2, r2;
public:
    TwoQueues() { f1 = -1; r1 = -1; f2 = MAX; r2 = MAX; }

    void addQ1(int val) {
        if (r1 < r2 - 1) {
            if (f1 == -1) f1 = 0;
            arr[++r1] = val;
        } else cout << "Overflow\n";
    }

    void addQ2(int val) {
        if (r1 < r2 - 1) {
            if (f2 == MAX) f2 = MAX - 1;
            arr[--r2] = val;
        } else cout << "Overflow\n";
    }

    void delQ1() {
        if (f1 != -1 && f1 <= r1) {
            cout << "Deleted Q1: " << arr[f1++] << endl;
            if (f1 > r1) f1 = r1 = -1;
        } else cout << "Underflow\n";
    }

    void delQ2() {
        if (f2 != MAX && f2 >= r2) {
            cout << "Deleted Q2: " << arr[f2--] << endl;
            if (f2 < r2) f2 = r2 = MAX;
        } else cout << "Underflow\n";
    }

    void display() {
        cout << "Q1: "; for(int i=f1; i!=-1 && i<=r1; i++) cout << arr[i] << " "; cout << endl;
        cout << "Q2: "; for(int i=f2; i!=MAX && i>=r2; i--) cout << arr[i] << " "; cout << endl;
    }
};

int main() {
    TwoQueues tq;
    tq.addQ1(1); tq.addQ1(2);
    tq.addQ2(9); tq.addQ2(8);
    tq.display();
    tq.delQ1(); tq.delQ2();
    tq.display();
    return 0;
}
// Two queues in single array from opposite ends | Time: O(1)
