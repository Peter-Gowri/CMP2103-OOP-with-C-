# C++ Take-Home Assignment: Inheritance and Polymorphism

| File | Topic |
|------|-------|
| `chained_inheritance.cpp` | Assignment 1: Chained (multilevel) inheritance |
| `polymorphism.cpp` | Assignment 2: Polymorphism |
| `Sketches_Inheritance_and_Polymorphism.pdf` | Illustrations for both programs (page 1 and page 2) |

Compile and run:

```
g++ -std=c++11 -Wall chained_inheritance.cpp -o chained && ./chained
g++ -std=c++11 -Wall polymorphism.cpp -o poly && ./poly
```

---

## 1. `chained_inheritance.cpp`

### What it demonstrates
Chained (multilevel) inheritance: a class inherits from a class that itself inherits from another class. The real-world example is vehicles:

```
Vehicle  ->  Car  ->  ElectricCar
```

### The classes

| Class | Role | Data members | Member functions |
|-------|------|--------------|------------------|
| `Vehicle` | Base (grandparent) | `brand`, `year` | `startEngine()`, `showVehicleInfo()` |
| `Car` | Derived from `Vehicle` (parent) | `doors` | `openDoors()`, `showCarInfo()` |
| `ElectricCar` | Derived from `Car` (child) | `batteryKWh` | `charge()`, `showElectricCarInfo()` |

### How it works
- `class Car : public Vehicle` and `class ElectricCar : public Car` form the chain.
- `brand`, `year` and `doors` are `protected`. Derived classes can use them, but code outside the classes cannot.
- Each constructor passes its values to its parent using an initializer list, e.g. `Car(...) : Vehicle(b, y)`. Construction runs top-down: `Vehicle`, then `Car`, then `ElectricCar`.
- `showCarInfo()` calls the inherited `showVehicleInfo()` and then prints its own data. `showElectricCarInfo()` does the same with `showCarInfo()`.

### What `main()` shows
1. A `Vehicle` object uses only its own members.
2. A `Car` object uses inherited `startEngine()` and its local `openDoors()`.
3. An `ElectricCar` object uses all three levels:
   - `startEngine()`, inherited from `Vehicle` (grandparent)
   - `openDoors()`, inherited from `Car` (parent)
   - `charge()`, defined in `ElectricCar` itself

### Sample output (ElectricCar part)
```
Brand: Tesla, Year: 2023
Doors: 4
Battery: 75 kWh
Tesla engine started.
Opening 4 doors.
Charging 75 kWh battery.
```

### Requirement checklist
- [x] At least three classes in an inheritance chain
- [x] Data members and member functions in each class
- [x] Derived class inherits from its parent
- [x] Objects use both inherited and locally defined members
- [x] Hand-drawn illustration: PDF page 1

---

## 2. `polymorphism.cpp`

### What it demonstrates
Runtime polymorphism ("many forms"). The same call, `describe()`, behaves differently depending on the actual type of the object. The real-world example is geometric shapes:

```
Shape (base)  ->  Circle
              ->  Rectangle
```

### The classes

| Class | Role | Data members | Overrides |
|-------|------|--------------|-----------|
| `Shape` | Base class | `name` | Declares `virtual area()` and `virtual describe()` |
| `Circle` | Derived | `radius` | `area()` = pi * r * r, `describe()` |
| `Rectangle` | Derived | `width`, `height` | `area()` = w * h, `describe()` |

### How it works
- The base class marks its functions `virtual`. This tells C++ to choose the version to run by the real object type while the program runs, not by the pointer type.
- The derived classes use `override`. The compiler then checks that they really override a base function.
- `virtual ~Shape()` is a virtual destructor. Without it, `delete` on a `Shape*` that points to a `Circle` would not clean up properly.

### What `main()` shows
1. **Base-class pointers:** `Shape* p1 = &c; p1->describe();` runs `Circle::describe()`. `p2` does the same for `Rectangle`.
2. **Base-class reference:** `printInfo(const Shape& s)` works for any shape.
3. **A collection of mixed shapes:** a `vector<Shape*>` holds circles and rectangles. One loop calls `describe()` and `area()` on each without checking its type.

### Sample output
```
Circle with radius 5, area = 78.5398
Rectangle 4 x 6, area = 24
```

### Why it matters
Code written against `Shape` keeps working when a new shape such as `Triangle` is added. The loop does not change, because the right `area()` is chosen automatically.

### Requirement checklist
- [x] Parent class with at least one virtual member function
- [x] At least two derived classes that override it
- [x] Runtime polymorphism through a base-class pointer and reference

---

## Inheritance vs. Polymorphism

| | Inheritance | Polymorphism |
|---|-------------|--------------|
| Idea | A class reuses members of another class | One call, different behaviour per object type |
| Keyword | `: public Base` | `virtual` and `override` |
| Benefit | Code reuse | Flexible, extensible code |
