global  _ft_strcmp

section .text
_ft_strcmp:
    push    r8
    push    r9
    push    rdi
    push    rsi
    mov     r8, 0
    mov     r9, 0
.cycle:
    mov     r8b, byte [rdi]
    mov     r9b, byte [rsi]
    cmp     r8b, 0
    jz      .re
    cmp     r9b, 0
    jz      .re
    cmp     r8b, r9b
    jnz     .re
    inc     rdi
    inc     rsi
    jmp     .cycle
.re:
    sub     r8, r9
    mov     rax, r8
    pop     rsi
    pop     rdi
    pop     r9
    pop     r8
    ret