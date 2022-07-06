#include <check.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "s21_string.h"

#define BUFF_SIZE 512

START_TEST(sprintf_1) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 48, 1), s21_memchr(s1, 48, 1));
} END_TEST

START_TEST(sprintf_2) {
  char str_9[12] = "Hello world";
  ck_assert_str_eq(memchr(str_9, 'w', strlen(str_9)), s21_memchr(str_9, 'w', s21_strlen(str_9)));
} END_TEST

START_TEST(sprintf_3) {
  char str_3[12] = "i am\nproger";
  ck_assert_str_eq(memchr(str_3, '\n', 6), s21_memchr(str_3, '\n', 6));
} END_TEST

START_TEST(sprintf_4) {
  char str_5[5] = " \n\0\0";
  ck_assert_str_eq(memchr(str_5, '\0', 4), s21_memchr(str_5, '\0', 4));
} END_TEST

START_TEST(sprintf_6) {
  char str_1[12] = "Hello world";
  ck_assert_str_eq(memchr(str_1, 'w', strlen(str_1)), s21_memchr(str_1, 'w', s21_strlen(str_1)));
} END_TEST

START_TEST(sprintf_8) {
  char str_1[20] = "Per aspera ad astra";
  ck_assert_ptr_eq(memchr(str_1, 'p', 2), s21_memchr(str_1, 'p', 2));
} END_TEST

START_TEST(sprintf_9) {
  char str_1[4] = "a\n\0";
  ck_assert_str_eq(memchr(str_1, '\0', 4), s21_memchr(str_1, '\0', 4));
} END_TEST

START_TEST(sprintf_10) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 2, 4), s21_memchr(s1, 2, 4));
} END_TEST

START_TEST(sprintf_11) {
  char str_3[12] = "i am\nproger";
  ck_assert_ptr_eq(memchr(str_3, 'p', 2), s21_memchr(str_3, 'p', 2));
} END_TEST

START_TEST(sprintf_12) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 85, 1), s21_memchr(s1, 85, 1));
} END_TEST

START_TEST(sprintf_13) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
} END_TEST

START_TEST(sprintf_14) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
} END_TEST

START_TEST(sprintf_15) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
} END_TEST

START_TEST(memmove_1) {
  char str[11] = "1234567890";
  ck_assert_str_eq(memmove(str + 4, str + 3, 3), s21_memmove(str + 4, str + 3, 3));
} END_TEST

START_TEST(memmove_2) {
  char str[11] = "321qwerty";
  ck_assert_str_eq(memmove(str + 4, str + 3, 0), s21_memmove(str + 4, str + 3, 0));
} END_TEST

START_TEST(memmove_3) {
  char str_1[50] = " schhol21\0";
  char str_2[12] = "i am\nproger";
  ck_assert_str_eq(memmove(str_1, str_2, 10), s21_memmove(str_1, str_2, 10));
} END_TEST

START_TEST(memmove_4) {
  char str_1[50] = " schhol21\0";
  char str_2[12] = "s_21\n\t";
  ck_assert_str_eq(memmove(str_1, str_2, 0), s21_memmove(str_1, str_2, 0));
} END_TEST

START_TEST(memmove_5) {
  char str_1[11] = "1234567890";
  char str_2[50] = " \n\0\0";
  ck_assert_str_eq(memmove(str_1, str_2, 2), s21_memmove(str_1, str_2, 2));
} END_TEST

START_TEST(memmove_6) {
  char str_1[10] = " a\n\0";
  char str_2[10] = "\0";
  ck_assert_str_eq(memmove(str_1, str_2, 2), s21_memmove(str_1, str_2, 2));
} END_TEST

START_TEST(memmove_7) {
  char str_1[10] = "t\n\f\t";
  char str_2[10] = "e5_=\n";
  ck_assert_str_eq(s21_memmove(str_1 + 2, str_2 + 2, 3), memmove(str_1 + 2, str_2 + 2, 3));
} END_TEST

START_TEST(memmove_8) {
  char str_1[15] = "ysbsdfn__--568\0";
  char str_3[10] = "lock -l";
  ck_assert_str_eq(s21_memmove(str_1, str_3, 6), memmove(str_1, str_3, 0));
} END_TEST

START_TEST(memmove_9) {
  char str_1[10] = "0";
  char str_3[10] = "\0";
  ck_assert_str_eq(s21_memmove(str_1, str_3, 8), memmove(str_1, str_3, 10));
} END_TEST

START_TEST(memmove_10) {
  char str_1[10] = "string(58)";
  char str_3[10] = "978=\0";
  ck_assert_str_eq(s21_memmove(str_1, str_3, 10), memmove(str_1, str_3, 10));
} END_TEST

START_TEST(memmove_11) {
  char str_1[11] = "1234567890";
  char str_2[11] = "1234567890";
  char str_4[12] = "i am\nproger";
  char str_3[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_7[10] = "\0";
  ck_assert_str_eq(memmove(str_1 + 4, str_1 + 3, 3), s21_memmove(str_1 + 4, str_1 + 3, 3));
  ck_assert_str_eq(memmove(str_2 + 4, str_2 + 3, 0), s21_memmove(str_2 + 4, str_2 + 3, 0));
  ck_assert_str_eq(memmove(str_3, str_4, 10), s21_memmove(str_3, str_4, 10));
  ck_assert_str_eq(memmove(str_3, str_4, 0), s21_memmove(str_3, str_4, 0));
  ck_assert_str_eq(memmove(str_2, str_5, 2), s21_memmove(str_2, str_5, 2));
  ck_assert_str_eq(memmove(str_6, str_7, 2), s21_memmove(str_6, str_7, 2));
} END_TEST

START_TEST(memmove_12) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_pstr_eq(memmove(s1, s2, 6), s21_memmove(s1, s2, 6));
  ck_assert_pstr_eq(memmove(s2, s1, 6), s21_memmove(s2, s1, 6));
  ck_assert_pstr_eq(memmove(s1, s1, 6), s21_memmove(s1, s1, 6));
} END_TEST

START_TEST(memcpy_1) {
char str_5[3] = "a\n\0";
char str_6[3] = "\0";
ck_assert_str_eq(memcpy(str_5, str_6, 2), s21_memcpy(str_5, str_6, 2));
} END_TEST

START_TEST(memcpy_2) {
char str_1[] = "\0";
char str_2[] = " ";
ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 1));
} END_TEST

START_TEST(memcpy_3) {
char str_1[] = "copy_! ";
char str_2[] = "n66";
ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
} END_TEST

START_TEST(memcpy_4) {
char str_1[] = "\n/n";
char str_2[] = "-55";
ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
} END_TEST

START_TEST(memcpy_5) {
char str_1[] = "5656";
char str_2[] = "\0\f";
ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
} END_TEST

START_TEST(memcpy_6) {
char str_1[] = "%hf*-5";
char str_2[] = "\0\f";
ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
} END_TEST

START_TEST(memcpy_7) {
char s1[255] = "QWERTY";
char s2[255] = "E";
ck_assert_pstr_eq(memcpy(s1, s2, 6), s21_memcpy(s1, s2, 6));
} END_TEST

START_TEST(memset_1) {
char str[10] = "123456789";
ck_assert_str_eq(memset(str, 'k', 3), s21_memset(str, 'k', 3));
} END_TEST

START_TEST(memset_2) {
char str1[15] = "1234567890";
char str2[15] = "5432167890";
int c = 'q';
int n = 10;
s21_memset(str1, c, n);
memset(str2, c, n);
ck_assert_mem_eq(str1, str2, 10);
} END_TEST

START_TEST(memset_3) {
char str1[15] = "qweqweqweqwe";
char str2[15] = "qweqweqweqwe";
int c = '\0';
int n = 5;
s21_memset(str1, c, n);
memset(str2, c, n);
ck_assert_mem_eq(str1, str2, 10);
} END_TEST

START_TEST(memset_4) {
char str1[15] = "qweqweqweqwe";
char str2[15] = "qweqweqweqwe";
int c = '\n';
int n = 5;
s21_memset(str1, c, n);
memset(str2, c, n);
ck_assert_mem_eq(str1, str2, 10);
} END_TEST

START_TEST(memset_5) {
char s1[255] = "QWERTY";
ck_assert_pstr_eq(memset(s1, 2, 6), s21_memset(s1, 2, 6));
} END_TEST

START_TEST(memcmp_1) {
char str[] = "Hello World";
char str1[] = "Hello World";
int n = '\0';
ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
} END_TEST

