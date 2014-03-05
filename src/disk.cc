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
}

void Disk::print_mbr()
{
  std::cout << "Print FAT disk header" << std::endl;
  PrintArray(jmp_boot_);
}
