
##
## This file is part of the `src-run/raspetub-arduino-app` package.
##
## (c) Rob Frawley 2nd <rmf@src.run>
##
## For the full copyright and license information, view the LICENSE.md
## file distributed with this source code.
##

# include required external modules
from pathlib import Path
from enum import OrderedDict, Enum
import enum
from abc import ABC, abstractmethod

# import required local modules
from bldr.system.abc import ABCMetaEnum
from itertools import chain, product

class FilePath:
    _create_open_modes_dict = {
        1: ['Wien Westbahnhof', 'WIEN_WESTBAHNHOF'],
        2: ['St. Pölten', 'ST_POELTEN'],
        3: ['Linz', 'LINZ'],
        4: ['Wels', 'WELS'],
    }

    Station = OrderedDict(value='Station', names=chain.from_iterable(
        product(v, [k]) for k, v in _create_open_modes_dict.items()
    ))

    class AbstractOpenMode(Enum, metaclass=ABCMetaEnum):
        GET_O = None
        GET_A_PUT = None
        PUT_O = None
        PUT_A_GET = None

    class CreateOpenMode(AbstractOpenMode):
        GET_O = 'r'
        GET_A_PUT = 'r+'
        PUT_O = 'w'
        PUT_A_GET = 'w+'

    class AppendOpenMode(AbstractOpenMode):
        GET_O = 'a+'
        GET_A_PUT = 'a+'
        PUT_O = 'a'
        PUT_A_GET = 'a+'

    class OperationsMode(Enum):
        TEXT = ''
        BYTE = 'b'

    def _open_mode(self, open_mode: AbstractOpenMode = CreateOpenMode.GET_O, opts_mode: OperationsMode = OperationsMode.TEXT):
        self.Station.get()
        is_broad = open_mode.value

    def __init__(self, path: str):
        self._setup_state(path)

    @property
    def real_path(self):
        return self._real_path

    @real_path.setter
    def real_path(self, path: str):
        raise RuntimeError(f'Cannot invoke setter method "{self.real_path.__name__}" of constant property.')

    @property
    def file_path(self):
        return self._file_path

    @file_path.setter
    def file_path(self, path: str):
        self._setup_state(path)

    def file_base(self):
        return Path(Path(self.real_path()).name)

    def path_base(self):
        return Path(Path(self.real_path()).parent)

    def is_symlink(self):
        return self.real_path().is_symlink()

    def is_absolute(self):
        return self.real_path().is_absolute()

    def is_existing(self):
        return self.real_path().exists()

    def is_readable(self):
        self.real_path().open()
        if not self.is_existing():
            return False
        with self.real_path().open(self.OpenMode.TEXT.value) as f:
            return f.readable()

    def is_writable(self):
        if not self.is_existing() or not self.is_readable():
            return False
        with self.real_path().open(self.OpenMode.TEXT.value) as f:
            return f.writable()

    def get_contents(self, size: int = None, mode: OpenMode = OpenMode.TEXT):
        return self.get_contents_of(self.real_path(), size, mode)

    def put_contents(self, data, mode: FormatMode = FormatMode.APPEND):
        return self.put_contents_in(self.real_path(), data, mode)

    @classmethod
    def get_contents_of(cls, file: str, size: int = None, mode: OpenMode = OpenMode.TEXT):
        file = cls(file)
        file.assert_is_readable(file)

        with file.real_path().open(mode.value) as file_gets:
            return file_gets.read(size if not None else -1)

    @classmethod
    def put_contents_in(cls, file: str, data: str, mode: FormatMode = FormatMode.APPEND):
        file = cls(file)
        file.assert_is_writable(file)

        with file.real_path().open(mode.value) as file_puts:
            file_puts.write(data)
        return file

    @classmethod
    def assert_is_existing(cls, file: 'FilePath'):
        if not file.is_existing():
            raise FileExistsError(f'Failed file status operation on "{file.real_path()}"; it does not exist.')

    @classmethod
    def assert_is_readable(cls, file: 'FilePath'):
        cls.assert_is_existing(file)

        if not file.is_readable():
            raise PermissionError(f'Failed file permissions operation on "{file.real_path()}"; it is not readable.')

    @classmethod
    def assert_is_writable(cls, file: 'FilePath'):
        cls.assert_is_readable(file)

        if not file.is_writable():
            raise PermissionError(f'Failed file permissions operation on "{file.real_path()}"; it is not writable.')

    def _setup_state(self, path: str):
        self._file_path = Path(path)
        self._real_path = Path(path).resolve().expanduser()
