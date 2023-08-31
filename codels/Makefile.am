
lib_LTLIBRARIES = libFoxgloveStudio_codels.la

libFoxgloveStudio_codels_la_SOURCES  =	FoxgloveStudio_c_types.h
libFoxgloveStudio_codels_la_SOURCES +=	FoxgloveStudio_codels.cc
libFoxgloveStudio_codels_la_SOURCES +=	FoxgloveStudio_main_codels.cc
libFoxgloveStudio_codels_la_SOURCES += foxglove/*.hpp
libFoxgloveStudio_codels_la_SOURCES += foxglove/*.h
libFoxgloveStudio_codels_la_SOURCES += base64.cc
libFoxgloveStudio_codels_la_SOURCES += serialization.cc
libFoxgloveStudio_codels_la_SOURCES += parameter.cc

libFoxgloveStudio_codels_la_CPPFLAGS =	$(requires_CFLAGS) --std=c++17
libFoxgloveStudio_codels_la_LIBADD   =	$(requires_LIBS)
libFoxgloveStudio_codels_la_CPPFLAGS+=	$(codels_requires_CFLAGS)
libFoxgloveStudio_codels_la_LIBADD  +=	$(codels_requires_LIBS)
libFoxgloveStudio_codels_la_LDFLAGS  =	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	FoxgloveStudio_c_types.h
CLEANFILES=	${BUILT_SOURCES}

FoxgloveStudio_c_types.h: ${top_srcdir}/foxglove.gen
	${GENOM3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/FoxgloveStudio_c_types.h.d
