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
}

void Input::read()
{
  file_.read(buffer_, SizeOfArray(buffer_));
  mbr_ = new Mbr(buffer_);
}

void Input::print()
{
  mbr_->print();
}
