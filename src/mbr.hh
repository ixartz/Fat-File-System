#ifndef MBR_HH
# define MBR_HH

# include <vector>
# include "partition.hh"

class Mbr
{
public:
  /// Constructor.
  Mbr(char* path);

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
  void read_partition_(char* sector);

  /// Partition vector.
  std::vector<Partition*> partition_vect_;
};

#endif /* !MBR_HH */
