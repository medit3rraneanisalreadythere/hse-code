%include "io.inc"

CEXTERN fopen
CEXTERN fscanf
CEXTERN qsort
CEXTERN fprintf
CEXTERN fclose

section .bss
    input resd 1
    output resd 1
    x resd 1
    arr resd 1000
    save resd 1

section .data
    k dd 0

section .rodata
    file1 db "input.txt", 0
    file2 db "output.txt", 0
    stringformat1 db "%d", 0
    stringformat2 db "%d ", 0
    readmode db "r", 0
    writemode db "w", 0
    
section .text
foo:
    push ebp
    mov ebp, esp
    push esi
    push edi
    
    mov esi, dword[ebp + 8]
    mov edi, dword[esi]
    mov esi, dword[ebp + 12]
    mov esi, dword[esi]
    cmp edi, esi
    jge .L2
    mov eax, -1
    jmp .L3
.L2:
    mov esi, dword[ebp + 8]
    mov edi, dword[esi]
    mov esi, dword[ebp + 12]
    mov esi, dword[esi]
    cmp edi, esi
    jne .L4
    mov eax, 0
    jmp .L3
.L4:
    mov eax, 1
.L3:
    pop edi
    pop esi
    mov esp, ebp
    pop ebp
    ret

global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    push ebp
    mov ebp, esp
    and esp, ~15
    sub esp, 16
    ; выравнивание стека по 16 байт
    
    mov dword[esp + 4], readmode
    mov dword[esp], file1
    call fopen
    mov dword[input], eax
    
    .while:
        mov dword[esp + 8], x
        mov dword[esp + 4], stringformat1
        mov eax, dword[input]
        mov dword[esp], eax
        call fscanf
        cmp eax, 0
        jle .while_end
        mov eax, dword[x]
        mov ecx, dword[k]
        mov dword[arr + 4 * ecx], eax
        inc dword[k]
        jmp .while
    .while_end:
    
    mov eax, dword[input]
    mov dword[esp], eax
    call fclose
    
    mov dword[esp + 12], foo
    mov dword[esp + 8], 4
    mov ecx, dword[k]
    mov dword[esp + 4], ecx
    mov dword[esp], arr
    call qsort
    
    mov dword[esp + 4], writemode
    mov dword[esp], file2
    call fopen
    mov dword[output], eax
    
    xor ecx, ecx
    .for:
        cmp ecx, dword[k]
        je .for_end
        mov eax, dword[arr + 4 * ecx]
        mov dword[esp + 8], eax
        mov dword[esp + 4], stringformat2
        mov eax, dword[output]
        mov dword[esp], eax
        mov dword[save], ecx
        call fprintf
        mov ecx, dword[save]
        inc ecx
        jmp .for
    .for_end:
    
    mov eax, dword[output]
    mov dword[esp], eax
    call fclose
     
    mov esp, ebp
    pop ebp
    xor eax, eax
    ret