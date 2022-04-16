/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2020 by Michael Kohn
 *
 */

#ifndef NAKEN_ASM_ASM_TMS1000_H
#define NAKEN_ASM_ASM_TMS1000_H

#include "common/assembler.h"

int parse_instruction_tms1000(struct _asm_context *asm_context, char *instr);
int parse_instruction_tms1100(struct _asm_context *asm_context, char *instr);

#endif

