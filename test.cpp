
#include "src/vm.h"
#include "src/stack.h"
#include <iostream>
#include "gtest/gtest.h"


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
    uint16_t in_short = 3;
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
    res = get_head();
    EXPECT_EQ(*res, 4 + 5);
}

TEST(VMTest, Add_ubyte_intruction_overfilling) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 255, 2, ADD_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = get_head();
    EXPECT_EQ(*res, uint8_t(uint8_t(255) + uint8_t(2)));
}

TEST(VMTest, Mul_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_mul[5] = {PUSH, 2, 4, 5, MUL_BYTE};
    EXPECT_EQ(execute_intruction(code_mul, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_mul, &pc), SUCCESS);
    res = get_head();
    EXPECT_EQ(*res, 4 * 5);
}

TEST(VMTest, Sub_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 4, 5, SUB_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = get_head();
    EXPECT_EQ(*res, 5 - 4);
}

TEST(VMTest, Div_ubyte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 3, 27, DIV_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = get_head();
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
    res = (int8_t *)get_head();
    EXPECT_EQ(*res, -3 + 9);
}

TEST(VMTest, Mul_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 9, -3, MUL_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)get_head();
    EXPECT_EQ(*res, -3 * 9);
}

TEST(VMTest, Sub_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 3, 1, SUB_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)get_head();
    EXPECT_EQ(*res, 1 - 3);
}

TEST(VMTest, Div_sbyte_intruction) {
    uint16_t pc = 0;
    int8_t *res;
    uint8_t code_add[5] = {PUSH, 2, -9, 27, DIV_SBYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (int8_t *)get_head();
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
    uint8_t code_add[7] = {PUSH, 4, 0, 4, 0, 5, ADD_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (uint16_t *)get_head();
    EXPECT_EQ(*res, 4 + 5);
}

TEST(VMTest, Add_ushort_intruction_2) {
    uint16_t pc = 0;
    uint16_t *res;
    uint8_t code_add[7] = {PUSH, 4, 1, 4, 0, 5, ADD_SHORT};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = (uint16_t *)get_head();
    EXPECT_EQ(*res, 256 + 4 + 5);
}
