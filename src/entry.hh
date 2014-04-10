#ifndef ENTRY_HH
# define ENTRY_HH

# include <string.h>
# include "tool-array.hh"

class Entry
{
public:
  /// Constructor.
  Entry(char* p);

private:
  char short_filename_[11];

  friend std::ostream& operator<<(std::ostream& ostr, Entry& e);
};

/// Print entry
std::ostream& operator<<(std::ostream& ostr, Entry& e);

#endif /* !ENTRY_HH */
