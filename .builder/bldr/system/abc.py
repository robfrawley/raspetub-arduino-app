
#
# This file is part of the `src-run/raspetub-arduino-app` package.
#
# (c) Rob Frawley 2nd <rmf@src.run>
#
# For the full copyright and license information, view the LICENSE.md
# file distributed with this source code.
#

# include required external modules
from enum import Enum, EnumMeta
from abc import ABCMeta


class ABCMetaEnum(ABCMeta, EnumMeta):

    def __new__(mcs, *args, **kw):
        scs = super().__new__(mcs, *args, **kw)

        if issubclass(scs, Enum) and scs.__len__() == 0:
            raise TypeError(f'Cannot instantiate abstract class "{mcs.__name__}" with zero members.')

        return scs

    def __call__(cls, *args, **kw):
        if cls.__len__() == 0:
            raise TypeError(f'Cannot instantiate abstract class "{cls.__name__}" with zero members.')

        return super().__call__(*args, **kw)
