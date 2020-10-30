section .text
    global ft_strcmp

ft_strcmp:
	mov		rax, 0
	mov 	rdx, 0
	cmp		rdi, 0
	je		return
	cmp		rsi, 0
	je		return

while:
	mov		bl, byte [rdi + rax]
	cmp		byte [rsi + rax], bl
	jne		return
	cmp		bl, 0
	je		return
	cmp		byte [rsi + rax], 0
	je		return
	inc		rax
	jmp		while

return:
	mov		rdi, [rdi + rax]
	and		rdi, 255
	mov		rsi, [rsi + rax]
	and		rsi, 255
	mov		rax, rdi
	sub		rax, rsi
	cmp rax, 0
    je ft_result0
    cmp rax, 0
    jg ft_result1
    cmp rax, 0
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