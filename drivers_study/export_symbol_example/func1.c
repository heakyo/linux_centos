/*
 * a simple kernel module: hello
 *
 * Copyright (C) 2014 Barry Song  (baohua@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/init.h>
#include <linux/module.h>

static int func1(void)
{
	printk("%s()\n", __func__);
	return 0;
}
EXPORT_SYMBOL(func1);

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World enter\n");
	return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Hello World exit\n ");
}
module_exit(hello_exit);

MODULE_AUTHOR("Marvin Ma");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("a simplest module");
