#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x73064479, "struct_module" },
	{ 0xa5423cc4, "param_get_int" },
	{ 0xcb32da10, "param_set_int" },
	{ 0xc69963cd, "bio_endio" },
	{ 0xb30543ef, "kmap_atomic" },
	{ 0x43b40de7, "kunmap_atomic" },
	{ 0x8536fabc, "elv_next_request" },
	{ 0x51ba507f, "end_request" },
	{ 0xd88f695a, "__mod_timer" },
	{ 0x7d11c268, "jiffies" },
	{ 0xb279da12, "pv_lock_ops" },
	{ 0x973873ab, "_spin_lock" },
	{ 0xff4a9b50, "blk_queue_make_request" },
	{ 0x2716e4e3, "blk_alloc_queue" },
	{ 0x6111e1bc, "init_timer" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xffa7762c, "add_disk" },
	{ 0x701d0ebd, "snprintf" },
	{ 0xdd584a72, "alloc_disk" },
	{ 0xa90e1105, "blk_queue_hardsect_size" },
	{ 0x4dc918c8, "blk_init_queue" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x71a50dbc, "register_blkdev" },
	{ 0xb72397d5, "printk" },
	{ 0x37a0cba, "kfree" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0x5a12892e, "kobject_put" },
	{ 0x36ad57b3, "put_disk" },
	{ 0x7e7aacf8, "del_gendisk" },
	{ 0xe910b532, "del_timer_sync" },
	{ 0x999e8297, "vfree" },
	{ 0xb3fae115, "blk_cleanup_queue" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "736A886424B7A5C70F336CB");
