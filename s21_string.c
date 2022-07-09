#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_strerror.h"
#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *s = S21_NULL;
  unsigned char *p = S21_NULL;
  unsigned char c_new = (unsigned char)c;
  s = (unsigned char *)str;
  while (n--) {
    if (*s == c_new) {
      p = s;
      break;
    } else {
      s++;
    }
  }
  return p;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *s1 = S21_NULL;
  unsigned char *s2 = S21_NULL;
  s1 = (unsigned char *)str1;
  s2 = (unsigned char *)str2;
  int ret = 0;
  while (n-- && ret == 0) {
    if (*s1 != *s2) {
      ret = *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return ret;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *s = (unsigned char *)src;
  unsigned char *d = (unsigned char *)dest;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *s = (unsigned char *)src;
  unsigned char *d = (unsigned char *)dest;
  while (n) {
    if (s >= d) {
      *d++ = *s++;
    } else {
      *(d + n - 1) = *(s + n - 1);
    }
    n--;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;
  while (n--) {
    *s++ = (unsigned char)c;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *d = dest;
  while (*d != '\0') {
    d++;
  }
  while (*src != '\0') {
    *d = *src;
    d++;
    src++;
  }
  *d = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t n1 = s21_strlen(dest);
  s21_size_t i = n1;
  for (; (i < n1 + n) && (src[i - n1] != '\0'); i++) {
    dest[i] = src[i - n1];
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  int i = 0;
  while (str[i] != c && str[i]) i++;
  return c == str[i] ? (char *)str + i : S21_NULL;
}

int s21_strcmp(const char *str1, const char *str2) {
  int ret = 0;
  while ((*str1 != '\0' || *str2 != '\0') && ret == 0) {
    if (*str1 != *str2) {
      ret = *str1 - *str2;
    }
    str1++;
    str2++;
  }
  return ret;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *pointer1 = str1;
  const char *pointer2 = str2;
  int result = 0;

  while (n--) {
    if (*pointer1 || *pointer2) {
      result = *pointer1 - *pointer2;
      pointer1++;
      pointer2++;
    }
    if (result != 0) break;
  }
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  char *p_dest = dest;
  const char *p_src = src;

  while (*p_src) {
    *p_dest = *p_src;
    p_dest++;
    p_src++;
  }
  *p_dest = '\0';

  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  s21_size_t flag = 0;
  for (i = 0; i < n; i++) {
    if (src[i] == '\0') flag = 1;
    if (flag == 0)
      dest[i] = src[i];
    else
      dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t ret = s21_strlen(str1);
  int flag = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1) && flag == 0; i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        ret = i;
        flag = 1;
        break;
      }
    }
  }
  return ret;
}

char *digit_ull_to_string(unsigned long long x) {
  static char str[40];
  if (x == 0) {
    str[0] = '0';
    str[1] = '\0';
  } else {
    int len_x = 0;
    while (x) {
      str[len_x] = x % 10 + '0';
      x /= 10;
      len_x++;
    }
    str[len_x] = '\0';
    reverse_str(str);
  }

  return (str);
}

char *s21_strerror(int errnum) {
  char *result = S21_NULL;
  if (errnum >= 0 && errnum <= max_number_error) {
    result = errors_messages[errnum];
  } else {
    char str[256];
    int len_x = 0;
    int flag = 0;
    int x = errnum;
    if (x < 0) {
      flag = 1;
      x = -x;
    }

    while (x) {
      str[len_x] = x % 10 + '0';
      x /= 10;
      len_x++;
    }
    if (flag == 1) {
      str[len_x++] = '-';
    }
    str[len_x] = '\0';
    
    for (int i = len_x - 1, j = 0; i > j; i--, j++) {
      char c;
      c = str[j];
      str[j] = str[i];
      str[i] = c;
    }

    static char unknown_error[256];
    unknown_error[0] = '\0';
    s21_strcat(unknown_error, UNKNOWN_ERROR);
    result = s21_strcat(unknown_error, str);
  }

  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; *(str + len); len++) {
  }
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int len1 = s21_strlen(str1);
  int len2 = s21_strlen(str2);
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      if (str1[i] == str2[j]) return (char *)&str1[i];
    }
  }
  return S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  const char *dest = S21_NULL;
  for (s21_size_t i = 0; *(str + i) != '\0'; i++) {
    if (*(str + i) == c) dest = (char *)(str + i);
  }
  if (c == 0) {
    dest = &str[s21_strlen(str)];
  }
  return (char *)dest;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int len1 = s21_strlen(str1);
  int len2 = s21_strlen(str2);
  int c = 0;
  int z = 0;
  while (str2[z] != '\0') {
    if (str1[0] == str2[z]) {
      for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
          if (str1[i] == str2[j]) c++;
        }
      }
    }
    z++;
  }
  return c;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *out_str = S21_NULL;
  for (int i = 0; haystack[i] != '\0'; i++) {
    int temp = i;
    int j = 0;
    while (haystack[i++] == needle[j++]) {
      if (needle[j] == '\0') {
        out_str = (char *)&haystack[temp];
        break;
      }
    }
    i = temp;
  }
  if (*needle == '\0') out_str = (char *)&haystack[0];
  return out_str;
}

