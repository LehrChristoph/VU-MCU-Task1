	.file	"pid.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	pid_Init
	.type	pid_Init, @function
pid_Init:
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,8
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 8 */
/* stack size = 10 */
.L__stack_usage = 10
	std Y+2,r25
	std Y+1,r24
	std Y+4,r23
	std Y+3,r22
	std Y+6,r21
	std Y+5,r20
	std Y+8,r19
	std Y+7,r18
	ldd r24,Y+7
	ldd r25,Y+8
	mov r30,r24
	mov r31,r25
	std Z+2,__zero_reg__
	std Z+3,__zero_reg__
	std Z+4,__zero_reg__
	std Z+5,__zero_reg__
	ldd r24,Y+7
	ldd r25,Y+8
	mov r30,r24
	mov r31,r25
	std Z+1,__zero_reg__
	st Z,__zero_reg__
	ldd r24,Y+7
	ldd r25,Y+8
	ldd r18,Y+1
	ldd r19,Y+2
	mov r30,r24
	mov r31,r25
	std Z+7,r19
	std Z+6,r18
	ldd r24,Y+7
	ldd r25,Y+8
	ldd r18,Y+3
	ldd r19,Y+4
	mov r30,r24
	mov r31,r25
	std Z+9,r19
	std Z+8,r18
	ldd r24,Y+7
	ldd r25,Y+8
	ldd r18,Y+5
	ldd r19,Y+6
	mov r30,r24
	mov r31,r25
	std Z+11,r19
	std Z+10,r18
	ldd r24,Y+7
	ldd r25,Y+8
	mov r30,r24
	mov r31,r25
	ldd r24,Z+6
	ldd r25,Z+7
	mov r18,r24
	mov r19,r25
	subi r18,-1
	sbci r19,-1
	ldi r24,lo8(-1)
	ldi r25,lo8(127)
	mov r22,r18
	mov r23,r19
	rcall __divmodhi4
	mov r24,r22
	mov r25,r23
	mov r18,r24
	mov r19,r25
	ldd r24,Y+7
	ldd r25,Y+8
	mov r30,r24
	mov r31,r25
	std Z+13,r19
	std Z+12,r18
	ldd r24,Y+7
	ldd r25,Y+8
	mov r30,r24
	mov r31,r25
	ldd r24,Z+8
	ldd r25,Z+9
	adiw r24,1
	mov r19,r25
	mov r18,r24
	lsl r25
	sbc r20,r20
	sbc r21,r21
	ldi r24,lo8(-1)
	ldi r25,lo8(-1)
	ldi r26,lo8(-1)
	ldi r27,lo8(63)
	mov r22,r24
	mov r23,r25
	mov r24,r26
	mov r25,r27
	rcall __divmodsi4
	mov r27,r21
	mov r26,r20
	mov r25,r19
	mov r24,r18
	ldd r18,Y+7
	ldd r19,Y+8
	mov r30,r18
	mov r31,r19
	std Z+14,r24
	std Z+15,r25
	std Z+16,r26
	std Z+17,r27
	nop
/* epilogue start */
	adiw r28,8
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
	.size	pid_Init, .-pid_Init
.global	__mulsi3
.global	pid_Controller_c
	.type	pid_Controller_c, @function
pid_Controller_c:
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,24
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 24 */
/* stack size = 26 */
.L__stack_usage = 26
	std Y+20,r25
	std Y+19,r24
	std Y+22,r23
	std Y+21,r22
	std Y+24,r21
	std Y+23,r20
	ldd r18,Y+19
	ldd r19,Y+20
	ldd r24,Y+21
	ldd r25,Y+22
	mov r20,r18
	mov r21,r19
	sub r20,r24
	sbc r21,r25
	mov r24,r20
	mov r25,r21
	std Y+12,r25
	std Y+11,r24
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r18,Z+12
	ldd r19,Z+13
	ldd r24,Y+11
	ldd r25,Y+12
	cp r18,r24
	cpc r19,r25
	brge .L3
	ldi r24,lo8(-1)
	ldi r25,lo8(127)
	std Y+2,r25
	std Y+1,r24
	rjmp .L4
.L3:
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r24,Z+12
	ldd r25,Z+13
	clr r18
	clr r19
	sub r18,r24
	sbc r19,r25
	ldd r24,Y+11
	ldd r25,Y+12
	cp r24,r18
	cpc r25,r19
	brge .L5
	ldi r24,lo8(1)
	ldi r25,lo8(-128)
	std Y+2,r25
	std Y+1,r24
	rjmp .L4
