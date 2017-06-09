main(int c,char*v[]){char*s=v[1];while(*s)putchar(*s>64?"nopqrstuvwxyzabcdefghijklm"[(*s++|32)-97]:*s++);putchar(10);}
