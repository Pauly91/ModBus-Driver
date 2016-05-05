#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <asm/io.h>
 
#include <linux/serial_reg.h>
 
#define SERIAL_PORT_BASE 0x9000F000
#define LCR 0x9000F00C

 
int __init init_module()
{
    int i;
    u8 data;
    //printk(KERN_INFO "Hey I am a serial Driver");
    //data = inb(SERIAL_PORT_BASE + UART_LCR);
    data = inb(SERIAL_PORT_BASE );
    printk(KERN_INFO "data :%d\n",data);
    for (i = 0; i < 20; i++)
    {
        /* Pulling the Tx line low */
        printk(KERN_INFO "Count :%d\n",i);
        //data |= UART_LCR_SBC;
        data = 127;
        outb(data, LCR);
        printk(KERN_INFO "data :%d\n",data);
        //outb(data, SERIAL_PORT_BASE + UART_LCR);
        outb(data, SERIAL_PORT_BASE);

        msleep(500);
        /* Defaulting the Tx line high */
        //data &= ~UART_LCR_SBC;
        data = 255;
        outb(data, LCR);
        printk(KERN_INFO "data :%d\n",data);
        //outb(data, SERIAL_PORT_BASE + UART_LCR);
        outb(data, SERIAL_PORT_BASE);

        msleep(500);
    }
    return 0;
}
 
void __exit cleanup_module()
{
    printk(KERN_INFO "Okay, The dude just killed me !!\n");
}
// Credits given below ! 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anil Kumar Pugalia <email_at_sarika-pugs_dot_com>");
MODULE_DESCRIPTION("Blinking LED Hack");
