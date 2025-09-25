#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned, unsigned = 1);
unsigned fib(unsigned, unsigned = 1, unsigned = 0, unsigned = 1);
unsigned mult(unsigned, unsigned, unsigned = 0);
unsigned power(unsigned, unsigned, unsigned = 1);
unsigned product(unsigned, unsigned, unsigned = 1);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

// Old Implementation
// unsigned fact(unsigned n) {
//     // base cases (combined)
//     if (n <= 1) {
//         return 1;
//     }

//     // recursive case
//     unsigned res = fact(n - 1);
//     return res * n;
// }

// Tail recursive implementation
unsigned fact(unsigned n, unsigned i) {
    // base cases (combined)
    if (n <= 1) {
        return i;
    }

    // recursive case
    return fact(n-1, n * i);
}

// fact(4) 
// = fact(3) * 4
// = (fact(2) * 3) * 4
// = ((fact(1) * 2) * 3) * 4
// = (1 * 2 * 3 * 4)
// = 24

// unsigned fib(unsigned n) {
//     // base case 1
//     if (n == 0) {
//         return 0;
//     }

//     // base case 2
//     else if (n == 1) {
//         return 1;
//     }

//     // recursive case
//     return fib(n - 1) + fib(n - 2);
// }

unsigned fib(unsigned n, unsigned curr_index, unsigned prev_value, unsigned curr_value) {
    // base case 1
    if (curr_index == n) {
        return curr_value;
    }

    // recursive case
    return fib(n, curr_index + 1, curr_value, prev_value + curr_value);
}

// Old Implementation
// unsigned mult(unsigned x, unsigned y) {
//     // base case
//     if (y == 0) {
//         return 0;
//     }

//     // recursive case
//     unsigned res = mult(x, y - 1);
//     return res + x;
// }

// Tail Recursive Implementation
unsigned mult(unsigned x, unsigned y, unsigned i) {
    // base case
    if (y == 0) {
        return i;
    }

    // recursive case
    return mult(x, y - 1, i + x);
}

// mult(3, 2)
// 2 != 0, res = mult(3, 1) --> 3 + 3 = 6
// 1 != 0, res = mult(3, 0) --> 0 + 3 = 3
// 0 == 0, returns 0

// Old Implementation
// unsigned power(unsigned x, unsigned y) {
//     // base case
//     if (y == 0) {
//         return 1;
//     }

//     // recursive case
//     unsigned res = power(x, y - 1);
//     return res * x;
// }

// Tail Recursive Implementation
unsigned power(unsigned x, unsigned y, unsigned i) {
    // base case
    if (y == 0) {
        return i;
    }

    // recursive case
   return power(x, y - 1, i * x);
}

// Old Implementation
// unsigned product(unsigned x, unsigned y) {
//     // base case
//     if (x == y) {
//         return x;
//     }

//     // recursive case
//     unsigned p = product(x + 1, y);
//     return p * x;
// }

// product(2, 4,)
//  2 != 4, p = product(3, 4)
//  3 != 4, p = product(4, 4), 4 * 3 
//  4 == 4, return 4

// Tail Recursive Implementation
unsigned product(unsigned x, unsigned y, unsigned i) {
    // base case
    if (x > y) {
        return i;
    }

    return product(x + 1, y, i * x);
}
