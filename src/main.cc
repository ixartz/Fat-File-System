#include "disk.hh"

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
    char* path = strcat(getenv("PWD"), "/");
    Disk d(path, argv[1]);
    d.read_mbr();
    d.print_mbr();
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " INPUT-FILE" << std::endl;
  }

  return 0;
}
