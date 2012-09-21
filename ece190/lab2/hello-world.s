	.file	"hello-world.i"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Leh_func_begin0:
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp0:
	movq	%rsp, %rbp
.Ltmp1:
	subq	$16, %rsp
.Ltmp2:
	movl	$0, %eax
	leaq	.L.str, %rdi
	movl	$0, -4(%rbp)
	movl	%eax, -8(%rbp)          # 4-byte Spill
	callq	puts
	movl	%eax, -12(%rbp)         # 4-byte Spill
	movl	-8(%rbp), %eax          # 4-byte Reload
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp3:
	.size	main, .Ltmp3-main
.Leh_func_end0:

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Hello, world!"
	.size	.L.str, 14

	.section	.eh_frame,"a",@progbits
.LEH_frame0:
.Lsection_eh_frame0:
.Leh_frame_common0:
.Lset0 = .Leh_frame_common_end0-.Leh_frame_common_begin0 # Length of Common Information Entry
	.long	.Lset0
.Leh_frame_common_begin0:
	.long	0                       # CIE Identifier Tag
	.byte	1                       # DW_CIE_VERSION
	.asciz	 "zR"                   # CIE Augmentation
	.byte	1                       # CIE Code Alignment Factor
	.byte	120                     # CIE Data Alignment Factor
	.byte	16                      # CIE Return Address Column
	.byte	1                       # Augmentation Size
	.byte	3                       # FDE Encoding = udata4
	.byte	12                      # DW_CFA_def_cfa
	.byte	7                       # Register
	.byte	8                       # Offset
	.byte	144                     # DW_CFA_offset + Reg (16)
	.byte	1                       # Offset
	.align	8
.Leh_frame_common_end0:
.Lmain.eh:
.Lset1 = .Leh_frame_end0-.Leh_frame_begin0 # Length of Frame Information Entry
	.long	.Lset1
.Leh_frame_begin0:
.Lset2 = .Leh_frame_begin0-.Leh_frame_common0 # FDE CIE offset
	.long	.Lset2
	.long	.Leh_func_begin0        # FDE initial location
.Lset3 = .Leh_func_end0-.Leh_func_begin0 # FDE address range
	.long	.Lset3
	.byte	0                       # Augmentation size
	.byte	4                       # DW_CFA_advance_loc4
.Lset4 = .Ltmp0-.Leh_func_begin0
	.long	.Lset4
	.byte	14                      # DW_CFA_def_cfa_offset
	.byte	16                      # Offset
	.byte	134                     # DW_CFA_offset + Reg (6)
	.byte	2                       # Offset
	.byte	4                       # DW_CFA_advance_loc4
.Lset5 = .Ltmp1-.Ltmp0
	.long	.Lset5
	.byte	13                      # DW_CFA_def_cfa_register
	.byte	6                       # Register
	.align	8
.Leh_frame_end0:


	.section	".note.GNU-stack","",@progbits
