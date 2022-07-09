#include <stdarg.h>
#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define S21_NULL (void *)0

typedef unsigned long int s21_size_t;

typedef struct specif_paramets {
  char specificator;
  int flag_align;
  int flag_sign;
  int flag_space;
  int flag_sharp;
  int flag_zero;
  int is_negative;
  int width;
  int out_len;
  int arg_len;
  int add_zeroes;
  int precision;
  int flag_star_width;
  int flag_star_precision;
  int type_short;
  int type_long;
  int type_ld;
} spec_struct;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

char *s21_to_low_up_func(const char *str, char a, char z, int sdvig);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);
void write_options_struct(spec_struct *options, const char *str, int len, va_list ap);
void struct_init(spec_struct *options);
char *sprintf_cs(spec_struct *options, va_list ap);
char *sprintf_diouxXp(spec_struct *options, va_list ap);
unsigned long sprintf_diouxXp_digit(spec_struct *options, va_list ap);
void sprintf_diouxXp_buffer(char *buffer, spec_struct *options,
                        unsigned long digit);
void sprintf_num_sys_to_str(char *str, unsigned long int lint, int num_sys);
void reverse_str(char *str);
char *sprintf_eEfgG(spec_struct *options, va_list ap);
void write_exponent(int *exponent, long double *digit);
char *digit_ull_to_string(unsigned long long x);

int s21_sscanf(const char *str, const char *format, ...);
void sscanf_options_struct(spec_struct *options, const char *str, int str_len);
int sscanf_d(long long int *out_int, char *in_str, int *in_str_index, int width);
long long int str_to_int(char *str, int notation);
int sscanf_x(long long int *out_int, char *in_str, int *in_str_index, int width);
int sscanf_o(long long int *out_int, char *in_str, int *in_str_index, int width);
int sscanf_i(long long int *out_int, char *in_str, int *in_str_index, int width);
int sscanf_hex(long long int *out_int, char *in_str, int *in_str_index, int width);
int sscanf_f(long double *out_float, char *in_str, int *in_str_index, int width);
int sscanf_e(long double *out_float, char *in_str, int *in_str_index, int width);
int check_inf_nan(long double *out_float, char *in_str, int *in_str_index, int width);

#endif  // SRC_S21_STRING_H_
