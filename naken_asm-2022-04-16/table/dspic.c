/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2019 by Michael Kohn
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "table/dspic.h"

#define DSPIC 1
#define ALL 0

struct _table_dspic table_dspic[] = {
  { "add", 0xb40000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "add", 0xb00000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "add", 0x400060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "add", 0x400000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "add", 0xcb0000, 0xff7fff, OP_ACC, 1, 1, DSPIC },
  { "add", 0xc90000, 0xff0000, OP_WS_LIT4_ACC, 1, 1, DSPIC },
  { "addc", 0xb48000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "addc", 0xb08000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "addc", 0x480060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "addc", 0x480000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "and", 0xb60000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "and", 0xb20000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "and", 0x600060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "and", 0x600000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "asr", 0xd58000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "asr", 0xd18000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "asr", 0xde8040, 0xff8070, OP_WB_LIT4_WND, 1, 1, ALL },
  { "asr", 0xde8000, 0xff8070, OP_WB_WNS_WND, 1, 1, ALL },
  { "bclr", 0xa90000, 0xff0000, OP_F_BIT4, 1, 1, ALL },
  { "bclr", 0xa10000, 0xff0b80, OP_WS_BIT4, 1, 1, ALL },
  { "bra", 0x370000, 0xff0000, OP_BRA, 2, 2, ALL },
  { "bra", 0x016000, 0xfffff0, OP_WN, 2, 2, ALL },
  { "bra c", 0x310000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra ge", 0x3d0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra geu", 0x310000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra gt", 0x3c0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra gtu", 0x3e0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra le", 0x340000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra leu", 0x360000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra lt", 0x350000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra ltu", 0x390000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra n", 0x330000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra nc", 0x390000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra nn", 0x3b0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra nov", 0x380000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra nz", 0x3a0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra oa", 0x0c0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra ob", 0x0d0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra ov", 0x300000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra sa", 0x0e0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra sb", 0x0f0000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bra z", 0x320000, 0xff0000, OP_BRA, 1, 2, ALL },
  { "bset", 0xa80000, 0xff0000, OP_F_BIT4, 1, 1, ALL },
  { "bset", 0xa00000, 0xff0b80, OP_WS_BIT4, 1, 1, ALL },
  { "bsw", 0xad0000, 0xff0780, OP_WS_WB, 1, 1, ALL },
  { "btg", 0xaa0000, 0xff0000, OP_F_BIT4, 1, 1, ALL },
  { "btg", 0xa20000, 0xff0b80, OP_WS_BIT4, 1, 1, ALL },
  { "btsc", 0xaf0000, 0xff0000, OP_F_BIT4, 1, 3, ALL },
  { "btsc", 0xa70000, 0xff0f80, OP_WS_BIT4_2, 1, 3, ALL },
  { "btss", 0xae0000, 0xff0000, OP_F_BIT4, 1, 3, ALL },
  { "btss", 0xa60000, 0xff0f80, OP_WS_BIT4_2, 1, 3, ALL },
  { "btst", 0xab0000, 0xff0000, OP_F_BIT4, 1, 1, ALL },
  { "btst", 0xa30000, 0xff0780, OP_F_BIT4_2, 1, 1, ALL },
  { "btst", 0xa50000, 0xff0780, OP_WS_WB, 1, 1, ALL },
  { "btsts", 0xac0000, 0xff0000, OP_F_BIT4, 1, 1, ALL },
  { "btsts", 0xa40000, 0xff0780, OP_F_BIT4_2, 1, 1, ALL },
  { "call", 0x020000, 0xff0001, OP_GOTO, 2, 2, ALL },
  { "call", 0x010000, 0xfffff0, OP_WN, 2, 2, ALL },
  { "clr", 0xef0000, 0xff8000, OP_F_OR_WREG, 1, 1, ALL },
  { "clr", 0xeb0000, 0xff807f, OP_WD, 1, 1, ALL },
  { "clr", 0xc30000, 0xff4000, OP_A_WX_WY_AWB, 1, 1, ALL },
  { "clrwdt", 0xfe6000, 0xffffff, OP_NONE, 1, 1, ALL },
  { "com", 0xee8000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "com", 0xea8000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "cp", 0xe30000, 0xffa000, OP_CP_F, 1, 1, ALL },
  { "cp", 0xe10060, 0xff83e0, OP_WB_LIT5, 1, 1, ALL },
  { "cp", 0xe10000, 0xff8380, OP_WB_WS, 1, 1, ALL },
  { "cp0", 0xe20000, 0xffa000, OP_CP_F, 1, 1, ALL },
  { "cp0", 0xe00000, 0xfffb80, OP_CP0_WS, 1, 1, ALL },
  { "cpb", 0xe38000, 0xffa000, OP_CP_F, 1, 1, ALL },
  { "cpb", 0xe18060, 0xff83e0, OP_WB_LIT5, 1, 1, ALL },
  { "cpb", 0xe18000, 0xff8380, OP_WB_WS, 1, 1, ALL },
  { "cpseq", 0xe78000, 0xff83f0, OP_WB_WN, 1, 3, ALL },
  { "cpsgt", 0xe60000, 0xff83f0, OP_WB_WN, 1, 3, ALL },
  { "cpslt", 0xe68000, 0xff83f0, OP_WB_WN, 1, 3, ALL },
  { "cpsne", 0xe70000, 0xff83f0, OP_WB_WN, 1, 3, ALL },
  { "daw", 0xfd4000, 0xfffff0, OP_DAW_B_WN, 1, 1, ALL },
  { "dec", 0xed0000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "dec", 0xe90000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "dec2", 0xed8000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "dec2", 0xe98000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "disi", 0xfc0000, 0xffc000, OP_LIT14, 18, 18, ALL },
  { "div", 0xd80000, 0xff8030, OP_S_WM_WN, 18, 18, ALL },
  { "div", 0xd88000, 0xff8030, OP_U_WM_WN, 18, 18, ALL },
  { "divf", 0xd90000, 0xff87f0, OP_WM_WN, 18, 18, ALL },
  { "do", 0x080000, 0xffc000, OP_LIT14_EXPR, 2, 2, ALL },
  { "do", 0x088000, 0xfffff0, OP_WN_EXPR, 2, 2, ALL },
  { "ed", 0xf04003, 0xfc4c03, OP_WM_WM_ACC_WX_WY_WXD, 1, 1, DSPIC },
  { "edac", 0xf04002, 0xfc4c03, OP_WM_WM_ACC_WX_WY_WXD, 1, 1, DSPIC },
  { "exch", 0xfd0000, 0xfff870, OP_WNS_WND, 1, 1, ALL },
  { "fbcl", 0xdf0000, 0xfff800, OP_WS_WND, 1, 1, ALL },
  { "ff1l", 0xcf8000, 0xfff800, OP_WS_WND, 1, 1, DSPIC },
  { "ff1r", 0xcf0000, 0xfff800, OP_WS_WND, 1, 1, DSPIC },
  { "goto", 0x040000, 0xff0001, OP_GOTO, 2, 2, ALL },
  { "goto", 0x014000, 0xfffff0, OP_WN, 2, 2, ALL },
  { "inc", 0xec0000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "inc", 0xe80000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "inc2", 0xec8000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "inc2", 0xe88000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "ior", 0xb70000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "ior", 0xb30000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "ior", 0x700060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "ior", 0x700000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "lac", 0xca0000, 0xff0000, OP_WS_LIT4_ACC, 1, 1, DSPIC },
  { "lnk", 0xfa0000, 0xffc001, OP_LNK_LIT14, 1, 1, ALL },
  { "lsr", 0xd50000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "lsr", 0xd10000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "lsr", 0xde0040, 0xff8070, OP_WB_LIT4_WND, 1, 1, ALL },
  { "lsr", 0xde0000, 0xff8070, OP_WB_WNS_WND, 1, 1, ALL },
  { "mac", 0xc00000, 0xf84000, OP_WM_WN_ACC_WX_WY_AWB, 1, 1, DSPIC },
  { "mac", 0xf00000, 0xfc4003, OP_WM_WM_ACC_WX_WY, 1, 1, DSPIC },
  { "mov", 0xbf8000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "mov", 0xb7a000, 0xffa000, OP_WREG_F, 1, 1, ALL },
  { "mov", 0x800000, 0xf80000, OP_F_WND, 1, 1, ALL },
  { "mov", 0x880000, 0xf80000, OP_WNS_F, 1, 1, ALL },
  { "mov", 0xb3c000, 0xfff000, OP_LIT8_WND, 1, 1, ALL },
  { "mov", 0x200000, 0xf00000, OP_LIT16_WND, 1, 1, ALL },
  { "mov", 0x900000, 0xf80000, OP_WS_LIT10_WND, 1, 1, ALL },
  { "mov", 0x980000, 0xf80000, OP_WNS_WD_LIT10, 1, 1, ALL },
  { "mov", 0x780000, 0xf80000, OP_WS_WB_WD_WB, 1, 1, ALL },
  { "mov", 0xbe0000, 0xfff880, OP_D_WNS_WND_2, 2, 2, ALL },
  { "mov", 0xbe8000, 0xffc071, OP_D_WNS_WND_1, 2, 2, ALL },
  { "movsac", 0xc70000, 0xff4000, OP_A_WX_WY_AWB, 1, 1, DSPIC },
  { "mpy", 0xc00003, 0xf84003, OP_WM_WN_ACC_WX_WY, 1, 1, DSPIC },
  { "mpy", 0xf00001, 0xfc4003, OP_WM_WM_ACC_WX_WY, 1, 1, DSPIC },
  { "mpy", 0xc04003, 0xf84003, OP_N_WM_WN_ACC_WX_WY, 1, 1, DSPIC },
  { "msc", 0xc04000, 0xf84000, OP_WM_WN_ACC_WX_WY_AWB, 1, 1, DSPIC },
  { "mul", 0xbc0000, 0xffa000, OP_CP_F, 1, 1, ALL },
  { "mul", 0xb98000, 0xff8000, OP_SS_WB_WS_WND, 1, 1, ALL },
  { "mul", 0xb90060, 0xff8060, OP_SU_WB_LIT5_WND, 1, 1, ALL },
  { "mul", 0xb90000, 0xff8000, OP_SU_WB_WS_WND, 1, 1, ALL },
  { "mul", 0xb88000, 0xff8000, OP_US_WB_WS_WND, 1, 1, ALL },
  { "mul", 0xb80060, 0xff8060, OP_UU_WB_LIT5_WND, 1, 1, ALL },
  { "mul", 0xb80000, 0xff8000, OP_UU_WB_WS_WND, 1, 1, ALL },
  { "neg", 0xee0000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "neg", 0xea0000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "neg", 0xcb1000, 0xff7fff, OP_ACC, 1, 1, DSPIC },
  { "nop", 0x000000, 0xff0000, OP_NONE, 1, 1, ALL },
  { "nopr", 0xff0000, 0xff0000, OP_NONE, 1, 1, ALL },
  { "pop", 0xf90000, 0xff0001, OP_F, 1, 1, ALL },
  { "pop", 0x78004f, 0xf8407f, OP_POP_WD, 1, 1, ALL },
  { "pop", 0xbe004f, 0xfff8ff, OP_POP_D_WND, 2, 2, ALL },
  { "pop", 0xfe8000, 0xffffff, OP_POP_S, 1, 1, ALL },
  { "push", 0xf80000, 0xff0001, OP_F, 1, 1, ALL },
  { "push", 0x781f80, 0xf87f80, OP_WS_PLUS_WB, 1, 1, ALL },
  { "push", 0xbe9f80, 0xfffff1, OP_PUSH_D_WNS, 2, 2, ALL },
  { "push", 0xfea000, 0xffffff, OP_POP_S, 1, 1, ALL },
  { "pwrsav", 0xfe4000, 0xfffffe, OP_LIT1, 1, 1, ALL },
  { "rcall", 0x070000, 0xff0000, OP_BRA, 2, 2, ALL },
  { "rcall", 0x012000, 0xfffff0, OP_WN, 2, 2, ALL },
  { "repeat", 0x090000, 0xffc000, OP_LIT14, 1, 1, ALL },
  { "repeat", 0x098000, 0xfffff0, OP_WN, 1, 1, ALL },
  { "reset", 0xfe0000, 0xffffff, OP_NONE, 1, 1, ALL },
  { "retfie", 0x064000, 0xffffff, OP_NONE, 2, 3, ALL },
  { "retlw", 0x050000, 0xff8000, OP_LIT10_WN, 2, 3, ALL },
  { "return", 0x060000, 0xffffff, OP_NONE, 2, 3, ALL },
  { "rlc", 0xd68000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "rlc", 0xd28000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "rlnc", 0xd60000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "rlnc", 0xd20000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "rrc", 0xd78000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "rrc", 0xd38000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "rrnc", 0xd70000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "rrnc", 0xd30000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "sac", 0xcc0000, 0xfe0000, OP_ACC_LIT4_WD, 1, 1, DSPIC },
  //{ "sac", 0xcc0000, 0xff0000, OP_ACC_LIT4_WD, 1, 1 },
  //{ "sac", 0xcd0000, 0xff0000, OP_ACC_LIT4_WD, 1, 1 },
  { "se", 0xfb0000, 0xfff800, OP_WS_WND, 1, 1, ALL },
  { "setm", 0xef8000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "setm", 0xeb8000, 0xff807f, OP_WD, 1, 1, ALL },
  { "sftac", 0xc80040, 0xff7fc0, OP_ACC_LIT6, 1, 1, DSPIC },
  { "sftac", 0xc80000, 0xff7ff0, OP_ACC_WB, 1, 1, DSPIC },
  { "sl", 0xd40000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "sl", 0xd00000, 0xff8000, OP_WS_WD, 1, 1, ALL },
  { "sl", 0xdd0040, 0xff8070, OP_WB_LIT4_WND, 1, 1, ALL },
  { "sl", 0xdd0000, 0xff8070, OP_WB_WNS_WND, 1, 1, ALL },
  { "sub", 0xb50000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "sub", 0xb10000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "sub", 0x500060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "sub", 0x500000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "sub", 0xcb3000, 0xff7fff, OP_ACC, 1, 1, DSPIC },
  { "subb", 0xb58000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "subb", 0xb18000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "subb", 0x580060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "subb", 0x580000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "subbr", 0xbd8000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "subbr", 0x180060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "subbr", 0x180000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "subr", 0xbd0000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "subr", 0x100060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "subr", 0x100000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "swap", 0xfd8000, 0xffbff0, OP_B_WN, 1, 1, ALL },
  { "tblrdh", 0xba8000, 0xff8000, OP_WS_WD, 2, 2, ALL },
  { "tblrdl", 0xba0000, 0xff8000, OP_WS_WD, 2, 2, ALL },
  { "tblwth", 0xbb8000, 0xff8000, OP_WS_WD, 2, 2, ALL },
  { "tblwtl", 0xbb0000, 0xff8000, OP_WS_WD, 2, 2, ALL },
  { "ulnk", 0xfa8000, 0xffffff, OP_NONE, 1, 1, ALL },
  { "xor", 0xb68000, 0xff8000, OP_F_WREG, 1, 1, ALL },
  { "xor", 0xb28000, 0xff8000, OP_LIT10_WN, 1, 1, ALL },
  { "xor", 0x680060, 0xf80060, OP_WB_LIT5_WD, 1, 1, ALL },
  { "xor", 0x680000, 0xf80000, OP_WB_WS_WD, 1, 1, ALL },
  { "ze", 0xfb8000, 0xffc000, OP_WS_WND, 1, 1, ALL },
  { NULL, 0, 0, 0,  0, 0, ALL }
};


