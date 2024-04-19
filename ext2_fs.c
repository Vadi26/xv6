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


struct ext2_superblock exs;

void
ext2_readsb(int dev, struct ext2_superblock *exs)
{
  struct buf *bp;

  bp = bread(dev, 1);
  memmove(exs, bp->data, sizeof(*exs));
  brelse(bp);
  cprintf("OKAY EXT2 readsb done ! \n");
}

void ext2_iinit(int dev){
	ext2_readsb(dev, &exs);
        cprintf("ext2sb: magic %x icount = %d bcount = %d\n log block size  %d inodes per group  %d first inode %d \
	inode size %d\n", exs.s_magic, exs.s_inodes_count, exs.s_blocks_count, \
	exs.s_log_block_size, exs.s_inodes_per_group, exs.s_first_ino, exs.s_inode_size);

}

// static uint
// ext2bmap(struct inode *ip, uint bn)
// {
//         uint addr;
//         struct buf *bp;

//     if (bn < EXT2_NDIR_BLOCKS) {
//         // Direct block
//         if ((addr = ip->addrs[bn]) == 0) {
//             ip->addrs[bn] = addr = balloc(ip->dev);
//             // Update inode on disk
//             iupdate(ip);
//         }
//         return addr;
//     }

//     bn -= EXT2_NDIR_BLOCKS;

//     if (bn < EXT2_ADDR_PER_BLOCK) {
//         // Indirect block
//         if ((addr = ip->addrs[EXT2_NDIR_BLOCKS]) == 0) {
//             ip->addrs[EXT2_NDIR_BLOCKS] = addr = balloc(ip->dev);
//             // Update inode on disk
//             iupdate(ip);
//         }
//         bp = bread(ip->dev, addr);
//         uint *indirect = (uint *)bp->data;
//         if ((addr = indirect[bn]) == 0) {
//             indirect[bn] = addr = balloc(ip->dev);
//             // Write indirect block to disk
//             log_write(bp);
//         }
//         brelse(bp);
//         return addr;
//     }

//     // Double indirect block
//     panic("bmap: out of range");
// }

int ext2_dirlink(struct inode *ino, char *name, uint inum){
        return 0;
}
struct inode *ext2_dirlookup(struct inode *ino, char *name, uint *poff){
        // uint off, inum;
        // struct ext2_dir_entry_2 de;
        // char fname[DIRSIZ];

        // if(ino->type != T_DIR) panic("dirlookup not DIR");

        // for(off = 0; off < ino->size; off += de.rec_len){
        //         // If the filename is /mnt we don't need to call readi coz we want to access the in memory data structure
        //         if(ino->iops->readI(ino, (char*)&de, off, sizeof(de)) != sizeof(de)) panic("ext2 dirlookup error");
        
        //         if(de.inode == 0) continue;

        //         strncpy(fname, de.name, de.name_len);
        //         fname[de.name_len] = '\0';
        
        //         if(namecmp(name, de.name) == 0){
        //                 // entry matches path element
        //                 if(poff) *poff = off;
        //                 inum = de.inode;
        //                 return iget(ino->dev, inum);
        //         }
        // }

        return 0;
}
struct inode *ext2_ialloc(uint dev, short type){
//         struct ext2_superblock sb;
//         struct buf *bp;
//         struct dinode *dip;
//         uint inum, imap_block;
//         int bit_offset, byte_offset;

//         // Read superblock
//         ext2_readsb(dev, &sb);

//         // Calculate inode bitmap block number
//         imap_block = sb.inodestart / BSIZE + 1;

//     // Loop over inode bitmap blocks
//     for (inum = 1; inum < sb.ninodes; inum++) {
//         bp = bread(dev, imap_block);
//         byte_offset = (inum - 1) / 8;
//         bit_offset = (inum - 1) % 8;

//         // Check if inode is free
//         if ((bp->data[byte_offset] & (1 << bit_offset)) == 0) {
//             // Mark inode as allocated
//             bp->data[byte_offset] |= (1 << bit_offset);
//             log_write(bp);
//             brelse(bp);

//             // Update superblock and group descriptor
//             sb.ninode--;
//             sb.nfreeinodes--;

//             // Write back updated superblock and group descriptor
//             writesb(dev, &sb);

//             // Allocate inode structure
//             struct inode *ip = iget(dev, inum);
//             ip->type = type;
//             ip->nlink = 1;
//             ip->size = 0;
//             iupdate(ip);
//             return ip;
//         }

//         brelse(bp);
//     }

//     panic("ialloc: no inodes");
        return 0;
}

void ext2_ilock(struct inode *ino){return;}
void ext2_iput(struct inode *ino){return;}
void ext2_iunlock(struct inode *ino){return;}

void ext2_iunlockput(struct inode *ino){return;}

void ext2_iupdate(struct inode *ino){return;}

int ext2_readi(struct inode *ino, char *dest, uint offset, uint num){
        // uint tot, m;
        // struct buf *bp;

        // if(ino->type == T_DEV){
        //         if(ino->major < 0 || ino->major >= NDEV || !devsw[ino->major].read)
        //                 return -1;
        //         return devsw[ino->major].read(ino, dest, num);
        // }

        // if(offset > ino->size || offset + num < offset)
        //         return -1;
        // if(offset + num > ino->size)
        //         num = ino->size - offset;

        // for(tot=0; tot<num; tot+=m, offset+=m, dest+=m){
        //         bp = bread(ino->dev, bmap(ino, offset/BSIZE));
        //         m = min(num - tot, BSIZE - offset%BSIZE);
        //         memmove(dest, bp->data + offset%BSIZE, m);
        //         brelse(bp);
        // }
        return num;
}
void ext2_stati(struct inode *ino, struct stat *statStruct){return;}

int ext2_writei(struct inode *ino, char *name, uint inum, uint num){
        return 0;
}