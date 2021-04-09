global _ft_strcpy
		section .text
_ft_strcpy:
		mov rcx, 0
		cmp rdi, 0
		je exc
		cmp rsi, 0
		je exc
ll:
		mov al, byte [rsi + rcx]
		mov byte [rdi + rcx], al
		cmp	byte[rsi + rcx], 0
		je quit
		inc rcx
		jmp ll
quit:
		mov rax, rdi
		ret
exc:
		mov rax, 0
		ret
