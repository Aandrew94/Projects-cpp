## [C++] Convert Decimal to Binary
---
Decimal to Binary Conversion Algorithm

|Decimal| 	Binary  |
|:-----:|:---------:|
|1      | 	0       |
|2      | 	10      |
|3      | 	11      |
|4      | 	100     |
|5      | 	101     |
|6      | 	110     |
|7      | 	111     |
|8      | 	1000    |
|9      |	1001    |
|10     | 	1010    |

<br>

|  1  | 0 | 0 |  1  |
|:---:|:-:|:-:|:---:|
| LSB |   |   | MSB |


### Steps:
1: Divide the number by 2 through % (modulus operator) and store the remainder in array

2: Divide the number by 2 through / (division operator)

3: Repeat the step 2 until the number is greater than zero