char *s21_strtok(char *str, const char *delim) {
  char *ret = S21_NULL;
  static char *stat_s = S21_NULL;

  if (str != S21_NULL) {
    stat_s = str;
    while (*stat_s != '\0' && s21_strchr(delim, *stat_s)) {
      *stat_s++ = '\0';
    }
  }
  if (stat_s && *stat_s != '\0') {
    str = stat_s;
    while (*stat_s && s21_strchr(delim, *stat_s) == S21_NULL) {
      stat_s++;
    }

    while (*stat_s != '\0' && s21_strchr(delim, *stat_s)) {
      *stat_s++ = '\0';
    }
    ret = str;
  }
  return ret;
}

char *s21_to_low_up_func(const char *str, char a, char z, int sdvig) {
  char *out_str = S21_NULL;
  if ((out_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char))) !=
      S21_NULL) {
    char *out_copy = out_str;

    while (*str != '\0') {
      if (*str >= a && *str <= z) {
        *out_copy = *str + sdvig;
      } else {
        *out_copy = *str;
      }
      str++;
      out_copy++;
    }
    *out_copy = '\0';
  }
  return out_str;
}

void *s21_to_lower(const char *str) {
  char *out_str = s21_to_low_up_func(str, 'A', 'Z', 32);
  return out_str;
}

void *s21_to_upper(const char *str) {
  char *out_str = s21_to_low_up_func(str, 'a', 'z', -32);
  return out_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *out_str = S21_NULL;
  if (src && str && s21_strlen(src) >= start_index) {
    if ((out_str = (char *)malloc((s21_strlen(str) + s21_strlen(src) + 1) *
                                  sizeof(char))) != S21_NULL) {
      char *out_copy = out_str;
      s21_size_t i = 0;
      while (i++ < start_index) {
        *out_copy = *src;
        out_copy++;
        src++;
      }
      while (*str != '\0') {
        *out_copy = *str;
        out_copy++;
        str++;
      }
      while (*src != '\0') {
        *out_copy = *src;
        out_copy++;
        src++;
      }
      *out_copy = '\0';
    }
  }
  return out_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_str = S21_NULL;
  char null_chars[] = " \t\n";
  if (trim_chars != S21_NULL && *trim_chars != '\0') {
    trim_str = (char *)trim_chars;
  } else {
    trim_str = null_chars;
  }
  char *out_str = S21_NULL;
  if (src != S21_NULL) {
    const char *s = src;
    int start = 0;
    int last = s21_strlen(s) - 1;
    while (s21_strchr(trim_str, *src) != S21_NULL && *src != '\0') {
      start++;
      src++;
    }
    while (s21_strchr(trim_str, s[last]) != S21_NULL && last >= 0) {
      last--;
    }
    int out_len = last - start + 1 > 0 ? last - start + 1 : 0;
    if ((out_str = (char *)malloc((out_len + 1) * sizeof(char))) != S21_NULL) {
      char *out_copy = out_str;
      while (last >= start) {
        *out_copy = *src;
        out_copy++;
        src++;
        start++;
      }
      *out_copy = '\0';
    }
  }
  return out_str;
}

int s21_sprintf(char *str, const char *format, ...) {
  char *s = str;
  int i = 0;
  va_list ap;
  va_start(ap, format);

  spec_struct spec;
  spec_struct *options = &spec;

  for (; format[i]; i++) {
    if (format[i] == '%') {
      int str_specif_len = s21_strcspn(format + i + 1, "cdieEfgGosuxXpn%");
      write_options_struct(options, format + i + 1, str_specif_len, ap);

      char *ret_str = S21_NULL;

      if (s21_strchr("cs%", options->specificator) != S21_NULL) {
        ret_str = sprintf_cs(options, ap);
      }

      if (s21_strchr("diouxXp", options->specificator) != S21_NULL) {
        ret_str = sprintf_diouxXp(options, ap);
      }

      if (s21_strchr("eEfgG", options->specificator) != S21_NULL) {
        ret_str = sprintf_eEfgG(options, ap);
      }

      if (options->specificator == 'n') {
        int *p = va_arg(ap, int *);
        unsigned long long n_int = s - str;
        *p = n_int;
      }
      if (options->specificator != 'n' && ret_str != S21_NULL) {
        s21_strcpy(s, ret_str);
        s += s21_strlen(ret_str);
        free(ret_str);
      }
      i += str_specif_len + 1;

    } else {
      *s++ = format[i];
    }
  }
  *s = '\0';
  va_end(ap);
  return (int)s21_strlen(str);
}

