#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/init.h>

#define BUF_LEN 8

static char login[] = "dtome-pe";

/*
** This function will be called when we write the Misc Device file
*/

static ssize_t etx_misc_write(struct file *file, const char __user *buf,
               size_t len, loff_t *ppos)
{
	char user_input[BUF_LEN];

	if (len != BUF_LEN)
		return -EINVAL;

	if (copy_from_user(user_input, buf, BUF_LEN))
		return -EFAULT;

    	if (strncmp(user_input, login, BUF_LEN) == 0)
        	return len;
    	else
        	return -EINVAL;
}

/*
** This function will be called when we read the Misc Device file
*/


static ssize_t etx_misc_read(struct file *filp, char __user *buf,
                    size_t count, loff_t *f_pos)
{;
	ssize_t len = strlen(login);

	if (*f_pos >= len)
		return 0;
	
	if (count > len - *f_pos)
		count = len - *f_pos;

	if (copy_to_user(buf, login + *f_pos, count))
		return -EFAULT;

	*f_pos += count;

    	return len;
}



static const struct file_operations fops = {
	.owner		= THIS_MODULE,
	.write		= etx_misc_write,
	.read		= etx_misc_read,
};


struct miscdevice etx_misc_device = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= "fortytwo",
	.fops	= &fops,
};

static int __init misc_init(void)
{
	int error;

	error = misc_register(&etx_misc_device);
  	if (error) {
		pr_err("misc_register failed!!!\n");
		return error;
	}
    
	pr_info("misc_register init done!!!\n");
	return 0;
}

static void __exit misc_exit(void)
{
	misc_deregister(&etx_misc_device);
    	pr_info("misc_register exit donte!!!\n");
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("dtome-pe");
MODULE_DESCRIPTION("Simple driver for a misc char device");


module_init(misc_init);
module_exit(misc_exit);
