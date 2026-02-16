Practical 1 - 
AIM - To find sum of n numbers using reccursion 
Algorithm - 
step1 - Start
step2 - Read an integer n
step3 - Call the function sum(n)
step4 - If n == 0, return 0
step5 - Else, return n + sum(n-1)
step6 - Store the returned value in result
step7 -Print result
step8 - Stop
use cases - 
1) Mathematical calculations

2) Teaching recursion concepts

3) Problem-solving in competitive programming

4) Computing series sums

Time complexity analysis 
reccurance relation 
T(n) = c + T(n-1) 
<img width="1847" height="832" alt="image" src="https://github.com/user-attachments/assets/2a4b2c2b-3c29-4cd4-ada6-3cace58680e6" />
practical 2 - 
Aim - To compute x raised to  power n using an optimized recursive method with logarithmic time complexity.
algo - 
Start

Read base x and exponent n

Call function power(x, n)

If n == 0, return 1

If n is even:

Compute half = power(x, n/2)

Return half * half

If n is odd:

Compute half = power(x, n/2)

Return x * half * half

Print the result

Stop

Use Cases

Fast modular exponentiation

Cryptography (RSA, Diffie-Hellman)

Scientific computing

Competitive programming

Recurrence Relation ->
T(n) = T(n/2) + c 
<img width="1759" height="880" alt="image" src="https://github.com/user-attachments/assets/f522259c-7c85-4a5b-ac67-6c41c0f22c94" />

practical 3 - 
Aim - To generate and print all permutations of a given string using recursion.
Algorithm used - 
Start

Read the input string s

Call function permute(s, l, r)

If l == r, print the string

For i from l to r:

Swap s[l] with s[i]

Recursively call permute(s, l+1, r)

Swap back s[l] with s[i] (backtrack)

Use cases - 
Generating anagrams

Password cracking simulations

Combinatorics problems

Testing all possible arrangements

Stop
Time analysis - 
Reccurance relation 
T(n) = c + n*T(n-1) 
<img width="1856" height="942" alt="image" src="https://github.com/user-attachments/assets/d4c80319-2600-4a37-b3dc-8e3ffd6c4369" />

Practical -4 
Aim -To generate all possible binary combinations (0 and 1) of length n using recursion, which forms the truth table for n boolean variables.
Algo used ->
Start

Read integer n (number of variables)

Create an array arr of size n

Call function generate(pos)

If pos == n:

Print the array as one row of the truth table

Return

Set arr[pos] = 0 and call generate(pos + 1)

Set arr[pos] = 1 and call generate(pos + 1)

Stop

Use Cases ->

Digital logic design

Boolean function testing

Circuit simulation

Logic gate verification

Time analysis ->
reccurance relation - 
T(n) = 2*T(n-1) +c 
<img width="1671" height="888" alt="image" src="https://github.com/user-attachments/assets/e3984322-c1a6-4df1-b3dc-10b3253a4e81" />

Practical -5 
AIM - 
To move n disks from the Source rod to the Destination rod using an Auxiliary rod following the rules of Tower of Hanoi.
Algo used - 
Start

Read integer n (number of disks)

Call function TOH(n, source, auxiliary, destination)

If n == 1:

Move disk 1 from source to destination

Return

Move n-1 disks from source to auxiliary using destination

Move disk n from source to destination

Move n-1 disks from auxiliary to destination using source

Stop
Use cases - >
Understanding recursion and stack behavior

Algorithm design practice

Disk scheduling simulations

Puzzle solving and game logic
Time analysis - 
Reccurance relation - 
T(n) = 2*T(n-1) + 1 
<img width="1753" height="874" alt="image" src="https://github.com/user-attachments/assets/7533aeaa-1666-4496-a34f-ff792d2be47c" />
Practical - 6 
AIM - 
To search for a given element in an array using a recursive linear search technique.
Algorithm used - 
Start

Read array size n and elements

Read the target element key

Call function linearSearch(arr, n, key, index) with index = 0

