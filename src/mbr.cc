#include "mbr.hh"

Mbr::Mbr(char* path, char* filename)
  : filename_(strcat(path, filename))
  , file_(filename_, std::ios::binary | std::fstream::in)
{
  if (!file_.is_open())
  {
    std::cerr << "Error while opening the file \"" << filename << "\"" << std::endl;
  }
}

void Mbr::read()
{
  file_.read(buffer_, SizeOfArray(buffer_));

  read_partition_();
}

void Mbr::read_partition_()
{
  char* partition_start = buffer_ + 0x1BE; /* 0x1BE = 446 */
  Partition* p;

  for (int i = 0; i < 4; ++i)
  {
    p = new Partition(partition_start + i * 0x10);

    partition_vect_.push_back(p);
  }
}

void Mbr::print()
{
  std::cout << "Print MBR information" << std::endl << std::endl;

  for (auto it: partition_vect_)
  {
    it->print();
    std::cout << std::endl;
  }
}
