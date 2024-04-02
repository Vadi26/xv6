struct inode_operations {
	int             (*dirlinK)(struct inode*, char*, uint);
	struct inode*   (*dirlookuP)(struct inode*, char*, uint*);
	struct inode*   (*ialloC)(uint, short);
	void            (*iiniT)(int);
	void            (*ilocK)(struct inode*);
	void            (*ipuT)(struct inode*);
	void            (*iunlocK)(struct inode*);
	void            (*iunlockpuT)(struct inode*);
	void            (*iupdatE)(struct inode*);
	int             (*readI)(struct inode*, char*, uint, uint);
	void            (*statI)(struct inode*, struct stat*);
	int             (*writeI)(struct inode*, char*, uint, uint);
};

struct file {
  enum { FD_NONE, FD_PIPE, FD_INODE } type;
  int ref; // reference count
  char readable;
  char writable;
  struct pipe *pipe;
  struct inode *ip;
  uint off;
};

// in-memory copy of an inode
struct inode {
  uint dev;           // Device number
  uint inum;          // Inode number
  int ref;            // Reference count
  struct sleeplock lock; // protects everything below here
  int valid;          // inode has been read from disk?
  struct inode_operations *iops; // pointer to inode_operations

  short type;         // copy of disk inode
  short major;
  short minor;
  short nlink;
  uint size;
  uint addrs[NDIRECT+1];
};

// table mapping major device number to
// device functions
struct devsw {
  int (*read)(struct inode*, char*, int);
  int (*write)(struct inode*, char*, int);
};

extern struct devsw devsw[];

#define CONSOLE 1