void write_options_struct(spec_struct *options, const char *str, int len,
                va_list ap) {
  struct_init(options);
  options->specificator = str[len];

  if (s21_strchr("feEgG", options->specificator) != S21_NULL)
    options->precision = 6;

  int i = 0;
  while (s21_strchr(" +-#0", str[i]) != S21_NULL) {
    if (str[i] == ' ') {
      options->flag_space = 1;
      i++;
    }
    if (str[i] == '+') {
      options->flag_sign = 1;
      i++;
    }
    if (str[i] == '-') {
      options->flag_align = 1;
      i++;
    }
    if (str[i] == '#') {
      options->flag_sharp = 1;
      i++;
    }
    if (s21_strchr("0", str[i])) {
      options->flag_zero = 1;
      i++;
    }
  }

  int sum = 0;
  while (s21_strchr("1234567890", str[i]) != S21_NULL) {
    sum = (sum * 10) + str[i] - '0';
    i++;
  }
  options->width = sum;

  if (str[i] == '*') {
    options->width = va_arg(ap, int);
    i++;
  }

  sum = 0;
  if (str[i] == '.') {
    i++;
    while (s21_strchr("1234567890", str[i]) != S21_NULL) {
      sum = (sum * 10) + str[i] - '0';
      i++;
    }
    options->precision = sum;

    if (str[i] == '*') {
      options->precision = va_arg(ap, int);
      i++;
    }
  }
  if (str[i] == 'h') options->type_short = 1;
  if (str[i] == 'l') options->type_long = 1;
  if (str[i] == 'L') options->type_ld = 1;
}

void struct_init(spec_struct *options) {
  options->flag_align = 0;
  options->flag_sign = 0;
  options->flag_space = 0;
  options->flag_sharp = 0;
  options->flag_zero = 0;
  options->is_negative = 0;
  options->out_len = 0;
  options->flag_star_precision = 0;
  options->flag_star_width = 0;
  options->width = 0;
  options->arg_len = 0;
  options->add_zeroes = 0;
  options->precision = -1;
  options->type_short = 0;
  options->type_long = 0;
  options->type_ld = 0;
}

char *sprintf_cs(spec_struct *options, va_list ap) {
  char s[] = "%";
  char *str = &s[0];
  char *out_str = S21_NULL;
  char null_str[7] = "";
  int flag_change_null_str = 0;
  if (options->specificator == 'c') {
    str[0] = (char)va_arg(ap, int);
  }
  if (options->specificator == 's') {
    str = va_arg(ap, char *);
    if (str == S21_NULL) {
      s21_strcpy(null_str, "(null)");
      str = null_str;
      flag_change_null_str = 1;
    }
  }
  if (str != S21_NULL) {
    options->arg_len = s21_strlen(str);
    if (options->precision >= 0 &&
        options->precision < options->arg_len) {
      options->arg_len = options->precision;
    }
    options->out_len = options->arg_len > options->width
                               ? options->arg_len
                               : options->width;
    out_str = (char *)malloc((options->out_len + 1) * sizeof(char));
    int i = 0;
    for (; i < options->out_len; i++) {
      out_str[i] = ' ';
    }
    out_str[i] = '\0';
    if (options->flag_align) {
      s21_memcpy(out_str, str, options->arg_len);
    } else {
      s21_memcpy(out_str + (s21_strlen(out_str) - options->arg_len), str,
                 options->arg_len);
    }
  }
  if (flag_change_null_str) str = S21_NULL;
  return out_str;
}

unsigned long sprintf_diouxXp_digit(spec_struct *options, va_list ap) {
  unsigned long digit;
  if (s21_strchr("ouxXp", options->specificator) != S21_NULL) {
    if (options->type_long == 1 || options->specificator == 'p') {
      digit = va_arg(ap, unsigned long int);
    } else if (options->type_short == 1) {
      digit = (unsigned short)va_arg(ap, int);
    } else {
      digit = (unsigned int)va_arg(ap, int);
    }
  }
  if (s21_strchr("di", options->specificator) != S21_NULL) {
    long temp;
    if (options->type_long == 1) {
      temp = va_arg(ap, long int);
    } else if (options->type_short == 1) {
      temp = (short)va_arg(ap, int);
    } else {
      temp = va_arg(ap, int);
    }

    if (temp < 0) {
      options->is_negative = 1;
      digit = -temp;
    } else {
      digit = temp;
    }
  }
  return digit;
}

void sprintf_diouxXp_buffer(char *buffer, spec_struct *options,
                        unsigned long digit) {
  if (s21_strchr("diu", options->specificator) != S21_NULL) {
    if (options->precision != 0 || digit != 0) {
      sprintf_num_sys_to_str(buffer, digit, 10);
    }
  }
  if (s21_strchr("xXp", options->specificator) != S21_NULL) {
    sprintf_num_sys_to_str(buffer, digit, 16);
  }
  if (options->specificator == 'o') {
    sprintf_num_sys_to_str(buffer, digit, 8);
  }
}

