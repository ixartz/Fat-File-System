#ifndef ENTRY_HH
# define ENTRY_HH

# include <sstream>
# include <string.h>
# include "tool-array.hh"

class Entry
{
public:
  /// Constructor.
  Entry(char* p);

  /**
   * \brief Calculate count of years from 1980
   * (valid value range 0–127 inclusive (1980–2107)).
   */
  static unsigned char calculate_year(unsigned char date[2]);

  /**
   * \brief Calculate the month of year from date.
   */
  static unsigned char calculate_month(unsigned char date[2]);

  /**
   * \brief Calculate the day of month from date.
   */
  static unsigned char calculate_day(unsigned char date[2]);

  /**
   * \brief Calculate the hour from time.
   */
  static unsigned char calculate_hour(unsigned char date[2]);

  /**
   * \brief Calculate the minute from time.
   */
  static unsigned char calculate_minute(unsigned char date[2]);

  /**
   * \brief Calculate the second from time.
   */
  static unsigned char calculate_second(unsigned char date[2]);

  /**
   * \brief Print a date.
   */
  static std::ostream& print_date(std::ostream& ostr,
                                  unsigned char year,
                                  unsigned char month,
                                  unsigned char day);

  /**
   * \brief Print a time.
   */
  static std::ostream& print_time(std::ostream& ostr,
                                  unsigned char hour,
                                  unsigned char minute,
                                  unsigned char second);

  /**
   * \brief Get the date file was created.
   */
  void print_creation_date(std::ostream& ostr);

  /**
   * \brief Get the date of last read or write.
   */
  void print_last_access_date(std::ostream& ostr);

  /**
   * \brief Get the date of last write
   */
  void print_write_date(std::ostream& ostr);

  /**
   * \brief Get the time file was created.
   */
  void print_creation_time(std::ostream& ostr);

  /**
   * \brief Get the time of last write
   */
  void print_write_time(std::ostream& ostr);

private:
  char short_filename_[11];
  unsigned char attr_[1];
  unsigned char ntres_[1];
  unsigned char crt_time_tenth_[1];
  unsigned char crt_time_[2];
  unsigned char crt_time_hour_;
  unsigned char crt_time_minute_;
  unsigned char crt_time_second_;
  unsigned char crt_date_[2];
  unsigned char crt_date_year_;
  unsigned char crt_date_month_;
  unsigned char crt_date_day_;
  unsigned char lst_acc_date_[2];
  unsigned char lst_acc_date_year_;
  unsigned char lst_acc_date_month_;
  unsigned char lst_acc_date_day_;
  unsigned char fst_clus_hi_array_[2];
  unsigned int fst_clus_hi_ = 0;
  unsigned char wrt_time_[2];
  unsigned char wrt_time_hour_;
  unsigned char wrt_time_minute_;
  unsigned char wrt_time_second_;
  unsigned char wrt_date_[2];
  unsigned char wrt_date_year_;
  unsigned char wrt_date_month_;
  unsigned char wrt_date_day_;
  unsigned char fst_clus_lo_array_[2];
  unsigned int fst_clus_lo_ = 0;
  unsigned char file_size_array_[4];
  unsigned int file_size_ = 0;

  friend std::ostream& operator<<(std::ostream& ostr, Entry& e);
};

/// Print entry
std::ostream& operator<<(std::ostream& ostr, Entry& e);

#endif /* !ENTRY_HH */
