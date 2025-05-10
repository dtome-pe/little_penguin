/* 

 The simplest kernel module. 

 */ 

#include <linux/module.h> /* Needed by all modules */ 
#include <linux/printk.h> /* Needed for pr_info() */ 

 

static int __init say_hello(void) 
{ 

    pr_info("Hello world !\n"); 
    return 0; 

} 

 

static void __exit clean(void) 
{ 
    pr_info("Cleaning up module.\n"); 

} 

MODULE_LICENSE("GPL");

module_init(say_hello);
module_exit(clean);
