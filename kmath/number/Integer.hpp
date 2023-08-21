//
// Integer.hpp
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C++/Include/Math/Number/Integer.hpp
//

#ifndef _INTEGER_HPP_
#define _INTEGER_HPP_

#include "../../wxh/wxh"

#pragma pack(1)

class Integer {
public:
    using ds_t = unsigned char;
    using small_t = unsigned long long;
public:
    /* sign */
    static SP_CONSTEXPR bool positive = 0x0;
    static SP_CONSTEXPR bool negative = 0x1;
    /* num */
    static SP_CONSTEXPR int zero      = 0x0;
    static SP_CONSTEXPR int one       = 0x1;
    static SP_CONSTEXPR int minus_one = 0x2;
    static SP_CONSTEXPR int other     = 0x3; // mode is also applicable
    /* special */
    static SP_CONSTEXPR bool inf = 0x0;
    static SP_CONSTEXPR bool nan = 0x1;
    /* mode */
    static SP_CONSTEXPR int small  = 0x0;
    static SP_CONSTEXPR int medium = 0x1;
    static SP_CONSTEXPR int large  = 0x2;
    /* limits */
    static SP_CONSTEXPR small_t small_max = 0xFFFFFFFFFFFFFFFF;
private:
    union {
        struct /* nt */ { // nature type
            bool          sign    : 1; // + -
            unsigned char mode    : 2; // Small Medium Large Other(num special)
            unsigned char msize   : 2; // Medium's size (and num, special)
            unsigned char num     : 2; // 0 1 -1 Other(Inf NaN)
            bool          spacial : 1; // Inf NaN
        } nature;
        ds_t nb; // nature byte
    };
    union {
        struct /* dst */ { // digits type
            size_t size;
            size_t capacity;
            ds_t*  dsp; // digits point
        } ds; // digits
        ds_t dsb[sizeof(ds)]; // digits bytes
        unsigned long long sx; // small x
    };
public:
    Integer()
    {
        nb = 0b01100000;
    }
private:
    void as(unsigned long long val) {
        if(val == 0) {
            nb = 0b01100000;
        } else if(val == 1) {
            nb = 0b01100010;
        } else {
            nb = 0b0
        }
    }
public:
    bool sign() const {
        return nature.sign;
    }

    int mode() const {
        return nature.mode;
    }

    int num() const {
        return nature.num;
    }

    bool spacial() const {
        return nature.spacial;
    }

    size_t size() const {
        int md = nature.mode;
        if(md == small)
            return sizeof(unsigned long long);
        if(md == medium)
            return nb & 0x1F;
        if(md == large)
            return ds.size;
        return 0;
    }

    size_t capacity() const {
        int md = nature.mode;
        if(md == small)
            return sizeof(unsigned long long);
        if(md == medium)
            return sizeof(ds);
        if(md == large)
            return ds.capacity;
        return 0;
    }

    ds_t* get_ds() {
        int md = nature.mode;
        if(md == small)
            return dsb;
        if(md == medium)
            return dsb;
        if(md == large)
            return ds.dsp;
        return (ds_t*)1;
    }

    const ds_t* get_ds() const {
        int md = nature.mode;
        if(md == small)
            return dsb;
        if(md == medium)
            return dsb;
        if(md == large)
            return ds.dsp;
        return (ds_t*)1;
    }
public: /* API */
    void add(const Integer& val) {
        int md = nature.mode;
        if(md == small) {
            if(nature.sign == val.nature.sign) {
                if(sx > small_max - val.sx) { // judgment overflow
                    ;
                } else {
                    sx += val.sx;
                    goto num_treatment;
                }
            } else {
                /* determine sign */
                if(sx < val.sx)
                    nature.sign = !nature.sign;
                small_t max = (sx > val.sx) ? (sx) : (val.sx);
                small_t min = (sx < val.sx) ? (sx) : (val.sx);
                sx = max - min;
                goto num_treatment;
            }
        }

        return;
        num_treatment:
        if(sx == 0)
            nature.num = zero;
        else if(sx == 1) {
            if(nature.sign == 0)
                nature.num = one;
            else
                nature.num = minus_one;
        }
        if(nature.num != other)
            nature.mode = other;
    }

    void subtract(const Integer& val) {
        ;
    }

    void multiply(const Integer& val) {
        ;
    }

    void divide(const Integer& val) {
        ;
    }
};

#pragma pack()

#endif /* _INTEGER_HPP_ */
