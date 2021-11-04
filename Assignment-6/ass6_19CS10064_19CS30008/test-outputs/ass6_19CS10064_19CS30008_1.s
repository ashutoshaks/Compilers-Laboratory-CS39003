	.globl	global_var
	.data
	.align	4
	.type	global_var, @object
	.size	global_var, 4
global_var:
	.long	0
.section	.rodata
.LC0:
	.string "Enter 10 array elements in sorted order, separated by newlines:\n"
.LC1:
	.string "Entered array : "
.LC2:
	.string " "
.LC3:
	.string "\n"
.LC4:
	.string "Number to search: "
.LC5:
	.string "Invalid search, element not found"
.LC6:
	.string "Element found\n"
.LC7:
	.string "Position: "
.LC8:
	.string "\n"
# printStr: 
# printInt: 
# readInt: 
# t0 = 0
# global_var = t0
# binarySearch: 

	.text
	.globl	binarySearch
	.type	binarySearch, @function
binarySearch:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# t1 = 1
.L5:
	movl	$1, -4(%rbp)
# if l <= r goto .L0
	movl	24(%rbp), %eax
	cmpl	32(%rbp), %eax
	jg	.L20
	jmp	.L0
.L20:
# t1 = 0
	movl	$0, -4(%rbp)
# goto .L1
	jmp	.L1
# goto .L1
	jmp	.L1
