# Functions

## Exercises Sections 6.1

### Exercise 6.1

-----

> What is the difference between a parameter and an argument?

**Parameters**: Local variable declared inside the function parameter list. they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

### Exercise 6.2

-----

> Indicate which if the following functions are in error and why. Suggest how you might correct the problems.

```c++
int f() {
    string s;
    // ...
    return s;
}

f2(int i) {/* ... */}

int calc(int v1, int v1) {/* ... */}

double square(double x) return x * x;
```

Correct:

```c++
// return type should be string
string f() {
    string s;
    // ...
    return s;
}

// function need return type
void f2(int i) {/* ... */}

// parameters list should not use same name twice
int calc(int v1, int v2) {/* ... */}

// function body needs braces
double square(double x) return x * x;
```

### Exercise 6.3

-----

> Write and test your own version of fact.

```c++
int fact(int val) {
    int rst = 1;
    for (int i = val; i > 0; --i) {
        rst *= i;
    }
    return rst;
}
```

### Exercise 6.4

-----

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from `main`.

[code](./exec_4.cc)

### Exercise 6.5

-----

> Write a function to return the absolute value of its argument.

[code](./exec_5.cc)

## Exercises Section 6.1.1

### Exercise 6.6

-----

> Explain the differences between a parameter, a local variable, and a local `static` variable. Give an example of a function in which each might useful.

**local variable**: Variables defined inside a block;

**parameter**: Local variables declared inside the function parameter list

**local static variable**: local static variable（object） is initialized before the first time execution passes through the object’s definition. Local statics are not destroyed when a function ends; they are destroyed when the program terminates.

```c++
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```

### Exercise 6.7

-----

> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

```c++
size_t gen() {
    static cnt = 0;
    return cnt++;
}
```

## Exercises Section 6.1.2

### Exercise 6.8

-----

> Write a header file named `Chapter6.h` that contains declarations for the functions you wrote for the exercises in 6.1(p. 205).

[Chapter6.h](./Chapter6.h)

## Exercises Section 6.1.3

### Exercise 6.9

-----

> Write your own versions of the `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

[fact.cc](./fact.cc)

[factMain.cc](./factMain.cc)

## Exercises Section 6.2.1

### Exercise 6.10

-----

> Using pointers, write a function to swap the values of  two `int`s. Test the function by calling it and printing teh swapped values.

[code](./exec_10.cc)

## Exercises Section 6.2.2

### Exercise 6.11

-----

> Write and test your own version of `reset` that takes a reference.

[code](./exec_11.cc)

### Exercise 6.12

-----

> Rewrite the program from [exercise 6.10](#exercise-610) in 6.2.1(p. 210) to use references instead of pointers to swap the value of two `int`s. Which version do you think would be easier to use and why?

[code](./exec_12.cc)

### Exercise 6.13

-----

> Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.

`void f(T)` pass the argument by value. nothing the function does to the parameter can affect the argument. `void f(T&)` pass a reference, will be bound to whatever `T` object we pass.

### Exercise 6.14

-----

> Given an example of when a parameter should be a reference type. Given an example of when a parameter should be not be a reference.

a parameter should be a reference type:

```c++
void reset(int &i) {
        i = 0;
}
```

a parameter should be not be a reference:

```c++
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator iter = begin; iter != end, ++iter) {
        std::cout << *iter << std::endl; 
    }
}
```

### Exercise 6.15

-----

> Explain the rationale for the type of each of `find_char`'s parameters. In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?

Because `s` should not be changed by this function, but `occurs` result must be calculated by the function.

Because `c` may be a temp variable, such as find_char(s, 'a', occurs).

`s` could be changed in the function, and `occurs` would not be changed. so `occurs = 0;` is an error.

## Exercises Section 6.2.3

### Exercise 6.16

-----

> The following function, although legal, is less useful than it might be, Identify and correct the limitation on this function:

```c++
bool is_empty(string& s) {return s.empty();}
```

Identify and correct:

```c++
bool is_empty(const string& s) {
    return s.empty();
}
```

### Exercise 6.17

-----

> Write a function to determine whether a `string` contains any capital letters. Write a function to change a `string` to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

```c++
// determine whether a `string` contains any capital letters.
bool contains_capital(const string& s) {
    for (auto c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

// change a `string` to all lowercase.
void to_lower(string& s) {
    for (auto &c : s) {
        tolower(c);
    }
}
```

These functions have different parameters types. `contains_capital` don't change the arguments, its parameters could be `const`. But `to_lower`'s parameters can not be `const`.

### Exercise 6.18

-----

> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.  
> (a) A function named `compare` that returns a `bool` and has two parameters that are references to a class named `matrix`.  
> (b) A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.

```c++
// (a)
bool compare(matrix &, matrix &);
// (b)
vector<int>::iterator change_val(int, vector<int> iterator);
```

### Exercise 6.19

-----

> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.

```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

// (a) illegal, only one parameter.
calc(23.4, 55.1);

// (b) legal
count("abcda", 'a');

// (c) legal, int -> double
calc(66);

// (d) legal, double -> int
sum(vec.begin(), vec.end(), 3.8);
```

### Exercise 6.20

-----

> When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

If we can use `const`, just use it. If we make a parameter a plain reference when it could be a reference to `const`, the reference value maybe changed.

## Exercises Section 6.2.4

### Exercise 6.21

-----

> Write a function that takes an `int` and a pointer to an `int` and returns larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?

```c++
int larger(const int a, const int *p) {
    return a > *p ? a : *p;
}
```

### Exercise 6.22

-----

> Write a function to swap two `int` pointers.

```c++
void swap(int* &p1, int* &p2) {
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}
```

### Exercise 6.23

-----

> Write your own versions of each of the `print` functions presented in this section. Call each of these functions to print `i` and `j` defined as follows:

```c++
int i = 0, j[2] = {0, 1};
```

[code](./exec_23.cc)

### Exercise 6.24

-----

> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.

```c++
void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i) 
        cout << ia[i] << endl;
}
```

The parameters like `const int ia[10]` can not promise the arguments array's size is ten. It is actually the same as `const int* ia`. Use reference can to ensure the size is ten, like this:
`const int (&ia)[10]`.

## Exercises Section 6.2.5

### Exercise 6.25

-----

> Write a `main` function that takes two arguments. Concatenate the supplied arguments and print the resulting `string`.

[code](./exec_25.cc)

### Exercise 6.26

-----

> Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.

[code](./exec_26.cc)

## Exercises Section 6.2.6

### Exercise 6.27

-----

> Write a function that takes an `initializer_list<int>` and produces the sum if teh elements in the list.

[code](./exec_27.cc)

### Exercise 6.28

-----

> In the second version of `error_msg` that has an `ErrCode` parameter, what is teh type of `elem` int the `for`| loop?

The type of elem in the `for` loop is `const std::string&`.

### Exercise 6.29

-----

> When you use an `initializer_list` in a range `for` would you ever use a reference as teh loop control variable? If so, why? If not, why not?

Depends on the type of elements of initializer_list. When the type is PODType, reference is unnecessary. Because `POD` is cheap to copy(such as `int`). Otherwise, Using reference(`const`) is the better choice.

## Exercises Section 6.3.2

### Exercise 6.30

-----

> Compile the version of `str_subrange` as presented on page 223 to see what your compiler does with the indicated errors.

[code](./exec_30.cc)

Result:

```shell
error: non-void function 'str_subrange' should return a value [-Wreturn-type]
            return;  // error #1: no return value; compiler should detect this
