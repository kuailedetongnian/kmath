//
// FastIO.hpp
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C++/Include/FastIO.hpp
//

#ifndef _FASTIO_HPP_
#define _FASTIO_HPP_

#include "wxh/wxh"

#include <cstdio>
#include <cctype>
#include <cwctype>
#include <cwchar>

_WXH_BEGIN

class FastIO {
#pragma region zi yuan
public:
    static constexpr unsigned char radix_min = 2;

    static constexpr unsigned char radix_max = 64;

    static constexpr char digits[] = {
        '0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', '+', '/'
    };

    static constexpr char mapping_digits[] = {
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0x3E, (char)0xFF, (char)0xFF, (char)0xFF, (char)0x3F,
        (char)0x00, (char)0x01, (char)0x02, (char)0x03, (char)0x04, (char)0x05, (char)0x06, (char)0x07, (char)0x08, (char)0x09, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0x24, (char)0x25, (char)0x26, (char)0x27, (char)0x28, (char)0x29, (char)0x2A, (char)0x2B, (char)0x2C, (char)0x2D, (char)0x2E, (char)0x2F, (char)0x30, (char)0x31, (char)0x32,
        (char)0x33, (char)0x34, (char)0x35, (char)0x36, (char)0x37, (char)0x38, (char)0x39, (char)0x3A, (char)0x3B, (char)0x3C, (char)0x3D, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0x0A, (char)0x0B, (char)0x0C, (char)0x0D, (char)0x0E, (char)0x0F, (char)0x10, (char)0x11, (char)0x12, (char)0x13, (char)0x14, (char)0x15, (char)0x16, (char)0x17, (char)0x18,
        (char)0x19, (char)0x1A, (char)0x1B, (char)0x1C, (char)0x1D, (char)0x1E, (char)0x1F, (char)0x20, (char)0x21, (char)0x22, (char)0x23, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF,
        (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF, (char)0xFF
    };

    static char buffer[255];
#pragma endregion zi yuan
public:
#pragma region input
#define K_DEFINE_FIO_READ_FUNC(getc_func, ...)                        \
    template <class IntegerType>                                      \
    static void read(__VA_ARGS__) {                                   \
        char last_get = getc_func;                                    \
        char now_get;                                                 \
        if('0' <= last_get && last_get <= '9') {                      \
            x = last_get ^ 48;                                        \
            while(('0' <= (now_get = getc_func)) && (now_get <= '9')) \
                x = (x << 3) + (x << 1) + (now_get ^ 48);             \
            return;                                                   \
        }                                                             \
        x = 0;                                                        \
        while(!(('0' <= (now_get = getc_func)) && (now_get <= '9')))  \
            last_get = now_get;                                       \
        do                                                            \
            x = (x << 3) + (x << 1) + (now_get ^ 48);                 \
        while(('0' <= (now_get = getc_func)) && (now_get <= '9'));    \
        if(last_get == '-')                                           \
            x = -x;                                                   \
        return;                                                       \
    }

    /* read a Integer from stdin */
    K_DEFINE_FIO_READ_FUNC(getchar(), IntegerType& x)

    /* read a Integer from string_buffer */
    K_DEFINE_FIO_READ_FUNC(*string_buffer++, IntegerType& x, const char* string_buffer)

    /* read a Integer from file */
    K_DEFINE_FIO_READ_FUNC(fgetc(fp), IntegerType& x, FILE* fp)

#undef K_DEFINE_FIO_READ_FUNC

#define K_DEFINE_FIO_READU_FUNC(getc_func, ...)           \
    template <class UnsignedIntegerType>                  \
    static void readu(__VA_ARGS__) {                      \
        x = 0;                                            \
        char c;                                           \
        while(!(('0' <= (c = getc_func)) && (c <= '9'))); \
        do                                                \
            x = (x << 3) + (x << 1) + (c ^ 48);           \
        while(('0' <= (c = getc_func)) && (c <= '9'));    \
        return;                                           \
    }

    /* read a Unsigned Integer from stdin */
    K_DEFINE_FIO_READU_FUNC(getchar(), UnsignedIntegerType& x)

    /* read a Unsigned Integer from string_buffer */
    K_DEFINE_FIO_READU_FUNC(*string_buffer++, UnsignedIntegerType& x, const char* string_buffer)

    /* read a Unsigned Integer from file */
    K_DEFINE_FIO_READU_FUNC(fgetc(fp), UnsignedIntegerType& x, FILE* fp)

#undef K_DEFINE_FIO_READU_FUNC

#define K_DEFINE_FIO_READ_S_FUNC(isspace_func, getc_func, ...) \
    static void read(__VA_ARGS__) {                            \
        while(isspace_func(*s = getc_func));                   \
        while(!isspace_func(*++s = getc_func));                \
        *s = 0;                                                \
        return;                                                \
    }

    /* read a string from stdin */
    K_DEFINE_FIO_READ_S_FUNC(isspace, getchar(), char* s)

    /* read a wide string from stdin */
    K_DEFINE_FIO_READ_S_FUNC(iswspace, getwchar(), wchar_t* s)

    /* read a string from string_buffer */
    K_DEFINE_FIO_READ_S_FUNC(isspace, *string_buffer++, char* s, const char* string_buffer)

    /* read a wide string from string_buffer */
    K_DEFINE_FIO_READ_S_FUNC(iswspace, *string_buffer++, wchar_t* s, const wchar_t* string_buffer)

    /* read a string from file */
    K_DEFINE_FIO_READ_S_FUNC(isspace, fgetc(fp), char* s, FILE* fp)

    /* read a wide string from file */
    K_DEFINE_FIO_READ_S_FUNC(iswspace, fgetwc(fp), wchar_t* s, FILE* fp)

#undef K_DEFINE_FIO_READ_S_FUNC

#define K_DEFINE_FIO_READ_SLN_FUNC(getc_func, ...)           \
    static void readln(__VA_ARGS__) {                        \
        while((*s++ = getc_func) != (decltype(*s + 0))'\n'); \
        *(s - 1) = 0;                                        \
        return;                                              \
    }

    /* read a line of string from stdin */
    K_DEFINE_FIO_READ_SLN_FUNC(getchar(), char* s)

    /* read a line of wide string from stdin */
    K_DEFINE_FIO_READ_SLN_FUNC(getwchar(), wchar_t* s)

    /* read a line of string from string_buffer */
    K_DEFINE_FIO_READ_SLN_FUNC(*string_buffer++, char* s, const char* string_buffer)

    /* read a line of wide string from string_buffer */
    K_DEFINE_FIO_READ_SLN_FUNC(*string_buffer++, wchar_t* s, const wchar_t* string_buffer)

    /* read a line of string from file */
    K_DEFINE_FIO_READ_SLN_FUNC(fgetc(fp), char* s, FILE* fp)

    /* read a line of wide string from file */
    K_DEFINE_FIO_READ_SLN_FUNC(fgetwc(fp), wchar_t* s, FILE* fp)

#undef K_DEFINE_FIO_READ_SLN_FUNC

    /**
     * Be careful!
     * The Base-32 contains 22 letters of A-V, which are not case sensitive.
     */

    template<class Integer>
    static void read(Integer& x, int radix) {
        using read_radix_t = void (*)(Integer&);
        static constexpr read_radix_t read_radix[] = {
            nullptr, nullptr, read2,  read3,  read4,  read5,  read6,  read7,
            read8,   read9,   read,   read11, read12, read13, read14, read15,
            read16,  read17,  read18, read19, read20, read21, read22, read23,
            read24,  read25,  read26, read27, read28, read29, read30, read31,
            read32,  read33,  read34, read35, read36, read37, read38, read39,
            read40,  read41,  read42, read43, read44, read45, read46, read47,
            read48,  read49,  read50, read51, read52, read53, read54, read55,
            read56,  read57,  read58, read59, read60, read61, read62, read63,
            read64
        };
        if(radix > radix_max)
            radix = 10;
        if(radix < radix_min)
            radix = 10;
        read_radix[radix](x);
        return;
    }

    template<class Integer>
    static void read(Integer& x, const char* string_buffer, int radix) {
        using read_radix_t = void (*)(Integer&, const char*);
        static constexpr read_radix_t read_radix[] = {
            nullptr, nullptr, read2,  read3,  read4,  read5,  read6,  read7,
            read8,   read9,   read,   read11, read12, read13, read14, read15,
            read16,  read17,  read18, read19, read20, read21, read22, read23,
            read24,  read25,  read26, read27, read28, read29, read30, read31,
            read32,  read33,  read34, read35, read36, read37, read38, read39,
            read40,  read41,  read42, read43, read44, read45, read46, read47,
            read48,  read49,  read50, read51, read52, read53, read54, read55,
            read56,  read57,  read58, read59, read60, read61, read62, read63,
            read64
        };
        if(radix > radix_max)
            radix = 10;
        if(radix < radix_min)
            radix = 10;
        read_radix[radix](x, string_buffer);
        return;
    }

    template<class Integer>
    static void read(Integer& x, FILE* fp, int radix) {
        using read_radix_t = void (*)(Integer&, FILE*);
        static constexpr read_radix_t read_radix[] = {
            nullptr, nullptr, read2,  read3,  read4,  read5,  read6,  read7,
            read8,   read9,   read,   read11, read12, read13, read14, read15,
            read16,  read17,  read18, read19, read20, read21, read22, read23,
            read24,  read25,  read26, read27, read28, read29, read30, read31,
            read32,  read33,  read34, read35, read36, read37, read38, read39,
            read40,  read41,  read42, read43, read44, read45, read46, read47,
            read48,  read49,  read50, read51, read52, read53, read54, read55,
            read56,  read57,  read58, read59, read60, read61, read62, read63,
            read64
        };
        if(radix > radix_max)
            radix = 10;
        if(radix < radix_min)
            radix = 10;
        read_radix[radix](x, fp);
        return;
    }

    template<class UnsignedInteger>
    static void readu(UnsignedInteger& x, int radix) {
        using readu_radix_t = void (*)(UnsignedInteger&);
        static constexpr readu_radix_t readu_radix[] = {
            nullptr, nullptr, readu2,  readu3,  readu4,  readu5,  readu6,  readu7,
            readu8,  readu9,  readu,   readu11, readu12, readu13, readu14, readu15,
            readu16, readu17, readu18, readu19, readu20, readu21, readu22, readu23,
            readu24, readu25, readu26, readu27, readu28, readu29, readu30, readu31,
            readu32, readu33, readu34, readu35, readu36, readu37, readu38, readu39,
            readu40, readu41, readu42, readu43, readu44, readu45, readu46, readu47,
            readu48, readu49, readu50, readu51, readu52, readu53, readu54, readu55,
            readu56, readu57, readu58, readu59, readu60, readu61, readu62, readu63,
            readu64
        };
        if(radix > radix_max)
            radix = 10;
        if(radix < radix_min)
            radix = 10;
        readu_radix[radix](x);
        return;
    }

    template<class UnsignedInteger>
    static void readu(UnsignedInteger& x, const char* string_buffer, int radix) {
        using readu_radix_t = void (*)(UnsignedInteger&, const char*);
        static constexpr readu_radix_t readu_radix[] = {
            nullptr, nullptr, readu2,  readu3,  readu4,  readu5,  readu6,  readu7,
            readu8,  readu9,  readu,   readu11, readu12, readu13, readu14, readu15,
            readu16, readu17, readu18, readu19, readu20, readu21, readu22, readu23,
            readu24, readu25, readu26, readu27, readu28, readu29, readu30, readu31,
            readu32, readu33, readu34, readu35, readu36, readu37, readu38, readu39,
            readu40, readu41, readu42, readu43, readu44, readu45, readu46, readu47,
            readu48, readu49, readu50, readu51, readu52, readu53, readu54, readu55,
            readu56, readu57, readu58, readu59, readu60, readu61, readu62, readu63,
            readu64
        };
        if(radix > radix_max)
            radix = 10;
        if(radix < radix_min)
            radix = 10;
        readu_radix[radix](x, string_buffer);
        return;
    }

    template<class UnsignedInteger>
    static void readu(UnsignedInteger& x, FILE* fp, int radix) {
        using readu_radix_t = void (*)(UnsignedInteger&, FILE*);
        static constexpr readu_radix_t readu_radix[] = {
            nullptr, nullptr, readu2,  readu3,  readu4,  readu5,  readu6,  readu7,
            readu8,  readu9,  readu,   readu11, readu12, readu13, readu14, readu15,
            readu16, readu17, readu18, readu19, readu20, readu21, readu22, readu23,
            readu24, readu25, readu26, readu27, readu28, readu29, readu30, readu31,
            readu32, readu33, readu34, readu35, readu36, readu37, readu38, readu39,
            readu40, readu41, readu42, readu43, readu44, readu45, readu46, readu47,
            readu48, readu49, readu50, readu51, readu52, readu53, readu54, readu55,
            readu56, readu57, readu58, readu59, readu60, readu61, readu62, readu63,
            readu64
        };
        if(radix > radix_max)
            radix = 10;
        if(radix < radix_min)
            radix = 10;
        readu_radix[radix](x, fp);
        return;
    }

#define K_DEFINE_FIO_READ_RADIX_FUNC(getc_func, radix, mul_func, isdigit_func, ctoint_func, ...) \
    template<class Integer>                                                                      \
    static void read ## radix(__VA_ARGS__) {                                                     \
        char last_get = getc_func;                                                               \
        char now_get = getc_func;                                                                \
        if(isdigit_func(last_get)) {                                                             \
            x = ctoint_func(last_get);                                                           \
            while(isdigit_func(now_get))                                                         \
                x = mul_func + ctoint_func(now_get), now_get = getc_func;                        \
            return;                                                                              \
        }                                                                                        \
        x = 0;                                                                                   \
        while(!isdigit_func(now_get))                                                            \
            last_get = now_get, now_get = getc_func;                                                                  \
        do                                                                                       \
            x = mul_func + ctoint_func(now_get), now_get = getc_func;                            \
        while(isdigit_func(now_get));                                                            \
        if(last_get == '-')                                                                      \
            x = -x;                                                                              \
        return;                                                                                  \
    }

#define K_FIO_READ_SSF(radix, mul_func, isdigit_func, ctoint_func)                                                                             \
    K_DEFINE_FIO_READ_RADIX_FUNC(getchar(), radix, mul_func, isdigit_func, ctoint_func, Integer& x)                                   \
    K_DEFINE_FIO_READ_RADIX_FUNC(*string_buffer++, radix, mul_func, isdigit_func, ctoint_func, Integer& x, const char* string_buffer) \
    K_DEFINE_FIO_READ_RADIX_FUNC(fgetc(fp), radix, mul_func, isdigit_func, ctoint_func, Integer& x, FILE* fp)

#define K_DEFINE_FIO_READU_RADIX_FUNC(getc_func, radix, mul_func, isdigit_func, ctoint_func, ...) \
    template<class UnsignedInteger>                                                               \
    static void readu ## radix(__VA_ARGS__) {                                                     \
        x = 0;                                                                                    \
        char c = getc_func;                                                                       \
        while(!isdigit_func(c));                                                                  \
        do                                                                                        \
            x = mul_func + ctoint_func(c), c = getc_func;                                         \
        while(isdigit_func(c));                                                                   \
        return;                                                                                   \
    }

