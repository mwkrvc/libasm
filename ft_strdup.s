global _ft_strdup
		extern _malloc
		extern _ft_strlen
		extern _ft_strcpy
		section .text
_ft_strdup:
		cmp rdi, 0
		je	exc
		call _ft_strlen
		inc	rax
		push rdi
		mov rdi, rax
		call _malloc
		cmp rax, 0
		je	malloc_error
		pop r8
		mov rsi, r8
		mov rdi, rax
		call _ft_strcpy
		ret
exc:
		mov rax, 0
		ret		
malloc_error:
		ret