START_TEST(memcmp_2) {
char str[] = "Hello World";
char str1[] = "Hello World";
int n = 0;
ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
} END_TEST

START_TEST(memcmp_3) {
char str[] = "Hello";
char str1[] = "notequal";
int n = 5;
ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
} END_TEST

START_TEST(memcmp_4) {
char str[] = "Hello World";
char str1[] = "";
int n = 1;
ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
} END_TEST

START_TEST(memcmp_5) {
char str[] = "Hello World";
char str1[] = "";
int n = 1;
ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
} END_TEST

START_TEST(memcmp_6) {
char str_5[] = " \n\0\0";
char str_6[] = " a\n\0";
ck_assert_int_eq(memcmp(str_5, str_6, 3), s21_memcmp(str_5, str_6, 3));
} END_TEST

START_TEST(memcmp_7) {
char str[] = "abc";
char str1[] = "bca";
ck_assert_int_eq(memcmp(str, str1, 2), s21_memcmp(str, str1, 2));
} END_TEST

START_TEST(memcmp_8) {
char str_36[] = "Hello";
char str_37[] = "HeLlo";
ck_assert_int_eq(memcmp(str_36, str_37, 3), s21_memcmp(str_36, str_37, 3));
} END_TEST

START_TEST(memcmp_9) {
char str[] = "Per aspera ad astra";
char str1[] = "i am\nproger";
ck_assert_int_eq(memcmp(str, str1, 3), s21_memcmp(str, str1, 3));
} END_TEST

START_TEST(memcmp_10) {
char str[] = "Per aspera ad astra";
char str1[] = "i am\nproger";
ck_assert_int_eq(memcmp(str, str1, 0), s21_memcmp(str, str1, 0));
} END_TEST

START_TEST(memcmp_11) {
char str[] = "Per aspera ad astra";
char str1[] = "i am\nproger";
ck_assert_int_eq(memcmp(str, str1, 10), s21_memcmp(str, str1, 10));
} END_TEST

START_TEST(memcmp_12) {
char str[] = "Per aspera ad astra";
char str1[] = "\0\0\0\0\0";
ck_assert_int_eq(memcmp(str, str1, 5), s21_memcmp(str, str1, 5));
} END_TEST

START_TEST(memcmp_13) {
char str1[] = "t\200";
char str2[] = "t\0";
int n = 2;
ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
} END_TEST

START_TEST(memcmp_14) {
char str1[] = "test\0test";
char str2[] = "test";
int n = 3;
ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
} END_TEST

START_TEST(memcmp_15) {
char str1[] = "t\200";
char str2[] = "t\n";
int n = 2;
ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
} END_TEST

START_TEST(memcmp_16) {
char *s1 = "QWERTY";
char *s2 = "QWE";
ck_assert_int_eq(memcmp(s1, s2, 6), s21_memcmp(s1, s2, 6));
ck_assert_int_eq(memcmp(s1, s2, 4), s21_memcmp(s1, s2, 4));
} END_TEST

START_TEST(memcmp_17) {
s21_size_t n1 = 3;
void *str1 = "LUGANO!";
void *str2 = "LUGANO!";
ck_assert_int_eq(memcmp(str1, str2, n1), s21_memcmp(str1, str2, n1));
} END_TEST

START_TEST(memcmp_18) {
s21_size_t n2 = 3;
void *str1 = "LUGANO THE BEST!";
void *str2 = "LU GANO OF THE BEST!!";
ck_assert_int_eq(memcmp(str1, str2, n2), s21_memcmp(str1, str2, n2));
} END_TEST

START_TEST(memcmp_19) {
s21_size_t n3 = 3;
void *str1 = " LUGANO OF THE BEST!!";
void *str2 = "LUGANO!";
ck_assert_int_eq(memcmp(str1, str2, n3), s21_memcmp(str1, str2, n3));
} END_TEST

START_TEST(memcmp_20) {
char str1[] = "1234567890\n\0";
char str2[] = "1234567890\n\0";
ck_assert_int_eq((s21_memcmp(str1, str2, 11) == 0), (memcmp(str1, str2, 11) == 0));
}
END_TEST

