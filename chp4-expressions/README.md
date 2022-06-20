# Expressions

## Exercises Section 4.1.2

### Exercise 4.1

-----

> What is the value returned by `5 + 10 * 20 / 2`?

The value is 105.

### Exercise 4.2

-----

> Using Table 4.12 (p.166), parenthesize the following expressions to indicate the order in which the operands are grouped.

```c++
* vec.begin() //=> *(vec.begin())
* vec.begin() + 1 //=> (*(vec.begin())) + 1
```

## Exercises Section 4.1.3

### Exercise 4.3

-----

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

No, such design can not improve performance significantly, but it can make bugs very trick to handle.

## Exercises Section 4.2

### Exercise 4.4

-----

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.

```c++
((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);
```

[code](./exec_4.cc)

### Exercise 4.5

-----

> Determine the result of the following expressions.

```c++
-30 * 3 + 21 / 5;   // -86
-30 + 3 * 21 / 5;   // -18
30 / 3 * 21 % 5;    // 0
-30 / 3 * 21 % 4;   // -2
```

### Exercise 4.6

-----

> Write an expression to determine whether an `int` value is even or odd.

```c++
!(i % 2)
```

When `i` is even, the expression equals `true`, and vice versa.

[code](./exec_6.cc)

### Exercise 4.7

> What dose overflow mean? Show three expressions that will overflow.

from the book:

> Some arithmetic expressions yield undefined results. Some of these undefined expressions are due to the nature of mathematics-for example, division by zero. Others are undefined due to the nature of computers-for example, due to overflow. Overflow happens when a value is computed that is outside the range of values that the type can represent.

```c++
short svalue = 32767; ++svalue; // -32768
unsigned uivalue = 0; --uivalue;  // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
```

## Exercises Section 4.3

### Exercise 4.8

> Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

from the book:

> The logical `AND` and `OR` operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as **short-circuit evaluation**.

- logical `AND`: the second operand is evaluated if and only if the left side is `true`.
- logical `OR`: the second operand is evaluated if and only if the left side is `false`.
- logical `==`: undefined.

### Exercise 4.9

-----

> Explain the behavior of the condition in the following `if`:

```c++
const char *cp = "Hello World";
if (cp && *cp)
```

`cp` is a `const char` pointer, and it's not `nullptr`, true.
`*cp` is a `char`: H, and it's nonzero value, true.
So, the condition is true.

### Exercise 4.10

-----

> Write the condition for a `while` loop that would read `int`s form the standard input and stop when the value read is equal to `42`.

```c++
int i = 0;
while (cin >> i && i != 42){}
```

### Exercise 4.11

-----

> Write an expression that test four values, `a`, `b`, `c`, and `d`, and ensure that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.

```c++
a > b && b > c && c > d;
```

### Exercise 4.12

-----

> Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.

It is equivalent to `i != (j < k)`. So if `j < k` is true, this expression equals to `i != 0`. Else, it equals to `i != 1`.

## Exercises Section 4.4

### Exercise 4.13

-----

> What are the values of `i` and `d` after each assignment?

```c++
int i; double d;

d = i = 3.5;    // i = 3, d = 3.0
i = d = 3.5;    // d = 3.5, i = 3
```

### Exercise 4.14

-----

> Explain what happens in each of the `if` tests:

```c++
if (42 = i)     // compile error: expression is not assignable.
if (i = 42)     // i = 42, then it is nonzero, true.
```

### Exercise 4.15

-----

> The following assignment is illegal. Why? How would you correct it?

```c++
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

`pi` is a pointer to `int`, can't assigned to `int` from type `int *`

correct:

```c++
double dval; int ival; int *pi;
dval = ival = 0;
pi = 0;
```

### Exercise 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why?
> Rewrite the expressions as you think they should be.

```c++
if (p = getPtr() != 0)
if (i = 1024)
```

correct:

```c++
if ((p = getPtr()) != 0)
if (i == 1024)
```

## Exercises Section 4.5

### Exercise 4.17

> Explain the difference between prefix and postfix increment.

- `++i` will increment the value of `i`, and then return the incremented value.
- `i++` will increment the value of `i`, and then return the original value that `i` hold before being incremented.

### Exercise 4.18

-----

> What would happen if the `while` loop on page 148 that prints the elements from a `vector` used the prefix increment operator?

It will print from the second element and dereference `v.end()` at last, which is a undefined behavior.

### Exercise 4.19

-----

> Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?

```c++
ptr != 0 && *ptr++  // check pointer is not an nullptr, and then check the pointer value.
ival++ && ival // check ival and then check ival + 1
vec[ival++] <= vec[ival] // incorrect, the "<=" operator don't promise the order of evaluation.

