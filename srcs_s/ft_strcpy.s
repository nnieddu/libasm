section .text
	global  ft_strcpy

ft_strcpy:
	mov     rax, 0

ft_strcpy_loop:
	mov		cl, byte[rsi + rax]
	mov		byte[rdi + rax], cl
	cmp		cl, 0
	je		exit
	inc		rax
	jmp		ft_strcpy_loop

exit:
	mov		rax, rdi
	ret
    mov rax, 60
    mov rdi, 0
    syscall	