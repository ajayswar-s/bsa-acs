/** @file
 * Copyright (c) 2016-2024, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "common/include/acs_val.h"
#include "common/include/acs_pe.h"
#include "common/include/acs_common.h"
#include "common/include/acs_std_smc.h"


/**
  @brief   Pointer to the memory location of the PE Information table
**/
extern PE_INFO_TABLE *g_pe_info_table;
/**
  @brief   global structure to pass and retrieve arguments for the SMC call
**/
extern ARM_SMC_ARGS g_smc_args;


/**
  @brief   This API provides a 'C' interface to call System register reads
           1. Caller       -  Test Suite
           2. Prerequisite -  None
  @param   reg_id  - the system register index for which data is returned
  @return  the value read from the system register.
**/
uint64_t
val_pe_reg_read(uint32_t reg_id)
{

  switch(reg_id) {
      case MPIDR_EL1:
          return ArmReadMpidr();
      case ID_AA64PFR0_EL1:
          return ArmReadIdPfr0();
      case ID_AA64PFR1_EL1:
          return ArmReadIdPfr1();
      case ID_AA64MMFR0_EL1:
          return AA64ReadMmfr0();
      case ID_AA64MMFR1_EL1:
          return AA64ReadMmfr1();
      case ID_AA64MMFR2_EL1:
          return AA64ReadMmfr2();
      case CTR_EL0:
          return AA64ReadCtr();
      case ID_AA64ISAR0_EL1:
          return AA64ReadIsar0();
      case ID_AA64ISAR1_EL1:
          return AA64ReadIsar1();
      case ID_AA64ISAR2_EL1:
          return AA64ReadIsar2();
      case SCTLR_EL3:
          return AA64ReadSctlr3();
      case SCTLR_EL2:
          return AA64ReadSctlr2();
      case SCTLR_EL1:
          return AA64ReadSctlr1();
      case PMCR_EL0:
          return AA64ReadPmcr();
      case ID_AA64DFR0_EL1:
          return AA64ReadIdDfr0();
      case ID_AA64DFR1_EL1:
          return AA64ReadIdDfr1();
      case CurrentEL:
          return AA64ReadCurrentEL();
      case MDCR_EL2:
          return AA64ReadMdcr2();
      case VBAR_EL2:
          return AA64ReadVbar2();
      case CCSIDR_EL1:
          return AA64ReadCcsidr();
      case CSSELR_EL1:
          return AA64ReadCsselr();
      case CLIDR_EL1:
          return AA64ReadClidr();
      case ID_DFR0_EL1:
          return ArmReadDfr0();
      case ID_ISAR0_EL1:
          return ArmReadIsar0();
      case ID_ISAR1_EL1:
          return ArmReadIsar1();
      case ID_ISAR2_EL1:
          return ArmReadIsar2();
      case ID_ISAR3_EL1:
          return ArmReadIsar3();
      case ID_ISAR4_EL1:
          return ArmReadIsar4();
      case ID_ISAR5_EL1:
          return ArmReadIsar5();
      case ID_MMFR0_EL1:
          return ArmReadMmfr0();
      case ID_MMFR1_EL1:
          return ArmReadMmfr1();
      case ID_MMFR2_EL1:
          return ArmReadMmfr2();
      case ID_MMFR3_EL1:
          return ArmReadMmfr3();
      case ID_MMFR4_EL1:
          return ArmReadMmfr4();
      case ID_PFR0_EL1:
          return ArmReadPfr0();
      case ID_PFR1_EL1:
          return ArmReadPfr1();
      case MIDR_EL1:
          return ArmReadMidr();
      case MVFR0_EL1:
          return ArmReadMvfr0();
      case MVFR1_EL1:
          return ArmReadMvfr1();
      case MVFR2_EL1:
          return ArmReadMvfr2();
      case PMCEID0_EL0:
          return AA64ReadPmceid0();
      case PMCEID1_EL0:
          return AA64ReadPmceid1();
      case VMPIDR_EL2:
          return AA64ReadVmpidr();
      case VPIDR_EL2:
          return AA64ReadVpidr();
      case PMBIDR_EL1:
          return AA64ReadPmbidr();
      case PMSIDR_EL1:
          return AA64ReadPmsidr();
      case LORID_EL1:
          return AA64ReadLorid();
      case ERRIDR_EL1:
          return AA64ReadErridr();
      case ERR0FR_EL1:
          return AA64ReadErr0fr();
      case ERR1FR_EL1:
          return AA64ReadErr1fr();
      case ERR2FR_EL1:
          return AA64ReadErr2fr();
      case ERR3FR_EL1:
          return AA64ReadErr3fr();
      case ESR_EL2:
          return AA64ReadEsr2();
      case FAR_EL2:
          return AA64ReadFar2();
      case RDVL:
          return ArmRdvl();
      case MAIR_ELx:
          if (AA64ReadCurrentEL() == AARCH64_EL1)
            return AA64ReadMair1();
          if (AA64ReadCurrentEL() == AARCH64_EL2)
            return AA64ReadMair2();
          break;
      case TCR_ELx:
          if (AA64ReadCurrentEL() == AARCH64_EL1)
            return AA64ReadTcr1();
          if (AA64ReadCurrentEL() == AARCH64_EL2)
            return AA64ReadTcr2();
          break;
      case DBGBCR0_EL1:
          return AA64ReadDbgbcr0El1();
      case DBGBCR1_EL1:
          return AA64ReadDbgbcr1El1();
      case DBGBCR2_EL1:
          return AA64ReadDbgbcr2El1();
      case DBGBCR3_EL1:
          return AA64ReadDbgbcr3El1();
      case DBGBCR4_EL1:
          return AA64ReadDbgbcr4El1();
      case DBGBCR5_EL1:
          return AA64ReadDbgbcr5El1();
      case DBGBCR6_EL1:
          return AA64ReadDbgbcr6El1();
      case DBGBCR7_EL1:
          return AA64ReadDbgbcr7El1();
      case DBGBCR8_EL1:
          return AA64ReadDbgbcr8El1();
      case DBGBCR9_EL1:
          return AA64ReadDbgbcr9El1();
      case DBGBCR10_EL1:
          return AA64ReadDbgbcr10El1();
      case DBGBCR11_EL1:
          return AA64ReadDbgbcr11El1();
      case DBGBCR12_EL1:
          return AA64ReadDbgbcr12El1();
      case DBGBCR13_EL1:
          return AA64ReadDbgbcr13El1();
      case DBGBCR14_EL1:
          return AA64ReadDbgbcr14El1();
      case DBGBCR15_EL1:
          return AA64ReadDbgbcr15El1();
      case ID_AA64ZFR0_EL1:
          return AA64ReadZfr0();
      case BRBIDR0_EL1:
          return AA64ReadBrbidr0();
      case TRBIDR_EL1:
          return AA64ReadTrbidr();
      case TRCIDR0:
          return AA64ReadTrcidr0();
       case TRCIDR4:
          return AA64ReadTrcidr4();
       case TRCIDR5:
          return AA64ReadTrcidr5();
       case HCR_EL2:
          return ArmReadHcr();
       case VTCR_EL2:
          return AA64ReadVtcr();

       case ID_AA64AFR0_EL1:
          return AA64ReadAfr0();
       case ID_AA64AFR1_EL1:
          return AA64ReadAfr1();
       case ID_AA64DFR2_EL1:
          return  AA64ReadDfr2();
       case ID_AA64FPFR0_EL1:
          return  AA64ReadFpfr0();
       case ID_AA64ISAR3_EL1:
          return AA64ReadIsar3();
       case ID_AA64MMFR3_EL1:
          return AA64ReadMmfr3();
       case ID_AA64MMFR4_EL1:
          return AA64ReadMmfr4();
       case ID_AA64PFR2_EL1:
          return AA64ReadPfr2();
       case AIDR_EL1:
          return AA64ReadAidr();
       case DCZID_EL0:
          return AA64ReadDczid();
       case REVIDR_EL1:
          return AA64ReadRevidr();
       case ID_AA64SMFR0_EL1:
          return AA64ReadSmfr0();
       case CPTR_EL2:
          return AA64ReadCptrEL2();
       case SMIDR_EL1:
          return AA64ReadSmidr();
       case AMCG1IDR_EL0:
          return AA64ReadAmcg1idr();
       case GMID_EL1:
          return AA64ReadGmid();
       case MPAMIDR_EL1:
          return AA64ReadMpamidr();
       case SPMIIDR_EL1:
          return AA64ReadSpmiidr();
       case MECIDR_EL2:
          return AA64ReadMecidr();
       case VMECID_A_EL2:
          return AA64ReadVmecida();
       case VMECID_P_EL2:
          return AA64ReadVmecidp();
       case TRCDEVID:
          return AA64ReadTrcdevid();
       case TRCTRACEIDR:
          return AA64ReadTrctraceidr();
       case TRCIDR1:
          return AA64ReadTrcidr1();
       case TRCIDR2:
          return AA64ReadTrcidr2();
       case TRCIDR3:
          return AA64ReadTrcidr3();
       case TRCIDR6:
          return AA64ReadTrcidr6();
       case TRCIDR7:
          return AA64ReadTrcidr7();
       case TRCIDR8:
          return AA64ReadTrcidr8();
       case TRCIDR9:
          return AA64ReadTrcidr9();
       case TRCIDR10:
          return AA64ReadTrcidr10();
       case TRCIDR11:
          return AA64ReadTrcidr11();
       case TRCIDR12:
          return AA64ReadTrcidr12();
       case TRCIDR13:
          return AA64ReadTrcidr13();
       case ID_AFR0_EL1:
          return ArmReadAfr0();
       case ID_DFR1_EL1:
          return ArmReadDfr1();
       case ID_ISAR6_EL1:
          return ArmReadIsar6();
       case ID_MMFR5_EL1:
          return ArmReadMmfr5();
       case ID_PFR2_EL1:
          return ArmReadPfr2();
      default:
           val_report_status(val_pe_get_index_mpid(val_pe_get_mpid()),
                                                 RESULT_FAIL(0, 0xFF), NULL);
           break;
  }

  return 0x0;
}

