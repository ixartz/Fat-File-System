#include "disk.hh"

Disk::Disk(char* path, char* filename)
  : filename_(strcat(path, filename))
  , file_(filename_, std::ios::binary | std::fstream::in)
{
  if (!file_.is_open())
  {
    std::cerr << "Error while opening the file \"" << filename << "\"" << std::endl;
  }
}

void Disk::read_mbr()
{
  file_.read(buffer_, SizeOfArray(buffer_));
  memcpy(jmp_boot_, buffer_, SizeOfArray(jmp_boot_));
  memcpy(oem_identifier_, buffer_ + 0x3, SizeOfArray(oem_identifier_));
  memcpy(nb_Byte_sector_, buffer_ + 0x11, SizeOfArray(nb_Byte_sector_));

  read_mbr_partition_();
}

void Disk::read_mbr_partition_()
{
  char* partition_start = buffer_ + 0x1BE; /* 0x1BE = 446 */

  for (int i = 0; i < 4; ++i)
  {
    partition_vect_.push_back(Partition(partition_start + i * 0x10));
  }
}

void Disk::print_mbr()
{
  std::cout << "Print FAT disk header" << std::endl;
  std::cout << "Jump instruction: ";
  PrintArray(jmp_boot_);

  std::cout << "OEM identifier: ";
  PrintArray(oem_identifier_);

  std::cout << "Number of Byte per sector: ";
  PrintArray(nb_Byte_sector_);
  std::cout << std::endl;

  for (auto it: partition_vect_)
  {
    it.print();
    std::cout << std::endl;
  }
}
