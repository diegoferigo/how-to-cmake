#include "Lib1.h"
#include "Lib3.h"

int main(int argc, char const *argv[]) {
  std::cout << argv[0] << ": ";
  printHelloFromLib1();
  std::cout << argv[0] << ": ";
  printHelloFromLib3();
  return 0;
}
