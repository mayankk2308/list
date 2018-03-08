# List in C++
This is a rather simple implementation of a generic linked list in **C++**. The primary motivations for developing this are to:
- Become familiar with C++ concepts such as templates and classes
- Become fluent in C++
- Highlight what kind of linked list implementation I like
- Share my implementation with others for critique

## Implementation
The `List` class is generic, and works with any **primitive** or **non-primitive** types. At the moment, it only has basic functionality and allows:
- Appending elements to the end of a List
- Appending elements to a given index in a list
- Removing elements from the List
- Removing elements from a given index in a list
- Merging lists
- Converting to an array
- Printing list to standard output

```cpp
// Append value to the end of the list
// Usage: list.append(5)
void List<T>::append(T value)

// Append value at position index of the list
// Usage: list.appendAt(6, 25)
void List<T>::appendAt(int index, T value)

// Remove first occurrence of value from the list
// Returns true if removal successful else false
// Usage: list.remove(5)
bool List<T>::remove(T value)

// Remove value at position index from the list
// Returns true if removal successful else false
// Usage: list.removeAt(4)
bool List<T>::removeAt(int index)

// Check the size of the list
// Returns the size of the list
// Usage: list.size()
long List<T>::size()

// Print the list
// Usage: list.print()
void List<T>::print()

// Fills array with elements in the list
// Usage: list.toArray(newArray)
void List<T>::toArray(T* array)

// Merge lists
// Usage: mergedList = list1 + list2
List<T> List<T>::operator +(List<T> otherList)
```

## License
This project is licensed under the MIT license. See the license file for more information.