START_TEST(memcmp_21) {
char str1[15] = "1234567890\0";
char str2[15] = "1234567890\0";
ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(memcmp_22) {
char str1[15] = "1234509876\n\0";
char str2[15] = "1234567890\n\0";
ck_assert_int_eq((s21_memcmp(str1, str2, 11) ==0), (memcmp(str1, str2, 11) == 0));
}
END_TEST

START_TEST(memcmp_23) {
char str1[15] = "1\n2\n3\n4\n5\n6\0";
char str2[15] = "1\n2\n3\n5\n6\n4\0";
ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(memcmp_24) {
char str1[15] = "\ngoogle\0";
char str2[15] = "\ngooble\0";
ck_assert_int_eq(s21_memcmp(str1, str2, 15), memcmp(str1, str2, 15));
}
END_TEST

START_TEST(memcmp_25) {
char str1[100] = "boobles\\//\'\0";
char str2[100] = "boobless\\//\'\00";
ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_26) {
char str1[100] = "boobless\\//\'\0";
char str2[100] = "boobless\\//\'\00";
ck_assert_int_eq(s21_memcmp(str1, str2, 50), memcmp(str1, str2, 50));
}
END_TEST

START_TEST(memcmp_27) {
char str1[20] = "Hello World\n";
char str2[20] = "Hello world";
ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_28) {
char str1[20] = "Hello World\0";
char str2[20] = "Hello World!\n\0";
ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_29) {
char str1[100] = "\0";
char str2[100] = "\0";
ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(strcmp_1) {
char str[] = " \n\0\0";
char str1[] = " a\n\0";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_2) {
char str[] = "Techie Delight  ";
char str1[] = "Ace the Technical Interviews";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_3) {
char str[] = "Techie";
char str1[] = "Techie";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_4) {
char str[] = "Techie";
char str1[] = "Techi";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_5) {
char str[] = "Techie";
char str1[] = "";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_6) {
char str[] = "Techie";
char str1[] = "Techia";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_7) {
char str[] = "Techie";
char str1[] = "Techis";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_8) {
char str[] = "";
char str1[] = "Techia";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_9) {
char str[] = "";
char str1[] = "";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_10) {
char str[] = "HELLO PRIVET MAMA YA V TESTE";
char str1[] = "\0";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_11) {
char str[] = "\0";
char str1[] = "\0";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_12) {
char str[] = "\0";
char str1[] = "HELLO PRIVET MAMA YA V TESTE";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_13) {
char str[] = "HELLO\0";
char str1[] = "HELLO PRIVET MAMA YA V TESTE";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_14) {
char str[] = "HEL\0";
char str1[] = "HEL \0";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_15) {
char str[] = " \n\0\0";
char str1[] = "HELO PRIVET MAMA YA V TESTE";
ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
} END_TEST

START_TEST(strcmp_16) {
char str_1[10] = "\0";
char str_7[50] = "Per aspera ad astra";
char str_4[50] = " schhol21\0";
char str_5[50] = " \n\0\0";
char str_6[10] = " a\n\0";
char str_11[] = "Hello";
char str_12[] = "lo";
ck_assert_int_eq(strcmp(str_1, str_7), s21_strcmp(str_1, str_7));
ck_assert_int_eq(strcmp(str_11, str_12), s21_strcmp(str_11, str_12));
ck_assert_int_eq(strcmp("", str_6), s21_strcmp("", str_6));
ck_assert_int_eq(strcmp(str_4, ""), s21_strcmp(str_4, ""));
ck_assert_int_eq(strcmp(str_5, str_6), s21_strcmp(str_5, str_6));
ck_assert_int_eq(strcmp(str_6, str_5), s21_strcmp(str_6, str_5));
} END_TEST

START_TEST(strcmp_17) {
char str1[] = "test\0test";
char str2[] = "test";
ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(strcmp_18) {
char *s1 = "QWERTY";
char *s2 = "E";
ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
ck_assert_int_eq(strcmp(s2, s1), s21_strcmp(s2, s1));
} END_TEST

START_TEST(strncmp_1) {
char str_1[10] = "\0";
char str_2[50] = "Per aspera ad astra";
ck_assert_int_eq(strncmp(str_1, str_2, 0), s21_strncmp(str_1, str_2, 0));
} END_TEST

START_TEST(strncmp_2) {
char str_1[12] = "i am\nproger";
char str_2[50] = " \n\0\0";
ck_assert_int_eq(strncmp(str_1, str_2, 5), s21_strncmp(str_1, str_2, 5));
} END_TEST

START_TEST(strncmp_3) {
char str_1[10] = " a\n\0";
char str_2[15] = "1234567890";
ck_assert_int_eq(strncmp(str_1, str_2, 3), s21_strncmp(str_1, str_2, 3));
} END_TEST

START_TEST(strncmp_4) {
char str_1[15] = "1234975654";
char str_2[15] = "1234567890";
ck_assert_int_eq(strncmp(str_1, str_2, 1), s21_strncmp(str_1, str_2, 1));
} END_TEST

START_TEST(strncmp_5) {
char str_1[15] = "1234567890";
char str_2[10] = "qwerty";
ck_assert_int_eq(strncmp(str_1, str_2, 5), s21_strncmp(str_1, str_2, 5));
} END_TEST

START_TEST(strncmp_6) {
char s1[255] = "QWERTY";
char s2[255] = "E";
ck_assert_int_eq(strncmp(s1, s2, 6), s21_strncmp(s1, s2, 6));
} END_TEST

START_TEST(strcpy_1) {
char str_1[50] = " \n\0\0";
char str_2[50] = " a\n\0";
ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
} END_TEST

START_TEST(strcpy_2) {
char str_1[50] = "\n\t";
char str_2[50] = "\056";
ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
} END_TEST

START_TEST(strcpy_3) {
char str_1[50] = "Hello";
char str_2[50] = "\t\n World!";
ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
} END_TEST

START_TEST(strcpy_4) {
char str_1[50] = "0";
char str_2[50] = "0\n\n6\t/t8";
ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
} END_TEST

START_TEST(strcpy_5) {
char str_1[50] = "\t/n\n\0/0 ";
char str_2[50] = " \t/n\n\0/0";
ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
} END_TEST

START_TEST(strcpy_6) {
char s1[255] = "QWERTY";
char s2[255] = "E";
char s3[255] = "E";
char s4[255] = "QWERTYUIO";
ck_assert_pstr_eq(strcpy(s1, s2), s21_strcpy(s3, s2));
ck_assert_pstr_eq(strcpy(s2, s4), s21_strcpy(s2, s4));
} END_TEST

START_TEST(strncpy_1) {
char str_1[50] = "qwerty";
char str_2[50] = "12345";
ck_assert_str_eq(strncpy(str_1, str_2, 2*2), s21_strncpy(str_1, str_2, 2*2));
} END_TEST

START_TEST(strncpy_2) {
char str_1[60] = "50 pdfh";
char str_2[50] = "HELLO!\n5";
ck_assert_str_eq(strncpy(str_1, str_2, 5-1), s21_strncpy(str_1, str_2, 5-1));
} END_TEST

START_TEST(strncpy_3) {
char str_1[50] = "\n/f\f/n";
char str_2[50] = "55/f/n\f\n";
ck_assert_str_eq(strncpy(str_1, str_2, 0), s21_strncpy(str_1, str_2, 0));
} END_TEST

START_TEST(strncpy_4) {
char str_1[20] = "abracadabra ";
char str_2[] = " 123";
ck_assert_str_eq(strncpy(str_1, str_2, 10), s21_strncpy(str_1, str_2, 10));
} END_TEST

START_TEST(strncpy_5) {
char str_1[50] = "s_=+*&/te   ";
char str_2[50] = "vosem'";
ck_assert_str_eq(strncpy(str_1, str_2, 6), s21_strncpy(str_1, str_2, 6));
} END_TEST

START_TEST(strncpy_6) {
char str_1[50] = "8h2f7y10/n5 6";
char str_2[] = "'40' -l";
ck_assert_str_eq(strncpy(str_1, str_2, 10/5), s21_strncpy(str_1, str_2, 10/5));
} END_TEST

START_TEST(strncpy_7) {
char s1[255] = "QWERTY";
char s2[255] = "Eeee";
ck_assert_pstr_eq(strncpy(s1, s2, 2), s21_strncpy(s1, s2, 2));
} END_TEST

START_TEST(strcat_1) {
char str_1[50] = "Hello";
char str_2[50] = "Hello World";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_2) {
char str_1[50] = "Hello";
char str_2[50] = "Hello World";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_3) {
char str_1[50] = "\0";
char str_2[50] = "123";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_4) {
char str_1[50] = "\0";
char str_2[50] = "\n\\\\\0";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_5) {
char str_1[50] = " 1 -";
char str_2[50] = "\t!";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_6) {
char str_1[50] = "\0";
char str_2[50] = "\0";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_7) {
char str_1[50] = "quas\0";
char str_2[50] = "\nwex\t\0";
ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
} END_TEST

START_TEST(strcat_8) {
char s1[255] = "QWERTY";
char *s2 = "E";
ck_assert_pstr_eq(strcat(s1, s2), s21_strcat(s1, s2));
} END_TEST

START_TEST(strncat_1) {
char str_1[100] = "Hello";
char str_2[100] = " World";
ck_assert_str_eq(strncat(str_1, str_2, 3), s21_strncat(str_1, str_2, 3));
} END_TEST

START_TEST(strncat_2) {
char str_1[100] = "\0";
char str_2[100] = "i am proger";
ck_assert_str_eq(strncat(str_1, str_2, 13), s21_strncat(str_1, str_2, 13));
} END_TEST

START_TEST(strncat_3) {
char str_1[100] = "\n";
char str_2[100] = "p-\0-roger";
ck_assert_str_eq(strncat(str_1, str_2, 9), s21_strncat(str_1, str_2, 9));
} END_TEST

START_TEST(strncat_4) {
char str_1[100] = "-\t-";
char str_2[100] = "\0";
ck_assert_str_eq(strncat(str_1, str_2, 2), s21_strncat(str_1, str_2, 2));
} END_TEST

START_TEST(strncat_5) {
char str_1[100] = " \b";
char str_2[100] = "  1 \n";
ck_assert_str_eq(strncat(str_1, str_2, 5), s21_strncat(str_1, str_2, 5));
} END_TEST

START_TEST(strncat_6) {
char str_1[100] = " 0 ";
char str_2[100] = "123";
ck_assert_str_eq(strncat(str_1, str_2, 0), s21_strncat(str_1, str_2, 0));
} END_TEST

START_TEST(strncat_7) {
char str_1[100] = " 0 ";
char str_2[100] = "qwer";
ck_assert_str_eq(strncat(str_1, str_2, 0+2), s21_strncat(str_1, str_2, 0+2));
} END_TEST

START_TEST(strncat_8) {
char str_1[100] = " 0 ";
char str_2[100] = "error";
ck_assert_str_eq(strncat(str_1, str_2, 4-1), s21_strncat(str_1, str_2, 4-1));
} END_TEST

START_TEST(strncat_9) {
char str_1[100] = "999";
char str_2[100] = "puckKK";
ck_assert_str_eq(strncat(str_1, str_2, 2*2), s21_strncat(str_1, str_2, 2*2));
} END_TEST

START_TEST(strncat_10) {
char s1[255] = "QWERTY";
char s2[255] = "E";
ck_assert_pstr_eq(strncat(s1, s2, 6), s21_strncat(s1, s2, 6));
} END_TEST

START_TEST(strchr_1) {
char str[] = "Hello world";
int c = 3;
ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_2) {
char str[] = "Hello world\0";
int c = 5;
ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_3) {
char str[] = "Hello world";
int c = 12;
ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_4) {
char str[] = "Hello world";
int c = '\0';
ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_5) {
char str[] = "";
int c = 0;
ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_6) {
char str[] = "a\n\0";
int c = 'a';
ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_7) {
char str[] = "aaaaaaaaaaaaaaaaaaa";
int c = 'b';
ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
} END_TEST

START_TEST(strchr_8) {
char *s1 = "QWERTY";
char s2 = 'E';
ck_assert_pstr_eq(strchr(s1, s2), s21_strchr(s1, s2));
} END_TEST

START_TEST(strrchr_1) {
char str[] = "Techie Delight – Ace the Technical Interviews";
int c = 'D';
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_2) {
char str[] = "Hello World";
int c = 'e';
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_3) {
char str[] = "Hello World";
int c = 'a';
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_4) {
char str[] = "Hello World";
int c = 0;
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_5) {
char str[] = "";
int c = 'a';
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_6) {
char str[] = "Privet verter";
int c = '\0';
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_7) {
char str[] = "a\n\0";
int c = '\0';
ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
} END_TEST

START_TEST(strrchr_8) {
char *s1 = "QWERTY";
char s2 = 'E';
ck_assert_pstr_eq(strrchr(s1, s2), s21_strrchr(s1, s2));
} END_TEST

START_TEST(strpbrk_1) {
char str[] = "\0";
char str1[] = "Per aspera ad astra";
ck_assert_ptr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
} END_TEST

START_TEST(strpbrk_2) {
char str[] = "Hello";
char str1[] = "lo";
ck_assert_str_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
} END_TEST

START_TEST(strpbrk_3) {
char str[] = "";
char str1[] = " a\n\0";
ck_assert_ptr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
} END_TEST

START_TEST(strpbrk_4) {
char str[] = " schhol21\0";
char str1[] = "";
ck_assert_ptr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
} END_TEST

START_TEST(strpbrk_5) {
char str[] = " \n\0\0";
char str1[] = " a\n\0";
ck_assert_str_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
} END_TEST

START_TEST(strpbrk_6) {
char str[] = "i am\nproger";
char str1[] = " a\n\0";
ck_assert_str_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
} END_TEST

START_TEST(strpbrk_7) {
char *str = "testtesttesttesttest";
char *str1 = "testtesttesttesttest";
ck_assert_ptr_eq(strpbrk(str, "abcabc"), s21_strpbrk(str1, "abcabc"));
} END_TEST

START_TEST(strpbrk_8) {
char *s1 = "QWERTY";
char *s2 = "WE";
ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
ck_assert_pstr_eq(strpbrk(s2, s1), s21_strpbrk(s2, s1));
ck_assert_pstr_eq(strpbrk(s1, s1), s21_strpbrk(s1, s1));
ck_assert_pstr_eq(strpbrk("", ""), s21_strpbrk("", ""));
} END_TEST

START_TEST(strtok_1) {
char str_24[15] = "This,is,my,way";
char str_25[2] = ",";
ck_assert_pstr_eq(strtok(str_24, str_25), s21_strtok(str_24, str_25));
} END_TEST

START_TEST(strtok_2) {
char str1[6] = "delim";
char str2[2] = "f";
ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
} END_TEST

START_TEST(strtok_3) {
char str[50] = "Per, :aspera;ad astra";
char str1[10] = " ,:\n\0";
ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
} END_TEST

START_TEST(strtok_4) {
char str[50] = "Per, :aspera;ad. astra";
char str1[10] = ",:\n\0";
ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
} END_TEST

START_TEST(strtok_5) {
char str[50] = "Per :aspn::::::era;ad. ast::::ra:";
char str1[10] = ":";
ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
} END_TEST

START_TEST(strtok_6) {
char str[50] = "test1/test2/test3/test4";
char str1[10] = "/";
ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
} END_TEST

START_TEST(strtok_7) {
char str[50] = "AadacAdxa";
char str1[10] = "a";
ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
} END_TEST

START_TEST(strtok_8) {
char str[] = "A";
char str1[] = "\0";
ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
} END_TEST

START_TEST(strtok_9) {
char str_24[15] = "This,is,my,way";
char str_25[2] = ",";
ck_assert_pstr_eq(strtok(str_24, str_25), s21_strtok(str_24, str_25));
} END_TEST

START_TEST(strtok_10) {
char str1[6] = "delim";
char str2[2] = "f";
ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
} END_TEST

START_TEST(strtok_11) {
char str1[] = "qwerty";
char str2[] = "1234";
ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
} END_TEST

START_TEST(strerror_1) {
int num_1 = 0;
ck_assert_str_eq(strerror(num_1), s21_strerror(num_1));
} END_TEST

START_TEST(strerror_2) {
int num_2 = 105;
ck_assert_str_eq(strerror(num_2), s21_strerror(num_2));
} END_TEST

START_TEST(strerror_3) {
int num_3 = 2147483647;
ck_assert_str_eq(strerror(num_3), s21_strerror(num_3));
} END_TEST

START_TEST(strerror_4) {
for (int i = -1; i <= 134; i++) {
ck_assert_str_eq(s21_strerror(i), strerror(i));
}
} END_TEST

START_TEST(strstr_1) {
char str[] = "Techie Delight – Ace the Technical Interviews";
char str1[] = "Ace";
ck_assert_str_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_2) {
char str[] = " \n\0\0";
char str1[] = " a\n\0";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_3) {
char str[] = "\0";
char str1[] = " schhol21\0";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_4) {
char str[] = "i am\nproger";
char str1[] = " a\n\0";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_5) {
char str[] = "Hello World";
char str1[] = "Hell";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_6) {
char str[] = "Hello World";
char str1[] = "";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_7) {
char str[] = "Hello World";
char str1[] = "abc";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_8) {
char str[] = "Hello World";
char str1[] = "Hello Worls";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_9) {
char str[] = "Hello World !!!!!!!!!";
char str1[] = "Hello Worls";
ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
} END_TEST

START_TEST(strstr_10) {
char *s1 = "QWERTY";
char *s2 = "E";
char *s3 = "";
ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
ck_assert_pstr_eq(strstr(s3, s2), s21_strstr(s3, s2));
ck_assert_pstr_eq(strstr(s1, s3), s21_strstr(s1, s3));
} END_TEST

START_TEST(strlen_1) {
char str1[] = "\0";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strlen_2) {
char str1[] = "Hello World\0";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strlen_3) {
char str1[] = "Hello World\0\n";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strlen_4) {
char str1[] = "";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strlen_5) {
char str1[] = "a\n\0";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strlen_6) {
char str1[] = " \n\0";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strlen_7) {
char str1[] = " \0";
ck_assert_int_eq(strlen(str1), s21_strlen(str1));
} END_TEST

START_TEST(strspn_1) {
char str[] = "23476";
char str1[] = "234";
ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
} END_TEST

START_TEST(strspn_2) {
char str[] = "Hello world\0dg234asfd76";
char str1[] = "";
ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
} END_TEST

START_TEST(strspn_3) {
char str[] = "Hello world\0dg234asfd76";
char str1[] = "\0";
ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
} END_TEST

START_TEST(strspn_4) {
char str[] = "Hello world\n\0dg234asfd76";
char str1[] = "H";
ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
} END_TEST

START_TEST(strspn_5) {
char str[] = "Hello world\n\0dg234asfd76";
char str1[] = " ";
ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
} END_TEST

START_TEST(strspn_6) {
char str[] = "";
char str1[] = "";
ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
} END_TEST

START_TEST(strcspn_1) {
char str[] = "23476";
char str1[] = "234";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_2) {
char str[] = "dg234asfd76";
char str1[] = "23dfgh4";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_3) {
char str[] = "Hello world\0dg234asfd76";
char str1[] = "";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_4) {
char str[] = "Hello world\0dg234asfd76";
char str1[] = "\0";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_5) {
char str[] = "Hello world\0dg234asfd76";
char str1[] = " H";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_6) {
char str[] = "Hello world\n\0dg234asfd76";
char str1[] = "H";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_7) {
char str[] = "Hello world\n\0dg234asfd76";
char str1[] = " ";
ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
} END_TEST

START_TEST(strcspn_8) {
char s1[] = "QWERTY";
char s2[] = "E";
char s3[] = "MFE";
char s4[] = "";
ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
ck_assert_int_eq(strcspn(s2, s1), s21_strcspn(s2, s1));
ck_assert_int_eq(strcspn(s1, s1), s21_strcspn(s1, s1));
ck_assert_int_eq(strcspn(s1, s3), s21_strcspn(s1, s3));
ck_assert_int_eq(strcspn(s1, s4), s21_strcspn(s1, s4));
ck_assert_int_eq(strcspn(s4, s1), s21_strcspn(s4, s1));
} END_TEST

START_TEST(to_upper_1) {
char str1[16] = "allcharstoupper";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "ALLCHARSTOUPPER");
free(str2);
} END_TEST

START_TEST(to_upper_2) {
char str1[19] = "few words to upper";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "FEW WORDS TO UPPER");
free(str2);
} END_TEST

START_TEST(to_upper_3) {
char str1[1] = "";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "");
free(str2);
} END_TEST

START_TEST(to_upper_4) {
char str1[16] = "NOTHINGTOCHANGE";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "NOTHINGTOCHANGE");
free(str2);
} END_TEST

