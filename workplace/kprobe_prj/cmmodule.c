#include <linux/kernel.h>
#include <linux/module.h>

extern int cm_kprobe_init(void);
extern void cm_kprobe_exit(void);

MODULE_LICENSE ("GPL");//开源协议GPL 或者Dual BSD
MODULE_AUTHOR ("Chenming");//作者
MODULE_DESCRIPTION ("MY_TEST");//描述此驱动

//EXPORT_NO_SYMBOLS;//不导出函数 可以不写
//EXPORT_SYMBOL(hello_data);//导出hello_data

int test_init(void)
{
	printk(KERN_INFO "hello world\n");
	cm_kprobe_init();
	return 0;
}
void test_exit(void)
{
	printk(KERN_INFO "goodbye world\n");
	cm_kprobe_exit();
}
module_init(test_init); //注册DriverEntry	 
module_exit(test_exit); //注册DriverUnload
