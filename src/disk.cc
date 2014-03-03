#include "disk.hh"

Disk::Disk(const char* filename)
  : filename_(filename)
  , file_(filename, std::ios::binary)
{

}

void Disk::read_meta()
{
  read_jump_boot_();
}

void Disk::read_jump_boot_()
{
}

void Disk::print_meta()
{
  std::cout << "Print FAT disk header" << std::endl;
  PrintArray(jmp_boot_);
}
