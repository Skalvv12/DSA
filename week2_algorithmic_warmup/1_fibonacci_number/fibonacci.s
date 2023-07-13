	.file	"fibonacci.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z15fibonacci_naivei
	.type	_Z15fibonacci_naivei, @function
_Z15fibonacci_naivei:
.LFB1522:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jg	.L2
	movl	-20(%rbp), %eax
	jmp	.L3
.L2:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	_Z15fibonacci_naivei
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	_Z15fibonacci_naivei
	addl	%ebx, %eax
.L3:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1522:
	.size	_Z15fibonacci_naivei, .-_Z15fibonacci_naivei
	.globl	_Z14fibonacci_fasti
	.type	_Z14fibonacci_fasti, @function
_Z14fibonacci_fasti:
.LFB1523:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -36(%rbp)
	cmpl	$1, -36(%rbp)
	jg	.L5
	movl	-36(%rbp), %eax
	cltq
	jmp	.L6
.L5:
	movq	$0, -24(%rbp)
	movq	$1, -16(%rbp)
	movl	$0, -28(%rbp)
.L8:
	movl	-36(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -28(%rbp)
	jnb	.L7
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	addq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	addl	$1, -28(%rbp)
	jmp	.L8
.L7:
	movq	-16(%rbp), %rax
.L6:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1523:
	.size	_Z14fibonacci_fasti, .-_Z14fibonacci_fasti
	.section	.rodata
.LC0:
	.string	"void test_solution()"
.LC1:
	.string	"fibonacci.cpp"
.LC2:
	.string	"fibonacci_fast(3) == 2"
.LC3:
	.string	"fibonacci_fast(10) == 55"
	.align 8
.LC4:
	.string	"fibonacci_fast(n) == fibonacci_naive(n)"
	.text
	.globl	_Z13test_solutionv
	.type	_Z13test_solutionv, @function
_Z13test_solutionv:
.LFB1524:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	$3, %edi
	call	_Z14fibonacci_fasti
	cmpq	$2, %rax
	je	.L10
	leaq	.LC0(%rip), %rcx
	movl	$41, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	__assert_fail@PLT
.L10:
	movl	$10, %edi
	call	_Z14fibonacci_fasti
	cmpq	$55, %rax
	je	.L11
	leaq	.LC0(%rip), %rcx
	movl	$42, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	call	__assert_fail@PLT
.L11:
	movl	$0, -20(%rbp)
.L14:
	cmpl	$19, -20(%rbp)
	jg	.L15
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	_Z14fibonacci_fasti
	movq	%rax, %rbx
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	_Z15fibonacci_naivei
	cltq
	cmpq	%rax, %rbx
	je	.L13
	leaq	.LC0(%rip), %rcx
	movl	$44, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC4(%rip), %rdi
	call	__assert_fail@PLT
.L13:
	addl	$1, -20(%rbp)
	jmp	.L14
.L15:
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1524:
	.size	_Z13test_solutionv, .-_Z13test_solutionv
	.globl	main
	.type	main, @function
main:
.LFB1525:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -12(%rbp)
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSirsERi@PLT
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	_Z14fibonacci_fasti
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEm@PLT
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L18
	call	__stack_chk_fail@PLT
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1525:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2008:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L21
	cmpl	$65535, -8(%rbp)
	jne	.L21
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L21:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2008:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z15fibonacci_naivei, @function
_GLOBAL__sub_I__Z15fibonacci_naivei:
.LFB2009:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2009:
	.size	_GLOBAL__sub_I__Z15fibonacci_naivei, .-_GLOBAL__sub_I__Z15fibonacci_naivei
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z15fibonacci_naivei
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
