# Strings, Vectors, and Arrays

## Exercises Section 3.1

### Exercise 3.1

-----

> Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.

1.4.1:

```c++
# include <iostream>

using std::cout;
using std::endl;

int main() {
    int sum = 0, val = 1;
    
    while (val <= 10) {
        sum += val;
        ++val;
    }
    
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    return 0;
}
```

[code for 2.6.2](./exec_1.cc)

## Exercises Section 3.2.2

### Exercise 3.2

-----

> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

[code](./exec_2.cc)

### Exercise 3.3

-----

> Explain how whitespace characters are handled in the `string` input operator and in the `getline` function

- **The `string` input operator** reads and discards any leading whitespace, including spaces, newlines, and tabs. It then reads characters until the next whitespace character is encountered.
- **The `getline` function** stops at a newline and discards the newline. Thus, the newline is not stored in the buffer string.

### Exercise 3.4

-----

> Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

[code](./exec_4.cc)

### Exercise 3.5

-----

> Write a program to read `string`s from the standard input, concatenating what is read into one large `string`. Print the concatenated `string`. Next, change the program to separate adjacent input `string`s by a space.

[code](./exec_5.cc)

## Exercises Section 3.2.3

### Exercise 3.6

-----

> Use a range for to change all the characters in a string to `X`.

[code](./exec_6.cc)

### Exercise 3.7

-----

> What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a `char` to see if you were right.

[code](./exec_7.cc)

### Exercise 3.8

-----

> Rewrite the program in the first exercise, first using a `while` and again using a traditional `for` loop. Which of the three approaches do you prefer and why?

[code](./exec_8.cc)

The range `for` is convenient for traversing all the members.

### Exercise 3.9

-----

> What does the following program do? Is it valid? If not, why not?

```c++
string s;
cout << s[0] << endl;
```

It's not valid.`s` is initialized to be empty, using the subscript `0` to get the first char of an empty string is not valid.

### Exercise 3.10

-----

> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

[code](./exec_10.cc)

### Exercise 3.11

-----

> Is the following range `for` legal? If so, what is the type of `c`?

```C++
const string s = "Keep out!";
for (auto &c : s) {/* ... */}
```

It is legal. Type of `c` is reference to `const char`.

## Exercises Section 3.3.1

### Exercise 3.12

-----

> Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.

```c++
// legal, define and initial an empty vector contains vectors.
vector<vector<int>> ivec;

// illegal, "svec" has different type with "ivec", "ivec" can't be used to initial "svec".
vector<string> svec = ivec;

// legal, define and initial a string vector has ten elements initialed to be "null".
vector<string> svec(10, "null");
```

### Exercise 3.13

-----

> How many elements are there in each of the following vectors? What are the values of the elements?

```c++
// Empty, no element.
vector<int> v1;

// 10 elements, initialized to be 0.
vector<int> v2(10);

// 10 elements, initialized to be 42.
vector<int> v2(10, 42);

// 1 element with the value of 10.
vector<int> v4{10};

// 2 elements, values are 10 and 42.
vector<int> v5{10, 42};

// 10 elements, values are empty string.
vector<string> v6{10};

// 10 elements, values are "hi".
vector<string> v7{10, "hi"};
```

## Exercises Section 3.3.2

### Exercise 3.14

-----
> Write a program to read a sequence of `int`s from cin and store those values in a `vector`.

[code](./exec_14.cc)

### Exercise 3.15

-----
> Repeat the previous program but read `string`s this time.

[code](./exec_15.cc)

## Exercises Section 3.3.3

### Exercise 3.16

-----

