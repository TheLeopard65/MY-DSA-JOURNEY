### **Hash Map / Hash Table in Data Structures**

A **Hash Map** (or **Hash Table**) is a data structure that stores key-value pairs for efficient lookup, insertion, and deletion. It uses a hash function to compute an index (hash value) into an array, from which the desired value can be found. It is known for its average **O(1)** time complexity for lookups, insertions, and deletions, which makes it highly efficient.

---

### **Definitions**

- **Hash Map / Hash Table**: A data structure that maps keys to values using a hash function. The hash function generates a hash value (an index) for each key, which is then used to store the value in an array.
  
- **Key**: A unique identifier for accessing data.
  
- **Value**: The data associated with a key.

- **Hash Function**: A function that takes a key and computes an index (hash value), which is used to place the value in the hash table.

---

### **Advantages of Hash Maps**

1. **Constant Time Complexity for Search**: Hash maps provide **O(1)** average time complexity for searching, inserting, and deleting elements, assuming a good hash function and proper collision handling.
   
2. **Efficient Storage**: Keys and values are stored in an array-like structure, making access very efficient compared to other data structures like linked lists.

3. **Flexibility**: Supports various data types as keys and values, allowing for versatile use cases.

4. **Fast Lookups**: With a good hash function, hash maps can perform fast lookups in constant time.

---

### **Disadvantages of Hash Maps**

1. **Memory Consumption**: Due to the underlying array structure, hash maps can consume a lot of memory, especially when the load factor is high.
   
2. **Collisions**: Two distinct keys might hash to the same index (collision), which requires handling mechanisms, adding some overhead.
   
3. **Non-Ordered**: Hash maps do not maintain any order of elements, unlike data structures such as trees or linked lists.

4. **Poor Performance with High Load Factor**: If the hash table becomes too full, the performance degrades, and a resize (rehashing) is required.

---

### **Time Complexity**

| Operation           | Average Time Complexity | Worst Case Time Complexity |
|---------------------|-------------------------|----------------------------|
| **Search**          | **O(1)**                | **O(n)**                   |
| **Insert**          | **O(1)**                | **O(n)**                   |
| **Delete**          | **O(1)**                | **O(n)**                   |
| **Resize (Rehash)** | **O(n)**                | **O(n)**                   |

**Note**: The average-case time complexity is O(1) for search, insertion, and deletion, assuming a good hash function and low collision rate. In the worst case (due to collisions), these operations could degrade to O(n), where n is the number of elements in the table.

---

### **Types of Hash Tables**

1. **Static Hash Tables**:
   - Size is fixed when created.
   - Insertion of elements beyond the initial size may require resizing.

2. **Dynamic Hash Tables**:
   - Size grows dynamically as elements are added.
   - Resizing is done by rehashing when the load factor exceeds a threshold.

3. **Open Addressing Hash Table**:
   - Handles collisions by finding another location within the table.
   - Techniques include **Linear Probing**, **Quadratic Probing**, and **Double Hashing**.

4. **Separate Chaining**:
   - Each slot of the hash table holds a linked list or another data structure.
   - Colliding elements are stored in these lists.

---

### **Basic Operations in Hash Map**

1. **Insert (Put)**:
   - Compute the hash for the key and store the value at the index.
   - If the key already exists, the value is updated.
   
2. **Search (Get)**:
   - Compute the hash for the key and retrieve the corresponding value from the table.
   - If the key is not present, return **null** or a sentinel value.

3. **Delete (Remove)**:
   - Compute the hash for the key and remove the key-value pair.
   
4. **Resize (Rehash)**:
   - When the load factor becomes high (too many elements in the table), the table is resized, and all the elements are rehashed to new positions.

---

### **Collision in Hash Maps**

A **collision** occurs when two distinct keys hash to the same index in the hash table. Since hash tables rely on the index to store values, this can lead to problems where multiple keys attempt to occupy the same index.

#### **Types of Collisions**:

- **Primary Collision**: Two keys hash to the same index.
- **Secondary Collision**: A collision happens after open addressing is used to resolve a previous collision.

---

### **Handling Collisions**

There are two main techniques to handle collisions in hash tables:

#### 1. **Separate Chaining** (Linked List)
   - **Idea**: Each array index stores a linked list (or other structure) of values that hash to the same index.
   - **Advantages**:
     - Easy to implement.
     - Can handle a large number of collisions gracefully.
   - **Disadvantages**:
     - More memory usage because of the extra linked list.
     - Performance can degrade to **O(n)** if many keys collide at the same index.

#### 2. **Open Addressing** (All elements are stored within the array itself, without linked lists)

- **Linear Probing**:
   - **Idea**: If a collision occurs, check the next slot, then the next, and so on (linearly) until an empty slot is found.
   - **Advantages**:
     - Simple to implement.
   - **Disadvantages**:
     - **Clustering**: A group of adjacent elements may form, leading to increased search time.
     - Degrades when the table is nearly full.

- **Quadratic Probing**:
   - **Idea**: Instead of checking the next slot linearly, check slots at increasing distances (1, 4, 9, 16, etc.) from the original index.
   - **Advantages**:
     - Reduces clustering compared to linear probing.
   - **Disadvantages**:
     - Still prone to clustering, though less than linear probing.
     - Needs to ensure that every slot is probed in the table.

- **Double Hashing**:
   - **Idea**: Uses a second hash function to compute the step size for probing.
   - **Advantages**:
     - Better than linear and quadratic probing in terms of spreading out the collisions.
   - **Disadvantages**:
     - More complex because two hash functions are involved.
     - Needs to handle the possibility of infinite loops.

- **Rehashing**:
   - **Idea**: When the load factor (number of elements / size of the table) becomes too high, the table is resized and all elements are rehashed.
   - **Advantages**:
     - Reduces collisions by increasing the size of the hash table.
   - **Disadvantages**:
     - Rehashing can be time-consuming (O(n) time complexity).

---

### **Applications and Use Cases**

1. **Databases**:
   - **Hash Maps** are used in databases for quick lookups of data based on keys (e.g., indexing).

2. **Caching**:
   - **Caching Systems** (like Memcached) use hash maps to store recently accessed data for fast retrieval.

3. **Symbol Tables**:
   - **Compilers** use hash maps to store variable names (symbols) and their corresponding information.

4. **Counting Frequencies**:
   - **Word count** problems, where a hash map is used to store the frequency of each word in a document.

5. **Unique Data Storage**:
   - Storing a collection of unique elements where the key is the element and the value is true.

---

### **Conclusion**

Hash Maps are a powerful tool in data structures, offering fast search, insert, and delete operations. They are extremely useful in real-time applications requiring quick data retrieval, though they require proper collision handling and efficient resizing mechanisms. By understanding how hash maps work and how to handle collisions effectively, one can implement a high-performance key-value storage system.

