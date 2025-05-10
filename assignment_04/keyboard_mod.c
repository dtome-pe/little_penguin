#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/usb/ch9.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Minimal module that loads on USB keyboard connection");

static int __init keyboard_init(void)
{
    pr_info("keyboard_mod: loaded (autoload test)\n");
    return 0;
}

static void __exit keyboard_exit(void)
{
    pr_info("keyboard_mod: unloaded\n");
}

module_init(keyboard_init);
module_exit(keyboard_exit);
