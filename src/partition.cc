#include "partition.hh"

Partition::Partition(char* p)
{
  memcpy(boot_flag_, p, SizeOfArray(boot_flag_));
  memcpy(CHS_begin_, p + 1, SizeOfArray(CHS_begin_));
  memcpy(type_, p + 4, SizeOfArray(type_));

  memcpy(CHS_end_, p + 5, SizeOfArray(CHS_end_));
  memcpy(LBA_offset_array_, p + 8, SizeOfArray(LBA_offset_array_));

  /* Convert to unsigned int from little endian */
  for (int i = 3; i >= 0; --i)
    LBA_offset_ = (LBA_offset_ << 8) | LBA_offset_array_[i];

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
  std::cout << "Relative LBA address: ";
  std::cout << LBA_offset_ << " in hex: ";
  PrintArray(LBA_offset_array_);
  std::cout << "Number of sector: ";
  PrintArray(nb_sector_);
}

void Partition::mount()
{
  if (type_[0] != 0x0B && LBA_offset_ > 0)
  {
    /* Fat32 partition. */
    //fs = new Fat();
  }
}

unsigned char Partition::get_LBA_offset()
{
  return LBA_offset_;
}
