Commands algorithm

	end_frame command -> get_size -> pop
	push commnad -> get_size -> push
	arithmetic and logic:
		binary command -> get_type_op_1 -> pop_op_1 -> get_type_op_2 -> pop_op_2 -> type_casting -> operation -> push
		unary command -> get_type_op -> pop_op -> operation -> push
	multiply operand:
		get_number_operands -> binary_command -> dec_number_operands

Types

	default:
	bool (1 byte)
	byte unsigned  (1 byte)
	sbyte signed   (1 byte)
	short signed    (2 byte)
	ushort unsigned (2 byte)	
	
	extended:
	int signed (4 byte)
	uint unsigned (4 byte)
	long signed ( 8 byte)
	ulong unsigned (8 byte )

	float:
	float (4 byte)
	
	double:
	double (8 byte)

Operations

	default:
		arithmetic and logic:
			binary: add, sub, mul, div(exception), and, or, shl, shr
			unary:  inc, dec, neg, not
	
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
  	5- 
  	6-
  	7-

Example

	// first byte is vm version
	// don't need push command in the start of code
	   	-> 6 byte
	5 	-> byte
	8 	-> byte
	9 -> byte
	mul	pop 5, 8 push byte 40
	sub	pop 40, 9 push byte 31


