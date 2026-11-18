global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

section .text

ft_strdup:
	push rbx
	mov rbx, rdi

	call ft_strlen wrt ..plt

	lea rdi, [rax + 1]
	call malloc wrt ..plt

	test rax, rax
	jz .done

	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy wrt ..plt

.done:
	pop rbx
	ret