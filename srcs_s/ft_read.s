section .text
    global ft_read
	extern __errno_location

ft_read:
	mov 	rax, 0
	syscall
	cmp 	rax, 0
	jl 		ft_error
	jmp		exit

ft_error:
	neg 	rax
	mov 	rdx, rax
	call 	__errno_location
	mov 	[rax], rdx
	mov 	rax, -1
	ret

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall