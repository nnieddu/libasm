section .text
    global ft_read
	extern __errno_location

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl error
	jmp exit
    
error:
	neg rax
	mov r15, rax
	call __errno_location
	mov [rax], r15
	mov rax, -1

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall