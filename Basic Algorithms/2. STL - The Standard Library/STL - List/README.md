#   List Containter in STL

<br>

Array and Vector are contiguous containers, i.e they store their data on continuous memory, thus the insert operation at the middle of vector/array is very costly (in terms of number of operaton and process time) because we have to shift all the elements, linked list overcome this problem. Linked list can be implemented by using the list container. 

---
List supports a bidirectional and provides an efficient way for insertion and deletion operations.

---

Syntax for creating a list is:

`   std::list< object_type > list_name;  `

<br>

For example:
```
#include    <list>

int main() {
    std::list<int> l;                               //  create a new empty linked list
    std::list<int> l1 {1,2,3};                      //  create a new list initialised with parameters
    std::list<std::string> l2 {"Andrei", "Andra"};  //  create a new list initialised with parameters
    std::list<int> new_list = 1;                    //  create list of integer and copies value of 1 into it
}
```
![](https://www.studytonight.com/cpp/stl/images/introducing-list.png)


<br>

---

<br>

## Member Functions of List Container


### `insert` function
This method, as the name suggests, inserts an element at specific position, in a list. There are 3 variations of insert(), they are as follows :
- `insert(iterator, element)` : inserts **element** in the list before the position pointed by the **iterator**.
- `insert(iterator, count, element)` : inserts **element** in the list before the position pointed by the **iterator**, **count** number of times.
- `insert(iterator, start_iterator, end_iterator)`: insert the element pointed by **start_iterator** to the element pointed by **end_iterator** before the position pointed by **iterator**


```
#include    <list>

int main(){
    std::list<int> l = {1, 2, 3, 4, 5};
    std::list<int>::iterator itr = l.begin();

    l.insert(itr+1, 100);           //  insert 100 before 2 position
                                    //  now, 'l' list is : 1 100 2 3 4 5

    std::list<int> new_l = {10, 20, 30, 40};

    new_l.insert(new_l.begin(), l.begin(), l.end());
    /*
        insert elements from beginning of list 'l' to the end of list 'l'
        before 1st position in list 'new_l'

        now, list new_l is 1 100 2 3 4 5 10 20 30 40
    */

    l.insert(l.begin(), 5, 10);     //  insert 10 before beginning 5 times
                                    //  now, 'l' list is: 10 10 10 10 10 1 100 2 3 4 5
}
```

<br>

### `push_back` and `push_front` function
`push_back(element)` method is used to push elements into a list from the back.

![](https://www.studytonight.com/cpp/stl/images/push_back.png)

`push_front(element)` method is used to push elements into a list from the front. 

![](https://www.studytonight.com/cpp/stl/images/push_front.png)

<br>

### `pop_back()` function
`pop_back()` is used to remove the last element from the vector. It reduces the size of the vector by one. 

![](https://www.studytonight.com/cpp/images/pop_back-example.png)

```
#include    <iostream>
#include    <list>

int main(){
    std::list<int> l{1,2,3,4,5};

    l.push_back(6);     
    l.push_back(7);
                            //  now, 'l' list become 1,2,3,4,5,6,7
    l.push_front(8);
    l.push_front(9);
                            //  now, 'l' list become 9,8,1,2,3,4,5,6,7
}
```

<br>

### `pop_back` and `pop_front` function
`pop_front()` removes first element from the start of the list. While `pop_back()` removes first element from the end of the list.

```
#include    <iostream>
#include    <list>

int main(){
    std::list<int> l{1,2,3,4,5};
    
    l.pop_back();           //  now, 'l' list becomes 1,2,3,4
    
    l.pop_front();          //  now, 'l' list becomes 2,3,4
}
```

<br>

### `empty` function
This method returns true if the list is empty else returns false.

<br>

### `size` function
This method can be used to find the number of elements present in the list.

<br>

### `front` and `back` function
`front()` is used to get the first element of the list from the start while `back()` is used to get the first element of the list from the back.

<br>

### `swap` function
Swaps two list, if there is exception thrown while swapping any element, `swap()` throws exception. Both lists which are to be swapped must be of the same type, i.e you can’t swap list of an integer with list of strings. 

<br>

### `reverse` function
This method can be used to reverse a list completely.

```
#include <iostream>
#include <list>

int main(){
    list<int> l{1,2,3,4,5};
    
    l.reverse();            //  now, 'l' list becomes 5,4,3,2,1
}
```

<br>

### `sort` function
`sort()` method sorts the given list. It does not create new sorted list but changes the position of elements within an existing list to sort it. This method has two variations :
-   `sort()` : sorts the elements of the list in ascending order, the element of the list should by numeric for this function.
-   `sort(compare_function)` : This type of sort() is used when we have to alter the method of sorting. Its very helpful for the elements that are not numeric. We can define how we want to sort the list elements in compare_funtion. For example, list of strings can be sorted by the length of the string, it can also be used for sorting in descending order.

```
#include <iostream>
#include <list>

bool compare_function( string& s1 , string& s2 )
{
    return ( s1.length() > s2.length() );
}

int main(){
    std::list<int> list1 = {2,4,5,6,1,3};
    std::list<string> list2 = {"h", "hhh", "hh"};
    
    list1.sort();                   //  list1 is now 1 2 3 4 5 6
    
    list2.sort(compare_function);   //  list2 is now h hh hhh
}
```

<br>

### `splice` function
`splice()` method transfers the elements from one list to another. There are three versions of splice :
-   `splice(iterator, list_name)` : Transfers complete list **list_name** at position pointed by the **iterator**.
-   `splice(iterator, list_name, iterator_pos)` : Transfer elements pointed by **iterator_pos** from **list_name** at position pointed by **iterator**.
-   `splice(iterator, list_name, itr_start, itr_end)` : Transfer range specified by **itr_start** and **itr_end** from **list_name** at position pointed by **iterator**.

```
#include <iostream>
#include <list>

int main (){
    std::list<int> list1 = {1,2,3,4};
    std::list<int> list2 = {5,6,7,8};
    std::list<int>::iterator it;
    
    it = list1.begin();
    ++it;                           //pointing to second position           
    
    list1.splice(it, list2);
    /*  transfer all elements of list2 at position 2 in list1
        now list1 is 1 5 6 7 8 2 3 4 and list2 is empty */
                                        
    list2.splice(list2.begin(), list1, it);
    /*  transfer element pointed by it in list1 to the beginning of list2
        list2 is now 5 and list1 is 1 6 7 8 2 3 4*/
    
    return 0;
}
```

<br>

### `merge` function
Merges two sorted list. It is mandatory that both the list should be sorted first. `merge()` merges the two list such that each element is placed at its proper position in the resulting list. Syntax for merge is `list1.merge(list2)`.

The list that is passed as parameter does not get deleted and the list which calls the merge() becomes the merged list

```
#include <iostream>
#include <list>

int main (){
    std::list<int> list1 = {1,3,5,7,9};
    std::list<int> list2 = {2,4,6,8,10};
    
    /*  both the lists are sorted. In case they are not , 
        first they should be sorted by sort function() */
    
    list1.merge(list2);     //  list list1 is now 1,2,3,4,5,6,7,8,9,10
    
    std::cout << list1.size() << std::endl;    // prints 10 
}
```
---

## Reference:
>   http://www.cplusplus.com/reference/list/list/

>   https://www.javatpoint.com/post/cpp-list