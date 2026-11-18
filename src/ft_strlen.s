global ft_strlen
section .text

ft_strlen:
    xor rcx,rcx
    .loop:
        cmp byte [rdi + rcx], 0x00
        je .done
        inc rcx
        jmp .loop
    .done:
        mov rax,rcx
        ret
