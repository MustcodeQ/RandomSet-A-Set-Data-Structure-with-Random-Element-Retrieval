# RandomSet: A Set Data Structure with Random Element Retrieval

RandomSet is a simple C implementation of a set data structure that stores unique integer values and provides functionality for random element retrieval. It allows users to insert elements into the set, remove elements, and retrieve random elements from the set.

## Features

- **Dynamic Array**: Utilizes a dynamic array to store unique integer values efficiently.
- **Insertion**: Allows insertion of elements into the set. Duplicates are automatically ignored.
- **Removal**: Supports removal of elements from the set.
- **Random Element Retrieval**: Provides functionality to retrieve a random element from the set.
- **Memory Management**: Proper memory management to avoid memory leaks.

## Usage

1. **Compilation**: Compile the source code using a C compiler such as GCC.
2. **Execution**: Run the compiled executable.
3. **Example Usage**:
#-#-#[c]
RandomSet *mySet = createSet();

insert(mySet, 5);
insert(mySet, 10);
insert(mySet, 15);
insert(mySet, 20);
insert(mySet, 25);

printSet(mySet);

removeValue(mySet, 15);

printSet(mySet);

int randomValue = getRandom(mySet);
printf("Random Value: %d\n", randomValue);

destroySet(mySet);
