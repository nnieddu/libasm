section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	call	ft_strlen	; call ft_strlen [rax = len of rdi(argv[0])]
	add		rax, 1		; rax + 1, for '\0' end
	push	rdi			; push rdi to the stack
	mov		rdi, rax	; rdi = rax 
	call	malloc		; malloc return (string malloc in rax)
	pop		r8			; pop old rdi to r8
	mov		rdi, rax	
	mov		rsi, r8
	call	ft_strcpy
	jmp exit

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall