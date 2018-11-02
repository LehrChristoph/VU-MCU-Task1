
wiimotedemo.elf:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
       0:	0c 94 72 00 	jmp	0xe4	; 0xe4 <__ctors_end>
       4:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
       8:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
       c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      10:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      14:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      18:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      1c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      20:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      24:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      28:	0c 94 0e 08 	jmp	0x101c	; 0x101c <__vector_10>
      2c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      30:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      34:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      38:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      3c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      40:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      44:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      48:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      4c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      50:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      54:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      58:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      5c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      60:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      64:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      68:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      6c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      70:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      74:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      78:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      7c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      80:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      84:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      88:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      8c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      90:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      94:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      98:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      9c:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      a0:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      a4:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      a8:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      ac:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      b0:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      b4:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      b8:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      bc:	0c 94 cd 07 	jmp	0xf9a	; 0xf9a <__vector_47>
      c0:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      c4:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      c8:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      cc:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      d0:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      d4:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      d8:	0c 94 82 08 	jmp	0x1104	; 0x1104 <__vector_54>
      dc:	0c 94 91 00 	jmp	0x122	; 0x122 <__bad_interrupt>
      e0:	0c 94 41 08 	jmp	0x1082	; 0x1082 <__vector_56>

000000e4 <__ctors_end>:
      e4:	11 24       	eor	r1, r1
      e6:	1f be       	out	0x3f, r1	; 63
      e8:	cf ef       	ldi	r28, 0xFF	; 255
      ea:	d1 e2       	ldi	r29, 0x21	; 33
      ec:	de bf       	out	0x3e, r29	; 62
      ee:	cd bf       	out	0x3d, r28	; 61

000000f0 <__do_copy_data>:
      f0:	12 e0       	ldi	r17, 0x02	; 2
      f2:	a0 e0       	ldi	r26, 0x00	; 0
      f4:	b2 e0       	ldi	r27, 0x02	; 2
      f6:	ea e0       	ldi	r30, 0x0A	; 10
      f8:	f2 e1       	ldi	r31, 0x12	; 18
      fa:	00 e0       	ldi	r16, 0x00	; 0
      fc:	0b bf       	out	0x3b, r16	; 59
      fe:	02 c0       	rjmp	.+4      	; 0x104 <__do_copy_data+0x14>
     100:	07 90       	elpm	r0, Z+
     102:	0d 92       	st	X+, r0
     104:	a2 35       	cpi	r26, 0x52	; 82
     106:	b1 07       	cpc	r27, r17
     108:	d9 f7       	brne	.-10     	; 0x100 <__do_copy_data+0x10>

0000010a <__do_clear_bss>:
     10a:	22 e0       	ldi	r18, 0x02	; 2
     10c:	a2 e5       	ldi	r26, 0x52	; 82
     10e:	b2 e0       	ldi	r27, 0x02	; 2
     110:	01 c0       	rjmp	.+2      	; 0x114 <.do_clear_bss_start>

00000112 <.do_clear_bss_loop>:
     112:	1d 92       	st	X+, r1

00000114 <.do_clear_bss_start>:
     114:	ab 3b       	cpi	r26, 0xBB	; 187
     116:	b2 07       	cpc	r27, r18
     118:	e1 f7       	brne	.-8      	; 0x112 <.do_clear_bss_loop>
     11a:	0e 94 01 01 	call	0x202	; 0x202 <main>
     11e:	0c 94 03 09 	jmp	0x1206	; 0x1206 <_exit>

00000122 <__bad_interrupt>:
     122:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000126 <rcvAccel>:
     126:	40 34       	cpi	r20, 0x40	; 64
     128:	24 f4       	brge	.+8      	; 0x132 <rcvAccel+0xc>
     12a:	40 3c       	cpi	r20, 0xC0	; 192
     12c:	24 f0       	brlt	.+8      	; 0x136 <rcvAccel+0x10>
     12e:	44 0f       	add	r20, r20
     130:	03 c0       	rjmp	.+6      	; 0x138 <rcvAccel+0x12>
     132:	4f e7       	ldi	r20, 0x7F	; 127
     134:	01 c0       	rjmp	.+2      	; 0x138 <rcvAccel+0x12>
     136:	40 e8       	ldi	r20, 0x80	; 128
     138:	40 58       	subi	r20, 0x80	; 128
     13a:	42 95       	swap	r20
     13c:	46 95       	lsr	r20
     13e:	47 70       	andi	r20, 0x07	; 7
     140:	21 e0       	ldi	r18, 0x01	; 1
     142:	30 e0       	ldi	r19, 0x00	; 0
     144:	02 c0       	rjmp	.+4      	; 0x14a <rcvAccel+0x24>
     146:	22 0f       	add	r18, r18
     148:	33 1f       	adc	r19, r19
     14a:	4a 95       	dec	r20
     14c:	e2 f7       	brpl	.-8      	; 0x146 <rcvAccel+0x20>
     14e:	88 23       	and	r24, r24
     150:	11 f4       	brne	.+4      	; 0x156 <rcvAccel+0x30>
     152:	22 b9       	out	0x02, r18	; 2
     154:	08 95       	ret
     156:	81 30       	cpi	r24, 0x01	; 1
     158:	11 f4       	brne	.+4      	; 0x15e <rcvAccel+0x38>
     15a:	25 b9       	out	0x05, r18	; 5
     15c:	08 95       	ret
     15e:	82 30       	cpi	r24, 0x02	; 2
     160:	11 f4       	brne	.+4      	; 0x166 <rcvAccel+0x40>
     162:	28 b9       	out	0x08, r18	; 8
     164:	08 95       	ret
     166:	83 30       	cpi	r24, 0x03	; 3
     168:	09 f4       	brne	.+2      	; 0x16c <rcvAccel+0x46>
     16a:	2b b9       	out	0x0b, r18	; 11
     16c:	08 95       	ret

0000016e <conCallback>:
     16e:	28 2f       	mov	r18, r24
     170:	30 e0       	ldi	r19, 0x00	; 0
     172:	66 23       	and	r22, r22
     174:	99 f0       	breq	.+38     	; 0x19c <conCallback+0x2e>
     176:	f9 01       	movw	r30, r18
     178:	ee 5a       	subi	r30, 0xAE	; 174
     17a:	fd 4f       	sbci	r31, 0xFD	; 253
     17c:	91 e0       	ldi	r25, 0x01	; 1
     17e:	90 83       	st	Z, r25
     180:	23 70       	andi	r18, 0x03	; 3
     182:	30 70       	andi	r19, 0x00	; 0
     184:	61 e0       	ldi	r22, 0x01	; 1
     186:	70 e0       	ldi	r23, 0x00	; 0
     188:	02 c0       	rjmp	.+4      	; 0x18e <conCallback+0x20>
     18a:	66 0f       	add	r22, r22
     18c:	77 1f       	adc	r23, r23
     18e:	2a 95       	dec	r18
     190:	e2 f7       	brpl	.-8      	; 0x18a <conCallback+0x1c>
     192:	4b ef       	ldi	r20, 0xFB	; 251
     194:	50 e0       	ldi	r21, 0x00	; 0
     196:	0e 94 b8 01 	call	0x370	; 0x370 <wiiUserSetLeds>
     19a:	04 c0       	rjmp	.+8      	; 0x1a4 <conCallback+0x36>
     19c:	2e 5a       	subi	r18, 0xAE	; 174
     19e:	3d 4f       	sbci	r19, 0xFD	; 253
     1a0:	f9 01       	movw	r30, r18
     1a2:	10 82       	st	Z, r1
     1a4:	90 91 53 02 	lds	r25, 0x0253	; 0x800253 <_wii.1211>
     1a8:	80 91 52 02 	lds	r24, 0x0252	; 0x800252 <__data_end>
     1ac:	88 23       	and	r24, r24
     1ae:	19 f0       	breq	.+6      	; 0x1b6 <conCallback+0x48>
     1b0:	99 23       	and	r25, r25
     1b2:	f1 f7       	brne	.-4      	; 0x1b0 <conCallback+0x42>
     1b4:	08 95       	ret
     1b6:	10 92 53 02 	sts	0x0253, r1	; 0x800253 <_wii.1211>
     1ba:	80 e0       	ldi	r24, 0x00	; 0
     1bc:	6b e4       	ldi	r22, 0x4B	; 75
     1be:	72 e0       	ldi	r23, 0x02	; 2
     1c0:	47 eb       	ldi	r20, 0xB7	; 183
     1c2:	50 e0       	ldi	r21, 0x00	; 0
     1c4:	0e 94 b5 01 	call	0x36a	; 0x36a <wiiUserConnect>
     1c8:	08 95       	ret

000001ca <rcvButton>:
     1ca:	0f 93       	push	r16
     1cc:	1f 93       	push	r17
     1ce:	18 2f       	mov	r17, r24
     1d0:	06 2f       	mov	r16, r22
     1d2:	63 ff       	sbrs	r22, 3
     1d4:	05 c0       	rjmp	.+10     	; 0x1e0 <rcvButton+0x16>
     1d6:	61 e0       	ldi	r22, 0x01	; 1
     1d8:	40 e0       	ldi	r20, 0x00	; 0
     1da:	50 e0       	ldi	r21, 0x00	; 0
     1dc:	0e 94 20 02 	call	0x440	; 0x440 <wiiUserSetRumbler>
     1e0:	02 ff       	sbrs	r16, 2
     1e2:	06 c0       	rjmp	.+12     	; 0x1f0 <rcvButton+0x26>
     1e4:	81 2f       	mov	r24, r17
     1e6:	60 e0       	ldi	r22, 0x00	; 0
     1e8:	40 e0       	ldi	r20, 0x00	; 0
     1ea:	50 e0       	ldi	r21, 0x00	; 0
     1ec:	0e 94 20 02 	call	0x440	; 0x440 <wiiUserSetRumbler>
     1f0:	1f 91       	pop	r17
     1f2:	0f 91       	pop	r16
     1f4:	08 95       	ret

000001f6 <setLedsCallback>:
     1f6:	61 e0       	ldi	r22, 0x01	; 1
     1f8:	40 e0       	ldi	r20, 0x00	; 0
     1fa:	50 e0       	ldi	r21, 0x00	; 0
     1fc:	0e 94 ee 01 	call	0x3dc	; 0x3dc <wiiUserSetAccel>
     200:	08 95       	ret

00000202 <main>:
     202:	85 ee       	ldi	r24, 0xE5	; 229
     204:	90 e0       	ldi	r25, 0x00	; 0
     206:	63 e9       	ldi	r22, 0x93	; 147
     208:	70 e0       	ldi	r23, 0x00	; 0
     20a:	0e 94 9a 01 	call	0x334	; 0x334 <wiiUserInit>
     20e:	80 e0       	ldi	r24, 0x00	; 0
     210:	60 e0       	ldi	r22, 0x00	; 0
     212:	0e 94 b7 00 	call	0x16e	; 0x16e <conCallback>
     216:	8f ef       	ldi	r24, 0xFF	; 255
     218:	81 b9       	out	0x01, r24	; 1
     21a:	84 b9       	out	0x04, r24	; 4
     21c:	87 b9       	out	0x07, r24	; 7
     21e:	8a b9       	out	0x0a, r24	; 10
     220:	ff cf       	rjmp	.-2      	; 0x220 <main+0x1e>

00000222 <sndCallback>:
     222:	28 2f       	mov	r18, r24
     224:	30 e0       	ldi	r19, 0x00	; 0
     226:	f9 01       	movw	r30, r18
     228:	ec 5a       	subi	r30, 0xAC	; 172
     22a:	fd 4f       	sbci	r31, 0xFD	; 253
     22c:	90 81       	ld	r25, Z
     22e:	10 82       	st	Z, r1
     230:	91 30       	cpi	r25, 0x01	; 1
     232:	11 f0       	breq	.+4      	; 0x238 <sndCallback+0x16>
     234:	92 30       	cpi	r25, 0x02	; 2
     236:	69 f4       	brne	.+26     	; 0x252 <sndCallback+0x30>
     238:	f9 01       	movw	r30, r18
     23a:	ee 0f       	add	r30, r30
     23c:	ff 1f       	adc	r31, r31
     23e:	eb 5a       	subi	r30, 0xAB	; 171
     240:	fd 4f       	sbci	r31, 0xFD	; 253
     242:	01 90       	ld	r0, Z+
     244:	f0 81       	ld	r31, Z
     246:	e0 2d       	mov	r30, r0
     248:	30 97       	sbiw	r30, 0x00	; 0
     24a:	89 f0       	breq	.+34     	; 0x26e <sndCallback+0x4c>
     24c:	60 e0       	ldi	r22, 0x00	; 0
     24e:	09 95       	icall
     250:	08 95       	ret
     252:	93 30       	cpi	r25, 0x03	; 3
     254:	61 f4       	brne	.+24     	; 0x26e <sndCallback+0x4c>
     256:	f9 01       	movw	r30, r18
     258:	ee 0f       	add	r30, r30
     25a:	ff 1f       	adc	r31, r31
     25c:	eb 5a       	subi	r30, 0xAB	; 171
     25e:	fd 4f       	sbci	r31, 0xFD	; 253
     260:	01 90       	ld	r0, Z+
     262:	f0 81       	ld	r31, Z
     264:	e0 2d       	mov	r30, r0
     266:	30 97       	sbiw	r30, 0x00	; 0
     268:	11 f0       	breq	.+4      	; 0x26e <sndCallback+0x4c>
     26a:	60 e0       	ldi	r22, 0x00	; 0
     26c:	09 95       	icall
     26e:	08 95       	ret

00000270 <rcvCallback>:
     270:	1f 93       	push	r17
     272:	cf 93       	push	r28
     274:	df 93       	push	r29
     276:	18 2f       	mov	r17, r24
     278:	ea 01       	movw	r28, r20
     27a:	62 30       	cpi	r22, 0x02	; 2
     27c:	08 f4       	brcc	.+2      	; 0x280 <rcvCallback+0x10>
     27e:	56 c0       	rjmp	.+172    	; 0x32c <rcvCallback+0xbc>
     280:	89 81       	ldd	r24, Y+1	; 0x01
     282:	81 33       	cpi	r24, 0x31	; 49
     284:	c9 f5       	brne	.+114    	; 0x2f8 <rcvCallback+0x88>
     286:	67 30       	cpi	r22, 0x07	; 7
     288:	d9 f5       	brne	.+118    	; 0x300 <rcvCallback+0x90>
     28a:	e0 91 5b 02 	lds	r30, 0x025B	; 0x80025b <_rcvAccel>
     28e:	f0 91 5c 02 	lds	r31, 0x025C	; 0x80025c <_rcvAccel+0x1>
     292:	30 97       	sbiw	r30, 0x00	; 0
     294:	b9 f1       	breq	.+110    	; 0x304 <rcvCallback+0x94>
     296:	2b 81       	ldd	r18, Y+3	; 0x03
     298:	30 e0       	ldi	r19, 0x00	; 0
     29a:	6a 81       	ldd	r22, Y+2	; 0x02
     29c:	70 e0       	ldi	r23, 0x00	; 0
     29e:	60 76       	andi	r22, 0x60	; 96
     2a0:	70 70       	andi	r23, 0x00	; 0
     2a2:	55 e0       	ldi	r21, 0x05	; 5
     2a4:	75 95       	asr	r23
     2a6:	67 95       	ror	r22
     2a8:	5a 95       	dec	r21
     2aa:	e1 f7       	brne	.-8      	; 0x2a4 <rcvCallback+0x34>
     2ac:	8c 81       	ldd	r24, Y+4	; 0x04
     2ae:	90 e0       	ldi	r25, 0x00	; 0
     2b0:	88 0f       	add	r24, r24
     2b2:	99 1f       	adc	r25, r25
     2b4:	88 0f       	add	r24, r24
     2b6:	99 1f       	adc	r25, r25
     2b8:	68 2b       	or	r22, r24
     2ba:	79 2b       	or	r23, r25
     2bc:	a9 01       	movw	r20, r18
     2be:	40 72       	andi	r20, 0x20	; 32
     2c0:	50 70       	andi	r21, 0x00	; 0
     2c2:	b5 e0       	ldi	r27, 0x05	; 5
     2c4:	55 95       	asr	r21
     2c6:	47 95       	ror	r20
     2c8:	ba 95       	dec	r27
     2ca:	e1 f7       	brne	.-8      	; 0x2c4 <rcvCallback+0x54>
     2cc:	8d 81       	ldd	r24, Y+5	; 0x05
     2ce:	90 e0       	ldi	r25, 0x00	; 0
     2d0:	88 0f       	add	r24, r24
     2d2:	99 1f       	adc	r25, r25
     2d4:	48 2b       	or	r20, r24
     2d6:	59 2b       	or	r21, r25
     2d8:	20 74       	andi	r18, 0x40	; 64
     2da:	30 70       	andi	r19, 0x00	; 0
     2dc:	b6 e0       	ldi	r27, 0x06	; 6
     2de:	35 95       	asr	r19
     2e0:	27 95       	ror	r18
     2e2:	ba 95       	dec	r27
     2e4:	e1 f7       	brne	.-8      	; 0x2de <rcvCallback+0x6e>
     2e6:	8e 81       	ldd	r24, Y+6	; 0x06
     2e8:	90 e0       	ldi	r25, 0x00	; 0
     2ea:	88 0f       	add	r24, r24
     2ec:	99 1f       	adc	r25, r25
     2ee:	28 2b       	or	r18, r24
     2f0:	39 2b       	or	r19, r25
     2f2:	81 2f       	mov	r24, r17
     2f4:	09 95       	icall
     2f6:	06 c0       	rjmp	.+12     	; 0x304 <rcvCallback+0x94>
     2f8:	80 33       	cpi	r24, 0x30	; 48
     2fa:	c1 f4       	brne	.+48     	; 0x32c <rcvCallback+0xbc>
     2fc:	64 30       	cpi	r22, 0x04	; 4
     2fe:	11 f0       	breq	.+4      	; 0x304 <rcvCallback+0x94>
     300:	0e 94 fe 08 	call	0x11fc	; 0x11fc <abort>
     304:	e0 91 59 02 	lds	r30, 0x0259	; 0x800259 <_rcvButton>
     308:	f0 91 5a 02 	lds	r31, 0x025A	; 0x80025a <_rcvButton+0x1>
     30c:	30 97       	sbiw	r30, 0x00	; 0
     30e:	71 f0       	breq	.+28     	; 0x32c <rcvCallback+0xbc>
     310:	6a 81       	ldd	r22, Y+2	; 0x02
     312:	70 e0       	ldi	r23, 0x00	; 0
     314:	6f 71       	andi	r22, 0x1F	; 31
     316:	70 70       	andi	r23, 0x00	; 0
     318:	76 2f       	mov	r23, r22
     31a:	66 27       	eor	r22, r22
     31c:	8b 81       	ldd	r24, Y+3	; 0x03
     31e:	90 e0       	ldi	r25, 0x00	; 0
     320:	8f 79       	andi	r24, 0x9F	; 159
     322:	90 70       	andi	r25, 0x00	; 0
     324:	68 2b       	or	r22, r24
     326:	79 2b       	or	r23, r25
     328:	81 2f       	mov	r24, r17
     32a:	09 95       	icall
     32c:	df 91       	pop	r29
     32e:	cf 91       	pop	r28
     330:	1f 91       	pop	r17
     332:	08 95       	ret

