#ifndef MBR_HH
# define MBR_HH

# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include "partition.hh"

class Mbr
{
public:
  /// Constructor.
  Mbr(char* path, char* filename);

  /**
   * \brief Read the Master Boot Record (MBR) where LBA = 0.
   */
  void read();

  /**
   * \brief Print the MBR information.
   */
  void print();
private:
  /**
   * \brief Read partition table.
   */
  void read_partition_();

  /// Buffer of the input file.
  char buffer_[512];

  /// Partition vector.
  std::vector<Partition*> partition_vect_;

  /// Name of the input file.
  std::string filename_;
  /// The stream to read.
  std::fstream file_;
};

#endif /* !MBR_HH */
