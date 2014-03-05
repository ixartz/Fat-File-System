#ifndef PARTITION_HH
# define PARTITION_HH

# include <iostream>
# include <string.h>
# include "tool-array.hh"

class Partition
{
public:
  /// Constructor.
  Partition(char* p);

  /**
   * \brief Print partition information.
   */
  void print();
private:
  unsigned char boot_flag_[1];
  /// Beginning of partition.
  unsigned char CHS_begin_[3];
  /// Type of the partition
  unsigned char type_[1];
  /// End of partition.
  unsigned char CHS_end_[3];
  /// Partition address (relative offset to the MBR)
  unsigned char LBA_offset_array_[4];
  unsigned int LBA_offset_ = 0;
  /// Number of sector
  unsigned char nb_sector_[4];
};

#endif /* !PARTITION_HH */
