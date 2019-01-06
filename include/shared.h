/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 */

#ifndef _SHARED_H
#define _SHARED_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <zlib.h>

#if defined (_WIN)
#include <winsock2.h> // needed for select()
#else
#include <sys/select.h>
#endif

bool overflow_check_u32_add (const u32 a, const u32 b);
bool overflow_check_u32_mul (const u32 a, const u32 b);
bool overflow_check_u64_add (const u64 a, const u64 b);
bool overflow_check_u64_mul (const u64 a, const u64 b);

bool is_power_of_2 (const u32 v);

u32 get_random_num (const u32 min, const u32 max);

u32 mydivc32 (const u32 dividend, const u32 divisor);
u64 mydivc64 (const u64 dividend, const u64 divisor);

char *filename_from_filepath (char *filepath);

void naive_replace (char *s, const char key_char, const char replace_char);
void naive_escape (char *s, size_t s_max, const char key_char, const char escape_char);

__attribute__ ((format (printf, 2, 3))) void hc_asprintf (char **strp, const char *fmt, ...);

void setup_environment_variables (void);
void setup_umask (void);
void setup_seeding (const bool rp_gen_seed_chgd, const u32 rp_gen_seed);

void  hc_qsort_r (void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *, void *), void *arg);
void *hc_bsearch_r (const void *key, const void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *, void *), void *arg);

bool hc_path_is_file (const char *path);
bool hc_path_is_directory (const char *path);
bool hc_path_is_empty (const char *path);
bool hc_path_exist (const char *path);
bool hc_path_read (const char *path);
bool hc_path_write (const char *path);
bool hc_path_create (const char *path);
bool hc_path_has_bom (const char *path);

bool hc_string_is_digit (const char *s);

void hc_string_trim_trailing (char *s);
void hc_string_trim_leading (char *s);

bool   hc_fopen(fp_tmp_t *fp_t, const char *path, char *mode);
size_t hc_fread (void *ptr, size_t size, size_t nmemb, fp_tmp_t *fp_t);
size_t hc_fread_direct (void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t hc_fwrite (void *ptr, size_t size, size_t nmemb, fp_tmp_t *fp_t);
void   hc_fwrite_direct (const void *ptr, size_t size, size_t nmemb, FILE *stream);
int    hc_fseek (fp_tmp_t *fp_t, off_t offset, int whence);
void   hc_rewind (fp_tmp_t *fp_t);
off_t  hc_ftell (fp_tmp_t *fp_t);
int    hc_fgetc (fp_tmp_t *fp_t);
int    hc_fputc (int c, fp_tmp_t *fp_t);
char  *hc_fgets (char *buf, int len, fp_tmp_t *fp_t);
int    hc_fileno (fp_tmp_t *fp_t);
int    hc_feof (fp_tmp_t *fp_t);
//void   hc_fflush (fp_tmp_t *fp_t);
void   hc_fclose (fp_tmp_t *fp_t);

bool hc_same_files (char *file1, char *file2);

u32 hc_strtoul  (const char *nptr, char **endptr, int base);
u64 hc_strtoull (const char *nptr, char **endptr, int base);

u32 power_of_two_ceil_32  (const u32 v);
u32 power_of_two_floor_32 (const u32 v);

u32 round_up_multiple_32 (const u32 v, const u32 m);
u64 round_up_multiple_64 (const u64 v, const u64 m);

void hc_strncat (u8 *dst, u8 *src, const size_t n);

int count_char (const u8 *buf, const int len, const u8 c);
float get_entropy (const u8 *buf, const int len);

int select_read_timeout  (int sockfd, const int sec);
int select_write_timeout (int sockfd, const int sec);

int select_read_timeout_console (const int sec);

#endif // _SHARED_H
