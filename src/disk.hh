#ifndef DISK_HH
# define DISK_HH

# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include <string.h>
# include "partition.hh"

class Disk
{
public:
  /// Constructor.
  Disk(char* path, char* filename);

  /**
   * \brief Read FAT32 Master Boot Record (MBR) where LBA = 0.
   */
  void read_mbr();

  /**
   * \brief Print MBR information.
   */
  void print_mbr();
private:
  /**
   * \brief Read all partitions.
   */
  void read_mbr_partition_();

  /// Buffer of the input file.
  char buffer_[512];
  /// Jump instruction to boot code.
  unsigned char jmp_boot_[3];
  /// OEM (original equipment manufacturer) identifier.
  unsigned char oem_identifier_[8];
  /// Number of Byte per sector.
  unsigned char nb_Byte_sector_[2];


  /// Partition vector.
  std::vector<Partition*> partition_vect_;

  /// Name of the input file.
  std::string filename_;
  /// The stream to read.
  std::fstream file_;
};

#endif /* !DISK_HH */