# t2 = l + r
.L0:
	movl	24(%rbp), %eax
	movl	32(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
# t3 = 2
	movl	$2, -12(%rbp)
# t4 = t2 / t3
	movl	-8(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	movl	%eax, -16(%rbp)
# mid = t4
	movl	-16(%rbp), %eax
	movl	%eax, -20(%rbp)
# t5 = 0
	movl	$0, -24(%rbp)
# t6 = mid
	movl	-20(%rbp), %eax
	movl	%eax, -28(%rbp)
# t6 = t6 * 4
	movl	-28(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -28(%rbp)
# t5 = t6
	movl	-28(%rbp), %eax
	movl	%eax, -24(%rbp)
# t7 = a[t5]
	movl	-24(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -32(%rbp)
# t8 = 1
	movl	$1, -36(%rbp)
# if t7 == x goto .L2
	movl	-32(%rbp), %eax
	cmpl	40(%rbp), %eax
	jne	.L21
	jmp	.L2
.L21:
# t8 = 0
	movl	$0, -36(%rbp)
# goto .L3
	jmp	.L3
# goto .L4
	jmp	.L4
# return mid
.L2:
	movq	-20(%rbp), %rax
	leave
	ret
# goto .L5
	jmp	.L5
# t9 = 0
.L3:
	movl	$0, -40(%rbp)
# t10 = mid
	movl	-20(%rbp), %eax
	movl	%eax, -44(%rbp)
# t10 = t10 * 4
	movl	-44(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -44(%rbp)
# t9 = t10
	movl	-44(%rbp), %eax
	movl	%eax, -40(%rbp)
# t11 = a[t9]
	movl	-40(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -48(%rbp)
# t12 = 1
	movl	$1, -52(%rbp)
# if t11 < x goto .L6
	movl	-48(%rbp), %eax
	cmpl	40(%rbp), %eax
	jge	.L22
	jmp	.L6
.L22:
# t12 = 0
	movl	$0, -52(%rbp)
# goto .L7
	jmp	.L7
# goto .L8
	jmp	.L8
# t13 = 1
.L6:
	movl	$1, -56(%rbp)
# t14 = mid + t13
	movl	-20(%rbp), %eax
	movl	-56(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -60(%rbp)
# l = t14
	movl	-60(%rbp), %eax
	movl	%eax, 24(%rbp)
# goto .L5
	jmp	.L5
# t15 = 1
.L7:
	movl	$1, -64(%rbp)
# t16 = mid - t15
	movl	-20(%rbp), %edx
	movl	-64(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -68(%rbp)
# r = t16
	movl	-68(%rbp), %eax
	movl	%eax, 32(%rbp)
# goto .L5
	jmp	.L5
# goto .L5
.L8:
	jmp	.L5
# goto .L5
.L4:
	jmp	.L5
# t17 = 1
.L1:
	movl	$1, -72(%rbp)
# t18 = -t17
	movl	-72(%rbp), %eax
	negl	%eax
	movl	%eax, -76(%rbp)
# return t18
	movq	-76(%rbp), %rax
	leave
	ret
# function binarySearch ends
	leave
	ret
	.size	binarySearch, .-binarySearch
# main: 

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$288, %rsp
# t19 = global_var
	movl	global_var(%rip), %eax
	movl	%eax, -8(%rbp)
# global_var = global_var + 1
	movl	global_var(%rip), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, global_var(%rip)
# t20 = 10
	movl	$10, -12(%rbp)
# param .LC0
# t21 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -76(%rbp)
	addq	$4, %rsp
# t22 = 0
	movl	$0, -80(%rbp)
# i = t22
	movl	-80(%rbp), %eax
	movl	%eax, -56(%rbp)
# t23 = 10
.L11:
	movl	$10, -84(%rbp)
# t24 = 1
	movl	$1, -88(%rbp)
# if i < t23 goto .L9
	movl	-56(%rbp), %eax
	cmpl	-84(%rbp), %eax
	jge	.L23
	jmp	.L9
.L23:
# t24 = 0
	movl	$0, -88(%rbp)
# goto .L10
	jmp	.L10
# goto .L10
	jmp	.L10
# t25 = i
.L12:
	movl	-56(%rbp), %eax
	movl	%eax, -92(%rbp)
# i = i + 1
	movl	-56(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -56(%rbp)
# goto .L11
	jmp	.L11
# t26 = 0
.L9:
	movl	$0, -96(%rbp)
# t27 = i
	movl	-56(%rbp), %eax
	movl	%eax, -100(%rbp)
# t27 = t27 * 4
	movl	-100(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -100(%rbp)
# t26 = t27
	movl	-100(%rbp), %eax
	movl	%eax, -96(%rbp)
# t28 = &c
	leaq	-64(%rbp), %rax
	movq	%rax, -112(%rbp)
# param t28
# t29 = call readInt, 1
	movq	-112(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -116(%rbp)
	addq	$8, %rsp
# a[t26] = t29
	movl	-96(%rbp), %edx
	movl	-116(%rbp), %eax
cltq
	movl	%eax, -52(%rbp,%rdx,1)
# goto .L12
	jmp	.L12
# param .LC1
.L10:
# t30 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -124(%rbp)
	addq	$4, %rsp
# t31 = 0
	movl	$0, -128(%rbp)
# i = t31
	movl	-128(%rbp), %eax
	movl	%eax, -56(%rbp)
# t32 = 10
.L15:
	movl	$10, -132(%rbp)
# t33 = 1
	movl	$1, -136(%rbp)
# if i < t32 goto .L13
	movl	-56(%rbp), %eax
	cmpl	-132(%rbp), %eax
	jge	.L24
	jmp	.L13
.L24:
# t33 = 0
	movl	$0, -136(%rbp)
# goto .L14
	jmp	.L14
# goto .L14
	jmp	.L14
# t34 = i
.L16:
	movl	-56(%rbp), %eax
	movl	%eax, -140(%rbp)
# i = i + 1
	movl	-56(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -56(%rbp)
# goto .L15
	jmp	.L15
# t35 = 0
.L13:
	movl	$0, -148(%rbp)
# t36 = i
	movl	-56(%rbp), %eax
	movl	%eax, -152(%rbp)
# t36 = t36 * 4
	movl	-152(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -152(%rbp)
# t35 = t36
	movl	-152(%rbp), %eax
	movl	%eax, -148(%rbp)
# t37 = a[t35]
	movl	-148(%rbp), %edx
cltq
	movl	-52(%rbp,%rdx,1), %eax
	movl	%eax, -156(%rbp)
# param t37
# t38 = call printInt, 1
	movq	-156(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -160(%rbp)
	addq	$4, %rsp
# param .LC2
# t39 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -168(%rbp)
	addq	$4, %rsp
# goto .L16
	jmp	.L16
# param .LC3
.L14:
# t40 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -176(%rbp)
	addq	$4, %rsp
# param .LC4
# t41 = call printStr, 1
	movq	$.LC4, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -188(%rbp)
	addq	$4, %rsp
# t42 = &c
	leaq	-64(%rbp), %rax
	movq	%rax, -196(%rbp)
# param t42
# t43 = call readInt, 1
	movq	-196(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -200(%rbp)
	addq	$8, %rsp
# x = t43
	movl	-200(%rbp), %eax
	movl	%eax, -180(%rbp)
# t45 = 0
	movl	$0, -212(%rbp)
# t46 = 9
	movl	$9, -216(%rbp)
# param a
# param t45
# param t46
# param x
# t47 = call binarySearch, 4
	movq	-180(%rbp), %rax
	pushq	%rax
	movq	%rax, %rcx
	movq	-216(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdx
	movq	-212(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	leaq	-52(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	binarySearch
	movq	%rax, -220(%rbp)
	addq	$20, %rsp
# index = t47
	movl	-220(%rbp), %eax
	movl	%eax, -224(%rbp)
# t48 = 1
	movl	$1, -228(%rbp)
# t49 = -t48
	movl	-228(%rbp), %eax
	negl	%eax
	movl	%eax, -232(%rbp)
# t50 = 1
	movl	$1, -236(%rbp)
# if index == t49 goto .L17
	movl	-224(%rbp), %eax
	cmpl	-232(%rbp), %eax
	jne	.L25
	jmp	.L17
.L25:
# t50 = 0
	movl	$0, -236(%rbp)
# goto .L18
	jmp	.L18
# goto .L19
	jmp	.L19
# param .LC5
.L17:
# t51 = call printStr, 1
	movq	$.LC5, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -244(%rbp)
	addq	$4, %rsp
# goto .L19
	jmp	.L19
# param .LC6
.L18:
# t52 = call printStr, 1
	movq	$.LC6, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -252(%rbp)
	addq	$4, %rsp
# param .LC7
# t53 = call printStr, 1
	movq	$.LC7, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -260(%rbp)
	addq	$4, %rsp
# param index
# t54 = call printInt, 1
	movq	-224(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -264(%rbp)
	addq	$4, %rsp
# goto .L19
	jmp	.L19
# param .LC8
.L19:
# t55 = call printStr, 1
	movq	$.LC8, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -272(%rbp)
	addq	$4, %rsp
# t56 = 0
	movl	$0, -276(%rbp)
# return t56
	movq	-276(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
