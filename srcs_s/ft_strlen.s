section .text
	global	ft_strlen

ft_strlen:
	mov		rax, 0

ft_strlen_loop:
	cmp		byte [rdi + rax], 0
	je		exit
	inc		rax
	jmp		ft_strlen_loop

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall