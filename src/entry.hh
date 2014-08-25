#ifndef ENTRY_HH
# define ENTRY_HH

# include <sstream>
# include <string.h>
# include "fat.hh"
# include "input.hh"
# include "tool-array.hh"

class Entry
{
public:
  /// Constructor.
  Entry(Fat* fs, char* p);

  /// Indicates that writes to the file should fail.
  static constexpr unsigned char ATTR_READ_ONLY = 0x01;

  /// Indicates that normal directory listings should not show this file.
  static constexpr unsigned char ATTR_HIDDEN = 0x02;

  /// Indicates that this is an operating system file.
  static constexpr unsigned char ATTR_SYSTEM = 0x04;

  /// Indicates the name of this file is actually the label for the volume.
  static constexpr unsigned char ATTR_VOLUME_ID = 0x08;

  /// Indicates that this file is actually a container for other files.
  static constexpr unsigned char ATTR_DIRECTORY = 0x10;

  /// Backup utilities may use this attribute.
  static constexpr unsigned char ATTR_ARCHIVE = 0x20;

  /// The file is actually part of the long name entry for some other file.
  static constexpr unsigned char ATTR_LONG_NAME = ATTR_READ_ONLY
                                                  | ATTR_HIDDEN
                                                  | ATTR_SYSTEM
                                                  | ATTR_VOLUME_ID;

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
   * \brief Indicates whether the entry is a long name or not
   */
  bool has_long_name();

  /**
   * \brief Indicates whether the entry which is a long name is the last
   */
  bool is_last_long_name();

  /**
   * \brief Calculate the last long name
   */
  unsigned char last_seq_long_name();

  /**
   * \brief Indicates whether the entry is deleted or not
   */
  bool is_deleted();

  /**
   * \brief Indicates whether the entry is a directory or not.
   */
  bool is_directory();

  /**
   * \brief Print the date file was created.
   */
  void print_creation_date(std::ostream& ostr);

  /**
   * \brief Print the date of last read or write.
   */
  void print_last_access_date(std::ostream& ostr);

  /**
   * \brief Print the date of last write
   */
  void print_write_date(std::ostream& ostr);

  /**
   * \brief Print the time file was created.
   */
  void print_creation_time(std::ostream& ostr);

  /**
   * \brief Print the time of last write
   */
  void print_write_time(std::ostream& ostr);

  /**
   * \brief Print all attribute.
   */
  void print_attribute(std::ostream& ostr);

  /**
   * \brief Calculate the first cluster number.
   */
  void calculate_first_cluster();

  /**
   * \brief Load content file.
   */
  void load_content(Input& in, unsigned int offset);

private:
  Fat* fs_;

  char short_filename_[9];
  unsigned char first_byte_;
  char extension_[4];
  unsigned char attr_array_[1];
  unsigned char attr_;
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
  unsigned char fst_clus_hi_[2];
  unsigned char wrt_time_[2];
  unsigned char wrt_time_hour_;
  unsigned char wrt_time_minute_;
  unsigned char wrt_time_second_;
  unsigned char wrt_date_[2];
  unsigned char wrt_date_year_;
  unsigned char wrt_date_month_;
  unsigned char wrt_date_day_;
  unsigned char fst_clus_lo_[2];
  unsigned int fst_clus_ = 0;
  unsigned char file_size_array_[4];
  unsigned int file_size_ = 0;

  std::string content_;

  friend std::ostream& operator<<(std::ostream& ostr, Entry& e);
};

/// Print entry
std::ostream& operator<<(std::ostream& ostr, Entry& e);

#endif /* !ENTRY_HH */
