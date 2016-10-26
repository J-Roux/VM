
#include "src/vm.h"
#include "src/stack.h"
#include <iostream>
#include "gtest/gtest.h"

#define GET_HEAD(TYPE) (TYPE *)get_head(sizeof(TYPE))




TEST(StackTest, Push_byte) {
    uint8_t out_byte = 0;
    uint8_t in_byte = 1;
    EXPECT_EQ(push_byte(in_byte), SUCCESS);
    EXPECT_EQ(pop_byte(&out_byte), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, STACK_START_ADDRESS);
    EXPECT_EQ(out_byte, in_byte);
}


TEST(StackTest, Push_short) {
    uint16_t out_short = 2;
    uint16_t in_short = 256;
    EXPECT_EQ(push_short(in_short), SUCCESS);
    EXPECT_EQ(pop_short(&out_short), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, STACK_START_ADDRESS);
    EXPECT_EQ(out_short, in_short);
}


TEST(StackTest, Push_int) {
    uint32_t out_int = 9;
    uint32_t in_int = 10;
    EXPECT_EQ(push_int(in_int), SUCCESS);
    EXPECT_EQ(pop_int(&out_int), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, STACK_START_ADDRESS);
    EXPECT_EQ(out_int, in_int);
}


TEST(StackTest, Push_long) {
    uint64_t out_long = 13;
    uint64_t in_long = 14;
    EXPECT_EQ(push_long(in_long), SUCCESS);
    EXPECT_EQ(pop_long(&out_long), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, STACK_START_ADDRESS);
    EXPECT_EQ(out_long, in_long);
}


TEST(VMTest, Add_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 4, 5, ADD_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, STACK_START_ADDRESS + 1);
    res = GET_HEAD(uint8_t);
    EXPECT_EQ(*res, 4 + 5);
}

TEST(VMTest, Add_ubyte_intruction_overfilling) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 255, 2, ADD_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint8_t);
    EXPECT_EQ(*res, uint8_t(uint8_t(255) + uint8_t(2)));
}

TEST(VMTest, Mul_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_mul[5] = {PUSH, 2, 4, 5, MUL_BYTE};
    EXPECT_EQ(execute_intruction(code_mul, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_mul, &pc), SUCCESS);
    res = GET_HEAD(uint8_t);
    EXPECT_EQ(*res, 4 * 5);
}

TEST(VMTest, Sub_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 4, 5, SUB_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint8_t);
    EXPECT_EQ(*res, 5 - 4);
}

TEST(VMTest, Div_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 3, 27, DIV_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint8_t);
    EXPECT_EQ(*res, 27 / 3);
}

TEST(VMTest, Div_ubyte_intruction_by_zero) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 0, 27, DIV_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), DIV_BY_ZERO);
}

TEST(VMTest, Add_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 9, -3, ADD_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)GET_HEAD(uint8_t);
    EXPECT_EQ(*res, -3 + 9);
}

TEST(VMTest, Mul_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 9, -3, MUL_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)GET_HEAD(uint8_t);
    EXPECT_EQ(*res, -3 * 9);
}

TEST(VMTest, Sub_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 3, 1, SUB_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)GET_HEAD(uint8_t);
    EXPECT_EQ(*res, 1 - 3);
}

TEST(VMTest, Div_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, -9, 27, DIV_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)GET_HEAD(uint8_t);
    EXPECT_EQ(*res, 27 / -9);
}

TEST(VMTest, Div_sbyte_intruction_by_zero) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 0, -27, DIV_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), DIV_BY_ZERO);
}



TEST(VMTest, Add_ushort_intruction) {
    uint16_t pc = 0;
    uint16_t *res;
    union{ uint16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 260;
    op2.data = 5;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, ADD_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint16_t);
    EXPECT_EQ(*res, 260 + 5 );
}


TEST(VMTest, Mul_ushort_intruction) {
    uint16_t pc = 0;
    uint16_t *res;
    union{ uint16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 260;
    op2.data = 5;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, MUL_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint16_t);
    EXPECT_EQ(*res, 260 * 5 );
}


TEST(VMTest, Sub_ushort_intruction) {
    uint16_t pc = 0;
    uint16_t *res;
    union{ uint16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 5;
    op2.data = 260;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, SUB_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint16_t);
    EXPECT_EQ(*res, 260 - 5 );
}



TEST(VMTest, Div_ushort_intruction) {
    uint16_t pc = 0;
    uint16_t *res;
    union{ uint16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 5;
    op2.data = 260;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, DIV_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint16_t);
    EXPECT_EQ(*res, 260 / 5 );
}


