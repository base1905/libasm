global		_ft_write
section		.text
extern		___error

_ft_write:	mov rax, 0x2000004
			syscall
			jc .re
			ret
.re:		push rax
			call ___error	
			pop	r9
			mov [rax], r9
			mov rax, -1
			ret