char *sprintf_diouxXp(spec_struct *options, va_list ap) {
  unsigned long digit = sprintf_diouxXp_digit(options, ap);
  char buffer[40] = "";

  sprintf_diouxXp_buffer(buffer, options, digit);
  if (digit == 0 && options->precision != 0) {
    buffer[0] = '0';
    buffer[1] = '\0';
  }
  int buffer_len = (int)s21_strlen(buffer);

  if (options->precision < buffer_len) options->precision = buffer_len;

  if (options->precision > buffer_len)
    options->add_zeroes = options->precision - buffer_len;

  char prefix[3] = "";

  if (options->specificator == 'o') {
    if (options->add_zeroes == 0 && options->flag_sharp) {
      prefix[0] = '0';
      prefix[1] = '\0';
    }
  }
  if (options->specificator == 'p' ||
      (options->specificator == 'x' && options->flag_sharp)) {
    prefix[0] = '0';
    prefix[1] = 'x';
    prefix[2] = '\0';
  }
  if (options->specificator == 'X' && options->flag_sharp) {
    prefix[0] = '0';
    prefix[1] = 'X';
    prefix[2] = '\0';
  }

  int prefix_len = (int)s21_strlen(prefix);

  char sign = 0;

  if (options->is_negative) {
    sign = '-';
  } else if (options->flag_sign) {
    sign = '+';
  } else if (options->flag_space) {
    sign = ' ';
  }

  int sign_len = sign ? 1 : 0;

  options->arg_len = options->precision + prefix_len + sign_len;

  if (options->width > options->arg_len) {
    options->out_len = options->width;
  } else {
    options->out_len = options->arg_len;
  }

  if (options->out_len > options->arg_len && options->flag_zero) {
    options->add_zeroes = options->out_len - options->arg_len;
  }

  char *out_str = (char *)malloc((options->out_len + 1) * sizeof(char));

  s21_memset(out_str, ' ', options->out_len);

  out_str[options->out_len] = '\0';

  char *p = out_str + options->out_len - buffer_len;

  if (options->specificator == 'X') {
    char *X_buffer = (char *)s21_to_upper(buffer);
    s21_strcpy(p, X_buffer);
    free(X_buffer);
  } else {
    s21_strcpy(p, buffer);
  }
  p = p - options->add_zeroes;

  s21_memset(p, '0', options->add_zeroes);

  p = p - prefix_len;

  s21_memcpy(p, prefix, prefix_len);

  p = p - sign_len;

  s21_memset(p, sign, sign_len);

  if (options->flag_align) {
    int spase_len = s21_strspn(out_str, " ");
    if (options->flag_space) spase_len--;
    s21_memmove(out_str, out_str + spase_len, options->out_len - spase_len);
    s21_memset(out_str + options->out_len - spase_len, ' ', spase_len);
  }

  return out_str;
}

void write_exponent(int *exponent, long double *digit) {
  while (*digit >= 10) {
    *digit /= 10;
    *exponent += 1;
  }
  while (*digit < 1 && *digit > 0) {
    *digit *= 10;
    *exponent -= 1;
  }
}

