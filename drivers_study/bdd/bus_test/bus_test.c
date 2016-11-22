#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>

MODULE_AUTHOR("yinjiabin");
MODULE_LICENSE("Dual BSD/GPL");

static char *Version = "$Revision: 1.0 $";

static ssize_t show_bus_version(struct bus_type *bus, char *buf)
{
        return snprintf(buf, PAGE_SIZE, "%s\n", Version);
}

/*�ں˴�������˶��壺#define BUS_ATTR(_name, _mode, _show, _store) \
struct bus_attribute bus_attr_##_name = __ATTR(_name, _mode, _show, _store),

����bus_attr_��Ϊ������name��ǰ׺���������ߵ��������ơ���Ӧ�������bus_attr_version*/
static BUS_ATTR(version, S_IRUGO, show_bus_version, NULL);


/*��һ�����豸������������ӵ��������ʱ,�÷��������á������ж�ָ�������������Ƿ��ܴ���ָ�����豸��������,�򷵻ط���ֵ��*/
static int my_match(struct device *dev, struct device_driver *driver)
{
        return !strncmp(dev->kobj.name, driver->name, strlen(driver->name));
}


/*��������*/
struct bus_type my_bus_type = {
        .name = "my_bus",  //��������
        .match = my_match, //����match����ָ��
};
EXPORT_SYMBOL(my_bus_type); //����my_bus_type


/*ģ����غ���*/
static int __init my_bus_init(void)
{
        int ret;

        /*ע������*/
        ret = bus_register(&my_bus_type);
        if (ret)
                return ret;

        /*���������ļ�--- create version file in dir my_bus */
        if (bus_create_file(&my_bus_type, &bus_attr_version))
                printk(KERN_NOTICE "Fail to create version attribute!\n");

        return ret;
}

/*ģ��ж�غ���*/
static void my_bus_exit(void)
{
        bus_unregister(&my_bus_type);
}

module_init(my_bus_init);
module_exit(my_bus_exit);