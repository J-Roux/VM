###YASM[![Build Status](https://travis-ci.org/J-Roux/YASM.svg?branch=master)](https://travis-ci.org/J-Roux/YASM)

Algorithms

	call func:
		push return address -> push args -> push func id -> call command -> func body computation -> result on top -> push pointer to ret address -> erase return address -> jump
	
	arithmetic and logic:
		binary command -> pop_op_1 -> pop_op_2  -> operation -> push
		unary command -> pop_op -> operation -> push
	branch:
		jmp command -> get_pos -> change_pc
		je command -> get_pos -> get_value -> value to bool -> if true -> change_pc
	mem:
		push command -> get_size -> push
		pop command -> get_size -> pop
	multiply operand:
		get_number_operands -> binary_command -> dec_number_operands

Exceptions

	stack overflow
	code use wider instruction set
	division by zero


Types

	default:
	byte unsigned   (1 byte)
	sbyte signed    (1 byte)
	short signed    (2 byte)
	ushort unsigned (2 byte)	
	
	extended:
	int signed      (4 byte)
	uint unsigned   (4 byte)
	long signed     (8 byte)
	ulong unsigned  (8 byte)

	float:
	float           (4 byte)
	
	double:
	double          (8 byte)

Func

	call func:
	|     *******    |
	| return address |
	|     arg one    |
	|     *******    |
	|      arg n     | <- head
	
	stack after func coputation
	|     *******    |
	| return address |<--
	| func return val|  |
	| ptr to ret addr|---   <-head
	
Operations

	default:
		arithmetic and logic(type depended *_bool, *_byte, *_sbyte, *_short, *_sshort .. etc) :
			binary: add, sub, mul, div(exception), and, or, shl, shr, eq, neq, lt, leq, gt, geq 
			unary:  inc, dec, neg, not
		branch:
			jmp, je 
		mem:
			push, pop
		type cast:
			one_to_two, one_to_four, two_to_one, two_to_four, four_to_one, four_to_two
			
	arithmetic and logic extended:
		binary: mod, pow	

	multiply operand:
		arithmetic and logic:
			m_add, m_mul, m_and, m_or - need param on stack head

Version format

	Bits:
 	0- type extendent
  	1- float
  	2- double
  	3- extendent arith operation
  	4- multiply operand 
  	5- string intruction(future)
  	6- arrays(future)
  	7- 

Example

	// first byte is vm version
	// don't need push command in the start of code
		-> 3 
	5 	-> byte
	8 	-> byte
	9 	-> byte
	mul_byte pop 5, 8 push byte 40 
	sub_byte pop 40, 9 push byte 31
	------------------
	overfall: 7 byte

