global ft_write
extern __errno_location
section .text

ft_write:
    mov eax, 1
    syscall

    cmp rax,0
    jl .error
    ret

.error:
    neg  rax 
    push rax

    call __errno_location wrt ..plt

    pop rdx

    mov [rax], rdx 
    mov rax, -1
    ret