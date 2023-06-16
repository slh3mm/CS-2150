	global linearSearch

linearSearch:
	mov rbx, 0		;set r10 as i

body:	
	;; if (i !< n)
	;; 	return -1
	;; else
	;; 	if(arr[i] !=x)
	;; 		jmp to increment i
	;;	else
	;; 		return i
	;; 	i++
	;; 	jmp to comparison
	cmp ebx, esi		;compares i to n
	jnl notLessThan		;jump if i !<n
	
	cmp [rdi + 4*rbx], edx	;compares arr[i] to x 
	jne increment		;jumps if not equal

	mov rax, rbx
	ret

notLessThan:	
	mov rax, -1
	ret
	
increment:
	inc rbx
	jmp body