.L5:
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r24,Z+6
	ldd r25,Z+7
	ldd r18,Y+11
	ldd r19,Y+12
	mov r22,r18
	mov r23,r19
	rcall __mulhi3
	std Y+2,r25
	std Y+1,r24
.L4:
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r18,Z+2
	ldd r19,Z+3
	ldd r20,Z+4
	ldd r21,Z+5
	ldd r24,Y+11
	ldd r25,Y+12
	mov __tmp_reg__,r25
	lsl r0
	sbc r26,r26
	sbc r27,r27
	add r24,r18
	adc r25,r19
	adc r26,r20
	adc r27,r21
	std Y+13,r24
	std Y+14,r25
	std Y+15,r26
	std Y+16,r27
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r18,Z+14
	ldd r19,Z+15
	ldd r20,Z+16
	ldd r21,Z+17
	ldd r24,Y+13
	ldd r25,Y+14
	ldd r26,Y+15
	ldd r27,Y+16
	cp r18,r24
	cpc r19,r25
	cpc r20,r26
	cpc r21,r27
	brge .L6
	ldi r24,lo8(-1)
	ldi r25,lo8(-1)
	ldi r26,lo8(-1)
	ldi r27,lo8(63)
	std Y+3,r24
	std Y+4,r25
	std Y+5,r26
	std Y+6,r27
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r24,Z+14
	ldd r25,Z+15
	ldd r26,Z+16
	ldd r27,Z+17
	ldd r18,Y+23
	ldd r19,Y+24
	mov r30,r18
	mov r31,r19
	std Z+2,r24
	std Z+3,r25
	std Z+4,r26
	std Z+5,r27
	rjmp .L7
.L6:
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r24,Z+14
	ldd r25,Z+15
	ldd r26,Z+16
	ldd r27,Z+17
	clr r18
	clr r19
	clr r20
	clr r21
	sub r18,r24
	sbc r19,r25
	sbc r20,r26
	sbc r21,r27
	ldd r24,Y+13
	ldd r25,Y+14
	ldd r26,Y+15
	ldd r27,Y+16
	cp r24,r18
	cpc r25,r19
	cpc r26,r20
	cpc r27,r21
	brge .L8
	ldi r24,lo8(1)
	ldi r25,0
	ldi r26,0
	ldi r27,lo8(-64)
	std Y+3,r24
	std Y+4,r25
	std Y+5,r26
	std Y+6,r27
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r24,Z+14
	ldd r25,Z+15
	ldd r26,Z+16
	ldd r27,Z+17
	com r27
	com r26
	com r25
	neg r24
	sbci r25,lo8(-1)
	sbci r26,lo8(-1)
	sbci r27,lo8(-1)
	ldd r18,Y+23
	ldd r19,Y+24
	mov r30,r18
	mov r31,r19
	std Z+2,r24
	std Z+3,r25
	std Z+4,r26
	std Z+5,r27
	rjmp .L7
.L8:
	ldd r18,Y+23
	ldd r19,Y+24
	ldd r24,Y+13
	ldd r25,Y+14
	ldd r26,Y+15
	ldd r27,Y+16
	mov r30,r18
	mov r31,r19
	std Z+2,r24
	std Z+3,r25
	std Z+4,r26
	std Z+5,r27
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r24,Z+8
	ldd r25,Z+9
	mov __tmp_reg__,r25
	lsl r0
	sbc r26,r26
	sbc r27,r27
	ldd r18,Y+23
	ldd r19,Y+24
	mov r30,r18
	mov r31,r19
	ldd r18,Z+2
	ldd r19,Z+3
	ldd r20,Z+4
	ldd r21,Z+5
	mov r22,r24
	mov r23,r25
	mov r24,r26
	mov r25,r27
	rcall __mulsi3
	mov r27,r25
	mov r26,r24
	mov r25,r23
	mov r24,r22
	std Y+3,r24
	std Y+4,r25
	std Y+5,r26
	std Y+6,r27
