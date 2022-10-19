#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import sys
import inspect

import _pyhash

__is_little_endian__ = sys.byteorder == 'little'

_MSC_VER = _pyhash.__dict__.get('_MSC_VER')
_GCC_VER = _pyhash.__dict__.get('_GCC_VER')
_CLANG_VER = _pyhash.__dict__.get('_CLANG_VER')
__VERSION__ = _pyhash.__dict__.get('__VERSION__')

build_with_sse42 = _pyhash.build_with_sse42
build_with_int128 = _pyhash.build_with_int128

fnv1_32 = _pyhash.fnv1_32
fnv1a_32 = _pyhash.fnv1a_32
fnv1_64 = _pyhash.fnv1_64
fnv1a_64 = _pyhash.fnv1a_64

xx_32 = _pyhash.xx_32
xx_64 = _pyhash.xx_64
xxh3_64 = _pyhash.xxh3_64
xxh3_128 = _pyhash.__dict__.get('xxh3_128')

__hasher__ = dict(inspect.getmembers(sys.modules[__name__], inspect.isclass))
