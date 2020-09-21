## [C++] Arrays 2d

---

A matrix that has the number of rows equal to the number of columns is called a quadratic matrix.

Since the number of lines is equal to the number of columns in the quadratic matrices, 2 important notions appear: 
- the main diagonal
- the secondary diagonal.

The main diagonal consists of the elements of a quadratic matrix located on the positions in which the index of the line is equal to that of the column (`i = j`), ie a [i][i]. 
For example in the quadratic matrix of [3][3], the elements on the main diagonal are a [0][0] - [1][1] - [2][2].

The secondary diagonal is formed by the elements of a quadratic matrix located on the positions where `i + j = n + 1`, more precisely a `[i][n-i + 1]`. 
For example in the quadratic matrix of [3][3], the elements on the main diagonal are a [0][2] - [1][2] and a [2][1].


### Main and secondary diagonal

![](https://invata.info/wp-content/uploads/2017/03/diagonala-principala-si-secundara.jpg)
- green squares represent the main diagonal
- yellow squares represent the secondary diagonal.  

<br>

### Below and above the main diagonal

![](https://invata.info/wp-content/uploads/2017/03/zone-speciala-matrice-patratica.jpg)
In the matrix above, dark green squares represent the elements below the main diagonal, while light blue elements represent the elements above the main diagonal.

- The relation of the elements above the main diagonal (blue boxes) is `i < j`.

- The relation of the elements below the main diagonal (green boxes) is `i > j`.


<br>

### Below and above the secondary diagonal

![](https://invata.info/wp-content/uploads/2017/03/zonediagonalasecundara-300x261.jpg)
- The relation of the elements above the secondary diagonal (blue boxes) is `i + j <n + 1`.
- The relation of the elements below the secondary diagonal (green boxes) is `i + j> n + 1`.