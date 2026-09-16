#include <iostream>
#include <string>

using namespace std;

// Function declarations
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    cout << "Enter a credit card number as a long long integer: ";
    cin >> cardNumber;

    if (isValid(cardNumber)) {
        cout << cardNumber << " is valid." << endl;
    } else {
        cout << cardNumber << " is invalid." << endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);
    if (size < 13 || size > 16) {
        return false;
    }

    bool matchPrefix = prefixMatched(number, 4) || 
                       prefixMatched(number, 5) || 
                       prefixMatched(number, 37) || 
                       prefixMatched(number, 6);

    if (!matchPrefix) {
        return false;
    }

    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    string numStr = to_string(number);
    int len = numStr.length();
    
    // Double every second digit from right to left
    for (int i = len - 2; i >= 0; i -= 2) {
        int digit = numStr[i] - '0';
        sum += getDigit(digit * 2);
    }
    
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number
int sumOfOddPlace(long long number) {
    int sum = 0;
    string numStr = to_string(number);
    int len = numStr.length();
    
    // Add all digits in the odd places from right to left
    for (int i = len - 1; i >= 0; i -= 2) {
        sum += numStr[i] - '0';
    }
    
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    return getPrefix(number, getSize(d)) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    string str = to_string(d);
    return str.length();
}

// Return the first k number of digits from number. If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    string numStr = to_string(number);
    if (numStr.length() <= k) {
        return number;
    }
    string prefixStr = numStr.substr(0, k);
    return stoll(prefixStr);
}