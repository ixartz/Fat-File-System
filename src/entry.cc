#include "entry.hh"

Entry::Entry(char* p)
{
  memcpy(short_filename_, p, SizeOfArray(short_filename_));
}

std::ostream& operator<<(std::ostream& ostr, Entry& e)
{
  return ostr << std::string(e.short_filename_);
}
