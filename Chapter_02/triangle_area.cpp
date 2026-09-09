// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the distance between two coordinates (x1, y1) and (x2, y2)
double calculateSide(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    // Prompt user to enter three coordinate pairs
    cout << "Enter three points for a triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the length of the three sides
    double side1 = calculateSide(x1, y1, x2, y2);
    double side2 = calculateSide(x2, y2, x3, y3);
    double side3 = calculateSide(x3, yS3, x1, y1);

    // Calculate semi-perimeter s
    double s = (side1 + side2 + side3) / 2.0;

    // Calculate triangle area using Heron's formula
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    // Display the resulting area
    cout << "The area of the triangle is " << area << endl;

    return 0;
}