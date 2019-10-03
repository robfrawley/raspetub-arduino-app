/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Utility.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace Utility
    { /* BEGIN namespace Utility */

            template <typename T, size_t N> constexpr size_t arrayLength(T(&)[N]) {
                return N;
            }

            template<typename T1, typename T2> T2 constrainRange(T1 input, T2 lower, T2 upper)
            {
                return static_cast<T2>(input > upper ? upper : (input < lower ? lower : input));
            }

            template<typename T> int sumVariadicLength(T t)
            {
                return floor(String(t).length() * 1.25);
            }

            template<typename T, typename... Args> int sumVariadicLength(T t, Args... a)
            {
                return RT::Utility::sumVariadicLength(t) + RT::Utility::sumVariadicLength(a...);
            }

            template <typename... Args> int lenVariadicPack(Args... a) {
                String values[] = { a... };

                return arrayLength(values);
            }

            template <typename T, typename T2> T2 mapVariadicValues(T values, ...)
            {
                String temp[100];
                int length = 0;
                va_list va;

                va_start(va, values);

                while (String s = va_arg(va, String)) {
                    temp[length] = s;
                    length += 1;
                }

                va_end(va);

                Serial.println("---");
                Serial.println(length);

                String retn[length];

                for (int i = 0; i < length; i++) {
                    retn[i] = temp[i];
                    Serial.println(temp[i]);
                    Serial.println(retn[i]);
                }

                return retn;
            }

    } // namespace Utility

} // namespace RT
