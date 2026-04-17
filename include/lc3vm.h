/** @file lc3vm.h
 * @brief LC-3 VM API
 *
 * @author Kadin Ahmad
 * @note   cwid: 50341941
 * @date   Spring 2026
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for LC-3 simulator API/functions.
 */
#include <stdbool.h>
#include <stdint.h>

#ifndef LC3VM_H
#define LC3VM_H

// total number of opcodes in the LC-3 architecture.
#define NUMOPS (16)

// Need to #define all of your bit manipulation macros like DR, SR1, etc. here.
#define FIMM(i) ((i >> 5) & 0x1)
#define FCND(i) (((i) >> 9) & 0x7)
#define BR(i) (((i) >> 6) & 0x7)
#define FL(i) (((i) >> 11) & 1)
#define TRP(i) ((i) & 0xFF)

// Task 3
#define OPC(i) ((i) >> 12)
#define SR2(i) ((i) & 0x0007)
#define SR1(i) (((i) >> 6) & 0x0007)
#define DR(i) (((i) >> 9) & 0x0007)
#define SEXTIMM(i) sign_extend((i), 5)
#define OFF6(i) sign_extend((i), 6)
#define PCOFF9(i) sign_extend((i), 9)
#define PCOFF11(i) sign_extend((i), 11)

typedef void (*op_ex_f)(uint16_t i);
typedef void (*trp_ex_f)();

enum
{
  trp_offset = 0x20
};

enum registr
{
  R0 = 0,
  R1,
  R2,
  R3,
  R4,
  R5,
  R6,
  R7,
  RPC,
  RCND,
  RCNT
};

enum flags
{
  FP = 1 << 0,
  FZ = 1 << 1,
  FN = 1 << 2
};

// If we are creating tests, make all declarations extern C so can
// work with catch2 C++ framework
#ifdef TEST
extern "C" {
#endif

extern bool running;
extern uint16_t mem[];
extern uint16_t reg[];
extern uint16_t PC_START;

// your task functions should go here

// Task 1
uint16_t mem_read(uint16_t addr);
void mem_write(uint16_t addr, uint16_t val);

// Task 2
uint16_t sign_extend(uint16_t bits, int size);

// Task 3 located towards top of file

// Task 4
void update_flags(enum registr r);

// Task 5
void add(uint16_t i);
void andlc(uint16_t i);
void notlc(uint16_t i);

// Task 6
void ld(uint16_t i);
void ldi(uint16_t i);
void ldr(uint16_t i);
void lea(uint16_t i);

// Task 7
void st(uint16_t i);
void sti(uint16_t i);
void str(uint16_t i);

// Task 8
void jmp(uint16_t i);
void br(uint16_t i);
void jsr(uint16_t i);

// Task 9
// No implementation needed

// Task 10
void start(uint16_t offset);

void rti(uint16_t i);
void res(uint16_t i);
void tgetc();
void tout();
void tputs();
void tin();
void thalt();
void tinu16();
void toutu16();
void trap(uint16_t i);
void ld_img(char* fname, uint16_t offset);

#ifdef TEST
} // end extern C for C++ test runner
#endif

#endif // LC3VM_H
