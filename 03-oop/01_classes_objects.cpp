/**
 * C++ OOP: Classes and Objects
 *
 * Object-oriented programming fundamentals for clean code design.
 *
 * Compile: g++ -std=c++17 -o 01_classes 01_classes_objects.cpp
 * Run: ./01_classes
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================
// BASIC CLASS DEFINITION
// ============================================

class Rectangle {
private:
    // Private members - only accessible within the class
    double width;
    double height;

public:
    // Constructor - called when object is created
    Rectangle(double w, double h) {
        width = w;
        height = h;
        cout << "Rectangle created: " << width << " x " << height << endl;
    }

    // Default constructor
    Rectangle() : width(0), height(0) {
        cout << "Default Rectangle created" << endl;
    }

    // Destructor - called when object is destroyed
    ~Rectangle() {
        cout << "Rectangle destroyed: " << width << " x " << height << endl;
    }

    // Member functions (methods)
    double area() const {  // const = doesn't modify object
        return width * height;
    }

    double perimeter() const {
        return 2 * (width + height);
    }

    // Getters
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    // Setters
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

    // Static member function (no object needed)
    static void describe() {
        cout << "I am a Rectangle class" << endl;
    }
};

// ============================================
// CLASS WITH INITIALIZER LIST
// ============================================

class Point {
private:
    int x, y;
    const int id;  // const members must be initialized in initializer list

public:
    // Initializer list - preferred way to initialize members
    Point(int x, int y, int id) : x(x), y(y), id(id) {}

    // Default values in initializer list
    Point() : x(0), y(0), id(0) {}

    void print() const {
        cout << "Point(" << x << ", " << y << ") id=" << id << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

// ============================================
// INHERITANCE
// ============================================

// Base class
class Shape {
protected:
    string name;
    string color;

public:
    Shape(const string& name, const string& color = "white")
        : name(name), color(color) {}

    virtual ~Shape() {  // Virtual destructor for proper cleanup
        cout << "Shape " << name << " destroyed" << endl;
    }

    virtual double area() const = 0;  // Pure virtual - makes this abstract

    virtual void describe() const {
        cout << "A " << color << " " << name;
    }

    string getName() const { return name; }
};

// Derived class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, const string& color = "white")
        : Shape("Circle", color), radius(r) {}

    double area() const override {  // override keyword (C++11)
        return 3.14159 * radius * radius;
    }

    void describe() const override {
        Shape::describe();  // Call base class method
        cout << " with radius " << radius << endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s, const string& color = "white")
        : Shape("Square", color), side(s) {}

    double area() const override {
        return side * side;
    }

    void describe() const override {
        Shape::describe();
        cout << " with side " << side << endl;
    }
};

// ============================================
// OPERATOR OVERLOADING
// ============================================

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Operator overloading
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    // Compound assignment
    Vector2D& operator+=(const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Stream output operator (friend function)
    friend ostream& operator<<(ostream& os, const Vector2D& v);

    double getX() const { return x; }
    double getY() const { return y; }
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// ============================================
// USEFUL PATTERN: LINKED LIST NODE CLASS
// ============================================

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

// Helper to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to delete linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================
// USEFUL PATTERN: TREE NODE CLASS
// ============================================

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// ============================================
// MAIN
// ============================================

int main() {
    cout << "=== Classes and Objects ===" << endl << endl;

    // Basic class usage
    cout << "--- Basic Class ---" << endl;
    {
        Rectangle rect(5, 3);
        cout << "Area: " << rect.area() << endl;
        cout << "Perimeter: " << rect.perimeter() << endl;

        Rectangle::describe();  // Static method call

    }  // rect destroyed here (RAII)

    cout << endl;

    // Initializer list
    cout << "--- Initializer List ---" << endl;
    Point p1(3, 4, 1);
    Point p2;
    p1.print();
    p2.print();

    // Inheritance and polymorphism
    cout << "\n--- Inheritance ---" << endl;
    Circle circle(5, "red");
    Square square(4, "blue");

    circle.describe();
    cout << "Area: " << circle.area() << endl;

    square.describe();
    cout << "Area: " << square.area() << endl;

    // Polymorphism with pointers
    cout << "\n--- Polymorphism ---" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Circle(3, "green"));
    shapes.push_back(new Square(2, "yellow"));

    for (Shape* s : shapes) {
        s->describe();
        cout << "Area: " << s->area() << endl;
    }

    // Clean up
    for (Shape* s : shapes) {
        delete s;
    }

    // Operator overloading
    cout << "\n--- Operator Overloading ---" << endl;
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2 = " << (v1 * 2) << endl;
    cout << "v1 == v2: " << (v1 == v2) << endl;

    // Linked list class usage
    cout << "\n--- Linked List Node ---" << endl;
    ListNode* head = createList({1, 2, 3, 4, 5});
    cout << "List: ";
    printList(head);
    deleteList(head);

    // ============================================
    // EXERCISES
    // ============================================

    cout << "\n=== Exercises ===" << endl;

    /**
     * Exercise 1: Create a Stack class using an array
     * - push(int)
     * - pop() returns int
     * - top() returns top element
     * - isEmpty() returns bool
     * - size() returns int
     */

    // YOUR CODE HERE


    /**
     * Exercise 2: Create a Fraction class with operator overloading
     * - Support +, -, *, /
     * - Support ==, <, >
     * - Auto-reduce fractions (use GCD)
     */

    // YOUR CODE HERE


    /**
     * Exercise 3: Implement a Binary Search Tree class
     * - insert(int)
     * - search(int) returns bool
     * - inorderTraversal() prints values
     */

    // YOUR CODE HERE


    /**
     * Exercise 4: Create a Graph class using adjacency list
     * - addVertex(int)
     * - addEdge(int from, int to)
     * - printGraph()
     */

    // YOUR CODE HERE

    return 0;
}
