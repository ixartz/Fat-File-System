#ifndef FAT_HH
# define FAT_HH

# include <string.h>
# include "input.hh"
# include "tool-array.hh"

/**
 * \brief Fat boot sector
 */
class Fat
{
public:
  /// Constructor.
  Fat(char* p);
  /// Destructor.
  ~Fat();

  /**
   * \brief Print Fat32 information.
   */
  void print();

  /**
   * \brief Load Fat structure.
   */
  void load_fat_structure(Input& in, unsigned int LBA_offset);

  /**
   * \brief Get next cluster according to the cluster chain.
   */
  unsigned int get_next_cluster(unsigned int pos);

  /// Return number of Byte per sector
  unsigned int get_nb_Byte_sector();

  /// Return number of sector per cluster
  unsigned char get_sec_per_clus();

  /// Return number of reserved sector
  unsigned int get_rsvd_sec_cnt();

  /// Return number sector per Fat
  unsigned int get_fatz32();

  /// Return cluster number of root directory.
  unsigned int get_root_clus();

private:
  /* BPB structure */
  /// Jump instruction to boot code.
  unsigned char jmp_boot_[3];
  /// OEM (original equipment manufacturer) identifier.
  char oem_identifier_[9];
  /// Number of Byte per sector.
  unsigned char nb_Byte_sector_array_[2];
  unsigned int nb_Byte_sector_ = 0;
  unsigned char sec_per_clus_array_[1];
  unsigned char sec_per_clus_;
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
  unsigned char root_clus_array_[4];
  unsigned int root_clus_;
  unsigned char fs_info_[2];
  unsigned char bk_boot_sec_[2];
  unsigned char reserved_[12];
  unsigned char drv_num_[1];
  unsigned char reserved1_[1];
  unsigned char boot_sig_[1];
  unsigned char vol_id_[4];
  char vol_lab_[12];
  char fil_sys_type_[9];

  unsigned long* cluster_chain_ = NULL;
};

#endif /* !FAT_HH */
