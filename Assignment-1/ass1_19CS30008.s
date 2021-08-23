	.file	"ass1.c"									# name of the source file
	.text												# code starts from here
	.section	.rodata									# read-only data
	.align 8											# 8 byte boundary alignment
.LC0:													# label of format string for 1st printf
	.string	"Enter how many elements you want:"
.LC1:													# label of format string for scanf
	.string	"%d"
.LC2:													# label of format string for 2nd printf
	.string	"Enter the %d elements:\n"
.LC3:													# label of format string for 3rd printf
	.string	"\nEnter the item to search"
.LC4:													# label of format string for 4th printf
	.string	"\n%d found in position: %d\n"
	.align 8
.LC5:													# label of format string for 5th printf
	.string	"\nItem is not present in the list."
	.text
	.globl	main										# specifies that main is a global name
	.type	main, @function								# specifies the type of main, which is a function

main:										# start of main
.LFB0:
	.cfi_startproc							# initialize internal structures and emit initial CFI for entry in .eh_frame
	endbr64
	pushq	%rbp							# save base pointer (rbp) in stack
	.cfi_def_cfa_offset 16					# set CFA at an offset of 16 bytes from the current stack pointer
	.cfi_offset 6, -16						# set value of register 6 at offset 16 from CFA
	movq	%rsp, %rbp						# rbp <-- rsp, set new stack base pointer
	.cfi_def_cfa_register 6					# use register 6 for computing CFA

# int n, a[MAXSIZE], item, i, loc;
	subq	$432, %rsp						# rsp <-- rsp - 432, allocating memory on the stack for a[], n, item, i, loc
	
	movq	%fs:40, %rax					# get canary
	movq	%rax, -8(%rbp)					# M[rbp - 8] <-- rax, place on stack
	xorl	%eax, %eax						# erase canary

# printf("Enter how many elements you want:\n");
	leaq	.LC0(%rip), %rdi				# load address of .LCO(%rip) into rdi, rdi (starting of the format string) is the first argument of printf 
	call	puts@PLT						# call printf with rdi as argument
											# equivalent to printf("Enter how many elements you want:\n")
	
# scanf("%d", &n);
	leaq	-432(%rbp), %rax				# rax <-- rbp - 432, load address of M[rbp - 432] into rax, which is rbp - 432 itself (rax now stores &n)
	movq	%rax, %rsi						# rsi <-- rax, rsi (which is &n) is the 2nd argument of the scanf function
	leaq	.LC1(%rip), %rdi				# load address of .LC1(%rip) into rdi, rdi (starting of the format string) is the first argument of printf 
	movl	$0, %eax						# eax <-- 0
	call	__isoc99_scanf@PLT				# call scanf with rdi and rsi as arguments
											# equivalent to scanf("%d", &n)

# printf("Enter the %d elements:\n", n);
	movl	-432(%rbp), %eax				# eax <-- M[rbp - 432] (eax stores n)
	movl	%eax, %esi						# esi <-- eax, esi (which is now n) is the 2nd argument of printf
	leaq	.LC2(%rip), %rdi				# load address of .LC2(%rip) into rdi, rdi (starting of the format string) is the first argument of printf
	movl	$0, %eax						# eax <-- 0, printf is a variable argument function, %al is expected to hold the number of vector registers, since here printf has integer argument so eax = 0 (al is the first 8 bits of eax)
	call	printf@PLT						# call printf with rdi and esi as arguments
											# equivalent to printf("Enter the %d elements:\n", n)
	
# for(i = 0; i < n; i++) scanf("%d", &a[i]);
	movl	$0, -424(%rbp)					# M[rbp - 424] <-- 0, (M[rbp - 424] stores i, equivalent to i = 0)
	jmp	.L2									# unconditional jump to .L2
.L3:
	leaq	-416(%rbp), %rax				# rax <-- rbp - 416, load address of M[rbp - 416] in rax (rax now stores a)
	movl	-424(%rbp), %edx				# edx <-- M[rbp - 424] (edx stores i)
	movslq	%edx, %rdx						# rdx <-- edx (signed extension from 32-bit to 64-bit)
	salq	$2, %rdx						# rdx <-- 2-bit arithmetic left shift (rdx stores 4*i)
	addq	%rdx, %rax						# rax <-- rax + rdx (a + 4*i = &a[i])
	movq	%rax, %rsi						# rsi <-- rax (rsi stores &a[i]), rsi is the second argument of scanf
	leaq	.LC1(%rip), %rdi				# load address of .LC1(%rip) into rdi, rdi (starting of the format string) is the first argument of scanf
	movl	$0, %eax						# eax <-- 0
	call	__isoc99_scanf@PLT				# call scanf with rdi and rsi as arguments
	addl	$1, -424(%rbp)					# M[rbp - 424] <-- M[rbp - 424] + 1 (increment i, equivalent to i++)
