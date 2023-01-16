#include <cpptoolkit/test/macros.h>
#include <cpptoolkit/test/tool/TestFailException.h>
#include <cpptoolkit/test/utest.h>

#include <cassert>
#include <cstdio>

#define MCR(a)           \
  void a();              \
  class _a_a {           \
   public:               \
    void Exec() { a(); } \
  };                     \
  void a()

MCR(my_function) {
  std::cout << "Function: " << __func__ << std::endl;
  std::cout << "File: " << __FILE__ << std::endl;
  std::cout << "Line: " << __LINE__ << std::endl;
}

class Tester {
 public:
  Tester() { std::cout << "this is the Tester constructor" << std::endl; }
  void call() { std::cout << "Hello b!" << std::endl; };
} instnce;

void ThrowFunction() {
  throw cpptoolkit::test::tool::TestFailException("ThrowFunction", "just fail",
                                                   "main.cpp");
}

int main() {
  _a_a a;
  a.Exec();

  try {
    ThrowFunction();
  }
  catch (const cpptoolkit::test::tool::TestFailException &ex) {
    std::cout << "Function:\t" << ex.function() << std::endl;
    std::cout << "Why:\t\t" << ex.why() << std::endl;
    std::cout << "Where:\t\t" << ex.where() << std::endl;
  }
}