00000334 <wiiUserInit>:
     334:	f8 94       	cli
     336:	20 91 5d 02 	lds	r18, 0x025D	; 0x80025d <_init.1370>
     33a:	22 23       	and	r18, r18
     33c:	19 f0       	breq	.+6      	; 0x344 <wiiUserInit+0x10>
     33e:	78 94       	sei
     340:	81 e0       	ldi	r24, 0x01	; 1
     342:	08 95       	ret
     344:	21 e0       	ldi	r18, 0x01	; 1
     346:	20 93 5d 02 	sts	0x025D, r18	; 0x80025d <_init.1370>
     34a:	78 94       	sei
     34c:	90 93 5a 02 	sts	0x025A, r25	; 0x80025a <_rcvButton+0x1>
     350:	80 93 59 02 	sts	0x0259, r24	; 0x800259 <_rcvButton>
     354:	70 93 5c 02 	sts	0x025C, r23	; 0x80025c <_rcvAccel+0x1>
     358:	60 93 5b 02 	sts	0x025B, r22	; 0x80025b <_rcvAccel>
     35c:	81 e1       	ldi	r24, 0x11	; 17
     35e:	91 e0       	ldi	r25, 0x01	; 1
     360:	68 e3       	ldi	r22, 0x38	; 56
     362:	71 e0       	ldi	r23, 0x01	; 1
     364:	0e 94 e1 02 	call	0x5c2	; 0x5c2 <wiiBtInit>
     368:	08 95       	ret

0000036a <wiiUserConnect>:
     36a:	0e 94 f8 02 	call	0x5f0	; 0x5f0 <wiiBtConnect>
     36e:	08 95       	ret

00000370 <wiiUserSetLeds>:
     370:	df 93       	push	r29
     372:	cf 93       	push	r28
     374:	00 d0       	rcall	.+0      	; 0x376 <wiiUserSetLeds+0x6>
     376:	0f 92       	push	r0
     378:	cd b7       	in	r28, 0x3d	; 61
     37a:	de b7       	in	r29, 0x3e	; 62
     37c:	88 23       	and	r24, r24
     37e:	39 f5       	brne	.+78     	; 0x3ce <wiiUserSetLeds+0x5e>
     380:	f8 94       	cli
     382:	80 91 54 02 	lds	r24, 0x0254	; 0x800254 <_state>
     386:	88 23       	and	r24, r24
     388:	11 f0       	breq	.+4      	; 0x38e <wiiUserSetLeds+0x1e>
     38a:	78 94       	sei
     38c:	20 c0       	rjmp	.+64     	; 0x3ce <wiiUserSetLeds+0x5e>
     38e:	71 e0       	ldi	r23, 0x01	; 1
     390:	70 93 54 02 	sts	0x0254, r23	; 0x800254 <_state>
     394:	78 94       	sei
     396:	62 95       	swap	r22
     398:	60 7f       	andi	r22, 0xF0	; 240
     39a:	60 93 58 02 	sts	0x0258, r22	; 0x800258 <_leds>
     39e:	50 93 56 02 	sts	0x0256, r21	; 0x800256 <_union+0x1>
     3a2:	40 93 55 02 	sts	0x0255, r20	; 0x800255 <_union>
     3a6:	20 91 57 02 	lds	r18, 0x0257	; 0x800257 <_rumbler>
     3aa:	26 2b       	or	r18, r22
     3ac:	32 ea       	ldi	r19, 0xA2	; 162
     3ae:	39 83       	std	Y+1, r19	; 0x01
     3b0:	91 e1       	ldi	r25, 0x11	; 17
     3b2:	9a 83       	std	Y+2, r25	; 0x02
     3b4:	2b 83       	std	Y+3, r18	; 0x03
     3b6:	80 e0       	ldi	r24, 0x00	; 0
     3b8:	63 e0       	ldi	r22, 0x03	; 3
     3ba:	ae 01       	movw	r20, r28
     3bc:	4f 5f       	subi	r20, 0xFF	; 255
     3be:	5f 4f       	sbci	r21, 0xFF	; 255
     3c0:	0e 94 3d 03 	call	0x67a	; 0x67a <wiiBtSendRaw>
     3c4:	88 23       	and	r24, r24
     3c6:	21 f0       	breq	.+8      	; 0x3d0 <wiiUserSetLeds+0x60>
     3c8:	10 92 54 02 	sts	0x0254, r1	; 0x800254 <_state>
     3cc:	01 c0       	rjmp	.+2      	; 0x3d0 <wiiUserSetLeds+0x60>
     3ce:	81 e0       	ldi	r24, 0x01	; 1
     3d0:	0f 90       	pop	r0
     3d2:	0f 90       	pop	r0
     3d4:	0f 90       	pop	r0
     3d6:	cf 91       	pop	r28
     3d8:	df 91       	pop	r29
     3da:	08 95       	ret

000003dc <wiiUserSetAccel>:
     3dc:	df 93       	push	r29
     3de:	cf 93       	push	r28
     3e0:	00 d0       	rcall	.+0      	; 0x3e2 <wiiUserSetAccel+0x6>
     3e2:	00 d0       	rcall	.+0      	; 0x3e4 <wiiUserSetAccel+0x8>
     3e4:	cd b7       	in	r28, 0x3d	; 61
     3e6:	de b7       	in	r29, 0x3e	; 62
     3e8:	88 23       	and	r24, r24
     3ea:	11 f5       	brne	.+68     	; 0x430 <__LOCK_REGION_LENGTH__+0x30>
     3ec:	f8 94       	cli
     3ee:	80 91 54 02 	lds	r24, 0x0254	; 0x800254 <_state>
     3f2:	88 23       	and	r24, r24
     3f4:	11 f0       	breq	.+4      	; 0x3fa <wiiUserSetAccel+0x1e>
     3f6:	78 94       	sei
     3f8:	1b c0       	rjmp	.+54     	; 0x430 <__LOCK_REGION_LENGTH__+0x30>
     3fa:	72 e0       	ldi	r23, 0x02	; 2
     3fc:	70 93 54 02 	sts	0x0254, r23	; 0x800254 <_state>
     400:	78 94       	sei
     402:	50 93 56 02 	sts	0x0256, r21	; 0x800256 <_union+0x1>
     406:	40 93 55 02 	sts	0x0255, r20	; 0x800255 <_union>
     40a:	62 ea       	ldi	r22, 0xA2	; 162
     40c:	69 83       	std	Y+1, r22	; 0x01
     40e:	32 e1       	ldi	r19, 0x12	; 18
     410:	3a 83       	std	Y+2, r19	; 0x02
     412:	1b 82       	std	Y+3, r1	; 0x03
     414:	21 e3       	ldi	r18, 0x31	; 49
     416:	2c 83       	std	Y+4, r18	; 0x04
     418:	80 e0       	ldi	r24, 0x00	; 0
     41a:	64 e0       	ldi	r22, 0x04	; 4
     41c:	ae 01       	movw	r20, r28
     41e:	4f 5f       	subi	r20, 0xFF	; 255
     420:	5f 4f       	sbci	r21, 0xFF	; 255
     422:	0e 94 3d 03 	call	0x67a	; 0x67a <wiiBtSendRaw>
     426:	88 23       	and	r24, r24
     428:	21 f0       	breq	.+8      	; 0x432 <__LOCK_REGION_LENGTH__+0x32>
     42a:	10 92 54 02 	sts	0x0254, r1	; 0x800254 <_state>
     42e:	01 c0       	rjmp	.+2      	; 0x432 <__LOCK_REGION_LENGTH__+0x32>
     430:	81 e0       	ldi	r24, 0x01	; 1
     432:	0f 90       	pop	r0
     434:	0f 90       	pop	r0
     436:	0f 90       	pop	r0
     438:	0f 90       	pop	r0
     43a:	cf 91       	pop	r28
     43c:	df 91       	pop	r29
     43e:	08 95       	ret

00000440 <wiiUserSetRumbler>:
     440:	df 93       	push	r29
     442:	cf 93       	push	r28
     444:	00 d0       	rcall	.+0      	; 0x446 <wiiUserSetRumbler+0x6>
     446:	0f 92       	push	r0
     448:	cd b7       	in	r28, 0x3d	; 61
     44a:	de b7       	in	r29, 0x3e	; 62
     44c:	88 23       	and	r24, r24
     44e:	49 f5       	brne	.+82     	; 0x4a2 <wiiUserSetRumbler+0x62>
     450:	f8 94       	cli
     452:	80 91 54 02 	lds	r24, 0x0254	; 0x800254 <_state>
     456:	88 23       	and	r24, r24
     458:	11 f0       	breq	.+4      	; 0x45e <wiiUserSetRumbler+0x1e>
     45a:	78 94       	sei
     45c:	22 c0       	rjmp	.+68     	; 0x4a2 <wiiUserSetRumbler+0x62>
     45e:	23 e0       	ldi	r18, 0x03	; 3
     460:	20 93 54 02 	sts	0x0254, r18	; 0x800254 <_state>
     464:	78 94       	sei
     466:	50 93 56 02 	sts	0x0256, r21	; 0x800256 <_union+0x1>
     46a:	40 93 55 02 	sts	0x0255, r20	; 0x800255 <_union>
     46e:	91 e0       	ldi	r25, 0x01	; 1
     470:	66 23       	and	r22, r22
     472:	09 f4       	brne	.+2      	; 0x476 <wiiUserSetRumbler+0x36>
     474:	90 e0       	ldi	r25, 0x00	; 0
     476:	90 93 57 02 	sts	0x0257, r25	; 0x800257 <_rumbler>
     47a:	30 91 58 02 	lds	r19, 0x0258	; 0x800258 <_leds>
     47e:	39 2b       	or	r19, r25
     480:	42 ea       	ldi	r20, 0xA2	; 162
     482:	49 83       	std	Y+1, r20	; 0x01
     484:	91 e1       	ldi	r25, 0x11	; 17
     486:	9a 83       	std	Y+2, r25	; 0x02
     488:	3b 83       	std	Y+3, r19	; 0x03
     48a:	80 e0       	ldi	r24, 0x00	; 0
     48c:	63 e0       	ldi	r22, 0x03	; 3
     48e:	ae 01       	movw	r20, r28
     490:	4f 5f       	subi	r20, 0xFF	; 255
     492:	5f 4f       	sbci	r21, 0xFF	; 255
     494:	0e 94 3d 03 	call	0x67a	; 0x67a <wiiBtSendRaw>
     498:	88 23       	and	r24, r24
     49a:	21 f0       	breq	.+8      	; 0x4a4 <wiiUserSetRumbler+0x64>
     49c:	10 92 54 02 	sts	0x0254, r1	; 0x800254 <_state>
     4a0:	01 c0       	rjmp	.+2      	; 0x4a4 <wiiUserSetRumbler+0x64>
     4a2:	81 e0       	ldi	r24, 0x01	; 1
     4a4:	0f 90       	pop	r0
     4a6:	0f 90       	pop	r0
     4a8:	0f 90       	pop	r0
     4aa:	cf 91       	pop	r28
     4ac:	df 91       	pop	r29
     4ae:	08 95       	ret

000004b0 <transmit_connection_request>:
     4b0:	df 93       	push	r29
     4b2:	cf 93       	push	r28
     4b4:	cd b7       	in	r28, 0x3d	; 61
     4b6:	de b7       	in	r29, 0x3e	; 62
     4b8:	2c 97       	sbiw	r28, 0x0c	; 12
     4ba:	0f b6       	in	r0, 0x3f	; 63
     4bc:	f8 94       	cli
     4be:	de bf       	out	0x3e, r29	; 62
     4c0:	0f be       	out	0x3f, r0	; 63
     4c2:	cd bf       	out	0x3d, r28	; 61
     4c4:	fe 01       	movw	r30, r28
     4c6:	31 96       	adiw	r30, 0x01	; 1
     4c8:	9c e0       	ldi	r25, 0x0C	; 12
     4ca:	df 01       	movw	r26, r30
     4cc:	1d 92       	st	X+, r1
     4ce:	9a 95       	dec	r25
     4d0:	e9 f7       	brne	.-6      	; 0x4cc <transmit_connection_request+0x1c>
     4d2:	98 e0       	ldi	r25, 0x08	; 8
     4d4:	99 83       	std	Y+1, r25	; 0x01
     4d6:	91 e0       	ldi	r25, 0x01	; 1
     4d8:	9b 83       	std	Y+3, r25	; 0x03
     4da:	92 e0       	ldi	r25, 0x02	; 2
     4dc:	9d 83       	std	Y+5, r25	; 0x05
     4de:	94 e0       	ldi	r25, 0x04	; 4
     4e0:	9f 83       	std	Y+7, r25	; 0x07
     4e2:	a8 2f       	mov	r26, r24
     4e4:	b0 e0       	ldi	r27, 0x00	; 0
     4e6:	a2 5a       	subi	r26, 0xA2	; 162
     4e8:	bd 4f       	sbci	r27, 0xFD	; 253
     4ea:	9c 91       	ld	r25, X
     4ec:	9e 83       	std	Y+6, r25	; 0x06
     4ee:	69 87       	std	Y+9, r22	; 0x09
     4f0:	4b 87       	std	Y+11, r20	; 0x0b
     4f2:	6c e0       	ldi	r22, 0x0C	; 12
     4f4:	af 01       	movw	r20, r30
     4f6:	0e 94 48 07 	call	0xe90	; 0xe90 <hci_transmit>
     4fa:	2c 96       	adiw	r28, 0x0c	; 12
     4fc:	0f b6       	in	r0, 0x3f	; 63
     4fe:	f8 94       	cli
     500:	de bf       	out	0x3e, r29	; 62
     502:	0f be       	out	0x3f, r0	; 63
     504:	cd bf       	out	0x3d, r28	; 61
     506:	cf 91       	pop	r28
     508:	df 91       	pop	r29
     50a:	08 95       	ret