/**
  @brief   This API provides a 'C' interface to call System register writes
           1. Caller       -  Test Suite
           2. Prerequisite -  None
  @param   reg_id  - the system register index for which data is written
  @param   write_data - the 64-bit data to write to the system register
  @return  None
**/
void
val_pe_reg_write(uint32_t reg_id, uint64_t write_data)
{

  switch(reg_id) {
      case CSSELR_EL1:
          AA64WriteCsselr(write_data);
          break;
      case PMCR_EL0:
          AA64WritePmcr(write_data);
          break;
      case PMOVSSET_EL0:
          AA64WritePmovsset(write_data);
          break;
      case PMOVSCLR_EL0:
          AA64WritePmovsclr(write_data);
          break;
      case PMINTENSET_EL1:
          AA64WritePmintenset(write_data);
          break;
      case PMINTENCLR_EL1:
          AA64WritePmintenclr(write_data);
          break;
      case MDCR_EL2:
          AA64WriteMdcr2(write_data);
          break;
      case VBAR_EL2:
          AA64WriteVbar2(write_data);
          break;
      case PMSIRR_EL1:
          AA64WritePmsirr(write_data);
          break;
      case PMSCR_EL2:
          AA64WritePmscr2(write_data);
          break;
      case PMSFCR_EL1:
          AA64WritePmsfcr(write_data);
          break;
      case PMBPTR_EL1:
          AA64WritePmbptr(write_data);
          break;
      case PMBLIMITR_EL1:
          AA64WritePmblimitr(write_data);
          break;
      default:
           val_report_status(val_pe_get_index_mpid(val_pe_get_mpid()),
                                                  RESULT_FAIL(0, 0xFF), NULL);
  }

}

