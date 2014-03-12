#include "input.hh"

Input::Input(char* path, char* filename)
  : filename_(strcat(path, filename))
  , file_(filename_, std::ios::binary | std::fstream::in)
{
  if (!file_.is_open())
  {
    std::cerr << "Error while opening the file \"" << filename << "\"" << std::endl;
  }
}

Input::~Input()
{
  file_.close();

  if (mbr_)
    delete mbr_;
}

void Input::read()
{
  file_.read(buffer_, SizeOfArray(buffer_));
  mbr_ = new Mbr(buffer_);
}

void Input::mount()
{
  for (auto it: mbr_->get_partition_vect())
  {
    file_.seekg(0x200 * it->get_LBA_offset());
    file_.read(buffer_, SizeOfArray(buffer_));
    it->mount(buffer_);
  }
}

void Input::print()
{
  mbr_->print();
}
