#ifndef INPUT_HH
# define INPUT_HH

# include <string>
# include <iostream>
# include <fstream>
# include <string.h>
# include "mbr.hh"
# include "tool-array.hh"

class Input
{
public:
  /// Constructor.
  Input(char* path, char* filename);
  /// Destructor.
  ~Input();

  /**
   * \brief Read the hard disk drive.
   */
  void read();

  /**
   * \brief Print HDD information.
   */
  void print();

  /**
   * \brief Mount all disk partitions.
   */
  void mount();

  /// Return buffer.
  char* get_buffer();

private:
  /// Buffer of the input file.
  char buffer_[512];

  /// Name of the input file.
  std::string filename_;
  /// The stream to read.
  std::fstream file_;

  /// Master Boot Record.
  Mbr* mbr_ = nullptr;
};

#endif /* !INPUT_HH */
