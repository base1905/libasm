global		_ft_strcpy
section		.text

_ft_strcpy:
			mov rax, rdi
.cycle:
			mov r9, [rsi]
			MOV [rdi], r9
			inc rdi
			inc rsi
			cmp byte [rsi], 0
			jz  .re
			jmp .cycle
.re:
			ret