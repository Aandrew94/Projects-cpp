#   Array Containter in STL

<br>

Arrays, as we all know, are collections of homogenous objects. 
Array containter in STL provides us the implementation of **static array**.

Syntax of array container:

`   std::array<object_type , array_size> array_name;  `

<br>

The above code creates an empty array of **object_type** with maximum size of **array_size**. However, if we want to create an array with elements in it, we can do by simply using the `=` operator (process called _copy assignment_ or just _assignment_) or using the `{}` (also called _uniform initialization_ form C++17):
```
#include    <array>
   
int main() {
    std::array<int , 4> odd_numbers = { 2, 4, 6, 8 };       //  copy initialization
    std::array<int , 5> even_number{ 1, 3, 5, 7, 9 };       //  uniform initialization 
    std::array<int , 3> zero_nr{};                          //  zero initialization for for all 3 variables
}
```
<br>

---

<br>

## Member Functions of Array Template

Following are the important and most used member functions of array template.

### `at` function
This method returns the value in the array at the given range. If the given range is greater than the array size, *out_of_range* exception is thrown.

```
#include    <iostream>
#include    <array>

int main(){
    std::array<int , 10> myarray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << myarray.at(2);         //  print   2
    std::cout << myarray.at(7);         //  print   7
    std::cout << myarray.at(12);        //  throwing an instance of 'std::out_of_range'
}
```

<br>

### `[]` operator
The use of operator `[]` is the same as it was for normal arrays. It returns the value at a given position in the array.

`std::cout << myarray[2];       //  print   2`

<br>

### `front()` function
This method returns the first element in the array.

<br>

### `back()` function
This method returns the last element in the array. Note that here, if the array is not completely filled, `back()` will return the rightmost element in the array.

<br>

### `fill()` function
This method assigns the given value to every element of the array.
```
#include    <array>

int main(){
    std::array<int , 8> myarray;
    myarray.fill(1);
}
```
This will fill the array with `1` value, at all of its `8` available positions.

<br>

### `swap` function
This method swaps the content of two arrays of the same type and same size.

It swaps index wise, thus the element of index **i** of the first array will be swapped with the element of the index **i** of the second array, and if swapping any of the two elements throws an exception, `swap()` throws exception.

```
#include    <iostream>
#include    <array>

int main(){
    std::array<int , 8> a = {1, 2, 3, 4, 5, 6, 7, 8};
    std::array<int , 8> b = {8, 7, 6, 5, 4, 3, 2, 1};
    
    a.swap(b)           // swaps array a and b
    
    std::cout << "a is : ";
    for(size_t i=0; i < a.size(); i++) {
        std::cout << a[i] <<" ";            //  print a: 8 7 6 5 4 3 2 1
    }

    std::cout << '\n';

    std::cout << "b is : ";
    for(size_t i=0; i < b.size(); i++) {
        std::cout << a[i] <<" ";            //  print b: 1 2 3 4 5 6 7 8 
    }
}
```
<br>

### `empty()` function
This method can be used to check whether the array is empty or not.
`array_name.empty();    //  returns true if array is empty or false if not`

<br>

### `size()` function
This method returns the number of elements present in the array.

<br>

### `max_size()` function
This method return the maximum size of array.

<br>

### `begin()` function
This method returns the iterator pointing to the first element of array. Iterators are just like pointers...
![](https://www.studytonight.com/cpp/stl/images/begin-end-array.png)

<br>

### `end()` function
This method returns an iterator pointing to an element next to the last element in the array, for example the above array has 4 elements and the end() call will return the iterator pointing to the 4th index of the array.

---

## Reference:
>   http://www.cplusplus.com/reference/array/