If index == n, return -1 (not found)

If arr[index] == key, return index

Else call linearSearch(arr, n, key, index + 1)

Print result

Stop
Use cases - 
Searching in small datasets

Educational recursion examples

Simple lookup operations

Time complexity analysis ->
T(n) = T(n-1) + c 
<img width="1919" height="967" alt="image" src="https://github.com/user-attachments/assets/16b19553-25ef-4b44-97b9-53f5a6d2aa97" />

Practical 7- 
Aim - To evaluate a polynomial expression efficiently using Horner’s Rule with recursion.
Algo used - 
Start

Read degree n

Read coefficients array a[0…n]

Read value of x

Call function horner(a, n, x)

If n == 0, return a[0]

Else return:
Print the result

Stop
USE CASE =>
Polynomial evaluation in compilers

Signal processing

Numerical methods

Scientific computing

Time complexity analysis =>
T(n) = T(n-1) + 1
<img width="955" height="696" alt="image" src="https://github.com/user-attachments/assets/8bbd6817-44a3-4d72-82c9-261c50f917aa" />

  Practical -8 
  Aim - 
  To sort an array of n elements in ascending order using iterative Selection Sort.
  ALGO USED - 
  Start

Read array size n and elements arr[0…n-1]

For i = 0 to n-2:

Set minIndex = i

For j = i+1 to n-1:

If arr[j] < arr[minIndex], update minIndex = j

Swap arr[i] with arr[minIndex]

Print the sorted array

Stop

Use cases - 
Sorting small arrays

Learning basic sorting techniques

Step-by-step algorithmic practice

Time analysis ->
time is o(n^2) both for worst and best case 
<img width="1691" height="909" alt="image" src="https://github.com/user-attachments/assets/9ad2fce5-324e-4b4a-a69c-e4e48c3dd9d2" />

Practical - 9 
Aim ->
to find the missing number in a sequence of consecutive integers using an efficient method.
Algo used ->
Start

Read array arr[] of size n-1

Loop through the array from i = 0 to n-2

Calculate expected_bit0 = 1 if i % 2 == 0 else 0

Calculate actual_bit0 = arr[i] & 1

If actual_bit0 != expected_bit0, return i → missing index

If no mismatch found, return n-1

Stop
Use cases ->
Detecting missing items in bit-patterned sequences

Low-level data validation / hardware testing

Competitive programming / algorithm optimization exercises

Time complexity analysis 
<img width="1816" height="863" alt="image" src="https://github.com/user-attachments/assets/37259260-6e93-4599-82ac-f2a033ffeffc" />

Practical - 10 
Aim -> 
To find the first occurrence of duplicate elements in an array using a simple nested loop approach.
Algo used ->
Start

Read array arr[] of size n

For i = 0 to n-2:

For j = i+1 to n-1:

If arr[i] == arr[j]:

Return i (index of first duplicate)

If no duplicates found, return -1

Stop
Use cases ->
Simple duplicate detection in small arrays

Educational example to understand brute-force searching

Can be used in exams and lab practicals to demonstrate nested loops logic

Time complexity anslysis ->
<img width="1847" height="933" alt="image" src="https://github.com/user-attachments/assets/a15efc43-4279-43dd-9bb7-fb2c0df0b3fd" />

Practical -11 
Aim - to find number of bounces of a ball thrown from a height 
Algo used -
Start

Read initial velocity vel and set bounce count n = 0

Call function bounce(vel, n)

If vel < 1, return n (base case)

Else:

Multiply velocity by 0.575

Increment n by 1

Recursively call bounce(0.575 * vel, n)

Print total number of bounces

Stop
Use case - 
Physics simulations (ball bounce, energy loss)

Teaching recursion and logarithmic processes

Game physics and animations

Time analysis ->
<img width="1714" height="877" alt="image" src="https://github.com/user-attachments/assets/7eff5b6b-b403-409f-9e75-df98b6340f38" />
















