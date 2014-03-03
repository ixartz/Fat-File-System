#ifndef DISK_HXX
# define DISK_HXX

template <typename A>
typename std::enable_if<std::is_array<A>::value, size_t>::type
SizeOfArray(const A __attribute__((__unused__))& a)
{
  return std::extent<A>::value;
}

template <typename A, int Size>
void PrintArray(A const(& array)[Size])
{
  for(int i = 0; i < Size; i++)
    std::cout << array[i];
}

#endif /* !DISK_HXX */