/**
  @brief   This API indicates the presence of exception level 3
           1. Caller       -  Test Suite
           2. Prerequisite -  None
  @param   None
  @return  1 if EL3 is present, 0 if EL3 is not implemented
**/
uint8_t
val_is_el3_enabled()
{
  uint64_t data;
  data = val_pe_reg_read(ID_AA64PFR0_EL1);
  return ((data >> 12) & 0xF);

}

/**
  @brief   This API indicates the presence of exception level 2
           1. Caller       -  Test Suite
           2. Prerequisite -  None
  @param   None
  @return  1 if EL2 is present, 0 if EL2 is not implemented
**/
uint8_t
val_is_el2_enabled()
{

  uint64_t data;
  data = val_pe_reg_read(ID_AA64PFR0_EL1);
  return ((data >> 8) & 0xF);

}


/**
  @brief   This API returns the PMU Overflow Signal Interrupt ID for a given PE index
           1. Caller       -  Test Suite, VAL
           2. Prerequisite -  val_create_peinfo_table
  @param   index - the index of PE whose PMU interrupt ID is returned.
  @return  PMU interrupt id
**/
uint32_t
val_pe_get_pmu_gsiv(uint32_t index)
{

  PE_INFO_ENTRY *entry;

  if (index > g_pe_info_table->header.num_of_pe) {
        val_report_status(index, RESULT_FAIL(0, 0xFF), NULL);
        return 0xFFFFFF;
  }

  entry = g_pe_info_table->pe_info;

  return entry[index].pmu_gsiv;

}
/**
  @brief   This API returns the GIC TRBE Interrupt ID for a given PE index
           1. Caller       -  Test Suite
           2. Prerequisite -  val_create_peinfo_table
  @param   index - the index of PE whose GIC TRBE interrupt ID is returned.
  @return  GIC TRBE interrupt ID
**/
uint32_t
val_pe_get_gicc_trbe_interrupt(uint32_t index)
{

  PE_INFO_ENTRY *entry;

  if (index > g_pe_info_table->header.num_of_pe) {
        val_report_status(index, RESULT_FAIL(0, 0xFF), NULL);
        return 0xFFFFFF;
  }

  entry = g_pe_info_table->pe_info;

  return entry[index].trbe_interrupt;

}

