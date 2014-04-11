#ifndef ENTRY_HH
# define ENTRY_HH

# include <string.h>
# include "tool-array.hh"

class Entry
{
public:
  /// Constructor.
  Entry(char* p);

  /**
   * \brief Calculate the year from a date.
   */
  static unsigned char calculate_year(unsigned char date[2]);

private:
  char short_filename_[11];
  unsigned char attr_[1];
  unsigned char ntres_[1];
  unsigned char crt_time_tenth_[1];
  unsigned char crt_time_[2];
  unsigned char crt_date_[2];
  unsigned char crt_date_year_;
  unsigned char lst_acc_date_[2];
  unsigned char fst_clus_hi_array_[2];
  unsigned int fst_clus_hi_ = 0;
  unsigned char wrt_time_[2];
  unsigned char wrt_date_[2];
  unsigned char fst_clus_lo_array_[2];
  unsigned int fst_clus_lo_ = 0;
  unsigned char file_size_array_[4];
  unsigned int file_size_ = 0;

  friend std::ostream& operator<<(std::ostream& ostr, Entry& e);
};

/// Print entry
std::ostream& operator<<(std::ostream& ostr, Entry& e);

#endif /* !ENTRY_HH */
