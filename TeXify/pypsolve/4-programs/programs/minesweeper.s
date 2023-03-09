	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_print_board                    ; -- Begin function print_board
	.p2align	2
_print_board:                           ; @print_board
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	stur	wzr, [x29, #-4]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-4]
	subs	w8, w8, #10
	b.ge	LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w9, [x29, #-4]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-4]
	add	w8, w8, #1
	stur	w8, [x29, #-4]
	b	LBB0_1
LBB0_4:
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	stur	wzr, [x29, #-8]
	b	LBB0_5
LBB0_5:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_7 Depth 2
	ldur	w8, [x29, #-8]
	subs	w8, w8, #10
	b.ge	LBB0_18
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_5 Depth=1
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	stur	wzr, [x29, #-12]
	b	LBB0_7
LBB0_7:                                 ;   Parent Loop BB0_5 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	w8, [x29, #-12]
	subs	w8, w8, #10
	b.ge	LBB0_16
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_7 Depth=2
	ldursw	x8, [x29, #-8]
	mov	x9, #40
	mul	x9, x8, x9
	adrp	x8, _revealed@GOTPAGE
	ldr	x8, [x8, _revealed@GOTPAGEOFF]
	add	x8, x8, x9
	ldursw	x9, [x29, #-12]
	ldr	w8, [x8, x9, lsl #2]
	cbz	w8, LBB0_13
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_7 Depth=2
	ldursw	x8, [x29, #-8]
	mov	x9, #40
	mul	x9, x8, x9
	adrp	x8, _board@GOTPAGE
	ldr	x8, [x8, _board@GOTPAGEOFF]
	add	x8, x8, x9
	ldursw	x9, [x29, #-12]
	ldr	w8, [x8, x9, lsl #2]
	adds	w8, w8, #1
	b.ne	LBB0_11
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_7 Depth=2
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	b	LBB0_12
LBB0_11:                                ;   in Loop: Header=BB0_7 Depth=2
	ldursw	x8, [x29, #-8]
	mov	x9, #40
	mul	x9, x8, x9
	adrp	x8, _board@GOTPAGE
	ldr	x8, [x8, _board@GOTPAGEOFF]
	add	x8, x8, x9
	ldursw	x9, [x29, #-12]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	b	LBB0_12
LBB0_12:                                ;   in Loop: Header=BB0_7 Depth=2
	b	LBB0_14
LBB0_13:                                ;   in Loop: Header=BB0_7 Depth=2
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB0_14
LBB0_14:                                ;   in Loop: Header=BB0_7 Depth=2
	b	LBB0_15
LBB0_15:                                ;   in Loop: Header=BB0_7 Depth=2
	ldur	w8, [x29, #-12]
	add	w8, w8, #1
	stur	w8, [x29, #-12]
	b	LBB0_7
LBB0_16:                                ;   in Loop: Header=BB0_5 Depth=1
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	b	LBB0_17
LBB0_17:                                ;   in Loop: Header=BB0_5 Depth=1
	ldur	w8, [x29, #-8]
	add	w8, w8, #1
	stur	w8, [x29, #-8]
	b	LBB0_5
LBB0_18:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_reveal_cell                    ; -- Begin function reveal_cell
	.p2align	2
_reveal_cell:                           ; @reveal_cell
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	str	w1, [sp, #8]
	ldursw	x8, [x29, #-4]
	mov	x9, #40
	mul	x9, x8, x9
	adrp	x8, _revealed@GOTPAGE
	ldr	x8, [x8, _revealed@GOTPAGEOFF]
	add	x8, x8, x9
	ldrsw	x9, [sp, #8]
	ldr	w8, [x8, x9, lsl #2]
	cbz	w8, LBB1_2
	b	LBB1_1
LBB1_1:
	b	LBB1_14
LBB1_2:
	ldursw	x8, [x29, #-4]
	mov	x9, #40
	mul	x10, x8, x9
	adrp	x8, _revealed@GOTPAGE
	ldr	x8, [x8, _revealed@GOTPAGEOFF]
	add	x10, x8, x10
	ldrsw	x11, [sp, #8]
	mov	w8, #1
	str	w8, [x10, x11, lsl #2]
	ldursw	x8, [x29, #-4]
	mul	x9, x8, x9
	adrp	x8, _board@GOTPAGE
	ldr	x8, [x8, _board@GOTPAGEOFF]
	add	x8, x8, x9
	ldrsw	x9, [sp, #8]
	ldr	w8, [x8, x9, lsl #2]
	adds	w8, w8, #1
	b.ne	LBB1_4
	b	LBB1_3
LBB1_3:
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	mov	w0, #0
	bl	_exit
LBB1_4:
	ldursw	x8, [x29, #-4]
	mov	x9, #40
	mul	x9, x8, x9
	adrp	x8, _board@GOTPAGE
	ldr	x8, [x8, _board@GOTPAGEOFF]
	add	x8, x8, x9
	ldrsw	x9, [sp, #8]
	ldr	w8, [x8, x9, lsl #2]
	cbnz	w8, LBB1_14
	b	LBB1_5
LBB1_5:
	ldur	w8, [x29, #-4]
	subs	w8, w8, #0
	b.le	LBB1_7
	b	LBB1_6
LBB1_6:
	ldur	w8, [x29, #-4]
	subs	w0, w8, #1
	ldr	w1, [sp, #8]
	bl	_reveal_cell
	b	LBB1_7
LBB1_7:
	ldur	w8, [x29, #-4]
	subs	w8, w8, #9
	b.ge	LBB1_9
	b	LBB1_8
LBB1_8:
	ldur	w8, [x29, #-4]
	add	w0, w8, #1
	ldr	w1, [sp, #8]
	bl	_reveal_cell
	b	LBB1_9
LBB1_9:
	ldr	w8, [sp, #8]
	subs	w8, w8, #0
	b.le	LBB1_11
	b	LBB1_10
LBB1_10:
	ldur	w0, [x29, #-4]
	ldr	w8, [sp, #8]
	subs	w1, w8, #1
	bl	_reveal_cell
	b	LBB1_11
LBB1_11:
	ldr	w8, [sp, #8]
	subs	w8, w8, #9
	b.ge	LBB1_13
	b	LBB1_12
LBB1_12:
	ldur	w0, [x29, #-4]
	ldr	w8, [sp, #8]
	add	w1, w8, #1
	bl	_reveal_cell
	b	LBB1_13
LBB1_13:
	b	LBB1_14
LBB1_14:
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
	sub	sp, sp, #112
	stp	x29, x30, [sp, #96]             ; 16-byte Folded Spill
	add	x29, sp, #96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, _board@GOTPAGE
	ldr	x8, [x8, _board@GOTPAGEOFF]
	str	x8, [sp, #32]                   ; 8-byte Folded Spill
	stur	wzr, [x29, #-4]
	stur	wzr, [x29, #-8]
	b	LBB2_1
LBB2_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB2_3 Depth 2
	ldur	w8, [x29, #-8]
	subs	w8, w8, #10
	b.ge	LBB2_8
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	stur	wzr, [x29, #-12]
	b	LBB2_3
LBB2_3:                                 ;   Parent Loop BB2_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	w8, [x29, #-12]
	subs	w8, w8, #10
	b.ge	LBB2_6
	b	LBB2_4
LBB2_4:                                 ;   in Loop: Header=BB2_3 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x9, [x29, #-8]
	mov	x10, #40
	mul	x9, x9, x10
	add	x9, x8, x9
	ldursw	x10, [x29, #-12]
	mov	w8, #0
	str	w8, [x9, x10, lsl #2]
	b	LBB2_5
LBB2_5:                                 ;   in Loop: Header=BB2_3 Depth=2
	ldur	w8, [x29, #-12]
	add	w8, w8, #1
	stur	w8, [x29, #-12]
	b	LBB2_3
LBB2_6:                                 ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_7
LBB2_7:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldur	w8, [x29, #-8]
	add	w8, w8, #1
	stur	w8, [x29, #-8]
	b	LBB2_1
LBB2_8:
	mov	x0, #0
	bl	_time
                                        ; kill: def $w0 killed $w0 killed $x0
	bl	_srand
	stur	wzr, [x29, #-16]
	b	LBB2_9
LBB2_9:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-16]
	subs	w8, w8, #10
	b.ge	LBB2_13
	b	LBB2_10
LBB2_10:                                ;   in Loop: Header=BB2_9 Depth=1
	bl	_rand
	mov	w9, #10
	str	w9, [sp, #28]                   ; 4-byte Folded Spill
	sdiv	w8, w0, w9
	mul	w8, w8, w9
	subs	w8, w0, w8
	stur	w8, [x29, #-20]
	bl	_rand
	ldr	w10, [sp, #28]                  ; 4-byte Folded Reload
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	sdiv	w9, w0, w10
	mul	w9, w9, w10
	subs	w9, w0, w9
	stur	w9, [x29, #-24]
	ldursw	x9, [x29, #-20]
	mov	x10, #40
	mul	x9, x9, x10
	add	x8, x8, x9
	ldursw	x9, [x29, #-24]
	ldr	w8, [x8, x9, lsl #2]
	adds	w8, w8, #1
	b.eq	LBB2_12
	b	LBB2_11
LBB2_11:                                ;   in Loop: Header=BB2_9 Depth=1
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x9, [x29, #-20]
	mov	x10, #40
	mul	x9, x9, x10
	add	x9, x8, x9
	ldursw	x10, [x29, #-24]
	mov	w8, #-1
	str	w8, [x9, x10, lsl #2]
	ldur	w8, [x29, #-16]
	add	w8, w8, #1
	stur	w8, [x29, #-16]
	b	LBB2_12
LBB2_12:                                ;   in Loop: Header=BB2_9 Depth=1
	b	LBB2_9
LBB2_13:
	stur	wzr, [x29, #-28]
	b	LBB2_14
LBB2_14:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB2_16 Depth 2
	ldur	w8, [x29, #-28]
	subs	w8, w8, #10
	b.ge	LBB2_35
	b	LBB2_15
LBB2_15:                                ;   in Loop: Header=BB2_14 Depth=1
	stur	wzr, [x29, #-32]
	b	LBB2_16
LBB2_16:                                ;   Parent Loop BB2_14 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	w8, [x29, #-32]
	subs	w8, w8, #10
	b.ge	LBB2_33
	b	LBB2_17
LBB2_17:                                ;   in Loop: Header=BB2_16 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x9, [x29, #-28]
	mov	x10, #40
	mul	x9, x9, x10
	add	x8, x8, x9
	ldursw	x9, [x29, #-32]
	ldr	w8, [x8, x9, lsl #2]
	adds	w8, w8, #1
	b.eq	LBB2_31
	b	LBB2_18
LBB2_18:                                ;   in Loop: Header=BB2_16 Depth=2
	stur	wzr, [x29, #-36]
	ldur	w8, [x29, #-28]
	subs	w8, w8, #0
	b.le	LBB2_21
	b	LBB2_19
LBB2_19:                                ;   in Loop: Header=BB2_16 Depth=2
	ldr	x10, [sp, #32]                  ; 8-byte Folded Reload
	ldur	w8, [x29, #-28]
	subs	w8, w8, #1
	mov	w9, #40
	smaddl	x8, w8, w9, x10
	ldursw	x9, [x29, #-32]
	ldr	w8, [x8, x9, lsl #2]
	adds	w8, w8, #1
	b.ne	LBB2_21
	b	LBB2_20
LBB2_20:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB2_21
LBB2_21:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-28]
	subs	w8, w8, #9
	b.ge	LBB2_24
	b	LBB2_22
LBB2_22:                                ;   in Loop: Header=BB2_16 Depth=2
	ldr	x10, [sp, #32]                  ; 8-byte Folded Reload
	ldur	w8, [x29, #-28]
	add	w8, w8, #1
	mov	w9, #40
	smaddl	x8, w8, w9, x10
	ldursw	x9, [x29, #-32]
	ldr	w8, [x8, x9, lsl #2]
	adds	w8, w8, #1
	b.ne	LBB2_24
	b	LBB2_23
LBB2_23:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB2_24
LBB2_24:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-32]
	subs	w8, w8, #0
	b.le	LBB2_27
	b	LBB2_25
LBB2_25:                                ;   in Loop: Header=BB2_16 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x9, [x29, #-28]
	mov	x10, #40
	mul	x9, x9, x10
	add	x8, x8, x9
	ldur	w9, [x29, #-32]
	subs	w9, w9, #1
	ldr	w8, [x8, w9, sxtw #2]
	adds	w8, w8, #1
	b.ne	LBB2_27
	b	LBB2_26
LBB2_26:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB2_27
LBB2_27:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-32]
	subs	w8, w8, #9
	b.ge	LBB2_30
	b	LBB2_28
LBB2_28:                                ;   in Loop: Header=BB2_16 Depth=2
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	ldursw	x9, [x29, #-28]
	mov	x10, #40
	mul	x9, x9, x10
	add	x8, x8, x9
	ldur	w9, [x29, #-32]
	add	w9, w9, #1
	ldr	w8, [x8, w9, sxtw #2]
	adds	w8, w8, #1
	b.ne	LBB2_30
	b	LBB2_29
LBB2_29:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB2_30
LBB2_30:                                ;   in Loop: Header=BB2_16 Depth=2
	ldr	x9, [sp, #32]                   ; 8-byte Folded Reload
	ldur	w8, [x29, #-36]
	ldursw	x10, [x29, #-28]
	mov	x11, #40
	mul	x10, x10, x11
	add	x9, x9, x10
	ldursw	x10, [x29, #-32]
	str	w8, [x9, x10, lsl #2]
	b	LBB2_31
LBB2_31:                                ;   in Loop: Header=BB2_16 Depth=2
	b	LBB2_32
LBB2_32:                                ;   in Loop: Header=BB2_16 Depth=2
	ldur	w8, [x29, #-32]
	add	w8, w8, #1
	stur	w8, [x29, #-32]
	b	LBB2_16
LBB2_33:                                ;   in Loop: Header=BB2_14 Depth=1
	b	LBB2_34
LBB2_34:                                ;   in Loop: Header=BB2_14 Depth=1
	ldur	w8, [x29, #-28]
	add	w8, w8, #1
	stur	w8, [x29, #-28]
	b	LBB2_14
LBB2_35:
	b	LBB2_36
LBB2_36:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB2_43 Depth 2
                                        ;       Child Loop BB2_45 Depth 3
	bl	_print_board
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	mov	x9, sp
	sub	x8, x29, #40
	str	x8, [x9]
	sub	x8, x29, #44
	str	x8, [x9, #8]
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_scanf
	ldur	w8, [x29, #-40]
	tbnz	w8, #31, LBB2_40
	b	LBB2_37
LBB2_37:                                ;   in Loop: Header=BB2_36 Depth=1
	ldur	w8, [x29, #-40]
	subs	w8, w8, #10
	b.ge	LBB2_40
	b	LBB2_38
LBB2_38:                                ;   in Loop: Header=BB2_36 Depth=1
	ldur	w8, [x29, #-44]
	tbnz	w8, #31, LBB2_40
	b	LBB2_39
LBB2_39:                                ;   in Loop: Header=BB2_36 Depth=1
	ldur	w8, [x29, #-44]
	subs	w8, w8, #10
	b.lt	LBB2_41
	b	LBB2_40
LBB2_40:                                ;   in Loop: Header=BB2_36 Depth=1
	adrp	x0, l_.str.8@PAGE
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	b	LBB2_42
LBB2_41:                                ;   in Loop: Header=BB2_36 Depth=1
	ldur	w0, [x29, #-40]
	ldur	w1, [x29, #-44]
	bl	_reveal_cell
	b	LBB2_42
LBB2_42:                                ;   in Loop: Header=BB2_36 Depth=1
	str	wzr, [sp, #48]
	str	wzr, [sp, #44]
	b	LBB2_43
LBB2_43:                                ;   Parent Loop BB2_36 Depth=1
                                        ; =>  This Loop Header: Depth=2
                                        ;       Child Loop BB2_45 Depth 3
	ldr	w8, [sp, #44]
	subs	w8, w8, #10
	b.ge	LBB2_52
	b	LBB2_44
LBB2_44:                                ;   in Loop: Header=BB2_43 Depth=2
	str	wzr, [sp, #40]
	b	LBB2_45
LBB2_45:                                ;   Parent Loop BB2_36 Depth=1
                                        ;     Parent Loop BB2_43 Depth=2
                                        ; =>    This Inner Loop Header: Depth=3
	ldr	w8, [sp, #40]
	subs	w8, w8, #10
	b.ge	LBB2_50
	b	LBB2_46
LBB2_46:                                ;   in Loop: Header=BB2_45 Depth=3
	ldrsw	x8, [sp, #44]
	mov	x9, #40
	mul	x9, x8, x9
	adrp	x8, _revealed@GOTPAGE
	ldr	x8, [x8, _revealed@GOTPAGEOFF]
	add	x8, x8, x9
	ldrsw	x9, [sp, #40]
	ldr	w8, [x8, x9, lsl #2]
	cbnz	w8, LBB2_48
	b	LBB2_47
LBB2_47:                                ;   in Loop: Header=BB2_45 Depth=3
	ldr	w8, [sp, #48]
	add	w8, w8, #1
	str	w8, [sp, #48]
	b	LBB2_48
LBB2_48:                                ;   in Loop: Header=BB2_45 Depth=3
	b	LBB2_49
LBB2_49:                                ;   in Loop: Header=BB2_45 Depth=3
	ldr	w8, [sp, #40]
	add	w8, w8, #1
	str	w8, [sp, #40]
	b	LBB2_45
LBB2_50:                                ;   in Loop: Header=BB2_43 Depth=2
	b	LBB2_51
LBB2_51:                                ;   in Loop: Header=BB2_43 Depth=2
	ldr	w8, [sp, #44]
	add	w8, w8, #1
	str	w8, [sp, #44]
	b	LBB2_43
LBB2_52:                                ;   in Loop: Header=BB2_36 Depth=1
	ldr	w8, [sp, #48]
	subs	w8, w8, #10
	b.ne	LBB2_54
	b	LBB2_53
LBB2_53:
	adrp	x0, l_.str.9@PAGE
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_printf
	mov	w0, #0
	bl	_exit
LBB2_54:                                ;   in Loop: Header=BB2_36 Depth=1
	b	LBB2_36
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"\n  "

l_.str.1:                               ; @.str.1
	.asciz	"%d "

l_.str.2:                               ; @.str.2
	.asciz	"\n"

	.comm	_revealed,400,2                 ; @revealed
	.comm	_board,400,2                    ; @board
l_.str.3:                               ; @.str.3
	.asciz	"* "

l_.str.4:                               ; @.str.4
	.asciz	". "

l_.str.5:                               ; @.str.5
	.asciz	"\nYou hit a bomb! Game over.\n"

l_.str.6:                               ; @.str.6
	.asciz	"\nEnter row and column to reveal (e.g. 2 4): "

l_.str.7:                               ; @.str.7
	.asciz	"%d %d"

l_.str.8:                               ; @.str.8
	.asciz	"Invalid input. Please try again.\n"

l_.str.9:                               ; @.str.9
	.asciz	"\nYou win!\n"

.subsections_via_symbols