0000050c <transmit_configuration_request>:
     50c:	df 93       	push	r29
     50e:	cf 93       	push	r28
     510:	cd b7       	in	r28, 0x3d	; 61
     512:	de b7       	in	r29, 0x3e	; 62
     514:	2c 97       	sbiw	r28, 0x0c	; 12
     516:	0f b6       	in	r0, 0x3f	; 63
     518:	f8 94       	cli
     51a:	de bf       	out	0x3e, r29	; 62
     51c:	0f be       	out	0x3f, r0	; 63
     51e:	cd bf       	out	0x3d, r28	; 61
     520:	ae 01       	movw	r20, r28
     522:	4f 5f       	subi	r20, 0xFF	; 255
     524:	5f 4f       	sbci	r21, 0xFF	; 255
     526:	9c e0       	ldi	r25, 0x0C	; 12
     528:	fa 01       	movw	r30, r20
     52a:	11 92       	st	Z+, r1
     52c:	9a 95       	dec	r25
     52e:	e9 f7       	brne	.-6      	; 0x52a <transmit_configuration_request+0x1e>
     530:	98 e0       	ldi	r25, 0x08	; 8
     532:	99 83       	std	Y+1, r25	; 0x01
     534:	91 e0       	ldi	r25, 0x01	; 1
     536:	9b 83       	std	Y+3, r25	; 0x03
     538:	94 e0       	ldi	r25, 0x04	; 4
     53a:	9d 83       	std	Y+5, r25	; 0x05
     53c:	9f 83       	std	Y+7, r25	; 0x07
     53e:	e8 2f       	mov	r30, r24
     540:	f0 e0       	ldi	r31, 0x00	; 0
     542:	e2 5a       	subi	r30, 0xA2	; 162
     544:	fd 4f       	sbci	r31, 0xFD	; 253
     546:	90 81       	ld	r25, Z
     548:	9e 83       	std	Y+6, r25	; 0x06
     54a:	69 87       	std	Y+9, r22	; 0x09
     54c:	7a 87       	std	Y+10, r23	; 0x0a
     54e:	6c e0       	ldi	r22, 0x0C	; 12
     550:	0e 94 48 07 	call	0xe90	; 0xe90 <hci_transmit>
     554:	2c 96       	adiw	r28, 0x0c	; 12
     556:	0f b6       	in	r0, 0x3f	; 63
     558:	f8 94       	cli
     55a:	de bf       	out	0x3e, r29	; 62
     55c:	0f be       	out	0x3f, r0	; 63
     55e:	cd bf       	out	0x3d, r28	; 61
     560:	cf 91       	pop	r28
     562:	df 91       	pop	r29
     564:	08 95       	ret

00000566 <transmit_configuration_response>:
     566:	df 93       	push	r29
     568:	cf 93       	push	r28
     56a:	cd b7       	in	r28, 0x3d	; 61
     56c:	de b7       	in	r29, 0x3e	; 62
     56e:	2e 97       	sbiw	r28, 0x0e	; 14
     570:	0f b6       	in	r0, 0x3f	; 63
     572:	f8 94       	cli
     574:	de bf       	out	0x3e, r29	; 62
     576:	0f be       	out	0x3f, r0	; 63
     578:	cd bf       	out	0x3d, r28	; 61
     57a:	ae 01       	movw	r20, r28
     57c:	4f 5f       	subi	r20, 0xFF	; 255
     57e:	5f 4f       	sbci	r21, 0xFF	; 255
     580:	9e e0       	ldi	r25, 0x0E	; 14
     582:	fa 01       	movw	r30, r20
     584:	11 92       	st	Z+, r1
     586:	9a 95       	dec	r25
     588:	e9 f7       	brne	.-6      	; 0x584 <transmit_configuration_response+0x1e>
     58a:	9a e0       	ldi	r25, 0x0A	; 10
     58c:	99 83       	std	Y+1, r25	; 0x01
     58e:	91 e0       	ldi	r25, 0x01	; 1
     590:	9b 83       	std	Y+3, r25	; 0x03
     592:	95 e0       	ldi	r25, 0x05	; 5
     594:	9d 83       	std	Y+5, r25	; 0x05
     596:	96 e0       	ldi	r25, 0x06	; 6
     598:	9f 83       	std	Y+7, r25	; 0x07
     59a:	e8 2f       	mov	r30, r24
     59c:	f0 e0       	ldi	r31, 0x00	; 0
     59e:	e1 5a       	subi	r30, 0xA1	; 161
     5a0:	fd 4f       	sbci	r31, 0xFD	; 253
     5a2:	90 81       	ld	r25, Z
     5a4:	9e 83       	std	Y+6, r25	; 0x06
     5a6:	69 87       	std	Y+9, r22	; 0x09
     5a8:	7a 87       	std	Y+10, r23	; 0x0a
     5aa:	6e e0       	ldi	r22, 0x0E	; 14
     5ac:	0e 94 48 07 	call	0xe90	; 0xe90 <hci_transmit>
     5b0:	2e 96       	adiw	r28, 0x0e	; 14
     5b2:	0f b6       	in	r0, 0x3f	; 63
     5b4:	f8 94       	cli
     5b6:	de bf       	out	0x3e, r29	; 62
     5b8:	0f be       	out	0x3f, r0	; 63
     5ba:	cd bf       	out	0x3d, r28	; 61
     5bc:	cf 91       	pop	r28
     5be:	df 91       	pop	r29
     5c0:	08 95       	ret

000005c2 <wiiBtInit>:
     5c2:	f8 94       	cli
     5c4:	20 91 6c 02 	lds	r18, 0x026C	; 0x80026c <_init.1316>
     5c8:	22 23       	and	r18, r18
     5ca:	19 f0       	breq	.+6      	; 0x5d2 <wiiBtInit+0x10>
     5cc:	78 94       	sei
     5ce:	81 e0       	ldi	r24, 0x01	; 1
     5d0:	08 95       	ret
     5d2:	31 e0       	ldi	r19, 0x01	; 1
     5d4:	30 93 6c 02 	sts	0x026C, r19	; 0x80026c <_init.1316>
     5d8:	78 94       	sei
     5da:	90 93 69 02 	sts	0x0269, r25	; 0x800269 <_sndCallback+0x1>
     5de:	80 93 68 02 	sts	0x0268, r24	; 0x800268 <_sndCallback>
     5e2:	70 93 63 02 	sts	0x0263, r23	; 0x800263 <_rcvCallback+0x1>
     5e6:	60 93 62 02 	sts	0x0262, r22	; 0x800262 <_rcvCallback>
     5ea:	0e 94 85 07 	call	0xf0a	; 0xf0a <hci_init>
     5ee:	08 95       	ret

000005f0 <wiiBtConnect>:
     5f0:	88 23       	and	r24, r24
     5f2:	19 f5       	brne	.+70     	; 0x63a <wiiBtConnect+0x4a>
     5f4:	61 15       	cp	r22, r1
     5f6:	71 05       	cpc	r23, r1
     5f8:	11 f1       	breq	.+68     	; 0x63e <wiiBtConnect+0x4e>
     5fa:	f8 94       	cli
     5fc:	80 91 64 02 	lds	r24, 0x0264	; 0x800264 <_control>
     600:	90 91 65 02 	lds	r25, 0x0265	; 0x800265 <_control+0x1>
     604:	00 97       	sbiw	r24, 0x00	; 0
     606:	11 f0       	breq	.+4      	; 0x60c <wiiBtConnect+0x1c>
     608:	78 94       	sei
     60a:	17 c0       	rjmp	.+46     	; 0x63a <wiiBtConnect+0x4a>
     60c:	81 e0       	ldi	r24, 0x01	; 1
     60e:	90 e0       	ldi	r25, 0x00	; 0
     610:	90 93 65 02 	sts	0x0265, r25	; 0x800265 <_control+0x1>
     614:	80 93 64 02 	sts	0x0264, r24	; 0x800264 <_control>
     618:	78 94       	sei
     61a:	50 93 6b 02 	sts	0x026B, r21	; 0x80026b <_conCallback+0x1>
     61e:	40 93 6a 02 	sts	0x026A, r20	; 0x80026a <_conCallback>
     622:	80 e0       	ldi	r24, 0x00	; 0
     624:	0e 94 19 07 	call	0xe32	; 0xe32 <hci_create_connection>
     628:	88 23       	and	r24, r24
     62a:	51 f0       	breq	.+20     	; 0x640 <wiiBtConnect+0x50>
     62c:	f8 94       	cli
     62e:	10 92 65 02 	sts	0x0265, r1	; 0x800265 <_control+0x1>
     632:	10 92 64 02 	sts	0x0264, r1	; 0x800264 <_control>
     636:	78 94       	sei
     638:	08 95       	ret
     63a:	81 e0       	ldi	r24, 0x01	; 1
     63c:	08 95       	ret
     63e:	81 e0       	ldi	r24, 0x01	; 1
     640:	08 95       	ret

00000642 <hci_disconnection_complete>:
     642:	48 2f       	mov	r20, r24
     644:	50 e0       	ldi	r21, 0x00	; 0
     646:	9a 01       	movw	r18, r20
     648:	22 0f       	add	r18, r18
     64a:	33 1f       	adc	r19, r19
     64c:	f9 01       	movw	r30, r18
     64e:	e6 59       	subi	r30, 0x96	; 150
     650:	fd 4f       	sbci	r31, 0xFD	; 253
     652:	01 90       	ld	r0, Z+
     654:	f0 81       	ld	r31, Z
     656:	e0 2d       	mov	r30, r0
     658:	40 5a       	subi	r20, 0xA0	; 160
     65a:	5d 4f       	sbci	r21, 0xFD	; 253
     65c:	da 01       	movw	r26, r20
     65e:	1c 92       	st	X, r1
     660:	f8 94       	cli
     662:	2c 59       	subi	r18, 0x9C	; 156
     664:	3d 4f       	sbci	r19, 0xFD	; 253
     666:	d9 01       	movw	r26, r18
     668:	11 96       	adiw	r26, 0x01	; 1
     66a:	1c 92       	st	X, r1
     66c:	1e 92       	st	-X, r1
     66e:	78 94       	sei
     670:	30 97       	sbiw	r30, 0x00	; 0
     672:	11 f0       	breq	.+4      	; 0x678 <hci_disconnection_complete+0x36>
     674:	60 e0       	ldi	r22, 0x00	; 0
     676:	09 95       	icall
     678:	08 95       	ret

0000067a <wiiBtSendRaw>:
     67a:	0f 93       	push	r16
     67c:	1f 93       	push	r17
     67e:	df 93       	push	r29
     680:	cf 93       	push	r28
     682:	cd b7       	in	r28, 0x3d	; 61
     684:	de b7       	in	r29, 0x3e	; 62
     686:	0d b7       	in	r16, 0x3d	; 61
     688:	1e b7       	in	r17, 0x3e	; 62
     68a:	88 23       	and	r24, r24
     68c:	c9 f5       	brne	.+114    	; 0x700 <wiiBtSendRaw+0x86>
     68e:	68 31       	cpi	r22, 0x18	; 24
     690:	b8 f5       	brcc	.+110    	; 0x700 <wiiBtSendRaw+0x86>
     692:	41 15       	cp	r20, r1
     694:	51 05       	cpc	r21, r1
     696:	a1 f1       	breq	.+104    	; 0x700 <wiiBtSendRaw+0x86>
     698:	80 91 60 02 	lds	r24, 0x0260	; 0x800260 <_state>
     69c:	8f 50       	subi	r24, 0x0F	; 15
     69e:	83 30       	cpi	r24, 0x03	; 3
     6a0:	78 f5       	brcc	.+94     	; 0x700 <wiiBtSendRaw+0x86>
     6a2:	86 2f       	mov	r24, r22
     6a4:	90 e0       	ldi	r25, 0x00	; 0
     6a6:	04 96       	adiw	r24, 0x04	; 4
     6a8:	2d b7       	in	r18, 0x3d	; 61
     6aa:	3e b7       	in	r19, 0x3e	; 62
     6ac:	28 1b       	sub	r18, r24
     6ae:	39 0b       	sbc	r19, r25
     6b0:	0f b6       	in	r0, 0x3f	; 63
     6b2:	f8 94       	cli
     6b4:	3e bf       	out	0x3e, r19	; 62
     6b6:	0f be       	out	0x3f, r0	; 63
     6b8:	2d bf       	out	0x3d, r18	; 61
     6ba:	ed b7       	in	r30, 0x3d	; 61
     6bc:	fe b7       	in	r31, 0x3e	; 62
     6be:	31 96       	adiw	r30, 0x01	; 1
     6c0:	ad b7       	in	r26, 0x3d	; 61
     6c2:	be b7       	in	r27, 0x3e	; 62
     6c4:	11 96       	adiw	r26, 0x01	; 1
     6c6:	6c 93       	st	X, r22
     6c8:	11 97       	sbiw	r26, 0x01	; 1
     6ca:	11 82       	std	Z+1, r1	; 0x01
     6cc:	90 91 66 02 	lds	r25, 0x0266	; 0x800266 <_interrupt>
     6d0:	80 91 67 02 	lds	r24, 0x0267	; 0x800267 <_interrupt+0x1>
     6d4:	92 83       	std	Z+2, r25	; 0x02
     6d6:	83 83       	std	Z+3, r24	; 0x03
     6d8:	2b 5f       	subi	r18, 0xFB	; 251
     6da:	3f 4f       	sbci	r19, 0xFF	; 255
     6dc:	80 e0       	ldi	r24, 0x00	; 0
     6de:	07 c0       	rjmp	.+14     	; 0x6ee <wiiBtSendRaw+0x74>
     6e0:	da 01       	movw	r26, r20
     6e2:	9d 91       	ld	r25, X+
     6e4:	ad 01       	movw	r20, r26
     6e6:	d9 01       	movw	r26, r18
     6e8:	9d 93       	st	X+, r25
     6ea:	9d 01       	movw	r18, r26
     6ec:	8f 5f       	subi	r24, 0xFF	; 255
     6ee:	86 17       	cp	r24, r22
     6f0:	b9 f7       	brne	.-18     	; 0x6e0 <wiiBtSendRaw+0x66>
     6f2:	68 2f       	mov	r22, r24
     6f4:	6c 5f       	subi	r22, 0xFC	; 252
     6f6:	80 e0       	ldi	r24, 0x00	; 0
     6f8:	af 01       	movw	r20, r30
     6fa:	0e 94 48 07 	call	0xe90	; 0xe90 <hci_transmit>
     6fe:	01 c0       	rjmp	.+2      	; 0x702 <wiiBtSendRaw+0x88>
     700:	81 e0       	ldi	r24, 0x01	; 1
     702:	0f b6       	in	r0, 0x3f	; 63
     704:	f8 94       	cli
     706:	1e bf       	out	0x3e, r17	; 62
     708:	0f be       	out	0x3f, r0	; 63
     70a:	0d bf       	out	0x3d, r16	; 61
     70c:	cf 91       	pop	r28
     70e:	df 91       	pop	r29
     710:	1f 91       	pop	r17
     712:	0f 91       	pop	r16
     714:	08 95       	ret

