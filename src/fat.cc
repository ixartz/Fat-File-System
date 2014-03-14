#include "fat.hh"

Fat::Fat(char* p)
{
  unsigned char signature[2];

  memcpy(jmp_boot_, p, SizeOfArray(jmp_boot_));
  memcpy(oem_identifier_, p + 3, SizeOfArray(oem_identifier_));
  memcpy(nb_Byte_sector_array_, p + 11, SizeOfArray(nb_Byte_sector_array_));
  nb_Byte_sector_ = array_to_int(nb_Byte_sector_array_);

  if (nb_Byte_sector_ != 512)
  {
    /* TODO: Need an exception here */
  }

  memcpy(sec_per_lus_, p + 13, SizeOfArray(sec_per_lus_));
  memcpy(rsvd_sec_cnt_, p + 14, SizeOfArray(rsvd_sec_cnt_));
  memcpy(num_fats_array_, p + 16, SizeOfArray(num_fats_array_));
  num_fats_ = array_to_int(num_fats_array_);

  if (num_fats_ != 2)
  {
    /* TODO: Need an exception here */
  }

  memcpy(root_ent_cnt_, p + 17, SizeOfArray(root_ent_cnt_));
  memcpy(tot_sec16_, p + 19, SizeOfArray(tot_sec16_));
  memcpy(media_, p + 21, SizeOfArray(media_));
  memcpy(fatz16_, p + 22, SizeOfArray(fatz16_));
  memcpy(sec_per_trk_, p + 24, SizeOfArray(sec_per_trk_));
  memcpy(num_heads_, p + 26, SizeOfArray(num_heads_));
  memcpy(hidd_sec_, p + 28, SizeOfArray(hidd_sec_));
  memcpy(tot_sec32_, p + 32, SizeOfArray(tot_sec32_));
  memcpy(fatz32_, p + 36, SizeOfArray(fatz32_));
  memcpy(ext_flags_, p + 40, SizeOfArray(ext_flags_));
  memcpy(fs_ver_, p + 42, SizeOfArray(fs_ver_));
  memcpy(root_clus_, p + 44, SizeOfArray(root_clus_));
  memcpy(fs_info_, p + 48, SizeOfArray(fs_info_));
  memcpy(bk_boot_sec_, p + 50, SizeOfArray(bk_boot_sec_));
  memcpy(reserved_, p + 52, SizeOfArray(reserved_));
  memcpy(drv_num_, p + 64, SizeOfArray(drv_num_));
  memcpy(reserved1_, p + 65, SizeOfArray(reserved1_));
  memcpy(boot_sig_, p + 66, SizeOfArray(boot_sig_));
  memcpy(vol_id_, p + 67, SizeOfArray(vol_id_));
  memcpy(vol_lab_, p + 71, SizeOfArray(vol_lab_));
  memcpy(fil_sys_type_, p + 82, SizeOfArray(fil_sys_type_));

  memcpy(signature, p + 0x1FE, SizeOfArray(signature));

  if (signature[0] != 0x55 && signature[1] != 0xAA)
  {
    /* TODO: Need an exception here */
  }
}

void Fat::print()
{
  std::cout << "Jump instruction: ";
  PrintArray(jmp_boot_);

  std::cout << "OEM identifier: "
            << std::string(oem_identifier_)
            << std::endl;

  std::cout << "Number of Byte per sector: "
            << nb_Byte_sector_ << " in hex: ";
  PrintArray(nb_Byte_sector_array_);
  std::cout << "Number of sectors per allocation unit: ";
  PrintArray(sec_per_lus_);
  std::cout << "Number of reserved sectors: ";
  PrintArray(rsvd_sec_cnt_);
  std::cout << "Number of FAT: "
            << num_fats_ << " in hex: ";
  PrintArray(num_fats_array_);
  std::cout << "Number of root directory entries: ";
  PrintArray(root_ent_cnt_);
  std::cout << "Total number of sectors: ";
  PrintArray(tot_sec16_);
  std::cout << "Media descriptor: ";
  PrintArray(media_);
  std::cout << "Count of sector in old 16-bit: ";
  PrintArray(fatz16_);
  std::cout << "Number of sectors per track: ";
  PrintArray(sec_per_trk_);
  std::cout << "Number of heads: ";
  PrintArray(num_heads_);
  std::cout << "Count of hidden sectors: ";
  PrintArray(hidd_sec_);
  std::cout << "Count of sector in new 32-bit: ";
  PrintArray(tot_sec32_);

  std::cout << "32-bit count of sectors occupied by one FAT: ";
  PrintArray(fatz32_);
  std::cout << "Flags: ";
  PrintArray(ext_flags_);
  std::cout << "Version of FAT32 Drive: ";
  PrintArray(fs_ver_);
  std::cout << "Cluster number of root directory: ";
  PrintArray(root_clus_);
  std::cout << "Sector number of FSINFO: ";
  PrintArray(fs_info_);
  std::cout << "Sector Number of the BackupBoot Sector: ";
  PrintArray(bk_boot_sec_);
  std::cout << "Reserved for future expansion: ";
  PrintArray(reserved_);
  std::cout << "Logical Drive Number: ";
  PrintArray(drv_num_);
  std::cout << "Reserved (used by Windows NT): ";
  PrintArray(reserved1_);
  std::cout << "Extended boot signature: ";
  PrintArray(boot_sig_);
  std::cout << "Volume serial number: ";
  PrintArray(vol_id_);
  std::cout << "Volume label: ";
  PrintArray(vol_lab_);
  std::cout << "File system type (informational only): ";
  PrintArray(fil_sys_type_);
}
