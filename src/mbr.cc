#include "mbr.hh"

Mbr::Mbr(char* sector)
{
  read_partition_(sector);
}

void Mbr::read_partition_(char* sector)
{
  char* partition_start = sector + 0x1BE; /* 0x1BE = 446 */
  Partition* p;
  unsigned char signature[2];

  /* By default, the MBR contains 4 partitions */
  for (int i = 0; i < 4; ++i)
  {
    p = new Partition(partition_start + i * 0x10);
    partition_vect_.push_back(p);
  }

  memcpy(signature, sector + 0x1FE, SizeOfArray(signature));

  if (signature[0] != 0x55 && signature[1] != 0xAA)
  {
    /* TODO: Need an exception here */
  }
}

void Mbr::print()
{
  std::cout << "Print MBR information" << std::endl;
  std::cout << "----------------------" << std::endl;

  for (auto it: partition_vect_)
  {
    it->print();
    std::cout << "----------------------" << std::endl;
  }
}

std::vector<Partition*>& Mbr::get_partition_vect()
{
  return partition_vect_;
}
