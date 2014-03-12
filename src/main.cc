#include <string.h>
#include "input.hh"

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
    char* path = strcat(getenv("PWD"), "/");
    Input d(path, argv[1]);
    d.read();
    d.mount();
    d.print();
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " INPUT-FILE" << std::endl;
  }

  return 0;
}
