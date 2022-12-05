#include <bits/stdc++.h>
using namespace std;



void taskA() {
    for (int i=1; i < 8000000; i++) {
        sleep(1);
        cout << "Task A : " << i << endl;
        fflush(stdout);
    }
}



void taskB() {
    for (int i=0; i < 100000; i++) {
        sleep(1);
        cout << "Task B : " << i << endl;
        fflush(stdout);
    }
}


int main() {
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();

    return 0;
}