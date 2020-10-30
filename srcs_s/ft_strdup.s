section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	call	ft_strlen
	add		rax, 1
	mov		rbx, rdi
	mov		rdi, rax
	call	malloc
	mov		rdi, rax	
	mov		rsi, rbx
	call	ft_strcpy

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall