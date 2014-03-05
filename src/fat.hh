#ifndef FAT_HH
# define FAT_HH

# include <string.h>
# include "tool-array.hh"

class Fat
{
public:
  /// Constructor.
  Fat(char* p);

  /**
   * \brief Print Fat32 information.
   */
  void print();
private:
  /// Jump instruction to boot code.
  unsigned char jmp_boot_[3];
  /// OEM (original equipment manufacturer) identifier.
  unsigned char oem_identifier_[8];
  /// Number of Byte per sector.
  unsigned char nb_Byte_sector_[2];
};

#endif /* !FAT_HH */
