global		_ft_strlen
section		.text

_ft_strlen:
			mov rax, 0
			push rdi
.cycle:		
			cmp byte [rdi + rax], 0
			jz .re
			inc rax
			jmp .cycle
.re:	
			pop rdi
			ret