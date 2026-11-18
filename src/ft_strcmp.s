%macro LOAD_CHARS 0
	movzx rax, byte [rdi]
	movzx rdx, byte [rsi]
%endmacro

global ft_strcmp
section .text

ft_strcmp:
.loop:
	movzx rax, byte [rdi]
	movzx rdx, byte [rsi]
	cmp rax, rdx
	jne .diff

	test rax, rax
	jz .equal

	inc rdi
	inc rsi
	jmp .loop

.diff:
	sub rax, rdx
	ret

.equal:
	xor eax, eax
	ret
