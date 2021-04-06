/* For each probe you need to allocate a kprobe structure */
#include <linux/kprobes.h>


static struct kprobe kp = {
	.symbol_name	= "ip_rcv",
};

static int handler_pre(struct kprobe *kp, struct pt_regs *regs)
{
	printk("%s kp:%p regs:%p\n", __func__, kp, regs);
	return 0;
};


static void handler_post(struct kprobe *kp, struct pt_regs *regs, unsigned long flags)
{
	printk("%s kp:%p regs:%p flags:0x%016X\n", __func__, kp, regs, flags);
};


static int handler_fault(struct kprobe *kp, struct pt_regs *regs, int trapnr)
{
	printk("%s kp:%p regs:%p trapnr:%d\n", __func__, kp, regs, trapnr);
	return 0;
};
 
int cm_kprobe_init(void)
{
	int ret;
	kp.pre_handler = handler_pre;
	kp.post_handler = handler_post;
	kp.fault_handler = handler_fault;
 
	ret = register_kprobe(&kp);
	if (ret < 0) {
		printk(KERN_INFO "register_kprobe failed, returned %d\n", ret);
		return ret;
	}
	printk(KERN_INFO "Planted kprobe at %p\n", kp.addr);
	return 0;
}
 
void cm_kprobe_exit(void)
{
	unregister_kprobe(&kp);
	printk(KERN_INFO "kprobe at %p unregistered\n", kp.addr);
}
 
EXPORT_SYMBOL(cm_kprobe_init);
EXPORT_SYMBOL(cm_kprobe_exit);
//MODULE_LICENSE("GPL");