.L2:
	movl	-432(%rbp), %eax				# eax <-- M[rbp - 432] (eax stores n)
	cmpl	%eax, -424(%rbp)				# compare M[rbp - 424] with eax, i.e., compare i with n for the condition i < n
	jl	.L3									# jump to .L3 if i < n

# inst_sort(a,n);
	movl	-432(%rbp), %edx				# edx <-- M[rbp - 432] (edx stores n)			
	leaq	-416(%rbp), %rax				# rax <-- rbp - 416, load address of M[rbp - 416] in rax (rax now stores a)
	movl	%edx, %esi						# esi <-- edx (esi now stores n), esi is the second argument of inst_sort
	movq	%rax, %rdi						# rdi <-- rax (rdi now stores a), rdi is the first argument of inst_sort
	call	inst_sort						# call the function inst_sort with rdi and esi as arguments
											# equivalent to inst_sort(a,n)

# printf("\nEnter the item to search\n");
	leaq	.LC3(%rip), %rdi				# load address of .LC3(%rip) into rdi, rdi (starting of the format string) is the first argument of printf
	call	puts@PLT						# call printf with rdi as argument

# scanf("%d", &item);
	leaq	-428(%rbp), %rax				# rax <-- rbp - 428, load address of M[rbp - 428] in rax (rax now stores &item)
	movq	%rax, %rsi						# rsi <-- rax (rsi now stores &item), rsi is the second argument of scanf
	leaq	.LC1(%rip), %rdi				# load address of .LC1(%rip) into rdi, rdi (starting of the format string) is the first argument of scanf
	movl	$0, %eax						# eax <-- 0
	call	__isoc99_scanf@PLT				# call scanf with rdi and rsi as arguments
											# equivalent to scanf("%d", &item)

# loc=bsearch(a,n,item);
	movl	-428(%rbp), %edx				# edx <-- M[rbp - 428] (edx stores item), edx is the third argument of the function bsearch
	movl	-432(%rbp), %ecx				# ecx <-- M[rbp - 432] (ecx stores n)
	leaq	-416(%rbp), %rax				# rax <-- rbp - 416, load address of M[rbp - 416] in rax (rax now stores a)
	movl	%ecx, %esi						# esi <-- ecx (esi now stores n), esi is the second argument of the function bsearch
	movq	%rax, %rdi						# rdi <-- rax (rdi now stores a), rdi is the first argument of the function bsearch
	call	bsearch							# call bsearch with rdi, esi and edx as arguments, and the return value is stored in eax
	movl	%eax, -420(%rbp)				# M[rbp - 420] <-- eax, assigning the return value from bsearch(a,n,item) to loc

# if (item == a[loc])
	movl	-420(%rbp), %eax				# eax <-- M[rbp - 420] (eax stores loc)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	movl	-416(%rbp,%rax,4), %edx			# edx <-- M[rbp + 4*rax - 416] (edx stores a[loc])
	movl	-428(%rbp), %eax				# eax <-- M[rbp - 428] (eax stores item)
	cmpl	%eax, %edx						# compare eax and edx (equivalent to checking if item == a[loc])
	jne	.L4									# jump to .L4 if eax and edx (i.e., item and a[loc]) are not equal

# printf("\n%d found in position: %d\n", item, loc + 1);
	movl	-420(%rbp), %eax				# eax <-- M[rbp - 420] (eax stores loc)
	leal	1(%rax), %edx					# edx <-- rax + 1 (rax is 64-bit version of eax, thus rax is loc, hence, edx stores loc + 1), edx is the third argument of printf
	movl	-428(%rbp), %eax				# eax <-- M[rbp - 428] (eax stores item)
	movl	%eax, %esi						# esi <-- eax, esi is the second argument of printf
	leaq	.LC4(%rip), %rdi				# load address of .LC4(%rip) into rdi, rdi (starting of the format string) is the first argument of printf
	movl	$0, %eax						# eax <-- 0
	call	printf@PLT						# call printf with rdi, esi and edx as arguments
	jmp	.L5									# unconditional jump to .L5

