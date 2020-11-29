
malloc_test:     file format elf32-littleriscv


Disassembly of section .text:

80000100 <_start>:
.globl _start
.type _start,@function

_start:
  // set stack pointer
  li sp, 0x20001000
80000100:	20001137          	lui	sp,0x20001

  .option push
  .option norelax
  la gp, __global_pointer$
80000104:	00002197          	auipc	gp,0x2
80000108:	f3c18193          	addi	gp,gp,-196 # 80002040 <__global_pointer$>
  .option pop

  // set argc, argv
  li a0, 0
8000010c:	00000513          	li	a0,0
  li a1, 0
80000110:	00000593          	li	a1,0

  // jump to main
  call main
80000114:	03c000ef          	jal	ra,80000150 <main>

80000118 <__spike_return>:

/**
 * Halt the spike simulation and return a value.
 * See https://github.com/riscv/riscv-tests/blob/master/benchmarks/common/syscalls.c#L56
 */
void __spike_return(uint32_t code) {
80000118:	fd010113          	addi	sp,sp,-48 # 20000fd0 <_start-0x5ffff130>
8000011c:	02812623          	sw	s0,44(sp)
80000120:	03010413          	addi	s0,sp,48
80000124:	fca42e23          	sw	a0,-36(s0)
    // Spike tohost layout
    // bit 0: must be set to 1
    // All other bits are code << 1
    uint32_t tohostValue = (code << 1) | 1;
80000128:	fdc42783          	lw	a5,-36(s0)
8000012c:	00179793          	slli	a5,a5,0x1
80000130:	0017e793          	ori	a5,a5,1
80000134:	fef42623          	sw	a5,-20(s0)
    // See https://www.pygears.org/blog/riscv/setup.html
    asm(
80000138:	fec42783          	lw	a5,-20(s0)
8000013c:	00078293          	mv	t0,a5
80000140:	00001317          	auipc	t1,0x1
80000144:	ec030313          	addi	t1,t1,-320 # 80001000 <tohost>
80000148:	00532023          	sw	t0,0(t1)
        "sw t0, 0(t1)\n"
        : // outputs
        : "r"(tohostValue) // inputs
        : // clobbers
        );
    while(1) {}
8000014c:	0000006f          	j	8000014c <__spike_return+0x34>

80000150 <main>:
#include <stdlib.h>
#include "spike_util.c"

int main() {
80000150:	fe010113          	addi	sp,sp,-32
80000154:	00112e23          	sw	ra,28(sp)
80000158:	00812c23          	sw	s0,24(sp)
8000015c:	02010413          	addi	s0,sp,32
    int *i = malloc(sizeof(int));
80000160:	00400513          	li	a0,4
80000164:	050000ef          	jal	ra,800001b4 <malloc>
80000168:	00050793          	mv	a5,a0
8000016c:	fef42623          	sw	a5,-20(s0)
    *i = 1;
80000170:	fec42783          	lw	a5,-20(s0)
80000174:	00100713          	li	a4,1
80000178:	00e7a023          	sw	a4,0(a5)
    
    int j = *i;
8000017c:	fec42783          	lw	a5,-20(s0)
80000180:	0007a783          	lw	a5,0(a5)
80000184:	fef42423          	sw	a5,-24(s0)
    free(i);
80000188:	fec42503          	lw	a0,-20(s0)
8000018c:	034000ef          	jal	ra,800001c0 <free>

    __spike_return(j);
80000190:	fe842783          	lw	a5,-24(s0)
80000194:	00078513          	mv	a0,a5
80000198:	f81ff0ef          	jal	ra,80000118 <__spike_return>
8000019c:	00000793          	li	a5,0
}
800001a0:	00078513          	mv	a0,a5
800001a4:	01c12083          	lw	ra,28(sp)
800001a8:	01812403          	lw	s0,24(sp)
800001ac:	02010113          	addi	sp,sp,32
800001b0:	00008067          	ret

800001b4 <malloc>:
800001b4:	00050593          	mv	a1,a0
800001b8:	80c1a503          	lw	a0,-2036(gp) # 8000184c <_impure_ptr>
800001bc:	0100006f          	j	800001cc <_malloc_r>

800001c0 <free>:
800001c0:	00050593          	mv	a1,a0
800001c4:	80c1a503          	lw	a0,-2036(gp) # 8000184c <_impure_ptr>
800001c8:	7b80006f          	j	80000980 <_free_r>

800001cc <_malloc_r>:
800001cc:	fd010113          	addi	sp,sp,-48
800001d0:	02112623          	sw	ra,44(sp)
800001d4:	02812423          	sw	s0,40(sp)
800001d8:	02912223          	sw	s1,36(sp)
800001dc:	03212023          	sw	s2,32(sp)
800001e0:	01312e23          	sw	s3,28(sp)
800001e4:	01412c23          	sw	s4,24(sp)
800001e8:	01512a23          	sw	s5,20(sp)
800001ec:	01612823          	sw	s6,16(sp)
800001f0:	01712623          	sw	s7,12(sp)
800001f4:	01812423          	sw	s8,8(sp)
800001f8:	00b58793          	addi	a5,a1,11
800001fc:	01600713          	li	a4,22
80000200:	04f77463          	bleu	a5,a4,80000248 <_malloc_r+0x7c>
80000204:	ff87f493          	andi	s1,a5,-8
80000208:	0404d263          	bgez	s1,8000024c <_malloc_r+0x80>
8000020c:	00c00793          	li	a5,12
80000210:	00f52023          	sw	a5,0(a0)
80000214:	00000513          	li	a0,0
80000218:	02c12083          	lw	ra,44(sp)
8000021c:	02812403          	lw	s0,40(sp)
80000220:	02412483          	lw	s1,36(sp)
80000224:	02012903          	lw	s2,32(sp)
80000228:	01c12983          	lw	s3,28(sp)
8000022c:	01812a03          	lw	s4,24(sp)
80000230:	01412a83          	lw	s5,20(sp)
80000234:	01012b03          	lw	s6,16(sp)
80000238:	00c12b83          	lw	s7,12(sp)
8000023c:	00812c03          	lw	s8,8(sp)
80000240:	03010113          	addi	sp,sp,48
80000244:	00008067          	ret
80000248:	01000493          	li	s1,16
8000024c:	fcb4e0e3          	bltu	s1,a1,8000020c <_malloc_r+0x40>
80000250:	00050993          	mv	s3,a0
80000254:	5c0000ef          	jal	ra,80000814 <__malloc_lock>
80000258:	80001937          	lui	s2,0x80001
8000025c:	1f700793          	li	a5,503
80000260:	01090913          	addi	s2,s2,16 # 80001010 <__global_pointer$+0xffffefd0>
80000264:	0497ea63          	bltu	a5,s1,800002b8 <_malloc_r+0xec>
80000268:	00848713          	addi	a4,s1,8
8000026c:	00e90733          	add	a4,s2,a4
80000270:	00472403          	lw	s0,4(a4)
80000274:	ff870693          	addi	a3,a4,-8
80000278:	0034d793          	srli	a5,s1,0x3
8000027c:	00d41863          	bne	s0,a3,8000028c <_malloc_r+0xc0>
80000280:	00c72403          	lw	s0,12(a4)
80000284:	00278793          	addi	a5,a5,2
80000288:	08870063          	beq	a4,s0,80000308 <_malloc_r+0x13c>
8000028c:	00442783          	lw	a5,4(s0)
80000290:	00c42703          	lw	a4,12(s0)
80000294:	00842683          	lw	a3,8(s0)
80000298:	ffc7f793          	andi	a5,a5,-4
8000029c:	00f407b3          	add	a5,s0,a5
800002a0:	00e6a623          	sw	a4,12(a3)
800002a4:	00d72423          	sw	a3,8(a4)
800002a8:	0047a703          	lw	a4,4(a5)
800002ac:	00176713          	ori	a4,a4,1
800002b0:	00e7a223          	sw	a4,4(a5)
800002b4:	0a80006f          	j	8000035c <_malloc_r+0x190>
800002b8:	0094d713          	srli	a4,s1,0x9
800002bc:	03f00793          	li	a5,63
800002c0:	00070a63          	beqz	a4,800002d4 <_malloc_r+0x108>
800002c4:	00400793          	li	a5,4
800002c8:	0ae7e263          	bltu	a5,a4,8000036c <_malloc_r+0x1a0>
800002cc:	0064d793          	srli	a5,s1,0x6
800002d0:	03878793          	addi	a5,a5,56
800002d4:	00178713          	addi	a4,a5,1
800002d8:	00371713          	slli	a4,a4,0x3
800002dc:	00e90733          	add	a4,s2,a4
800002e0:	00472403          	lw	s0,4(a4)
800002e4:	ff870593          	addi	a1,a4,-8
800002e8:	00f00513          	li	a0,15
800002ec:	00b40c63          	beq	s0,a1,80000304 <_malloc_r+0x138>
800002f0:	00442703          	lw	a4,4(s0)
800002f4:	ffc77713          	andi	a4,a4,-4
800002f8:	40970633          	sub	a2,a4,s1
800002fc:	0cc55063          	ble	a2,a0,800003bc <_malloc_r+0x1f0>
80000300:	fff78793          	addi	a5,a5,-1
80000304:	00178793          	addi	a5,a5,1
80000308:	01092403          	lw	s0,16(s2)
8000030c:	800015b7          	lui	a1,0x80001
80000310:	00890693          	addi	a3,s2,8
80000314:	01858593          	addi	a1,a1,24 # 80001018 <__global_pointer$+0xffffefd8>
80000318:	12d40863          	beq	s0,a3,80000448 <_malloc_r+0x27c>
8000031c:	00442703          	lw	a4,4(s0)
80000320:	00f00613          	li	a2,15
80000324:	ffc77713          	andi	a4,a4,-4
80000328:	40970533          	sub	a0,a4,s1
8000032c:	0aa65a63          	ble	a0,a2,800003e0 <_malloc_r+0x214>
80000330:	0014e793          	ori	a5,s1,1
80000334:	00f42223          	sw	a5,4(s0)
80000338:	00940633          	add	a2,s0,s1
8000033c:	00c92a23          	sw	a2,20(s2)
80000340:	00c92823          	sw	a2,16(s2)
80000344:	00156793          	ori	a5,a0,1
80000348:	00d62623          	sw	a3,12(a2)
8000034c:	00d62423          	sw	a3,8(a2)
80000350:	00f62223          	sw	a5,4(a2)
80000354:	00e40733          	add	a4,s0,a4
80000358:	00a72023          	sw	a0,0(a4)
8000035c:	00098513          	mv	a0,s3
80000360:	4b8000ef          	jal	ra,80000818 <__malloc_unlock>
80000364:	00840513          	addi	a0,s0,8
80000368:	eb1ff06f          	j	80000218 <_malloc_r+0x4c>
8000036c:	01400793          	li	a5,20
80000370:	00e7e663          	bltu	a5,a4,8000037c <_malloc_r+0x1b0>
80000374:	05b70793          	addi	a5,a4,91
80000378:	f5dff06f          	j	800002d4 <_malloc_r+0x108>
8000037c:	05400793          	li	a5,84
80000380:	00e7e863          	bltu	a5,a4,80000390 <_malloc_r+0x1c4>
80000384:	00c4d793          	srli	a5,s1,0xc
80000388:	06e78793          	addi	a5,a5,110
8000038c:	f49ff06f          	j	800002d4 <_malloc_r+0x108>
80000390:	15400793          	li	a5,340
80000394:	00e7e863          	bltu	a5,a4,800003a4 <_malloc_r+0x1d8>
80000398:	00f4d793          	srli	a5,s1,0xf
8000039c:	07778793          	addi	a5,a5,119
800003a0:	f35ff06f          	j	800002d4 <_malloc_r+0x108>
800003a4:	55400693          	li	a3,1364
800003a8:	07e00793          	li	a5,126
800003ac:	f2e6e4e3          	bltu	a3,a4,800002d4 <_malloc_r+0x108>
800003b0:	0124d793          	srli	a5,s1,0x12
800003b4:	07c78793          	addi	a5,a5,124
800003b8:	f1dff06f          	j	800002d4 <_malloc_r+0x108>
800003bc:	00c42683          	lw	a3,12(s0)
800003c0:	00064c63          	bltz	a2,800003d8 <_malloc_r+0x20c>
800003c4:	00842783          	lw	a5,8(s0)
800003c8:	00d7a623          	sw	a3,12(a5)
800003cc:	00f6a423          	sw	a5,8(a3)
800003d0:	00e407b3          	add	a5,s0,a4
800003d4:	ed5ff06f          	j	800002a8 <_malloc_r+0xdc>
800003d8:	00068413          	mv	s0,a3
800003dc:	f11ff06f          	j	800002ec <_malloc_r+0x120>
800003e0:	00d92a23          	sw	a3,20(s2)
800003e4:	00d92823          	sw	a3,16(s2)
800003e8:	00054c63          	bltz	a0,80000400 <_malloc_r+0x234>
800003ec:	00e40733          	add	a4,s0,a4
800003f0:	00472783          	lw	a5,4(a4)
800003f4:	0017e793          	ori	a5,a5,1
800003f8:	00f72223          	sw	a5,4(a4)
800003fc:	f61ff06f          	j	8000035c <_malloc_r+0x190>
80000400:	1ff00693          	li	a3,511
80000404:	00492803          	lw	a6,4(s2)
80000408:	16e6e863          	bltu	a3,a4,80000578 <_malloc_r+0x3ac>
8000040c:	00375713          	srli	a4,a4,0x3
80000410:	40275613          	srai	a2,a4,0x2
80000414:	00100693          	li	a3,1
80000418:	00170713          	addi	a4,a4,1
8000041c:	00c696b3          	sll	a3,a3,a2
80000420:	00371713          	slli	a4,a4,0x3
80000424:	00e90733          	add	a4,s2,a4
80000428:	0106e6b3          	or	a3,a3,a6
8000042c:	00d92223          	sw	a3,4(s2)
80000430:	00072683          	lw	a3,0(a4)
80000434:	ff870613          	addi	a2,a4,-8
80000438:	00c42623          	sw	a2,12(s0)
8000043c:	00d42423          	sw	a3,8(s0)
80000440:	00872023          	sw	s0,0(a4)
80000444:	0086a623          	sw	s0,12(a3)
80000448:	4027d713          	srai	a4,a5,0x2
8000044c:	00100313          	li	t1,1
80000450:	00e31333          	sll	t1,t1,a4
80000454:	00492703          	lw	a4,4(s2)
80000458:	06676a63          	bltu	a4,t1,800004cc <_malloc_r+0x300>
8000045c:	006776b3          	and	a3,a4,t1
80000460:	00069c63          	bnez	a3,80000478 <_malloc_r+0x2ac>
80000464:	ffc7f793          	andi	a5,a5,-4
80000468:	00131313          	slli	t1,t1,0x1
8000046c:	006776b3          	and	a3,a4,t1
80000470:	00478793          	addi	a5,a5,4
80000474:	fe068ae3          	beqz	a3,80000468 <_malloc_r+0x29c>
80000478:	00f00e13          	li	t3,15
8000047c:	00379693          	slli	a3,a5,0x3
80000480:	00d906b3          	add	a3,s2,a3
80000484:	00068813          	mv	a6,a3
80000488:	00078513          	mv	a0,a5
8000048c:	00c82403          	lw	s0,12(a6)
80000490:	1b041463          	bne	s0,a6,80000638 <_malloc_r+0x46c>
80000494:	00150513          	addi	a0,a0,1
80000498:	00357713          	andi	a4,a0,3
8000049c:	00880813          	addi	a6,a6,8
800004a0:	fe0716e3          	bnez	a4,8000048c <_malloc_r+0x2c0>
800004a4:	0037f713          	andi	a4,a5,3
800004a8:	20071663          	bnez	a4,800006b4 <_malloc_r+0x4e8>
800004ac:	00492703          	lw	a4,4(s2)
800004b0:	fff34793          	not	a5,t1
800004b4:	00f777b3          	and	a5,a4,a5
800004b8:	00f92223          	sw	a5,4(s2)
800004bc:	00492703          	lw	a4,4(s2)
800004c0:	00131313          	slli	t1,t1,0x1
800004c4:	00676463          	bltu	a4,t1,800004cc <_malloc_r+0x300>
800004c8:	20031a63          	bnez	t1,800006dc <_malloc_r+0x510>
800004cc:	00892b83          	lw	s7,8(s2)
800004d0:	004ba403          	lw	s0,4(s7)
800004d4:	ffc47a93          	andi	s5,s0,-4
800004d8:	009ae863          	bltu	s5,s1,800004e8 <_malloc_r+0x31c>
800004dc:	409a8733          	sub	a4,s5,s1
800004e0:	00f00793          	li	a5,15
800004e4:	30e7cc63          	blt	a5,a4,800007fc <_malloc_r+0x630>
800004e8:	80002a37          	lui	s4,0x80002
800004ec:	8181a403          	lw	s0,-2024(gp) # 80001858 <__malloc_top_pad>
800004f0:	840a2703          	lw	a4,-1984(s4) # 80001840 <__global_pointer$+0xfffff800>
800004f4:	fff00793          	li	a5,-1
800004f8:	00848433          	add	s0,s1,s0
800004fc:	1ef71463          	bne	a4,a5,800006e4 <_malloc_r+0x518>
80000500:	01040413          	addi	s0,s0,16
80000504:	00040593          	mv	a1,s0
80000508:	00098513          	mv	a0,s3
8000050c:	310000ef          	jal	ra,8000081c <_sbrk_r>
80000510:	fff00793          	li	a5,-1
80000514:	00050b13          	mv	s6,a0
80000518:	26f50863          	beq	a0,a5,80000788 <_malloc_r+0x5bc>
8000051c:	015b87b3          	add	a5,s7,s5
80000520:	00f57463          	bleu	a5,a0,80000528 <_malloc_r+0x35c>
80000524:	272b9263          	bne	s7,s2,80000788 <_malloc_r+0x5bc>
80000528:	82018693          	addi	a3,gp,-2016 # 80001860 <__malloc_current_mallinfo>
8000052c:	0006a703          	lw	a4,0(a3)
80000530:	82018c13          	addi	s8,gp,-2016 # 80001860 <__malloc_current_mallinfo>
80000534:	00e40733          	add	a4,s0,a4
80000538:	00e6a023          	sw	a4,0(a3)
8000053c:	1d679063          	bne	a5,s6,800006fc <_malloc_r+0x530>
80000540:	01479693          	slli	a3,a5,0x14
80000544:	1a069c63          	bnez	a3,800006fc <_malloc_r+0x530>
80000548:	00892783          	lw	a5,8(s2)
8000054c:	008a8433          	add	s0,s5,s0
80000550:	00146413          	ori	s0,s0,1
80000554:	0087a223          	sw	s0,4(a5)
80000558:	000c2783          	lw	a5,0(s8)
8000055c:	8141a683          	lw	a3,-2028(gp) # 80001854 <__malloc_max_sbrked_mem>
80000560:	00f6f463          	bleu	a5,a3,80000568 <_malloc_r+0x39c>
80000564:	80f1aa23          	sw	a5,-2028(gp) # 80001854 <__malloc_max_sbrked_mem>
80000568:	8101a683          	lw	a3,-2032(gp) # 80001850 <_edata>
8000056c:	20f6fe63          	bleu	a5,a3,80000788 <_malloc_r+0x5bc>
80000570:	80f1a823          	sw	a5,-2032(gp) # 80001850 <_edata>
80000574:	2140006f          	j	80000788 <_malloc_r+0x5bc>
80000578:	00975613          	srli	a2,a4,0x9
8000057c:	00400693          	li	a3,4
80000580:	04c6e663          	bltu	a3,a2,800005cc <_malloc_r+0x400>
80000584:	00675693          	srli	a3,a4,0x6
80000588:	03868693          	addi	a3,a3,56
8000058c:	00168613          	addi	a2,a3,1
80000590:	00361613          	slli	a2,a2,0x3
80000594:	00c90633          	add	a2,s2,a2
80000598:	ff860513          	addi	a0,a2,-8
8000059c:	00062603          	lw	a2,0(a2)
800005a0:	08c51263          	bne	a0,a2,80000624 <_malloc_r+0x458>
800005a4:	4026d693          	srai	a3,a3,0x2
800005a8:	00100713          	li	a4,1
800005ac:	00d716b3          	sll	a3,a4,a3
800005b0:	0106e6b3          	or	a3,a3,a6
800005b4:	00d92223          	sw	a3,4(s2)
800005b8:	00a42623          	sw	a0,12(s0)
800005bc:	00c42423          	sw	a2,8(s0)
800005c0:	00852423          	sw	s0,8(a0)
800005c4:	00862623          	sw	s0,12(a2)
800005c8:	e81ff06f          	j	80000448 <_malloc_r+0x27c>
800005cc:	01400693          	li	a3,20
800005d0:	00c6e663          	bltu	a3,a2,800005dc <_malloc_r+0x410>
800005d4:	05b60693          	addi	a3,a2,91
800005d8:	fb5ff06f          	j	8000058c <_malloc_r+0x3c0>
800005dc:	05400693          	li	a3,84
800005e0:	00c6e863          	bltu	a3,a2,800005f0 <_malloc_r+0x424>
800005e4:	00c75693          	srli	a3,a4,0xc
800005e8:	06e68693          	addi	a3,a3,110
800005ec:	fa1ff06f          	j	8000058c <_malloc_r+0x3c0>
800005f0:	15400693          	li	a3,340
800005f4:	00c6e863          	bltu	a3,a2,80000604 <_malloc_r+0x438>
800005f8:	00f75693          	srli	a3,a4,0xf
800005fc:	07768693          	addi	a3,a3,119
80000600:	f8dff06f          	j	8000058c <_malloc_r+0x3c0>
80000604:	55400513          	li	a0,1364
80000608:	07e00693          	li	a3,126
8000060c:	f8c560e3          	bltu	a0,a2,8000058c <_malloc_r+0x3c0>
80000610:	01275693          	srli	a3,a4,0x12
80000614:	07c68693          	addi	a3,a3,124
80000618:	f75ff06f          	j	8000058c <_malloc_r+0x3c0>
8000061c:	00862603          	lw	a2,8(a2)
80000620:	00c50863          	beq	a0,a2,80000630 <_malloc_r+0x464>
80000624:	00462683          	lw	a3,4(a2)
80000628:	ffc6f693          	andi	a3,a3,-4
8000062c:	fed768e3          	bltu	a4,a3,8000061c <_malloc_r+0x450>
80000630:	00c62503          	lw	a0,12(a2)
80000634:	f85ff06f          	j	800005b8 <_malloc_r+0x3ec>
80000638:	00442703          	lw	a4,4(s0)
8000063c:	00c42603          	lw	a2,12(s0)
80000640:	ffc77713          	andi	a4,a4,-4
80000644:	409708b3          	sub	a7,a4,s1
80000648:	051e5063          	ble	a7,t3,80000688 <_malloc_r+0x4bc>
8000064c:	0014e793          	ori	a5,s1,1
80000650:	00f42223          	sw	a5,4(s0)
80000654:	00842783          	lw	a5,8(s0)
80000658:	009406b3          	add	a3,s0,s1
8000065c:	00e40733          	add	a4,s0,a4
80000660:	00c7a623          	sw	a2,12(a5)
80000664:	00f62423          	sw	a5,8(a2)
80000668:	00d92a23          	sw	a3,20(s2)
8000066c:	00d92823          	sw	a3,16(s2)
80000670:	0018e793          	ori	a5,a7,1
80000674:	00b6a623          	sw	a1,12(a3)
80000678:	00b6a423          	sw	a1,8(a3)
8000067c:	00f6a223          	sw	a5,4(a3)
80000680:	01172023          	sw	a7,0(a4)
80000684:	cd9ff06f          	j	8000035c <_malloc_r+0x190>
80000688:	0208c263          	bltz	a7,800006ac <_malloc_r+0x4e0>
8000068c:	00e40733          	add	a4,s0,a4
80000690:	00472783          	lw	a5,4(a4)
80000694:	0017e793          	ori	a5,a5,1
80000698:	00f72223          	sw	a5,4(a4)
8000069c:	00842783          	lw	a5,8(s0)
800006a0:	00c7a623          	sw	a2,12(a5)
800006a4:	00f62423          	sw	a5,8(a2)
800006a8:	cb5ff06f          	j	8000035c <_malloc_r+0x190>
800006ac:	00060413          	mv	s0,a2
800006b0:	de1ff06f          	j	80000490 <_malloc_r+0x2c4>
800006b4:	ff868713          	addi	a4,a3,-8
800006b8:	0006a683          	lw	a3,0(a3)
800006bc:	fff78793          	addi	a5,a5,-1
800006c0:	dee682e3          	beq	a3,a4,800004a4 <_malloc_r+0x2d8>
800006c4:	df9ff06f          	j	800004bc <_malloc_r+0x2f0>
800006c8:	00478793          	addi	a5,a5,4
800006cc:	00131313          	slli	t1,t1,0x1
800006d0:	006776b3          	and	a3,a4,t1
800006d4:	fe068ae3          	beqz	a3,800006c8 <_malloc_r+0x4fc>
800006d8:	da5ff06f          	j	8000047c <_malloc_r+0x2b0>
800006dc:	00050793          	mv	a5,a0
800006e0:	ff1ff06f          	j	800006d0 <_malloc_r+0x504>
800006e4:	000017b7          	lui	a5,0x1
800006e8:	00f78793          	addi	a5,a5,15 # 100f <_start-0x7ffff0f1>
800006ec:	00f40433          	add	s0,s0,a5
800006f0:	fffff7b7          	lui	a5,0xfffff
800006f4:	00f47433          	and	s0,s0,a5
800006f8:	e0dff06f          	j	80000504 <_malloc_r+0x338>
800006fc:	840a2603          	lw	a2,-1984(s4)
80000700:	fff00693          	li	a3,-1
80000704:	0ad61663          	bne	a2,a3,800007b0 <_malloc_r+0x5e4>
80000708:	856a2023          	sw	s6,-1984(s4)
8000070c:	007b7593          	andi	a1,s6,7
80000710:	00058863          	beqz	a1,80000720 <_malloc_r+0x554>
80000714:	00800793          	li	a5,8
80000718:	40b785b3          	sub	a1,a5,a1
8000071c:	00bb0b33          	add	s6,s6,a1
80000720:	000017b7          	lui	a5,0x1
80000724:	00f585b3          	add	a1,a1,a5
80000728:	008b0433          	add	s0,s6,s0
8000072c:	fff78793          	addi	a5,a5,-1 # fff <_start-0x7ffff101>
80000730:	00f47433          	and	s0,s0,a5
80000734:	40858a33          	sub	s4,a1,s0
80000738:	000a0593          	mv	a1,s4
8000073c:	00098513          	mv	a0,s3
80000740:	0dc000ef          	jal	ra,8000081c <_sbrk_r>
80000744:	fff00793          	li	a5,-1
80000748:	00f51663          	bne	a0,a5,80000754 <_malloc_r+0x588>
8000074c:	000b0513          	mv	a0,s6
80000750:	00000a13          	li	s4,0
80000754:	000c2783          	lw	a5,0(s8)
80000758:	41650533          	sub	a0,a0,s6
8000075c:	01692423          	sw	s6,8(s2)
80000760:	014787b3          	add	a5,a5,s4
80000764:	01450a33          	add	s4,a0,s4
80000768:	001a6a13          	ori	s4,s4,1
8000076c:	00fc2023          	sw	a5,0(s8)
80000770:	014b2223          	sw	s4,4(s6)
80000774:	df2b82e3          	beq	s7,s2,80000558 <_malloc_r+0x38c>
80000778:	00f00713          	li	a4,15
8000077c:	05576263          	bltu	a4,s5,800007c0 <_malloc_r+0x5f4>
80000780:	00100793          	li	a5,1
80000784:	00fb2223          	sw	a5,4(s6)
80000788:	00892783          	lw	a5,8(s2)
8000078c:	0047a783          	lw	a5,4(a5)
80000790:	ffc7f793          	andi	a5,a5,-4
80000794:	40978733          	sub	a4,a5,s1
80000798:	0097e663          	bltu	a5,s1,800007a4 <_malloc_r+0x5d8>
8000079c:	00f00793          	li	a5,15
800007a0:	04e7ce63          	blt	a5,a4,800007fc <_malloc_r+0x630>
800007a4:	00098513          	mv	a0,s3
800007a8:	070000ef          	jal	ra,80000818 <__malloc_unlock>
800007ac:	a69ff06f          	j	80000214 <_malloc_r+0x48>
800007b0:	40fb07b3          	sub	a5,s6,a5
800007b4:	00e787b3          	add	a5,a5,a4
800007b8:	00fc2023          	sw	a5,0(s8)
800007bc:	f51ff06f          	j	8000070c <_malloc_r+0x540>
800007c0:	004ba783          	lw	a5,4(s7)
800007c4:	ff4a8413          	addi	s0,s5,-12
800007c8:	ff847413          	andi	s0,s0,-8
800007cc:	0017f793          	andi	a5,a5,1
800007d0:	0087e7b3          	or	a5,a5,s0
800007d4:	00fba223          	sw	a5,4(s7)
800007d8:	00500693          	li	a3,5
800007dc:	008b87b3          	add	a5,s7,s0
800007e0:	00d7a223          	sw	a3,4(a5)
800007e4:	00d7a423          	sw	a3,8(a5)
800007e8:	d68778e3          	bleu	s0,a4,80000558 <_malloc_r+0x38c>
800007ec:	008b8593          	addi	a1,s7,8
800007f0:	00098513          	mv	a0,s3
800007f4:	18c000ef          	jal	ra,80000980 <_free_r>
800007f8:	d61ff06f          	j	80000558 <_malloc_r+0x38c>
800007fc:	00892403          	lw	s0,8(s2)
80000800:	0014e793          	ori	a5,s1,1
80000804:	00f42223          	sw	a5,4(s0)
80000808:	009407b3          	add	a5,s0,s1
8000080c:	00f92423          	sw	a5,8(s2)
80000810:	a9dff06f          	j	800002ac <_malloc_r+0xe0>

80000814 <__malloc_lock>:
80000814:	00008067          	ret

80000818 <__malloc_unlock>:
80000818:	00008067          	ret

8000081c <_sbrk_r>:
8000081c:	ff010113          	addi	sp,sp,-16
80000820:	00812423          	sw	s0,8(sp)
80000824:	00912223          	sw	s1,4(sp)
80000828:	00050493          	mv	s1,a0
8000082c:	00058513          	mv	a0,a1
80000830:	00112623          	sw	ra,12(sp)
80000834:	8401a423          	sw	zero,-1976(gp) # 80001888 <errno>
80000838:	4f4000ef          	jal	ra,80000d2c <_sbrk>
8000083c:	fff00793          	li	a5,-1
80000840:	00f51863          	bne	a0,a5,80000850 <_sbrk_r+0x34>
80000844:	8481a783          	lw	a5,-1976(gp) # 80001888 <errno>
80000848:	00078463          	beqz	a5,80000850 <_sbrk_r+0x34>
8000084c:	00f4a023          	sw	a5,0(s1)
80000850:	00c12083          	lw	ra,12(sp)
80000854:	00812403          	lw	s0,8(sp)
80000858:	00412483          	lw	s1,4(sp)
8000085c:	01010113          	addi	sp,sp,16
80000860:	00008067          	ret

80000864 <_malloc_trim_r>:
80000864:	fd010113          	addi	sp,sp,-48
80000868:	03212023          	sw	s2,32(sp)
8000086c:	80001937          	lui	s2,0x80001
80000870:	02812423          	sw	s0,40(sp)
80000874:	02912223          	sw	s1,36(sp)
80000878:	01312e23          	sw	s3,28(sp)
8000087c:	00b12623          	sw	a1,12(sp)
80000880:	02112623          	sw	ra,44(sp)
80000884:	00050993          	mv	s3,a0
80000888:	01090913          	addi	s2,s2,16 # 80001010 <__global_pointer$+0xffffefd0>
8000088c:	f89ff0ef          	jal	ra,80000814 <__malloc_lock>
80000890:	00892783          	lw	a5,8(s2)
80000894:	00c12583          	lw	a1,12(sp)
80000898:	0047a483          	lw	s1,4(a5)
8000089c:	000017b7          	lui	a5,0x1
800008a0:	fef78413          	addi	s0,a5,-17 # fef <_start-0x7ffff111>
800008a4:	ffc4f493          	andi	s1,s1,-4
800008a8:	40b40433          	sub	s0,s0,a1
800008ac:	00940433          	add	s0,s0,s1
800008b0:	00c45413          	srli	s0,s0,0xc
800008b4:	fff40413          	addi	s0,s0,-1
800008b8:	00c41413          	slli	s0,s0,0xc
800008bc:	02f45663          	ble	a5,s0,800008e8 <_malloc_trim_r+0x84>
800008c0:	00098513          	mv	a0,s3
800008c4:	f55ff0ef          	jal	ra,80000818 <__malloc_unlock>
800008c8:	00000513          	li	a0,0
800008cc:	02c12083          	lw	ra,44(sp)
800008d0:	02812403          	lw	s0,40(sp)
800008d4:	02412483          	lw	s1,36(sp)
800008d8:	02012903          	lw	s2,32(sp)
800008dc:	01c12983          	lw	s3,28(sp)
800008e0:	03010113          	addi	sp,sp,48
800008e4:	00008067          	ret
800008e8:	00000593          	li	a1,0
800008ec:	00098513          	mv	a0,s3
800008f0:	f2dff0ef          	jal	ra,8000081c <_sbrk_r>
800008f4:	00892783          	lw	a5,8(s2)
800008f8:	009787b3          	add	a5,a5,s1
800008fc:	fcf512e3          	bne	a0,a5,800008c0 <_malloc_trim_r+0x5c>
80000900:	408005b3          	neg	a1,s0
80000904:	00098513          	mv	a0,s3
80000908:	f15ff0ef          	jal	ra,8000081c <_sbrk_r>
8000090c:	fff00793          	li	a5,-1
80000910:	04f51063          	bne	a0,a5,80000950 <_malloc_trim_r+0xec>
80000914:	00000593          	li	a1,0
80000918:	00098513          	mv	a0,s3
8000091c:	f01ff0ef          	jal	ra,8000081c <_sbrk_r>
80000920:	00892703          	lw	a4,8(s2)
80000924:	00f00693          	li	a3,15
80000928:	40e507b3          	sub	a5,a0,a4
8000092c:	f8f6dae3          	ble	a5,a3,800008c0 <_malloc_trim_r+0x5c>
80000930:	800026b7          	lui	a3,0x80002
80000934:	8406a683          	lw	a3,-1984(a3) # 80001840 <__global_pointer$+0xfffff800>
80000938:	0017e793          	ori	a5,a5,1
8000093c:	00f72223          	sw	a5,4(a4)
80000940:	40d50533          	sub	a0,a0,a3
80000944:	800026b7          	lui	a3,0x80002
80000948:	86a6a023          	sw	a0,-1952(a3) # 80001860 <__global_pointer$+0xfffff820>
8000094c:	f75ff06f          	j	800008c0 <_malloc_trim_r+0x5c>
80000950:	00892783          	lw	a5,8(s2)
80000954:	408484b3          	sub	s1,s1,s0
80000958:	80002737          	lui	a4,0x80002
8000095c:	0014e493          	ori	s1,s1,1
80000960:	0097a223          	sw	s1,4(a5)
80000964:	86072783          	lw	a5,-1952(a4) # 80001860 <__global_pointer$+0xfffff820>
80000968:	00098513          	mv	a0,s3
8000096c:	40878433          	sub	s0,a5,s0
80000970:	86872023          	sw	s0,-1952(a4)
80000974:	ea5ff0ef          	jal	ra,80000818 <__malloc_unlock>
80000978:	00100513          	li	a0,1
8000097c:	f51ff06f          	j	800008cc <_malloc_trim_r+0x68>

80000980 <_free_r>:
80000980:	24058e63          	beqz	a1,80000bdc <_free_r+0x25c>
80000984:	ff010113          	addi	sp,sp,-16
80000988:	00812423          	sw	s0,8(sp)
8000098c:	00912223          	sw	s1,4(sp)
80000990:	00050413          	mv	s0,a0
80000994:	00058493          	mv	s1,a1
80000998:	00112623          	sw	ra,12(sp)
8000099c:	e79ff0ef          	jal	ra,80000814 <__malloc_lock>
800009a0:	ffc4a503          	lw	a0,-4(s1)
800009a4:	80001637          	lui	a2,0x80001
800009a8:	ff848693          	addi	a3,s1,-8
800009ac:	ffe57793          	andi	a5,a0,-2
800009b0:	01060813          	addi	a6,a2,16 # 80001010 <__global_pointer$+0xffffefd0>
800009b4:	00f685b3          	add	a1,a3,a5
800009b8:	0045a703          	lw	a4,4(a1)
800009bc:	00882803          	lw	a6,8(a6)
800009c0:	01060613          	addi	a2,a2,16
800009c4:	ffc77713          	andi	a4,a4,-4
800009c8:	00157513          	andi	a0,a0,1
800009cc:	06b81263          	bne	a6,a1,80000a30 <_free_r+0xb0>
800009d0:	00e787b3          	add	a5,a5,a4
800009d4:	02051063          	bnez	a0,800009f4 <_free_r+0x74>
800009d8:	ff84a703          	lw	a4,-8(s1)
800009dc:	40e686b3          	sub	a3,a3,a4
800009e0:	0086a583          	lw	a1,8(a3)
800009e4:	00e787b3          	add	a5,a5,a4
800009e8:	00c6a703          	lw	a4,12(a3)
800009ec:	00e5a623          	sw	a4,12(a1)
800009f0:	00b72423          	sw	a1,8(a4)
800009f4:	0017e713          	ori	a4,a5,1
800009f8:	00e6a223          	sw	a4,4(a3)
800009fc:	80002737          	lui	a4,0x80002
80000a00:	84472703          	lw	a4,-1980(a4) # 80001844 <__global_pointer$+0xfffff804>
80000a04:	00d62423          	sw	a3,8(a2)
80000a08:	00e7e863          	bltu	a5,a4,80000a18 <_free_r+0x98>
80000a0c:	8181a583          	lw	a1,-2024(gp) # 80001858 <__malloc_top_pad>
80000a10:	00040513          	mv	a0,s0
80000a14:	e51ff0ef          	jal	ra,80000864 <_malloc_trim_r>
80000a18:	00040513          	mv	a0,s0
80000a1c:	00812403          	lw	s0,8(sp)
80000a20:	00c12083          	lw	ra,12(sp)
80000a24:	00412483          	lw	s1,4(sp)
80000a28:	01010113          	addi	sp,sp,16
80000a2c:	dedff06f          	j	80000818 <__malloc_unlock>
80000a30:	00e5a223          	sw	a4,4(a1)
80000a34:	00000813          	li	a6,0
80000a38:	02051663          	bnez	a0,80000a64 <_free_r+0xe4>
80000a3c:	ff84a503          	lw	a0,-8(s1)
80000a40:	800018b7          	lui	a7,0x80001
80000a44:	01888893          	addi	a7,a7,24 # 80001018 <__global_pointer$+0xffffefd8>
80000a48:	40a686b3          	sub	a3,a3,a0
80000a4c:	00a787b3          	add	a5,a5,a0
80000a50:	0086a503          	lw	a0,8(a3)
80000a54:	0b150663          	beq	a0,a7,80000b00 <_free_r+0x180>
80000a58:	00c6a883          	lw	a7,12(a3)
80000a5c:	01152623          	sw	a7,12(a0)
80000a60:	00a8a423          	sw	a0,8(a7)
80000a64:	00e58533          	add	a0,a1,a4
80000a68:	00452503          	lw	a0,4(a0)
80000a6c:	00157513          	andi	a0,a0,1
80000a70:	02051863          	bnez	a0,80000aa0 <_free_r+0x120>
80000a74:	00e787b3          	add	a5,a5,a4
80000a78:	0085a703          	lw	a4,8(a1)
80000a7c:	08081663          	bnez	a6,80000b08 <_free_r+0x188>
80000a80:	80001537          	lui	a0,0x80001
80000a84:	01850513          	addi	a0,a0,24 # 80001018 <__global_pointer$+0xffffefd8>
80000a88:	08a71063          	bne	a4,a0,80000b08 <_free_r+0x188>
80000a8c:	00d62a23          	sw	a3,20(a2)
80000a90:	00d62823          	sw	a3,16(a2)
80000a94:	00e6a623          	sw	a4,12(a3)
80000a98:	00e6a423          	sw	a4,8(a3)
80000a9c:	00100813          	li	a6,1
80000aa0:	0017e713          	ori	a4,a5,1
80000aa4:	00e6a223          	sw	a4,4(a3)
80000aa8:	00f68733          	add	a4,a3,a5
80000aac:	00f72023          	sw	a5,0(a4)
80000ab0:	f60814e3          	bnez	a6,80000a18 <_free_r+0x98>
80000ab4:	1ff00713          	li	a4,511
80000ab8:	06f76063          	bltu	a4,a5,80000b18 <_free_r+0x198>
80000abc:	0037d793          	srli	a5,a5,0x3
80000ac0:	4027d593          	srai	a1,a5,0x2
80000ac4:	00100713          	li	a4,1
80000ac8:	00b71733          	sll	a4,a4,a1
80000acc:	00462583          	lw	a1,4(a2)
80000ad0:	00178793          	addi	a5,a5,1
80000ad4:	00379793          	slli	a5,a5,0x3
80000ad8:	00f607b3          	add	a5,a2,a5
80000adc:	00b76733          	or	a4,a4,a1
80000ae0:	00e62223          	sw	a4,4(a2)
80000ae4:	0007a703          	lw	a4,0(a5)
80000ae8:	ff878613          	addi	a2,a5,-8
80000aec:	00c6a623          	sw	a2,12(a3)
80000af0:	00e6a423          	sw	a4,8(a3)
80000af4:	00d7a023          	sw	a3,0(a5)
80000af8:	00d72623          	sw	a3,12(a4)
80000afc:	f1dff06f          	j	80000a18 <_free_r+0x98>
80000b00:	00100813          	li	a6,1
80000b04:	f61ff06f          	j	80000a64 <_free_r+0xe4>
80000b08:	00c5a583          	lw	a1,12(a1)
80000b0c:	00b72623          	sw	a1,12(a4)
80000b10:	00e5a423          	sw	a4,8(a1)
80000b14:	f8dff06f          	j	80000aa0 <_free_r+0x120>
80000b18:	0097d593          	srli	a1,a5,0x9
80000b1c:	00400713          	li	a4,4
80000b20:	04b76863          	bltu	a4,a1,80000b70 <_free_r+0x1f0>
80000b24:	0067d713          	srli	a4,a5,0x6
80000b28:	03870713          	addi	a4,a4,56
80000b2c:	00170593          	addi	a1,a4,1
80000b30:	00359593          	slli	a1,a1,0x3
80000b34:	00b605b3          	add	a1,a2,a1
80000b38:	ff858513          	addi	a0,a1,-8
80000b3c:	0005a583          	lw	a1,0(a1)
80000b40:	08b51463          	bne	a0,a1,80000bc8 <_free_r+0x248>
80000b44:	00100793          	li	a5,1
80000b48:	40275713          	srai	a4,a4,0x2
80000b4c:	00e79733          	sll	a4,a5,a4
80000b50:	00462783          	lw	a5,4(a2)
80000b54:	00f76733          	or	a4,a4,a5
80000b58:	00e62223          	sw	a4,4(a2)
80000b5c:	00a6a623          	sw	a0,12(a3)
80000b60:	00b6a423          	sw	a1,8(a3)
80000b64:	00d52423          	sw	a3,8(a0)
80000b68:	00d5a623          	sw	a3,12(a1)
80000b6c:	eadff06f          	j	80000a18 <_free_r+0x98>
80000b70:	01400713          	li	a4,20
80000b74:	00b76663          	bltu	a4,a1,80000b80 <_free_r+0x200>
80000b78:	05b58713          	addi	a4,a1,91
80000b7c:	fb1ff06f          	j	80000b2c <_free_r+0x1ac>
80000b80:	05400713          	li	a4,84
80000b84:	00b76863          	bltu	a4,a1,80000b94 <_free_r+0x214>
80000b88:	00c7d713          	srli	a4,a5,0xc
80000b8c:	06e70713          	addi	a4,a4,110
80000b90:	f9dff06f          	j	80000b2c <_free_r+0x1ac>
80000b94:	15400713          	li	a4,340
80000b98:	00b76863          	bltu	a4,a1,80000ba8 <_free_r+0x228>
80000b9c:	00f7d713          	srli	a4,a5,0xf
80000ba0:	07770713          	addi	a4,a4,119
80000ba4:	f89ff06f          	j	80000b2c <_free_r+0x1ac>
80000ba8:	55400513          	li	a0,1364
80000bac:	07e00713          	li	a4,126
80000bb0:	f6b56ee3          	bltu	a0,a1,80000b2c <_free_r+0x1ac>
80000bb4:	0127d713          	srli	a4,a5,0x12
80000bb8:	07c70713          	addi	a4,a4,124
80000bbc:	f71ff06f          	j	80000b2c <_free_r+0x1ac>
80000bc0:	0085a583          	lw	a1,8(a1)
80000bc4:	00b50863          	beq	a0,a1,80000bd4 <_free_r+0x254>
80000bc8:	0045a703          	lw	a4,4(a1)
80000bcc:	ffc77713          	andi	a4,a4,-4
80000bd0:	fee7e8e3          	bltu	a5,a4,80000bc0 <_free_r+0x240>
80000bd4:	00c5a503          	lw	a0,12(a1)
80000bd8:	f85ff06f          	j	80000b5c <_free_r+0x1dc>
80000bdc:	00008067          	ret

80000be0 <cleanup_glue>:
80000be0:	ff010113          	addi	sp,sp,-16
80000be4:	00812423          	sw	s0,8(sp)
80000be8:	00058413          	mv	s0,a1
80000bec:	0005a583          	lw	a1,0(a1)
80000bf0:	00912223          	sw	s1,4(sp)
80000bf4:	00112623          	sw	ra,12(sp)
80000bf8:	00050493          	mv	s1,a0
80000bfc:	00058463          	beqz	a1,80000c04 <cleanup_glue+0x24>
80000c00:	fe1ff0ef          	jal	ra,80000be0 <cleanup_glue>
80000c04:	00040593          	mv	a1,s0
80000c08:	00812403          	lw	s0,8(sp)
80000c0c:	00c12083          	lw	ra,12(sp)
80000c10:	00048513          	mv	a0,s1
80000c14:	00412483          	lw	s1,4(sp)
80000c18:	01010113          	addi	sp,sp,16
80000c1c:	d65ff06f          	j	80000980 <_free_r>

80000c20 <_reclaim_reent>:
80000c20:	80c1a783          	lw	a5,-2036(gp) # 8000184c <_impure_ptr>
80000c24:	10a78263          	beq	a5,a0,80000d28 <_reclaim_reent+0x108>
80000c28:	04c52783          	lw	a5,76(a0)
80000c2c:	fe010113          	addi	sp,sp,-32
80000c30:	00812c23          	sw	s0,24(sp)
80000c34:	00912a23          	sw	s1,20(sp)
80000c38:	01212823          	sw	s2,16(sp)
80000c3c:	00112e23          	sw	ra,28(sp)
80000c40:	01312623          	sw	s3,12(sp)
80000c44:	00050413          	mv	s0,a0
80000c48:	00000493          	li	s1,0
80000c4c:	08000913          	li	s2,128
80000c50:	04079463          	bnez	a5,80000c98 <_reclaim_reent+0x78>
80000c54:	04042583          	lw	a1,64(s0)
80000c58:	00058663          	beqz	a1,80000c64 <_reclaim_reent+0x44>
80000c5c:	00040513          	mv	a0,s0
80000c60:	d21ff0ef          	jal	ra,80000980 <_free_r>
80000c64:	14842583          	lw	a1,328(s0)
80000c68:	04058c63          	beqz	a1,80000cc0 <_reclaim_reent+0xa0>
80000c6c:	14c40493          	addi	s1,s0,332
80000c70:	04958863          	beq	a1,s1,80000cc0 <_reclaim_reent+0xa0>
80000c74:	0005a903          	lw	s2,0(a1)
80000c78:	00040513          	mv	a0,s0
80000c7c:	d05ff0ef          	jal	ra,80000980 <_free_r>
80000c80:	00090593          	mv	a1,s2
80000c84:	fedff06f          	j	80000c70 <_reclaim_reent+0x50>
80000c88:	009585b3          	add	a1,a1,s1
80000c8c:	0005a583          	lw	a1,0(a1)
80000c90:	00059e63          	bnez	a1,80000cac <_reclaim_reent+0x8c>
80000c94:	00448493          	addi	s1,s1,4
80000c98:	04c42583          	lw	a1,76(s0)
80000c9c:	ff2496e3          	bne	s1,s2,80000c88 <_reclaim_reent+0x68>
80000ca0:	00040513          	mv	a0,s0
80000ca4:	cddff0ef          	jal	ra,80000980 <_free_r>
80000ca8:	fadff06f          	j	80000c54 <_reclaim_reent+0x34>
80000cac:	0005a983          	lw	s3,0(a1)
80000cb0:	00040513          	mv	a0,s0
80000cb4:	ccdff0ef          	jal	ra,80000980 <_free_r>
80000cb8:	00098593          	mv	a1,s3
80000cbc:	fd5ff06f          	j	80000c90 <_reclaim_reent+0x70>
80000cc0:	05442583          	lw	a1,84(s0)
80000cc4:	00058663          	beqz	a1,80000cd0 <_reclaim_reent+0xb0>
80000cc8:	00040513          	mv	a0,s0
80000ccc:	cb5ff0ef          	jal	ra,80000980 <_free_r>
80000cd0:	03842783          	lw	a5,56(s0)
80000cd4:	02078c63          	beqz	a5,80000d0c <_reclaim_reent+0xec>
80000cd8:	03c42783          	lw	a5,60(s0)
80000cdc:	00040513          	mv	a0,s0
80000ce0:	000780e7          	jalr	a5
80000ce4:	2e042583          	lw	a1,736(s0)
80000ce8:	02058263          	beqz	a1,80000d0c <_reclaim_reent+0xec>
80000cec:	00040513          	mv	a0,s0
80000cf0:	01812403          	lw	s0,24(sp)
80000cf4:	01c12083          	lw	ra,28(sp)
80000cf8:	01412483          	lw	s1,20(sp)
80000cfc:	01012903          	lw	s2,16(sp)
80000d00:	00c12983          	lw	s3,12(sp)
80000d04:	02010113          	addi	sp,sp,32
80000d08:	ed9ff06f          	j	80000be0 <cleanup_glue>
80000d0c:	01c12083          	lw	ra,28(sp)
80000d10:	01812403          	lw	s0,24(sp)
80000d14:	01412483          	lw	s1,20(sp)
80000d18:	01012903          	lw	s2,16(sp)
80000d1c:	00c12983          	lw	s3,12(sp)
80000d20:	02010113          	addi	sp,sp,32
80000d24:	00008067          	ret
80000d28:	00008067          	ret

80000d2c <_sbrk>:
80000d2c:	ff010113          	addi	sp,sp,-16
80000d30:	00812423          	sw	s0,8(sp)
80000d34:	81c1a783          	lw	a5,-2020(gp) # 8000185c <heap_end.2474>
80000d38:	01212023          	sw	s2,0(sp)
80000d3c:	00112623          	sw	ra,12(sp)
80000d40:	00912223          	sw	s1,4(sp)
80000d44:	00050913          	mv	s2,a0
80000d48:	04079a63          	bnez	a5,80000d9c <_sbrk+0x70>
80000d4c:	00000513          	li	a0,0
80000d50:	00000593          	li	a1,0
80000d54:	00000613          	li	a2,0
80000d58:	00000693          	li	a3,0
80000d5c:	00000713          	li	a4,0
80000d60:	0d600893          	li	a7,214
80000d64:	00000073          	ecall
80000d68:	00050493          	mv	s1,a0
80000d6c:	02055663          	bgez	a0,80000d98 <_sbrk+0x6c>
80000d70:	084000ef          	jal	ra,80000df4 <__errno>
80000d74:	409004b3          	neg	s1,s1
80000d78:	00952023          	sw	s1,0(a0)
80000d7c:	fff00513          	li	a0,-1
80000d80:	00c12083          	lw	ra,12(sp)
80000d84:	00812403          	lw	s0,8(sp)
80000d88:	00412483          	lw	s1,4(sp)
80000d8c:	00012903          	lw	s2,0(sp)
80000d90:	01010113          	addi	sp,sp,16
80000d94:	00008067          	ret
80000d98:	80a1ae23          	sw	a0,-2020(gp) # 8000185c <heap_end.2474>
80000d9c:	81c1a503          	lw	a0,-2020(gp) # 8000185c <heap_end.2474>
80000da0:	00000593          	li	a1,0
80000da4:	00000613          	li	a2,0
80000da8:	00a90533          	add	a0,s2,a0
80000dac:	00000693          	li	a3,0
80000db0:	00000713          	li	a4,0
80000db4:	00000793          	li	a5,0
80000db8:	0d600893          	li	a7,214
80000dbc:	00000073          	ecall
80000dc0:	00050493          	mv	s1,a0
80000dc4:	00055a63          	bgez	a0,80000dd8 <_sbrk+0xac>
80000dc8:	409004b3          	neg	s1,s1
80000dcc:	028000ef          	jal	ra,80000df4 <__errno>
80000dd0:	00952023          	sw	s1,0(a0)
80000dd4:	fff00493          	li	s1,-1
80000dd8:	81c1a783          	lw	a5,-2020(gp) # 8000185c <heap_end.2474>
80000ddc:	fff00513          	li	a0,-1
80000de0:	00f90933          	add	s2,s2,a5
80000de4:	f9249ee3          	bne	s1,s2,80000d80 <_sbrk+0x54>
80000de8:	8091ae23          	sw	s1,-2020(gp) # 8000185c <heap_end.2474>
80000dec:	00078513          	mv	a0,a5
80000df0:	f91ff06f          	j	80000d80 <_sbrk+0x54>

80000df4 <__errno>:
80000df4:	80c1a503          	lw	a0,-2036(gp) # 8000184c <_impure_ptr>
80000df8:	00008067          	ret