```

### Exercise 6.31

-----

> When is it valid to return a reference? A reference to `const`?

when you can find the preexisting object that the reference referred.

### Exercise 6.32

-----

> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```c++
int &get(int *arry, int index) {return arry[index];}

int main() {
    int ia[10];
    for (int i = 1; i != 10; ++i) 
        get(ia, i) = i;
}
```

legal, it gave the values (0 ~ 9) to array ia.

### Exercise 6.33

-----

> Write a recursive function to print the contents of a vector.

[code](./exec_33.cc)

### Exercise 6.34

-----

> What would happen if the stopping condition in `factorial` were `if (val != 0)`

- case 1 : If the argument is positive, recursion stops at 0.(Note : There is one extra multiplication step though as the combined expression for factorial(5) reads `5 * 4 * 3 * 2 * 1 * 1`. In terms of programming languages learning, such subtle difference probably looks quite trivial. In algorithms analysis and proof, however, this extra step may be super important.)
- case 2 : if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.

### Exercise 6.35

-----

> In the call to `fact`, why did we pass `val - 1` rather than `val--`?

the recursive function will always use val as the parameter. a recursion loop would happen.

## Exercises Section 6.3.3

### Exercise 6.36

-----

> Write the declaration for function that returns a reference to an array of ten `string`s, without using either a trailing return, `decltype`, or a type alias.

```c++
string (&func())[10];
```

### Exercise 6.37

-----

> Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should ues `decltype`. which form do you prefer and why?

```c++
// type alias
using ArrT = string[10];
ArrT& func();

// trailing return;
auto func() -> string (&)[10];

// decltype
string[10] arr;
decltype(arr) &func();
```

I prefer the second one, it's simple.

### Exercise 6.38

-----

> Revise the `arrPtr` function on to return a reference to the array.

```c++
auto arrPtr(int i) -> int (&)[5] {
    return (i % 2) ? odd : even;
}
```

## Exercises Section 6.4

### Exercise 6.39

-----

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

```c++
// (a) legal, repeated declarations(without definition) are legal in C++
int calc(int, int);
int calc(const int, const int);

// (b) illegal, same parameter list.
int get();
double get();

