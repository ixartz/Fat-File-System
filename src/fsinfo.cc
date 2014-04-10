#include "fsinfo.hh"

Fsinfo::Fsinfo(char* p)
{
  unsigned char signature_first[4];
  unsigned char signature_second[4];
  unsigned char signature_boot[2];
  memcpy(signature_first, p, SizeOfArray(signature_first));

  if (signature_first[0] != 0x52 &&
      signature_first[1] != 0x52 &&
      signature_first[2] != 0x61 &&
      signature_first[3] != 0x41)
  {
    /* TODO: Need an exception here */
  }

  memcpy(signature_second, p + 0x1E4, SizeOfArray(signature_second));

  if (signature_second[0] != 0x72 &&
      signature_second[1] != 0x72 &&
      signature_second[2] != 0x41 &&
      signature_second[3] != 0x61)
  {
    /* TODO: Need an exception here */
  }

  memcpy(nb_free_cluster_, p + 0x1E8, SizeOfArray(nb_free_cluster_));
  memcpy(cluster_most_allocated_, p + 0x1EC, SizeOfArray(cluster_most_allocated_));

  memcpy(signature_boot, p + 0x1FE, SizeOfArray(signature_boot));

  if (signature_boot[0] != 0x55 &&
      signature_boot[1] != 0xAA)
  {
    /* TODO: Need an exception here */
  }
}

void Fsinfo::print()
{
  std::cout << "File System Information Sector" << std::endl;

  std::cout << "Number of free cluster: ";
  PrintArray(nb_free_cluster_);
  std::cout << "Cluster that was most recently allocated: ";
  PrintArray(cluster_most_allocated_);
}
