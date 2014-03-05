#ifndef DISK_HH
# define DISK_HH

# include <string>
# include <iostream>
# include <fstream>
# include <cstddef>
# include <type_traits>
# include <string.h>

class Disk
{
public:
  /// Constructor.
  Disk(char* path, char* filename);

  /**
   * \brief Read FAT32 Master Boot Record (MBR) where LBA = 0
   */
  void read_mbr();

  /**
   * \brief Print MBR information.
   */
  void print_mbr();
private:
  /// The buffer of the input file
  char buffer_[512];
  /// Jump instruction to boot code
  unsigned char jmp_boot_[3];

  /// The name of the input file
  std::string filename_;
  /// The stream to read
  std::fstream file_;
};

/**
 * \brief Calculate the size of C-like array
 */
template <typename A>
typename std::enable_if<std::is_array<A>::value, size_t>::type
SizeOfArray(const A& a);

/**
 * \brief Print the content of C-like array
 */
template <typename A, int Size>
void PrintArray(const A (& array)[Size]);

# include "disk.hxx"

#endif /* !DISK_HH */
