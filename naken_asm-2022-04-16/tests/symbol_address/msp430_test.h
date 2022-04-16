const char *msp430_1 =
  ".msp430\n"
  ".org 0x200\n"
  "first:\n"
  "  mov.w #1, &100\n"
  "second:\n"
  "  mov.w #first, &100\n"
  "third:\n"
  "  mov.w #fifth, &100\n"
  "fourth:\n"
  "  mov.b #1, &100\n"
  ".org 10\n"
  "fifth:\n"
  "  mov.w #fourth, &100\n\n";

const char *msp430_2 =
  ".msp430x\n"
  ".org 0x200\n"
  "first:\n"
  "  mov.w #fifth, &100\n"
  "second:\n"
  "  mova &first, r7\n"
  "third:\n"
  "  mova r7, &100\n"
  "fourth:\n"
  "  mov.b #1, &100\n"
  ".org 2\n"
  "fifth:\n"
  "  mov.w #fourth, &100\n\n";

const char *msp430_3 =
  ".msp430x\n"
  ".org 0x200\n"
  "first:\n"
  "  rpt #5, adda #7, r8\n"
  "second:\n"
  "  calla fifth\n"
  "third:\n"
  "  mova r7, &100\n"
  "fourth:\n"
  "  mov.b #1, &100\n"
  ".org 2\n"
  "fifth:\n"
  "  mov.w #fourth, &100\n\n";

const char *msp430_4 =
  ".msp430x\n"
  ".org 0x200\n"
  "first:\n"
  "  pushx.a #0xffff\n"
  "second:\n"
  "  calla fifth\n"
  "third:\n"
  "  pushx.a #0xfffff\n"
  "fourth:\n"
  "  mov.b #1, &100\n"
  ".org 2\n"
  "fifth:\n"
  "  mov.w #fourth, &100\n\n";

const char *msp430_5 =
  ".msp430x\n"
  ".org 0x200\n"
  "first:\n"
  "  pushx.a #blah4\n"
  "second:\n"
  "  calla fifth\n"
  "third:\n"
  "  pushx.a #blah5\n"
  "fourth:\n"
  "  mov.b #1, &100\n"
  ".org 2\n"
  "fifth:\n"
  "  mov.w #fourth, &100\n"
  ".org 0xffff\n"
  "blah4:\n"
  ".org 0xfffff\n"
  "blah5:\n";

const char *msp430_6 =
  ".msp430\n"
  ".org 0x200\n"
  "first:\n"
  "  mov.w 0(r4), r4\n"
  "second:\n"
  "  mov.w fifth(r4), r4\n"
  "third:\n"
  "  mov.w 6(r4), fifth(r4)\n"
  "fourth:\n"
  "  mov.w second(r4), r4\n"
  ".org 2\n"
  "fifth:\n"
  "  mov.w #fourth, blah4(r5)\n"
  ".org 0xffff\n"
  "blah4:\n"
  ".org 0xfffff\n"
  "blah5:\n";

const char *msp430_7 =
  ".msp430x\n"
  ".org 0x200\n"
  "first:\n"
  "  rra.b 0(r4)\n"
  "second:\n"
  "  rra.w fifth(r4)\n"
  "third:\n"
  "  mova 0(r4), r5\n"
  "fourth:\n"
  "  mova fifth(r4), r4\n"
  ".org 0\n"
  "fifth:\n"
  "  mov.w #fourth, blah4(r5)\n"
  ".org 0xffff\n"
  "blah4:\n"
  ".org 0xfffff\n"
  "blah5:\n";

