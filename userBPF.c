#include <linux/kernel.h>
#include <linux/filter.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>




long bpf_syscall(void* p, int cpu_num)
{
    return syscall(549, p, cpu_num);
}

int main(int argc, char *argv[])

{
    for (int i = 0; i < 1000; i++){
    unsigned char *bpf_data = malloc(1024);
    bpf_syscall(bpf_data, i);
    int bpf_flags = (bpf_data[0]) << 24 | (bpf_data[1]) << 16 | (bpf_data[2]) << 8 | (bpf_data[3]);
    printf("%d\n", bpf_flags);
    }

}