00000716 <hci_number_of_completed_packets>:
     716:	28 2f       	mov	r18, r24
     718:	30 e0       	ldi	r19, 0x00	; 0
     71a:	d9 01       	movw	r26, r18
     71c:	af 59       	subi	r26, 0x9F	; 159
     71e:	bd 4f       	sbci	r27, 0xFD	; 253
     720:	1c 92       	st	X, r1
     722:	f9 01       	movw	r30, r18
     724:	e0 5a       	subi	r30, 0xA0	; 160
     726:	fd 4f       	sbci	r31, 0xFD	; 253
     728:	90 81       	ld	r25, Z
     72a:	99 23       	and	r25, r25
     72c:	29 f4       	brne	.+10     	; 0x738 <hci_number_of_completed_packets+0x22>
     72e:	91 e0       	ldi	r25, 0x01	; 1
     730:	90 83       	st	Z, r25
     732:	61 e1       	ldi	r22, 0x11	; 17
     734:	40 e4       	ldi	r20, 0x40	; 64
     736:	1a c0       	rjmp	.+52     	; 0x76c <hci_number_of_completed_packets+0x56>
     738:	92 30       	cpi	r25, 0x02	; 2
     73a:	41 f4       	brne	.+16     	; 0x74c <hci_number_of_completed_packets+0x36>
     73c:	43 e0       	ldi	r20, 0x03	; 3
     73e:	40 83       	st	Z, r20
     740:	f9 01       	movw	r30, r18
     742:	ee 0f       	add	r30, r30
     744:	ff 1f       	adc	r31, r31
     746:	ec 59       	subi	r30, 0x9C	; 156
     748:	fd 4f       	sbci	r31, 0xFD	; 253
     74a:	1c c0       	rjmp	.+56     	; 0x784 <hci_number_of_completed_packets+0x6e>
     74c:	96 30       	cpi	r25, 0x06	; 6
     74e:	41 f4       	brne	.+16     	; 0x760 <hci_number_of_completed_packets+0x4a>
     750:	57 e0       	ldi	r21, 0x07	; 7
     752:	50 83       	st	Z, r21
     754:	f9 01       	movw	r30, r18
     756:	ee 0f       	add	r30, r30
     758:	ff 1f       	adc	r31, r31
     75a:	ec 59       	subi	r30, 0x9C	; 156
     75c:	fd 4f       	sbci	r31, 0xFD	; 253
     75e:	20 c0       	rjmp	.+64     	; 0x7a0 <hci_number_of_completed_packets+0x8a>
     760:	97 30       	cpi	r25, 0x07	; 7
     762:	39 f4       	brne	.+14     	; 0x772 <hci_number_of_completed_packets+0x5c>
     764:	28 e0       	ldi	r18, 0x08	; 8
     766:	20 83       	st	Z, r18
     768:	63 e1       	ldi	r22, 0x13	; 19
     76a:	41 e4       	ldi	r20, 0x41	; 65
     76c:	0e 94 58 02 	call	0x4b0	; 0x4b0 <transmit_connection_request>
     770:	08 95       	ret
     772:	99 30       	cpi	r25, 0x09	; 9
     774:	61 f4       	brne	.+24     	; 0x78e <hci_number_of_completed_packets+0x78>
     776:	6a e0       	ldi	r22, 0x0A	; 10
     778:	60 83       	st	Z, r22
     77a:	f9 01       	movw	r30, r18
     77c:	ee 0f       	add	r30, r30
     77e:	ff 1f       	adc	r31, r31
     780:	ea 59       	subi	r30, 0x9A	; 154
     782:	fd 4f       	sbci	r31, 0xFD	; 253
     784:	60 81       	ld	r22, Z
     786:	71 81       	ldd	r23, Z+1	; 0x01
     788:	0e 94 86 02 	call	0x50c	; 0x50c <transmit_configuration_request>
     78c:	08 95       	ret
     78e:	9d 30       	cpi	r25, 0x0D	; 13
     790:	61 f4       	brne	.+24     	; 0x7aa <hci_number_of_completed_packets+0x94>
     792:	7e e0       	ldi	r23, 0x0E	; 14
     794:	70 83       	st	Z, r23
     796:	f9 01       	movw	r30, r18
     798:	ee 0f       	add	r30, r30
     79a:	ff 1f       	adc	r31, r31
     79c:	ea 59       	subi	r30, 0x9A	; 154
     79e:	fd 4f       	sbci	r31, 0xFD	; 253
     7a0:	60 81       	ld	r22, Z
     7a2:	71 81       	ldd	r23, Z+1	; 0x01
     7a4:	0e 94 b3 02 	call	0x566	; 0x566 <transmit_configuration_response>
     7a8:	08 95       	ret
     7aa:	41 e0       	ldi	r20, 0x01	; 1
     7ac:	4c 93       	st	X, r20
     7ae:	9f 30       	cpi	r25, 0x0F	; 15
     7b0:	c1 f4       	brne	.+48     	; 0x7e2 <hci_number_of_completed_packets+0xcc>
     7b2:	40 91 68 02 	lds	r20, 0x0268	; 0x800268 <_sndCallback>
     7b6:	50 91 69 02 	lds	r21, 0x0269	; 0x800269 <_sndCallback+0x1>
     7ba:	41 15       	cp	r20, r1
     7bc:	51 05       	cpc	r21, r1
     7be:	11 f0       	breq	.+4      	; 0x7c4 <hci_number_of_completed_packets+0xae>
     7c0:	90 e1       	ldi	r25, 0x10	; 16
     7c2:	01 c0       	rjmp	.+2      	; 0x7c6 <hci_number_of_completed_packets+0xb0>
     7c4:	91 e1       	ldi	r25, 0x11	; 17
     7c6:	90 83       	st	Z, r25
     7c8:	f9 01       	movw	r30, r18
     7ca:	ee 0f       	add	r30, r30
     7cc:	ff 1f       	adc	r31, r31
     7ce:	e6 59       	subi	r30, 0x96	; 150
     7d0:	fd 4f       	sbci	r31, 0xFD	; 253
     7d2:	01 90       	ld	r0, Z+
     7d4:	f0 81       	ld	r31, Z
     7d6:	e0 2d       	mov	r30, r0
     7d8:	30 97       	sbiw	r30, 0x00	; 0
     7da:	51 f0       	breq	.+20     	; 0x7f0 <hci_number_of_completed_packets+0xda>
     7dc:	61 e0       	ldi	r22, 0x01	; 1
     7de:	09 95       	icall
     7e0:	08 95       	ret
     7e2:	90 31       	cpi	r25, 0x10	; 16
     7e4:	29 f4       	brne	.+10     	; 0x7f0 <hci_number_of_completed_packets+0xda>
     7e6:	e0 91 68 02 	lds	r30, 0x0268	; 0x800268 <_sndCallback>
     7ea:	f0 91 69 02 	lds	r31, 0x0269	; 0x800269 <_sndCallback+0x1>
     7ee:	09 95       	icall
     7f0:	08 95       	ret

000007f2 <hci_connection_complete>:
     7f2:	66 23       	and	r22, r22
     7f4:	19 f4       	brne	.+6      	; 0x7fc <hci_connection_complete+0xa>
     7f6:	0e 94 8b 03 	call	0x716	; 0x716 <hci_number_of_completed_packets>
     7fa:	08 95       	ret
     7fc:	0e 94 21 03 	call	0x642	; 0x642 <hci_disconnection_complete>
     800:	08 95       	ret

00000802 <hci_receive>:
     802:	ef 92       	push	r14
     804:	ff 92       	push	r15
     806:	1f 93       	push	r17
     808:	df 93       	push	r29
     80a:	cf 93       	push	r28
     80c:	0f 92       	push	r0
     80e:	cd b7       	in	r28, 0x3d	; 61
     810:	de b7       	in	r29, 0x3e	; 62
     812:	18 2f       	mov	r17, r24
     814:	7a 01       	movw	r14, r20
     816:	65 30       	cpi	r22, 0x05	; 5
     818:	08 f4       	brcc	.+2      	; 0x81c <hci_receive+0x1a>
     81a:	3f c1       	rjmp	.+638    	; 0xa9a <hci_receive+0x298>
     81c:	86 2f       	mov	r24, r22
     81e:	90 e0       	ldi	r25, 0x00	; 0
     820:	ac 01       	movw	r20, r24
     822:	44 50       	subi	r20, 0x04	; 4
     824:	50 40       	sbci	r21, 0x00	; 0
     826:	d7 01       	movw	r26, r14
     828:	2c 91       	ld	r18, X
     82a:	30 e0       	ldi	r19, 0x00	; 0
     82c:	42 17       	cp	r20, r18
     82e:	53 07       	cpc	r21, r19
     830:	09 f0       	breq	.+2      	; 0x834 <hci_receive+0x32>
     832:	33 c1       	rjmp	.+614    	; 0xa9a <hci_receive+0x298>
     834:	11 96       	adiw	r26, 0x01	; 1
     836:	2c 91       	ld	r18, X
     838:	11 97       	sbiw	r26, 0x01	; 1
     83a:	22 23       	and	r18, r18
     83c:	09 f0       	breq	.+2      	; 0x840 <hci_receive+0x3e>
     83e:	2d c1       	rjmp	.+602    	; 0xa9a <hci_receive+0x298>
     840:	12 96       	adiw	r26, 0x02	; 2
     842:	2c 91       	ld	r18, X
     844:	12 97       	sbiw	r26, 0x02	; 2
     846:	21 30       	cpi	r18, 0x01	; 1
     848:	09 f0       	breq	.+2      	; 0x84c <hci_receive+0x4a>
     84a:	fb c0       	rjmp	.+502    	; 0xa42 <hci_receive+0x240>
     84c:	13 96       	adiw	r26, 0x03	; 3
     84e:	3c 91       	ld	r19, X
     850:	13 97       	sbiw	r26, 0x03	; 3
     852:	33 23       	and	r19, r19
     854:	09 f0       	breq	.+2      	; 0x858 <hci_receive+0x56>
     856:	21 c1       	rjmp	.+578    	; 0xa9a <hci_receive+0x298>
     858:	68 30       	cpi	r22, 0x08	; 8
     85a:	08 f4       	brcc	.+2      	; 0x85e <hci_receive+0x5c>
     85c:	1e c1       	rjmp	.+572    	; 0xa9a <hci_receive+0x298>
     85e:	f7 01       	movw	r30, r14
     860:	34 96       	adiw	r30, 0x04	; 4
     862:	22 81       	ldd	r18, Z+2	; 0x02
     864:	30 e0       	ldi	r19, 0x00	; 0
     866:	08 97       	sbiw	r24, 0x08	; 8
     868:	28 17       	cp	r18, r24
     86a:	39 07       	cpc	r19, r25
     86c:	09 f0       	breq	.+2      	; 0x870 <hci_receive+0x6e>
     86e:	15 c1       	rjmp	.+554    	; 0xa9a <hci_receive+0x298>
     870:	83 81       	ldd	r24, Z+3	; 0x03
     872:	88 23       	and	r24, r24
     874:	09 f0       	breq	.+2      	; 0x878 <hci_receive+0x76>
     876:	11 c1       	rjmp	.+546    	; 0xa9a <hci_receive+0x298>
     878:	68 50       	subi	r22, 0x08	; 8
     87a:	14 96       	adiw	r26, 0x04	; 4
     87c:	8c 91       	ld	r24, X
     87e:	14 97       	sbiw	r26, 0x04	; 4
     880:	83 30       	cpi	r24, 0x03	; 3
     882:	09 f0       	breq	.+2      	; 0x886 <hci_receive+0x84>
     884:	4f c0       	rjmp	.+158    	; 0x924 <hci_receive+0x122>
     886:	21 81       	ldd	r18, Z+1	; 0x01
     888:	81 2f       	mov	r24, r17
     88a:	90 e0       	ldi	r25, 0x00	; 0
     88c:	dc 01       	movw	r26, r24
     88e:	a2 5a       	subi	r26, 0xA2	; 162
     890:	bd 4f       	sbci	r27, 0xFD	; 253
     892:	ec 90       	ld	r14, X
     894:	2e 15       	cp	r18, r14
     896:	09 f0       	breq	.+2      	; 0x89a <hci_receive+0x98>
     898:	00 c1       	rjmp	.+512    	; 0xa9a <hci_receive+0x298>
     89a:	68 30       	cpi	r22, 0x08	; 8
     89c:	09 f0       	breq	.+2      	; 0x8a0 <hci_receive+0x9e>
     89e:	fd c0       	rjmp	.+506    	; 0xa9a <hci_receive+0x298>
     8a0:	f7 80       	ldd	r15, Z+7	; 0x07
     8a2:	ff 20       	and	r15, r15
     8a4:	09 f0       	breq	.+2      	; 0x8a8 <hci_receive+0xa6>
     8a6:	f9 c0       	rjmp	.+498    	; 0xa9a <hci_receive+0x298>
     8a8:	30 85       	ldd	r19, Z+8	; 0x08
     8aa:	32 30       	cpi	r19, 0x02	; 2
     8ac:	08 f0       	brcs	.+2      	; 0x8b0 <hci_receive+0xae>
     8ae:	f5 c0       	rjmp	.+490    	; 0xa9a <hci_receive+0x298>
     8b0:	41 85       	ldd	r20, Z+9	; 0x09
     8b2:	44 23       	and	r20, r20
     8b4:	09 f0       	breq	.+2      	; 0x8b8 <hci_receive+0xb6>
     8b6:	f1 c0       	rjmp	.+482    	; 0xa9a <hci_receive+0x298>
     8b8:	33 23       	and	r19, r19
     8ba:	09 f0       	breq	.+2      	; 0x8be <hci_receive+0xbc>
     8bc:	f0 c0       	rjmp	.+480    	; 0xa9e <hci_receive+0x29c>
     8be:	dc 01       	movw	r26, r24
     8c0:	a2 5a       	subi	r26, 0xA2	; 162
     8c2:	bd 4f       	sbci	r27, 0xFD	; 253
     8c4:	2f 5f       	subi	r18, 0xFF	; 255
     8c6:	2c 93       	st	X, r18
     8c8:	55 81       	ldd	r21, Z+5	; 0x05
     8ca:	40 e0       	ldi	r20, 0x00	; 0
     8cc:	24 81       	ldd	r18, Z+4	; 0x04
     8ce:	30 e0       	ldi	r19, 0x00	; 0
     8d0:	24 2b       	or	r18, r20
     8d2:	35 2b       	or	r19, r21
     8d4:	46 81       	ldd	r20, Z+6	; 0x06
     8d6:	40 34       	cpi	r20, 0x40	; 64
     8d8:	89 f4       	brne	.+34     	; 0x8fc <hci_receive+0xfa>
     8da:	dc 01       	movw	r26, r24
     8dc:	a0 5a       	subi	r26, 0xA0	; 160
     8de:	bd 4f       	sbci	r27, 0xFD	; 253
     8e0:	5c 91       	ld	r21, X
     8e2:	51 30       	cpi	r21, 0x01	; 1
     8e4:	09 f0       	breq	.+2      	; 0x8e8 <hci_receive+0xe6>
     8e6:	d9 c0       	rjmp	.+434    	; 0xa9a <hci_receive+0x298>
     8e8:	fc 01       	movw	r30, r24
     8ea:	ee 0f       	add	r30, r30
     8ec:	ff 1f       	adc	r31, r31
     8ee:	ec 59       	subi	r30, 0x9C	; 156
     8f0:	fd 4f       	sbci	r31, 0xFD	; 253
     8f2:	31 83       	std	Z+1, r19	; 0x01
     8f4:	20 83       	st	Z, r18
     8f6:	62 e0       	ldi	r22, 0x02	; 2
     8f8:	6c 93       	st	X, r22
     8fa:	34 c0       	rjmp	.+104    	; 0x964 <hci_receive+0x162>
     8fc:	41 34       	cpi	r20, 0x41	; 65
     8fe:	09 f0       	breq	.+2      	; 0x902 <hci_receive+0x100>
     900:	cc c0       	rjmp	.+408    	; 0xa9a <hci_receive+0x298>
     902:	dc 01       	movw	r26, r24
     904:	a0 5a       	subi	r26, 0xA0	; 160
     906:	bd 4f       	sbci	r27, 0xFD	; 253
     908:	7c 91       	ld	r23, X
     90a:	78 30       	cpi	r23, 0x08	; 8
     90c:	09 f0       	breq	.+2      	; 0x910 <hci_receive+0x10e>
     90e:	c5 c0       	rjmp	.+394    	; 0xa9a <hci_receive+0x298>
     910:	fc 01       	movw	r30, r24
     912:	ee 0f       	add	r30, r30
     914:	ff 1f       	adc	r31, r31
     916:	ea 59       	subi	r30, 0x9A	; 154
     918:	fd 4f       	sbci	r31, 0xFD	; 253
     91a:	31 83       	std	Z+1, r19	; 0x01
     91c:	20 83       	st	Z, r18
     91e:	29 e0       	ldi	r18, 0x09	; 9
     920:	2c 93       	st	X, r18
     922:	35 c0       	rjmp	.+106    	; 0x98e <hci_receive+0x18c>
     924:	84 30       	cpi	r24, 0x04	; 4
     926:	c1 f5       	brne	.+112    	; 0x998 <hci_receive+0x196>
     928:	64 30       	cpi	r22, 0x04	; 4
     92a:	08 f4       	brcc	.+2      	; 0x92e <hci_receive+0x12c>
     92c:	b6 c0       	rjmp	.+364    	; 0xa9a <hci_receive+0x298>
     92e:	95 81       	ldd	r25, Z+5	; 0x05
     930:	99 23       	and	r25, r25
     932:	09 f0       	breq	.+2      	; 0x936 <hci_receive+0x134>
     934:	b2 c0       	rjmp	.+356    	; 0xa9a <hci_receive+0x298>
     936:	81 2f       	mov	r24, r17
     938:	90 e0       	ldi	r25, 0x00	; 0
     93a:	dc 01       	movw	r26, r24
     93c:	a1 5a       	subi	r26, 0xA1	; 161
     93e:	bd 4f       	sbci	r27, 0xFD	; 253
     940:	31 81       	ldd	r19, Z+1	; 0x01
     942:	3c 93       	st	X, r19
     944:	24 81       	ldd	r18, Z+4	; 0x04
     946:	20 34       	cpi	r18, 0x40	; 64
     948:	89 f4       	brne	.+34     	; 0x96c <hci_receive+0x16a>
     94a:	fc 01       	movw	r30, r24
     94c:	e0 5a       	subi	r30, 0xA0	; 160
     94e:	fd 4f       	sbci	r31, 0xFD	; 253
     950:	20 81       	ld	r18, Z
     952:	23 30       	cpi	r18, 0x03	; 3
     954:	11 f4       	brne	.+4      	; 0x95a <hci_receive+0x158>
     956:	85 e0       	ldi	r24, 0x05	; 5
     958:	13 c0       	rjmp	.+38     	; 0x980 <hci_receive+0x17e>
     95a:	24 30       	cpi	r18, 0x04	; 4
     95c:	09 f0       	breq	.+2      	; 0x960 <hci_receive+0x15e>
     95e:	9f c0       	rjmp	.+318    	; 0xa9e <hci_receive+0x29c>
     960:	a6 e0       	ldi	r26, 0x06	; 6
     962:	a0 83       	st	Z, r26
     964:	8f 59       	subi	r24, 0x9F	; 159
     966:	9d 4f       	sbci	r25, 0xFD	; 253
     968:	fc 01       	movw	r30, r24
     96a:	61 c0       	rjmp	.+194    	; 0xa2e <hci_receive+0x22c>
     96c:	21 34       	cpi	r18, 0x41	; 65
     96e:	09 f0       	breq	.+2      	; 0x972 <hci_receive+0x170>
     970:	94 c0       	rjmp	.+296    	; 0xa9a <hci_receive+0x298>
     972:	fc 01       	movw	r30, r24
     974:	e0 5a       	subi	r30, 0xA0	; 160
     976:	fd 4f       	sbci	r31, 0xFD	; 253
     978:	20 81       	ld	r18, Z
     97a:	2a 30       	cpi	r18, 0x0A	; 10
     97c:	19 f4       	brne	.+6      	; 0x984 <hci_receive+0x182>
     97e:	8c e0       	ldi	r24, 0x0C	; 12
     980:	80 83       	st	Z, r24
     982:	8d c0       	rjmp	.+282    	; 0xa9e <hci_receive+0x29c>
     984:	2b 30       	cpi	r18, 0x0B	; 11
     986:	09 f0       	breq	.+2      	; 0x98a <hci_receive+0x188>
     988:	8a c0       	rjmp	.+276    	; 0xa9e <hci_receive+0x29c>
     98a:	bd e0       	ldi	r27, 0x0D	; 13
     98c:	b0 83       	st	Z, r27
     98e:	8f 59       	subi	r24, 0x9F	; 159
     990:	9d 4f       	sbci	r25, 0xFD	; 253
     992:	dc 01       	movw	r26, r24
     994:	8c 91       	ld	r24, X
     996:	4c c0       	rjmp	.+152    	; 0xa30 <hci_receive+0x22e>
     998:	85 30       	cpi	r24, 0x05	; 5
     99a:	09 f0       	breq	.+2      	; 0x99e <hci_receive+0x19c>
     99c:	4f c0       	rjmp	.+158    	; 0xa3c <hci_receive+0x23a>
     99e:	81 81       	ldd	r24, Z+1	; 0x01
     9a0:	21 2f       	mov	r18, r17
     9a2:	30 e0       	ldi	r19, 0x00	; 0
     9a4:	d9 01       	movw	r26, r18
     9a6:	a2 5a       	subi	r26, 0xA2	; 162
     9a8:	bd 4f       	sbci	r27, 0xFD	; 253
     9aa:	ec 90       	ld	r14, X
     9ac:	8e 15       	cp	r24, r14
     9ae:	09 f0       	breq	.+2      	; 0x9b2 <hci_receive+0x1b0>
     9b0:	74 c0       	rjmp	.+232    	; 0xa9a <hci_receive+0x298>
     9b2:	66 30       	cpi	r22, 0x06	; 6
     9b4:	08 f4       	brcc	.+2      	; 0x9b8 <hci_receive+0x1b6>
     9b6:	71 c0       	rjmp	.+226    	; 0xa9a <hci_receive+0x298>
     9b8:	8f 5f       	subi	r24, 0xFF	; 255
     9ba:	8c 93       	st	X, r24
     9bc:	85 81       	ldd	r24, Z+5	; 0x05
     9be:	88 23       	and	r24, r24
     9c0:	09 f0       	breq	.+2      	; 0x9c4 <hci_receive+0x1c2>
     9c2:	6b c0       	rjmp	.+214    	; 0xa9a <hci_receive+0x298>
     9c4:	f6 80       	ldd	r15, Z+6	; 0x06
     9c6:	f0 fc       	sbrc	r15, 0
     9c8:	68 c0       	rjmp	.+208    	; 0xa9a <hci_receive+0x298>
     9ca:	40 85       	ldd	r20, Z+8	; 0x08
     9cc:	44 23       	and	r20, r20
     9ce:	09 f0       	breq	.+2      	; 0x9d2 <hci_receive+0x1d0>
     9d0:	64 c0       	rjmp	.+200    	; 0xa9a <hci_receive+0x298>
     9d2:	51 85       	ldd	r21, Z+9	; 0x09
     9d4:	55 23       	and	r21, r21
     9d6:	09 f0       	breq	.+2      	; 0x9da <hci_receive+0x1d8>
     9d8:	60 c0       	rjmp	.+192    	; 0xa9a <hci_receive+0x298>
     9da:	84 81       	ldd	r24, Z+4	; 0x04
     9dc:	80 34       	cpi	r24, 0x40	; 64
     9de:	81 f4       	brne	.+32     	; 0xa00 <hci_receive+0x1fe>
     9e0:	f9 01       	movw	r30, r18
     9e2:	e0 5a       	subi	r30, 0xA0	; 160
     9e4:	fd 4f       	sbci	r31, 0xFD	; 253
     9e6:	80 81       	ld	r24, Z
     9e8:	83 30       	cpi	r24, 0x03	; 3
     9ea:	11 f4       	brne	.+4      	; 0x9f0 <hci_receive+0x1ee>
     9ec:	84 e0       	ldi	r24, 0x04	; 4
     9ee:	c8 cf       	rjmp	.-112    	; 0x980 <hci_receive+0x17e>
     9f0:	85 30       	cpi	r24, 0x05	; 5
     9f2:	09 f0       	breq	.+2      	; 0x9f6 <hci_receive+0x1f4>
     9f4:	54 c0       	rjmp	.+168    	; 0xa9e <hci_receive+0x29c>
     9f6:	f9 01       	movw	r30, r18
     9f8:	e0 5a       	subi	r30, 0xA0	; 160
     9fa:	fd 4f       	sbci	r31, 0xFD	; 253
     9fc:	86 e0       	ldi	r24, 0x06	; 6
     9fe:	13 c0       	rjmp	.+38     	; 0xa26 <hci_receive+0x224>
     a00:	81 34       	cpi	r24, 0x41	; 65
     a02:	09 f0       	breq	.+2      	; 0xa06 <hci_receive+0x204>
     a04:	4a c0       	rjmp	.+148    	; 0xa9a <hci_receive+0x298>
     a06:	f9 01       	movw	r30, r18
     a08:	e0 5a       	subi	r30, 0xA0	; 160
     a0a:	fd 4f       	sbci	r31, 0xFD	; 253
     a0c:	80 81       	ld	r24, Z
     a0e:	8a 30       	cpi	r24, 0x0A	; 10
     a10:	19 f4       	brne	.+6      	; 0xa18 <hci_receive+0x216>
     a12:	1b e0       	ldi	r17, 0x0B	; 11
     a14:	10 83       	st	Z, r17
     a16:	43 c0       	rjmp	.+134    	; 0xa9e <hci_receive+0x29c>
     a18:	8c 30       	cpi	r24, 0x0C	; 12
     a1a:	09 f0       	breq	.+2      	; 0xa1e <hci_receive+0x21c>
     a1c:	40 c0       	rjmp	.+128    	; 0xa9e <hci_receive+0x29c>
     a1e:	f9 01       	movw	r30, r18
     a20:	e0 5a       	subi	r30, 0xA0	; 160
     a22:	fd 4f       	sbci	r31, 0xFD	; 253
     a24:	8d e0       	ldi	r24, 0x0D	; 13
     a26:	80 83       	st	Z, r24
     a28:	2f 59       	subi	r18, 0x9F	; 159
     a2a:	3d 4f       	sbci	r19, 0xFD	; 253
     a2c:	f9 01       	movw	r30, r18
     a2e:	80 81       	ld	r24, Z
     a30:	88 23       	and	r24, r24
     a32:	a9 f1       	breq	.+106    	; 0xa9e <hci_receive+0x29c>
     a34:	81 2f       	mov	r24, r17
     a36:	0e 94 8b 03 	call	0x716	; 0x716 <hci_number_of_completed_packets>
     a3a:	31 c0       	rjmp	.+98     	; 0xa9e <hci_receive+0x29c>
     a3c:	86 30       	cpi	r24, 0x06	; 6
     a3e:	79 f1       	breq	.+94     	; 0xa9e <hci_receive+0x29c>
     a40:	2c c0       	rjmp	.+88     	; 0xa9a <hci_receive+0x298>
     a42:	21 34       	cpi	r18, 0x41	; 65
     a44:	51 f5       	brne	.+84     	; 0xa9a <hci_receive+0x298>
     a46:	d7 01       	movw	r26, r14
     a48:	13 96       	adiw	r26, 0x03	; 3
     a4a:	ec 91       	ld	r30, X
     a4c:	13 97       	sbiw	r26, 0x03	; 3
     a4e:	ee 23       	and	r30, r30
     a50:	21 f5       	brne	.+72     	; 0xa9a <hci_receive+0x298>
     a52:	81 2f       	mov	r24, r17
     a54:	90 e0       	ldi	r25, 0x00	; 0
     a56:	fc 01       	movw	r30, r24
     a58:	e0 5a       	subi	r30, 0xA0	; 160
     a5a:	fd 4f       	sbci	r31, 0xFD	; 253
     a5c:	20 81       	ld	r18, Z
     a5e:	2e 30       	cpi	r18, 0x0E	; 14
     a60:	e0 f0       	brcs	.+56     	; 0xa9a <hci_receive+0x298>
     a62:	2e 30       	cpi	r18, 0x0E	; 14
     a64:	69 f4       	brne	.+26     	; 0xa80 <hci_receive+0x27e>
     a66:	2f e0       	ldi	r18, 0x0F	; 15
     a68:	20 83       	st	Z, r18
     a6a:	8f 59       	subi	r24, 0x9F	; 159
     a6c:	9d 4f       	sbci	r25, 0xFD	; 253
     a6e:	fc 01       	movw	r30, r24
     a70:	70 81       	ld	r23, Z
     a72:	77 23       	and	r23, r23
     a74:	29 f0       	breq	.+10     	; 0xa80 <hci_receive+0x27e>
     a76:	81 2f       	mov	r24, r17
     a78:	69 83       	std	Y+1, r22	; 0x01
     a7a:	0e 94 8b 03 	call	0x716	; 0x716 <hci_number_of_completed_packets>
     a7e:	69 81       	ldd	r22, Y+1	; 0x01
     a80:	e0 91 62 02 	lds	r30, 0x0262	; 0x800262 <_rcvCallback>
     a84:	f0 91 63 02 	lds	r31, 0x0263	; 0x800263 <_rcvCallback+0x1>
     a88:	30 97       	sbiw	r30, 0x00	; 0
     a8a:	49 f0       	breq	.+18     	; 0xa9e <hci_receive+0x29c>
     a8c:	64 50       	subi	r22, 0x04	; 4
     a8e:	a7 01       	movw	r20, r14
     a90:	4c 5f       	subi	r20, 0xFC	; 252
     a92:	5f 4f       	sbci	r21, 0xFF	; 255
     a94:	81 2f       	mov	r24, r17
     a96:	09 95       	icall
     a98:	02 c0       	rjmp	.+4      	; 0xa9e <hci_receive+0x29c>
     a9a:	0e 94 fe 08 	call	0x11fc	; 0x11fc <abort>
     a9e:	0f 90       	pop	r0
     aa0:	cf 91       	pop	r28
     aa2:	df 91       	pop	r29
     aa4:	1f 91       	pop	r17
     aa6:	ff 90       	pop	r15
     aa8:	ef 90       	pop	r14
     aaa:	08 95       	ret

