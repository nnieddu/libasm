section .text
    global ft_read
	extern __errno_location

ft_read:
	mov rax, 0
	cmp rsi, 0
	je 	exit
	syscall
	cmp rax, 0
	jl error
	jmp exit
    
error:
	neg rax
	mov rbx, rax
	call __errno_location
	mov [rax], rbx
	mov rax, -1

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall