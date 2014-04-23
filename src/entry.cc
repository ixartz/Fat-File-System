#include "entry.hh"

Entry::Entry(Fat* fs, char* p)
  : fs_(fs)
{
  read_string(short_filename_, p);

  memcpy(attr_, p + 11, SizeOfArray(attr_));
  memcpy(ntres_, p + 12, SizeOfArray(ntres_));
  memcpy(crt_time_tenth_, p + 13, SizeOfArray(crt_time_tenth_));

  /* Get creation time */
  memcpy(crt_time_, p + 14, SizeOfArray(crt_time_));
  crt_time_hour_ = calculate_hour(crt_time_);
  crt_time_minute_ = calculate_month(crt_time_);
  crt_time_second_ = calculate_second(crt_time_);

  /* Get creation date */
  memcpy(crt_date_, p + 16, SizeOfArray(crt_date_));
  crt_date_year_ = calculate_year(crt_date_);
  crt_date_month_ = calculate_month(crt_date_);
  crt_date_day_ = calculate_day(crt_date_);

  /* Get last access date */
  memcpy(lst_acc_date_, p + 18, SizeOfArray(lst_acc_date_));
  lst_acc_date_year_ = calculate_year(lst_acc_date_);
  lst_acc_date_month_ = calculate_month(lst_acc_date_);
  lst_acc_date_day_ = calculate_day(lst_acc_date_);

  memcpy(fst_clus_hi_, p + 20, SizeOfArray(fst_clus_hi_));

  /* Get time of last write */
  memcpy(wrt_time_, p + 22, SizeOfArray(wrt_time_));
  wrt_time_hour_ = calculate_hour(wrt_time_);
  wrt_time_minute_ = calculate_minute(wrt_time_);
  wrt_time_second_ = calculate_second(wrt_time_);

  /* Get date of last write */
  memcpy(wrt_date_, p + 24, SizeOfArray(wrt_date_));
  wrt_date_year_ = calculate_year(wrt_date_);
  wrt_date_month_ = calculate_month(wrt_date_);
  wrt_date_day_ = calculate_day(wrt_date_);

  memcpy(fst_clus_lo_, p + 26, SizeOfArray(fst_clus_lo_));
  calculate_first_cluster();

  memcpy(file_size_array_, p + 28, SizeOfArray(file_size_array_));
  file_size_ = array_to_int(file_size_array_);
}

unsigned char Entry::calculate_year(unsigned char date[2])
{
  return (date[1] & 0xFE) >> 1;
}

unsigned char Entry::calculate_month(unsigned char date[2])
{
  return ((date[1] & 0x01) << 3) | date[0] >> 5;
}

unsigned char Entry::calculate_day(unsigned char date[2])
{
  return date[0] & 0x1F;
}

unsigned char Entry::calculate_hour(unsigned char date[2])
{
  return (date[1] & 0xF8) >> 3;
}

unsigned char Entry::calculate_minute(unsigned char date[2])
{
  return ((date[1] & 0x07) << 3) | (date[0] & 0xE0) >> 5;
}

unsigned char Entry::calculate_second(unsigned char date[2])
{
  return date[0] & 0x1F;
}

std::ostream& Entry::print_date(std::ostream& ostr,
                                unsigned char year,
                                unsigned char month,
                                unsigned char day)
{
  return ostr << 1980 + year << "-"
              << promote_int(month) << "-"
              << promote_int(day);
}

std::ostream& Entry::print_time(std::ostream& ostr,
                                unsigned char hour,
                                unsigned char minute,
                                unsigned char second)
{
  return ostr << promote_int(hour) << ":"
              << promote_int(minute) << ":"
              << promote_int(second);
}

void Entry::print_creation_date(std::ostream& ostr)
{
  Entry::print_date(ostr, crt_date_year_, crt_date_month_, crt_date_day_);
}

void Entry::print_last_access_date(std::ostream& ostr)
{
  Entry::print_date(ostr, lst_acc_date_year_, lst_acc_date_month_, lst_acc_date_day_);
}

void Entry::print_write_date(std::ostream& ostr)
{
  Entry::print_date(ostr, wrt_date_year_, wrt_date_month_, wrt_date_day_);
}

void Entry::print_creation_time(std::ostream& ostr)
{
  Entry::print_time(ostr, crt_time_hour_, crt_time_minute_, crt_time_second_);
}

void Entry::print_write_time(std::ostream& ostr)
{
  Entry::print_time(ostr, wrt_time_hour_, wrt_time_minute_, wrt_time_second_);
}

void Entry::calculate_first_cluster()
{
  unsigned int hi_ = array_to_int(fst_clus_hi_);
  unsigned int lo_ = array_to_int(fst_clus_lo_);
  fst_clus_ = hi_ << 8 | lo_;
}

void Entry::load_content(Input& in, unsigned int offset)
{
  char* p = in.get_buffer_at(fs_->get_sec_per_clus_()
                             * (fst_clus_ - fs_->get_root_clus_()) + offset,
                             fs_->get_nb_Byte_sector());

  memcpy(content_, p, SizeOfArray(content_));
}

std::ostream& operator<<(std::ostream& ostr, Entry& e)
{
  ostr << "Short filename: [" << e.short_filename_ << "]"
       << " - Size: " << e.file_size_
       << " - First cluster: " << e.fst_clus_ << std::endl
       << "  Created: ";
  e.print_creation_date(ostr);

  ostr << " ";
  e.print_creation_time(ostr);

  ostr << " - Modified: ";
  e.print_write_date(ostr);

  ostr << " ";
  e.print_write_time(ostr);

  ostr << " - Last opened: ";
  e.print_last_access_date(ostr);

  ostr << std::endl
       << "--------File content--------" << std::endl
       << e.content_ << std::endl
       << "--------END--------";

  return ostr;
}