char *sprintf_eEfgG(spec_struct *options, va_list ap) {
  long double digit = 0.;
  if (options->type_ld) {
    digit = (long double)va_arg(ap, long double);
  } else {
    digit = (long double)va_arg(ap, double);
  }
  if (digit < 0) {
    options->is_negative = 1;
    digit = -digit;
  }

  long double digit_copy = digit;
  int exponent = 0;
  if (s21_strchr("eE", options->specificator) != S21_NULL &&
      digit != INFINITY && digit != NAN) {
    write_exponent(&exponent, &digit_copy);
    digit = digit_copy;
  }

  int g_flag = 0;
  if (s21_strchr("gG", options->specificator) != S21_NULL &&
      digit != INFINITY && digit != NAN) {
    write_exponent(&exponent, &digit_copy);
    g_flag = 1;

    if (options->precision == 0) options->precision = 1;
    if (options->precision > exponent && exponent >= -4) {
      options->precision = options->precision - (exponent + 1);
    } else {
      if (options->specificator == 'g') {
        options->specificator = 'e';
      } else {
        options->specificator = 'E';
      }
      options->precision = options->precision - 1;
      write_exponent(&exponent, &digit_copy);
      digit = digit_copy;
    }
  }
  unsigned long long digit_int = (unsigned long long)digit;
  long double temp = digit - digit_int;

  unsigned long long digit_fraction = 0;
  unsigned long long j = 1;
  for (int i = 1; i <= options->precision; i++) j *= 10;

  digit_fraction = (unsigned long long)(temp * j + 0.5);

  if (digit_fraction >= j) {
    digit_fraction -= j;
    digit_int += 1;
  }

  unsigned long long j_trim_count = 0;

  if (g_flag) {
    while (digit_fraction) {
      unsigned long long temp = digit_fraction % 10;
      if (temp) {
        break;
      } else {
        digit_fraction /= 10;
        j_trim_count += 1;
      }
    }
  }

  int dot_len = 1;

  if (options->precision == 0) {
    digit_int += digit_fraction;
    dot_len = 0;
  }

  char str_digit_fraction[40] = "";
  char str_digit_fraction_zeroes[20] = "";

  unsigned long long digit_fraction_zeroes = 0;

  digit_fraction_zeroes = s21_strlen(digit_ull_to_string(j)) - j_trim_count -
                           s21_strlen(digit_ull_to_string(digit_fraction));
  if (digit_fraction_zeroes < 1) {
    digit_fraction_zeroes = 1;
  }
  digit_fraction_zeroes -= 1;

  if (isnan(digit)) digit_fraction_zeroes = 0;

  char str_digit_fraction_end_zeroes[40] = "";
  if (s21_strchr("Gg", options->specificator) != S21_NULL &&
      options->flag_sharp) {
    s21_memset(str_digit_fraction_end_zeroes, '0', j_trim_count);
  }

  s21_memset(str_digit_fraction_zeroes, '0', digit_fraction_zeroes);
  s21_strcat(str_digit_fraction, str_digit_fraction_zeroes);
  s21_strcat(str_digit_fraction, digit_ull_to_string(digit_fraction));
  s21_strcat(str_digit_fraction, str_digit_fraction_end_zeroes);

  if (g_flag && digit == 0 && digit_fraction == 0 &&
      options->flag_sharp != 1) {
    s21_strcpy(str_digit_fraction, "");
    dot_len = 0;
  }

  char str_digit_int[40] = "";
  s21_strcpy(str_digit_int, digit_ull_to_string(digit_int));

  char digit_str_out[40] = "";
  s21_strcat(digit_str_out, str_digit_int);

  if (dot_len) {
    s21_strcat(digit_str_out, ".");
    s21_strcat(digit_str_out, str_digit_fraction);
  } else if (options->flag_sharp) {
    s21_strcat(digit_str_out, ".");
  }
  char postfix[30] = "";
  if (s21_strchr("eE", options->specificator) != S21_NULL) {
    postfix[0] = options->specificator == 'E' ? 'E' : 'e';
    int sign_exponent = 0;
    if (exponent < 0) {
      exponent = -exponent;
      sign_exponent = 1;
    }
    if (sign_exponent == 0) {
      postfix[1] = '+';
    } else {
      postfix[1] = '-';
    }
    if (exponent < 10) {
      postfix[2] = '0';
      postfix[3] = exponent + '0';
    } else {
      s21_strcat(postfix, digit_ull_to_string(exponent));
    }
  }
  s21_strcat(digit_str_out, postfix);

  if (digit == INFINITY) {
    if (s21_strchr("GE", options->specificator) != S21_NULL) {
      s21_strcpy(digit_str_out, "INF");
    } else {
      s21_strcpy(digit_str_out, "inf");
    }
    options->flag_zero = 0;
  }
  if (isnan(digit)) {
    if (s21_strchr("EG", options->specificator) != S21_NULL) {
      s21_strcpy(digit_str_out, "NAN");
    } else {
      s21_strcpy(digit_str_out, "nan");
    }
    options->flag_zero = 0;
  }

  char sign = 0;

  if (options->is_negative) {
    sign = '-';
  } else if (options->flag_sign) {
    sign = '+';
  } else if (options->flag_space) {
    sign = ' ';
  }

  int sign_len = sign ? 1 : 0;

  options->out_len =
      (options->width >= (int)s21_strlen(digit_str_out) + sign_len)
          ? options->width
          : (int)s21_strlen(digit_str_out) + sign_len;

  char *out_str = S21_NULL;
  if ((out_str = (char *)malloc((options->out_len + 1) * sizeof(char))) !=
      S21_NULL) {
    s21_memset(out_str, ' ', options->out_len);
    out_str[options->out_len] = '\0';

    if (options->flag_zero) {
      options->add_zeroes =
          (options->width - sign_len - (int)s21_strlen(digit_str_out)) < 0
              ? 0
              : options->width - sign_len - (int)s21_strlen(digit_str_out);
    }

    char *p = out_str + options->out_len - s21_strlen(digit_str_out);

    s21_memcpy(p, digit_str_out, s21_strlen(digit_str_out));

    if (options->add_zeroes > 0) p = p - options->add_zeroes;

    s21_memset(p, '0', options->add_zeroes);

    p = p - sign_len;

    s21_memset(p, sign, sign_len);

    if (options->flag_align) {
      int spase_len = s21_strspn(out_str, " ");
      if (sign == ' ') spase_len--;

      s21_memmove(out_str, out_str + spase_len,
                  options->out_len - spase_len);
      s21_memset(out_str + options->out_len - spase_len, ' ', spase_len);
    }
  }
  return out_str;
}

void sprintf_num_sys_to_str(char *str, unsigned long int lint, int num_sys) {
  char *s = str;
  while (lint) {
    char ost_chr;
    int ostatok = lint % num_sys;
    if (ostatok <= 9) {
      ost_chr = ostatok + '0';
    } else {
      ost_chr = ostatok + 87;
    }
    *s++ = ost_chr;
    lint = lint / num_sys;
  }
  *s = '\0';
  reverse_str(str);
}

void reverse_str(char *str) {
  for (int i = s21_strlen(str) - 1, j = 0; i > j; i--, j++) {
    char c = str[j];
    str[j] = str[i];
    str[i] = c;
  }
}

