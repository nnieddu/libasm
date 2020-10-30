section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rax, 1
    cmp rdx, -1
    jle  error2
	syscall
    cmp rax, -1
    jle  error
    jmp exit

error2:
    mov rax, -1
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