00000aac <sndCallback>:
     aac:	8f b7       	in	r24, 0x3f	; 63
     aae:	f8 94       	cli
     ab0:	e0 91 8f 02 	lds	r30, 0x028F	; 0x80028f <_first>
     ab4:	f0 91 90 02 	lds	r31, 0x0290	; 0x800290 <_first+0x1>
     ab8:	30 97       	sbiw	r30, 0x00	; 0
     aba:	31 f4       	brne	.+12     	; 0xac8 <sndCallback+0x1c>
     abc:	10 92 27 02 	sts	0x0227, r1	; 0x800227 <_last+0x1>
     ac0:	10 92 26 02 	sts	0x0226, r1	; 0x800226 <_last>
     ac4:	8f bf       	out	0x3f, r24	; 63
     ac6:	08 95       	ret
     ac8:	8f bf       	out	0x3f, r24	; 63
     aca:	90 91 91 02 	lds	r25, 0x0291	; 0x800291 <_offset.1295>
     ace:	df 01       	movw	r26, r30
     ad0:	a9 0f       	add	r26, r25
     ad2:	b1 1d       	adc	r27, r1
     ad4:	11 96       	adiw	r26, 0x01	; 1
     ad6:	8c 91       	ld	r24, X
     ad8:	11 97       	sbiw	r26, 0x01	; 1
     ada:	9f 5f       	subi	r25, 0xFF	; 255
     adc:	20 81       	ld	r18, Z
     ade:	92 17       	cp	r25, r18
     ae0:	49 f4       	brne	.+18     	; 0xaf4 <sndCallback+0x48>
     ae2:	21 a1       	ldd	r18, Z+33	; 0x21
     ae4:	32 a1       	ldd	r19, Z+34	; 0x22
     ae6:	30 93 90 02 	sts	0x0290, r19	; 0x800290 <_first+0x1>
     aea:	20 93 8f 02 	sts	0x028F, r18	; 0x80028f <_first>
     aee:	12 a2       	std	Z+34, r1	; 0x22
     af0:	11 a2       	std	Z+33, r1	; 0x21
     af2:	90 e0       	ldi	r25, 0x00	; 0
     af4:	90 93 91 02 	sts	0x0291, r25	; 0x800291 <_offset.1295>
     af8:	0e 94 e4 07 	call	0xfc8	; 0xfc8 <halWT41FcUartSend>
     afc:	08 95       	ret

00000afe <transmit>:
     afe:	4f b7       	in	r20, 0x3f	; 63
     b00:	f8 94       	cli
     b02:	e0 91 26 02 	lds	r30, 0x0226	; 0x800226 <_last>
     b06:	f0 91 27 02 	lds	r31, 0x0227	; 0x800227 <_last+0x1>
     b0a:	90 93 27 02 	sts	0x0227, r25	; 0x800227 <_last+0x1>
     b0e:	80 93 26 02 	sts	0x0226, r24	; 0x800226 <_last>
     b12:	20 91 8f 02 	lds	r18, 0x028F	; 0x80028f <_first>
     b16:	30 91 90 02 	lds	r19, 0x0290	; 0x800290 <_first+0x1>
     b1a:	21 15       	cp	r18, r1
     b1c:	31 05       	cpc	r19, r1
     b1e:	21 f0       	breq	.+8      	; 0xb28 <transmit+0x2a>
     b20:	92 a3       	std	Z+34, r25	; 0x22
     b22:	81 a3       	std	Z+33, r24	; 0x21
     b24:	4f bf       	out	0x3f, r20	; 63
     b26:	08 95       	ret
     b28:	90 93 90 02 	sts	0x0290, r25	; 0x800290 <_first+0x1>
     b2c:	80 93 8f 02 	sts	0x028F, r24	; 0x80028f <_first>
     b30:	4f bf       	out	0x3f, r20	; 63
     b32:	30 97       	sbiw	r30, 0x00	; 0
     b34:	11 f4       	brne	.+4      	; 0xb3a <transmit+0x3c>
     b36:	0e 94 56 05 	call	0xaac	; 0xaac <sndCallback>
     b3a:	08 95       	ret

