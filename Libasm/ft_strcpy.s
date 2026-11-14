global ft_strcpy
section .text

;	char *strcpy(char *dest, const char *src);
ft_strcpy:
	xor rcx, rcx

.loop:
	mov dl, [rsi + rcx]
	mov [rdi + rcx], dl

	cmp dl, 0
	je 	.done
	inc rcx
	jmp .loop

.done:
	mov rcx, rax
	ret