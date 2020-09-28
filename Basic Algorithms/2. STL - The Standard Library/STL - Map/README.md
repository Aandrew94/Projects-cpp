#   Map Containter in STL

<br>

**Maps** contain sorted **key-value** pair, in which each key is unique and cannot be changed, and it can be inserted or deleted but cannot be altered. Value associated with keys can be altered. 
>   We can search, remove and insert in a map within `O(n)` time complexity.

For example: A map of students where roll number is the key and name is the value can be represented graphically as : 

![](https://www.studytonight.com/cpp/images/map-example.png)
Notice that keys are arranged in ascending order, its because maps always arrange its keys in sorted order. In case the keys are of string type, they are sorted lexicographically.

Syntax for creating a map is:

`   std::map< key_type , value_type > map_name;  `

This will create a map with key of type **Key_type** and value of type **value_type**. One thing which is to remembered is that key of a map and corresponding values are always inserted as a pair, _you cannot insert only key or just a value in a map._

<br>

For example:
```
#include    <map>

int main(){
    
    std::map<int,int> m { {1,2}, {2,3}, {3,4} };    
    /*  creates a map 'm' with int-keys 1,2,3 and
        their coresponding int-values 2,3,4     */

    std::map<std::string,int> map1;
    /*  create a map with string-key and
        their coresponding int-values   */

    map1["as"]  = 100;      //  insert string-key = "as" with int-value = 100
    map1["b"]   = 200;      //  insert string-key = "b" with int-value = 200
    map1["c"]   = 300;      //  insert string-key = "c" with int-value = 300
    map1["def"] = 400;      //  insert string-key = "def" with int-value = 400

    std::map<std::string,int> map2 (map1.begin(),map1.end());
    /*  create a map which have entries copied
        from map1.begin() to map2.end() */

    std::map<int,int> map3 (m);
    /*  create map which is a copy of map 'm' */

```

<br>

## Member Functions of Map Container


### `at` and `[]` 
Both `at` and `[]` are used for accessing the elements in the map. The only difference between them is:
-   `at` throws an exception if the accessed key is not present in the map
-   `[]` operator inserts the key in the map if the key is not present already in the map

```
#include    <iostream>
#include    <map>

int main(){
    
    std::map<int, std::string> m    { {1,"car"}, {2,"house"}, {3,"job"} };

    std::cout<< m.at(1);
    std::cout<< m.at(2);

    std::cout<< m[3];

//  change the value associated with key 1
    m.at(1) = "plane";

//  change the value associated with key 2
    m[2] = "new_car";

    m[4] = "new_house";
/*  since there is no int-key = 4 in the map
    it insert a pair int_key = 4 - string_value
    in the map  */

    m.at(5) = "euro_trip";
/*  since there is no int-key = 5 in the map,
    it throws an exception -> std::out_of_range*/

}
```

<br>

### `empty` and `size` and `ma_size` function
-   `empty()` returns boolean true if the map is empty, else it returns Boolean false. 
-   `size()` returns number of entries in the map, an entry consist of a key and a value.
-   `max_size()` returns the maximum possible entries based on the memory allocated to the map. 

<br>

### `insert` and ~~`insert_or_assign`~~
`insert()` is used to insert entries in the map. Since keys are unique in a map, it first checks that whether the given key is already present in the map or not, if it is present the entry is not inserted in the map and the iterator to the existing key is returned otherwise new entry is inserted in the map.

There are two variations of `insert()`:
-   `insert(pair)` : In this variation, a pair of key and value is inserted in the map. The inserted pair is always inserted at the appropriate position as keys are arranged in sorted order.
-   `insert(start_itr , end_itr)`: This variation inserts the entries in range defined by **start_itr** and **end_itr** of another map.

~~The `insert_or_assign()` works exactly as `insert()` except that if the given key is already present in the map then its values is modified.~~

```
#include    <map>

int main(){
    
    std::map<int,int> m {{1,2} , {2,3} , {3,4} };
    
    m.insert( std::pair<int,int> (4,5)  );
    /*  inserts a new entry of key = 4 and value = 5 in map m   */
    
    /*  make_pair() can also be used for creating a pair    */
    m.insert( std::make_pair(5, 6)  );
    /*  inserts a new entry of key = 5 and value = 6    */
    
    
    std::map<int,int>::iterator i , j;
    i = m.find(2);      //    points to entry having key =2
    j = m.find(5);      //    points to entry having key =5
    
    std::map<int,int> new_map;
    
    new_map.insert(i,j);
    /*  insert all the entries which are pointed 
        by iterator i to iterator j */ 
    
    m.insert( std::make_pair(3,6)   );  
    //  do not insert the pair as map m already contain key = 3 */ 
```

<br>

### `erase(itr)` and `clear()` 
`erase(itr)` removes the entry from the map pointed by the iterator(which is passed as parameter), however if we want to remove all the elements from the map, we can use `clear()`, which it clears the map and sets its size to `0`;

There are two variations of erase:
-   `erase(iterator_itr)` : This removes entry from the map pointed by iterator **iterator_itr**, reducing the size of map by `1`
-   `erase(start_iterator , end_iterator)` : it removes the elements in tange specified by the **start_iterator** and **end_iterator**

<br>

### `begin()`/`rbegin()`, `end`/`rend()` and `find(key_value)` 
Note that `begin()`, `end()` and `find()` returns an **iterator**. 
-   `begin()` returns a read/write iterator that points to the first pair in the map. Iteration is done in ascending order according to the keys.
-   `rbegin()` returns a read/write _reverse iterator_ that points to the last pair in the map. Iteration is done in descending order according to the keys.
-   `end()` returns a read/write iterator that points one past the last pair in the map Iteration is done in ascending order
-   `rend()` returns a read/write _reverse iterator_ that points to one before the first pair in the  map. Iteration is done in descending order according to the keys.
-   `find(key_value)` returns the iterator to the entry having key equal to given key (passed as parameter).

![](https://www.studytonight.com/cpp/images/begin-find-end-functions.png)


## Reference:
>   http://www.cplusplus.com/reference/map/map/

>   https://www.javatpoint.com/post/cpp-map