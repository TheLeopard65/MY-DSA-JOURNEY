# Stack in Data Structures & Algorithms (DSA)

### **Definition of Stack**

A **Stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle, meaning that the last element added to the stack will be the first one to be removed. Think of a stack as a collection of items placed one on top of another, such as a stack of plates. You can only add or remove elements from the top of the stack.

### **Stack Operations**

The fundamental operations that can be performed on a stack include:

- **Push**: Adding an element to the top of the stack.
- **Pop**: Removing the element from the top of the stack.
- **Peek/Top**: Accessing the top element without removing it.
- **isEmpty**: Checking if the stack is empty.
- **isFull**: Checking if the stack is full (in case of a fixed-size stack).

### **Advantages of Stack**

1. **Simple and Efficient**: The stack provides a simple mechanism for storing and retrieving data.
2. **Memory Efficiency**: As stacks only deal with the last element added, they can be efficient in managing memory for some specific applications.
3. **Easy Implementation**: Stacks are easy to implement using arrays or linked lists in programming languages like C++.
4. **Supports Recursion**: The function call stack is a common implementation of the stack in many programming languages, which enables recursion.

### **Disadvantages of Stack**

1. **Limited Access**: Stacks restrict access to the elements stored in them. You can only access the top element, making it less flexible compared to other data structures.
2. **Fixed Size (in some implementations)**: When using arrays to implement stacks, the size of the stack is fixed, which could result in overflow if the stack is full.
3. **Not Suitable for Searching**: Searching through the stack for a specific element is not efficient, as you can only access the top element at a time.

### **Types of Stack**

There are two primary types of stacks based on their implementation:

1. **Array-based Stack**:
   - Uses a fixed-size array to store the elements.
   - Requires additional management to prevent overflow or underflow.

2. **Linked List-based Stack**:
   - Uses a linked list where each node contains an element and a reference to the next node.
   - Dynamic size, so no overflow or underflow happens unless the system runs out of memory.

### **Time Complexity of Stack Operations**

| Operation        | Time Complexity |
|------------------|-----------------|
| Push             | O(1)            |
| Pop              | O(1)            |
| Peek/Top         | O(1)            |
| isEmpty          | O(1)            |
| isFull (Array)   | O(1)            |
| Search (Linked)  | O(n)            |

- **Push** and **Pop** are O(1) because we can add or remove elements at the top of the stack in constant time.
- **Peek/Top** also runs in O(1) time because accessing the top element does not require any traversal.
- **Search** is O(n) because you would need to traverse all the elements to search for a specific one (not efficient).

### **Applications of Stack**

Stacks are widely used in various real-world applications, some of which are listed below:

1. **Function Call Stack (Recursion)**: When a function is called, its local variables and the return address are pushed onto the stack. When the function returns, the stack is popped to retrieve the address to return to, and the local variables are discarded.

2. **Expression Evaluation**: Stacks are used to evaluate expressions, particularly in **postfix** and **prefix** notation. Converting from infix to postfix and evaluating postfix expressions relies heavily on stacks.

3. **Undo Mechanism**: Many software applications use a stack to store user actions (like a sequence of changes made to a document). Each time an action is made, it is pushed onto the stack, and when the user clicks undo, the last action is popped.

4. **Browser History**: The **back** button of a web browser is implemented using a stack to keep track of the URLs visited. When you press back, the last URL is popped from the stack.

5. **Depth-First Search (DFS) in Graphs**: In graph traversal, DFS uses a stack to keep track of the nodes to be explored.

6. **Expression Conversion**: Converting infix expressions (e.g., `(A + B) * (C + D)`) into postfix (e.g., `AB+CD+*`) or prefix notation (e.g., `*+AB+CD`) can be efficiently done using a stack.

### **Use Cases of Stack**

1. **Balancing Parentheses**: A stack can be used to check whether a given expression has balanced parentheses (or brackets or braces). Push opening symbols onto the stack and pop when you encounter a matching closing symbol.

2. **Reverse a String**: By pushing each character of a string onto a stack and then popping them off, we can reverse the string.

3. **Postfix Expression Evaluation**: A stack is used for evaluating postfix expressions (also known as Reverse Polish Notation). Each time an operator is encountered, operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.

### **Stack Operations in Detail**

1. **Push (Inserting an Element)**:
   - **Definition**: The push operation adds an element to the top of the stack.
   - **Time Complexity**: O(1)
   - **Use Case**: Pushing an element in an expression evaluation, pushing a function call onto the stack.

2. **Pop (Deleting an Element)**:
   - **Definition**: The pop operation removes the element from the top of the stack and returns it.
   - **Time Complexity**: O(1)
   - **Use Case**: Popping an element to undo an action or to process elements from a data structure like DFS.

3. **Peek/Top (Searching the Top Element)**:
   - **Definition**: The peek operation returns the top element of the stack without removing it.
   - **Time Complexity**: O(1)
   - **Use Case**: In infix-to-postfix conversion, the operator precedence is checked using the top element of the stack.

4. **isEmpty (Checking if the Stack is Empty)**:
   - **Definition**: This operation checks whether the stack is empty.
   - **Time Complexity**: O(1)
   - **Use Case**: Checking if there are any elements to pop from the stack before performing operations.

5. **isFull (Checking if the Stack is Full)**:
   - **Definition**: This operation checks whether the stack has reached its maximum capacity (only applicable to array-based stacks).
   - **Time Complexity**: O(1)
   - **Use Case**: Ensuring that no overflow occurs in a fixed-size stack.

6. **Search (Searching an Element)**:
   - **Definition**: This operation searches for a specific element in the stack.
   - **Time Complexity**: O(n)
   - **Use Case**: Searching for an element in a stack (although this operation is generally inefficient).

7. **Sorting (Sorting Stack Elements)**:
   - **Definition**: Sorting involves arranging the elements of the stack in a specific order (e.g., ascending or descending).
   - **Time Complexity**: O(n^2) for simple sorting algorithms, but optimized sorting algorithms can perform better.

8. **Reversing a Stack**:
   - **Definition**: Reversing the stack involves changing the order of elements so that the first element becomes the last, and the last becomes the first.
   - **Time Complexity**: O(n)
   - **Use Case**: Reversing a stack can be useful when processing elements in the opposite order.

9. **Counting (Counting the Number of Elements in the Stack)**:
   - **Definition**: Counting involves counting how many elements are in the stack.
   - **Time Complexity**: O(n) since we need to traverse the entire stack.

10. **Traversing a Stack**:
    - **Definition**: Traversing the stack involves accessing all elements in the stack, often for displaying or processing them.
    - **Time Complexity**: O(n)
    - **Use Case**: Iterating through a stack to print or process all its elements.

### **Conclusion**

Stacks are an essential part of computer science and are used in various real-world scenarios. They provide an efficient and straightforward way of organizing data where only the most recently added element is accessible. Understanding stack operations and their applications is crucial for many algorithmic problems like parsing expressions, managing function calls, and implementing undo operations in software.
