section .text
	global ft_write
	extern __errno_location

ft_write:
	mov		rax, 1
	syscall
	cmp 	rax, 0
	jl 		ft_error
	jmp		exit

ft_error:
	neg 	rax
	mov 	rdx, rax
	call	__errno_location
	mov 	[rax], rdx
	mov 	rax, -1
	jmp		exit

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall	