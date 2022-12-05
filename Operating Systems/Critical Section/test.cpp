#include <bits/stdc++.h>
using namespace std;


mutex f;


int res = 0;

void task() {
    f.lock();
    for (int i=0; i < 1000000; i++) res+=1;
    f.unlock();
}

int main() {
    thread t1(task);
    thread t2(task);
    
    t1.join();
    t2.join();

    cout << res << endl;

    return 0;
}