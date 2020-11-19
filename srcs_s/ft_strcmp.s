section .text
    global ft_strcmp


ft_strcmp:
	mov 	rax, 0
	mov 	cx, 0
	mov 	dx, 0

ft_strcmp_loop:
	mov 	cl, [rdi + rax]
	mov 	dl, [rsi + rax]
	cmp 	cl, 0
	je		ft_ret
	cmp 	dl, 0
	je 		ft_ret
	cmp 	cl, dl
	jne 	ft_ret
	inc 	rax	
	jmp 	ft_strcmp_loop

ft_ret:
	cmp 	cx, dx
	jl 		neg_ret
	ja 		pos_ret
	jmp 	eq_ret

neg_ret:
	mov rax, -1
	jmp exit

pos_ret:
	mov rax, 1
	jmp exit

eq_ret:
	mov rax, 0
	jmp exit

exit:
	ret
    mov rax, 60
    mov rdi, 0
    syscall