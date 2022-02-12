#include <bits/stdc++.h>
using namespace std;



// getting divisors of n in O(sqrt(n))
int get_divisors_of_n(int n) {
    int divisors = 0;
    for (int i = 1; i*i <= n; i++) { // O(sqrt(n))
        if (n % i == 0) {
            divisors++;

            if (i != n/i) divisors++;
        }
    }
    return divisors;
}


// getting divisors of numbers till n in O(n*sqrt(n))
vector<int> get_divisors_till_n(int n) {
    vector<int> divisors(n, 0);
    
    for (int i=1; i <= n; i++) { // O(n)
        divisors[i-1] = get_divisors_of_n(i); // O(sqrt(n))
    }

    return divisors;
}


// getting divisors of numbers till n in O(n*log(n))
vector<int> get_divisors_till_n_optimized(int n) {

    // Idea behind this is that we can calculate how many numbers i can devide and store that in an array.
    // Basically Iterating in multiples instead of divisors.
    // nlog(n) << n*sqrt(n)


    vector<int> divisors(n, 0);
    
    for (int i=1; i <= n; i++) { // O(n)
        for (int j=i; j <= n; j+=i) { // O(log(n))
            divisors[j-1]++;
        }
    }

    return divisors;
}


// getting prime numbers from 1 to n in O(n)
vector<int> get_prime_numbers_till_n(int n) {
    vector<int> prime_numbers(n, 0);
    
    for (int i=2; i <= n; i++) { // O(n)
        if (prime_numbers[i-1] == 0) {
            for (int j=i*i; j <= n; j+=i) { // O(sqrt(n))
                prime_numbers[j-1] = 1;
            }
        }
    }

    return prime_numbers;
}



int main() {
    int n;
    
    cin >> n;

    cout << get_divisors_of_n(n) << endl;
    
    
    vector<int> divisors = get_divisors_till_n(n);
    vector<int> divisors_optimised = get_divisors_till_n_optimized(n);

    // Proof that both are same
    for (int i=0; i < n; i++) {
        if (divisors[i] != divisors_optimised[i]) {
            cout << "Error" << endl;
            return 0;
        }
    }

    

    return 0;
}