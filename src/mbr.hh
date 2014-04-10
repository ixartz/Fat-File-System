#ifndef MBR_HH
# define MBR_HH

# include <vector>
# include "partition.hh"

class Mbr
{
public:
  /// Constructor.
  Mbr(char* in);

  /**
   * \brief Read the Master Boot Record (MBR) where LBA = 0.
   */
  void read();

  /**
   * \brief Print the MBR information.
   */
  void print();

  /// Return partition vector
  std::vector<Partition*>& get_partition_vect();

private:
  /**
   * \brief Read partition table.
   */
  void read_partition_(char* sector);

  /// Partition vector.
  std::vector<Partition*> partition_vect_;
};

#endif /* !MBR_HH */
