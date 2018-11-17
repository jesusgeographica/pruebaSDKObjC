#ifndef _CGLIB_BASE_H
#define _CGLIB_BASE_H

#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cassert>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <limits>
#include <istream>
#include <ostream>

#ifndef CGLIB_FORCEINLINE
#   if defined(_MSC_VER)
#       define CGLIB_FORCEINLINE __forceinline
#   elif defined(__GNUC__) && __GNUC__ > 3
#       define CGLIB_FORCEINLINE inline __attribute__ ((always_inline))
#   else
#       define CGLIB_FORCEINLINE inline
#   endif
#endif

namespace cglib
{
    
    using std::size_t;
    
    /**
     * Generic traits class for floating point operations.
     */
    
    template <typename T>
        class float_traits
    {

    public:

        static constexpr T infinity() { return std::numeric_limits<T>::has_infinity ? std::numeric_limits<T>::infinity() : std::numeric_limits<T>::max(); }
        static constexpr T epsilon() { return 0; }
        static inline T sqrt(T val) { return static_cast<T>(std::sqrt(static_cast<double>(val))); }
        static inline T cos(T val) { return static_cast<T>(std::cos(static_cast<double>(val))); }
        static inline T sin(T val) { return static_cast<T>(std::sin(static_cast<double>(val))); }
        static inline T tan(T val) { return static_cast<T>(std::tan(static_cast<double>(val))); }
        static inline T acos(T val) { return static_cast<T>(std::acos(static_cast<double>(val))); }
        static inline T asin(T val) { return static_cast<T>(std::asin(static_cast<double>(val))); }
        static inline T atan2(T val1, T val2) { return static_cast<T>(std::atan2(static_cast<double>(val1), static_cast<double>(val2))); }
        static constexpr bool eq(T val1, T val2) { return val1 == val2; }
        };
    
    /**
     * Specialized traits classes for float/double types.
     */

    template <>
        class float_traits<float>
    {

    public:

        static constexpr float infinity() { return std::numeric_limits<float>::infinity(); }
        static constexpr float epsilon() { return 0; }
        static inline float sqrt(float val) { return std::sqrt(val); }
        static inline float cos(float val) { return std::cos(val); }
        static inline float sin(float val) { return std::sin(val); }
        static inline float tan(float val) { return std::tan(val); }
        static inline float acos(float val) { return std::acos(val); }
        static inline float asin(float val) { return std::asin(val);}
        static inline float atan2(float val1, float val2) { return std::atan2(val1, val2); }
        static constexpr bool eq(float val1, float val2) { return val1 == val2; }
    };

    template <>
        class float_traits<double>
    {

    public:

        static constexpr double infinity() { return std::numeric_limits<double>::infinity(); }
        static constexpr double epsilon() { return 0; }
        static inline double sqrt(double val) { return std::sqrt(val); }
        static inline double cos(double val) { return std::cos(val); }
        static inline double sin(double val) { return std::sin(val); }
        static inline double tan(double val) { return std::tan(val); }
        static inline double acos(double val) { return std::acos(val); }
        static inline double asin(double val) { return std::asin(val);}
        static inline double atan2(double val1, double val2) { return std::atan2(val1, val2); }
        static constexpr bool eq(double val1, double val2) { return val1 == val2; }
    };
    
    template <size_t N>
        struct for_each_unrolled
    {
        template <typename UnaryFunction> CGLIB_FORCEINLINE
            for_each_unrolled(UnaryFunction f)
        {
            for_each_unrolled<N-1> unroll(f);
            f(N - 1);
        }
    };
    
    template <>
        struct for_each_unrolled<0>
    {
        template <typename UnaryFunction> CGLIB_FORCEINLINE
            for_each_unrolled(UnaryFunction f)
        {
        }
    };

}

#endif
