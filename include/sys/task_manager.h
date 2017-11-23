
#ifndef _PROC_H
#define _PROC_H

struct vma_struct{
	uint64_t vstart;
	uint64_t vend;
	struct vma_struct* nextvma;
};

typedef struct vma_struct vma;


struct mm{
	vma* vma_list;
};

typedef struct mm mm_struct;

struct pcb_t
{
	uint64_t pid;
	uint64_t ppid;
	uint64_t entry_point;
	uint64_t u_stack;
	uint64_t k_stackbase;
	uint64_t k_stack;
	uint64_t state;
	uint64_t cr3;
	mm_struct mmstruct;
	uint64_t heap_top;
	struct pcb_t *next;
};

typedef struct pcb_t PCB;

void switch_to();
void init_proc();
void test();

void syscall_init();

void context1();

void context2();
#endif