#define K_FIO_READU_SSF(radix, mul_func, isdigit_func, ctoint_func)                                                                             \
    K_DEFINE_FIO_READU_RADIX_FUNC(getchar(), radix, mul_func, isdigit_func, ctoint_func, UnsignedInteger& x)                                   \
    K_DEFINE_FIO_READU_RADIX_FUNC(*string_buffer++, radix, mul_func, isdigit_func, ctoint_func, UnsignedInteger& x, const char* string_buffer) \
    K_DEFINE_FIO_READU_RADIX_FUNC(fgetc(fp), radix, mul_func, isdigit_func, ctoint_func, UnsignedInteger& x, FILE* fp)

#define K_FIO_ISDIGIT_2(c)  (((c - '0') | 1) == 1)
#define K_FIO_ISDIGIT_3(c)  ('0' <= c && c <= '2')
#define K_FIO_ISDIGIT_4(c)  (((c - '0') | 3) == 3)
#define K_FIO_ISDIGIT_5(c)  ('0' <= c && c <= '4')
#define K_FIO_ISDIGIT_6(c)  ('0' <= c && c <= '5')
#define K_FIO_ISDIGIT_7(c)  ('0' <= c && c <= '6')
#define K_FIO_ISDIGIT_8(c)  (((c - '0') | 7) == 7)
#define K_FIO_ISDIGIT_9(c)  ('0' <= c && c <= '8')
#define K_FIO_ISDIGIT_10(c) ('0' <= c && c <= '9')
#define K_FIO_ISDIGIT_X(x, c)  (mapping_digits[c] != -1 && mapping_digits[c] < x)
#define K_FIO_ISDIGIT_11(c) K_FIO_ISDIGIT_X(11, tolower(c))
#define K_FIO_ISDIGIT_12(c) K_FIO_ISDIGIT_X(12, tolower(c))
#define K_FIO_ISDIGIT_13(c) K_FIO_ISDIGIT_X(13, tolower(c))
#define K_FIO_ISDIGIT_14(c) K_FIO_ISDIGIT_X(14, tolower(c))
#define K_FIO_ISDIGIT_15(c) K_FIO_ISDIGIT_X(15, tolower(c))
#define K_FIO_ISDIGIT_16(c) K_FIO_ISDIGIT_X(16, tolower(c))
#define K_FIO_ISDIGIT_17(c) K_FIO_ISDIGIT_X(17, tolower(c))
#define K_FIO_ISDIGIT_18(c) K_FIO_ISDIGIT_X(18, tolower(c))
#define K_FIO_ISDIGIT_19(c) K_FIO_ISDIGIT_X(19, tolower(c))
#define K_FIO_ISDIGIT_20(c) K_FIO_ISDIGIT_X(20, tolower(c))
#define K_FIO_ISDIGIT_21(c) K_FIO_ISDIGIT_X(21, tolower(c))
#define K_FIO_ISDIGIT_22(c) K_FIO_ISDIGIT_X(22, tolower(c))
#define K_FIO_ISDIGIT_23(c) K_FIO_ISDIGIT_X(23, tolower(c))
#define K_FIO_ISDIGIT_24(c) K_FIO_ISDIGIT_X(24, tolower(c))
#define K_FIO_ISDIGIT_25(c) K_FIO_ISDIGIT_X(25, tolower(c))
#define K_FIO_ISDIGIT_26(c) K_FIO_ISDIGIT_X(26, tolower(c))
#define K_FIO_ISDIGIT_27(c) K_FIO_ISDIGIT_X(27, tolower(c))
#define K_FIO_ISDIGIT_28(c) K_FIO_ISDIGIT_X(28, tolower(c))
#define K_FIO_ISDIGIT_29(c) K_FIO_ISDIGIT_X(29, tolower(c))
#define K_FIO_ISDIGIT_30(c) K_FIO_ISDIGIT_X(30, tolower(c))
#define K_FIO_ISDIGIT_31(c) K_FIO_ISDIGIT_X(31, tolower(c))
#define K_FIO_ISDIGIT_32(c) K_FIO_ISDIGIT_X(32, tolower(c))
#define K_FIO_ISDIGIT_33(c) K_FIO_ISDIGIT_X(33, tolower(c))
#define K_FIO_ISDIGIT_34(c) K_FIO_ISDIGIT_X(34, tolower(c))
#define K_FIO_ISDIGIT_35(c) K_FIO_ISDIGIT_X(35, tolower(c))
#define K_FIO_ISDIGIT_36(c) K_FIO_ISDIGIT_X(36, tolower(c))
#define K_FIO_ISDIGIT_37(c) K_FIO_ISDIGIT_X(37, c)
#define K_FIO_ISDIGIT_38(c) K_FIO_ISDIGIT_X(38, c)
#define K_FIO_ISDIGIT_39(c) K_FIO_ISDIGIT_X(39, c)
#define K_FIO_ISDIGIT_40(c) K_FIO_ISDIGIT_X(40, c)
#define K_FIO_ISDIGIT_41(c) K_FIO_ISDIGIT_X(41, c)
#define K_FIO_ISDIGIT_42(c) K_FIO_ISDIGIT_X(42, c)
#define K_FIO_ISDIGIT_43(c) K_FIO_ISDIGIT_X(43, c)
#define K_FIO_ISDIGIT_44(c) K_FIO_ISDIGIT_X(44, c)
#define K_FIO_ISDIGIT_45(c) K_FIO_ISDIGIT_X(45, c)
#define K_FIO_ISDIGIT_46(c) K_FIO_ISDIGIT_X(46, c)
#define K_FIO_ISDIGIT_47(c) K_FIO_ISDIGIT_X(47, c)
#define K_FIO_ISDIGIT_48(c) K_FIO_ISDIGIT_X(48, c)
#define K_FIO_ISDIGIT_49(c) K_FIO_ISDIGIT_X(49, c)
#define K_FIO_ISDIGIT_50(c) K_FIO_ISDIGIT_X(50, c)
#define K_FIO_ISDIGIT_51(c) K_FIO_ISDIGIT_X(51, c)
#define K_FIO_ISDIGIT_52(c) K_FIO_ISDIGIT_X(52, c)
#define K_FIO_ISDIGIT_53(c) K_FIO_ISDIGIT_X(53, c)
#define K_FIO_ISDIGIT_54(c) K_FIO_ISDIGIT_X(54, c)
#define K_FIO_ISDIGIT_55(c) K_FIO_ISDIGIT_X(55, c)
#define K_FIO_ISDIGIT_56(c) K_FIO_ISDIGIT_X(56, c)
#define K_FIO_ISDIGIT_57(c) K_FIO_ISDIGIT_X(57, c)
#define K_FIO_ISDIGIT_58(c) K_FIO_ISDIGIT_X(58, c)
#define K_FIO_ISDIGIT_59(c) K_FIO_ISDIGIT_X(59, c)
#define K_FIO_ISDIGIT_60(c) K_FIO_ISDIGIT_X(60, c)
#define K_FIO_ISDIGIT_61(c) K_FIO_ISDIGIT_X(61, c)
#define K_FIO_ISDIGIT_62(c) K_FIO_ISDIGIT_X(62, c)
#define K_FIO_ISDIGIT_63(c) K_FIO_ISDIGIT_X(63, c)
#define K_FIO_ISDIGIT_64(c) K_FIO_ISDIGIT_X(64, c)