00000b3c <rcvCallback>:
     b3c:	0f 93       	push	r16
     b3e:	1f 93       	push	r17
     b40:	cf 93       	push	r28
     b42:	df 93       	push	r29
     b44:	90 91 8d 02 	lds	r25, 0x028D	; 0x80028d <_state.1399>
     b48:	92 34       	cpi	r25, 0x42	; 66
     b4a:	09 f4       	brne	.+2      	; 0xb4e <rcvCallback+0x12>
     b4c:	52 c1       	rjmp	.+676    	; 0xdf2 <rcvCallback+0x2b6>
     b4e:	94 32       	cpi	r25, 0x24	; 36
     b50:	09 f4       	brne	.+2      	; 0xb54 <rcvCallback+0x18>
     b52:	45 c0       	rjmp	.+138    	; 0xbde <rcvCallback+0xa2>
     b54:	99 23       	and	r25, r25
     b56:	29 f4       	brne	.+10     	; 0xb62 <rcvCallback+0x26>
     b58:	82 30       	cpi	r24, 0x02	; 2
     b5a:	41 f0       	breq	.+16     	; 0xb6c <rcvCallback+0x30>
     b5c:	84 30       	cpi	r24, 0x04	; 4
     b5e:	31 f0       	breq	.+12     	; 0xb6c <rcvCallback+0x30>
     b60:	61 c1       	rjmp	.+706    	; 0xe24 <rcvCallback+0x2e8>
     b62:	92 30       	cpi	r25, 0x02	; 2
     b64:	31 f4       	brne	.+12     	; 0xb72 <rcvCallback+0x36>
     b66:	80 93 6d 02 	sts	0x026D, r24	; 0x80026d <_union.1411>
     b6a:	82 e1       	ldi	r24, 0x12	; 18
     b6c:	80 93 8d 02 	sts	0x028D, r24	; 0x80028d <_state.1399>
     b70:	5b c1       	rjmp	.+694    	; 0xe28 <rcvCallback+0x2ec>
     b72:	92 31       	cpi	r25, 0x12	; 18
     b74:	a9 f4       	brne	.+42     	; 0xba0 <rcvCallback+0x64>
     b76:	98 2f       	mov	r25, r24
     b78:	90 7f       	andi	r25, 0xF0	; 240
     b7a:	90 32       	cpi	r25, 0x20	; 32
     b7c:	09 f0       	breq	.+2      	; 0xb80 <rcvCallback+0x44>
     b7e:	52 c1       	rjmp	.+676    	; 0xe24 <rcvCallback+0x2e8>
     b80:	20 91 6d 02 	lds	r18, 0x026D	; 0x80026d <_union.1411>
     b84:	38 2f       	mov	r19, r24
     b86:	3f 70       	andi	r19, 0x0F	; 15
     b88:	80 91 00 02 	lds	r24, 0x0200	; 0x800200 <__data_start>
     b8c:	90 91 01 02 	lds	r25, 0x0201	; 0x800201 <__data_start+0x1>
     b90:	82 17       	cp	r24, r18
     b92:	93 07       	cpc	r25, r19
     b94:	09 f0       	breq	.+2      	; 0xb98 <rcvCallback+0x5c>
     b96:	46 c1       	rjmp	.+652    	; 0xe24 <rcvCallback+0x2e8>
     b98:	10 92 6d 02 	sts	0x026D, r1	; 0x80026d <_union.1411>
     b9c:	82 e2       	ldi	r24, 0x22	; 34
     b9e:	e6 cf       	rjmp	.-52     	; 0xb6c <rcvCallback+0x30>
     ba0:	92 32       	cpi	r25, 0x22	; 34
     ba2:	49 f4       	brne	.+18     	; 0xbb6 <rcvCallback+0x7a>
     ba4:	08 2f       	mov	r16, r24
     ba6:	01 50       	subi	r16, 0x01	; 1
     ba8:	0b 31       	cpi	r16, 0x1B	; 27
     baa:	08 f0       	brcs	.+2      	; 0xbae <rcvCallback+0x72>
     bac:	3b c1       	rjmp	.+630    	; 0xe24 <rcvCallback+0x2e8>
     bae:	80 93 8c 02 	sts	0x028C, r24	; 0x80028c <_length.1400>
     bb2:	82 e3       	ldi	r24, 0x32	; 50
     bb4:	db cf       	rjmp	.-74     	; 0xb6c <rcvCallback+0x30>
     bb6:	92 33       	cpi	r25, 0x32	; 50
     bb8:	29 f4       	brne	.+10     	; 0xbc4 <rcvCallback+0x88>
     bba:	88 23       	and	r24, r24
     bbc:	09 f0       	breq	.+2      	; 0xbc0 <rcvCallback+0x84>
     bbe:	32 c1       	rjmp	.+612    	; 0xe24 <rcvCallback+0x2e8>
     bc0:	82 e4       	ldi	r24, 0x42	; 66
     bc2:	d4 cf       	rjmp	.-88     	; 0xb6c <rcvCallback+0x30>
     bc4:	94 30       	cpi	r25, 0x04	; 4
     bc6:	21 f4       	brne	.+8      	; 0xbd0 <rcvCallback+0x94>
     bc8:	80 93 6d 02 	sts	0x026D, r24	; 0x80026d <_union.1411>
     bcc:	84 e1       	ldi	r24, 0x14	; 20
     bce:	ce cf       	rjmp	.-100    	; 0xb6c <rcvCallback+0x30>
     bd0:	8e 31       	cpi	r24, 0x1E	; 30
     bd2:	08 f0       	brcs	.+2      	; 0xbd6 <rcvCallback+0x9a>
     bd4:	27 c1       	rjmp	.+590    	; 0xe24 <rcvCallback+0x2e8>
     bd6:	80 93 8c 02 	sts	0x028C, r24	; 0x80028c <_length.1400>
     bda:	84 e2       	ldi	r24, 0x24	; 36
     bdc:	c7 cf       	rjmp	.-114    	; 0xb6c <rcvCallback+0x30>
     bde:	90 91 8b 02 	lds	r25, 0x028B	; 0x80028b <_offset.1401>
     be2:	e9 2f       	mov	r30, r25
     be4:	f0 e0       	ldi	r31, 0x00	; 0
     be6:	e3 59       	subi	r30, 0x93	; 147
     be8:	fd 4f       	sbci	r31, 0xFD	; 253
     bea:	81 83       	std	Z+1, r24	; 0x01
     bec:	9f 5f       	subi	r25, 0xFF	; 255
     bee:	90 93 8b 02 	sts	0x028B, r25	; 0x80028b <_offset.1401>
     bf2:	20 91 8c 02 	lds	r18, 0x028C	; 0x80028c <_length.1400>
     bf6:	92 17       	cp	r25, r18
     bf8:	09 f0       	breq	.+2      	; 0xbfc <rcvCallback+0xc0>
     bfa:	16 c1       	rjmp	.+556    	; 0xe28 <rcvCallback+0x2ec>
     bfc:	10 92 8b 02 	sts	0x028B, r1	; 0x80028b <_offset.1401>
     c00:	10 92 8d 02 	sts	0x028D, r1	; 0x80028d <_state.1399>
     c04:	80 91 6d 02 	lds	r24, 0x026D	; 0x80026d <_union.1411>
     c08:	83 30       	cpi	r24, 0x03	; 3
     c0a:	e1 f5       	brne	.+120    	; 0xc84 <rcvCallback+0x148>
     c0c:	9b 30       	cpi	r25, 0x0B	; 11
     c0e:	09 f0       	breq	.+2      	; 0xc12 <rcvCallback+0xd6>
     c10:	09 c1       	rjmp	.+530    	; 0xe24 <rcvCallback+0x2e8>
     c12:	80 91 02 02 	lds	r24, 0x0202	; 0x800202 <_create>
     c16:	88 23       	and	r24, r24
     c18:	09 f0       	breq	.+2      	; 0xc1c <rcvCallback+0xe0>
     c1a:	04 c1       	rjmp	.+520    	; 0xe24 <rcvCallback+0x2e8>
     c1c:	e1 e7       	ldi	r30, 0x71	; 113
     c1e:	f2 e0       	ldi	r31, 0x02	; 2
     c20:	84 e0       	ldi	r24, 0x04	; 4
     c22:	90 e0       	ldi	r25, 0x00	; 0
     c24:	31 91       	ld	r19, Z+
     c26:	dc 01       	movw	r26, r24
     c28:	ad 5f       	subi	r26, 0xFD	; 253
     c2a:	bd 4f       	sbci	r27, 0xFD	; 253
     c2c:	11 96       	adiw	r26, 0x01	; 1
     c2e:	2c 91       	ld	r18, X
     c30:	11 97       	sbiw	r26, 0x01	; 1
     c32:	32 17       	cp	r19, r18
     c34:	09 f0       	breq	.+2      	; 0xc38 <rcvCallback+0xfc>
     c36:	f6 c0       	rjmp	.+492    	; 0xe24 <rcvCallback+0x2e8>
     c38:	01 96       	adiw	r24, 0x01	; 1
     c3a:	8a 30       	cpi	r24, 0x0A	; 10
     c3c:	91 05       	cpc	r25, r1
     c3e:	91 f7       	brne	.-28     	; 0xc24 <rcvCallback+0xe8>
     c40:	80 91 02 02 	lds	r24, 0x0202	; 0x800202 <_create>
     c44:	60 91 6e 02 	lds	r22, 0x026E	; 0x80026e <_union.1411+0x1>
     c48:	66 23       	and	r22, r22
     c4a:	09 f0       	breq	.+2      	; 0xc4e <rcvCallback+0x112>
     c4c:	81 c0       	rjmp	.+258    	; 0xd50 <rcvCallback+0x214>
     c4e:	10 91 77 02 	lds	r17, 0x0277	; 0x800277 <_union.1411+0xa>
     c52:	11 30       	cpi	r17, 0x01	; 1
     c54:	09 f0       	breq	.+2      	; 0xc58 <rcvCallback+0x11c>
     c56:	e6 c0       	rjmp	.+460    	; 0xe24 <rcvCallback+0x2e8>
     c58:	40 91 78 02 	lds	r20, 0x0278	; 0x800278 <_union.1411+0xb>
     c5c:	44 23       	and	r20, r20
     c5e:	09 f0       	breq	.+2      	; 0xc62 <rcvCallback+0x126>
     c60:	e1 c0       	rjmp	.+450    	; 0xe24 <rcvCallback+0x2e8>
     c62:	90 91 70 02 	lds	r25, 0x0270	; 0x800270 <_union.1411+0x3>
     c66:	90 31       	cpi	r25, 0x10	; 16
     c68:	08 f0       	brcs	.+2      	; 0xc6c <rcvCallback+0x130>
     c6a:	dc c0       	rjmp	.+440    	; 0xe24 <rcvCallback+0x2e8>
     c6c:	20 91 6f 02 	lds	r18, 0x026F	; 0x80026f <_union.1411+0x2>
     c70:	39 2f       	mov	r19, r25
     c72:	e8 2f       	mov	r30, r24
     c74:	f0 e0       	ldi	r31, 0x00	; 0
     c76:	ee 0f       	add	r30, r30
     c78:	ff 1f       	adc	r31, r31
     c7a:	e0 50       	subi	r30, 0x00	; 0
     c7c:	fe 4f       	sbci	r31, 0xFE	; 254
     c7e:	31 83       	std	Z+1, r19	; 0x01
     c80:	20 83       	st	Z, r18
     c82:	66 c0       	rjmp	.+204    	; 0xd50 <rcvCallback+0x214>
     c84:	85 30       	cpi	r24, 0x05	; 5
     c86:	01 f5       	brne	.+64     	; 0xcc8 <rcvCallback+0x18c>
     c88:	94 30       	cpi	r25, 0x04	; 4
     c8a:	09 f0       	breq	.+2      	; 0xc8e <rcvCallback+0x152>
     c8c:	cb c0       	rjmp	.+406    	; 0xe24 <rcvCallback+0x2e8>
     c8e:	50 91 6e 02 	lds	r21, 0x026E	; 0x80026e <_union.1411+0x1>
     c92:	55 23       	and	r21, r21
     c94:	09 f0       	breq	.+2      	; 0xc98 <rcvCallback+0x15c>
     c96:	c6 c0       	rjmp	.+396    	; 0xe24 <rcvCallback+0x2e8>
     c98:	80 91 6f 02 	lds	r24, 0x026F	; 0x80026f <_union.1411+0x2>
     c9c:	90 91 70 02 	lds	r25, 0x0270	; 0x800270 <_union.1411+0x3>
     ca0:	20 91 00 02 	lds	r18, 0x0200	; 0x800200 <__data_start>
     ca4:	30 91 01 02 	lds	r19, 0x0201	; 0x800201 <__data_start+0x1>
     ca8:	82 17       	cp	r24, r18
     caa:	93 07       	cpc	r25, r19
     cac:	09 f0       	breq	.+2      	; 0xcb0 <rcvCallback+0x174>
     cae:	ba c0       	rjmp	.+372    	; 0xe24 <rcvCallback+0x2e8>
     cb0:	80 e0       	ldi	r24, 0x00	; 0
     cb2:	90 e1       	ldi	r25, 0x10	; 16
     cb4:	90 93 01 02 	sts	0x0201, r25	; 0x800201 <__data_start+0x1>
     cb8:	80 93 00 02 	sts	0x0200, r24	; 0x800200 <__data_start>
     cbc:	10 92 8e 02 	sts	0x028E, r1	; 0x80028e <_packet>
     cc0:	80 e0       	ldi	r24, 0x00	; 0
     cc2:	0e 94 21 03 	call	0x642	; 0x642 <hci_disconnection_complete>
     cc6:	b0 c0       	rjmp	.+352    	; 0xe28 <rcvCallback+0x2ec>
     cc8:	8d 30       	cpi	r24, 0x0D	; 13
     cca:	09 f4       	brne	.+2      	; 0xcce <rcvCallback+0x192>
     ccc:	ad c0       	rjmp	.+346    	; 0xe28 <rcvCallback+0x2ec>
     cce:	8f 30       	cpi	r24, 0x0F	; 15
     cd0:	09 f0       	breq	.+2      	; 0xcd4 <rcvCallback+0x198>
     cd2:	44 c0       	rjmp	.+136    	; 0xd5c <rcvCallback+0x220>
     cd4:	94 30       	cpi	r25, 0x04	; 4
     cd6:	09 f0       	breq	.+2      	; 0xcda <rcvCallback+0x19e>
     cd8:	a5 c0       	rjmp	.+330    	; 0xe24 <rcvCallback+0x2e8>
     cda:	60 91 6f 02 	lds	r22, 0x026F	; 0x80026f <_union.1411+0x2>
     cde:	61 30       	cpi	r22, 0x01	; 1
     ce0:	09 f0       	breq	.+2      	; 0xce4 <rcvCallback+0x1a8>
     ce2:	a0 c0       	rjmp	.+320    	; 0xe24 <rcvCallback+0x2e8>
     ce4:	70 91 04 02 	lds	r23, 0x0204	; 0x800204 <_command+0x1>
     ce8:	80 91 70 02 	lds	r24, 0x0270	; 0x800270 <_union.1411+0x3>
     cec:	77 23       	and	r23, r23
     cee:	71 f4       	brne	.+28     	; 0xd0c <rcvCallback+0x1d0>
     cf0:	88 23       	and	r24, r24
     cf2:	09 f0       	breq	.+2      	; 0xcf6 <rcvCallback+0x1ba>
     cf4:	97 c0       	rjmp	.+302    	; 0xe24 <rcvCallback+0x2e8>
     cf6:	a0 91 71 02 	lds	r26, 0x0271	; 0x800271 <_union.1411+0x4>
     cfa:	aa 23       	and	r26, r26
     cfc:	09 f0       	breq	.+2      	; 0xd00 <rcvCallback+0x1c4>
     cfe:	92 c0       	rjmp	.+292    	; 0xe24 <rcvCallback+0x2e8>
     d00:	b1 e0       	ldi	r27, 0x01	; 1
     d02:	b0 93 04 02 	sts	0x0204, r27	; 0x800204 <_command+0x1>
     d06:	0e 94 56 05 	call	0xaac	; 0xaac <sndCallback>
     d0a:	8e c0       	rjmp	.+284    	; 0xe28 <rcvCallback+0x2ec>
     d0c:	85 30       	cpi	r24, 0x05	; 5
     d0e:	09 f0       	breq	.+2      	; 0xd12 <rcvCallback+0x1d6>
     d10:	89 c0       	rjmp	.+274    	; 0xe24 <rcvCallback+0x2e8>
     d12:	e0 91 71 02 	lds	r30, 0x0271	; 0x800271 <_union.1411+0x4>
     d16:	e4 30       	cpi	r30, 0x04	; 4
     d18:	09 f0       	breq	.+2      	; 0xd1c <rcvCallback+0x1e0>
     d1a:	84 c0       	rjmp	.+264    	; 0xe24 <rcvCallback+0x2e8>
     d1c:	f8 94       	cli
     d1e:	20 91 24 02 	lds	r18, 0x0224	; 0x800224 <_command+0x21>
     d22:	30 91 25 02 	lds	r19, 0x0225	; 0x800225 <_command+0x22>
     d26:	80 91 26 02 	lds	r24, 0x0226	; 0x800226 <_last>
     d2a:	90 91 27 02 	lds	r25, 0x0227	; 0x800227 <_last+0x1>
     d2e:	78 94       	sei
     d30:	21 15       	cp	r18, r1
     d32:	31 05       	cpc	r19, r1
     d34:	09 f0       	breq	.+2      	; 0xd38 <rcvCallback+0x1fc>
     d36:	76 c0       	rjmp	.+236    	; 0xe24 <rcvCallback+0x2e8>
     d38:	22 e0       	ldi	r18, 0x02	; 2
     d3a:	83 30       	cpi	r24, 0x03	; 3
     d3c:	92 07       	cpc	r25, r18
     d3e:	09 f4       	brne	.+2      	; 0xd42 <rcvCallback+0x206>
     d40:	71 c0       	rjmp	.+226    	; 0xe24 <rcvCallback+0x2e8>
     d42:	60 91 6e 02 	lds	r22, 0x026E	; 0x80026e <_union.1411+0x1>
     d46:	66 23       	and	r22, r22
     d48:	09 f4       	brne	.+2      	; 0xd4c <rcvCallback+0x210>
     d4a:	6e c0       	rjmp	.+220    	; 0xe28 <rcvCallback+0x2ec>
     d4c:	80 91 02 02 	lds	r24, 0x0202	; 0x800202 <_create>
     d50:	f1 e0       	ldi	r31, 0x01	; 1
     d52:	f0 93 02 02 	sts	0x0202, r31	; 0x800202 <_create>
     d56:	0e 94 f9 03 	call	0x7f2	; 0x7f2 <hci_connection_complete>
     d5a:	66 c0       	rjmp	.+204    	; 0xe28 <rcvCallback+0x2ec>
     d5c:	83 31       	cpi	r24, 0x13	; 19
     d5e:	09 f0       	breq	.+2      	; 0xd62 <rcvCallback+0x226>
     d60:	61 c0       	rjmp	.+194    	; 0xe24 <rcvCallback+0x2e8>
     d62:	22 23       	and	r18, r18
     d64:	09 f4       	brne	.+2      	; 0xd68 <rcvCallback+0x22c>
     d66:	5e c0       	rjmp	.+188    	; 0xe24 <rcvCallback+0x2e8>
     d68:	00 91 6e 02 	lds	r16, 0x026E	; 0x80026e <_union.1411+0x1>
     d6c:	0e 31       	cpi	r16, 0x1E	; 30
     d6e:	08 f0       	brcs	.+2      	; 0xd72 <rcvCallback+0x236>
     d70:	59 c0       	rjmp	.+178    	; 0xe24 <rcvCallback+0x2e8>
     d72:	30 e0       	ldi	r19, 0x00	; 0
     d74:	80 2f       	mov	r24, r16
     d76:	90 e0       	ldi	r25, 0x00	; 0
     d78:	88 0f       	add	r24, r24
     d7a:	99 1f       	adc	r25, r25
     d7c:	88 0f       	add	r24, r24
     d7e:	99 1f       	adc	r25, r25
     d80:	01 96       	adiw	r24, 0x01	; 1
     d82:	28 17       	cp	r18, r24
     d84:	39 07       	cpc	r19, r25
     d86:	09 f0       	breq	.+2      	; 0xd8a <rcvCallback+0x24e>
     d88:	4d c0       	rjmp	.+154    	; 0xe24 <rcvCallback+0x2e8>
     d8a:	cf e6       	ldi	r28, 0x6F	; 111
     d8c:	d2 e0       	ldi	r29, 0x02	; 2
     d8e:	10 e0       	ldi	r17, 0x00	; 0
     d90:	2d c0       	rjmp	.+90     	; 0xdec <rcvCallback+0x2b0>
     d92:	9a 81       	ldd	r25, Y+2	; 0x02
     d94:	91 30       	cpi	r25, 0x01	; 1
     d96:	09 f0       	breq	.+2      	; 0xd9a <rcvCallback+0x25e>
     d98:	45 c0       	rjmp	.+138    	; 0xe24 <rcvCallback+0x2e8>
     d9a:	8b 81       	ldd	r24, Y+3	; 0x03
     d9c:	88 23       	and	r24, r24
     d9e:	09 f0       	breq	.+2      	; 0xda2 <rcvCallback+0x266>
     da0:	41 c0       	rjmp	.+130    	; 0xe24 <rcvCallback+0x2e8>
     da2:	88 81       	ld	r24, Y
     da4:	99 81       	ldd	r25, Y+1	; 0x01
     da6:	20 91 00 02 	lds	r18, 0x0200	; 0x800200 <__data_start>
     daa:	30 91 01 02 	lds	r19, 0x0201	; 0x800201 <__data_start+0x1>
     dae:	82 17       	cp	r24, r18
     db0:	93 07       	cpc	r25, r19
     db2:	d1 f4       	brne	.+52     	; 0xde8 <rcvCallback+0x2ac>
     db4:	20 91 8e 02 	lds	r18, 0x028E	; 0x80028e <_packet>
     db8:	22 23       	and	r18, r18
     dba:	a1 f1       	breq	.+104    	; 0xe24 <rcvCallback+0x2e8>
     dbc:	f8 94       	cli
     dbe:	20 91 49 02 	lds	r18, 0x0249	; 0x800249 <_data+0x21>
     dc2:	30 91 4a 02 	lds	r19, 0x024A	; 0x80024a <_data+0x22>
     dc6:	80 91 26 02 	lds	r24, 0x0226	; 0x800226 <_last>
     dca:	90 91 27 02 	lds	r25, 0x0227	; 0x800227 <_last+0x1>
     dce:	78 94       	sei
     dd0:	21 15       	cp	r18, r1
     dd2:	31 05       	cpc	r19, r1
     dd4:	39 f5       	brne	.+78     	; 0xe24 <rcvCallback+0x2e8>
     dd6:	22 e0       	ldi	r18, 0x02	; 2
     dd8:	88 32       	cpi	r24, 0x28	; 40
     dda:	92 07       	cpc	r25, r18
     ddc:	19 f1       	breq	.+70     	; 0xe24 <rcvCallback+0x2e8>
     dde:	10 92 8e 02 	sts	0x028E, r1	; 0x80028e <_packet>
     de2:	80 e0       	ldi	r24, 0x00	; 0
     de4:	0e 94 8b 03 	call	0x716	; 0x716 <hci_number_of_completed_packets>
     de8:	1f 5f       	subi	r17, 0xFF	; 255
     dea:	24 96       	adiw	r28, 0x04	; 4
     dec:	10 17       	cp	r17, r16
     dee:	88 f2       	brcs	.-94     	; 0xd92 <rcvCallback+0x256>
     df0:	1b c0       	rjmp	.+54     	; 0xe28 <rcvCallback+0x2ec>
     df2:	60 91 8b 02 	lds	r22, 0x028B	; 0x80028b <_offset.1401>
     df6:	e6 2f       	mov	r30, r22
     df8:	f0 e0       	ldi	r31, 0x00	; 0
     dfa:	e3 59       	subi	r30, 0x93	; 147
     dfc:	fd 4f       	sbci	r31, 0xFD	; 253
     dfe:	81 83       	std	Z+1, r24	; 0x01
     e00:	6f 5f       	subi	r22, 0xFF	; 255
     e02:	60 93 8b 02 	sts	0x028B, r22	; 0x80028b <_offset.1401>
     e06:	00 91 8c 02 	lds	r16, 0x028C	; 0x80028c <_length.1400>
     e0a:	60 17       	cp	r22, r16
     e0c:	69 f4       	brne	.+26     	; 0xe28 <rcvCallback+0x2ec>
     e0e:	10 92 8b 02 	sts	0x028B, r1	; 0x80028b <_offset.1401>
     e12:	10 92 8d 02 	sts	0x028D, r1	; 0x80028d <_state.1399>
     e16:	80 91 6d 02 	lds	r24, 0x026D	; 0x80026d <_union.1411>
     e1a:	4e e6       	ldi	r20, 0x6E	; 110
     e1c:	52 e0       	ldi	r21, 0x02	; 2
     e1e:	0e 94 01 04 	call	0x802	; 0x802 <hci_receive>
     e22:	02 c0       	rjmp	.+4      	; 0xe28 <rcvCallback+0x2ec>
     e24:	0e 94 fe 08 	call	0x11fc	; 0x11fc <abort>
     e28:	df 91       	pop	r29
     e2a:	cf 91       	pop	r28
     e2c:	1f 91       	pop	r17
     e2e:	0f 91       	pop	r16
     e30:	08 95       	ret

