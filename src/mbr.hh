#ifndef MBR_HH
# define MBR_HH

# include <vector>
# include "input.hh"
# include "partition.hh"

class Mbr
{
public:
  /// Constructor.
  Mbr(char* path, char* filename);

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
  void read_partition_();

  /**
   * \brief Mount all disk partitions.
   */
  void mount_partition_();

  /// Partition vector.
  std::vector<Partition*> partition_vect_;

  /// Input.
  Input in_;
};

#endif /* !MBR_HH */
