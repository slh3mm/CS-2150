	;; Spencer Hernandez
	;; Pre-lab 08
	;; mathlib.s

	global product
	global power
	
product:
	;;prologue
	push rdi
	mov rax, 0

loop:
	;; subroutine
	cmp rsi, 0
	je end
	add rax, rdi
	sub rsi, 1
	jmp loop
end:
	;; epilogue
	pop rdi
	ret

	
power:
	cmp rsi,0
	jne loop2
	mov rax, 1
	jmp end2
loop2:
	sub rsi, 1
	push rdi
	push rsi
	call power
	pop rsi
	pop rdi
	mov rsi, rax
	call product
	jmp end2
end2:
	ret
	
	
	;; take in 2 numbers a and b to calculate a^b
	;; if b is 0 return 1
	;; else, return product(a, power(a,b-1))
	
	
