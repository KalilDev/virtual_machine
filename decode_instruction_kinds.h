#include"types.h"

struct {
} kind_no_words;
struct {
    word_t word;
} kind_one_word;
struct {
    register_id register_;
} kind_one_register;
struct {
    register_id register1, register2;
} kind_two_registers;
struct {
    word_t word;
    register_id register_;
} kind_one_word_one_register;
struct {
    interrupt_id interrupt;
} kind_interrupt;
struct {
    pointer_t pointer;
} kind_one_pointer;
struct {
    word_t word;
    pointer_t pointer;
} kind_one_word_one_pointer;