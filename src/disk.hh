#ifndef DISK_HH
# define DISK_HH

# include <string>
# include <iostream>
# include <fstream>
# include <cstddef>
# include <type_traits>

class Disk
{
public:
  Disk(const char* filename);
  void read_meta();
  void print_meta();
private:
  void read_jump_boot_();

  char jmp_boot_[3];

  std::string filename_;
  std::fstream file_;
};

template <typename A>
typename std::enable_if<std::is_array<A>::value, size_t>::type
SizeOfArray(const A& a);

template <typename A, int Size>
void PrintArray(A const(& array)[Size]);

# include "disk.hxx"

#endif /* !DISK_HH */
