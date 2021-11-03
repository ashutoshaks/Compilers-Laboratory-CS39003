.section	.rodata
.LC0:
	.string " "
.LC1:
	.string "\n"
.LC2:
	.string "Merge Sort \n"
.LC3:
	.string "Given array :: \n"
.LC4:
	.string "Sorted array :: \n"
# printStr: 
# printInt: 
# readInt: 
# merge: 
	.text
	.globl	merge
	.type	merge, @function
merge:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$352, %rsp
# t0 = m - l
	movl	32(%rbp), %edx
	movl	24(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%rbp)
# t1 = 1
	movl	$1, -20(%rbp)
# t2 = t0 + t1
	movl	-16(%rbp), %eax
	movl	-20(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
# n1 = t2
	movl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
# t3 = r - m
	movl	40(%rbp), %edx
	movl	32(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -32(%rbp)
# n2 = t3
	movl	-32(%rbp), %eax
	movl	%eax, -36(%rbp)
# t4 = 6
	movl	$6, -40(%rbp)
# t5 = 6
	movl	$6, -44(%rbp)
# t6 = 0
	movl	$0, -96(%rbp)
# i = t6
	movl	-96(%rbp), %eax
	movl	%eax, -4(%rbp)
# t7 = 1
.L2:
	movl	$1, -100(%rbp)
# if i < n1 goto .L0
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L25
	jmp	.L0
.L25:
# t7 = 0
	movl	$0, -100(%rbp)
# goto .L1
	jmp	.L1
# goto .L1
	jmp	.L1
# t8 = i
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, -104(%rbp)
# i = i + 1
	movl	-4(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
# goto .L2
	jmp	.L2
# t9 = 0
.L0:
	movl	$0, -108(%rbp)
# t10 = i
	movl	-4(%rbp), %eax
	movl	%eax, -112(%rbp)
# t10 = t10 * 4
	movl	-112(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -112(%rbp)
# t9 = t10
	movl	-112(%rbp), %eax
	movl	%eax, -108(%rbp)
# t11 = l + i
	movl	24(%rbp), %eax
	movl	-4(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -116(%rbp)
# t12 = 0
	movl	$0, -120(%rbp)
# t13 = t11
	movl	-116(%rbp), %eax
	movl	%eax, -124(%rbp)
# t13 = t13 * 4
	movl	-124(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -124(%rbp)
# t12 = t13
	movl	-124(%rbp), %eax
	movl	%eax, -120(%rbp)
# t14 = arr[t12]
	movl	-120(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -128(%rbp)
# L[t9] = t14
	movl	-108(%rbp), %edx
	movl	-128(%rbp), %eax
cltq
	movl	%eax, -68(%rbp,%rdx,1)
# goto .L3
	jmp	.L3
# t15 = 0
.L1:
	movl	$0, -132(%rbp)
# j = t15
	movl	-132(%rbp), %eax
	movl	%eax, -8(%rbp)
# t16 = 1
.L6:
	movl	$1, -136(%rbp)
# if j < n2 goto .L4
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jge	.L26
	jmp	.L4
.L26:
# t16 = 0
	movl	$0, -136(%rbp)
# goto .L5
	jmp	.L5
# goto .L5
	jmp	.L5
# t17 = j
.L7:
	movl	-8(%rbp), %eax
	movl	%eax, -140(%rbp)
# j = j + 1
	movl	-8(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
# goto .L6
	jmp	.L6
# t18 = 1
.L4:
	movl	$1, -144(%rbp)
# t19 = m + t18
	movl	32(%rbp), %eax
	movl	-144(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -148(%rbp)
# t20 = t19 + j
	movl	-148(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -152(%rbp)
# zz = t20
	movl	-152(%rbp), %eax
	movl	%eax, -156(%rbp)
# t21 = 0
	movl	$0, -160(%rbp)
# t22 = j
	movl	-8(%rbp), %eax
	movl	%eax, -164(%rbp)
# t22 = t22 * 4
	movl	-164(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -164(%rbp)
# t21 = t22
	movl	-164(%rbp), %eax
	movl	%eax, -160(%rbp)
# t23 = 0
	movl	$0, -168(%rbp)
# t24 = zz
	movl	-156(%rbp), %eax
	movl	%eax, -172(%rbp)
# t24 = t24 * 4
	movl	-172(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -172(%rbp)
# t23 = t24
	movl	-172(%rbp), %eax
	movl	%eax, -168(%rbp)
# t25 = arr[t23]
	movl	-168(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -176(%rbp)
# R[t21] = t25
	movl	-160(%rbp), %edx
	movl	-176(%rbp), %eax
cltq
	movl	%eax, -92(%rbp,%rdx,1)
# goto .L7
	jmp	.L7
# t26 = 0
.L5:
	movl	$0, -180(%rbp)
# i = t26
	movl	-180(%rbp), %eax
	movl	%eax, -4(%rbp)
# t27 = 0
	movl	$0, -184(%rbp)
# j = t27
	movl	-184(%rbp), %eax
	movl	%eax, -8(%rbp)
# k = l
	movl	24(%rbp), %eax
	movl	%eax, -12(%rbp)
# t28 = 1
.L14:
	movl	$1, -188(%rbp)
# if i < n1 goto .L8
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L27
	jmp	.L8
.L27:
# t28 = 0
	movl	$0, -188(%rbp)
# goto .L9
	jmp	.L9
# t29 = 1
.L8:
	movl	$1, -192(%rbp)
# if j < n2 goto .L10
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jge	.L28
	jmp	.L10
.L28:
# t29 = 0
	movl	$0, -192(%rbp)
# goto .L9
	jmp	.L9
# goto .L9
	jmp	.L9
# t30 = 0
.L10:
	movl	$0, -196(%rbp)
# t31 = i
	movl	-4(%rbp), %eax
	movl	%eax, -200(%rbp)
# t31 = t31 * 4
	movl	-200(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -200(%rbp)
# t30 = t31
	movl	-200(%rbp), %eax
	movl	%eax, -196(%rbp)
# t32 = L[t30]
	movl	-196(%rbp), %edx
cltq
	movl	-68(%rbp,%rdx,1), %eax
	movl	%eax, -204(%rbp)
# t33 = 0
	movl	$0, -208(%rbp)
# t34 = j
	movl	-8(%rbp), %eax
	movl	%eax, -212(%rbp)
# t34 = t34 * 4
	movl	-212(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -212(%rbp)
# t33 = t34
	movl	-212(%rbp), %eax
	movl	%eax, -208(%rbp)
# t35 = R[t33]
	movl	-208(%rbp), %edx
cltq
	movl	-92(%rbp,%rdx,1), %eax
	movl	%eax, -216(%rbp)
# t36 = 1
	movl	$1, -220(%rbp)
# if t32 <= t35 goto .L11
	movl	-204(%rbp), %eax
	cmpl	-216(%rbp), %eax
	jg	.L29
	jmp	.L11
.L29:
# t36 = 0
	movl	$0, -220(%rbp)
# goto .L12
	jmp	.L12
# goto .L13
	jmp	.L13
# t37 = 0
.L11:
	movl	$0, -224(%rbp)
# t38 = k
	movl	-12(%rbp), %eax
	movl	%eax, -228(%rbp)
# t38 = t38 * 4
	movl	-228(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -228(%rbp)
# t37 = t38
	movl	-228(%rbp), %eax
	movl	%eax, -224(%rbp)
# t39 = 0
	movl	$0, -232(%rbp)
# t40 = i
	movl	-4(%rbp), %eax
	movl	%eax, -236(%rbp)
# t40 = t40 * 4
	movl	-236(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -236(%rbp)
# t39 = t40
	movl	-236(%rbp), %eax
	movl	%eax, -232(%rbp)
# t41 = L[t39]
	movl	-232(%rbp), %edx
cltq
	movl	-68(%rbp,%rdx,1), %eax
	movl	%eax, -240(%rbp)
# arr[t37] = t41
	movl	-224(%rbp), %edx
	movl	-240(%rbp), %eax
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movl	%eax, (%rdx)
# t42 = i
	movl	-4(%rbp), %eax
	movl	%eax, -244(%rbp)
# i = i + 1
	movl	-4(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
# goto .L13
	jmp	.L13
# t43 = 0
.L12:
	movl	$0, -248(%rbp)
# t44 = k
	movl	-12(%rbp), %eax
	movl	%eax, -252(%rbp)
# t44 = t44 * 4
	movl	-252(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -252(%rbp)
# t43 = t44
	movl	-252(%rbp), %eax
	movl	%eax, -248(%rbp)
# t45 = 0
	movl	$0, -256(%rbp)
# t46 = j
	movl	-8(%rbp), %eax
	movl	%eax, -260(%rbp)
# t46 = t46 * 4
	movl	-260(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -260(%rbp)
# t45 = t46
	movl	-260(%rbp), %eax
	movl	%eax, -256(%rbp)
# t47 = R[t45]
	movl	-256(%rbp), %edx
cltq
	movl	-92(%rbp,%rdx,1), %eax
	movl	%eax, -264(%rbp)
# arr[t43] = t47
	movl	-248(%rbp), %edx
	movl	-264(%rbp), %eax
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movl	%eax, (%rdx)
# t48 = j
	movl	-8(%rbp), %eax
	movl	%eax, -268(%rbp)
# j = j + 1
	movl	-8(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
# goto .L13
	jmp	.L13
# t49 = k
.L13:
	movl	-12(%rbp), %eax
	movl	%eax, -272(%rbp)
# k = k + 1
	movl	-12(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
# goto .L14
	jmp	.L14
# t50 = 1
.L9:
	movl	$1, -276(%rbp)
# if i < n1 goto .L15
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L30
	jmp	.L15
.L30:
# t50 = 0
	movl	$0, -276(%rbp)
# goto .L16
	jmp	.L16
# goto .L16
	jmp	.L16
# t51 = 0
.L15:
	movl	$0, -280(%rbp)
# t52 = k
	movl	-12(%rbp), %eax
	movl	%eax, -284(%rbp)
# t52 = t52 * 4
	movl	-284(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -284(%rbp)
# t51 = t52
	movl	-284(%rbp), %eax
	movl	%eax, -280(%rbp)
# t53 = 0
	movl	$0, -288(%rbp)
# t54 = i
	movl	-4(%rbp), %eax
	movl	%eax, -292(%rbp)
# t54 = t54 * 4
	movl	-292(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -292(%rbp)
# t53 = t54
	movl	-292(%rbp), %eax
	movl	%eax, -288(%rbp)
# t55 = L[t53]
	movl	-288(%rbp), %edx
cltq
	movl	-68(%rbp,%rdx,1), %eax
	movl	%eax, -296(%rbp)
# arr[t51] = t55
	movl	-280(%rbp), %edx
	movl	-296(%rbp), %eax
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movl	%eax, (%rdx)
# t56 = i
	movl	-4(%rbp), %eax
	movl	%eax, -300(%rbp)
# i = i + 1
	movl	-4(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
# t57 = k
	movl	-12(%rbp), %eax
	movl	%eax, -304(%rbp)
# k = k + 1
	movl	-12(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
# goto .L9
	jmp	.L9
# t58 = 1
.L16:
	movl	$1, -308(%rbp)
# if j < n2 goto .L17
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jge	.L31
	jmp	.L17
.L31:
# t58 = 0
	movl	$0, -308(%rbp)
# goto .L18
	jmp	.L18
# goto .L18
	jmp	.L18
# t59 = 0
.L17:
	movl	$0, -312(%rbp)
# t60 = k
	movl	-12(%rbp), %eax
	movl	%eax, -316(%rbp)
# t60 = t60 * 4
	movl	-316(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -316(%rbp)
# t59 = t60
	movl	-316(%rbp), %eax
	movl	%eax, -312(%rbp)
# t61 = 0
	movl	$0, -320(%rbp)
# t62 = j
	movl	-8(%rbp), %eax
	movl	%eax, -324(%rbp)
# t62 = t62 * 4
	movl	-324(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -324(%rbp)
# t61 = t62
	movl	-324(%rbp), %eax
	movl	%eax, -320(%rbp)
# t63 = R[t61]
	movl	-320(%rbp), %edx
cltq
	movl	-92(%rbp,%rdx,1), %eax
	movl	%eax, -328(%rbp)
# arr[t59] = t63
	movl	-312(%rbp), %edx
	movl	-328(%rbp), %eax
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movl	%eax, (%rdx)
# t64 = j
	movl	-8(%rbp), %eax
	movl	%eax, -332(%rbp)
# j = j + 1
	movl	-8(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
# t65 = k
	movl	-12(%rbp), %eax
	movl	%eax, -336(%rbp)
# k = k + 1
	movl	-12(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
# goto .L16
	jmp	.L16
# t66 = 0
.L18:
	movl	$0, -340(%rbp)
# return t66
	movq	-340(%rbp), %rax
	leave
	ret
# function merge ends
	leave
	ret
	.size	merge, .-merge
# mergeSort: 
	.text
	.globl	mergeSort
	.type	mergeSort, @function
mergeSort:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# t67 = 1
	movl	$1, -4(%rbp)
# if l < r goto .L19
	movl	24(%rbp), %eax
	cmpl	32(%rbp), %eax
	jge	.L32
	jmp	.L19
.L32:
# t67 = 0
	movl	$0, -4(%rbp)
# goto .L20
	jmp	.L20
# goto .L20
	jmp	.L20
# t68 = r - l
.L19:
	movl	32(%rbp), %edx
	movl	24(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -8(%rbp)
# t69 = 2
	movl	$2, -12(%rbp)
# t70 = t68 / t69
	movl	-8(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	movl	%eax, -16(%rbp)
# t71 = l + t70
	movl	24(%rbp), %eax
	movl	-16(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
# m = t71
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
# param arr
# param l
# param m
# t73 = call mergeSort, 3
	movq	-24(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	movq	16(%rbp), %rdi
	movq	%rdi, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	mergeSort
	movq	%rax, -36(%rbp)
	addq	$16, %rsp
# t75 = 1
	movl	$1, -44(%rbp)
# t76 = m + t75
	movl	-24(%rbp), %eax
	movl	-44(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -48(%rbp)
# param arr
# param t76
# param r
# t77 = call mergeSort, 3
	movq	32(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	movq	16(%rbp), %rdi
	movq	%rdi, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	mergeSort
	movq	%rax, -52(%rbp)
	addq	$16, %rsp
# param arr
# param l
# param m
# param r
# t79 = call merge, 4
	movq	32(%rbp), %rax
	pushq	%rax
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	movq	16(%rbp), %rdi
	movq	%rdi, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	merge
	movq	%rax, -64(%rbp)
	addq	$20, %rsp
# goto .L20
	jmp	.L20
# t80 = 0
.L20:
	movl	$0, -68(%rbp)
# return t80
	movq	-68(%rbp), %rax
	leave
	ret
# function mergeSort ends
	leave
	ret
	.size	mergeSort, .-mergeSort
# printArray: 
	.text
	.globl	printArray
	.type	printArray, @function
printArray:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64, %rsp
# t81 = 0
	movl	$0, -8(%rbp)
# i = t81
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
# t82 = 1
.L23:
	movl	$1, -12(%rbp)
# if i < size goto .L21
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jge	.L33
	jmp	.L21
.L33:
# t82 = 0
	movl	$0, -12(%rbp)
# goto .L22
	jmp	.L22
# goto .L22
	jmp	.L22
# t83 = i
.L24:
	movl	-4(%rbp), %eax
	movl	%eax, -16(%rbp)
# i = i + 1
	movl	-4(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
# goto .L23
	jmp	.L23
# t84 = 0
.L21:
	movl	$0, -24(%rbp)
# t85 = i
	movl	-4(%rbp), %eax
	movl	%eax, -28(%rbp)
# t85 = t85 * 4
	movl	-28(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -28(%rbp)
# t84 = t85
	movl	-28(%rbp), %eax
	movl	%eax, -24(%rbp)
# t86 = A[t84]
	movl	-24(%rbp), %edx
cltq
	movq	16(%rbp), %rdi
	addq	%rdi, %rdx
	movq	(%rdx) ,%rax
	movq	%rax, -32(%rbp)
# param t86
# t87 = call printInt, 1
	movq	-32(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printInt
	movq	%rax, -36(%rbp)
	addq	$4, %rsp
# param .LC0
# t88 = call printStr, 1
	movq	$.LC0, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -48(%rbp)
	addq	$4, %rsp
# goto .L24
	jmp	.L24
# param .LC1
.L22:
# t89 = call printStr, 1
	movq	$.LC1, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -56(%rbp)
	addq	$4, %rsp
# t90 = 0
	movl	$0, -60(%rbp)
# return t90
	movq	-60(%rbp), %rax
	leave
	ret
# function printArray ends
	leave
	ret
	.size	printArray, .-printArray
# main: 
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$224, %rsp
# param .LC2
# t91 = call printStr, 1
	movq	$.LC2, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -12(%rbp)
	addq	$4, %rsp
# t92 = 6
	movl	$6, -16(%rbp)
# t93 = 0
	movl	$0, -44(%rbp)
# t94 = 0
	movl	$0, -48(%rbp)
# t95 = t93
	movl	-44(%rbp), %eax
	movl	%eax, -52(%rbp)
# t95 = t95 * 4
	movl	-52(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -52(%rbp)
# t94 = t95
	movl	-52(%rbp), %eax
	movl	%eax, -48(%rbp)
# t96 = 3
	movl	$3, -56(%rbp)
# arr[t94] = t96
	movl	-48(%rbp), %edx
	movl	-56(%rbp), %eax
cltq
	movl	%eax, -40(%rbp,%rdx,1)
# t97 = 1
	movl	$1, -60(%rbp)
# t98 = 0
	movl	$0, -64(%rbp)
# t99 = t97
	movl	-60(%rbp), %eax
	movl	%eax, -68(%rbp)
# t99 = t99 * 4
	movl	-68(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -68(%rbp)
# t98 = t99
	movl	-68(%rbp), %eax
	movl	%eax, -64(%rbp)
# t100 = 5
	movl	$5, -72(%rbp)
# arr[t98] = t100
	movl	-64(%rbp), %edx
	movl	-72(%rbp), %eax
cltq
	movl	%eax, -40(%rbp,%rdx,1)
# t101 = 2
	movl	$2, -76(%rbp)
# t102 = 0
	movl	$0, -80(%rbp)
# t103 = t101
	movl	-76(%rbp), %eax
	movl	%eax, -84(%rbp)
# t103 = t103 * 4
	movl	-84(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -84(%rbp)
# t102 = t103
	movl	-84(%rbp), %eax
	movl	%eax, -80(%rbp)
# t104 = 9
	movl	$9, -88(%rbp)
# arr[t102] = t104
	movl	-80(%rbp), %edx
	movl	-88(%rbp), %eax
cltq
	movl	%eax, -40(%rbp,%rdx,1)
# t105 = 3
	movl	$3, -92(%rbp)
# t106 = 0
	movl	$0, -96(%rbp)
# t107 = t105
	movl	-92(%rbp), %eax
	movl	%eax, -100(%rbp)
# t107 = t107 * 4
	movl	-100(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -100(%rbp)
# t106 = t107
	movl	-100(%rbp), %eax
	movl	%eax, -96(%rbp)
# t108 = 13
	movl	$13, -104(%rbp)
# arr[t106] = t108
	movl	-96(%rbp), %edx
	movl	-104(%rbp), %eax
cltq
	movl	%eax, -40(%rbp,%rdx,1)
# t109 = 4
	movl	$4, -108(%rbp)
# t110 = 0
	movl	$0, -112(%rbp)
# t111 = t109
	movl	-108(%rbp), %eax
	movl	%eax, -116(%rbp)
# t111 = t111 * 4
	movl	-116(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -116(%rbp)
# t110 = t111
	movl	-116(%rbp), %eax
	movl	%eax, -112(%rbp)
# t112 = 23
	movl	$23, -120(%rbp)
# arr[t110] = t112
	movl	-112(%rbp), %edx
	movl	-120(%rbp), %eax
cltq
	movl	%eax, -40(%rbp,%rdx,1)
# t113 = 5
	movl	$5, -124(%rbp)
# t114 = 0
	movl	$0, -128(%rbp)
# t115 = t113
	movl	-124(%rbp), %eax
	movl	%eax, -132(%rbp)
# t115 = t115 * 4
	movl	-132(%rbp), %eax
	imull	$4, %eax
	movl	%eax, -132(%rbp)
# t114 = t115
	movl	-132(%rbp), %eax
	movl	%eax, -128(%rbp)
# t116 = 4
	movl	$4, -136(%rbp)
# arr[t114] = t116
	movl	-128(%rbp), %edx
	movl	-136(%rbp), %eax
cltq
	movl	%eax, -40(%rbp,%rdx,1)
# t117 = 6
	movl	$6, -140(%rbp)
# arr_size = t117
	movl	-140(%rbp), %eax
	movl	%eax, -144(%rbp)
# param .LC3
# t118 = call printStr, 1
	movq	$.LC3, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -152(%rbp)
	addq	$4, %rsp
# param arr
# param arr_size
# t120 = call printArray, 2
	movq	-144(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	leaq	-40(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printArray
	movq	%rax, -164(%rbp)
	addq	$12, %rsp
# t122 = 0
	movl	$0, -176(%rbp)
# t123 = 1
	movl	$1, -180(%rbp)
# t124 = arr_size - t123
	movl	-144(%rbp), %edx
	movl	-180(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -184(%rbp)
# param arr
# param t122
# param t124
# t125 = call mergeSort, 3
	movq	-184(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdx
	movq	-176(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	leaq	-40(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	mergeSort
	movq	%rax, -188(%rbp)
	addq	$16, %rsp
# param .LC4
# t126 = call printStr, 1
	movq	$.LC4, %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printStr
	movq	%rax, -196(%rbp)
	addq	$4, %rsp
# param arr
# param arr_size
# t128 = call printArray, 2
	movq	-144(%rbp), %rax
	pushq	%rax
	movq	%rax, %rsi
	leaq	-40(%rbp), %rax
	pushq	%rax
	movq	%rax, %rdi
	call	printArray
	movq	%rax, -204(%rbp)
	addq	$12, %rsp
# t129 = 0
	movl	$0, -208(%rbp)
# return t129
	movq	-208(%rbp), %rax
	leave
	ret
# function main ends
	leave
	ret
	.size	main, .-main
