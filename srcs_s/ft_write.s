section .text
	global ft_write
	extern __errno_location

ft_write:
	mov rax, 1
    mov rdi, 1
	syscall
    cmp rax, 0
    jl  error
    cmp rax, 0
    jge exit

error:
    call __errno_location
	ret
    mov rax, 60
    mov rdi, -1
    syscall

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall