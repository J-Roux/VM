
#include "../src/vm.h"
#include "../src/stack.h"
#include "../src/code_stream.h"
#include <iostream>
#include <functional>
#include <vector>
#include "gtest/gtest.h"
#include <type_traits>

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


template<class T, typename type>
void TestMethod(COMMANDS command, type op1, type op2);

template<class T>
auto get_code(T op1, T op2, COMMANDS command );


template<>
auto get_code<uint8_t>(uint8_t op1, uint8_t op2, COMMANDS command)
{
        return std::vector<uint8_t>({ PUSH, 2, op1, op2, (uint8_t)command });
}

template<>
auto get_code<uint16_t>(uint16_t op1, uint16_t op2, COMMANDS command)
{
        union{ uint16_t data; struct { uint8_t hi; uint8_t lo;}; } o1, o2;
        o1.data = op1;
        o2.data = op2;
        return std::vector<uint8_t>({ PUSH, 4, o1.hi , o1.lo, o2.hi, o2.lo, uint8_t(command) });
}

template<>
auto get_code<uint32_t>(uint32_t op1, uint32_t op2, COMMANDS command)
{
        union{ uint32_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;}; } o1, o2;
        o1.data = op1;
        o2.data = op2;
        return std::vector<uint8_t> ({uint8_t(PUSH), 8, o1.one, o1.two, o1.three, o1.four, o2.one, o2.two, o2.three, o2.four, uint8_t(command)});
}

template<>
auto get_code<uint64_t>(uint64_t op1, uint64_t op2, COMMANDS command)
{
        union{ uint64_t data; struct { uint8_t one; uint8_t two; uint8_t three; uint8_t four;
                                       uint8_t five; uint8_t six; uint8_t seven; uint8_t eight;}; } o1, o2;
        o1.data = op1;
        o2.data = op2;
        return std::vector<uint8_t> ({uint8_t(PUSH), 16,
                                      o1.one, o1.two, o1.three, o1.four, o1.five, o1.six, o1.seven, o1.eight,
                                      o2.one, o2.two, o2.three, o2.four, o2.five, o2.six, o2.seven, o2.eight,
                                      uint8_t(command)});

}


template<class T, class type >
void TestMethod(COMMANDS command, type op1, type op2) {
        using code_type = typename std::make_unsigned<type>::type;
        uint16_t pc = 0;
        auto code = get_code<code_type>(op1, op2, command);
        set_code(code.data(), code.size());
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);
        jmp(0);
        auto res = GET_HEAD(type);
        EXPECT_EQ(*res, T{}(op2, op1));
}



template<typename T = void>
struct shift_right;

template<typename T = void>
struct shift_left;

template<>
struct shift_right<void>
{
        template< class T, class U>
        constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(std::forward<T>(lhs) >> std::forward<U>(rhs))
        {
                return    std::forward<T>(lhs) >> std::forward<U>(rhs);
        }
};

template<>
struct shift_left<void>
{
        template< class T, class U>
        constexpr auto operator()(T&& lhs, U&& rhs) const-> decltype(std::forward<T>(lhs) << std::forward<U>(rhs))
        {
                return    std::forward<T>(lhs) << std::forward<U>(rhs);
        }
};


template<typename T = void>
struct negative;

template<>
struct negative<void>
{
        template< class T, class U>
        constexpr auto operator()(T&& lhs, U&& rhs) const-> decltype(std::forward<T>(lhs) - std::forward<U>(rhs))
        {
                return    std::forward<T>(lhs) - std::forward<U>(rhs);
        }
};

TEST(VMTest, Dub_command){
    data = std::vector<uint8_t>({PUSH, 1, 5, DUB, 0, 1}).data();
    EXPECT_EQ(execute_intruction(), SUCCESS);
    EXPECT_EQ(execute_intruction(), SUCCESS);
    auto res = GET_HEAD(uint8_t);
    EXPECT_EQ(5, *res);
}


TEST(VMTest, Eq_byte_intruction) {
        TestMethod<std::equal_to<>, uint8_t>(EQ_BYTE, 2, 5);
        TestMethod<std::equal_to<>, uint8_t>(EQ_BYTE, 5, 5);
}

