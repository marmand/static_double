include %reldir%/tests/local.mk

nobase_include_HEADERS += %reldir%/abs.hh
nobase_include_HEADERS += %reldir%/add.hh
nobase_include_HEADERS += %reldir%/convert.hh
nobase_include_HEADERS += %reldir%/compare.hh
nobase_include_HEADERS += %reldir%/digits.hh
nobase_include_HEADERS += %reldir%/div.hh
nobase_include_HEADERS += %reldir%/double.hh
nobase_include_HEADERS += %reldir%/long.hh
nobase_include_HEADERS += %reldir%/eq.hh
nobase_include_HEADERS += %reldir%/max.hh
nobase_include_HEADERS += %reldir%/min.hh
nobase_include_HEADERS += %reldir%/mod.hh
nobase_include_HEADERS += %reldir%/mul.hh
nobase_include_HEADERS += %reldir%/pow.hh
nobase_include_HEADERS += %reldir%/shifted.hh
nobase_include_HEADERS += %reldir%/sub.hh

include %reldir%/long/local.mk
include %reldir%/double/local.mk
