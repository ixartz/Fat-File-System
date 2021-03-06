#ifndef TOOL_ARRAY_HXX
# define TOOL_ARRAY_HXX

template <typename A>
typename std::enable_if<std::is_array<A>::value, size_t>::type
SizeOfArray(const A __attribute__((__unused__))& a)
{
  return std::extent<A>::value;
}

template <typename A, int Size>
void PrintArray(const A (& array)[Size])
{
  for (int i = 0; i < Size; i++)
    printf("%02X", array[i]);

  printf("\n");
}

template <typename A, int Size>
unsigned int array_to_int(const A (& array)[Size])
{
  unsigned int res = 0;

  for (int i = Size - 1; i >= 0; --i)
    res = (res << (sizeof(A) * 8)) | array[i];

  return res;
}

template <typename A, int Size>
void read_string(A (& array)[Size], char* p)
{
  memcpy(array, p, Size - 1);
  array[Size - 1] = 0;
}

template <typename T>
auto promote_int(T i) -> decltype(+i)
{
  return +i;
}

#endif /* !TOOL_ARRAY_HXX */