TEST(VMTest, Neq_byte_intruction) {
        TestMethod<std::not_equal_to<>, uint8_t>(NEQ_BYTE, 2, 5);
        TestMethod<std::not_equal_to<>, uint8_t>(NEQ_BYTE, 5, 5);
}



TEST(VMTest, Shr_byte_intruction) {
        TestMethod<shift_right<>, uint8_t>(SHR_BYTE, 2, 5);
}

TEST(VMTest, Shl_byte_intruction) {
        TestMethod<shift_left<>, uint8_t>(SHL_BYTE, 2, 5);
}

TEST(VMTest, And_byte_intruction) {
        TestMethod<std::bit_and<>, uint8_t>(AND_BYTE, 4, 5);
}

TEST(VMTest, Or_byte_intruction) {
        TestMethod<std::bit_or<>, uint8_t>(OR_BYTE, 4, 5);
}


TEST(VMTest, Add_ubyte_intruction) {
        TestMethod<std::plus<>, uint8_t>(ADD_BYTE, 4, 5);
}


TEST(VMTest, Mul_ubyte_intruction) {
        TestMethod<std::multiplies<>, uint8_t>(MUL_BYTE, 4, 5);
}

TEST(VMTest, Sub_ubyte_intruction) {
        TestMethod<std::minus<>, uint8_t>(SUB_BYTE, 4, 5);
}

TEST(VMTest, Div_ubyte_intruction) {
        TestMethod<std::divides<>, uint8_t>(DIV_BYTE, 3, 27);
}


TEST(VMTest, Add_sbyte_intruction) {
        TestMethod<std::plus<>, int8_t>(ADD_BYTE, -3, 9);
}

TEST(VMTest, Mul_sbyte_intruction) {
        TestMethod<std::multiplies<>, int8_t>(MUL_BYTE, 40, -3);
}

TEST(VMTest, Sub_sbyte_intruction) {
        TestMethod<std::minus<>, int8_t>(SUB_BYTE, 3, 1);
}

TEST(VMTest, Div_sbyte_intruction) {
        TestMethod<std::divides<>, int8_t>(DIV_SBYTE, -9, 27);
}




TEST(VMTest, And_short_intruction) {
        TestMethod<std::bit_and<>, uint16_t>(AND_SHORT, 5, 260);
}


TEST(VMTest, Or_short_intruction) {
        TestMethod<std::bit_or<>, uint16_t>(OR_SHORT, 5, 260);
}


TEST(VMTest, Shr_short_intruction) {
        TestMethod<shift_right<>, uint16_t>(SHR_SHORT, 5, 260);
}



TEST(VMTest, Shl_short_intruction) {
        TestMethod<shift_left<>, uint16_t>(SHL_SHORT, 5, 260);
}


TEST(VMTest, Add_ushort_intruction) {
        TestMethod<std::plus<>, uint16_t>(ADD_SHORT, 5, 260);
}


TEST(VMTest, Mul_ushort_intruction) {
        TestMethod<std::multiplies<>, uint16_t>(MUL_SHORT, 5, 260);
}


TEST(VMTest, Sub_ushort_intruction) {
        TestMethod<std::minus<>, uint16_t>(SUB_SHORT, 5, 260);
}



TEST(VMTest, Div_ushort_intruction) {
        TestMethod<std::divides<>, uint16_t>(DIV_SHORT, 5, 260);
}




TEST(VMTest, Add_sshort_intruction) {
        TestMethod<std::plus<>, int16_t>(ADD_SHORT, -5, 260);
}


TEST(VMTest, Mul_sshort_intruction) {
        TestMethod<std::multiplies<>, int16_t>(MUL_SHORT, -5, 260);
}


TEST(VMTest, Sub_sshort_intruction) {
        TestMethod<std::minus<>, int16_t>(SUB_SHORT, -5, 260);
}



TEST(VMTest, Div_sshort_intruction) {
        TestMethod<std::divides<>, int16_t>(DIV_SSHORT, -5, 260);
}