.L4:
# printf("\nItem is not present in the list.\n");
	leaq	.LC5(%rip), %rdi				# load address of .LC5(%rip) into rdi, rdi (starting of the format string) is the first argument of printf
	call	puts@PLT						# call printf with rdi as argument

.L5:
# return 0;
	movl	$0, %eax						# eax <-- 0, eax has the value to be returned from main
	movq	-8(%rbp), %rcx					# rcx <-- M[rbp - 8]
	xorq	%fs:40, %rcx					# take xor, and check if we get 0 or not, if we get 0 then that means there is no stack overflow, and everything is fine
	je	.L7									# jump to .L7 if we get 0 in the previous step
	call	__stack_chk_fail@PLT			# if we reach here that indicates a stack overflow, hence the execution is terminated
.L7:
	leave									# set rsp to rbp, and pop top of stack into rbp
	.cfi_def_cfa 7, 8						# for computing CFA, take address from register 7 and add an offset of 8 to it 
	ret										# pop return address from stack and transfer control back to the return address
	.cfi_endproc							# close the unwind entry previously opened by .cfi_startproc. and emit it to .eh_frame
.LFE0:
	.size	main, .-main								# size of main
	.globl	inst_sort									# specifies that inst_sort is a global name
	.type	inst_sort, @function						# specifies the type of inst_sort, which is a function

inst_sort:									# start of inst_sort
.LFB1:
	.cfi_startproc							# initialize internal structures and emit initial CFI for entry in .eh_frame
	endbr64
	pushq	%rbp							# save base pointer (rbp) in stack
	.cfi_def_cfa_offset 16					# set CFA at an offset of 16 bytes from the current stack pointer
	.cfi_offset 6, -16						# set value of register 6 at offset 16 from CFA
	movq	%rsp, %rbp						# rbp <-- rsp, set new stack base pointer
	.cfi_def_cfa_register 6					# use register 6 for computing CFA
	movq	%rdi, -24(%rbp)					# M[rbp - 24] <-- rdi, store the first argument num (the array with which inst_sort was called)
	movl	%esi, -28(%rbp)					# M[rbp - 28] <-- esi, store the second argument n (the size of the array with which inst_sort was called)
	
# for(j=1;j<n;j++)
	movl	$1, -8(%rbp)					# M[rbp - 8] <-- 1 (M[rbp - 8] stores j), equivalent to j = 1
	jmp	.L9									# unconditional jump to .L9

.L13:
# k=num[j];
	movl	-8(%rbp), %eax					# eax <-- M[rbp - 8] (eax stores j)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*j)
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores num)
	addq	%rdx, %rax						# rax <-- rax + rdx (rax now stores num + 4*j) 
	movl	(%rax), %eax					# eax <-- M[rax] (eax now stores num[j])
	movl	%eax, -4(%rbp)					# M[rbp - 4] <-- eax (M[rbp - 4] is actually k, so this is equivalent to k = num[j])
	
# for(i=j-1;i>=0 && k<num[i];i--) num[i+1]=num[i];
	movl	-8(%rbp), %eax					# eax <-- M[rbp - 8] (eax stores j)
	subl	$1, %eax						# eax <-- eax - 1 (eax now becomes j - 1)
	movl	%eax, -12(%rbp)					# M[rbp - 12] <-- eax (M[rbp - 12] stores i, so this is equivalent to i = j - 1)
	jmp	.L10								# unconditional jump to .L10
.L12:
	movl	-12(%rbp), %eax					# eax <-- M[rbp - 12] (eax stores i)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*i)
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores num)
	addq	%rdx, %rax						# rax <-- rax + rdx (rax now stores num + 4*i)
	movl	-12(%rbp), %edx					# edx <-- M[rbp - 12] (edx stores i)
	movslq	%edx, %rdx						# rdx <-- edx (signed extension from 32-bit to 64-bit)
	addq	$1, %rdx						# rdx <-- rdx + 1 (rdx stores i + 1)
	leaq	0(,%rdx,4), %rcx				# rcx <-- rdx*4 (rcx stores 4*(i + 1))
	movq	-24(%rbp), %rdx					# rdx <-- M[rbp - 24] (rdx stores num)
	addq	%rcx, %rdx						# rdx <-- rdx + rcx (rdx now stores num + 4*(i + 1))
	movl	(%rax), %eax					# eax <-- M[rax] (eax now stores num[i + 1])
	movl	%eax, (%rdx)					# M[rdx] <-- eax (equivalent to num[i + 1] = num[i])
	subl	$1, -12(%rbp)					# M[rbp - 12] <-- M[rbp - 12] - 1 (i is decreased by 1, equivalent to i--)
