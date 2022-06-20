# Classes

## Exercises Section 7.1.1

### Exercise 7.1

-----

> Write a version of the transaction-processing program from 1.6(p. 24) using the `Sales_data` class you defined for the exercises in 2.6.1(p. 72)

[code](./exec_1.cc)

## Exercises Section 7.1.2

### Exercise 7.2

-----

> Add the `combine` and `isbn`members to the `Sales_data` class you wrote for the exercises in 2.6.2(p. 76).

[Sales_data](./Sales_data.h)

### Exercise 7.3

-----

> Revise your transaction-processing program from [7.1.1](#exercises-section-711)(p. 256) to use these members.

[code](./exec_3.cc)

### Exercise 7.4

-----

> Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subsequent exercises will incrementally add features to this class.

[Person](./person.h)

### Exercise 7.5

-----

> Provide operations in your `Person` class to return the name and address, Should these functions be `const`? Explain your choice.

[Person](./person.h)

These functions should be `const`. They don't modify the members.

## Exercises Section 7.1.3

### Exercise 7.6

-----

> Define your own versions of the `add`, `read`, and `print` functions.

[Sales_data](./Sales_data.h)

### Exercise 7.7

-----

> Rewrite the transaction-processing program you wrote for the exercises in [7.1.2](#exercises-section-712)(p. 260) to use these new function.

[code](./exec_7.cc)

### Exercise 7.8

-----

> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

Define `read`'s `Sales_data` parameter as plain reference since it's intended to change the revenue's value.

Define `print`'s `Sales_data` parameter as a reference to `const` since it isn't intended to change any member's value of this object.

### Exercise 7.9

-----

> Add operations to read and print `Person` objects to the code you wrote for the exercises in [7.1.2](#exercises-section-712)(p. 260).

[Person](./person.h)

### Exercise 7.10

-----

> What does the condition in the following `if` statement do?

```c++
if (read(read(cin, data1), data2))
```

the condition of the `if` statement would read two `Sales_data` object at one time.

## Exercises Section 7.1.4

### Exercise 7.11

-----

> Add constructors to your `Sales_data` class and write a program to use each of the constructors.

[Sales_data](./Sales_data.h)  
[code](./exec_11.cc)

### Exercise 7.12

-----

> Move the definition of the `Sales_data` constructor that takes an `istream` into the body of the `Sales_data` class.

[Sales_data](./Sales_data.h)

### Exercise 7.13

-----

> Rewrite the program from page 255 to use the `istream` constructor.

[code](./exec_13.cc)

### Exercise 7.14

-----

> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

```c++
Sales_data() {
    bookNo = "";
    units_sold = 0;
    revenue = 0.0;
}
```

### Exercise 7.15

-----

> Add appropriate constructors to your `Person` class.

[Person](./person.h)

## Exercises Section 7.2

### Exercise 7.16

-----

> What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

There are no restrictions on how often an access specifier may appear.The specified access level remains in effect until the next access specifier or the end of the class body.

The members which are accessible to all parts of the program should define after a `public` specifier.

The members which are accessible to the member functions of the class but are not accessible to code that uses the class should define after a `private` specifier.

### Exercise 7.17

-----

> What, if any, are the differences between using `class` or `struct`?

The only difference between using class and using struct to define a class is the default access level. (class : private, struct : public)

### Exercise 7.18

-----

> What is encapsulation? Why is it useful?

encapsulation is the separation of implementation from interface. It hides the implementation details of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class).

Important advantages:

- User code cannot inadvertently corrupt the state of an encapsulation object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

### Exercise 7.19

-----

> Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

public include: constructors, getName(), getAddress(). private include: name, address.
the interface should be defined as public, the data shouldn't expose to outside of the class.

## Exercises Section 7.2.1

### Exercise 7.20

-----

> When are friends useful? Discuss the pros and cons of using friends.

`friend` is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.

Pros:

- the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
- you can access all the nonpublic members conveniently.
- sometimes, more readable to the users of class.

Cons:

- lessens encapsulation and therefore maintainability.
- code verbosity, declarations inside the class, outside the class.

### Exercise 7.21

-----

> Update your `Sales_data` class to hide its implementation. The programs you've written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that still work.

[Sales_data](./Sales_data.h)

### Exercise 7.22

-----

> Update your `Person` class to hide its implementation.

[Person](./person.h)

## Exercises Section 7.3.1

### Exercise 7.23

-----

> Write your own version of the `Screen` class.

[Screen](./screen.h)

### Exercise 7.24

-----

> Give your `Screen` class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

[Screen](./screen.h)

### Exercise 7.25

-----

> Can `Screen` safely rely on the default versions of copy and assignment? If so, why? If not, why not?

Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have vector or string members.  
The class below which used only built-in type and strings can rely on the default version of copy and assignment.

### Exercise 7.26

-----

Define `Sales_data:: avg_price` as an `inline` function.

## Exercise Section 7.3.2

### Exercise 7.27

> Add the `move`, `set`, and `display` operations ot your version of `Screen`. Test your class by executing the following type:

```c++
Screen myScreen(5, 5, 'X');
```

[Screen](./screen.h)  
[code](./exec_27.cc)

### Exercise 7.28

-----

> What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`?

The second call to `display` couldn't print `#` among the output, cause the call to set would change the temporary copy, not `myScreen`.

### Exercise 7.29

-----

> Revise your `Screen` class so that `move`, `set`, and `display` functions return `Screen` and check your prediction from the previous exercise.

```text
#with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

### Exercise 7.30

-----

> It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access member.

Pros

- more explicit
- less scope for misreading
- can use the member function parameter which name is same as the member name.

```c++
void setAddr(const std::string &addr) { this->addr = addr; }
```

Cons

- more to read

- sometimes redundant

```c++
  std::string getAddr() const { return this->addr; } // unnecessary
```

## Exercises Section 7.3.3

### Exercise 7.31

-----

> Define a pair fo classes `X` and `Y`, in which `X` has a pointer ot `Y`, and `Y` has an object of type `X`.

```c++
class Y;

class X {
    Y *y = nullptr;
}

class Y {
    X x;
}
```

## Exercises Section 7.3.4

### Exercise 7.32

-----

> Define your own versions of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`.

[Window_mgr](./window_mgr.h)

## Exercises Section 7.4

### Exercise 7.33

-----

> What would happen if we gave `Screen` a `size` member defined as follows? Fix any problems you identify.

```c++
pos Screen::size() const {
    return height * width;
}
```

error: unknown type name 'pos'

Fix:

```c++
Screen::pos Screen::size() const {
    return height * width;
}
```

## Exercises Section 7.4.1

### Exercise 7.34

-----

> What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

There is an error in

```c++
dummy_fcn(pos height)
           ^
Unknown type name 'pos'
```

### Exercise 7.35

-----

> Explain the following code, indicating which definition fo `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.

```c++
typedef string Type;
Type initVal();             // use string
class Exercise {
   public:
    typedef double Type;
    Type setVal(Type);      // use double
    Type initVal();         // use double
   private:
    int val;
};

Type Exercise::setVal(Type parm) {  // first use string, second use double.
    val = parm + initVal();         // use Exercise::initVal()
    return val;
}
```

fix:

```c++
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

## Exercise Section 7.5.1

### Exercise 7.36

-----

> The following initializer is in error. Identify and fix the problem.

```c++
struct X {
    X(int i, int j): base(i), rem(base % j) {}
    int rem, base;
}
```

Fix:

```c++
// `rem` is initialized first, the `base` in (`base % j`) is undefined.
struct X {
    // Use parameter `i` to initialize rem, rather than member `base`.
    X(int i, int j): base(i), rem(i % j) {}
    int rem, base;
}
```

### Exercise 7.37

-----

> Using the version of `Sales_data` from this section, determine which construct is used to initialize each of the following variable and list the values of the data members in each object:

```c++
Sales_data first_item(cin);             // Sales_data(std::istream &is)

int main() {
    Sales_data next;                    // Sales_data(std::string s = "")
    Sales_data last("9-999-99999-9");   // Sales_data(std::string s = "")
}
```

### Exercise 7.38

-----

> We might want to supply `cin` as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses `cin` as a default argument.

```c++
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

### Exercise 7.39

-----

> Would it be legal for both the constructor that takes a `string` and the one that takes an `istream&` to have default arguments? If not, why not?

illegal. cause the call of overloaded 'Sales_data()' is ambiguous.

### Exercise 7.40

-----

> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.

```text
(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
```

Date:

```c++
class Date {
   public:
    Data(unsigned year, unsigned month, unsigned day):
        year_(year), month_(month), day_(day) {}

    Date(std::istream &is) { is >> year_ >> month_ >> day_; }

   private:
    unsigned year_;
    unsigned month_;
    unsigned day_;
}
```

## Exercises Section 7.5.2

### Exercise 7.41

-----

> Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that print a message whenever it si executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

[Sales_data](./Sales_data.h)

### Exercise 7.42

-----

> For the class you wrote for [exercise 7.40](#exercise-740) int 7.5.1(p. 291), decide whether any of the constructors might ues delegation. If so, write teh delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

```c++
class Date {
   public:
    Data(unsigned year, unsigned month, unsigned day):
        year_(year), month_(month), day_(day) {}

    Data() : Data(1971, 1, 1) {}

    Date(std::istream &is) : Data() { is >> year_ >> month_ >> day_; }


   private:
    unsigned year_;
    unsigned month_;
    unsigned day_;
}
```

## Exercises Section 7.5.3

### Exercise 7.43

-----

> Assume we have a class named `NoDefault` that has a constructor that takes an `int`, but has no default constructor. Define a class `C` that has a member of type `NoDefault`. Define the default constructor for `C`.

```c++
class NoDefault {
   public:
    NoDefault(int m) : mem(m) {}
   private:
    int mem;
}

class C {
   public:
    C() : nd(0) {}
   private:
    NoDefault nd;
}
```

### Exercise 7.44

-----

> Is the following declaration legal? If not, why not?

```c++
vector<NoDefault> vec(10);
```

illegal, cause there are ten elements, each would be default initialized. But no default initializer for the temporary object.

### Exercise 7.45

-----

> What if we defined the `vector` in the previous exercise to hold objects of type C?

No problem. cause `C` have the default constructor.

### Exercise 7.46

-----

> Which, if any, of the following statements are untrue? Why?  
> (a) A class must provide at least one constructor.  
> (b) A default constructor is a constructor with an empty parameter list.  
> (c) If there are no meaningful default values for a class, the class should not provide a default constructor.  
> (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

- (a) **untrue**. The compiler generate synthesized default constructor for class defined no constructor.
- (b) **untrue**. A default constructor is a constructor that is used if no initializer is supplied.What's more, A constructor that supplies default arguments for all its parameters also defines the default constructor.
- (c) **untrue**. The class should provide.
- (d) **untrue**. Only if our class does not explicitly define any constructors, the compiler will implicitly define the default constructor for us

## Exercises Section 7.5.4

### Exercise 7.47

-----

> Explain whether the `Sales_data` constructor that takes a `string` should be `explicit`. What are the benefits fo making the constructor `explicit`? What are the drawbacks?

Whether the conversion of a `string` to `Sales_data` is desired depends on how we think our users will use the conversion. In this case, it might be okay. The `string` in `null_book` probably represents a nonexistent ISBN.

Benefits:

- Prevent the use of a constructor in a context that requires an implicit conversion.
- We can define a constructor which is used only with the direct form of initialization.

Drawbacks:

- Meaningful only on constructors that can be called with a single argument.

### Exercise 7.48

-----

> Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions

```c++
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

> What happens if the `Sales_data` constructors are `explicit`?

Both are nothing happened.

### Exercise 7.49

-----

> For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:

```c++
// ok
Sales_data &combine(Sales_data);

// Error, no matching function for call to 'Sales_data::combine(std::string&)' (`std::string&` can not convert to `Sales_data` type.)  
Sales_data &combine(Sales_data&);

// The trailing const mark can't be put here, as it forbids any mutation on data members. This conflicts with combine's semantics.
Sales_data &combine(const Sales_data&) const;
```

### Exercise 7.50

-----

> Determine whether any of your `Person` class constructors should be explicit.

[Person](./person.h)

### Exercise 7.51

-----

> Why do you think `vector` defines its single-argument constructor as `explicit`, but `string` does not?

Such as a function like that:

```c++
int getSize(const std::vector<int>&);
```

if `vector` has not defined its single-argument constructor as `explicit`. we can use the function like:

```c++
getSize(34);
```

What is this mean? It's very confused.

But the `std::string` is different. In ordinary, we use `std::string` to replace `const char *`(the C language). so when we call a function like that:

```c++
void setYourName(std::string); // declaration.
setYourName("test"); // just fine.
```

## Exercise Section 7.5.5

### Exercise 7.52

-----

> Using our first version of `Sales_data` from 2.6.1(p. 72), explain the following initialization. Identify and fix any problems.

```c++
Sales_data item = {"978-0590353403", 25, 15.99};
```

The aggregate class should have no in-class initializers.

```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## Exercise Section 7.5.6

### Exercise 7.53

-----

> Define your own version of `Debug`.

```c++
class Debug {
public:
    constexpr Debug(bool b = true) : rt(b), io(b), other(b) { }
    constexpr Debug(bool r, bool i, bool o) : rt(r), io(i), other(o) { }
    constexpr bool any() { return rt || io || other; }
    
    void set_rt(bool b) { rt = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }
    
private:
    bool rt;        // runtime error
    bool io;        // I/O error
    bool other;     // the others
};
```

### Exercise 7.54

-----

> Should the members of `Debug` that begin with `set_` be declared as constexpr? If not, why?

In C++11, constexpr member functions are implicitly const, so the "set_xx" functions, which will modify data members, cannot be declared as constexpr. In C++14, this property no longer holds, so constexpr is suitable.

### Exercise 7.55

-----

> Is the `Data` class from 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

not a literal class.

`std::string` is not a literal type.

## Exercises Section 7.6

### Exercise 7.56

-----

> What is a `static` class member?

A class member that is associated with the class, rather than with individual objects of the class type.

> What are the advantages of `static` member?

Each object can no need to store a common data. And if the data is changed, each object can use the new value.  

> How do they differ from ordinary members?

- A static data member can have incomplete type.
- We can use a static member as a default argument.

### Exercise 7.57

-----

> Write your own version of the Account class.

```c++
class Account {
   public:
    static double rate() { return interestRate; }
    static void rate(double);
   private:
    static constexpr int period = 30;
    double daily_tbl[period];
};
```

### Exercise 7.58

-----

> Which, if any, of the following `static` data member declarations and definitions are errors? Explain why.

```c++
// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
}

// example.c
#include "example.h"

double Example::rate;
vector<double> Example::vec;

class Account {
public:
    static double rate() { return interestRate; }
    static void rate(double);
private:
    static constexpr int period = 30;
    double daily_tbl[period];
}
```

Fixed:

```c++
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
