#   Vector Containter in STL

<br>

An **array** works fine when we have to implement sequential data structures like arrays, except it is static, i.e. we have to define its maximum size during its initialization and it cannot contain elements greater than its maximum size. Now suppose, if during the program execution we have to store elements more than its size, or if we are reading input stream of elements and we do not know the upper bound of the number of elements, there are high chances of occurrence of **index_out_bound** exception or unwanted termination of the program.

We can do one thing, initialize the array with maximum size allowed by the complier, i.e. `10^6` elements per array, but that is highly space consuming approach and there is a wastage of space if number of elements to be entered are way too less, thus this approach is never used in programming.

---

Solution of the above problem is **dynamic arrays**! 

They have dynamic size, i.e. their size can change during runtime. Container library provides vectors to replicate dynamic arrays.

Vector being a dynamic array, doesn't needs size during declaration

---


Syntax for creating a vector is:

`   std::vector< object_type > vector_name;  `

<br>

For example:
```
#include    <vector>

int main() {
    std::vector<int> my_vector;                     //  will create a blank vector
    std::vector<string> vect {"Pankaj", "The", "Java"};
    std::vector<string> new_vector (4, "test")      //  will create a vector with 4 elements of type string and value 'test'
}
```
![](https://www.studytonight.com/cpp/images/vector-declaration.png)
![](https://www.studytonight.com/cpp/images/inserting-data-vector.png)

<br>

---

<br>

## Member Functions of Vector

Following are some of the most commonly used functions for vector container in STL:

### `push_back()` function
`push_back()` is used for inserting an element at the end of the vector. If the type of object passed as parameter in the push_back() is not same as that of the vector or is not interconvertible an exception is thrown. 
![](https://www.studytonight.com/cpp/images/push_back%20working.png)

```
#include    <iostream>
#include    <vector>

int main(){
    std::vector<int> v;

    v.push_back(1);         //  insert 1 at the back of v
    v.push_back(4);         //  insert 4 at the back of v
    v.push_back(8);         //  insert 8 at the back of v

    for(size_t i = 0; i < v.size(); i++){
        std::cout<< v[i] << '\t';       //  printing 1 4 8
    }
}
```

<br>

### `insert(itr , element)` function
`insert(itr, element)` method inserts the element in vector before the position pointed by iterator `itr`. 

![](https://www.studytonight.com/cpp/images/single-insert-vector.png)

`insert` function can be overloaded by third argument, **count** as well. This count parameter defines how many times the element is to be inserted before the pointed position. 

![](https://www.studytonight.com/cpp/images/multiple-insert-vector.png)

<br>

### `pop_back()` function
`pop_back()` is used to remove the last element from the vector. It reduces the size of the vector by one. 

![](https://www.studytonight.com/cpp/images/pop_back-example.png)

```
#include    <iostream>
#include    <vector>

int main(){
    std::vector<int> v {10,20,30,40};
    std::vector<int>::iterator itr;
    v.pop_back();
    for(itr = v.begin(); itr != v.end(); itr++){
        std::cout<< *itr <<'\t';        //  printing 10 20 30
    }
}
```
<br>

### `erase()` function
`erase(itr_pos)` removes the element pointed by the iterator `itr_pos`. erase method can also be overloaded with an extra iterator specifying the end point of the range to be removed, i.e `erase(itr_start, itr_end)`.

```
#include    <iostream>
#include    <vector>

int main(){
    std::vector<int> v1 {10,20,30,40};
    std::vector<int>iterator:: itr = v1.begin();
    
    v1.erase(it);                       //  removes first element from the vector
    
    v1.erase(v1.begin(), v1.end() - 2 ) //  removes all the elements except last two
    
    for(itr = v1.begin(); itr != v1.end(); itr++) {
        std::cout << *itr << '\t';      //  printing 30 40
    }
}
```

<br>

### `resize` function
`resize(size_type n, value_type val)` method resizes the vector to **n** elements. If the current size of the vector is greater than **n** then the trailing elements are removed from the vector and if the current size is smaller than **n** than extra **val** elements are inserted at the back of the vector.

For example, If the size of the vector is 4 right now, with elements {10, 20, 30, 40} and we use `resize` method to resize it to size 5. Then by default a fifth element with value **0** will be inserted in the vector. We can specify the data to not be zero, by explicitly mentioning it as the **val** while calling the resize method.

<br>

### `swap` function
This method interchanges value of two vectors.

If we have two vectors v1 and v2 and we want to swap the elements inside them, you just need to call `v1.swap(v2)`, this will swap the values of the two vectors.

<br>

### `clear()` function
This method clears the whole vector, removes all the elements from the vector but do not delete the vector. 

For a vector v, `v.clear()` will clear it, but not delete it.

<br>

### `size()` function
This method returns the size of the vector.

<br>

### `capacity()` function
This method returns the number of elements that can be inserted in the vector based on the memory allocated to the vector.

<br>

### `empty()` function
This method returns true if the vector is empty else returns false. 

<br>

### `at()` function
This method works same in case of vector as it works for array. 

`vector_name.at(i)` returns the element at **i**_th index in the vector **vector_name**. 

<br>

### `front()` and `back()` function
`vector_name.front()` returns the element at the front of the vector (i.e. leftmost element). 

While `vector_name.back()` returns the element at the back of the vector (i.e. rightmost element). 

---

## Reference:
>   http://www.cplusplus.com/reference/vector/vector/