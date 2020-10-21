#ifndef _H_DELAY_
#define _H_DELAY_

#define _NOP_LOOP(x) \
  __asm__( \
    /* 1 */ "mov r0,#" #x "\n" \
    /* - */ "1:\n"             \
    /* 1 */ "sub r0,#1\n"      \
    /* 1 */ "cmp r0,#0\n"      \
    /* 1 */ "bge 1b\n"         \
      ::: "r0" \
  )

#define NOP_LOOP(x) _NOP_LOOP(((x) / 3) - 1)
#define DELAY_NS(x) NOP_LOOP((x) / (1000000000/72000000))
#define DELAY_US(x) DELAY_NS((x) * 1000)

#endif