.L7:
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ldd r20,Z+10
	ldd r21,Z+11
	ldd r24,Y+23
	ldd r25,Y+24
	mov r30,r24
	mov r31,r25
	ld r18,Z
	ldd r19,Z+1
	ldd r24,Y+21
	ldd r25,Y+22
	sub r18,r24
	sbc r19,r25
	mov r24,r20
	mov r25,r21
	mov r22,r18
	mov r23,r19
	rcall __mulhi3
	std Y+18,r25
	std Y+17,r24
	ldd r24,Y+23
	ldd r25,Y+24
	ldd r18,Y+21
	ldd r19,Y+22
	mov r30,r24
	mov r31,r25
	std Z+1,r19
	st Z,r18
	ldd r24,Y+1
	ldd r25,Y+2
	mov r19,r25
	mov r18,r24
	lsl r25
	sbc r20,r20
	sbc r21,r21
	ldd r24,Y+3
	ldd r25,Y+4
	ldd r26,Y+5
	ldd r27,Y+6
	add r18,r24
	adc r19,r25
	adc r20,r26
	adc r21,r27
	ldd r24,Y+17
	ldd r25,Y+18
	mov __tmp_reg__,r25
	lsl r0
	sbc r26,r26
	sbc r27,r27
	add r24,r18
	adc r25,r19
	adc r26,r20
	adc r27,r21
	tst r27
	brge .L9
	subi r24,-127
	sbci r25,-1
	sbci r26,-1
	sbci r27,-1
.L9:
	set
	bld __zero_reg__,7-1
	1:
	asr r27
	ror r26
	ror r25
	ror r24
	lsr __zero_reg__
	brne 1b
	std Y+7,r24
	std Y+8,r25
	std Y+9,r26
	std Y+10,r27
	ldd r24,Y+7
	ldd r25,Y+8
	ldd r26,Y+9
	ldd r27,Y+10
	cp r24,__zero_reg__
	sbci r25,-128
	cpc r26,__zero_reg__
	cpc r27,__zero_reg__
	brlt .L10
	ldi r24,lo8(-1)
	ldi r25,lo8(127)
	ldi r26,0
	ldi r27,0
	std Y+7,r24
	std Y+8,r25
	std Y+9,r26
	std Y+10,r27
	rjmp .L11
.L10:
	ldd r24,Y+7
	ldd r25,Y+8
	ldd r26,Y+9
	ldd r27,Y+10
	cpi r24,1
	sbci r25,-128
	sbci r26,-1
	sbci r27,-1
	brge .L11
	ldi r24,lo8(1)
	ldi r25,lo8(-128)
	ldi r26,lo8(-1)
	ldi r27,lo8(-1)
	std Y+7,r24
	std Y+8,r25
	std Y+9,r26
	std Y+10,r27
.L11:
	ldd r24,Y+7
	ldd r25,Y+8
/* epilogue start */
	adiw r28,24
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
	.size	pid_Controller_c, .-pid_Controller_c
.global	pid_Controller_asm
	.type	pid_Controller_asm, @function
