section .data
ini			dd 0.0

section .bss
temp_prod	resd 100
sdot		resd 1

section .text
global asmsdot
asmsdot:
	XOR R9, R9		; let R9 be the traversal
	XOR RBX, RBX		; let RBX be the counter for loop
	MOVSS XMM0, [ini]	; let XMM0 be the temporary storage for the summation
	SDOT_LOOP:
		CMP RBX, R8
		JZ DONE

		MOVSS XMM1, [RCX+R9]
		MOVSS XMM2, [RDX+R9]

		MULSS XMM1, XMM2
		ADDSS XMM0, XMM1

		ADD R9, 4
		INC RBX
		JUMP SDOT_LOOP

	DONE:
		MOVSS dword[sdot], XMM0	; store output to sdot
		ret