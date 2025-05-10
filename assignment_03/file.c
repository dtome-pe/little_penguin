#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>


/*
 * do_work - perform some pointless computation with a delay
 *
 * Returns the product of the input value after delay.
 */

int do_work(int *my_int, int retval) 
{
	int x;
	int y = *my_int;
	int z;

	for (x = 0; x < y; ++x) {
		udelay(10);
	}

	if (y < 10)
		pr_info("We slept a long time!");

	z = x * y;
	return z;
}

int my_init(void) 
{
	int x = 10;
	
	x = do_work(&x, x);
	return x;
}

void my_exit(void) 
{
	/*Nothing to clean up.*/
}

module_init(my_init);
module_exit(my_exit);
