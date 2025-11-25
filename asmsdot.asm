section .data
ini dd 0.0

section .bss
sdot		resd 1

section .text
bits 64
default rel

global asmsdot
asmsdot:
	XOR R10, R10		; let R10 be the counter for loop
	MOVSS XMM0, [ini]	; let XMM0 be the temporary storage for the summation
	SDOT_LOOP:
		CMP R10, R8
		JE DONE

		MOVSS XMM1, [RCX+R10*4]
		MOVSS XMM2, [RDX+R10*4]

		MULSS XMM1, XMM2
		ADDSS XMM0, XMM1

		INC R10
		JMP SDOT_LOOP

	DONE:
		MOVSS dword[sdot], XMM0	; store output to sdot
		MOVSS [R9], XMM0
		ret