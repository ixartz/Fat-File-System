#include "fat.hh"

Fat::Fat(char* p)
{
  unsigned char signature[2];

  memcpy(jmp_boot_, p, SizeOfArray(jmp_boot_));
  read_string(oem_identifier_, p + 3);
  memcpy(nb_Byte_sector_array_, p + 11, SizeOfArray(nb_Byte_sector_array_));
  nb_Byte_sector_ = array_to_int(nb_Byte_sector_array_);

  if (nb_Byte_sector_ != 512)
  {
    /* TODO: Need an exception here */
  }

  memcpy(sec_per_clus_array_, p + 13, SizeOfArray(sec_per_clus_array_));
  sec_per_clus_ = sec_per_clus_array_[0];

  memcpy(rsvd_sec_cnt_array_, p + 14, SizeOfArray(rsvd_sec_cnt_array_));
  rsvd_sec_cnt_ = array_to_int(rsvd_sec_cnt_array_);
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
  memcpy(fatz32_array_, p + 36, SizeOfArray(fatz32_array_));
  fatz32_ = array_to_int(fatz32_array_);
  memcpy(ext_flags_, p + 40, SizeOfArray(ext_flags_));
  memcpy(fs_ver_, p + 42, SizeOfArray(fs_ver_));
  memcpy(root_clus_array_, p + 44, SizeOfArray(root_clus_array_));
  root_clus_ = array_to_int(root_clus_array_);
  memcpy(fs_info_, p + 48, SizeOfArray(fs_info_));
  memcpy(bk_boot_sec_, p + 50, SizeOfArray(bk_boot_sec_));
  memcpy(reserved_, p + 52, SizeOfArray(reserved_));
  memcpy(drv_num_, p + 64, SizeOfArray(drv_num_));
  memcpy(reserved1_, p + 65, SizeOfArray(reserved1_));
  memcpy(boot_sig_, p + 66, SizeOfArray(boot_sig_));
  memcpy(vol_id_, p + 67, SizeOfArray(vol_id_));
  read_string(vol_lab_, p + 71);
  read_string(fil_sys_type_, p + 82);

  memcpy(signature, p + 0x1FE, SizeOfArray(signature));

  if (signature[0] != 0x55 && signature[1] != 0xAA)
  {
    /* TODO: Need an exception here */
  }
}

Fat::~Fat()
{
  if (cluster_chain_)
    delete[] cluster_chain_;
}

void Fat::print()
{
  std::cout << "Fat32 partition" << std::endl;

  std::cout << "Jump instruction: ";
  PrintArray(jmp_boot_);

  std::cout << "OEM identifier: ["
            << oem_identifier_
            << "]" << std::endl;

  std::cout << "Number of Byte per sector: "
            << nb_Byte_sector_ << " in hex: ";
  PrintArray(nb_Byte_sector_array_);
  std::cout << "Number of sectors per allocation unit: "
            << promote_int(sec_per_clus_) << " in hex: ";
  PrintArray(sec_per_clus_array_);

  std::cout << "Number of reserved sectors: "
            << rsvd_sec_cnt_ << " in hex: ";
  PrintArray(rsvd_sec_cnt_array_);
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

  std::cout << "32-bit count of sectors occupied by one FAT: "
            << fatz32_ << " in hex: ";
  PrintArray(fatz32_array_);
  std::cout << "Flags: ";
  PrintArray(ext_flags_);
  std::cout << "Version of FAT32 Drive: ";
  PrintArray(fs_ver_);
  std::cout << "Cluster number of root directory: "
            << root_clus_ << " in hex: ";
  PrintArray(root_clus_array_);

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
  std::cout << "Volume label: ["
            << vol_lab_ << "]" << std::endl;
  std::cout << "File system type (informational only): ["
            << fil_sys_type_ << "]" << std::endl;
}

void Fat::load_fat_structure(Input& in, unsigned int LBA_offset)
{
  unsigned char* p;
  unsigned long cluster;
  unsigned int nb_cluster_chain_per_sector = nb_Byte_sector_ / 4;

  cluster_chain_ = new unsigned long[get_fatz32() * nb_cluster_chain_per_sector];
  in.move_at(LBA_offset + get_rsvd_sec_cnt());

  for (unsigned int j = 0; j < get_fatz32(); ++j)
  {
    p = (unsigned char*) in.get_next_buffer();

    for (unsigned int i = 0; i < nb_cluster_chain_per_sector; ++i)
    {
      cluster = 0;

      for (int k = 3; k >= 0; --k)
        cluster = (cluster << 8) | p[i * 4 + k];

      cluster_chain_[j * nb_cluster_chain_per_sector + i] = cluster;
    }
  }
}

unsigned int Fat::get_nb_Byte_sector()
{
  return nb_Byte_sector_;
}

unsigned char Fat::get_sec_per_clus_()
{
  return sec_per_clus_;
}

unsigned int Fat::get_rsvd_sec_cnt()
{
  return rsvd_sec_cnt_;
}

unsigned int Fat::get_fatz32()
{
  return fatz32_;
}

unsigned int Fat::get_root_clus_()
{
  return root_clus_;
}