START_TEST(to_upper_5) {
char str1[13] = "charswith123";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "CHARSWITH123");
free(str2);
} END_TEST

START_TEST(to_upper_6) {
char str1[12] = "hello\0world";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "HELLO");
free(str2);
} END_TEST

START_TEST(to_upper_7) {
char str1[10]= "\0a\0";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "");
free(str2);
} END_TEST

START_TEST(to_upper_8) {
char str1[10]= "{hello}";
char *str2 = s21_to_upper(str1);
ck_assert_str_eq(str2, "{HELLO}");
free(str2);
} END_TEST

START_TEST(to_lower_1) {
char str1[16] = "ALLCHARSTOUPPER";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "allcharstoupper");
free(str2);
} END_TEST

START_TEST(to_lower_2) {
char str1[19] = "FEW WORDS TO LOWER";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "few words to lower");
free(str2);
} END_TEST

START_TEST(to_lower_3) {
char str1[1] = "";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "");
free(str2);
} END_TEST

START_TEST(to_lower_4) {
char str1[16] = "nothingtochange";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "nothingtochange");
free(str2);
} END_TEST

START_TEST(to_lower_5) {
char str1[13] = "CHARSWITH123";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "charswith123");
free(str2);
} END_TEST

START_TEST(to_lower_6) {
char str1[12] = "HELLO\0WORLD";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "hello");
free(str2);
} END_TEST

