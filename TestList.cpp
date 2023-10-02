#include <iostream>
#include "List.hpp" // Include the header file where your List class is defined

int main() {
    List<int> myList; // Create an instance of List<int>

    // Push some elements into the list
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // Print the list
    std::cout << "List elements: ";
    myList.printTheList();

    // Access front and back elements
    std::cout << "Front element: " << myList.front() << std::endl;
    std::cout << "Back element: " << myList.back() << std::endl;

    // Pop an element from the front and back
    myList.pop_front();
    myList.pop_back();

    // Print the modified list
    std::cout << "List elements after popping front and back: ";
    myList.printTheList();

    return 0;
}