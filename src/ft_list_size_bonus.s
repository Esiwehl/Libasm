global ft_list_size

section .text

ft_list_size:
    xor rax, rax
    
.loopity:
    test rdi, rdi
    jz .return
    inc rax
    mov rdi, [rdi + 8]
    jmp .loopity

.return:
    ret