.L10:
	cmpl	$0, -12(%rbp)					# compare M[rbp - 12] with 0 (i.e., compare i with 0)
	js	.L11								# jump to .L11 if M[rbp - 12] < 0 (i.e., if i < 0)

	movl	-12(%rbp), %eax					# eax <-- M[rbp - 12] (eax stores i)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*i)
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores num)
	addq	%rdx, %rax						# rax <-- rax + rdx (rax now stores num + 4*i)
	movl	(%rax), %eax					# eax <-- M[rax] (eax now stores num[i])
	cmpl	%eax, -4(%rbp)					# compare M[rbp - 4] with eax (i.e., k with num[i])
	jl	.L12								# jump to .L12 if M[rbp - 4] < eax (i.e., if k < num[i])

.L11:
# num[i+1]=k;
	movl	-12(%rbp), %eax					# eax <-- M[rbp - 12] (eax stores i)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	addq	$1, %rax						# rax <-- rax + 1 (rax now stores i + 1)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*(i + 1))
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores num)
	addq	%rax, %rdx						# rdx <-- rdx + rax (rdx now stores num + 4*(i + 1))
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores k)
	movl	%eax, (%rdx)					# M[rdx] <-- eax (equivalent to num[i + 1] = k)
	addl	$1, -8(%rbp)					# M[rbp - 8] <-- M[rbp - 8] + 1 (increment j by 1, equivalent to j++)
	
.L9:
	movl	-8(%rbp), %eax					# eax <-- M[rbp - 8] (eax stores j)
	cmpl	-28(%rbp), %eax					# compare eax with M[rbp - 28] (comparing j with n)
	jl	.L13								# jump to .L13 if eax < M[rbp - 28] (i.e., j < n)
	nop										# does nothing
	nop										# does nothing
	popq	%rbp							# pop top of stack into rbp
	.cfi_def_cfa 7, 8						# for computing CFA, take address from register 7 and add an offset of 8 to it
	ret										# transfer control back to the return address
	.cfi_endproc							# close the unwind entry previously opened by .cfi_startproc. and emit it to .eh_frame
.LFE1:
	.size	inst_sort, .-inst_sort						# size of inst_sort
	.globl	bsearch										# specifies that bsearch is a global name
	.type	bsearch, @function							# specifies the type of bsearch, which is a function

bsearch:									# start of bsearch
.LFB2:
	.cfi_startproc							# initialize internal structures and emit initial CFI for entry in .eh_frame
	endbr64
	pushq	%rbp							# save base pointer (rbp) in stack
	.cfi_def_cfa_offset 16					# set CFA at an offset of 16 bytes from the current stack pointer
	.cfi_offset 6, -16						# set value of register 6 at offset 16 from CFA
	movq	%rsp, %rbp						# rbp <-- rsp, set new stack base pointer
	.cfi_def_cfa_register 6					# use register 6 for computing CFA
	movq	%rdi, -24(%rbp)					# M[rbp - 24] <-- rdi, store the first argument a (the array with which bsearch was called)
	movl	%esi, -28(%rbp)					# M[rbp - 28] <-- esi, store the second argument n (the size of the array with which bsearch was called)
	movl	%edx, -32(%rbp)					# M[rbp - 32] <-- edx, store the third argument item (the number for which bsearch was called)
	
# bottom = 1;
	movl	$1, -8(%rbp)					# M[rbp - 8] <-- 1 (M[rbp - 8] stores bottom, equivalent to bottom = 1)
	
# top = n;
	movl	-28(%rbp), %eax					# eax <-- M[rbp - 28] (eax stores n)
	movl	%eax, -12(%rbp)					# M[rbp - 12] <-- eax (M[rbp - 12] stores top, equivalent to top = n)

