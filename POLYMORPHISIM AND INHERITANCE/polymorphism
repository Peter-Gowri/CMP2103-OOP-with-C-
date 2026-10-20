// Runtime polymorphism: Shape (base) -> Circle, Rectangle (derived)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const double PI = 3.14159265;

// Parent class with virtual member functions
class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual double area() const { return 0.0; }
    virtual void describe() const {
        cout << "I am a generic shape called " << name << ".\n";
    }
    virtual ~Shape() {}   // virtual destructor for safe deletion
};

// Derived class 1
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    double area() const override { return PI * radius * radius; }
    void describe() const override {
        cout << "Circle with radius " << radius
             << ", area = " << area() << "\n";
    }
};

// Derived class 2
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
    double area() const override { return width * height; }
    void describe() const override {
        cout << "Rectangle " << width << " x " << height
             << ", area = " << area() << "\n";
    }
};

// Works with ANY Shape through a reference
void printInfo(const Shape& s) {
    s.describe();
}

int main() {
    Circle c(5);
    Rectangle r(4, 6);

    // Base-class pointers calling overridden functions
    Shape* p1 = &c;
    Shape* p2 = &r;
    cout << "--- Via base-class pointers ---\n";
    p1->describe();   // calls Circle::describe at runtime
    p2->describe();   // calls Rectangle::describe at runtime

    // Base-class reference
    cout << "\n--- Via base-class reference ---\n";
    printInfo(c);
    printInfo(r);

    // Collection of different shapes handled uniformly
    cout << "\n--- Array of Shape pointers ---\n";
    vector<Shape*> shapes = { new Circle(2), new Rectangle(3, 7), new Circle(1.5) };
    double total = 0;
    for (Shape* s : shapes) {
        s->describe();
        total += s->area();
    }
    cout << "Total area: " << total << "\n";

    for (Shape* s : shapes) delete s;
    return 0;
}
