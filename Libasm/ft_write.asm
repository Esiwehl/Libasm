global ft_write
; STILL NEED TO SET ERRNO

section .text

ft_write:
    mov edx,rdx     ; message length.
    mov rsi,     ; message to write
    mov rdi,       ; fd stdout
    mov eax,4       ; system call number (sys_write)
    int 0x80        ; call kernel, but why is this necessary?

    mov eax,1       ; system call om te exiten
    int 0x80  