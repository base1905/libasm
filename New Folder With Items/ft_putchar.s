global _ft_putchar

section .text
_ft_putchar:
	push	rdi
	mov	rax, 0x2000004
	mov	rsi, rdi
	mov	rdi, 1
	mov	rdx, 1
	syscall
	pop	rdi
	ret
	
	
	
	
	
	;RDI RSI RDX