void sscanf_options_struct(spec_struct *options, const char *str, int str_len) {
  struct_init(options);
  options->specificator = str[str_len];
  int i = 0;
  if (str[i] == '*') {
    options->flag_star_width = 1;
    i++;
  }
  while ((s21_strchr("0123456789", str[i]) != S21_NULL)) {
    options->width = options->width * 10 + (str[i] - '0');
    i++;
  }
  if (str[i] == 'h') {
    options->type_short = 1;
  }
  if (str[i] == 'l') {
    options->type_long = 1;
  }
  if (str[i] == 'L') {
    options->type_ld = 1;
  }
}

int sscanf_i(long long int *out_int, char *in_str, int *in_str_index,
             int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  int negative = 0;
  int i = *in_str_index;
  int notation = 0;
  int flag_continue = 1;
  if (in_str[i] == '-') {
    negative = 1;
    i++;
    width--;
  } else if (in_str[i] == '+') {
    i++;
    width--;
  }
  if (in_str[i] == '0' && (in_str[i + 1] == 'x' || in_str[i + 1] == 'X') &&
      (width >= 2 || width_ignor)) {
    notation = 16;
    i = i + 2;
    width = width - 2;
  } else if (in_str[i] == '0' &&
             s21_strchr("01234567", in_str[i + 1]) != S21_NULL &&
             (width >= 2 || width_ignor)) {
    notation = 8;
    i++;
    width--;
  } else if (s21_strchr("0123456789", in_str[i]) != S21_NULL &&
             (width >= 1 || width_ignor)) {
    notation = 10;
  } else {
    flag_continue = 0;
  }
  char buffer[50] = "";
  int j = 0;
  while (in_str[i] && flag_continue && (width || width_ignor) &&
         ((notation == 8 && s21_strchr("01234567", in_str[i]) != S21_NULL) ||
          (notation == 10 && s21_strchr("0123456789", in_str[i]) != S21_NULL) ||
          (notation == 16 &&
           s21_strchr("0123456789abcdefABCDEF", in_str[i]) != S21_NULL))) {
    buffer[j] = in_str[i];
    j++;
    i++;
    width--;
    flag_success = 1;
  }
  if (flag_success) {
    buffer[j] = '\0';
    *out_int = str_to_int(buffer, notation);
    if (negative) *out_int = -*out_int;
    *in_str_index = i;
  }
  return flag_success;
}

int sscanf_d(long long int *out_int, char *in_str, int *in_str_index,
             int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  int negative = 0;
  int i = *in_str_index;
  if (in_str[i] == '-') {
    negative = 1;
    i++;
    width--;
  } else if (in_str[i] == '+') {
    i++;
    width--;
  }
  char digit[] = "0123456789";
  char buffer[50] = "";
  int j = 0;
  while ((width || width_ignor) && in_str[i] &&
         (s21_strchr(digit, in_str[i]) != S21_NULL)) {
    buffer[j] = in_str[i];
    width--;
    i++;
    j++;
    flag_success = 1;
  }
  if (flag_success) {
    buffer[j] = '\0';
    *out_int = str_to_int(buffer, 10);
    if (negative) *out_int = -*out_int;
    *in_str_index = i;
  }
  return flag_success;
}

int sscanf_x(long long int *out_int, char *in_str, int *in_str_index,
             int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  int negative = 0;
  int i = *in_str_index;
  if (in_str[i] == '-') {
    negative = 1;
    i++;
    width--;
  } else if (in_str[i] == '+') {
    i++;
    width--;
  }
  if (in_str[i] == '0' && (in_str[i + 1] == 'x' || in_str[i + 1] == 'X') &&
      (width >= 2 || width_ignor)) {
    i = i + 2;
    width = width - 2;
    char buffer[50] = "";
    int j = 0;
    while (in_str[i] && (width || width_ignor) &&
           s21_strchr("0123456789abcdefABCDEF", in_str[i]) != S21_NULL) {
      buffer[j] = in_str[i];
      j++;
      i++;
      width--;
      flag_success = 1;
    }
    if (flag_success) {
      buffer[j] = '\0';
      *out_int = str_to_int(buffer, 16);
      if (negative) *out_int = -*out_int;
      *in_str_index = i;
    }
  }
  return flag_success;
}

int sscanf_hex(long long int *out_int, char *in_str, int *in_str_index,
               int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  int negative = 0;
  int i = *in_str_index;
  if (in_str[i] == '-') {
    negative = 1;
    i++;
    width--;
  } else if (in_str[i] == '+') {
    i++;
    width--;
  }
  char buffer[50] = "";
  int j = 0;
  while (in_str[i] && (width || width_ignor) &&
         s21_strchr("0123456789abcdefABCDEF", in_str[i]) != S21_NULL) {
    buffer[j] = in_str[i];
    j++;
    i++;
    width--;
    flag_success = 1;
  }
  if (flag_success) {
    buffer[j] = '\0';
    *out_int = str_to_int(buffer, 16);
    if (negative) *out_int = -*out_int;
    *in_str_index = i;
  }
  return flag_success;
}

