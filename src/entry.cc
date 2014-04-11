#include "entry.hh"

Entry::Entry(char* p)
{
  memcpy(short_filename_, p, SizeOfArray(short_filename_));
  memcpy(attr_, p + 11, SizeOfArray(attr_));
  memcpy(ntres_, p + 12, SizeOfArray(ntres_));
  memcpy(crt_time_tenth_, p + 13, SizeOfArray(crt_time_tenth_));
  memcpy(crt_time_, p + 14, SizeOfArray(crt_time_));
  memcpy(crt_date_, p + 16, SizeOfArray(crt_date_));
  crt_date_year_ = calculate_year(crt_date_);
  memcpy(lst_acc_date_, p + 18, SizeOfArray(lst_acc_date_));
  memcpy(fst_clus_hi_array_, p + 20, SizeOfArray(fst_clus_hi_array_));
  fst_clus_hi_ = array_to_int(fst_clus_hi_array_);
  memcpy(wrt_time_, p + 22, SizeOfArray(wrt_time_));
  memcpy(wrt_date_, p + 24, SizeOfArray(wrt_date_));
  memcpy(fst_clus_lo_array_, p + 26, SizeOfArray(fst_clus_lo_array_));
  fst_clus_lo_ = array_to_int(fst_clus_lo_array_);
  memcpy(file_size_array_, p + 28, SizeOfArray(file_size_array_));
  file_size_ = array_to_int(file_size_array_);
}

unsigned char Entry::calculate_year(unsigned char date[2])
{
  return date[0] & 0xFE >> 1;
}

std::ostream& operator<<(std::ostream& ostr, Entry& e)
{
  return ostr << "Short filename: [" << std::string(e.short_filename_) << "]"
              << " - Size: " << e.file_size_
              << " - First cluster: " << e.fst_clus_hi_
              << " - Last cluster: " << e.fst_clus_lo_ << std::endl
              << "  Created: " << +e.crt_date_year_
              << " - Modified: - Last opened: ";
}