00000e32 <hci_create_connection>:
     e32:	88 23       	and	r24, r24
     e34:	19 f4       	brne	.+6      	; 0xe3c <hci_create_connection+0xa>
     e36:	61 15       	cp	r22, r1
     e38:	71 05       	cpc	r23, r1
     e3a:	11 f4       	brne	.+4      	; 0xe40 <hci_create_connection+0xe>
     e3c:	0e 94 fe 08 	call	0x11fc	; 0x11fc <abort>
     e40:	f8 94       	cli
     e42:	80 91 00 02 	lds	r24, 0x0200	; 0x800200 <__data_start>
     e46:	90 91 01 02 	lds	r25, 0x0201	; 0x800201 <__data_start+0x1>
     e4a:	20 e1       	ldi	r18, 0x10	; 16
     e4c:	80 30       	cpi	r24, 0x00	; 0
     e4e:	92 07       	cpc	r25, r18
     e50:	20 f0       	brcs	.+8      	; 0xe5a <hci_create_connection+0x28>
     e52:	80 91 02 02 	lds	r24, 0x0202	; 0x800202 <_create>
     e56:	88 23       	and	r24, r24
     e58:	19 f4       	brne	.+6      	; 0xe60 <hci_create_connection+0x2e>
     e5a:	78 94       	sei
     e5c:	81 e0       	ldi	r24, 0x01	; 1
     e5e:	08 95       	ret
     e60:	10 92 02 02 	sts	0x0202, r1	; 0x800202 <_create>
     e64:	78 94       	sei
     e66:	fb 01       	movw	r30, r22
     e68:	36 96       	adiw	r30, 0x06	; 6
     e6a:	84 e0       	ldi	r24, 0x04	; 4
     e6c:	90 e0       	ldi	r25, 0x00	; 0
     e6e:	22 91       	ld	r18, -Z
     e70:	dc 01       	movw	r26, r24
     e72:	ad 5f       	subi	r26, 0xFD	; 253
     e74:	bd 4f       	sbci	r27, 0xFD	; 253
     e76:	11 96       	adiw	r26, 0x01	; 1
     e78:	2c 93       	st	X, r18
     e7a:	11 97       	sbiw	r26, 0x01	; 1
     e7c:	01 96       	adiw	r24, 0x01	; 1
     e7e:	8a 30       	cpi	r24, 0x0A	; 10
     e80:	91 05       	cpc	r25, r1
     e82:	a9 f7       	brne	.-22     	; 0xe6e <hci_create_connection+0x3c>
     e84:	83 e0       	ldi	r24, 0x03	; 3
     e86:	92 e0       	ldi	r25, 0x02	; 2
     e88:	0e 94 7f 05 	call	0xafe	; 0xafe <transmit>
     e8c:	80 e0       	ldi	r24, 0x00	; 0
     e8e:	08 95       	ret

00000e90 <hci_transmit>:
     e90:	88 23       	and	r24, r24
     e92:	11 f4       	brne	.+4      	; 0xe98 <hci_transmit+0x8>
     e94:	6c 31       	cpi	r22, 0x1C	; 28
     e96:	10 f0       	brcs	.+4      	; 0xe9c <hci_transmit+0xc>
     e98:	0e 94 fe 08 	call	0x11fc	; 0x11fc <abort>
     e9c:	2f b7       	in	r18, 0x3f	; 63
     e9e:	f8 94       	cli
     ea0:	80 91 00 02 	lds	r24, 0x0200	; 0x800200 <__data_start>
     ea4:	90 91 01 02 	lds	r25, 0x0201	; 0x800201 <__data_start+0x1>
     ea8:	30 e1       	ldi	r19, 0x10	; 16
     eaa:	80 30       	cpi	r24, 0x00	; 0
     eac:	93 07       	cpc	r25, r19
     eae:	20 f4       	brcc	.+8      	; 0xeb8 <hci_transmit+0x28>
     eb0:	30 91 8e 02 	lds	r19, 0x028E	; 0x80028e <_packet>
     eb4:	33 23       	and	r19, r19
     eb6:	19 f0       	breq	.+6      	; 0xebe <hci_transmit+0x2e>
     eb8:	2f bf       	out	0x3f, r18	; 63
     eba:	81 e0       	ldi	r24, 0x01	; 1
     ebc:	08 95       	ret
     ebe:	a1 e0       	ldi	r26, 0x01	; 1
     ec0:	a0 93 8e 02 	sts	0x028E, r26	; 0x80028e <_packet>
     ec4:	2f bf       	out	0x3f, r18	; 63
     ec6:	76 2f       	mov	r23, r22
     ec8:	7b 5f       	subi	r23, 0xFB	; 251
     eca:	70 93 28 02 	sts	0x0228, r23	; 0x800228 <_data>
     ece:	80 93 2a 02 	sts	0x022A, r24	; 0x80022a <_data+0x2>
     ed2:	89 2f       	mov	r24, r25
     ed4:	80 62       	ori	r24, 0x20	; 32
     ed6:	80 93 2b 02 	sts	0x022B, r24	; 0x80022b <_data+0x3>
     eda:	60 93 2c 02 	sts	0x022C, r22	; 0x80022c <_data+0x4>
     ede:	84 2f       	mov	r24, r20
     ee0:	95 2f       	mov	r25, r21
     ee2:	fc 01       	movw	r30, r24
     ee4:	80 e0       	ldi	r24, 0x00	; 0
     ee6:	90 e0       	ldi	r25, 0x00	; 0
     ee8:	08 c0       	rjmp	.+16     	; 0xefa <hci_transmit+0x6a>
     eea:	51 91       	ld	r21, Z+
     eec:	dc 01       	movw	r26, r24
     eee:	a3 5d       	subi	r26, 0xD3	; 211
     ef0:	bd 4f       	sbci	r27, 0xFD	; 253
     ef2:	11 96       	adiw	r26, 0x01	; 1
     ef4:	5c 93       	st	X, r21
     ef6:	11 97       	sbiw	r26, 0x01	; 1
     ef8:	01 96       	adiw	r24, 0x01	; 1
     efa:	86 17       	cp	r24, r22
     efc:	b0 f3       	brcs	.-20     	; 0xeea <hci_transmit+0x5a>
     efe:	88 e2       	ldi	r24, 0x28	; 40
     f00:	92 e0       	ldi	r25, 0x02	; 2
     f02:	0e 94 7f 05 	call	0xafe	; 0xafe <transmit>
     f06:	80 e0       	ldi	r24, 0x00	; 0
     f08:	08 95       	ret

00000f0a <hci_init>:
     f0a:	86 e5       	ldi	r24, 0x56	; 86
     f0c:	95 e0       	ldi	r25, 0x05	; 5
     f0e:	6e e9       	ldi	r22, 0x9E	; 158
     f10:	75 e0       	ldi	r23, 0x05	; 5
     f12:	0e 94 9b 07 	call	0xf36	; 0xf36 <halWT41FcUartInit>
     f16:	08 95       	ret

00000f18 <send>:
     f18:	80 93 36 01 	sts	0x0136, r24	; 0x800136 <__TEXT_REGION_LENGTH__+0x7e0136>
     f1c:	80 91 b7 02 	lds	r24, 0x02B7	; 0x8002b7 <_state>
     f20:	82 fd       	sbrc	r24, 2
     f22:	05 c0       	rjmp	.+10     	; 0xf2e <send+0x16>
     f24:	20 91 31 01 	lds	r18, 0x0131	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
     f28:	20 64       	ori	r18, 0x40	; 64
     f2a:	20 93 31 01 	sts	0x0131, r18	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
     f2e:	32 e0       	ldi	r19, 0x02	; 2
     f30:	30 93 b7 02 	sts	0x02B7, r19	; 0x8002b7 <_state>
     f34:	08 95       	ret

00000f36 <halWT41FcUartInit>:
     f36:	00 97       	sbiw	r24, 0x00	; 0
     f38:	61 f1       	breq	.+88     	; 0xf92 <halWT41FcUartInit+0x5c>
     f3a:	61 15       	cp	r22, r1
     f3c:	71 05       	cpc	r23, r1
     f3e:	59 f1       	breq	.+86     	; 0xf96 <halWT41FcUartInit+0x60>
     f40:	f8 94       	cli
     f42:	20 91 b8 02 	lds	r18, 0x02B8	; 0x8002b8 <_sndCallback>
     f46:	30 91 b9 02 	lds	r19, 0x02B9	; 0x8002b9 <_sndCallback+0x1>
     f4a:	21 15       	cp	r18, r1
     f4c:	31 05       	cpc	r19, r1
     f4e:	11 f0       	breq	.+4      	; 0xf54 <halWT41FcUartInit+0x1e>
     f50:	78 94       	sei
     f52:	1f c0       	rjmp	.+62     	; 0xf92 <halWT41FcUartInit+0x5c>
     f54:	90 93 b9 02 	sts	0x02B9, r25	; 0x8002b9 <_sndCallback+0x1>
     f58:	80 93 b8 02 	sts	0x02B8, r24	; 0x8002b8 <_sndCallback>
     f5c:	78 94       	sei
     f5e:	88 e0       	ldi	r24, 0x08	; 8
     f60:	80 93 05 01 	sts	0x0105, r24	; 0x800105 <__TEXT_REGION_LENGTH__+0x7e0105>
     f64:	88 e2       	ldi	r24, 0x28	; 40
     f66:	80 93 04 01 	sts	0x0104, r24	; 0x800104 <__TEXT_REGION_LENGTH__+0x7e0104>
     f6a:	f8 94       	cli
     f6c:	82 ee       	ldi	r24, 0xE2	; 226
     f6e:	94 e0       	ldi	r25, 0x04	; 4
     f70:	90 93 29 01 	sts	0x0129, r25	; 0x800129 <__TEXT_REGION_LENGTH__+0x7e0129>
     f74:	80 93 28 01 	sts	0x0128, r24	; 0x800128 <__TEXT_REGION_LENGTH__+0x7e0128>
     f78:	78 94       	sei
     f7a:	83 e0       	ldi	r24, 0x03	; 3
     f7c:	80 93 21 01 	sts	0x0121, r24	; 0x800121 <__TEXT_REGION_LENGTH__+0x7e0121>
     f80:	70 93 93 02 	sts	0x0293, r23	; 0x800293 <_rcvCallback+0x1>
     f84:	60 93 92 02 	sts	0x0292, r22	; 0x800292 <_rcvCallback>
     f88:	82 e0       	ldi	r24, 0x02	; 2
     f8a:	80 93 73 00 	sts	0x0073, r24	; 0x800073 <__TEXT_REGION_LENGTH__+0x7e0073>
     f8e:	80 e0       	ldi	r24, 0x00	; 0
     f90:	08 95       	ret
     f92:	81 e0       	ldi	r24, 0x01	; 1
     f94:	08 95       	ret
     f96:	81 e0       	ldi	r24, 0x01	; 1
     f98:	08 95       	ret

