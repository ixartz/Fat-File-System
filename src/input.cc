#include "input.hh"

Input::Input(char* path, char* filename)
  : filename_(strcat(path, filename))
  , file_(filename_, std::ios::binary | std::fstream::in)
{
  if (!file_.is_open())
  {
    /* TODO: Need an exception here */
    std::cerr << "Error while opening the file \"" << filename << "\"" << std::endl;
  }
}

Input::~Input()
{
  file_.close();
}

char* Input::get_next_buffer()
{
  file_.read(buffer_, SizeOfArray(buffer_));
  return buffer_;
}

char* Input::get_buffer_at(unsigned int location, unsigned int cluster_size)
{
  file_.seekg(cluster_size * location);
  return get_next_buffer();
}