TEST(VMTest, And_int_intruction) {
        TestMethod<std::bit_and<>, uint32_t>(AND_INT, 5, 33000);
}


TEST(VMTest, Or_int_intruction) {
        TestMethod<std::bit_or<>, uint32_t>(OR_INT, 5, 33000);
}

TEST(VMTest, Shr_int_intruction) {
        TestMethod<shift_right<>, uint32_t>(SHR_INT, 5, 33000);

}

TEST(VMTest, Shl_int_intruction) {
        TestMethod<shift_left<>, uint32_t>(SHL_INT, 5, 33000);
}



TEST(VMTest, Add_int_intruction) {
        TestMethod<std::plus<>, uint32_t>(ADD_INT, 5, 33000);
}


TEST(VMTest, Sub_int_intruction) {
        TestMethod<std::minus<>, uint32_t>(SUB_INT, 5, 33000);
}

TEST(VMTest, Mul_int_intruction) {
        TestMethod<std::multiplies<>, uint32_t>(MUL_INT, 5, 33000);

}

TEST(VMTest, Div_int_intruction) {
        TestMethod<std::divides<>, uint32_t>(DIV_INT, 5, 33000);
}

TEST(VMTest, Add_sint_intruction) {
        TestMethod<std::plus<>, int32_t>(ADD_INT, -5, 33000);
}


TEST(VMTest, Sub_sint_intruction) {
        TestMethod<std::minus<>, int32_t>(SUB_INT, -5, 33000);
}

TEST(VMTest, Mul_sint_intruction) {
        TestMethod<std::multiplies<>, int32_t>(MUL_INT, -5, 33000);
}

TEST(VMTest, Div_sint_intruction) {
        TestMethod<std::divides<>, int32_t>(DIV_SINT, -5, 33000);
}


TEST(VMTest, And_long_intruction) {
        TestMethod<std::bit_and<>, uint64_t>(AND_LONG, 5, 33000);
}


TEST(VMTest, Or_long_intruction) {
        TestMethod<std::bit_or<>, uint64_t>(OR_LONG, 5, 33000);
}

TEST(VMTest, Shr_long_intruction) {
        TestMethod<shift_right<>, uint64_t>(SHR_LONG, 5, 33000);

}

TEST(VMTest, Shl_long_intruction) {
        TestMethod<shift_left<>, uint64_t>(SHL_LONG, 5, 33000);
}



TEST(VMTest, Add_long_intruction) {
        TestMethod<std::plus<>, uint64_t>(ADD_LONG, 5, 33000);
}


TEST(VMTest, Sub_long_intruction) {
        TestMethod<std::minus<>, uint64_t>(SUB_LONG, 5, 33000);
}

TEST(VMTest, Mul_long_intruction) {
        TestMethod<std::multiplies<>, uint64_t>(MUL_LONG, 5, 33000);

}

TEST(VMTest, Div_long_intruction) {
        TestMethod<std::divides<>, uint64_t>(DIV_LONG, 5, 33000);
}



TEST(VMTest, Add_slong_intruction) {
        TestMethod<std::plus<>, int64_t>(ADD_LONG, -5, 33000);
}


TEST(VMTest, Sub_slong_intruction) {
        TestMethod<std::minus<>, int64_t>(SUB_LONG, -5, 33000);
}

TEST(VMTest, Mul_slong_intruction) {
        TestMethod<std::multiplies<>, int64_t>(MUL_LONG, -5, 33000);
}

TEST(VMTest, Div_slong_intruction) {
        TestMethod<std::divides<>, int64_t>(DIV_SLONG, -5, 33000);
}




TEST(VMTest, Jmp_intruction) {
        data = std::vector<uint8_t>({PUSH, 2, 1, 7, ADD_BYTE, JMP, 6, 0}).data();
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);

}

TEST(VMTest, Jt_intruction) {

        data = std::vector<uint8_t>({PUSH, 2, 7, 7, EQ_BYTE, JT, 6, 0}).data();
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);

        data = std::vector<uint8_t>({PUSH, 2, 7, 4, EQ_BYTE, JT, 6, 0}).data();
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);
        EXPECT_EQ(execute_intruction(), SUCCESS);

}




