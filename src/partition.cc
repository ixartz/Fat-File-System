#include "partition.hh"

Partition::Partition(char* p)
{
  memcpy(boot_flag_, p, SizeOfArray(boot_flag_));
  memcpy(CHS_begin_, p + 1, SizeOfArray(CHS_begin_));
  memcpy(type_, p + 4, SizeOfArray(type_));

  /* Partitions up to 2047GB. */
  //TODO
  /*
  if (type_[0] != 0x0B)
    throw new std::Exception();
  */

  memcpy(CHS_end_, p + 5, SizeOfArray(CHS_end_));
  memcpy(LBA_offset_, p + 8, SizeOfArray(LBA_offset_));
  memcpy(nb_sector_, p + 12, SizeOfArray(nb_sector_));
}

void Partition::print()
{
  std::cout << "Partition" << std::endl;
  std::cout << "Boot flag: ";
  PrintArray(boot_flag_);
  std::cout << "Beginning of partition in CHS: ";
  PrintArray(CHS_begin_);
  std::cout << "Type of partition: ";
  PrintArray(type_);
  std::cout << "End of partition in CHS: ";
  PrintArray(CHS_end_);
  std::cout << "Relative LBA address";
  PrintArray(LBA_offset_);
  std::cout << "Number of sector: ";
  PrintArray(nb_sector_);
}
