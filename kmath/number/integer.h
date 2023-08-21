//
// integer.h
// /number/integer.h
//     by kuailedetongnian
//

#ifndef _INTEGER_H_
#define _INTEGER_H_

typedef unsigned char ds_t;
typedef unsigned long long isize_t;

#pragma pack(1)

typedef struct {
    union {
        struct attr_t {
            unsigned char mode    : 2; // small / large / special / Not A Number
            unsigned char num     : 2; // 0 / 1 / 2 / Inf
            unsigned char sign    : 1; // + / -
            unsigned char _nt     : 3;
        } attr;
        ds_t ab; // attribute byte
    };
    union {
        struct dss_t { // digits struct type
            isize_t size;
            isize_t capacity;
            ds_t*  dsp; // digits point
        } ds; // digits
        unsigned long long sv; // small value
    };
} integer_t;

#pragma pack()

#define KM_INTEGER_SMALL   0b00000000
#define KM_INTEGER_LARGE   0b01000000
#define KM_INTEGER_SPECIAL 0b01000000
#define KM_INTEGER_NAN     0b11000000

#define KM_INTEGER_0    0b10000000
#define KM_INTEGER_1    0b10010000
#define KM_INTEGER_N1   0b10011000
#define KM_INTEGER_2    0b10100000
#define KM_INTEGER_N2   0b10101000
#define KM_INTEGER_INF  0b10110000
#define KM_INTEGER_NINF 0b10111000

#define KM_IS_SAME(a, b) (!((a) ^ (b)))
#define KM_INTEGER_IS_SMALL(ab)   (!((ab) & 0b11000000))
#define KM_INTEGER_IS_LARGE(ab)   KM_IS_SAME((ab) & 0b11000000, 0b01000000)
#define KM_INTEGER_IS_SPECIAL(ab) KM_IS_SAME((ab) & 0b11000000, 0b10000000)
#define KM_INTEGER_IS_NAN(ab)     ((ab) & 0b11000000)
#define KM_INTEGER_IS_0(ab)       KM_IS_SAME((ab) & 0b11110000, KM_INTEGER_0)
#define KM_INTEGER_IS_1(ab)       KM_IS_SAME((ab) & 0b11111000, KM_INTEGER_1)
#define KM_INTEGER_IS_N1(ab)      KM_IS_SAME((ab) & 0b11111000, KM_INTEGER_N1)
#define KM_INTEGER_IS_2(ab)       KM_IS_SAME((ab) & 0b11111000, KM_INTEGER_2)
#define KM_INTEGER_IS_N2(ab)      KM_IS_SAME((ab) & 0b11111000, KM_INTEGER_N2)
#define KM_INTEGER_IS_INF(ab)     KM_IS_SAME((ab) & 0b11111000, KM_INTEGER_INF)
#define KM_INTEGER_IS_NINF(ab)    KM_IS_SAME((ab) & 0b11111000, KM_INTEGER_NINF)
#define KM_INTEGER_SIGN(ab) ((ab) & 0b00001000)

void km_integer_init(integer_t* np) {
    np->ab = KM_INTEGER_0;
    np->ds.size = 0;
    np->ds.capacity = 0;
    np->ds.dsp = 0;
}

void km_integer_as_i(integer_t* np, long long val) {
    if(!val)
        np->ab = KM_INTEGER_0;
    else if(KM_IS_SAME(val, 1))
        np->ab = KM_INTEGER_1;
    else if(KM_IS_SAME(val, -1))
        np->ab = KM_INTEGER_N1;
    else {
        np->ab = KM_INTEGER_SMALL;
        np->sv = val;
    }
}

void km_integer_add(integer_t* np, const integer_t rnp) {
    if(KM_INTEGER_IS_NAN(np->ab))
        return;
    if(KM_INTEGER_IS_INF(np->ab)) {
        if(!KM_INTEGER_IS_NINF(rnp.ab))
            return;
        np->ab = KM_INTEGER_NAN;
        return;
    } else if(KM_INTEGER_IS_NINF(np->ab)) {
        if(!KM_INTEGER_IS_INF(rnp.ab))
            return;
        np->ab = KM_INTEGER_NAN;
        return;
    } else if(KM_INTEGER_IS_0(np->ab))
}

void km_integer_subtract(integer_t* np, const integer_t rnp);
void km_integer_multiply(integer_t* np, const integer_t rnp);
void km_integer_divide(integer_t* np, const integer_t rnp);
integer_t km_integer_divide_mod(integer_t* np, const integer_t rnp);

#endif /* _INTEGER_H_ */
