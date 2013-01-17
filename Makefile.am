lib_LTLIBRARIES = observerChat.la

observerChat_la_SOURCES = observerChat.cpp
observerChat_la_CXXFLAGS= -I$(top_srcdir)/include -I$(top_srcdir)/plugins/plugin_utils
observerChat_la_LDFLAGS = -module -avoid-version -shared
observerChat_la_LIBADD = $(top_builddir)/plugins/plugin_utils/libplugin_utils.la

AM_CPPFLAGS = $(CONF_CPPFLAGS)
AM_CFLAGS = $(CONF_CFLAGS)
AM_CXXFLAGS = $(CONF_CXXFLAGS)

EXTRA_DIST = \
	README.txt \
	observerChat.def \
	observerChat.sln \
	observerChat.vcxproj

MAINTAINERCLEANFILES =	\
	Makefile.in
