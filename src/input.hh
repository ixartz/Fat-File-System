#ifndef INPUT_HH
# define INPUT_HH

# include <string>
# include <iostream>
# include <fstream>
# include <string.h>
# include "tool-array.hh"

class Input
{
public:
  /// Constructor.
  Input(char* path, char* filename);
  /// Destructor.
  ~Input();

  /// Return buffer for the next sector.
  char* get_next_buffer();

  /// Return buffer located at sector number 'location'
  char* get_buffer_at(int location);

private:
  /// Buffer of the input file.
  char buffer_[512];

  /// Name of the input file.
  std::string filename_;
  /// The stream to read.
  std::fstream file_;
};

#endif /* !INPUT_HH */