.L18:
# mid = (bottom + top) / 2;
	movl	-8(%rbp), %edx					# edx <-- M[rbp - 8] (edx stores bottom)
	movl	-12(%rbp), %eax					# eax <-- M[rbp - 12] (eax stores top)
	addl	%edx, %eax						# eax <-- eax + edx (eax now stores top + bottom)
	movl	%eax, %edx						# edx <-- eax (edx stores top + bottom)
	shrl	$31, %edx						# right shift edx by 31 bits, since edx is a 32-bit register, here we get the sign bit (0 if positive, 1 if negative)
	addl	%edx, %eax						# eax <-- eax + edx (adds 1 to eax if edx was negative, else adds 0)
	sarl	%eax							# right shift eax by 1 bit, resulting in division by 2 (eax now stores (top + bottom) / 2)
	movl	%eax, -4(%rbp)					# M[rbp - 4] <-- eax (M[rbp - 4] stores mid, so this is equivalent to mid = (bottom + top) / 2)

# if (item < a[mid])
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores mid)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*mid)
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores a)
	addq	%rdx, %rax						# rax <-- rax + rdx (rax now stores a + 4*mid)
	movl	(%rax), %eax					# eax <-- M[rax] (eax now stores a[mid])
	cmpl	%eax, -32(%rbp)					# compare M[rbp - 32] with eax (i.e., item with a[mid])
	jge	.L15								# jump to .L15 if M[rbp - 32] is greater than or equal to eax (i.e., if item >= a[mid])
	
# top = mid - 1;
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores mid)
	subl	$1, %eax						# eax <-- eax - 1 (eax now stores mid - 1)
	movl	%eax, -12(%rbp)					# M[rbp - 12] <-- eax (M[rbp - 12] stores top, so this is equivalent to top = mid - 1)
	jmp	.L16								# unconditional jump to .L16

.L15:
# else if (item > a[mid])
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores mid)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*mid)
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores a)
	addq	%rdx, %rax						# rax <-- rax + rdx (rax now stores a + 4*mid)
	movl	(%rax), %eax					# eax <-- M[rax] (eax now stores a[mid])
	cmpl	%eax, -32(%rbp)					# compare M[rbp - 32] with eax (i.e., item with a[mid])
	jle	.L16								# jump to .L16 if M[rbp - 32] is less than or equal to eax (i.e., if item <= a[mid])
	
# bottom = mid + 1;
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores mid)
	addl	$1, %eax						# eax <-- eax + 1 (eax now stores mid + 1)
	movl	%eax, -8(%rbp)					# M[rbp - 8] <-- eax (M[rbp - 8] stores bottom, so this is equivalent to bottom = mid + 1)

.L16:
# while (item != a[mid] && bottom <= top);
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores mid)
	cltq									# rax <-- eax (signed extension from 32-bit to 64-bit)
	leaq	0(,%rax,4), %rdx				# rdx <-- rax*4 (rdx stores 4*mid)
	movq	-24(%rbp), %rax					# rax <-- M[rbp - 24] (rax stores a)
	addq	%rdx, %rax						# rax <-- rax + rdx (rax now stores a + 4*mid)
	movl	(%rax), %eax					# eax <-- M[rax] (eax now stores a[mid])
	cmpl	%eax, -32(%rbp)					# compare M[rbp - 32] with eax (i.e., item with a[mid])
	je	.L17								# jump to .L17 if M[rbp - 32] is equal to eax (i.e., if item == a[mid])
	movl	-8(%rbp), %eax					# eax <-- M[rbp - 8] (eax stores bottom)
	cmpl	-12(%rbp), %eax					# compare eax with M[rbp - 12] (i.e., bottom with top)
	jle	.L18								# jump to .L18 if eax is less than or equal to M[rbp - 12] (i.e., if bottom <= top)

.L17:
# return mid;
	movl	-4(%rbp), %eax					# eax <-- M[rbp - 4] (eax stores mid), eax has the value to be returned from bsearch			
	popq	%rbp							# pop top of stack into rbp
	.cfi_def_cfa 7, 8						# for computing CFA, take address from register 7 and add an offset of 8 to it 
	ret										# transfer control back to the return address
	.cfi_endproc							# close the unwind entry previously opened by .cfi_startproc. and emit it to .eh_frame
.LFE2:
	.size	bsearch, .-bsearch							# size of bsearch
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