TEST(VMTest, Div_ushort_intruction_by_zero) {
    uint16_t pc = 0;
    uint16_t *res;
    union{ uint16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 0;
    op2.data = 260;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, DIV_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), DIV_BY_ZERO);
}


TEST(VMTest, Add_sshort_intruction) {
    uint16_t pc = 0;
    int16_t *res;
    union{ int16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = -260;
    op2.data = 5;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, ADD_SSHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int16_t);
    EXPECT_EQ(*res, -260 + 5 );
}


TEST(VMTest, Mul_sshort_intruction) {
    uint16_t pc = 0;
    int16_t *res;
    union{ int16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = -260;
    op2.data = 5;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, MUL_SSHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int16_t);
    EXPECT_EQ(*res, -260 * 5 );
}


TEST(VMTest, Sub_sshort_intruction) {
    uint16_t pc = 0;
    int16_t *res;
    union{ int16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 260;
    op2.data = 5;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, SUB_SSHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int16_t);
    EXPECT_EQ(*res,  5 - 260 );
}



TEST(VMTest, Div_sshort_intruction) {
    uint16_t pc = 0;
    int16_t *res;
    union{ int16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = -5;
    op2.data = 260;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, DIV_SSHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int16_t);
    EXPECT_EQ(*res, 260 /- 5 );
}

TEST(VMTest, Div_sshort_intruction_by_zero) {
    uint16_t pc = 0;
    int16_t *res;
    union{ int16_t data; struct { uint8_t hi; uint8_t lo;}; } op1, op2;
    op1.data = 0;
    op2.data = 260;
    uint8_t code_add[7] = {PUSH, 4, op1.hi, op1.lo, op2.hi, op2.lo, DIV_SSHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), DIV_BY_ZERO);

}


TEST(VMTest, Add_int_intruction) {
    uint16_t pc = 0;
    uint32_t *res;
    union{ uint32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 33000;
    op2.data = 5;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, ADD_INT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint32_t);
    EXPECT_EQ(*res, 33000 + 5);
}


TEST(VMTest, Sub_int_intruction) {
    uint16_t pc = 0;
    uint32_t *res;
    union{ uint32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 5;
    op2.data = 33000;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, SUB_INT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint32_t);
    EXPECT_EQ(*res, 33000 - 5);
}

TEST(VMTest, Mul_int_intruction) {
    uint16_t pc = 0;
    uint32_t *res;
    union{ uint32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 33000;
    op2.data = 5;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, MUL_INT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint32_t);
    EXPECT_EQ(*res, 33000 * 5);
}

TEST(VMTest, Div_int_intruction) {
    uint16_t pc = 0;
    uint32_t *res;
    union{ uint32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 5;
    op2.data = 33000;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, DIV_INT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(uint32_t);
    EXPECT_EQ(*res, 33000 / 5);
}

TEST(VMTest, Div_int_intruction_by_zero) {
    uint16_t pc = 0;
    uint32_t *res;
    union{ uint32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 0;
    op2.data = 33000;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, DIV_INT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), DIV_BY_ZERO);
}

TEST(VMTest, Add_sint_intruction) {
    uint16_t pc = 0;
    int32_t *res;
    union{ int32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = -33000;
    op2.data = 5;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, ADD_SINT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int32_t);
    EXPECT_EQ(*res, -33000 + 5);
}


TEST(VMTest, Sub_sint_intruction) {
    uint16_t pc = 0;
    int32_t *res;
    union{ int32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 33000;
    op2.data = 5;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, SUB_SINT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int32_t);
    EXPECT_EQ(*res, 5 - 33000);
}

TEST(VMTest, Mul_sint_intruction) {
    uint16_t pc = 0;
    int32_t *res;
    union{ int32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 33000;
    op2.data = -5;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, MUL_SINT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int32_t);
    EXPECT_EQ(*res, 33000 * -5);
}

TEST(VMTest, Div_sint_intruction) {
    uint16_t pc = 0;
    int32_t *res;
    union{ int32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = -5;
    op2.data = 33000;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, DIV_SINT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = GET_HEAD(int32_t);
    EXPECT_EQ(*res, 33000 / -5);
}

TEST(VMTest, Div_sint_intruction_by_zero) {
    uint16_t pc = 0;
    int32_t *res;
    union{ int32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } op1, op2;
    op1.data = 0;
    op2.data = -33000;
    uint8_t code_add[11] = {PUSH, 8, op1.one, op1.two, op1.three, op1.four, op2.one, op2.two, op2.three, op2.four, DIV_SINT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), DIV_BY_ZERO);
}
