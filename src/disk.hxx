#ifndef DISK_HXX
# define DISK_HXX

template <typename A>
typename std::enable_if<std::is_array<A>::value, size_t>::type
SizeOfArray(const A __attribute__((__unused__))& a)
{
  return std::extent<A>::value;
}

template <typename A, int Size>
void PrintArray(const A (& array)[Size])
{
  for(int i = 0; i < Size; i++)
    printf("%02X", array[i]);

  printf("\n");
}

#endif /* !DISK_HXX */