/**
  @brief   This API returns the GIC Maintenance Interrupt ID for a given PE index
           1. Caller       -  Test Suite
           2. Prerequisite -  val_create_peinfo_table
  @param   index - the index of PE whose GIC Maintenance interrupt ID is to be returned.
  @return  GIC Maintenance interrupt id
**/
uint32_t
val_pe_get_gmain_gsiv(uint32_t index)
{

  PE_INFO_ENTRY *entry;

  if (index > g_pe_info_table->header.num_of_pe) {
        val_report_status(index, RESULT_FAIL(0, 0xFF), NULL);
        return 0xFFFFFF;
  }

  entry = g_pe_info_table->pe_info;

  return entry[index].gmain_gsiv;

}

/**
  @brief   This API reads the TCR register and fills info to structure.

  @param   ttbr1  If ttbr1 is used
  @param   *tcr   To fill the TCR information

  @return  Status 0 if Success
**/
void
val_pe_spe_disable(void)
{
  DisableSpe();
}

uint32_t val_pe_reg_read_tcr(uint32_t ttbr1, PE_TCR_BF *tcr)
{
    uint64_t val = val_pe_reg_read(TCR_ELx);
    uint32_t el = AA64ReadCurrentEL() & AARCH64_EL_MASK;
    uint8_t tg_ttbr0[3] = {12 /*4KB*/, 16 /*64KB*/, 14 /*16KB*/};
    uint8_t tg_ttbr1[4] = {0 /* N/A */, 14 /*16KB*/, 12 /*4KB*/, 16 /* 64KB*/};
    uint64_t e2h = 0;

    if ((tcr == NULL) ||
        (el != AARCH64_EL1 && el != AARCH64_EL2))
        return ACS_STATUS_ERR;

    if (el == AARCH64_EL2)
        e2h = ArmReadHcr() & AARCH64_HCR_E2H_MASK;

    if (el == AARCH64_EL1 || (el == AARCH64_EL2 && e2h))
    {
        tcr->ps = (val & BSA_TCR_IPS_MASK) >> BSA_TCR_IPS_SHIFT;
        if (ttbr1) {
            tcr->tg = (val & BSA_TCR_TG1_MASK) >> BSA_TCR_TG1_SHIFT;
            if (tcr->tg == 0 || tcr->tg > 3)
                return ACS_STATUS_ERR;
            tcr->tg_size_log2 = tg_ttbr1[tcr->tg];
            tcr->sh = (val & BSA_TCR_SH1_MASK) >> BSA_TCR_SH1_SHIFT;
            tcr->orgn = (val & BSA_TCR_ORGN1_MASK) >> BSA_TCR_ORGN1_SHIFT;
            tcr->irgn = (val & BSA_TCR_IRGN1_MASK) >> BSA_TCR_IRGN1_SHIFT;
            tcr->tsz = (val & BSA_TCR_T1SZ_MASK) >> BSA_TCR_T1SZ_SHIFT;
            return 0;
        }
    }
    else if (!ttbr1)
        tcr->ps = (val & BSA_TCR_PS_MASK) >> BSA_TCR_PS_SHIFT;
    else
        return ACS_STATUS_ERR;

    tcr->tg = (val & BSA_TCR_TG0_MASK) >> BSA_TCR_TG0_SHIFT;
    if (tcr->tg > 2)
        return ACS_STATUS_ERR;
    tcr->tg_size_log2 = tg_ttbr0[tcr->tg];
    tcr->sh = (val & BSA_TCR_SH0_MASK) >> BSA_TCR_SH0_SHIFT;
    tcr->orgn = (val & BSA_TCR_ORGN0_MASK) >> BSA_TCR_ORGN0_SHIFT;
    tcr->irgn = (val & BSA_TCR_IRGN0_MASK) >> BSA_TCR_IRGN0_SHIFT;
    tcr->tsz = (val & BSA_TCR_T0SZ_MASK) >> BSA_TCR_T0SZ_SHIFT;
    return 0;
}

/**
  @brief   This API reads the TTBR register and fills info to structure.

  @param   ttbr1       If ttbr1 is used
  @param   *ttbr_ptr   To fill the TTBR information

  @return  Status 0 if Success
**/
uint32_t val_pe_reg_read_ttbr(uint32_t ttbr1, uint64_t *ttbr_ptr)
{
    uint32_t el = AA64ReadCurrentEL() & AARCH64_EL_MASK;
    typedef uint64_t (*ReadTtbr_t)(void);
    ReadTtbr_t ReadTtbr[2][2] = {{AA64ReadTtbr0El1, AA64ReadTtbr0El2},
                                  {AA64ReadTtbr1El1, AA64ReadTtbr1El2}};

    if ((ttbr_ptr == NULL) ||
        (el != AARCH64_EL1 && el != AARCH64_EL2) ||
        ttbr1 > 1)
        return ACS_STATUS_ERR;

    *ttbr_ptr = ReadTtbr[ttbr1][(el >> 2) - 1]();
    return 0;
}
