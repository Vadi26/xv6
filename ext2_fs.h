extern struct inode_operations ext2fs_inode_ops;

// Block size for ext2
#define EXT2_BSIZE 1024

#define GET_GROUP_NO(inum, ext2_sb) 	((inum - 1) / ext2_sb.s_inodes_per_group)
#define GET_INODE_INDEX(inum, ext2_sb) 	((inum - 1) % ext2_sb.s_inodes_per_group)

// for directory entry
#define EXT2_NAME_LEN 255

struct ext2_super_block {
	uint	s_inodes_count;		/* Inodes count */
	uint	s_blocks_count;		/* Blocks count */
	uint	s_r_blocks_count;	/* Reserved blocks count */
	uint	s_free_blocks_count;	/* Free blocks count */
	uint	s_free_inodes_count;	/* Free inodes count */
	uint	s_first_data_block;	/* First Data Block */
	uint	s_log_block_size;	/* Block size */
	uint	s_log_frag_size;	/* Fragment size */
	uint	s_blocks_per_group;	/* # Blocks per group */
	uint	s_frags_per_group;	/* # Fragments per group */
	uint	s_inodes_per_group;	/* # Inodes per group */
	uint	s_mtime;		/* Mount time */
	uint	s_wtime;		/* Write time */
	ushort	s_mnt_count;		/* Mount count */
	ushort	s_max_mnt_count;	/* Maximal mount count */
	ushort	s_magic;		/* Magic signature */
	ushort	s_state;		/* File system state */
	ushort	s_errors;		/* Behaviour when detecting errors */
	ushort	s_minor_rev_level; 	/* minor revision level */
	uint	s_lastcheck;		/* time of last check */
	uint	s_checkinterval;	/* max. time between checks */
	uint	s_creator_os;		/* OS */
	uint	s_rev_level;		/* Revision level */
	ushort	s_def_resuid;		/* Default uid for reserved blocks */
	ushort	s_def_resgid;		/* Default gid for reserved blocks */
	/*
	 * These fields are for EXT2_DYNAMIC_REV superblocks only.
	 *
	 * Note: the difference between the compatible feature set and
	 * the incompatible feature set is that if there is a bit set
	 * in the incompatible feature set that the kernel doesn't
	 * know about, it should refuse to mount the filesystem.
	 *
	 * e2fsck's requirements are more strict; if it doesn't know
	 * about a feature in either the compatible or incompatible
	 * feature set, it must abort and not try to meddle with
	 * things it doesn't understand...
	 */
	uint	s_first_ino; 		/* First non-reserved inode */
	ushort   s_inode_size; 		/* size of inode structure */
	ushort	s_block_group_nr; 	/* block group # of this superblock */
	uint	s_feature_compat; 	/* compatible feature set */
	uint	s_feature_incompat; 	/* incompatible feature set */
	uint	s_feature_ro_compat; 	/* readonly-compatible feature set */
	uchar	s_uuid[16];		/* 128-bit uuid for volume */
	char	s_volume_name[16]; 	/* volume name */
	char	s_last_mounted[64]; 	/* directory where last mounted */
	uint	s_algorithm_usage_bitmap; /* For compression */
	/*
	 * Performance hints.  Directory preallocation should only
	 * happen if the EXT2_COMPAT_PREALLOC flag is on.
	 */
	uchar	s_prealloc_blocks;	/* Nr of blocks to try to preallocate*/
	uchar	s_prealloc_dir_blocks;	/* Nr to preallocate for dirs */
	ushort	s_padding1;
	/*
	 * Journaling support valid if EXT3_FEATURE_COMPAT_HAS_JOURNAL set.
	 */
	uchar	s_journal_uuid[16];	/* uuid of journal superblock */
	uint	s_journal_inum;		/* inode number of journal file */
	uint	s_journal_dev;		/* device number of journal file */
	uint	s_last_orphan;		/* start of list of inodes to delete */
	uint	s_hash_seed[4];		/* HTREE hash seed */
	uchar	s_def_hash_version;	/* Default hash version to use */
	uchar	s_reserved_char_pad;
	ushort	s_reserved_word_pad;
	uint	s_default_mount_opts;
	uint	s_first_meta_bg; 	/* First metablock block group */
	uint	s_reserved[190];	/* Padding to the end of the block */
};