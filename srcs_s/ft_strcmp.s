section .text
    global ft_strcmp

ft_strcmp:
    mov    rax, 0
    mov     rcx, 0

ft_strcmp_s1:
    cmp byte [rdi + rax], 0
    je ft_strcmp_s2
    inc rax
    jmp ft_strcmp_s1

ft_strcmp_s2:
    cmp byte [rsi + rcx], 0
    je  ft_result_comput
    inc rcx
    jmp ft_strcmp_s2

ft_result_comput:
    cmp rax, rcx
    je ft_result0
    cmp rax, rcx
    jg ft_result1
    cmp rax, rcx
    jl ft_resultm1

ft_result0:
    mov     rax, 0
    jmp exit

ft_result1:
    mov     rax, 1
    jmp exit

ft_resultm1:
    mov     rax, -1
    jmp exit

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall