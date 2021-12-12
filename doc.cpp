/* Beginning C++17 From Novice chapter 7 page 242

The string header of the C++ Standard Library defines 
the std::string type.

The string type is defined by a class 
(or to be more precise, a class template).

Because the string type is defined in the string header, 
you must include this header when you’re using string objects.

    #include <string>

The string type name is defined within the std namespace, 
so you’d need a using declaration to use 
the type name in its unqualified form.

    using namespace std;

STRING OBJECTS--------------------------------------------

An object of type string contains a sequence of characters 
of type char, which can be empty

    std::string empty; // An empty string

In this case, empty contains a string that has no characters 
and so it has ZERO LENGTH.

Initialize a string object with a string literal

    std::string s = "Hello, world!";
    std::string proverb {"Many a mickle makes a muckle."};

C-style compatibility----------------------------------

Internally, the character array encapsulated by a string object 
is always terminated by a null character as well. 
This is done to assure compatibility with the numerous 
existing functions that expect C-style strings.

convert a std::string object to a C-style string
The first is by calling its c_str() member function 
(short for C-string):

    //This conversion results in a C-string of type const char*
    const char* proverb_c_str = proverb.c_str();

Because it’s const, this pointer cannot be used to
modify the characters of the string, only to access them.

the string’s data() function, which starting from 
C++17 evaluates to a non-const char* pointer1
(prior to C++17, data() resulted in a const char* pointer as well):

    char* proberb_data = proverb.data();

String object properties--------------------------------

length() returns the number of characters in the string

    std::cout << "The proverb has " << proverb.length() << " characters.\n";
-- start in page 243

*/

/* Operator Overloading
Beginning C++17 From Novice Chapter 12 page 469

You’ll learn how to add support for operators such as 
add and subtract to your classes
so that they can be applied to objects. 

Operator overloading enables you to write 
member functions that enable the basic operators 
to be applied to class objects.
*/