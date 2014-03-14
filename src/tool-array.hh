#ifndef TOOL_ARRAY_HH
# define TOOL_ARRAY_HH

# include <iostream>
# include <cstddef>
# include <type_traits>

/**
 * \brief Calculate the size of C-like array
 */
template <typename A>
typename std::enable_if<std::is_array<A>::value, size_t>::type
SizeOfArray(const A& a);

/**
 * \brief Print the content of C-like array
 */
template <typename A, int Size>
void PrintArray(const A (& array)[Size]);

/**
 * \brief Convert from little endian Array to unsigned int
 */
template <typename A, int Size>
unsigned int array_to_int();

# include "tool-array.hxx"

#endif /* !TOOL_ARRAY_HH */
