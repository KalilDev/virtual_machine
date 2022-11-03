













unsigned int step = 10;
unsigned int iterations = 100;
unsigned int result = 0;

int main() {
    unsigned int r2 = step;
    unsigned int r3 = iterations;
    unsigned int r1 = 0;
    unsigned int r4 = 0;
    loop_head:
    r3--;
    if (r1 == r3) {
        goto end;
    }
    r4 += r2;
    goto loop_head;
    end:
    result = r4
}



#00 jump _start(#0e):
_step:
#06 10
_iterations:
#0a 100
_start:
#0e read_ r2 _step(#06)
#0f read_ r3 _iterations(#0a)
#16 load 0 r1
#16 load 0 r4
_loop_head:
#1d dec r3
#25 jump_z _end(#30)
#2a add r4 r2
#2d jmp _loop_head(#1d)
_end
#30 write_ r4 _result(#37)
#36 halt
_result:
#37 0




























