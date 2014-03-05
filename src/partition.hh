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
  /// Beginning of partition
  unsigned char CHS_begin_[3];
};

#endif /* !PARTITION_HH */
