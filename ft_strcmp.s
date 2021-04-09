global _ft_strcmp
		section .text
_ft_strcmp:
ll:		
		mov bh, byte [rsi]
		or	bh, byte [rdi]
		jz	check
		mov	al, byte [rdi]
		cmp	al, byte [rsi]
		jne	check
		inc	rdi
		inc	rsi
		jmp ll
check:
		movzx	rax, byte [rdi]
		movzx	rcx, byte [rsi]
		sub		rax, rcx
		ret
