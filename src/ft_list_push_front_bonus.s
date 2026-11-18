global ft_list_push_front
extern malloc

section .text
ft_list_push_front:
    test rdi, rdi
    jz .return

    push r12
    push r13
    sub rsp, 8

    mov r12, rdi
    mov r13, rsi

    mov rdi, 16
    call malloc wrt ..plt
    test rax, rax
    jz .done

    mov [rax], r13
    mov rdx, [r12]
    mov [rax + 8], rdx
    mov [rbx], r12

.done:
    add rsp, 8
    pop r13
    pop r12

.return:
    ret