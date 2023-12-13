#include <iostream>
#include <stack>

// Function to insert an element at the correct position in a sorted stack
void insertAtCorrectPosition(std::stack<int>& sortedStack, int element) {
    if (sortedStack.empty() || element >= sortedStack.top()) {
        sortedStack.push(element);
        return;
    }

    int topElement = sortedStack.top();
    sortedStack.pop();
    insertAtCorrectPosition(sortedStack, element);
    sortedStack.push(topElement);
}

// Function to sort the stack in descending order
void sortStackDescending(std::stack<int>& inputStack) {
    if (inputStack.empty()) {
        return;
    }

    int temp = inputStack.top();
    inputStack.pop();
    
    sortStackDescending(inputStack);
    insertAtCorrectPosition(inputStack, temp);
}

int main() {
    std::stack<int> inputStack;

    // Push elements into the stack
    inputStack.push(34);
    inputStack.push(3);
    inputStack.push(31);
    inputStack.push(98);
    inputStack.push(92);
    inputStack.push(23);

    std::cout << "Stack before sorting:" << std::endl;
    std::stack<int> tempStack = inputStack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }

    sortStackDescending(inputStack);

    std::cout << "\nStack after sorting in descending order:" << std::endl;
    while (!inputStack.empty()) {
        std::cout << inputStack.top() << " ";
        inputStack.pop();
    }

    return 0;
}