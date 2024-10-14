#include <iostream>

int main() {
    
    int a, b, c;

    // Ask the user to input three integers
    std::cout << "Enter the first integer: ";
    std::cin >> a;

    std::cout << "Enter the second integer: ";
    std::cin >> b;

    std::cout << "Enter the third integer: ";
    std::cin >> c;

    // Create integer pointers using dynamic memory allocation
    int* ptr1 = new int;
    int* ptr2 = new int;
    int* ptr3 = new int;

    // Assign the values to the dynamically allocated memory
    *ptr1 = a;
    *ptr2 = b;
    *ptr3 =c;

    // Display the values of the variables and the pointers
    std::cout << "\nDisplaying the variables and pointers:\n";
    std::cout << "Value1: " << a << " (Pointer points to: " << *ptr1 << ")\n";
    std::cout << "Value2: " << b << " (Pointer points to: " << *ptr2 << ")\n";
    std::cout << "Value3: " << c << " (Pointer points to: " << *ptr3 << ")\n";

    // Deallocate the memory used by the pointers
    delete ptr1;
    delete ptr2;
    delete ptr3;

    // Set pointers to nullptr after deallocation (best practice)
    ptr1 = nullptr;
    ptr2 = nullptr;
    ptr3 = nullptr;

    return 0;
}

