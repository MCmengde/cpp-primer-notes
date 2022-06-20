# Statements

## Exercises Sections 5.1

### Exercise 5.1

-----

> What is a `null` statement? When might you use a `null` statement?

A `null` statement is a single semicolon. A null statement is useful where the language requires a statement but the
program’s logic does not.

### Exercise 5.2

-----

> What is a block? When might you might use a block?

A block is a (possibly empty) sequence of statements and declarations surrounded by a pair of curly braces.It's used when multiple statements are needed.

### Exercise 5.3

-----

Use the comma operator (4.10, p. 157) to rewrite the while loop from 1.4.1(p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

[code](./exec_3.cc)

The rewrite diminishes the readability.

## Exercises Section 5.2

### Exercise 5.4

-----

> Explain each of the following example, and correct any problems you detect.

```c++
while (string::iterator iter != s.end()) {}     // illegal declaration

while (bool status = find(word)) {}             // Variable "status" is only declared inside scope of while condition.
if (!status) {}
```

## Exercises Section 5.3.1

### Exercise 5.5

> Using an `if-else` statement, write your own version of the program to generate the letter grade from numeric grade.

[code](./exec_5.cc)

### Exercise 5.6

> Rewrite your grading program to use the conditional operator in place of the `if-else` statement.

[code](./exec_6.cc)

### Exercise 5.7

> Correct the errors in each fo the following code fragments:

```c++
if (ival1 != ival2) 
    ival1 = ival2
else ival1 = ival2 = 0;

if (ival < minval)
    minval = ival;
    occurs = 1;

if (int ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival) 
    cout << "ival = 0\n";

if (ival = 0)
    ival = get_value();
```

Correct:

```c++
if (ival1 != ival2) 
    ival1 = ival2;                      // add semicolon.
else ival1 = ival2 = 0;

if (ival < minval) {                    // add braces.
    minval = ival;
    occurs = 1;
}

if (int ival = get_value())
    cout << "ival = " << ival << endl;
else if (!ival)                         // add else 
    cout << "ival = 0\n";

if (ival == 0)                          // add "="
    ival = get_value();
```

### Exercise 5.8

-----

> What is a "dangling `else`"? How are `else` clauses resolved in C++?

In C++, an else is always paired with the closest preceding unmatched if.

## Exercises Section 5.3.2

### Exercise 5.9

-----

> Write a program using a series of `if` statements to count the number of vowel int text from cin.

[code](./exec_9)

### Exercise 5.10

-----

> There is one problem with our vowel-counting program as we've implemented it: It doesn't count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel-that is, your program should count both 'a' and 'A' as part of `aCnt`, and so forth.

[code](./exec_10.cc)

### Exercise 5.11

-----

> Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

[code](./exec_11.cc)

### Exercise 5.12

-----

> Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl and fi.

[code](./exec_12.cc)

### Exercise 5.13

-----

> Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

```c++
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}

unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
}

unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddCnt++;
        break;
    case 2, 4, 6, 8, 10:
        evenCnt++;
        break;
}

unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

```c++
// Error, have no break statement.
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++; break;
    case 'e': eCnt++; break;
    default: iouCnt++;
}

// Error, the `ix` may not define.
unsigned index = some_value();
int ix;
switch (index) {
    case 1:
        ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
}

// Error, case label syntax error
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3: case 5: case 7: case 9:
        oddCnt++;
        break;
    case 2: case 4: case 6: case 8: case 10:
        evenCnt++;
        break;
}


// Error, case label must be a constant expression.
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

## Exercises Section 5.4.1

### Exercise 5.14

-----

> Write a program to read `string`s from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicated, or else print a message saying that no word was repeated.

[code](./exec_14.cc)

## Exercises Section 5.4.2

### Exercise 5.15

-----

> Explain each of the following loops. Correct any problems you detect.

```c++
for (int ix = 0; ix != sz; ++ix) {}
if (ix != sz)

int ix;
for (ix != sz; ++ix) {}

for (int ix = 0; ix != sz; ++ix, ++sz) {}
```

Correct:

```c++
// Define `ix` out of the for loop. 
int ix;
for (ix = 0; ix != sz; ++ix) {}
if (ix != sz)

// Miss the initial part.
int ix;
for (; ix != sz; ++ix) {}

// `sz` can not increase.
for (int ix = 0; ix != sz; ++ix) {}
```

### Exercise 5.16

-----

> The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The `for` loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

```c++
// while idiomatic
int i;
while (cin >> i) {}

// the same for
for (int i; cin >> i;){}


// for idiomatic
for (int i = 0; i < size; ++i){}

// the same while
int i = 0;
while (i < size) {
    //...
    ++i;
}
```

I prefer for to while in such cases, because it's terse.

### Exercise 5.17

> Given two `vector`s of `int`s, write a program ot determine whether one `vector` is a prefix of the order. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing `0, 1, 1,` and `2` and `0, 1, 1, 2, 3, 5, 8`, respectively your program should return `true`.

[code](./exec_17.cc)

## Exercise Section 5.4.4

### Exercise 5.18

-----

Explain each of the following loops. Correct any problems you detect

```c++
do
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sun is: " << v1 + v2 << endl;
while (cin);

do {
    //...
} while (int ival = get_response());

do {
    int ival = get_response();
} while (ival);
```

Correct:

```c++
// add bracket
do {
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sun is: " << v1 + v2 << endl;
} while (cin);

// should not declared in while.
int ival;
do {
    //...
} while (ival = get_response());

// ival is not declared in this scope
int ival = get_response;
do {
    ival = get_response();
} while (ival);
```

### Exercise 5.19

-----

> Write a program that uses a `do while` loop to repetitively request two `string`s from the user and report which `string` is less than the other.

[code](./exec_19.cc)

## Exercises Section 5.5.1

### Exercise 5.20

-----

> Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the `break` statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

[code](./exec_20.cc)

## Exercises Section 5.5.2

### Exercise 5.21

-----

> Revise the program form the exercise in 5.5.1(p. 191) so that it looks only for duplicated words that start with an uppercase letter.

[code](./exec_21.cc)

## Exercises Sections 5.5.3

### Exercise 5.22

-----

> The last example in this section that jumped back to `begin` could be better written using a loop. Rewrite the code to eliminate `goto`.

```c++
for (int sz = get_size(); sz <= 0; sz = get_size());
```

## Exercises Section 5.6.3

### Exercise 5.23

-----

> Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

[code](./exec_23.cc)

### Exercise 5.24

-----

> Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don't `catch` an exception.

[code](./exec_24.cc)

### Exercise 5.25

-----

> Revise your program from the previous exercise to use a `try` block to `catch` the exception. The `catch` clause should print a message to the user and ask them to supply a new number and repeat the code inside the `try`.

[code](./exec_25.cc)
