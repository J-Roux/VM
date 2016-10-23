
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
    EXPECT_EQ(pointer, -1);
    EXPECT_EQ(out_byte, in_byte);
}


TEST(StackTest, Push_short) {
    uint16_t out_short = 2;
    uint16_t in_short = 3;


    EXPECT_EQ(push_short(in_short), SUCCESS);
    EXPECT_EQ(pop_short(&out_short), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, -1);
    EXPECT_EQ(out_short, in_short);
}


TEST(StackTest, Push_int) {
    uint32_t out_int = 9;
    uint32_t in_int = 10;
    EXPECT_EQ(push_int(in_int), SUCCESS);
    EXPECT_EQ(pop_int(&out_int), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, -1);
    EXPECT_EQ(out_int, in_int);
}


TEST(StackTest, Push_long) {
    uint64_t out_long = 13;
    uint64_t in_long = 14;
    EXPECT_EQ(push_long(in_long), SUCCESS);
    EXPECT_EQ(pop_long(&out_long), SUCCESS);
    ptr_size pointer = get_pointer();
    EXPECT_EQ(pointer, -1);
    EXPECT_EQ(out_long, in_long);
}


TEST(VMTest, Mul_byte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_mul[5] = {PUSH, 2, 4, 5, MUL_BYTE};
    EXPECT_EQ(execute_intruction(code_mul, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_mul, &pc), SUCCESS);
    res = get_head();
    EXPECT_EQ(*res, 4 * 5);
}


TEST(VMTest, Add_byte_intruction) {
    uint16_t pc = 0;
    uint8_t *res;
    uint8_t code_add[5] = {PUSH, 2, 4, 5, ADD_BYTE};
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    EXPECT_EQ(execute_intruction(code_add, &pc), SUCCESS);
    res = get_head();
    EXPECT_EQ(*res, 4 + 5);
}








