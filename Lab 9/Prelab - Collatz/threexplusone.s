	;; Used lea to compute 3n+1 faster than previously
	;; Used a bit shift right to divide by 2 instead of using idiv
	;; Used test in order to perform modulo operation
global threexplusone
	
section .text
	
	
threexplusone:
	cmp rdi, 1		;Base Case
	je baseCase
	test rdi, 1
	jz even			;jump to even if x % 2 ==0
	lea rdi, [rdi*3 + 1]	;else, do the odd procedure
	call threexplusone
	inc rax
	
	ret
even:
	sar rdi, 1 		;mov rdi, rax
	call threexplusone
	inc rax
	ret
baseCase:			; baseCase
	mov rax, 0
	ret
