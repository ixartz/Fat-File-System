#ifndef FAT_HH
# define FAT_HH

# include <string.h>
# include "tool-array.hh"

/**
 * \brief Fat boot sector
 */
class Fat
{
public:
  /// Constructor.
  Fat(char* p);

  /**
   * \brief Print Fat32 information.
   */
  void print();

  /// Return number of Byte per sector
  unsigned int get_nb_Byte_sector();

  /// Return number of reserved sector
  unsigned int get_rsvd_sec_cnt();

  /// Return number sector per Fat
  unsigned int get_fatz32();

private:
  /* BPB structure */
  /// Jump instruction to boot code.
  unsigned char jmp_boot_[3];
  /// OEM (original equipment manufacturer) identifier.
  char oem_identifier_[8];
  /// Number of Byte per sector.
  unsigned char nb_Byte_sector_array_[2];
  unsigned int nb_Byte_sector_ = 0;
  unsigned char sec_per_lus_[1];
  unsigned char rsvd_sec_cnt_array_[2];
  unsigned int rsvd_sec_cnt_ = 0;
  unsigned char num_fats_array_[1];
  unsigned int num_fats_;
  unsigned char root_ent_cnt_[2];
  unsigned char tot_sec16_[2];
  unsigned char media_[1];
  unsigned char fatz16_[2];
  unsigned char sec_per_trk_[2];
  unsigned char num_heads_[2];
  unsigned char hidd_sec_[4];
  unsigned char tot_sec32_[4];

  /* FAT32 structure */
  unsigned char fatz32_array_[4];
  unsigned int fatz32_;
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
  char vol_lab_[11];
  char fil_sys_type_[8];
};

#endif /* !FAT_HH */
