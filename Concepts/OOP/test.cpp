#include <bits/stdc++.h>
using namespace std;


bool foo(int n){
  if(n > 20){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  bool b;
  b = foo(20);
  cout << b;
}