#define K_FIO_CTOINT_LOW10(c) (c ^ 48)
#define K_FIO_CTOINT_LOW16(c) (mapping_digits[tolower(c)])
#define K_FIO_CTOINT_LOW64(c) (mapping_digits[c])

    K_FIO_READ_SSF(2,  (x << 1),            K_FIO_ISDIGIT_2,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(3,  (x << 1) + (x << 0), K_FIO_ISDIGIT_3,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(4,  (x << 2),            K_FIO_ISDIGIT_4,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(5,  (x << 2) + (x << 0), K_FIO_ISDIGIT_5,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(6,  (x << 2) + (x << 1), K_FIO_ISDIGIT_6,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(7,  (x * 7),             K_FIO_ISDIGIT_7,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(8,  (x << 3),            K_FIO_ISDIGIT_8,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(9,  (x << 3) + (x << 0), K_FIO_ISDIGIT_9,  K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(10, (x << 3) + (x << 1), K_FIO_ISDIGIT_10, K_FIO_CTOINT_LOW10)
    K_FIO_READ_SSF(11, (x * 11),            K_FIO_ISDIGIT_11, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(12, (x << 3) + (x << 2), K_FIO_ISDIGIT_12, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(13, (x * 13),            K_FIO_ISDIGIT_13, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(14, (x * 14),            K_FIO_ISDIGIT_14, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(15, (x * 15),            K_FIO_ISDIGIT_15, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(16, (x << 4),            K_FIO_ISDIGIT_16, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(17, (x << 4) + (x << 0), K_FIO_ISDIGIT_17, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(18, (x << 4) + (x << 1), K_FIO_ISDIGIT_18, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(19, (x * 19),            K_FIO_ISDIGIT_19, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(20, (x << 4) + (x << 2), K_FIO_ISDIGIT_20, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(21, (x * 21),            K_FIO_ISDIGIT_21, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(22, (x * 22),            K_FIO_ISDIGIT_22, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(23, (x * 23),            K_FIO_ISDIGIT_23, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(24, (x << 4) + (x << 3), K_FIO_ISDIGIT_24, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(25, (x * 25),            K_FIO_ISDIGIT_25, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(26, (x * 26),            K_FIO_ISDIGIT_26, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(27, (x * 27),            K_FIO_ISDIGIT_27, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(28, (x * 28),            K_FIO_ISDIGIT_28, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(29, (x * 29),            K_FIO_ISDIGIT_29, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(30, (x * 30),            K_FIO_ISDIGIT_30, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(31, (x * 31),            K_FIO_ISDIGIT_31, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(32, (x << 5),            K_FIO_ISDIGIT_32, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(33, (x << 5) + (x << 0), K_FIO_ISDIGIT_33, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(34, (x << 5) + (x << 1), K_FIO_ISDIGIT_34, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(35, (x * 35),            K_FIO_ISDIGIT_35, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(36, (x << 5) + (x << 2), K_FIO_ISDIGIT_36, K_FIO_CTOINT_LOW16)
    K_FIO_READ_SSF(37, (x * 37),            K_FIO_ISDIGIT_37, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(38, (x * 38),            K_FIO_ISDIGIT_38, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(39, (x * 39),            K_FIO_ISDIGIT_39, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(40, (x << 5) + (x << 3), K_FIO_ISDIGIT_40, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(41, (x * 41),            K_FIO_ISDIGIT_41, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(42, (x * 42),            K_FIO_ISDIGIT_42, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(43, (x * 43),            K_FIO_ISDIGIT_43, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(44, (x * 44),            K_FIO_ISDIGIT_44, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(45, (x * 45),            K_FIO_ISDIGIT_45, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(46, (x * 46),            K_FIO_ISDIGIT_46, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(47, (x * 47),            K_FIO_ISDIGIT_47, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(48, (x << 5) + (x << 4), K_FIO_ISDIGIT_48, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(49, (x * 49),            K_FIO_ISDIGIT_49, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(50, (x * 50),            K_FIO_ISDIGIT_50, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(51, (x * 51),            K_FIO_ISDIGIT_51, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(52, (x * 52),            K_FIO_ISDIGIT_52, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(53, (x * 53),            K_FIO_ISDIGIT_53, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(54, (x * 54),            K_FIO_ISDIGIT_54, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(55, (x * 55),            K_FIO_ISDIGIT_55, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(56, (x * 56),            K_FIO_ISDIGIT_56, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(57, (x * 57),            K_FIO_ISDIGIT_57, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(58, (x * 58),            K_FIO_ISDIGIT_58, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(59, (x * 59),            K_FIO_ISDIGIT_59, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(60, (x * 60),            K_FIO_ISDIGIT_60, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(61, (x * 61),            K_FIO_ISDIGIT_61, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(62, (x * 62),            K_FIO_ISDIGIT_62, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(63, (x * 63),            K_FIO_ISDIGIT_63, K_FIO_CTOINT_LOW64)
    K_FIO_READ_SSF(64, (x << 6),            K_FIO_ISDIGIT_64, K_FIO_CTOINT_LOW64)

    K_FIO_READU_SSF(2,  (x << 1),            K_FIO_ISDIGIT_2,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(3,  (x << 1) + (x << 0), K_FIO_ISDIGIT_3,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(4,  (x << 2),            K_FIO_ISDIGIT_4,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(5,  (x << 2) + (x << 0), K_FIO_ISDIGIT_5,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(6,  (x << 2) + (x << 1), K_FIO_ISDIGIT_6,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(7,  (x * 7),             K_FIO_ISDIGIT_7,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(8,  (x << 3),            K_FIO_ISDIGIT_8,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(9,  (x << 3) + (x << 0), K_FIO_ISDIGIT_9,  K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(10, (x << 3) + (x << 1), K_FIO_ISDIGIT_10, K_FIO_CTOINT_LOW10)
    K_FIO_READU_SSF(11, (x * 11),            K_FIO_ISDIGIT_11, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(12, (x << 3) + (x << 2), K_FIO_ISDIGIT_12, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(13, (x * 13),            K_FIO_ISDIGIT_13, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(14, (x * 14),            K_FIO_ISDIGIT_14, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(15, (x * 15),            K_FIO_ISDIGIT_15, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(16, (x << 4),            K_FIO_ISDIGIT_16, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(17, (x << 4) + (x << 0), K_FIO_ISDIGIT_17, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(18, (x << 4) + (x << 1), K_FIO_ISDIGIT_18, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(19, (x * 19),            K_FIO_ISDIGIT_19, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(20, (x << 4) + (x << 2), K_FIO_ISDIGIT_20, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(21, (x * 21),            K_FIO_ISDIGIT_21, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(22, (x * 22),            K_FIO_ISDIGIT_22, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(23, (x * 23),            K_FIO_ISDIGIT_23, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(24, (x << 4) + (x << 3), K_FIO_ISDIGIT_24, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(25, (x * 25),            K_FIO_ISDIGIT_25, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(26, (x * 26),            K_FIO_ISDIGIT_26, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(27, (x * 27),            K_FIO_ISDIGIT_27, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(28, (x * 28),            K_FIO_ISDIGIT_28, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(29, (x * 29),            K_FIO_ISDIGIT_29, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(30, (x * 30),            K_FIO_ISDIGIT_30, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(31, (x * 31),            K_FIO_ISDIGIT_31, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(32, (x << 5),            K_FIO_ISDIGIT_32, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(33, (x << 5) + (x << 0), K_FIO_ISDIGIT_33, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(34, (x << 5) + (x << 1), K_FIO_ISDIGIT_34, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(35, (x * 35),            K_FIO_ISDIGIT_35, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(36, (x << 5) + (x << 2), K_FIO_ISDIGIT_36, K_FIO_CTOINT_LOW16)
    K_FIO_READU_SSF(37, (x * 37),            K_FIO_ISDIGIT_37, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(38, (x * 38),            K_FIO_ISDIGIT_38, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(39, (x * 39),            K_FIO_ISDIGIT_39, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(40, (x << 5) + (x << 3), K_FIO_ISDIGIT_40, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(41, (x * 41),            K_FIO_ISDIGIT_41, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(42, (x * 42),            K_FIO_ISDIGIT_42, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(43, (x * 43),            K_FIO_ISDIGIT_43, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(44, (x * 44),            K_FIO_ISDIGIT_44, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(45, (x * 45),            K_FIO_ISDIGIT_45, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(46, (x * 46),            K_FIO_ISDIGIT_46, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(47, (x * 47),            K_FIO_ISDIGIT_47, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(48, (x << 5) + (x << 4), K_FIO_ISDIGIT_48, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(49, (x * 49),            K_FIO_ISDIGIT_49, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(50, (x * 50),            K_FIO_ISDIGIT_50, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(51, (x * 51),            K_FIO_ISDIGIT_51, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(52, (x * 52),            K_FIO_ISDIGIT_52, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(53, (x * 53),            K_FIO_ISDIGIT_53, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(54, (x * 54),            K_FIO_ISDIGIT_54, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(55, (x * 55),            K_FIO_ISDIGIT_55, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(56, (x * 56),            K_FIO_ISDIGIT_56, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(57, (x * 57),            K_FIO_ISDIGIT_57, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(58, (x * 58),            K_FIO_ISDIGIT_58, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(59, (x * 59),            K_FIO_ISDIGIT_59, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(60, (x * 60),            K_FIO_ISDIGIT_60, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(61, (x * 61),            K_FIO_ISDIGIT_61, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(62, (x * 62),            K_FIO_ISDIGIT_62, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(63, (x * 63),            K_FIO_ISDIGIT_63, K_FIO_CTOINT_LOW64)
    K_FIO_READU_SSF(64, (x << 6),            K_FIO_ISDIGIT_64, K_FIO_CTOINT_LOW64)

#undef K_FIO_ISDIGIT_2
#undef K_FIO_ISDIGIT_3
#undef K_FIO_ISDIGIT_4
#undef K_FIO_ISDIGIT_5
#undef K_FIO_ISDIGIT_6
#undef K_FIO_ISDIGIT_7
#undef K_FIO_ISDIGIT_8
#undef K_FIO_ISDIGIT_9
#undef K_FIO_ISDIGIT_10
#undef K_FIO_ISDIGIT_X
#undef K_FIO_ISDIGIT_11
#undef K_FIO_ISDIGIT_12
#undef K_FIO_ISDIGIT_13
#undef K_FIO_ISDIGIT_14
#undef K_FIO_ISDIGIT_15
#undef K_FIO_ISDIGIT_16
#undef K_FIO_ISDIGIT_17
#undef K_FIO_ISDIGIT_18
#undef K_FIO_ISDIGIT_19
#undef K_FIO_ISDIGIT_20
#undef K_FIO_ISDIGIT_21
#undef K_FIO_ISDIGIT_22
#undef K_FIO_ISDIGIT_23
#undef K_FIO_ISDIGIT_24
#undef K_FIO_ISDIGIT_25
#undef K_FIO_ISDIGIT_26
#undef K_FIO_ISDIGIT_27
#undef K_FIO_ISDIGIT_28
#undef K_FIO_ISDIGIT_29
#undef K_FIO_ISDIGIT_30
#undef K_FIO_ISDIGIT_31
#undef K_FIO_ISDIGIT_32
#undef K_FIO_ISDIGIT_33
#undef K_FIO_ISDIGIT_34
#undef K_FIO_ISDIGIT_35
#undef K_FIO_ISDIGIT_36
#undef K_FIO_ISDIGIT_37
#undef K_FIO_ISDIGIT_38
#undef K_FIO_ISDIGIT_39
#undef K_FIO_ISDIGIT_40
#undef K_FIO_ISDIGIT_41
#undef K_FIO_ISDIGIT_42
#undef K_FIO_ISDIGIT_43
#undef K_FIO_ISDIGIT_44
#undef K_FIO_ISDIGIT_45
#undef K_FIO_ISDIGIT_46
#undef K_FIO_ISDIGIT_47
#undef K_FIO_ISDIGIT_48
#undef K_FIO_ISDIGIT_49
#undef K_FIO_ISDIGIT_50
#undef K_FIO_ISDIGIT_51
#undef K_FIO_ISDIGIT_52
#undef K_FIO_ISDIGIT_53
#undef K_FIO_ISDIGIT_54
#undef K_FIO_ISDIGIT_55
#undef K_FIO_ISDIGIT_56
#undef K_FIO_ISDIGIT_57
#undef K_FIO_ISDIGIT_58
#undef K_FIO_ISDIGIT_59
#undef K_FIO_ISDIGIT_60
#undef K_FIO_ISDIGIT_61
#undef K_FIO_ISDIGIT_62
#undef K_FIO_ISDIGIT_63
#undef K_FIO_ISDIGIT_64
#undef K_FIO_CTOINT_LOW10
#undef K_FIO_CTOINT_TALL10
#undef K_FIO_READ_SSF
#undef K_DEFINE_FIO_READ_RADIX_FUNC
#undef K_FIO_READU_SSF
#undef K_DEFINE_FIO_READU_RADIX_FUNC

#pragma endregion input

#pragma region output

#define K_FIO_WRITE_FUNC(with_end_symbol, putc_func) \
    int xl = 0;                                      \
    while(x)                                         \
    {                                                \
        buffer[xl++] = x % 10;                       \
        x /= 10;                                     \
    }                                                \
    for(int i = xl - 1; i >= 0; i--)                 \
        putc_func(buffer[i] + '0');                  \
    if constexpr (with_end_symbol)                   \
        putc_func(0);

#define K_DEFINE_FIO_WRITE_FUNC(with_end_symbol, putc_func, ...) \
    template <class IntegerType>                                 \
    static void write(__VA_ARGS__) {                             \
        if(!x) {                                                 \
            putc_func('0');                                      \
            if constexpr (with_end_symbol)                       \
                putc_func(0);                                    \
            return;                                              \
        }                                                        \
        if(x < 0) {                                              \
            putc_func('-');                                      \
            x = -x;                                              \
        };                                                       \
        K_FIO_WRITE_FUNC(with_end_symbol, putc_func)             \
        return;                                                  \
    }

#define K_FIO_FPUTC(c) fputc(c, fp)

    /* write a Integer to stdin */
    K_DEFINE_FIO_WRITE_FUNC(false, putchar, IntegerType x)

    /* write a Integer to string_buffer */
    K_DEFINE_FIO_WRITE_FUNC(true, *string_buffer++ =, IntegerType x, char* string_buffer)

    /* write a Integer to file */
    K_DEFINE_FIO_WRITE_FUNC(false, K_FIO_FPUTC, IntegerType x, FILE* fp)

#undef K_DEFINE_FIO_WRITE_FUNC

#define K_DEFINE_FIO_WRITEU_FUNC(with_end_symbol, putc_func, ...) \
    template <class UnsignedIntegerType>                          \
    static void writeu(__VA_ARGS__) {                             \
        if(!x) {                                                  \
            putc_func('0');                                       \
            if constexpr (with_end_symbol)                        \
                putc_func(0);                                     \
            return;                                               \
        }                                                         \
        K_FIO_WRITE_FUNC(with_end_symbol, putc_func)              \
        return;                                                   \
    }

    /* write a Unsigned Integer to stdin */
    K_DEFINE_FIO_WRITEU_FUNC(false, putchar, UnsignedIntegerType x)

    /* write a Unsigned Integer to string_buffer */
    K_DEFINE_FIO_WRITEU_FUNC(true, *string_buffer++ =, UnsignedIntegerType x, char* string_buffer)

    /* write a Unsigned Integer to file */
    K_DEFINE_FIO_WRITEU_FUNC(false, K_FIO_FPUTC, UnsignedIntegerType x, FILE* fp)

#undef K_DEFINE_FIO_WRITEU_FUNC

#define K_DEFINE_FIO_WRITE_S(with_end_symbol, putc_func, ...) \
    static void write(__VA_ARGS__) {                          \
        while(*s)                                             \
            putc_func(*s++);                                  \
        if constexpr (with_end_symbol)                        \
            putc_func(0);                                     \
        return;                                               \
    }

    /* write a string to stdin */
    K_DEFINE_FIO_WRITE_S(false, putchar, const char* s)

    /* write a wide string to stdin */
    K_DEFINE_FIO_WRITE_S(false, putwchar, const wchar_t* s)

    /* write a string to string_buffer */
    K_DEFINE_FIO_WRITE_S(true, *string_buffer++ =, const char* s, char* string_buffer) // strcpy ?

    /* write a wide string to string_buffer */
    K_DEFINE_FIO_WRITE_S(true, *string_buffer++ =, const wchar_t* s, wchar_t* string_buffer) // wcscpy ?

    /* write a string to file */
    K_DEFINE_FIO_WRITE_S(false, K_FIO_FPUTC, const char* s, FILE* fp);

    /* write a wide string to file */
    K_DEFINE_FIO_WRITE_S(false, K_FIO_FPUTC, const wchar_t* s, FILE* fp);

#undef K_FIO_FPUTC

#pragma endregion output

    // template<class Integer>
    // static void write(Integer x, FILE* fp, int radix) {
    //     using write_radix_t = void (*)(Integer, FILE*);
    //     static constexpr write_radix_t write_radix[] = {
    //         nullptr, nullptr, write2,  write3,  write4,  write5,  write6,  write7,
    //         write8,  write9,  write,   write11, write12, write13, write14, write15,
    //         write16, write17, write18, write19, write20, write21, write22, write23,
    //         write24, write25, write26, write27, write28, write29, write30, write31,
    //         write32, write33, write34, write35, write36, write37, write38, write39,
    //         write40, write41, write42, write43, write44, write45, write46, write47,
    //         write48, write49, write50, write51, write52, write53, write54, write55,
    //         write56, write57, write58, write59, write60, write61, write62, write63,
    //         write64
    //     };
    //     if(radix > radix_max)
    //         radix = 10;
    //     if(radix < 10)
    //         radix = 10;
    //     write_radix[radix](x, fp);
    //     return;
    // }

    // template<class UnsignedInteger>
    // static void writeu(UnsignedInteger x, FILE* fp, int radix) {
    //     using writeu_radix_t = void (*)(UnsignedInteger, FILE*);
    //     static constexpr writeu_radix_t writeu_radix[] = {
    //         nullptr, nullptr,   writeu2,  writeu3,  writeu4,  writeu5,  writeu6,  writeu7,
    //         writeu8,  writeu9,  writeu,   writeu11, writeu12, writeu13, writeu14, writeu15,
    //         writeu16, writeu17, writeu18, writeu19, writeu20, writeu21, writeu22, writeu23,
    //         writeu24, writeu25, writeu26, writeu27, writeu28, writeu29, writeu30, writeu31,
    //         writeu32, writeu33, writeu34, writeu35, writeu36, writeu37, writeu38, writeu39,
    //         writeu40, writeu41, writeu42, writeu43, writeu44, writeu45, writeu46, writeu47,
    //         writeu48, writeu49, writeu50, writeu51, writeu52, writeu53, writeu54, writeu55,
    //         writeu56, writeu57, writeu58, writeu59, writeu60, writeu61, writeu62, writeu63,
    //         writeu64
    //     };
    //     if(radix > radix_max)
    //         radix = 10;
    //     if(radix < 10)
    //         radix = 10;
    //     writeu_radix[radix](x, fp);
    //     return;
    // }

#define K_DEFINE_FIO_WRITE_RADIX_FUNC(with_end_symbol, putc_func, radix, div_func, mod_func, ...) \
    template<class Integer>                                                                       \
    void write(__VA_ARGS__) {                                                                     \
        if(x == 0) {                                                                              \
            putc_func('0');                                                                       \
            return 0;                                                                             \
        }                                                                                         \
        if(x < 0)                                                                                 \
            putc_func('-');                                                                       \
        K_FIO_WRITE_RADIX_FUNC(with_end_symbol, putc_func, radix, div_func, mod_func)             \
        return;                                                                                   \
    }

#define K_DEFINE_FIO_WRITE_SSF

};

#define K_FIO_WRITE_RADIX_FUNC(with_end_symbol, putc_func, radix, div_func, mod_func) \
    int xl = 0;                                                                       \
    while(x)                                                                          \
    {                                                                                 \
        buffer[xl++] = mod_func;                                                      \
        div_func;                                                                     \
    }                                                                                 \
    for(int i = xl - 1; i >= 0; i--)                                                  \
        putc_func(buffer[i] + '0');                                                   \
    if constexpr (with_end_symbol)                                                    \
        putc_func(0);

char FastIO::buffer[255];

_WXH_END

#endif /* _FASTIO_HPP_ */