int sscanf_o(long long int *out_int, char *in_str, int *in_str_index,
             int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  int negative = 0;
  int i = *in_str_index;
  if (in_str[i] == '-') {
    negative = 1;
    i++;
    width--;
  } else if (in_str[i] == '+') {
    i++;
    width--;
  }
  if (in_str[i] == '0' && s21_strchr("01234567", in_str[i + 1]) != S21_NULL &&
      (width >= 2 || width_ignor)) {
    i++;
    width = width - 1;
    char buffer[50] = "";
    int j = 0;
    while (in_str[i] && (width || width_ignor) &&
           s21_strchr("01234567", in_str[i]) != S21_NULL) {
      buffer[j] = in_str[i];
      j++;
      i++;
      width--;
      flag_success = 1;
    }
    if (flag_success) {
      buffer[j] = '\0';
      *out_int = str_to_int(buffer, 8);
      if (negative) *out_int = -*out_int;
      *in_str_index = i;
    }
  }
  return flag_success;
}

int sscanf_f(long double *out_float, char *in_str, int *in_str_index,
             int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  long long int temp = 0;
  long double temp_float = 0;
  flag_success = sscanf_d(&temp, in_str, in_str_index, width);
  if (flag_success) {
    *out_float = temp;
    if (in_str[*in_str_index] == '.' && (width || width_ignor)) {
      (*in_str_index)++;
      width--;
      int exponent = 10;
      while ((width || width_ignor) &&
             s21_strchr("0123456789", in_str[*in_str_index]) != S21_NULL &&
             in_str[*in_str_index]) {
        temp_float += (long double)(in_str[*in_str_index] - '0') / exponent;
        exponent = exponent * 10;
        (*in_str_index)++;
        width--;
      }
      if (*out_float >= 0) {
        *out_float += temp_float;
      } else {
        *out_float -= temp_float;
      }
    }
  }
  return flag_success;
}

int sscanf_e(long double *out_float, char *in_str, int *in_str_index,
             int width) {
  int width_ignor = width ? 0 : 1;
  int flag_success = 0;
  long double buffer = 0;
  long long int exponent = 0;
  int start_index = *in_str_index;

  flag_success = sscanf_f(&buffer, in_str, in_str_index, width);
  width = width - (*in_str_index - start_index);
  if (flag_success) {
    if (in_str[*in_str_index] == 'e' || in_str[*in_str_index] == 'E') {
      width--;
      (*in_str_index)++;
      if (width > 0 || width_ignor) {
        sscanf_d(&exponent, in_str, in_str_index, width);
      }
    } else {
      flag_success = 0;
    }
  }
  if (flag_success) {
    if (exponent >= 0) {
      for (long long int i = 1; i <= exponent; i++) {
        buffer = buffer * 10;
      }
    } else {
      for (long long int i = 1; i <= -exponent; i++) {
        buffer = buffer / 10;
      }
    }
    *out_float = buffer;
  }
  return flag_success;
}

int check_inf_nan(long double *out_float, char *in_str, int *in_str_index,
                  int width) {
  int ret = 0;
  char *str = S21_NULL;
  str = s21_to_lower(in_str + *in_str_index);
  if (s21_strncmp("infinity", str, 8) == 0 && (width == 0 || width >= 8)) {
    *out_float = 1. / 0.;
    *in_str_index += 8;
    ret = 1;
  } else if (s21_strncmp("-infinity", str, 9) == 0 &&
             (width == 0 || width >= 8)) {
    *out_float = -1. / 0.;
    *in_str_index += 9;
    ret = 1;
  } else if (s21_strncmp("inf", str, 3) == 0 && (width == 0 || width >= 3)) {
    *out_float = 1. / 0.;
    *in_str_index += 3;
    ret = 1;
  } else if (s21_strncmp("-inf", str, 4) == 0 && (width == 0 || width >= 4)) {
    *out_float = -1. / 0.;
    *in_str_index += 4;
    ret = 1;
  } else if (s21_strncmp("nan", str, 3) == 0 && (width == 0 || width >= 3)) {
    *out_float = -(0. / 0.);
    *in_str_index += 3;
    ret = 1;
  } else if (s21_strncmp("-nan", str, 4) == 0 && (width == 0 || width >= 4)) {
    *out_float = 0. / 0.;
    *in_str_index += 4;
    ret = 1;
  }
  if (str != S21_NULL) free(str);
  return ret;
}

long long int str_to_int(char *str, int notation) {
  long long int result = 0;
  long long int k = 1;
  int i = s21_strlen(str);
  while (i > 0) {
    if (str[i - 1] <= '9') {
      result += (str[i - 1] - '0') * k;
    } else if (str[i - 1] >= 97 && str[i - 1] <= 102) {
      result += (str[i - 1] - 87) * k;
    } else {
      result += (str[i - 1] - 55) * k;
    }
    i--;
    k = k * notation;
  }
  return result;
}

