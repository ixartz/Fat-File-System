#include <string.h>
#include "input.hh"
#include "mbr.hh"

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
    char* path = strcat(getenv("PWD"), "/");
    Mbr disk(path, argv[1]);
    disk.print();
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " INPUT-FILE" << std::endl;
  }

  return 0;
}
