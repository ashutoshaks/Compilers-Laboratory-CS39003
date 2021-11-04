	.globl	global_var
	.data
	.align	4
	.type	global_var, @object
	.size	global_var, 4
global_var:
	.long	0
	.globl	counter
	.data
	.align	4
	.type	counter, @object
	.size	counter, 4
counter:
	.long	0
.section	.rodata
.LC0:
	.string "Enter n (n < 20): "
.LC1:
	.string "fib["
.LC2:
	.string "] = "
.LC3:
	.string "\n"
# printStr: 
.L11:
# printInt: 
# readInt: 
# t0 = 0
# global_var = t0
# t1 = 0
# counter = t1
# fibn: 
# main: 

	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$576, %rsp
# t2 = counter
	movl	counter(%rip), %eax
	movl	%eax, -8(%rbp)
# counter = counter + 1
	movl	counter(%rip), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, counter(%rip)
# global_var = counter
	movl	counter(%rip), %eax
	movl	%eax, global_var(%rip)
# param .LC0
# t3 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -32(%rbp)
	addq	$4, %rsp
# t4 = &flag
	leaq	-20(%rbp), %rax
	movq	%rax, -44(%rbp)
# param t4
# t5 = call readInt, 1
	movq	-44(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	readInt
	movq	%rax, -48(%rbp)
	addq	$8, %rsp
# n = t5
	movl	-48(%rbp), %eax
	movl	%eax, -16(%rbp)
# t6 = 100
	movl	$100, -56(%rbp)
# t7 = 0
	movl	$0, -460(%rbp)
# i = t7
	movl	-460(%rbp), %eax
	movl	%eax, -52(%rbp)
# t8 = 1
.L2:
	movl	$1, -464(%rbp)
# if i < n goto .L0
	movl	-52(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	.L16
	jmp	.L0
.L16:
# t8 = 0
	movl	$0, -464(%rbp)
# goto .L1
	jmp	.L1
# goto .L1
	jmp	.L1
# t9 = i
.L3:
	movl	-52(%rbp), %eax
	movl	%eax, -468(%rbp)
# i = i + 1
	movl	-52(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -52(%rbp)
# goto .L2
	jmp	.L2
# t10 = 0
.L0:
	movl	$0, -472(%rbp)
# t11 = i
	movl	-52(%rbp), %eax
	movl	%eax, -476(%rbp)
# t11 = t11 * 4
	movl	-476(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -476(%rbp)
# t10 = t11
	movl	-476(%rbp), %eax
	movl	%eax, -472(%rbp)
# t12 = 1
	movl	$1, -484(%rbp)
# t13 = i + t12
	movl	-52(%rbp), %eax
	movl	-484(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -488(%rbp)
# param t13
# t14 = call fibn, 1
	movq	-488(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	fibn
	movq	%rax, -492(%rbp)
	addq	$4, %rsp
# fib[t10] = t14
	movl	-472(%rbp), %edx
	movl	-492(%rbp), %eax
cltq
	movl	%eax, -456(%rbp,%rdx,1)
# t15 = counter
	movl	counter(%rip), %eax
	movl	%eax, -496(%rbp)
# counter = counter + 1
	movl	counter(%rip), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, counter(%rip)
# global_var = counter
	movl	counter(%rip), %eax
	movl	%eax, global_var(%rip)
# goto .L3
	jmp	.L3
# t16 = 0
.L1:
	movl	$0, -500(%rbp)
# i = t16
	movl	-500(%rbp), %eax
	movl	%eax, -52(%rbp)
# t17 = 1
.L6:
	movl	$1, -504(%rbp)
# if i < n goto .L4
	movl	-52(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jge	.L17
	jmp	.L4
.L17:
# t17 = 0
	movl	$0, -504(%rbp)
# goto .L5
	jmp	.L5
# goto .L5
	jmp	.L5
# t18 = i
.L7:
	movl	-52(%rbp), %eax
	movl	%eax, -508(%rbp)
# i = i + 1
	movl	-52(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -52(%rbp)
# goto .L6
	jmp	.L6
# param .LC1
.L4:
# t19 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -516(%rbp)
	addq	$4, %rsp
# t20 = 1
	movl	$1, -524(%rbp)
# t21 = i + t20
	movl	-52(%rbp), %eax
	movl	-524(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -528(%rbp)
# param t21
# t22 = call printInt, 1
	movq	-528(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -532(%rbp)
	addq	$4, %rsp
# param .LC2
# t23 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -540(%rbp)
	addq	$4, %rsp
# t24 = 0
	movl	$0, -544(%rbp)
# t25 = i
	movl	-52(%rbp), %eax
	movl	%eax, -548(%rbp)
# t25 = t25 * 4
	movl	-548(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -548(%rbp)
# t24 = t25
	movl	-548(%rbp), %eax
	movl	%eax, -544(%rbp)
# t26 = fib[t24]
	movl	-544(%rbp), %edx
cltq
	movl	-456(%rbp,%rdx,1), %eax
	movl	%eax, -552(%rbp)
# param t26
# t27 = call printInt, 1
	movq	-552(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -556(%rbp)
	addq	$4, %rsp
# param .LC3
# t28 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -564(%rbp)
	addq	$4, %rsp
# goto .L7
	jmp	.L7
# t29 = 0
.L5:
	movl	$0, -568(%rbp)
# return t29
	movq	-568(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
# fibn: 

	.text
	.globl	fibn
	.type	fibn, @function
fibn:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# t30 = counter
	movl	counter(%rip), %eax
	movl	%eax, -8(%rbp)
# counter = counter + 1
	movl	counter(%rip), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, counter(%rip)
# global_var = counter
	movl	counter(%rip), %eax
	movl	%eax, global_var(%rip)
# t31 = 0
	movl	$0, -16(%rbp)
# t32 = 1
	movl	$1, -20(%rbp)
# if n == t31 goto .L8
	movl	16(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L18
	jmp	.L8
.L18:
# t32 = 0
	movl	$0, -20(%rbp)
# goto .L9
	jmp	.L9
# goto .L10
	jmp	.L10
# t33 = 0
.L8:
	movl	$0, -24(%rbp)
# return t33
	movq	-24(%rbp), %rax
	leave
	ret
# goto .L11
	jmp	.L11
# t34 = 1
.L9:
	movl	$1, -28(%rbp)
# t35 = 1
	movl	$1, -32(%rbp)
# if n == t34 goto .L12
	movl	16(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jne	.L19
	jmp	.L12
.L19:
# t35 = 0
	movl	$0, -32(%rbp)
# goto .L13
	jmp	.L13
# t36 = 2
.L13:
	movl	$2, -36(%rbp)
# t37 = 1
	movl	$1, -40(%rbp)
# if n == t36 goto .L12
	movl	16(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jne	.L20
	jmp	.L12
.L20:
# t37 = 0
	movl	$0, -40(%rbp)
# goto .L14
	jmp	.L14
# goto .L15
	jmp	.L15
# t38 = 1
.L12:
	movl	$1, -44(%rbp)
# return t38
	movq	-44(%rbp), %rax
	leave
	ret
# goto .L11
	jmp	.L11
# t39 = 1
.L14:
	movl	$1, -52(%rbp)
# t40 = n - t39
	movl	16(%rbp), %edx
	movl	-52(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -56(%rbp)
# param t40
# t41 = call fibn, 1
	movq	-56(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	fibn
	movq	%rax, -60(%rbp)
	addq	$4, %rsp
# t42 = 2
	movl	$2, -64(%rbp)
# t43 = n - t42
	movl	16(%rbp), %edx
	movl	-64(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -68(%rbp)
# param t43
# t44 = call fibn, 1
	movq	-68(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	fibn
	movq	%rax, -72(%rbp)
	addq	$4, %rsp
# t45 = t41 + t44
	movl	-60(%rbp), %eax
	movl	-72(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -76(%rbp)
# return t45
	movq	-76(%rbp), %rax
	leave
	ret
# goto .L11
	jmp	.L11
# goto .L11
.L15:
	jmp	.L11
# function fibn ends
.L10:
	leave
	ret
	.size	fibn, .-fibn
