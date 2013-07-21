TOPLEVEL=../..

include ../Make.inc

INCLUDES=$(XFS_INCLUDES) $(XFSUTILS_INCLUDES) $(FUSE_INCLUDES) -I.
CFLAGS=$(FUSE_CFLAGS) $(INCLUDES)
LDFLAGS=$(FUSE_LDFLAGS)

fuse-xfs: $(BINS)/fuse-xfs

$(OBJECTS)/main_fuse.o: main.c $(SRC)/xfsutil/xfsutil.h
	ln -sf /usr/local/include/fuse/fuse.h fuse.h;\
	ln -sf /usr/local/include/fuse/fuse_common.h fuse_common.h;\
	ln -sf /usr/local/include/fuse/fuse_lowlevel.h fuse_lowlevel.h;\
	ln -sf /usr/local/include/fuse/fuse_opt.h fuse_opt.h;\
	$(CC) -w $(CFLAGS) -o $(OBJECTS)/main_fuse.o -c main.c

$(OBJECTS)/fuse_xfs.o: fuse_xfs.c $(SRC)/xfsutil/xfsutil.h
	$(CC) -w $(CFLAGS) -o $(OBJECTS)/fuse_xfs.o -c fuse_xfs.c 

$(BINS)/fuse-xfs: $(OBJECTS)/main_fuse.o $(OBJECTS)/fuse_xfs.o $(OBJECTS)/xfsutil.o $(LIBS)/libxfs.a
	$(CC) $(LDFLAGS) -o $(BINS)/fuse-xfs $(OBJECTS)/main_fuse.o $(OBJECTS)/fuse_xfs.o $(OBJECTS)/xfsutil.o $(LIBS)/libxfs.a

clean:

