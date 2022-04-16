.68000

.binfile "s3k.bin"

.define TIME_BONUS_COUNTDOWN $F7D2
.define RING_BONUS_COUNTDOWN $F7D4

.org 0x2DC5C
move.w (TIME_BONUS_COUNTDOWN).w,d0
move.w #0,(TIME_BONUS_COUNTDOWN).w
add.w (RING_BONUS_COUNTDOWN).w,d0
move.w #0,(RING_BONUS_COUNTDOWN).w
jmp $0002DC7E

// A copy of the code overwritten above also exists at 0x2E484, but that seems to be for special stage results, which aren't removed from timing
