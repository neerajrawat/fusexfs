VERSION=0.1

BUILD=$(TOPLEVEL)/build
SRC=$(TOPLEVEL)/src
BINS=$(BUILD)/bin
LIBS=$(BUILD)/lib
OBJECTS=$(BUILD)/obj

CC=gcc
FUSE_CFLAGS=-D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26
FUSE_LDFLAGS=-L/usr/local/lib -lfuse
FUSE_INCLUDES=-I/usr/local/include/fuse
XFSUTILS_INCLUDES=-I$(SRC)/xfsutil
XFS_INCLUDES=-I$(SRC)/xfsprogs/include

PROGRAMS=xfs-cli xfs-rcopy fuse-xfs mkfs.xfs
PROGRAMS:=$(addprefix $(BINS)/, $(PROGRAMS))

DMG=$(BUILD)/fuse-xfs-$(VERSION).dmg
