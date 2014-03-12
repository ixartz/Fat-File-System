#include "fat.hh"

Fat::Fat(char* p)
{
  memcpy(jmp_boot_, p, SizeOfArray(jmp_boot_));
  memcpy(oem_identifier_, p + 0x3, SizeOfArray(oem_identifier_));
  memcpy(nb_Byte_sector_, p + 0x11, SizeOfArray(nb_Byte_sector_));
}

void Fat::print()
{
  std::cout << "Jump instruction: ";
  PrintArray(jmp_boot_);

  std::cout << "OEM identifier: ";
  PrintArray(oem_identifier_);

  std::cout << "Number of Byte per sector: ";
  PrintArray(nb_Byte_sector_);
}
