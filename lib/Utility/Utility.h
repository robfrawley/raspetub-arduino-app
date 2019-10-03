/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_UTILITY

    #define RT_HR_INCLUDED_UTILITY

    #include <Arduino.h>

    namespace RT
    { /* BEGIN namespace RT */

        namespace Utility
        { /* BEGIN namespace Utility */

            //#define ARRAY_LENGTH(a) (sizeof(A)/sizeof(A[0])) // <-- maybe this one is right?
            //#define ARRAY_LENGTH(A) (sizeof(A)/sizeof(A[0])) // <-- maybe this other one?
            template<typename T, size_t N> constexpr size_t arrayLength(T(&)[N]);

            template<typename T1, typename T2> long int constrainRange(T1 input, T2 lower, T2 upper);

            template<typename T> int sumVariadicLength(T t);

            template<typename T, typename... Args> int sumVariadicLength(T t, Args... a);

            template <typename T, typename T2> T2 mapVariadicValues(T values, ...);

        }; /* namespace Utility */

    }; /* namespace RT */

#endif
