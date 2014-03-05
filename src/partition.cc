#include "partition.hh"

Partition::Partition(char* p)
{
  memcpy(boot_flag_, p, SizeOfArray(boot_flag_));
  memcpy(CHS_begin_, p + 1, SizeOfArray(CHS_begin_));
}

void Partition::print()
{
  std::cout << "Partition" << std::endl;
  PrintArray(boot_flag_);
  PrintArray(CHS_begin_);
}