int s21_sscanf(const char *str, const char *format, ...) {
  char *s = (char *)str;
  va_list ap;
  va_start(ap, format);
  spec_struct spec;
  spec_struct *options = &spec;
  char space_symbols[] = " \t\n\f\r\v";
  int stop_scan = 0;
  int ret = 0;
  int i = 0;
  int j = 0;
  for (; format[i] != '\0' && stop_scan == 0; i++) {
    while (s21_strchr(space_symbols, format[i]) != S21_NULL) {
      i++;
      while (s21_strchr(space_symbols, s[j]) != S21_NULL) {
        j++;
      }
    }
    while (format[i] != '%') {
      if (format[i] == s[j]) {
        i++;
        j++;
      } else {
        stop_scan = 1;
        break;
      }
    }

    if (format[i] == '%' && stop_scan == 0) {
      int str_specif_len = s21_strcspn(format + i + 1, "cdieEfgGosuxXpn%");
      sscanf_options_struct(options, format + i + 1, str_specif_len);

      if (options->specificator == 'c') {
        if (options->flag_star_width == 0) {
          char *c = (char *)va_arg(ap, char *);
          *c = s[j];
          j++;
          ret += 1;
        } else {
          j++;
        }
      }
      if (options->specificator == 's') {
        char *ptr = S21_NULL;
        if (options->flag_star_width == 0) {
          ptr = (char *)va_arg(ap, char *);
        }
        while (s21_strchr(space_symbols, s[j]) != S21_NULL) {
          j++;
        }
        int flag_width = 0;
        if (options->width) {
          flag_width = 1;
        } else {
          options->width = 1;
        }
        while (s21_strchr(space_symbols, s[j]) == S21_NULL &&
               options->width > 0) {
          if (options->flag_star_width == 0) {
            *ptr = s[j];
            ptr++;
          }
          j++;
          if (flag_width) options->width--;
        }
        if (options->flag_star_width == 0) {
          *ptr = '\0';
          ret += 1;
        }
      }
      if (options->specificator == '%') {
        while (s21_strchr(space_symbols, s[j]) != S21_NULL) {
          j++;
        }
        if (s[j] == '%') {
          j++;
        }
      }
      if (s21_strchr("diouxXp", options->specificator) != S21_NULL) {
        while (s21_strchr(space_symbols, s[j]) != S21_NULL) {
          j++;
        }
        long long int result = 0;
        int flag_success = 0;
        if (options->specificator == 'd' ||
            options->specificator == 'u') {
          flag_success = sscanf_d(&result, s, &j, options->width);
        }
        if (options->specificator == 'x' ||
            options->specificator == 'X') {
          flag_success = sscanf_x(&result, s, &j, options->width);
          if (!flag_success) {
            if (s[j] == '0') {
              result = 0;
              j++;
              flag_success = 1;
            } else if ((s[j] == '-' || s[j] == '+') && s[j + 1] == '0' &&
                       options->width != 1) {
              result = 0;
              j += 2;
              flag_success = 1;
            }
          }
        }
        if (options->specificator == 'o') {
          flag_success = sscanf_o(&result, s, &j, options->width);
        }
        if (options->specificator == 'i') {
          flag_success = sscanf_i(&result, s, &j, options->width);
        }
        if (options->specificator == 'p') {
          flag_success = sscanf_x(&result, s, &j, options->width);
          if (!flag_success) {
            flag_success = sscanf_hex(&result, s, &j, options->width);
          }
        }
        if (flag_success) {
          if (options->flag_star_width == 0) {
            if (options->type_short) {
              short int *ptr = (short int *)va_arg(ap, int *);
              *ptr = (short int)result;
            } else if (options->type_long) {
              long long int *ptr = (long long int *)va_arg(ap, long long int *);
              *ptr = (long long int)result;
            } else if (options->specificator == 'p') {
              long long int **ptr =
                  (long long int **)va_arg(ap, long long int **);
              *ptr = (long long int *)result;
            } else {
              int *ptr = (int *)va_arg(ap, int *);
              *ptr = result;
            }
            ret++;
          }
        } else {
          stop_scan = 1;
        }
      }
      if (s21_strchr("feEgG", options->specificator) != S21_NULL) {
        while (s21_strchr(space_symbols, s[j]) != S21_NULL) {
          j++;
        }
        long double result = 0;
        int flag_success = 0;
        if (check_inf_nan(&result, s, &j, options->width)) {
          flag_success = 1;
        } else {
          int safe_j = j;
          flag_success = sscanf_e(&result, s, &j, options->width);
          if (!flag_success) {
            j = safe_j;
            flag_success = sscanf_f(&result, s, &j, options->width);
          }
        }
        if (options->flag_star_width == 0) {
          if (flag_success) {
            if (options->type_ld) {
              long double *ptr = (long double *)va_arg(ap, long double *);
              *ptr = result;
            } else {
              float *ptr = (float *)va_arg(ap, float *);
              *ptr = (float)result;
            }
            ret++;
          } else {
            stop_scan = 1;
          }
        }
      }
      if (options->specificator == 'n') {
        int *ptr = va_arg(ap, int *);
        *ptr = j;
      }
      i += str_specif_len + 1;
    }
  }
  va_end(ap);
  return ret;
}
