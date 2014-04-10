#include "partition.hh"

Partition::Partition(char* p)
{
  memcpy(boot_flag_, p, SizeOfArray(boot_flag_));
  memcpy(CHS_begin_, p + 1, SizeOfArray(CHS_begin_));
  memcpy(type_, p + 4, SizeOfArray(type_));
  memcpy(CHS_end_, p + 5, SizeOfArray(CHS_end_));
  memcpy(LBA_offset_array_, p + 8, SizeOfArray(LBA_offset_array_));
  LBA_offset_ = array_to_int(LBA_offset_array_);

  memcpy(nb_sector_, p + 12, SizeOfArray(nb_sector_));
}

Partition::~Partition()
{
  if (fs)
    delete fs;
}

void Partition::print()
{
  std::cout << "Partition" << std::endl;
  std::cout << "Boot flag: ";
  PrintArray(boot_flag_);
  std::cout << "Beginning of partition in CHS: ";
  PrintArray(CHS_begin_);
  std::cout << "Type of partition: ";
  PrintArray(type_);
  std::cout << "End of partition in CHS: ";
  PrintArray(CHS_end_);
  std::cout << "Relative LBA address: "
            << LBA_offset_ << " in hex: ";
  PrintArray(LBA_offset_array_);
  std::cout << "Number of sector: ";
  PrintArray(nb_sector_);

  if (fs)
  {
    std::cout << std::endl;
    fs->print();
    std::cout << std::endl;
    fsinfo->print();
  }
}

void Partition::mount(Input& in)
{
  if (type_[0] == 0x0B && LBA_offset_ > 0)
  {
    /* Fat32 partition. */
    char* p = in.get_buffer_at(get_LBA_offset());
    fs = new Fat(p);
    char* p_fsinfo = in.get_buffer_at(get_LBA_offset() + 1);
    fsinfo = new Fsinfo(p_fsinfo);
  }
}

unsigned int Partition::get_LBA_offset()
{
  return LBA_offset_;
}
