#include "types.h"
#include "defs.h"
#include "param.h"
#include "stat.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "ext2_fs.h"
#include "buf.h"
#include "file.h"


// int ext2_dirlink(struct inode *ino, char *name, uint inum);
// struct inode *ext2_dirlookup(struct inode *ino, char *name, uint inum);
// struct inode *ext2_ialloc(struct inode *ino, char *name, uint inum);
// void ext2_iinit(struct inode *ino, char *name, uint inum);
// void ext2_ilock(struct inode *ino, char *name, uint inum);
// void ext2_iput(struct inode *ino, char *name, uint inum);
// void ext2_iunlock(struct inode *ino, char *name, uint inum);
// void ext2_iunlockput(struct inode *ino, char *name, uint inum);
// void ext2_iupdate(struct inode *ino, char *name, uint inum);
// int ext2_readi(struct inode *ino, char *name, uint inum);
// void ext2_stati(struct inode *ino, char *name, uint inum);
// int ext2_writei(struct inode *ino, char *name, uint inum);

int ext2_dirlink(struct inode *ino, char *name, uint inum){
        return 0;
}
struct inode *ext2_dirlookup(struct inode *ino, char *name, uint *inum){
//        struct inode *ptr;
        return 0;
}
struct inode *ext2_ialloc(uint inum, short num){
  //      struct inode *ptr;
        return 0;
}

void ext2_ilock(struct inode *ino){return;}
void ext2_iput(struct inode *ino){return;}
void ext2_iunlock(struct inode *ino){return;}

void ext2_iunlockput(struct inode *ino){return;}

void ext2_iupdate(struct inode *ino){return;}

int ext2_readi(struct inode *ino, char *name, uint inum, uint num){
        return 0;
}
void ext2_stati(struct inode *ino, struct stat *statStruct){return;}

int ext2_writei(struct inode *ino, char *name, uint inum, uint num){
        return 0;
}

struct inode_operations ext2_inode_ops = {
        ext2_dirlink,
        ext2_dirlookup,
        ext2_ialloc,
        ext2_iinit,
        ext2_ilock,
        ext2_iput,
        ext2_iunlock,
        ext2_iunlockput,
        ext2_iupdate,
        ext2_readi,
        ext2_stati,
        ext2_writei,
};
