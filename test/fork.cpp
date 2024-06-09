#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    for(int i=1; i<5; i++){
        if(fork() == 0)    // f0
            fork();    // f1
        else{
            fork();    // f2
            fork();    // f3
        }
    }
    return 0;    // end program
}