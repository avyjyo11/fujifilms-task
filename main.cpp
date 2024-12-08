#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

int main(int argc, char *argv[]) {

  printf("Hello world!");

  // std::string foo = "I am foo";
  // std::string bar = "I am bar";


  // std::string fooRef = foo; // This creates a reference to foo.
  // fooRef += ". Hi!"; // Modifies foo through the reference
  // std::cout << fooRef << '\n'; // Prints "I am foo. Hi!"

  // std::cout << &fooRef << '\n'; // Prints the address of foo
  // // Doesn't reassign "fooRef". This is the same as "foo = bar", and
  // //   foo == "I am bar"
  // // after this line.
  // fooRef = bar;
  // std::cout << &fooRef << '\n'; // Still prints the address of foo
  // std::cout << fooRef << '\n';  // Prints "I am bar"
  // std::cout << foo << '\n';
  // printf("Helloo wrold~");

  // try {
  //     // Do not allocate exceptions on the heap using _new_.
  //     throw std::runtime_error("A problem occurred");
  // }

  // // Catch exceptions by const reference if they are objects
  // catch (const std::exception& ex)
  // {
  //     std::cout << ex.what();
  // }
  return 0;
}