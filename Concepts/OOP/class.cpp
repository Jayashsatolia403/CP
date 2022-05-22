#include <bits/stdc++.h>
using namespace std;


class MyClass {
    string name;
    int age;
    string* gender;
    char grades[10];

    public:
    void setName(string x) {
        name = x;
    }

    string getName() {
        return name;
    }
};

int main() {

    MyClass c;

    string name;
    cin >> name;

    c.setName(name);

    cout << c.getName() << endl;

    return 0;
}