// (c) legal, the parameter type is different and return type is changed
int *reset(int *);
double *reset(double *);
```

## Exercises Section 6.5.1

### Exercise 6.40

-----

> Which, if either, of the following declarations are errors? Why?

```c++
// (a) no error.
int ff(int a, int b = 0, int c = 0);

// (b) errors, missing default argument on parameter 'wd', 'bckgrnd'.
char *init(int ht = 24, int wd, char bckgrnd);
```

### Exercise 6.41

-----

> Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?

```c++
char *init(int ht, int wd = 80, char bckgrnd = ' ');

// (a) illegal, missing the necessary parameter `ht`.
init();

// (b) legal
init(24, 10);

// (c) legal, unlikely to match the programmer's intent.
// '*' is convert to int, then assigned to `wd`.
init(14, '*');
```

### Exercise 6.42

-----

> Given the second parameter of `make_plural` (6.3.2, p.224) a default argument of `s`. Test your program by printing singular and plural versions of the words `success` and `failure`.

[code](./exec_42.cc)

## Exercises Section 6.5.2

### Exercise 6.43

-----

> Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.

```c++
// (a) header, it's a define of inline function.
inline bool eq(const BigInt&, const BigInt&) {...}

// (b) header, it's a declaration.
void putValues(int *arr, int size);
```

### Exercise 6.44

-----

> Rewrite the `isShorter` function from 6.2.2(p. 211) to be `inline`.

```c++
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
```

### Exercise 6.45

-----

> Review the programs you've written for the earlier exercises and decide whether they should be defined as `inline`. If so, do so. If not, explain why they should not be `inline`.

For example, the function `arrPtr` in [Exercise 6.38](#Exercise-638) and `make_plural` in [Exercise 6.42](#Exercise-642) should be defined as `inline`. But the function func in [Exercise 6.4](#Exercise-64) shouldn't. It is not that small and it's only being called once. Hence, it will probably not expand as `inline`.

### Exercise 6.46

-----

> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No. Because `std::string::size()` is not a `constexpr` function and `s1.size() < s2.size()` is not a constant expression.

## Exercises Section 6.5.3

### Exercise 6.47

-----

> Revise the program you wrote in the exercises in 6.3.2(p. 228) that used recursion to print the contents of a `vector` to conditionally print information about its execution. For example, you might print the size of the `vector` on each call. Compile and run the program with debugging turned on and again with it turned off.

[code](./exec_47.cc)

### Exercise 6.48

-----

> Explain what this loop does and whether it is a good use of `assert`.

```c++
string s;
while (cin >> s && s != sought) {} 
assert(cin);
```

This loop let user input a word all the way until the word is sought.

It isn't a good use of `assert`. because if user begin to input a word, the `cin` would be always have content. so the `assert` would be always `true`. It is meaningless. using `assert(s == sought)` is better.

## Exercises Section 6.6

### Exercise 6.49

-----

> What is a candidate function? What is a viable function?

**candidate function**:  
Set of functions that are considered when resolving a function call. (all the functions with the name used in the call for which a declaration is in scope at the time of the call.)

**viable function**:  
Subset of the candidate functions that could match a given call. It have the same number of parameters as arguments to the call, and each argument type can be converted to the corresponding parameter type.

### Exercise 6.50

-----

> Given the declarations for `f` from page 242, list the viable function, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

```c++
// ambiguous
f(2.56, 42)

// best match: void f(int);
f(42)

// best match: void f(int, int);
f(42, 0)

// best match: void f(double, double = 3.14);
f(2.56, 3.14)
```

### Exercise 6.51

-----

> Write all four versions fo `f`. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

[code](./exec_51.cc)

## Exercises Section 6.6.1

### Exercise 6.52

-----

> Given the following declarations,  
> `void manip(int, int);`  
> `double dobj;`
> What is the rank(6.6.1, p.245) of each conversion in the following calls?

```c++
// 3. Match through a promotion
manip('a', 'z');

// 4. Match through an arithmetic conversion.
manip(55.4, dobj)
```

### Exercise 6.53

-----

> Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

```c++
// (a)
int calc(int&, int&);
int calc(const int&, const int&);

// (b)
int calc(char*, char*);
int calc(const char*, const char*);

// (c) illegal
int calc(char*, char*);
int calc(char* const, char* const);
```

## Exercises Section 6.7

### Exercise 6.54

-----

> Write a declaration for a function that takes two `int` parameters and return an `int`, and declare a `vector` whose elements have this function pointer type.

```c++
int func(int, int);
std::vector<decltype(func) *> v;
```

### Exercise 6.55

-----

> Write four functions that add, subtract, multiply, and divide two `int` values. Store pointers to these values in your `vector` from the previous exercise.

```c++
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

std:vector<int (*)(int, int)> {add, subtract, multiply, divide};
```

### Exercise 6.56

-----

> Call each element in the `vector` and print their result.

[code](./exec_56.cc)
