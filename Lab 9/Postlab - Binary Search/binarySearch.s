global binarySearch
section .text
	
binarySearch:
	cmp edx, -1		;Check if size == 0
	je terminate
body:	
	;; rdi: arr
	;; rsi:	low
	;; rdx: high
	;; rcx: key
	;; r10: mid
	cmp rsi, rdx 		;Check if(low <= high)
	jg terminate
	
	mov r10, rsi 		;Create mid
	add r10, rdx
	shr r10, 1
	
	cmp [rdi + r10*4], ecx	;Compare and jump accordingly
	jl lessThan
	jg greaterThan
equal:
	mov rax, r10
	ret
lessThan:	
	mov rsi, r10
	inc rsi
	jmp body
greaterThan:	
	mov rdx, r10
	dec rdx
	jmp body
terminate:	
	mov rax, -1
	ret