START_TEST(to_lower_7) {
char str1[10]= "\0A\0";
char *str2 = s21_to_lower(str1);
ck_assert_str_eq(str2, "");
free(str2);
} END_TEST

START_TEST(insert_1) {
char str1[7] = "this +";
char str2[6] = " this";
char *str3 = (char*)s21_insert(str1, str2, 6);
ck_assert_str_eq(str3, "this + this");
free(str3);
} END_TEST

START_TEST(insert_2) {
char str1[1] = "";
char str2[14] = "checking null";
char *str3 = (char*)s21_insert(str1, str2, 1);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_3) {
char str1[8] = "splitme";
char str2[2] = " ";
char *str3 = (char*)s21_insert(str1, str2, 5);
ck_assert_str_eq(str3, "split me");
free(str3);
} END_TEST

START_TEST(insert_4) {
char str1[14] = "checking null";
char *str2 = NULL;
char *str3 = (char*)s21_insert(str1, str2, 0);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_5) {
char str1[4] = "end";
char str2[6] = "start";
char *str3 = (char*)s21_insert(str1, str2, 0);
ck_assert_str_eq(str3, "startend");
free(str3);
} END_TEST

START_TEST(insert_6) {
char str1[7] = "caseof";
char str2[8] = "mistake";
char *str3 = (char*)s21_insert(str1, str2, -1);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_7) {
char *str1 = NULL;
char str2[14] = "checking null";
char *str3 = (char*)s21_insert(str1, str2, 1);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_8) {
char str1[2] = " ";
char str2[32] = "if strlen src lesser than index";
char *str3 = (char*)s21_insert(str1, str2, 3);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_9) {
char *str1 = NULL;
char str2[1] = "";
char *str3 = (char*)s21_insert(str1, str2, 0);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_10) {
char *str1 = NULL;
char *str2 = NULL;
char *str3 = (char*)s21_insert(str1, str2, 0);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(insert_11) {
char str1[4] = "";
char str2[6] = "";
char *str3 = (char*)s21_insert(str1, str2, 1);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(trim_1) {
char *str1 = "Hello World";
char *str2 = "H";
char *str3 = (char *)s21_trim(str1, str2);
ck_assert_str_eq(str3, "ello World");
free(str3);
} END_TEST

START_TEST(trim_2) {
char *str1 = "Hello World";
char *str2 = "Hedl";
char *str3 = (char *)s21_trim(str1, str2);
ck_assert_str_eq(str3, "o Wor");
free(str3);
} END_TEST

START_TEST(trim_3) {
char *str1 = "";
char *str2 = "";
char *str3 = (char *)s21_trim(str1, str2);
ck_assert_str_eq(str3, "");
free(str3);
} END_TEST

START_TEST(trim_4) {
char *str = "empty";
char *str2 = "empty";
char *str3 = (char *)s21_trim(str, str2);
ck_assert_str_eq(str3, "");
free(str3);
} END_TEST

START_TEST(trim_5) {
char *str = NULL;
char *str2 = NULL;
char *str3 = (char *)s21_trim(str, str2);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(trim_6) {
char *str = NULL;
char *str2 = "  ";
char *str3 = (char *)s21_trim(str, str2);
ck_assert_ptr_eq(str3, NULL);
free(str3);
} END_TEST

START_TEST(trim_7) {
char *str = "empty";
char *str2 = "t";
char *str3 = (char *)s21_trim(str, str2);
ck_assert_str_ne(str3, "em");
free(str3);
} END_TEST

START_TEST(ssprintf_1) {
    char data[100];
    char data1[100];
    sprintf(data, "|%32s|\n", "111");
    s21_sprintf(data1, "|%32s|\n", "111");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_2) {
    char data[100];
    char data1[100];
    sprintf(data, "|%32s|\n", "abc");
    s21_sprintf(data1, "|%32s|\n", "abc");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_3) {
    char data[100];
    char data1[100];
    sprintf(data, "|%-32s|\n", "abc");
    s21_sprintf(data1, "|%-32s|\n", "abc");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_4) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%.03s|\n", "hello");
    int d = sprintf(data1, "|%.03s|\n", "hello");
    ck_assert_int_eq(c, d);
} END_TEST

START_TEST(ssprintf_5) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-s|\n", "test");
    sprintf(data1, "|%-s|\n", "test");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_6) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%10s|\n", "\0\0\0\0\0");
    sprintf(data1, "%10s|\n", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_7) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%s|\n", "");
    sprintf(data1, "%s|\n", "");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_8) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%1.1d|\n", -20);
    sprintf(data1, "%1.1d|\n", -20);
} END_TEST

START_TEST(ssprintf_9) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-10d|\n", -50);
    sprintf(data1, "%-10d|\n", -50);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_10) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%5.10d|\n", -16);
    sprintf(data1, "%5.10d|\n", -16);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_11) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%.2d|\n", -1);
    sprintf(data1, "%.2d|\n", -1);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_12) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-10d|\n", -90);
    sprintf(data1, "%-10d|\n", -90);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_13) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-.10d|\n", -10);
    sprintf(data1, "%-.10d|\n", -10);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_14) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%6d|\n", 35);
    sprintf(data1, "%6d|\n", 35);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_15) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-u|\n", (unsigned)50);
    sprintf(data1, "%-u|\n", (unsigned)50);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_16) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%10u|\n", (unsigned)90);
    sprintf(data1, "%10u|\n", (unsigned)90);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_17) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%.10u|\n", (unsigned)90);
    sprintf(data1, "%.10u|\n", (unsigned)90);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_18) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%15u|\n", (unsigned)-100);
    sprintf(data1, "%15u|\n", (unsigned)-100);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_19) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%.d|\n", 5);
    sprintf(data1, "%.d|\n", 5);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_20) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%.3s|\n", "21");
    sprintf(data1, "%.3s|\n", "21");
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_21) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%f\n", 4.134);
    sprintf(data1, "%f\n", 4.134);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_22) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%10f|\n", 13.343);
    sprintf(data1, "%10f|\n", 13.343);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_23) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.3f|\n", 1.343);
    sprintf(data1, "|%10.3f|\n", 1.343);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_24) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-1.10f\n", 4.343);
    sprintf(data1, "%-1.10f\n", 4.343);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_25) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10f|\n", 4.1123132);
    sprintf(data1, "|%10f|\n", 4.1123132);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_26) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.15f|\n", 34.1123132);
    sprintf(data1, "|%10.15f|\n", 34.1123132);
    ck_assert_str_eq(data, data1);
} END_TEST

