#ifndef FSINFO_HH
# define FSINFO_HH

# include <string.h>
# include "tool-array.hh"

class Fsinfo
{
public:
  /// Constructor.
  Fsinfo(char* p);

  /**
   * \brief Print File System Information Sector.
   */
  void print();

private:
  /// Number of free clusters.
  unsigned char nb_free_cluster_[4];
  /// Cluster that was most recently allocated.
  unsigned char cluster_most_allocated_[4];
};

#endif /* !FSINFO_HH */
