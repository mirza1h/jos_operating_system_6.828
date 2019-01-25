// buggy program - causes a divide by zero exception

#include <inc/lib.h>
//CHALLENGE
int zero;
void div_zero_handler(struct UTrapframe * utf) {
	cprintf("Error code: %x\n",utf->utf_err);
	cprintf("Dividing by zero! Not cool!\n");
	sys_env_destroy(sys_getenvid());
};

void
umain(int argc, char **argv)
{
	zero = 0;
	set_pgfault_handler(div_zero_handler);
	cprintf("1/0 is %08x!\n", 1/zero);
}

