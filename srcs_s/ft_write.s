section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rax, 1
    cmp edx, -1
    jle  negativ_count
	syscall
    cmp rax, -1
    jle  error
    jmp exit

negativ_count:
    mov rax, 14
    mov rbx, rax
	call __errno_location
	mov [rax], rbx
	mov rax, -1
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