// correct:
vec[ival] <= vec[ival + 1];
ival++;
```

## Exercises Section 4.6

### Exercise 4.20

-----

> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren't legal are in error.

```c++
*iter++;    // legal, return the char "iter" point to and increment iter.
(*iter)++;  // illegal, "*iter" is a string, can't "++".
*iter.empty()   // illegal, dereference has a lower precedence than dot. So this expression equals to "*(iter.empty())", but iter has no member empty().
iter->empty()   // legal, indicate whether the string iter point to is empty.
++*iter;    // illegal, (*iter) is string, have no increment.
iter++->empty() //return iter->empty(), then ++iter.
```

## Exercises Section 4.7

### Exercise 4.21

-----

> Write a program to use a conditional operator to find the elements in a `vector<int>` that that have odd value and double the value of each such element.

[code](./exec_21.cc)

### Exercise 4.22

-----

> Extend the program that assigned high pass, pass and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more `if` statements. Which version do you think is easier to understand and why?

[code](./exec_22.cc)

### Exercise 4.23

-----

> The following expression fails to compile due to operator precedence. Using Table 4.12(p. 166), explain why it fails. How would you fix it?

```c++
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s";
```

Operator precedence: `?:` < `=`, fix it:

```c++
string p1 = s + (s[size() - 1] == 's' ? "" : "s");
```

### Exercise 4.24

-----

> Our program that distinguished between high pass, pass and fail depended on the fact that the condition operator is right associative. Describe hwo that operator would be evaluated if the operator were left associative.

It would be like:

```c++
final_grade = ((grade > 90) ? "high pass" : (grade < 60>)) ? "fail" : "pass";
```

## Exercises Section 4.8

### Exercise 4.25

-----

> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in witch `q` has the bit pattern `01110001`?

`~'q'` means `~00000000_00000000_00000000_01110001`, the result is `11111111_11111111_11111111_10001110`. Then `<<6`, results in `11111111_11111111_11100011_1000000`. The final value in decimal is `-7296`.

### Exercise 4.26

-----

> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

The C++ standard does not specify the size of integral types in bytes, but it specifies minimum ranges they must be able to hold. The minimum range of unsigned int is 0 to 65535. Since some implementations use only the minimum 16 bits for unsigned int, this could cause undefined behavior.

### Exercise 4.27

-----

> What is the result of each of these expressions?

```c++
unsigned long ul1 = 3, ul2 = 7;
// ul1 -> 0000...0011, ul2 -> 0000...0111
ul1 & ul2   // -> 0000...0011 = 3
ul1 | ul2   // -> 0000...0111 = 7
ul1 && ul2  // -> true
ul1 || ul2  // -> true
```

## Exercises Section 4.9

### Exercise 4.28

-----

> Write a program ot print the size of each the built-in types.

[code](./exec_28.cc)

### Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run teh program. Is the output what you expected? If not, figure out why.

```c++
int x[10]; int *p = x;
cout << sizeof(x) / sizeof(*x) << endl; // 10
cout << sizeof(p) / sizeof(*p) << endl; // 2
```

[code](./exec_29.cc)

### Exercise 4.30

-----

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:

```c++
sizeof x + y        // (sizeof x) + y
sizeof p->mem[i]    // sizeof(p->mem[i])
sizeof a < b        // (sizeof a) < b
sizeof f()          // sizeof the return type of "f()", except the return type is "void"
```

## Exercises Section 4.10

### Exercise 4.31

-----

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

So, it's just a good habits. And there are no changes if we have to be made to use the postfix versions.

### Exercise 4.32

-----

> Explain the following loop.

```c++
constexpr int size = 5;
int ia[size] = {1, 2, 3, 4 ,5};
for (int *ptr = ia, ix = 0;
     ix != size && ptr != ia + size;
     ++ix, ++ptr) {} 
```

`ptr` and `ix` have the same function. The former use a pointer, and the latter use the index of array. we use the loop to through the array.(just choose one from `ptr` and `ix`)

### Exercise 4.33

-----

> Using Table 4.12 (p. 166) explain what the following expression does:

```c++
someValue ? ++x, ++y : --x, --y;
```

If `someValue` is `true`, then `++x`, and the result is `y`, if `someValue` is `false`, then `--x`, and the result is `--y`.

## Exercises Section 4.11.1

### Exercise 4.34

-----

> Given the variable definitions in this section, explain what conversions take place in the following expression:

```c++
if (fval)           // fval: float -> bool
dval = fval + ival; // ival: int -> float; (fval + ival): float -> double
dval + ival * cval  // cval: char -> int; (ival * cval): int -> double
```

> Remember that you may need to consider the associativity of the operators.

### Exercise 4.35

-----

> Given the following definitions,

```c++
char cval; int ival; unsigned int ui;
float fval; double dval;
```

> identify the implicit type conversions, if any, taking place:

```c++
cval = 'a' + 3;             // 'a': char -> int; 'a' + 3: int -> char
fval = ui - ival * 1.0;     // ival: int -> double; ui: unsigned int -> double; ui - ival * 1.0: double -> int 
dval = ui * fval;           // ui: unsigned int -> float; ui * fval: float -> double
cval = ival + fval + dval;  // ival: int -> float; ival + fval: float -> double; ival + fval + dval: double -> char
```

## Exercises Section 4.11.3

### Exercise 4.36

-----

> Assuming `i` is an `int` and `d` is a `double` write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.

```c++
i *= static_cast<int>(d);
```

### Exercise 4.37

-----

> Rewrite each of the following old-style casts to use a named cast:

```c++
int i; double d; const string *ps; char *pc; void *pv;

pv = (void*)ps;     // pv = const_cast<void*>ps;
i = int(*pc);       // i = static_cast<int>(*pc);
pv = &d;            // pv = static_cast<void*>(&d);
pc = (char*) pv;    // pv = static_cast<char*>pv;
```

### Exercise 4.38

-----

> Explain the following expression:

```c++
double slope = static_cast<double>(j / i);
```

j/i is an int(by truncation), then converted to double and assigned to slope.
