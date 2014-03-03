#include "disk.hh"

int main()
{
  Disk d("test");
  d.read_meta();
  d.print_meta();

  return 0;
}
