section .text
    global ft_read
    extern __errno_location

ft_read:
    mov rax, 0
    syscall
    test rax, rax
    jnl .return

    push r10
    neg rax
    mov r10, rax
    call __errno_location
    mov dword [rax], r10d
    mov rax, -1
	pop r10

.return:
	ret

