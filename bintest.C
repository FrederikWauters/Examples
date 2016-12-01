/* Hello World program */

#include<stdio.h>

main()
{
    int a = 255;
    printf("a  = %0x\n",a);
    
    int b = 0xF0;
    printf("b  = %0x\n",b);
    
    int c = a & b;
    printf("c  = %0x\n",c);
    
    a = 0x9F8;
    
    unsigned char byte = (char)a;
    
    printf("a = %0x\n",a);
    printf("byte = %0x\n",byte);
    
}