pid_Controller_asm:
	push r16
	push r17
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,18
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 18 */
/* stack size = 22 */
.L__stack_usage = 22
	std Y+14,r25
	std Y+13,r24
	std Y+16,r23
	std Y+15,r22
	std Y+18,r21
	std Y+17,r20
	std Y+1,__zero_reg__
	ldi r24,lo8(49)
	std Y+2,r24
	ldd r24,Y+17
	ldd r25,Y+18
	mov r30,r24
	mov r31,r25
	ldd r18,Z+2
	ldd r19,Z+3
	ldd r20,Z+4
	ldd r21,Z+5
	ldd r22,Y+13
	ldd r23,Y+14
	ldd r24,Y+15
	ldd r25,Y+16
	mov r16,r22
	mov r17,r23
	sub r16,r24
	sbc r17,r25
	mov r24,r16
	mov r25,r17
	mov __tmp_reg__,r25
	lsl r0
	sbc r26,r26
	sbc r27,r27
	add r24,r18
	adc r25,r19
	adc r26,r20
	adc r27,r21
	ldd r18,Y+17
	ldd r19,Y+18
	mov r30,r18
	mov r31,r19
	std Z+2,r24
	std Z+3,r25
	std Z+4,r26
	std Z+5,r27
	ldd r24,Y+13
	ldd r25,Y+14
	mov r24,r25
	lsl r25
	sbc r25,r25
	std Y+3,r24
	ldd r24,Y+13
	andi r24,lo8(-128)
	std Y+4,r24
	ldd r18,Y+13
	ldd r19,Y+14
	ldd r24,Y+15
	ldd r25,Y+16
	mov r16,r18
	mov r17,r19
	sub r16,r24
	sbc r17,r25
	mov r24,r16
	mov r25,r17
	mov r24,r25
	lsl r25
	sbc r25,r25
	std Y+5,r24
	ldd r25,Y+13
	ldd r24,Y+15
	mov r17,r25
	sub r17,r24
	mov r24,r17
	andi r24,lo8(-128)
	std Y+6,r24
	ldd r24,Y+17
	ldd r25,Y+18
	mov r30,r24
	mov r31,r25
	ld r18,Z
	ldd r19,Z+1
	ldd r24,Y+15
	ldd r25,Y+16
	mov r16,r18
	mov r17,r19
	sub r16,r24
	sbc r17,r25
	mov r24,r16
	mov r25,r17
	mov r24,r25
	lsl r25
	sbc r25,r25
	std Y+7,r24
	ldd r24,Y+17
	ldd r25,Y+18
	mov r30,r24
	mov r31,r25
	ld r24,Z
	ldd r25,Z+1
	mov r25,r24
	ldd r24,Y+15
	mov r31,r25
	sub r31,r24
	mov r24,r31
	andi r24,lo8(-128)
	std Y+8,r24
	ldd r24,Y+17
	ldd r25,Y+18
	mov r30,r24
	mov r31,r25
	ldd r24,Z+2
	ldd r25,Z+3
	ldd r26,Z+4
	ldd r27,Z+5
	mov r24,r25
	mov r25,r26
	mov r26,r27
	clr r27
	sbrc r26,7
	dec r27
	std Y+9,r24
	ldd r24,Y+17
	ldd r25,Y+18
	mov r30,r24
	mov r31,r25
	ldd r24,Z+2
	ldd r25,Z+3
	ldd r26,Z+4
	ldd r27,Z+5
	andi r24,lo8(-128)
	std Y+10,r24
	ldd r24,Y+17
	ldd r25,Y+18
	ldd r18,Y+15
	ldd r19,Y+16
	mov r30,r24
	mov r31,r25
	std Z+1,r19
	st Z,r18
	ldd r24,Y+3
	ldd r25,Y+4
	ldd r18,Y+5
	ldd r19,Y+6
	ldd r20,Y+7
	ldd r21,Y+8
	ldd r22,Y+9
	ldd r23,Y+10
	mov r16,r24
	mov r17,r25
/* #APP */
 ;  117 "pid.c" 1
	.equ temp1, 0x10
	.equ temp2, 0x11
	.equ temp3, 0x12
	.equ errorH, 0x13
	.equ errorL, 0x14
	push temp1
	push temp2
	push temp3
	mov temp1, r19
	mulsu temp1, 1
	mov temp1, R1
	mov pidL, R0
	mov temp2, r18
	mulsu temp2, 1
	mov temp2, R1
	add temp1, temp2
	mov pidH, temp1
	mov temp1, r21
	mulsu temp1, 0
	mov temp1, R1
	add pidL, R0
	mov temp2, r20
	mulsu temp2, 0
	mov temp2, R1
	add temp1, temp2
	add pidH, temp1
	mov temp2, R1
	add temp1, temp2
	add pidH, temp1
	pop temp3
	pop temp2
	pop temp1
	
 ;  0 "" 2
/* #NOAPP */
	mov r24,r17
	mov r25,r16
	std Y+11,r25
	std Y+12,r24
	ldd r24,Y+11
	mov __tmp_reg__,r24
	lsl r0
	sbc r25,r25
	mov r25,r24
	clr r24
	std Y+1,r24
	ldd r25,Y+1
	ldd r24,Y+12
	or r24,r25
	std Y+1,r24
	ldd r24,Y+1
	mov __tmp_reg__,r24
	lsl r0
	sbc r25,r25
/* epilogue start */
	adiw r28,18
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	pop r17
	pop r16
	ret
	.size	pid_Controller_asm, .-pid_Controller_asm
.global	pid_Reset_Integrator
	.type	pid_Reset_Integrator, @function
pid_Reset_Integrator:
	push r28
	push r29
	rcall .
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 2 */
/* stack size = 4 */
.L__stack_usage = 4
	std Y+2,r25
	std Y+1,r24
	ldd r24,Y+1
	ldd r25,Y+2
	mov r30,r24
	mov r31,r25
	std Z+2,__zero_reg__
	std Z+3,__zero_reg__
	std Z+4,__zero_reg__
	std Z+5,__zero_reg__
	nop
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.size	pid_Reset_Integrator, .-pid_Reset_Integrator
	.ident	"GCC: (GNU) 6.3.0"
