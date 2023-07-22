	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_get_string                     ; -- Begin function get_string
	.p2align	2
_get_string:                            ; @get_string
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #128
	.cfi_def_cfa_offset 128
	stp	x29, x30, [sp, #112]            ; 16-byte Folded Spill
	add	x29, sp, #112
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stdinp@GOTPAGE
	ldr	x8, [x8, ___stdinp@GOTPAGEOFF]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
	stur	x0, [x29, #-16]
	stur	x1, [x29, #-24]
	adrp	x8, _allocations@PAGE
	ldr	x8, [x8, _allocations@PAGEOFF]
	mov	x9, #2305843009213693951
	subs	x8, x8, x9
	cset	w8, ne
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_2:
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-32]
	stur	xzr, [x29, #-40]
	stur	xzr, [x29, #-48]
	ldur	x8, [x29, #-24]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_7
	b	LBB0_3
LBB0_3:
	ldur	x8, [x29, #-16]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:
	add	x9, sp, #48
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB0_6
LBB0_5:
	ldur	x8, [x29, #-16]
	ldr	x8, [x8]
	str	x8, [sp, #48]
	b	LBB0_6
LBB0_6:
	ldur	x0, [x29, #-24]
	ldr	x1, [sp, #48]
	bl	_vprintf
	b	LBB0_7
LBB0_7:
	b	LBB0_8
LBB0_8:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x0, [x8]
	bl	_fgetc
	stur	w0, [x29, #-52]
	subs	w8, w0, #13
	cset	w8, eq
	mov	w9, #0
	str	w9, [sp, #12]                   ; 4-byte Folded Spill
	tbnz	w8, #0, LBB0_11
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_8 Depth=1
	ldur	w8, [x29, #-52]
	subs	w8, w8, #10
	cset	w8, eq
	mov	w9, #0
	str	w9, [sp, #12]                   ; 4-byte Folded Spill
	tbnz	w8, #0, LBB0_11
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_8 Depth=1
	ldur	w8, [x29, #-52]
	adds	w8, w8, #1
	cset	w8, ne
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	b	LBB0_11
LBB0_11:                                ;   in Loop: Header=BB0_8 Depth=1
	ldr	w8, [sp, #12]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB0_20
	b	LBB0_12
LBB0_12:                                ;   in Loop: Header=BB0_8 Depth=1
	ldur	x8, [x29, #-48]
	add	x8, x8, #1
	ldur	x9, [x29, #-40]
	subs	x8, x8, x9
	cset	w8, ls
	tbnz	w8, #0, LBB0_19
	b	LBB0_13
LBB0_13:                                ;   in Loop: Header=BB0_8 Depth=1
	ldur	x8, [x29, #-40]
	adds	x8, x8, #1
	cset	w8, hs
	tbnz	w8, #0, LBB0_15
	b	LBB0_14
LBB0_14:                                ;   in Loop: Header=BB0_8 Depth=1
	ldur	x8, [x29, #-40]
	add	x8, x8, #1
	stur	x8, [x29, #-40]
	b	LBB0_16
LBB0_15:
	ldur	x0, [x29, #-32]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_16:                                ;   in Loop: Header=BB0_8 Depth=1
	ldur	x0, [x29, #-32]
	ldur	x1, [x29, #-40]
	bl	_realloc
	str	x0, [sp, #40]
	ldr	x8, [sp, #40]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_18
	b	LBB0_17
LBB0_17:
	ldur	x0, [x29, #-32]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_18:                                ;   in Loop: Header=BB0_8 Depth=1
	ldr	x8, [sp, #40]
	stur	x8, [x29, #-32]
	b	LBB0_19
LBB0_19:                                ;   in Loop: Header=BB0_8 Depth=1
	ldur	w8, [x29, #-52]
	ldur	x9, [x29, #-32]
	ldur	x10, [x29, #-48]
	add	x11, x10, #1
	stur	x11, [x29, #-48]
	strb	w8, [x9, x10]
	b	LBB0_8
LBB0_20:
	ldur	x8, [x29, #-48]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_23
	b	LBB0_21
LBB0_21:
	ldur	w8, [x29, #-52]
	adds	w8, w8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB0_23
	b	LBB0_22
LBB0_22:
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_23:
	ldur	x8, [x29, #-48]
	adds	x8, x8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB0_25
	b	LBB0_24
LBB0_24:
	ldur	x0, [x29, #-32]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_25:
	ldur	w8, [x29, #-52]
	subs	w8, w8, #13
	cset	w8, ne
	tbnz	w8, #0, LBB0_31
	b	LBB0_26
LBB0_26:
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x0, [x8]
	bl	_fgetc
	stur	w0, [x29, #-52]
	subs	w8, w0, #10
	cset	w8, eq
	tbnz	w8, #0, LBB0_31
	b	LBB0_27
LBB0_27:
	ldur	w8, [x29, #-52]
	adds	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB0_30
	b	LBB0_28
LBB0_28:
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	ldur	w0, [x29, #-52]
	ldr	x1, [x8]
	bl	_ungetc
	adds	w8, w0, #1
	cset	w8, ne
	tbnz	w8, #0, LBB0_30
	b	LBB0_29
LBB0_29:
	ldur	x0, [x29, #-32]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_30:
	b	LBB0_31
LBB0_31:
	ldur	x0, [x29, #-32]
	ldur	x8, [x29, #-48]
	add	x1, x8, #1
	bl	_realloc
	str	x0, [sp, #32]
	ldr	x8, [sp, #32]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_33
	b	LBB0_32
LBB0_32:
	ldur	x0, [x29, #-32]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_33:
	ldr	x8, [sp, #32]
	ldur	x9, [x29, #-48]
	add	x8, x8, x9
	strb	wzr, [x8]
	adrp	x8, _strings@PAGE
	ldr	x0, [x8, _strings@PAGEOFF]
	adrp	x8, _allocations@PAGE
	ldr	x8, [x8, _allocations@PAGEOFF]
	add	x9, x8, #1
	mov	x8, #8
	mul	x1, x8, x9
	bl	_realloc
	str	x0, [sp, #24]
	ldr	x8, [sp, #24]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_35
	b	LBB0_34
LBB0_34:
	ldr	x0, [sp, #32]
	bl	_free
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_36
LBB0_35:
	ldr	x8, [sp, #24]
	adrp	x9, _strings@PAGE
	str	x8, [x9, _strings@PAGEOFF]
	ldr	x8, [sp, #32]
	ldr	x10, [x9, _strings@PAGEOFF]
	adrp	x9, _allocations@PAGE
	ldr	x11, [x9, _allocations@PAGEOFF]
	str	x8, [x10, x11, lsl #3]
	ldr	x8, [x9, _allocations@PAGEOFF]
	add	x8, x8, #1
	str	x8, [x9, _allocations@PAGEOFF]
	ldr	x8, [sp, #32]
	stur	x8, [x29, #-8]
	b	LBB0_36
LBB0_36:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #112]            ; 16-byte Folded Reload
	add	sp, sp, #128
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_char                       ; -- Begin function get_char
	.p2align	2
_get_char:                              ; @get_char
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	.cfi_def_cfa_offset 80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	sub	x9, x29, #24
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x1, [x29, #-16]
	sub	x0, x29, #24
	bl	_get_string
	str	x0, [sp, #32]
	ldr	x8, [sp, #32]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB1_3
	b	LBB1_2
LBB1_2:
	mov	w8, #127
	sturb	w8, [x29, #-1]
	b	LBB1_6
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x0, [sp, #32]
	mov	x9, sp
	add	x8, sp, #31
	str	x8, [x9]
	add	x8, sp, #30
	str	x8, [x9, #8]
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	bl	_sscanf
	subs	w8, w0, #1
	cset	w8, ne
	tbnz	w8, #0, LBB1_5
	b	LBB1_4
LBB1_4:
	ldrb	w8, [sp, #31]
	sturb	w8, [x29, #-1]
	b	LBB1_6
LBB1_5:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_1
LBB1_6:
	ldursb	w0, [x29, #-1]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3                               ; -- Begin function get_double
lCPI2_0:
	.quad	0x7fefffffffffffff              ; double 1.7976931348623157E+308
lCPI2_1:
	.quad	0x7ff0000000000000              ; double +Inf
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_get_double
	.p2align	2
_get_double:                            ; @get_double
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	.cfi_def_cfa_offset 96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-24]
	sub	x9, x29, #32
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x1, [x29, #-24]
	sub	x0, x29, #32
	bl	_get_string
	str	x0, [sp, #40]
	ldr	x8, [sp, #40]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_3
	b	LBB2_2
LBB2_2:
	adrp	x8, lCPI2_0@PAGE
	ldr	d0, [x8, lCPI2_0@PAGEOFF]
	stur	d0, [x29, #-16]
	b	LBB2_16
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x0, [sp, #40]
	bl	_strlen
	subs	x8, x0, #0
	cset	w8, ls
	tbnz	w8, #0, LBB2_15
	b	LBB2_4
LBB2_4:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #40]
	ldrb	w0, [x8]
	bl	_isspace
	subs	w8, w0, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_15
	b	LBB2_5
LBB2_5:                                 ;   in Loop: Header=BB2_1 Depth=1
	bl	___error
	str	wzr, [x0]
	ldr	x0, [sp, #40]
	add	x1, sp, #32
	bl	_strtod
	str	d0, [sp, #24]
	bl	___error
	ldr	w8, [x0]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_14
	b	LBB2_6
LBB2_6:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_14
	b	LBB2_7
LBB2_7:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	d0, [sp, #24]
	stur	d0, [x29, #-8]
	ldur	d0, [x29, #-8]
	ldur	d1, [x29, #-8]
	fcmp	d0, d1
	cset	w8, ne
	mov	w9, #0
	str	w9, [sp, #20]                   ; 4-byte Folded Spill
	tbnz	w8, #0, LBB2_9
	b	LBB2_8
LBB2_8:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldur	d0, [x29, #-8]
	fabs	d0, d0
	adrp	x8, lCPI2_1@PAGE
	ldr	d1, [x8, lCPI2_1@PAGEOFF]
	fcmp	d0, d1
	cset	w8, ne
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	b	LBB2_9
LBB2_9:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #20]                   ; 4-byte Folded Reload
	ands	w8, w8, #0x1
	cset	w8, eq
	tbnz	w8, #0, LBB2_14
	b	LBB2_10
LBB2_10:                                ;   in Loop: Header=BB2_1 Depth=1
	ldr	d0, [sp, #24]
	adrp	x8, lCPI2_0@PAGE
	ldr	d1, [x8, lCPI2_0@PAGEOFF]
	fcmp	d0, d1
	cset	w8, pl
	tbnz	w8, #0, LBB2_14
	b	LBB2_11
LBB2_11:                                ;   in Loop: Header=BB2_1 Depth=1
	ldr	x0, [sp, #40]
	adrp	x1, l_.str.1@PAGE
	add	x1, x1, l_.str.1@PAGEOFF
	bl	_strcspn
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldr	x0, [sp, #40]
	bl	_strlen
	mov	x8, x0
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x0, x8
	cset	w8, ne
	tbnz	w8, #0, LBB2_13
	b	LBB2_12
LBB2_12:
	ldr	d0, [sp, #24]
	stur	d0, [x29, #-16]
	b	LBB2_16
LBB2_13:                                ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_14
LBB2_14:                                ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_15
LBB2_15:                                ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_1
LBB2_16:
	ldur	d0, [x29, #-16]
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_float                      ; -- Begin function get_float
	.p2align	2
_get_float:                             ; @get_float
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	.cfi_def_cfa_offset 80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	sub	x9, x29, #24
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x1, [x29, #-16]
	sub	x0, x29, #24
	bl	_get_string
	str	x0, [sp, #32]
	ldr	x8, [sp, #32]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB3_3
	b	LBB3_2
LBB3_2:
	mov	w8, #2139095039
	fmov	s0, w8
	stur	s0, [x29, #-8]
	b	LBB3_16
LBB3_3:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x0, [sp, #32]
	bl	_strlen
	subs	x8, x0, #0
	cset	w8, ls
	tbnz	w8, #0, LBB3_15
	b	LBB3_4
LBB3_4:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrb	w0, [x8]
	bl	_isspace
	subs	w8, w0, #0
	cset	w8, ne
	tbnz	w8, #0, LBB3_15
	b	LBB3_5
LBB3_5:                                 ;   in Loop: Header=BB3_1 Depth=1
	bl	___error
	str	wzr, [x0]
	ldr	x0, [sp, #32]
	add	x1, sp, #24
	bl	_strtof
	str	s0, [sp, #20]
	bl	___error
	ldr	w8, [x0]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB3_14
	b	LBB3_6
LBB3_6:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	ldrsb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB3_14
	b	LBB3_7
LBB3_7:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	s0, [sp, #20]
	stur	s0, [x29, #-4]
	ldur	s0, [x29, #-4]
	ldur	s1, [x29, #-4]
	fcmp	s0, s1
	cset	w8, ne
	mov	w9, #0
	str	w9, [sp, #16]                   ; 4-byte Folded Spill
	tbnz	w8, #0, LBB3_9
	b	LBB3_8
LBB3_8:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldur	s0, [x29, #-4]
	fabs	s0, s0
	mov	w8, #2139095040
	fmov	s1, w8
	fcmp	s0, s1
	cset	w8, ne
	str	w8, [sp, #16]                   ; 4-byte Folded Spill
	b	LBB3_9
LBB3_9:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #16]                   ; 4-byte Folded Reload
	ands	w8, w8, #0x1
	cset	w8, eq
	tbnz	w8, #0, LBB3_14
	b	LBB3_10
LBB3_10:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	s0, [sp, #20]
	mov	w8, #2139095039
	fmov	s1, w8
	fcmp	s0, s1
	cset	w8, pl
	tbnz	w8, #0, LBB3_14
	b	LBB3_11
LBB3_11:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	x0, [sp, #32]
	adrp	x1, l_.str.1@PAGE
	add	x1, x1, l_.str.1@PAGEOFF
	bl	_strcspn
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	ldr	x0, [sp, #32]
	bl	_strlen
	mov	x8, x0
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x0, x8
	cset	w8, ne
	tbnz	w8, #0, LBB3_13
	b	LBB3_12
LBB3_12:
	ldr	s0, [sp, #20]
	stur	s0, [x29, #-8]
	b	LBB3_16
LBB3_13:                                ;   in Loop: Header=BB3_1 Depth=1
	b	LBB3_14
LBB3_14:                                ;   in Loop: Header=BB3_1 Depth=1
	b	LBB3_15
LBB3_15:                                ;   in Loop: Header=BB3_1 Depth=1
	b	LBB3_1
LBB3_16:
	ldur	s0, [x29, #-8]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_int                        ; -- Begin function get_int
	.p2align	2
_get_int:                               ; @get_int
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	add	x9, sp, #24
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB4_1
LBB4_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x1, [x29, #-16]
	add	x0, sp, #24
	bl	_get_string
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB4_3
	b	LBB4_2
LBB4_2:
	mov	w8, #2147483647
	stur	w8, [x29, #-4]
	b	LBB4_12
LBB4_3:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	x0, [sp, #16]
	bl	_strlen
	subs	x8, x0, #0
	cset	w8, ls
	tbnz	w8, #0, LBB4_11
	b	LBB4_4
LBB4_4:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	x8, [sp, #16]
	ldrb	w0, [x8]
	bl	_isspace
	subs	w8, w0, #0
	cset	w8, ne
	tbnz	w8, #0, LBB4_11
	b	LBB4_5
LBB4_5:                                 ;   in Loop: Header=BB4_1 Depth=1
	bl	___error
	str	wzr, [x0]
	ldr	x0, [sp, #16]
	add	x1, sp, #8
	mov	w2, #10
	bl	_strtol
	str	x0, [sp]
	bl	___error
	ldr	w8, [x0]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB4_10
	b	LBB4_6
LBB4_6:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	x8, [sp, #8]
	ldrsb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB4_10
	b	LBB4_7
LBB4_7:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	x8, [sp]
	mov	x9, #-2147483648
	subs	x8, x8, x9
	cset	w8, lt
	tbnz	w8, #0, LBB4_10
	b	LBB4_8
LBB4_8:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	x8, [sp]
	mov	x9, #2147483647
	subs	x8, x8, x9
	cset	w8, ge
	tbnz	w8, #0, LBB4_10
	b	LBB4_9
LBB4_9:
	ldr	x8, [sp]
                                        ; kill: def $w8 killed $w8 killed $x8
	stur	w8, [x29, #-4]
	b	LBB4_12
LBB4_10:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_11
LBB4_11:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_1
LBB4_12:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_long                       ; -- Begin function get_long
	.p2align	2
_get_long:                              ; @get_long
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	add	x9, sp, #24
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB5_1
LBB5_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x1, [x29, #-16]
	add	x0, sp, #24
	bl	_get_string
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB5_3
	b	LBB5_2
LBB5_2:
	mov	x8, #9223372036854775807
	stur	x8, [x29, #-8]
	b	LBB5_11
LBB5_3:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x0, [sp, #16]
	bl	_strlen
	subs	x8, x0, #0
	cset	w8, ls
	tbnz	w8, #0, LBB5_10
	b	LBB5_4
LBB5_4:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #16]
	ldrb	w0, [x8]
	bl	_isspace
	subs	w8, w0, #0
	cset	w8, ne
	tbnz	w8, #0, LBB5_10
	b	LBB5_5
LBB5_5:                                 ;   in Loop: Header=BB5_1 Depth=1
	bl	___error
	str	wzr, [x0]
	ldr	x0, [sp, #16]
	add	x1, sp, #8
	mov	w2, #10
	bl	_strtol
	str	x0, [sp]
	bl	___error
	ldr	w8, [x0]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB5_9
	b	LBB5_6
LBB5_6:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #8]
	ldrsb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB5_9
	b	LBB5_7
LBB5_7:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp]
	mov	x9, #9223372036854775807
	subs	x8, x8, x9
	cset	w8, ge
	tbnz	w8, #0, LBB5_9
	b	LBB5_8
LBB5_8:
	ldr	x8, [sp]
	stur	x8, [x29, #-8]
	b	LBB5_11
LBB5_9:                                 ;   in Loop: Header=BB5_1 Depth=1
	b	LBB5_10
LBB5_10:                                ;   in Loop: Header=BB5_1 Depth=1
	b	LBB5_1
LBB5_11:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_long_long                  ; -- Begin function get_long_long
	.p2align	2
_get_long_long:                         ; @get_long_long
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	add	x9, sp, #24
	add	x8, x29, #16
	str	x8, [x9]
	b	LBB6_1
LBB6_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	x1, [x29, #-16]
	add	x0, sp, #24
	bl	_get_string
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	subs	x8, x8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB6_3
	b	LBB6_2
LBB6_2:
	mov	x8, #9223372036854775807
	stur	x8, [x29, #-8]
	b	LBB6_11
LBB6_3:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x0, [sp, #16]
	bl	_strlen
	subs	x8, x0, #0
	cset	w8, ls
	tbnz	w8, #0, LBB6_10
	b	LBB6_4
LBB6_4:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x8, [sp, #16]
	ldrb	w0, [x8]
	bl	_isspace
	subs	w8, w0, #0
	cset	w8, ne
	tbnz	w8, #0, LBB6_10
	b	LBB6_5
LBB6_5:                                 ;   in Loop: Header=BB6_1 Depth=1
	bl	___error
	str	wzr, [x0]
	ldr	x0, [sp, #16]
	add	x1, sp, #8
	mov	w2, #10
	bl	_strtoll
	str	x0, [sp]
	bl	___error
	ldr	w8, [x0]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB6_9
	b	LBB6_6
LBB6_6:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x8, [sp, #8]
	ldrsb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB6_9
	b	LBB6_7
LBB6_7:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x8, [sp]
	mov	x9, #9223372036854775807
	subs	x8, x8, x9
	cset	w8, ge
	tbnz	w8, #0, LBB6_9
	b	LBB6_8
LBB6_8:
	ldr	x8, [sp]
	stur	x8, [x29, #-8]
	b	LBB6_11
LBB6_9:                                 ;   in Loop: Header=BB6_1 Depth=1
	b	LBB6_10
LBB6_10:                                ;   in Loop: Header=BB6_1 Depth=1
	b	LBB6_1
LBB6_11:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function setup
_setup:                                 ; @setup
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stdoutp@GOTPAGE
	ldr	x8, [x8, ___stdoutp@GOTPAGEOFF]
	ldr	x0, [x8]
	mov	x1, #0
	mov	w2, #2
	mov	x3, #0
	bl	_setvbuf
	adrp	x0, _teardown@PAGE
	add	x0, x0, _teardown@PAGEOFF
	bl	_atexit
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function teardown
_teardown:                              ; @teardown
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, _strings@PAGE
	ldr	x8, [x8, _strings@PAGEOFF]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB8_6
	b	LBB8_1
LBB8_1:
	str	xzr, [sp, #8]
	b	LBB8_2
LBB8_2:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #8]
	adrp	x9, _allocations@PAGE
	ldr	x9, [x9, _allocations@PAGEOFF]
	subs	x8, x8, x9
	cset	w8, hs
	tbnz	w8, #0, LBB8_5
	b	LBB8_3
LBB8_3:                                 ;   in Loop: Header=BB8_2 Depth=1
	adrp	x8, _strings@PAGE
	ldr	x8, [x8, _strings@PAGEOFF]
	ldr	x9, [sp, #8]
	ldr	x0, [x8, x9, lsl #3]
	bl	_free
	b	LBB8_4
LBB8_4:                                 ;   in Loop: Header=BB8_2 Depth=1
	ldr	x8, [sp, #8]
	add	x8, x8, #1
	str	x8, [sp, #8]
	b	LBB8_2
LBB8_5:
	adrp	x8, _strings@PAGE
	ldr	x0, [x8, _strings@PAGEOFF]
	bl	_free
	b	LBB8_6
LBB8_6:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x0, #0
	adrp	x1, l_.str.2@PAGE
	add	x1, x1, l_.str.2@PAGEOFF
	bl	_get_string
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
.zerofill __DATA,__bss,_allocations,8,3 ; @allocations
.zerofill __DATA,__bss,_strings,8,3     ; @strings
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%c%c"

l_.str.1:                               ; @.str.1
	.asciz	"XxEePp"

l_.str.2:                               ; @.str.2
	.asciz	"What's your name? "

l_.str.3:                               ; @.str.3
	.asciz	"Hello, %s\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	_setup
.subsections_via_symbols
