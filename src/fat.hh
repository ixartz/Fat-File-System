#ifndef FAT_HH
# define FAT_HH

# include <string.h>
# include "tool-array.hh"

class Fat
{
public:
  /// Constructor.
  Fat(char* p);

  /**
   * \brief Print Fat32 information.
   */
  void print();
private:
  /* BPB structure */
  /// Jump instruction to boot code.
  unsigned char jmp_boot_[3];
  /// OEM (original equipment manufacturer) identifier.
  char oem_identifier_[8];
  /// Number of Byte per sector.
  unsigned char nb_Byte_sector_[2];
  unsigned char sec_per_lus_[1];
  unsigned char rsvd_sec_cnt_[2];
  unsigned char num_fats_[1];
  unsigned char root_ent_cnt_[2];
  unsigned char tot_sec16_[2];
  unsigned char media_[1];
  unsigned char fatz16_[2];
  unsigned char sec_per_trk_[2];
  unsigned char num_heads_[2];
  unsigned char hidd_sec_[4];
  unsigned char tot_sec32_[4];

  /* FAT32 structure */
  unsigned char fatz32_[4];
  unsigned char ext_flags_[2];
  unsigned char fs_ver_[2];
  unsigned char root_clus_[4];
  unsigned char fs_info_[2];
  unsigned char bk_boot_sec_[2];
  unsigned char reserved_[12];
  unsigned char drv_num_[1];
  unsigned char reserved1_[1];
  unsigned char boot_sig_[1];
  unsigned char vol_id_[4];
  unsigned char vol_lab_[11];
  unsigned char fil_sys_type_[8];
};

#endif /* !FAT_HH */
