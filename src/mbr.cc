#include "mbr.hh"

Mbr::Mbr(char* sector)
{
  read_partition_(sector);
}

void Mbr::read_partition_(char* sector)
{
  char* partition_start = sector + 0x1BE; /* 0x1BE = 446 */
  Partition* p;

  /* By default, the MBR contains 4 partitions */
  for (int i = 0; i < 4; ++i)
  {
    p = new Partition(partition_start + i * 0x10);
    partition_vect_.push_back(p);
  }
}

void Mbr::print()
{
  std::cout << "Print MBR information" << std::endl << std::endl;

  for (auto it: partition_vect_)
  {
    it->print();
    std::cout << std::endl;
  }
}