START_TEST(ssprintf_27) {
    char str[100];
    char str1[100];
    sprintf(str, "|%9s|\n", "abcd");
    s21_sprintf(str1, "|%9s|\n", "abcd");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(ssprintf_28) {
    char str[100];
    char str1[100];
    sprintf(str, "|%5s|\n", "abrafdefgbr");
    s21_sprintf(str1, "|%5s|\n", "abrafdefgbr");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(ssprintf_29) {
    char str[100];
    char str1[100];
    sprintf(str, "|%8s|\n", "abcd");
    s21_sprintf(str1, "|%8s|\n", "abcd");
    ck_assert_str_eq(str, str1);
}

START_TEST(ssprintf_30) {
    char str[100];
    char str1[100];
    sprintf(str, "%c\n", 'a');
    s21_sprintf(str1, "%c\n", 'a');
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(ssprintf_31) {
    char str[100];
    char str1[100];
    sprintf(str, "%c", 'a');
    s21_sprintf(str1, "%c", 'a');
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(ssprintf_32) {
    char str[100];
    char str1[100];
    sprintf(str, " %+li ", 36854775807);
    s21_sprintf(str1, " %+li ", 36854775807);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(ssprintf_33) {
    char str[100];
    char str1[100];
    sprintf(str, " %+ld ", 23372036854775807);
    s21_sprintf(str1, " %+ld ", 23372036854775807);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(ssprintf_34) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%012i", 78), sprintf(str2, "%012i", 78));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, "%15o", val), sprintf(str2, "%15o", val));

  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, "%-16o", val), sprintf(str2, "%-16o", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int val = 15130;
  ck_assert_int_eq(s21_sprintf(str1, "%.51o", val), sprintf(str2, "%.51o", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int val = 15110;
  ck_assert_int_eq(s21_sprintf(str1, "%-5.51o", val), sprintf(str2, "%-5.51o", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%o", 0), sprintf(str2, "%o", 0));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, "%#o", val), sprintf(str2, "%#o", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long int val = 532149114140;
  ck_assert_int_eq(s21_sprintf(str1, "%lo", val), sprintf(str2, "%lo", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  unsigned val = 151155151;
  ck_assert_int_eq(s21_sprintf(str1, "%5x", val), sprintf(str2, "%5x", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  unsigned val = 345123415;
  ck_assert_int_eq(s21_sprintf(str1, "%#-10x", val), sprintf(str2, "%#-10x", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_45) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  unsigned val = 345123415;
  ck_assert_int_eq(s21_sprintf(str1, "%.15x", val), sprintf(str2, "%.15x", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_46) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, "%#hx", val), sprintf(str2, "%#hx", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_47) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, "%#lx", val), sprintf(str2, "%#lx", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_48) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%p", "%p"),
                   sprintf(str2, "%p", "%p"));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_49) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%15p", "%15p"),
                   sprintf(str2, "%15p", "%15p"));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_50) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *ptr = NULL;
  s21_sprintf(str1, "%p", ptr);
  sprintf(str2, "%p", ptr);
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_51) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  ck_assert_int_eq(s21_sprintf(str1, "Hello,%n", &ret),
                   sprintf(str2, "Hello,%n", &ret));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_52) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, "%10Lf", val), sprintf(str2, "%10Lf", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_53) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, "%.0Lf", val), sprintf(str2, "%.0Lf", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_54) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, "%.Le", val), sprintf(str2, "%.Le", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_55) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, "%.15Le", val), sprintf(str2, "%.15Le", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_56) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, "%.15Le", val), sprintf(str2, "%.15Le", val));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_57) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, "%g", hex),
  sprintf(str2, "%g", hex));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_58) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, "%g", hex), sprintf(str2, "%g", hex));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_59) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, "%.5g", hex), sprintf(str2, "%.5g", hex));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_60) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, "%.0g", hex),
  sprintf(str2, "%.0g", hex));
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_61) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);
  ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(ssprintf_62) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sscanff_1) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298/02", "%d%*c%d", &x1, &x2),
                   s21_sscanf("298/02", "%d%*c%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d", &x1, &x2),
                   s21_sscanf("298\n\t 3.1", "%d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  int x5, y5;
  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d%n", &x1, &x2, &x5),
                   s21_sscanf("298\n\t 3.1", "%d%d%n", &y1, &y2, &y5));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x5, y5);

  short int x4, y4;
  ck_assert_int_eq(sscanf("298 3", "%d%hd", &x1, &x4),
                   s21_sscanf("298 3", "%d%hd", &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);

  long int x3, y3;
  ck_assert_int_eq(sscanf("298 3", "%ld%hd", &x3, &x4),
                   s21_sscanf("298 3", "%ld%hd", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("298 3", "%ld%n%hd", &x3, &x1, &x4),
                   s21_sscanf("298 3", "%ld%n%hd", &y3, &y1, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);
} END_TEST

START_TEST(sscanff_2) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 -7 ab", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 -7 ab", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 7 -3", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 7 -3", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0003", "%hu%*i%lu", &x3, &x4),
                   s21_sscanf("298 -7 0003", "%hu%*i%lu", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
} END_TEST

START_TEST(sscanff_3) {
  int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("0x298 -7 ab", "%i%*i%i", &x1, &x2),
                   s21_sscanf("0x298 -7 ab", "%i%*i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short x3, y3;
  long x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0xab", "%hi%*i%li", &x3, &x4),
                   s21_sscanf("298 -7 0xab", "%hi%*i%li", &y3, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 -7 0xab", "%hn%i%ln", &x3, &x1, &x4),
                   s21_sscanf("298 -7 0xab", "%hn%i%ln", &y3, &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
} END_TEST

START_TEST(sscanff_4) {
  void *x1, *x2, *y1, *y2;
  ck_assert_int_eq(sscanf("298 7 0xab", "%p%*p%p", &x1, &x2),
                   s21_sscanf("298 7 0xab", "%p%*p%p", &y1, &y2));
  ck_assert_int_eq((long)x1, (long)y1);
  ck_assert_int_eq((long)x2, (long)y2);
} END_TEST

START_TEST(sscanff_5) {
  float x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298.3 4", "%f%f", &x1, &x2),
                   s21_sscanf("298.3 4", "%f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  ck_assert_int_eq(sscanf("298.3 0 nAN 4", "%f%*f%*f%f", &x1, &x2),
                   s21_sscanf("298.3 0 Nan 4", "%f%*f%*f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  long double x3, y3;
  ck_assert_int_eq(sscanf("298e-2 iNf 3E3", "%Lf%*f%f", &x3, &x2),
                   s21_sscanf("298e-2 InF 3E3", "%Lf%*f%f", &y3, &y2));
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq((x3 - y3) * 1e15, 0);
} END_TEST

START_TEST(sscanff_6) {
    int r1 = 0, r2 = 0;
    unsigned long lu1 = 0, lu2 = 0;
    long ld1 = 0, ld2 = 0;

    r1 = sscanf("12345", "%lu", &lu1);
    r2 = s21_sscanf("12345", "%lu", &lu2);
    ck_assert_int_eq(lu1, lu2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12345", "%ld", &ld1);
    r2 = s21_sscanf("12345", "%ld", &ld2);
    ck_assert_int_eq(ld1, ld2);
    ck_assert_int_eq(r1, r2);
} END_TEST

START_TEST(sscanff_7) {
    int r1 = 0, r2 = 0;
    long double Lf1 = 0, Lf2 = 0;

    r1 = sscanf("123.45", "%Lf", &Lf1);
    r2 = s21_sscanf("123.45", "%Lf", &Lf2);
    ck_assert_msg((int)Lf1 == (int)Lf2, "floats not equals");
    ck_assert_int_eq(r1, r2);
} END_TEST

START_TEST(sscanff_8) {
    int r1 = 0, r2 = 0;
    unsigned u1 = 0, u2 = 0;

    r1 = sscanf("+123", "%u", &u1);
    r2 = s21_sscanf("+123", "%u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+z123", "%u", &u1);
    r2 = s21_sscanf("+z123", "%u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x12345", "%2u", &u1);
    r2 = s21_sscanf("0x12345", "%2u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.456", "%u", &u1);
    r2 = s21_sscanf("123.456", "%u", &u2);
    ck_assert_msg(u1 == u2, "floats not equals");
    ck_assert_int_eq(r1, r2);
} END_TEST

START_TEST(sscanff_9) {
    int r1 = 0, r2 = 0;
    unsigned short hu1 = 0, hu2 = 0;

    r1 = sscanf("12345", "%hu", &hu1);
    r2 = s21_sscanf("12345", "%hu", &hu2);
    ck_assert_int_eq(hu1, hu2);
    ck_assert_int_eq(r1, r2);
} END_TEST

START_TEST(sscanff_10) {
    int r1 = 0, r2 = 0;
    char s1[100], s2[100];

    r1 = sscanf("asdf asdf", "%*s%2s", s1);
    r2 = s21_sscanf("asdf asdf", "%*s%2s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("\nasdf asdf", "%*s%10s", s1);
    r2 = s21_sscanf("\nasdf asdf", "%*s%10s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("   asdf asdf", "%*s%s", s1);
    r2 = s21_sscanf("   asdf asdf", "%*s%s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);
} END_TEST

/* START_TEST(sscanff_11) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 7 ab", "%o%*o%o", &x1, &x2),
                   s21_sscanf("298 7 ab", "%o%*o%o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%ho%*i%lo", &x3, &x4),
                   s21_sscanf("298 7 ab", "%ho%*i%lo", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
} END_TEST */

Suite *Suite_create(void) {
  Suite *s21_string = suite_create("s21_string");
  TCase *tcase_test = tcase_create("test");
tcase_add_test(tcase_test, sprintf_1);
tcase_add_test(tcase_test, sprintf_2);
tcase_add_test(tcase_test, sprintf_3);
tcase_add_test(tcase_test, sprintf_4);
tcase_add_test(tcase_test, sprintf_6);
tcase_add_test(tcase_test, sprintf_8);
tcase_add_test(tcase_test, sprintf_9);
tcase_add_test(tcase_test, sprintf_10);
tcase_add_test(tcase_test, sprintf_11);
tcase_add_test(tcase_test, sprintf_12);
tcase_add_test(tcase_test, sprintf_13);
tcase_add_test(tcase_test, sprintf_14);
tcase_add_test(tcase_test, sprintf_15);
tcase_add_test(tcase_test, memmove_1);
tcase_add_test(tcase_test, memmove_2);
tcase_add_test(tcase_test, memmove_3);
tcase_add_test(tcase_test, memmove_4);
tcase_add_test(tcase_test, memmove_5);
tcase_add_test(tcase_test, memmove_6);
tcase_add_test(tcase_test, memmove_7);
tcase_add_test(tcase_test, memmove_8);
tcase_add_test(tcase_test, memmove_9);
tcase_add_test(tcase_test, memmove_10);
tcase_add_test(tcase_test, memmove_11);
tcase_add_test(tcase_test, memmove_12);
tcase_add_test(tcase_test, memcpy_1);
tcase_add_test(tcase_test, memcpy_2);
tcase_add_test(tcase_test, memcpy_3);
tcase_add_test(tcase_test, memcpy_4);
tcase_add_test(tcase_test, memcpy_5);
tcase_add_test(tcase_test, memcpy_6);
tcase_add_test(tcase_test, memcpy_7);
tcase_add_test(tcase_test, memset_1);
tcase_add_test(tcase_test, memset_2);
tcase_add_test(tcase_test, memset_3);
tcase_add_test(tcase_test, memset_4);
tcase_add_test(tcase_test, memset_5);
tcase_add_test(tcase_test, memcmp_1);
tcase_add_test(tcase_test, memcmp_2);
tcase_add_test(tcase_test, memcmp_3);
tcase_add_test(tcase_test, memcmp_4);
tcase_add_test(tcase_test, memcmp_5);
tcase_add_test(tcase_test, memcmp_6);
tcase_add_test(tcase_test, memcmp_7);
tcase_add_test(tcase_test, memcmp_8);
tcase_add_test(tcase_test, memcmp_9);
tcase_add_test(tcase_test, memcmp_10);
tcase_add_test(tcase_test, memcmp_11);
tcase_add_test(tcase_test, memcmp_12);
tcase_add_test(tcase_test, memcmp_13);
tcase_add_test(tcase_test, memcmp_14);
tcase_add_test(tcase_test, memcmp_15);
tcase_add_test(tcase_test, memcmp_16);
tcase_add_test(tcase_test, memcmp_17);
tcase_add_test(tcase_test, memcmp_18);
tcase_add_test(tcase_test, memcmp_19);
tcase_add_test(tcase_test, memcmp_20);
tcase_add_test(tcase_test, memcmp_21);
tcase_add_test(tcase_test, memcmp_22);
tcase_add_test(tcase_test, memcmp_23);
tcase_add_test(tcase_test, memcmp_24);
tcase_add_test(tcase_test, memcmp_25);
tcase_add_test(tcase_test, memcmp_26);
tcase_add_test(tcase_test, memcmp_27);
tcase_add_test(tcase_test, memcmp_28);
tcase_add_test(tcase_test, memcmp_29);
tcase_add_test(tcase_test, strcmp_1);
tcase_add_test(tcase_test, strcmp_2);
tcase_add_test(tcase_test, strcmp_3);
tcase_add_test(tcase_test, strcmp_4);
tcase_add_test(tcase_test, strcmp_5);
tcase_add_test(tcase_test, strcmp_6);
tcase_add_test(tcase_test, strcmp_7);
tcase_add_test(tcase_test, strcmp_8);
tcase_add_test(tcase_test, strcmp_9);
tcase_add_test(tcase_test, strcmp_10);
tcase_add_test(tcase_test, strcmp_11);
tcase_add_test(tcase_test, strcmp_12);
tcase_add_test(tcase_test, strcmp_13);
tcase_add_test(tcase_test, strcmp_14);
tcase_add_test(tcase_test, strcmp_15);
tcase_add_test(tcase_test, strcmp_16);
tcase_add_test(tcase_test, strcmp_17);
tcase_add_test(tcase_test, strcmp_18);
tcase_add_test(tcase_test, strncmp_1);
tcase_add_test(tcase_test, strncmp_2);
tcase_add_test(tcase_test, strncmp_3);
tcase_add_test(tcase_test, strncmp_4);
tcase_add_test(tcase_test, strncmp_5);
tcase_add_test(tcase_test, strncmp_6);
tcase_add_test(tcase_test, strcpy_1);
tcase_add_test(tcase_test, strcpy_2);
tcase_add_test(tcase_test, strcpy_3);
tcase_add_test(tcase_test, strcpy_4);
tcase_add_test(tcase_test, strcpy_5);
tcase_add_test(tcase_test, strcpy_6);
tcase_add_test(tcase_test, strncpy_1);
tcase_add_test(tcase_test, strncpy_2);
tcase_add_test(tcase_test, strncpy_3);
tcase_add_test(tcase_test, strncpy_4);
tcase_add_test(tcase_test, strncpy_5);
tcase_add_test(tcase_test, strncpy_6);
tcase_add_test(tcase_test, strncpy_7);
tcase_add_test(tcase_test, strcat_1);
tcase_add_test(tcase_test, strcat_2);
tcase_add_test(tcase_test, strcat_3);
tcase_add_test(tcase_test, strcat_4);
tcase_add_test(tcase_test, strcat_5);
tcase_add_test(tcase_test, strcat_6);
tcase_add_test(tcase_test, strcat_7);
tcase_add_test(tcase_test, strcat_8);
tcase_add_test(tcase_test, strncat_1);
tcase_add_test(tcase_test, strncat_2);
tcase_add_test(tcase_test, strncat_3);
tcase_add_test(tcase_test, strncat_4);
tcase_add_test(tcase_test, strncat_5);
tcase_add_test(tcase_test, strncat_6);
tcase_add_test(tcase_test, strncat_7);
tcase_add_test(tcase_test, strncat_8);
tcase_add_test(tcase_test, strncat_9);
tcase_add_test(tcase_test, strncat_10);
tcase_add_test(tcase_test, strchr_1);
tcase_add_test(tcase_test, strchr_2);
tcase_add_test(tcase_test, strchr_3);
tcase_add_test(tcase_test, strchr_4);
tcase_add_test(tcase_test, strchr_5);
tcase_add_test(tcase_test, strchr_6);
tcase_add_test(tcase_test, strchr_7);
tcase_add_test(tcase_test, strchr_8);
tcase_add_test(tcase_test, strrchr_1);
tcase_add_test(tcase_test, strrchr_2);
tcase_add_test(tcase_test, strrchr_3);
tcase_add_test(tcase_test, strrchr_4);
tcase_add_test(tcase_test, strrchr_5);
tcase_add_test(tcase_test, strrchr_6);
tcase_add_test(tcase_test, strrchr_7);
tcase_add_test(tcase_test, strrchr_8);
tcase_add_test(tcase_test, strpbrk_1);
tcase_add_test(tcase_test, strpbrk_2);
tcase_add_test(tcase_test, strpbrk_3);
tcase_add_test(tcase_test, strpbrk_4);
tcase_add_test(tcase_test, strpbrk_5);
tcase_add_test(tcase_test, strpbrk_6);
tcase_add_test(tcase_test, strpbrk_7);
tcase_add_test(tcase_test, strpbrk_8);
tcase_add_test(tcase_test, strtok_1);
tcase_add_test(tcase_test, strtok_2);
tcase_add_test(tcase_test, strtok_3);
tcase_add_test(tcase_test, strtok_4);
tcase_add_test(tcase_test, strtok_5);
tcase_add_test(tcase_test, strtok_6);
tcase_add_test(tcase_test, strtok_7);
tcase_add_test(tcase_test, strtok_8);
tcase_add_test(tcase_test, strtok_9);
tcase_add_test(tcase_test, strtok_10);
tcase_add_test(tcase_test, strtok_11);
tcase_add_test(tcase_test, strerror_1);
tcase_add_test(tcase_test, strerror_2);
tcase_add_test(tcase_test, strerror_3);
tcase_add_test(tcase_test, strerror_4);
tcase_add_test(tcase_test, strstr_1);
tcase_add_test(tcase_test, strstr_2);
tcase_add_test(tcase_test, strstr_3);
tcase_add_test(tcase_test, strstr_4);
tcase_add_test(tcase_test, strstr_5);
tcase_add_test(tcase_test, strstr_6);
tcase_add_test(tcase_test, strstr_7);
tcase_add_test(tcase_test, strstr_8);
tcase_add_test(tcase_test, strstr_9);
tcase_add_test(tcase_test, strstr_10);
tcase_add_test(tcase_test, strlen_1);
tcase_add_test(tcase_test, strlen_2);
tcase_add_test(tcase_test, strlen_3);
tcase_add_test(tcase_test, strlen_4);
tcase_add_test(tcase_test, strlen_5);
tcase_add_test(tcase_test, strlen_6);
tcase_add_test(tcase_test, strlen_7);
tcase_add_test(tcase_test, strspn_1);
tcase_add_test(tcase_test, strspn_2);
tcase_add_test(tcase_test, strspn_3);
tcase_add_test(tcase_test, strspn_4);
tcase_add_test(tcase_test, strspn_5);
tcase_add_test(tcase_test, strspn_6);
tcase_add_test(tcase_test, strcspn_1);
tcase_add_test(tcase_test, strcspn_2);
tcase_add_test(tcase_test, strcspn_3);
tcase_add_test(tcase_test, strcspn_4);
tcase_add_test(tcase_test, strcspn_5);
tcase_add_test(tcase_test, strcspn_6);
tcase_add_test(tcase_test, strcspn_7);
tcase_add_test(tcase_test, strcspn_8);
tcase_add_test(tcase_test, to_upper_1);
tcase_add_test(tcase_test, to_upper_2);
tcase_add_test(tcase_test, to_upper_3);
tcase_add_test(tcase_test, to_upper_4);
tcase_add_test(tcase_test, to_upper_5);
tcase_add_test(tcase_test, to_upper_6);
tcase_add_test(tcase_test, to_upper_7);
tcase_add_test(tcase_test, to_upper_8);
tcase_add_test(tcase_test, to_lower_1);
tcase_add_test(tcase_test, to_lower_2);
tcase_add_test(tcase_test, to_lower_3);
tcase_add_test(tcase_test, to_lower_4);
tcase_add_test(tcase_test, to_lower_5);
tcase_add_test(tcase_test, to_lower_6);
tcase_add_test(tcase_test, to_lower_7);
tcase_add_test(tcase_test, insert_1);
tcase_add_test(tcase_test, insert_2);
tcase_add_test(tcase_test, insert_3);
tcase_add_test(tcase_test, insert_4);
tcase_add_test(tcase_test, insert_5);
tcase_add_test(tcase_test, insert_6);
tcase_add_test(tcase_test, insert_7);
tcase_add_test(tcase_test, insert_8);
tcase_add_test(tcase_test, insert_9);
tcase_add_test(tcase_test, insert_10);
tcase_add_test(tcase_test, insert_11);
tcase_add_test(tcase_test, trim_1);
tcase_add_test(tcase_test, trim_2);
tcase_add_test(tcase_test, trim_3);
tcase_add_test(tcase_test, trim_4);
tcase_add_test(tcase_test, trim_5);
tcase_add_test(tcase_test, trim_6);
tcase_add_test(tcase_test, trim_7);
tcase_add_test(tcase_test, ssprintf_1);
tcase_add_test(tcase_test, ssprintf_2);
tcase_add_test(tcase_test, ssprintf_3);
tcase_add_test(tcase_test, ssprintf_4);
tcase_add_test(tcase_test, ssprintf_5);
tcase_add_test(tcase_test, ssprintf_6);
tcase_add_test(tcase_test, ssprintf_7);
tcase_add_test(tcase_test, ssprintf_8);
tcase_add_test(tcase_test, ssprintf_9);
tcase_add_test(tcase_test, ssprintf_10);
tcase_add_test(tcase_test, ssprintf_11);
tcase_add_test(tcase_test, ssprintf_12);
tcase_add_test(tcase_test, ssprintf_13);
tcase_add_test(tcase_test, ssprintf_14);
tcase_add_test(tcase_test, ssprintf_15);
tcase_add_test(tcase_test, ssprintf_16);
tcase_add_test(tcase_test, ssprintf_17);
tcase_add_test(tcase_test, ssprintf_18);
tcase_add_test(tcase_test, ssprintf_19);
tcase_add_test(tcase_test, ssprintf_20);
tcase_add_test(tcase_test, ssprintf_21);
tcase_add_test(tcase_test, ssprintf_22);
tcase_add_test(tcase_test, ssprintf_23);
tcase_add_test(tcase_test, ssprintf_24);
tcase_add_test(tcase_test, ssprintf_25);
tcase_add_test(tcase_test, ssprintf_26);
tcase_add_test(tcase_test, ssprintf_27);
tcase_add_test(tcase_test, ssprintf_28);
tcase_add_test(tcase_test, ssprintf_29);
tcase_add_test(tcase_test, ssprintf_30);
tcase_add_test(tcase_test, ssprintf_31);
tcase_add_test(tcase_test, ssprintf_32);
tcase_add_test(tcase_test, ssprintf_33);
tcase_add_test(tcase_test, ssprintf_34);
tcase_add_test(tcase_test, ssprintf_35);
tcase_add_test(tcase_test, ssprintf_36);
tcase_add_test(tcase_test, ssprintf_37);
tcase_add_test(tcase_test, ssprintf_38);
tcase_add_test(tcase_test, ssprintf_39);
tcase_add_test(tcase_test, ssprintf_40);
tcase_add_test(tcase_test, ssprintf_41);
tcase_add_test(tcase_test, ssprintf_42);
tcase_add_test(tcase_test, ssprintf_43);
tcase_add_test(tcase_test, ssprintf_44);
tcase_add_test(tcase_test, ssprintf_45);
tcase_add_test(tcase_test, ssprintf_46);
tcase_add_test(tcase_test, ssprintf_47);
tcase_add_test(tcase_test, ssprintf_48);
tcase_add_test(tcase_test, ssprintf_49);
tcase_add_test(tcase_test, ssprintf_50);
tcase_add_test(tcase_test, ssprintf_51);
tcase_add_test(tcase_test, ssprintf_52);
tcase_add_test(tcase_test, ssprintf_53);
tcase_add_test(tcase_test, ssprintf_54);
tcase_add_test(tcase_test, ssprintf_55);
tcase_add_test(tcase_test, ssprintf_56);
tcase_add_test(tcase_test, ssprintf_57);
tcase_add_test(tcase_test, ssprintf_58);
tcase_add_test(tcase_test, ssprintf_59);
tcase_add_test(tcase_test, ssprintf_60);
tcase_add_test(tcase_test, ssprintf_61);
tcase_add_test(tcase_test, ssprintf_62);
tcase_add_test(tcase_test, sscanff_1);
tcase_add_test(tcase_test, sscanff_2);
tcase_add_test(tcase_test, sscanff_3);
tcase_add_test(tcase_test, sscanff_4);
tcase_add_test(tcase_test, sscanff_5);
tcase_add_test(tcase_test, sscanff_6);
tcase_add_test(tcase_test, sscanff_7);
tcase_add_test(tcase_test, sscanff_8);
tcase_add_test(tcase_test, sscanff_9);
tcase_add_test(tcase_test, sscanff_10);
// tcase_add_test(tcase_test, sscanff_11);

  suite_add_tcase(s21_string, tcase_test);

  return s21_string;
}

int main(void) {
  Suite *suite = Suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(suite_runner);

  srunner_free(suite_runner);

  return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
