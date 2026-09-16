// Write a program that prompts the user to enter three integer values, and
// then outputs the values in numerical sequence separated by commas.
// So, if the user enters the values 10 4 6, the output should be 4, 6, 10.
// If two values are the same, they should just be ordered together. So, the input 4 5 4 should give 4, 4, 5.


#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    // Prompt the user to enter three integer values
    cout << "Enter three integer values (separated by spaces): ";
    if (!(cin >> a >> b >> c)) {
        cerr << "Invalid input. Please enter integers only." << endl;
        return 1;
    }

    // Sort the values using a small sorting network (swapping values)
    // Ensure 'a' holds the smallest value, and 'c' holds the largest
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    // Re-check a and b because the previous swap might have put a smaller value in b
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Output the values in numerical sequence separated by commas
    cout << a << ", " << b << ", " << c << std::endl;

    return 0;
}