%include "io.inc"

CEXTERN fopen
CEXTERN fscanf
CEXTERN printf
CEXTERN fclose

section .bss
    input resd 1
    x resd 1

section .data
    k dd 0

section .rodata
    file db "data.in", 0
    stringformat db "%d", 0
    readmode db "r", 0
    
section .text
global CMAIN
CMAIN:
    push ebp
    mov ebp, esp
    and esp, ~15
    sub esp, 16
    ; выравнивание стека по 16 байт
    
    mov dword[esp + 4], readmode
    mov dword[esp], file
    call fopen
    mov dword[input], eax
    
    .while:
        mov dword[esp + 8], x
        mov dword[esp + 4], stringformat
        mov eax, dword[input]
        mov dword[esp], eax
        call fscanf
        cmp eax, 0
        jle .while_end
        inc dword[k]
        jmp .while
    .while_end:
    
    mov eax, dword[input]
    mov dword[esp], eax
    call fclose
    
    mov eax, dword[k]
    mov dword[esp + 4], eax
    mov dword[esp], stringformat
    call printf
    
    mov esp, ebp
    pop ebp
    xor eax, eax
    ret