> Write a program to print the size and contents of the vectors from [exercise 3.13](###-exercise-3.13). Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

[code](./exec_16.cc)

### Exercise 3.17

-----

> Read a sequence of words from `cin` and store the values a `vector`. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.

[code](./exec_17.cc)

### Exercise 3.18

-----

> Is the following program legal? If not, how might you fix it?

```c++
vector<int> ivec;
ivec[0] = 42;
```

It's illegal. An empty vector has no element to subscript.

### Exercise 3.19

-----

> List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

```c++
// Way 1
vector<int> v1(10, 42);

// Way 2
vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

// Way 3
vector<int> v3;
for (int i = 0; i < 10; i++) v3.push_back(42);
```

Apparently, the first one is more effective and simply.

### Exercise 3.20

-----

> Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

[code](./exec_20.cc)

## Exercises Section 3.4.1

## Exercise 3.21

-----

> Redo the first exercise from § 3.3.3 (p. 105) using iterators.

[code](./exec_21.cc)

## Exercise 3.22

-----

>Revise the loop that printed the first paragraph in `text` to instead change the elements in `text` that correspond to the first paragraph to all uppercase. After you’ve updated `text`, print its contents.

[code](./exec_22.cc)

## Exercise 3.23

-----

>Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.

[code](./exec_23.cc)

## Exercises Section 3.4.2

### Exercise 3.24

-----

> Redo the last exercise from § 3.3.3 (p. 105) using iterators.

[code](./exec_24.cc)

### Exercise 3.25

-----

> Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.

[code](./exec_25.cc)

### Exercise 3.26

-----

> In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) / 2;`?

`beg + end` results to an invalid iterator.

## Exercises Section 3.5.1

### Exercise 3.27

-----

> Assuming `txt_size` is a function that takes no arguments and returns an `int` value, which of the following definitions are illegal? Explain why.

```c++
unsigned buf_size = 1024;

int ia[buf_size];

int ia[4 * 7 - 14];

int ia[txt_size()];

// Illegal, no space for the null.
char st[11] = "fundamental";
```

### Exercise 3.28

-----

> What are the values in the following arrays?

```c++
// Empty strings in sa.
string sa[10];

// 0s in ia.
int ia[10];

int main() {
    // Undefined values in those two arrays.
    string sa2[10];
    int ia[10];
}
```

### Exercise 3.29

> List some of the drawbacks of using an array instead of a `vector`

- You can not add elements to an array.
- You should decide the size of an array when defining it.

## Exercise Section 3.5.2

### Exercise 3.30

-----

> Identify the indexing errors int the following code:

```c++
constexpr size_t array_size = 10;
int ia[array_size];
// ERROR: ix can't equals to array_size, the max index is array_size - 1.
for (size_t ix = 1; ix <= array_size; ++ix) 
    ia[ix] = ix;
```

### Exercise 3.31

-----

> Write a program to define an array of ten `int`s. Give each element the same value as its position in the array.

[code](./exec_31.cc)

### Exercise 3.32

-----

> Copy the array you defined in the previous exercise into another array. Rewrite your program to use `vector`s.

**array:** [code1](./exec_32_1.cc)

**vector:** [code2](./exec_32_2.cc)

### Exercise 3.33

-----

> What would happen if we did not initialize the scores array in the program on page 116?

Without initialization, those values in the scores array would be undefined, then the `++` operator can not get correct result.

## Exercises Section 3.5.3

### Exercise 3.34

-----

> Given that p1 and p2 point to elements in the same array, what dose the following code do? Are there values of p1 or p2 that make this code illegal?

```c++
p1 += p2 - p1;
```

It move p1 with the offset `p2 - p1`, then `p1` and `p2` point to the same address. Any legal `p1` and `p2` make this code legal.

### Exercise 3.35

-----

> Using pointers, writes a program to set the elements in an array to zero.

[code](./exec_35.cc)

### Exercise 3.36

-----

> Write a program to compare two arrays for equality. Write a similar program to compare two `vector`s.

[code](./exec_36.cc)

## Exercises Section 3.5.4

### Exercise 3.37

-----

> What does the following program do?

```c++
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

This code print all characters in `ca`. But as no `\0` appended, the `while` loop won't terminated as expected, causing an undefined behavior.

### Exercise 3.38

-----

> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

[For Details](https://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)

### Exercise 3.39

-----

> Write a program to compare two `string`s. Now write a program to compare the values of two C-style character strings.

[code](./exec_39.cc)

### Exercise 3.40

-----

> Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use `strcpy` and `strcat` to copy the two arrays int the third.

[code](./exec_40.cc)

## Exercises Section 3.5.5

### Exercise 3.41

-----

> Write a program to initialize a `vector` from an array of `int`s.

[code](./exec_41.cc)

### Exercise 3.42

> Write a program to copy a `vector` of `int`s into an array of `int`s.

[code](./exec_42.cc)

## Exercises Section 3.6

### Exercise 3.43

-----

> Write three different versions of a program to print the elements of `ia`. One version should use a range `for` to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, `auto`, or `decltype` to simplify the code.

[code](./exec_43.cc)

### Exercise 3.44

-----

> Rewrite the programs from the previous exercises using a type alisa for the type of the loop control variables.

[code](./exec_44.cc)

### Exercise 3.45

-----

> Rewrite the programs again, this time using `auto`.

[code](./exec_45.cc)