00000f9a <__vector_47>:
     f9a:	1f 92       	push	r1
     f9c:	0f 92       	push	r0
     f9e:	0f b6       	in	r0, 0x3f	; 63
     fa0:	0f 92       	push	r0
     fa2:	11 24       	eor	r1, r1
     fa4:	8f 93       	push	r24
     fa6:	88 e9       	ldi	r24, 0x98	; 152
     fa8:	80 93 31 01 	sts	0x0131, r24	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
     fac:	80 e2       	ldi	r24, 0x20	; 32
     fae:	80 93 05 01 	sts	0x0105, r24	; 0x800105 <__TEXT_REGION_LENGTH__+0x7e0105>
     fb2:	88 e0       	ldi	r24, 0x08	; 8
     fb4:	80 93 6c 00 	sts	0x006C, r24	; 0x80006c <__TEXT_REGION_LENGTH__+0x7e006c>
     fb8:	10 92 73 00 	sts	0x0073, r1	; 0x800073 <__TEXT_REGION_LENGTH__+0x7e0073>
     fbc:	8f 91       	pop	r24
     fbe:	0f 90       	pop	r0
     fc0:	0f be       	out	0x3f, r0	; 63
     fc2:	0f 90       	pop	r0
     fc4:	1f 90       	pop	r1
     fc6:	18 95       	reti

00000fc8 <halWT41FcUartSend>:
     fc8:	1f 93       	push	r17
     fca:	1f b7       	in	r17, 0x3f	; 63
     fcc:	f8 94       	cli
     fce:	90 91 31 01 	lds	r25, 0x0131	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
     fd2:	93 ff       	sbrs	r25, 3
     fd4:	1f c0       	rjmp	.+62     	; 0x1014 <halWT41FcUartSend+0x4c>
     fd6:	90 91 b7 02 	lds	r25, 0x02B7	; 0x8002b7 <_state>
     fda:	29 2f       	mov	r18, r25
     fdc:	30 e0       	ldi	r19, 0x00	; 0
     fde:	23 70       	andi	r18, 0x03	; 3
     fe0:	30 70       	andi	r19, 0x00	; 0
     fe2:	21 15       	cp	r18, r1
     fe4:	31 05       	cpc	r19, r1
     fe6:	b1 f4       	brne	.+44     	; 0x1014 <halWT41FcUartSend+0x4c>
     fe8:	32 e0       	ldi	r19, 0x02	; 2
     fea:	3b bb       	out	0x1b, r19	; 27
     fec:	20 91 03 01 	lds	r18, 0x0103	; 0x800103 <__TEXT_REGION_LENGTH__+0x7e0103>
     ff0:	22 ff       	sbrs	r18, 2
     ff2:	0b c0       	rjmp	.+22     	; 0x100a <halWT41FcUartSend+0x42>
     ff4:	91 60       	ori	r25, 0x01	; 1
     ff6:	90 93 b7 02 	sts	0x02B7, r25	; 0x8002b7 <_state>
     ffa:	80 93 ba 02 	sts	0x02BA, r24	; 0x8002ba <_wait>
     ffe:	80 91 68 00 	lds	r24, 0x0068	; 0x800068 <__TEXT_REGION_LENGTH__+0x7e0068>
    1002:	82 60       	ori	r24, 0x02	; 2
    1004:	80 93 68 00 	sts	0x0068, r24	; 0x800068 <__TEXT_REGION_LENGTH__+0x7e0068>
    1008:	02 c0       	rjmp	.+4      	; 0x100e <halWT41FcUartSend+0x46>
    100a:	0e 94 8c 07 	call	0xf18	; 0xf18 <send>
    100e:	1f bf       	out	0x3f, r17	; 63
    1010:	80 e0       	ldi	r24, 0x00	; 0
    1012:	02 c0       	rjmp	.+4      	; 0x1018 <halWT41FcUartSend+0x50>
    1014:	1f bf       	out	0x3f, r17	; 63
    1016:	81 e0       	ldi	r24, 0x01	; 1
    1018:	1f 91       	pop	r17
    101a:	08 95       	ret

0000101c <__vector_10>:
    101c:	1f 92       	push	r1
    101e:	0f 92       	push	r0
    1020:	0f b6       	in	r0, 0x3f	; 63
    1022:	0f 92       	push	r0
    1024:	0b b6       	in	r0, 0x3b	; 59
    1026:	0f 92       	push	r0
    1028:	11 24       	eor	r1, r1
    102a:	2f 93       	push	r18
    102c:	3f 93       	push	r19
    102e:	4f 93       	push	r20
    1030:	5f 93       	push	r21
    1032:	6f 93       	push	r22
    1034:	7f 93       	push	r23
    1036:	8f 93       	push	r24
    1038:	9f 93       	push	r25
    103a:	af 93       	push	r26
    103c:	bf 93       	push	r27
    103e:	ef 93       	push	r30
    1040:	ff 93       	push	r31
    1042:	80 91 03 01 	lds	r24, 0x0103	; 0x800103 <__TEXT_REGION_LENGTH__+0x7e0103>
    1046:	82 fd       	sbrc	r24, 2
    1048:	09 c0       	rjmp	.+18     	; 0x105c <__vector_10+0x40>
    104a:	80 91 ba 02 	lds	r24, 0x02BA	; 0x8002ba <_wait>
    104e:	0e 94 8c 07 	call	0xf18	; 0xf18 <send>
    1052:	20 91 68 00 	lds	r18, 0x0068	; 0x800068 <__TEXT_REGION_LENGTH__+0x7e0068>
    1056:	2d 7f       	andi	r18, 0xFD	; 253
    1058:	20 93 68 00 	sts	0x0068, r18	; 0x800068 <__TEXT_REGION_LENGTH__+0x7e0068>
    105c:	ff 91       	pop	r31
    105e:	ef 91       	pop	r30
    1060:	bf 91       	pop	r27
    1062:	af 91       	pop	r26
    1064:	9f 91       	pop	r25
    1066:	8f 91       	pop	r24
    1068:	7f 91       	pop	r23
    106a:	6f 91       	pop	r22
    106c:	5f 91       	pop	r21
    106e:	4f 91       	pop	r20
    1070:	3f 91       	pop	r19
    1072:	2f 91       	pop	r18
    1074:	0f 90       	pop	r0
    1076:	0b be       	out	0x3b, r0	; 59
    1078:	0f 90       	pop	r0
    107a:	0f be       	out	0x3f, r0	; 63
    107c:	0f 90       	pop	r0
    107e:	1f 90       	pop	r1
    1080:	18 95       	reti

00001082 <__vector_56>:
    1082:	1f 92       	push	r1
    1084:	0f 92       	push	r0
    1086:	0f b6       	in	r0, 0x3f	; 63
    1088:	0f 92       	push	r0
    108a:	0b b6       	in	r0, 0x3b	; 59
    108c:	0f 92       	push	r0
    108e:	11 24       	eor	r1, r1
    1090:	2f 93       	push	r18
    1092:	3f 93       	push	r19
    1094:	4f 93       	push	r20
    1096:	5f 93       	push	r21
    1098:	6f 93       	push	r22
    109a:	7f 93       	push	r23
    109c:	8f 93       	push	r24
    109e:	9f 93       	push	r25
    10a0:	af 93       	push	r26
    10a2:	bf 93       	push	r27
    10a4:	ef 93       	push	r30
    10a6:	ff 93       	push	r31
    10a8:	30 91 31 01 	lds	r19, 0x0131	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    10ac:	3f 7b       	andi	r19, 0xBF	; 191
    10ae:	30 93 31 01 	sts	0x0131, r19	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    10b2:	24 e0       	ldi	r18, 0x04	; 4
    10b4:	20 93 b7 02 	sts	0x02B7, r18	; 0x8002b7 <_state>
    10b8:	78 94       	sei
    10ba:	e0 91 b8 02 	lds	r30, 0x02B8	; 0x8002b8 <_sndCallback>
    10be:	f0 91 b9 02 	lds	r31, 0x02B9	; 0x8002b9 <_sndCallback+0x1>
    10c2:	09 95       	icall
    10c4:	f8 94       	cli
    10c6:	80 91 b7 02 	lds	r24, 0x02B7	; 0x8002b7 <_state>
    10ca:	82 30       	cpi	r24, 0x02	; 2
    10cc:	19 f0       	breq	.+6      	; 0x10d4 <__vector_56+0x52>
    10ce:	10 92 b7 02 	sts	0x02B7, r1	; 0x8002b7 <_state>
    10d2:	05 c0       	rjmp	.+10     	; 0x10de <__vector_56+0x5c>
    10d4:	40 91 31 01 	lds	r20, 0x0131	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    10d8:	40 64       	ori	r20, 0x40	; 64
    10da:	40 93 31 01 	sts	0x0131, r20	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    10de:	ff 91       	pop	r31
    10e0:	ef 91       	pop	r30
    10e2:	bf 91       	pop	r27
    10e4:	af 91       	pop	r26
    10e6:	9f 91       	pop	r25
    10e8:	8f 91       	pop	r24
    10ea:	7f 91       	pop	r23
    10ec:	6f 91       	pop	r22
    10ee:	5f 91       	pop	r21
    10f0:	4f 91       	pop	r20
    10f2:	3f 91       	pop	r19
    10f4:	2f 91       	pop	r18
    10f6:	0f 90       	pop	r0
    10f8:	0b be       	out	0x3b, r0	; 59
    10fa:	0f 90       	pop	r0
    10fc:	0f be       	out	0x3f, r0	; 63
    10fe:	0f 90       	pop	r0
    1100:	1f 90       	pop	r1
    1102:	18 95       	reti

00001104 <__vector_54>:
    1104:	1f 92       	push	r1
    1106:	0f 92       	push	r0
    1108:	0f b6       	in	r0, 0x3f	; 63
    110a:	0f 92       	push	r0
    110c:	0b b6       	in	r0, 0x3b	; 59
    110e:	0f 92       	push	r0
    1110:	11 24       	eor	r1, r1
    1112:	1f 93       	push	r17
    1114:	2f 93       	push	r18
    1116:	3f 93       	push	r19
    1118:	4f 93       	push	r20
    111a:	5f 93       	push	r21
    111c:	6f 93       	push	r22
    111e:	7f 93       	push	r23
    1120:	8f 93       	push	r24
    1122:	9f 93       	push	r25
    1124:	af 93       	push	r26
    1126:	bf 93       	push	r27
    1128:	ef 93       	push	r30
    112a:	ff 93       	push	r31
    112c:	80 91 30 01 	lds	r24, 0x0130	; 0x800130 <__TEXT_REGION_LENGTH__+0x7e0130>
    1130:	8c 71       	andi	r24, 0x1C	; 28
    1132:	11 f0       	breq	.+4      	; 0x1138 <__vector_54+0x34>
    1134:	0e 94 fe 08 	call	0x11fc	; 0x11fc <abort>
    1138:	80 91 36 01 	lds	r24, 0x0136	; 0x800136 <__TEXT_REGION_LENGTH__+0x7e0136>
    113c:	90 91 b6 02 	lds	r25, 0x02B6	; 0x8002b6 <_count.1312>
    1140:	99 23       	and	r25, r25
    1142:	59 f5       	brne	.+86     	; 0x119a <__vector_54+0x96>
    1144:	91 e0       	ldi	r25, 0x01	; 1
    1146:	90 93 b6 02 	sts	0x02B6, r25	; 0x8002b6 <_count.1312>
    114a:	10 e2       	ldi	r17, 0x20	; 32
    114c:	78 94       	sei
    114e:	e0 91 92 02 	lds	r30, 0x0292	; 0x800292 <_rcvCallback>
    1152:	f0 91 93 02 	lds	r31, 0x0293	; 0x800293 <_rcvCallback+0x1>
    1156:	09 95       	icall
    1158:	f8 94       	cli
    115a:	80 91 b6 02 	lds	r24, 0x02B6	; 0x8002b6 <_count.1312>
    115e:	81 50       	subi	r24, 0x01	; 1
    1160:	80 93 b6 02 	sts	0x02B6, r24	; 0x8002b6 <_count.1312>
    1164:	8f 31       	cpi	r24, 0x1F	; 31
    1166:	31 f4       	brne	.+12     	; 0x1174 <__vector_54+0x70>
    1168:	20 91 31 01 	lds	r18, 0x0131	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    116c:	20 68       	ori	r18, 0x80	; 128
    116e:	20 93 31 01 	sts	0x0131, r18	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    1172:	07 c0       	rjmp	.+14     	; 0x1182 <__vector_54+0x7e>
    1174:	80 31       	cpi	r24, 0x10	; 16
    1176:	19 f4       	brne	.+6      	; 0x117e <__vector_54+0x7a>
    1178:	10 93 05 01 	sts	0x0105, r17	; 0x800105 <__TEXT_REGION_LENGTH__+0x7e0105>
    117c:	02 c0       	rjmp	.+4      	; 0x1182 <__vector_54+0x7e>
    117e:	88 23       	and	r24, r24
    1180:	49 f1       	breq	.+82     	; 0x11d4 <__vector_54+0xd0>
    1182:	30 91 95 02 	lds	r19, 0x0295	; 0x800295 <_read.1314>
    1186:	e3 2f       	mov	r30, r19
    1188:	f0 e0       	ldi	r31, 0x00	; 0
    118a:	ea 56       	subi	r30, 0x6A	; 106
    118c:	fd 4f       	sbci	r31, 0xFD	; 253
    118e:	80 81       	ld	r24, Z
    1190:	3f 5f       	subi	r19, 0xFF	; 255
    1192:	3f 71       	andi	r19, 0x1F	; 31
    1194:	30 93 95 02 	sts	0x0295, r19	; 0x800295 <_read.1314>
    1198:	d9 cf       	rjmp	.-78     	; 0x114c <__vector_54+0x48>
    119a:	19 2f       	mov	r17, r25
    119c:	1f 5f       	subi	r17, 0xFF	; 255
    119e:	10 93 b6 02 	sts	0x02B6, r17	; 0x8002b6 <_count.1312>
    11a2:	90 32       	cpi	r25, 0x20	; 32
    11a4:	31 f4       	brne	.+12     	; 0x11b2 <__vector_54+0xae>
    11a6:	40 91 31 01 	lds	r20, 0x0131	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    11aa:	4f 77       	andi	r20, 0x7F	; 127
    11ac:	40 93 31 01 	sts	0x0131, r20	; 0x800131 <__TEXT_REGION_LENGTH__+0x7e0131>
    11b0:	05 c0       	rjmp	.+10     	; 0x11bc <__vector_54+0xb8>
    11b2:	98 31       	cpi	r25, 0x18	; 24
    11b4:	19 f4       	brne	.+6      	; 0x11bc <__vector_54+0xb8>
    11b6:	58 e2       	ldi	r21, 0x28	; 40
    11b8:	50 93 05 01 	sts	0x0105, r21	; 0x800105 <__TEXT_REGION_LENGTH__+0x7e0105>
    11bc:	70 91 94 02 	lds	r23, 0x0294	; 0x800294 <_write.1315>
    11c0:	e7 2f       	mov	r30, r23
    11c2:	f0 e0       	ldi	r31, 0x00	; 0
    11c4:	ea 56       	subi	r30, 0x6A	; 106
    11c6:	fd 4f       	sbci	r31, 0xFD	; 253
    11c8:	80 83       	st	Z, r24
    11ca:	67 2f       	mov	r22, r23
    11cc:	6f 5f       	subi	r22, 0xFF	; 255
    11ce:	6f 71       	andi	r22, 0x1F	; 31
    11d0:	60 93 94 02 	sts	0x0294, r22	; 0x800294 <_write.1315>
    11d4:	ff 91       	pop	r31
    11d6:	ef 91       	pop	r30
    11d8:	bf 91       	pop	r27
    11da:	af 91       	pop	r26
    11dc:	9f 91       	pop	r25
    11de:	8f 91       	pop	r24
    11e0:	7f 91       	pop	r23
    11e2:	6f 91       	pop	r22
    11e4:	5f 91       	pop	r21
    11e6:	4f 91       	pop	r20
    11e8:	3f 91       	pop	r19
    11ea:	2f 91       	pop	r18
    11ec:	1f 91       	pop	r17
    11ee:	0f 90       	pop	r0
    11f0:	0b be       	out	0x3b, r0	; 59
    11f2:	0f 90       	pop	r0
    11f4:	0f be       	out	0x3f, r0	; 63
    11f6:	0f 90       	pop	r0
    11f8:	1f 90       	pop	r1
    11fa:	18 95       	reti

000011fc <abort>:
    11fc:	81 e0       	ldi	r24, 0x01	; 1
    11fe:	90 e0       	ldi	r25, 0x00	; 0
    1200:	f8 94       	cli
    1202:	0c 94 03 09 	jmp	0x1206	; 0x1206 <_exit>

00001206 <_exit>:
    1206:	f8 94       	cli

00001208 <__stop_program>:
    1208:	ff cf       	rjmp	.-2      	; 0x1208 <__stop_program>
