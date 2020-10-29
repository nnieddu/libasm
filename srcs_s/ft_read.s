section .text
    global ft_read

ft_read:
	mov rax, 0
	cmp rsi, 0
	je ret_0
	syscall
	cmp rax, 0
	jl err_call
	jmp exit
    
err_call:
	neg rax
	mov r15, rax
	call __errno_location
	mov [rax], r15
	mov rax, -1
	ret
ret_0:
	mov rax, 0
	jmp exit

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall